package com.jaredtamana.protogenssh.ui;

// imports for base Android

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.Build;
import android.os.Handler;
import android.os.StrictMode;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

// Material imports
import androidx.security.crypto.EncryptedSharedPreferences;
import androidx.security.crypto.MasterKeys;

import com.google.android.material.snackbar.BaseTransientBottomBar;
import com.google.android.material.snackbar.Snackbar;

// Self imports
import com.jaredtamana.protogenssh.R;

// JSch imports
import com.jcraft.jsch.ChannelExec;
import com.jcraft.jsch.JSch;
import com.jcraft.jsch.JSchException;
import com.jcraft.jsch.Session;

// Java imports
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class Functions {

    // executeSSHcommand function
    // Creates an SSH session and sends a single command before immediately closing the connection again
    // (this does mean no responses can be grabbed by this function)
    // accepts string of command, context for sharedPrefs, view for snackbar
    // returns void
    static public void executeSSHcommand(String command, Context context, View baseView) {
        int sdk = Build.VERSION.SDK_INT;
        String user;
        String password;
        String host;
        int port;
        SharedPreferences sharedPreferences;
        if (sdk >= 23){
            String masterKeyAlias;
            try {
                masterKeyAlias = MasterKeys.getOrCreate(MasterKeys.AES256_GCM_SPEC); // get master key
                sharedPreferences = EncryptedSharedPreferences.create(
                        "secret_shared_prefs",
                        masterKeyAlias,
                        context,
                        EncryptedSharedPreferences.PrefKeyEncryptionScheme.AES256_SIV,
                        EncryptedSharedPreferences.PrefValueEncryptionScheme.AES256_GCM
                );
            } catch (Exception e) {
                e.printStackTrace();
                Snackbar.make(baseView, "Failed to create encryption keys (IOException or SecurityException)", BaseTransientBottomBar.LENGTH_LONG)
                        .show();
                return;
            }
            user = sharedPreferences.getString(context.getString(R.string.username_sharedprop), "pi");
            password = sharedPreferences.getString(context.getString(R.string.password_sharedprop), "raspberry");
            host = sharedPreferences.getString(context.getString(R.string.host_sharedprop), "192.168.4.1");
            port = sharedPreferences.getInt(context.getString(R.string.port_sharedprop), 22);
        } else {
            sharedPreferences = context.getSharedPreferences("credentials", Context.MODE_PRIVATE); // open credentials file
            user = sharedPreferences.getString("username", "pi"); // use credentials unless not set, then use username pi
            password = sharedPreferences.getString("password", "raspberry"); // use credentials unless not set, then use password raspberry
            host = sharedPreferences.getString("host", "192.168.4.1"); // use IP address, will end up adding a field for this later
            port = sharedPreferences.getInt("port", 22); // use credentials unless not set, then use port 22
        }
        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder()
                .permitAll().build();
        StrictMode.setThreadPolicy(policy); // just a workaround
        try {
            JSch jsch = new JSch(); // instantiate a new JSch call
            assert host != null;
            Session session = jsch.getSession(user, host, port); // set session credentials
            session.setPassword(password); // set password
            java.util.Properties config = new java.util.Properties();
            config.put("StrictHostKeyChecking", "no"); // turn off Strict Host Key Checking
            session.setConfig(config);
            session.setTimeout(1000); // timeout after 1s
            session.connect(); // attempt connection
            ChannelExec channel = (ChannelExec) session.openChannel("exec"); // open ssh channel
            channel.setCommand(command); // set command to be sent
            channel.connect(1000); // connect to channel with timeout of 1s (send command)
            channel.disconnect(); // disconnect

        } catch (JSchException e) {
            e.printStackTrace();
            Snackbar snackbar = Snackbar.make(baseView, R.string.connect_failed_snack, BaseTransientBottomBar.LENGTH_LONG);
            View snackbarView = snackbar.getView();
            TextView snackTextView = (TextView) snackbarView.findViewById(com.google.android.material.R.id.snackbar_text);
            snackTextView.setMaxLines(3);
            snackbar.show(); // tell the user the command failed
        }
    }

    // readFile function
    // Reads in button data and places buttons into the designated layout
    // accepts LinearLayout to be placed into, context for fileInput, view for snackbar
    // returns void
    public static void readFile(LinearLayout emoteListLayout, String fileName, final Context context, Activity activity, final View baseView) {
        try {
            // instantiate fis
            FileInputStream fileInputStream = context.openFileInput(fileName);
            InputStreamReader inputStreamReader = new InputStreamReader(fileInputStream);

            // instantiate reader
            BufferedReader reader = new BufferedReader(inputStreamReader);
            while (reader.ready()) { // while there is content to be read
                String buttonName = reader.readLine(); // read the next line as a string variable for the button label
                final String buttonCommand = reader.readLine(); // read the next line as a string variable for the command the button sends
                Button nb = new Button(activity); // create new button
                nb.setText(buttonName); // set the label text
                nb.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) { // set OnClick to executeSSHcommand with buttonCommand
                        Handler h = new Handler(); // create Handler for asynchronous function
                        h.post(new Runnable() {
                            @Override
                            public void run() {
                                Functions.executeSSHcommand(buttonCommand, context, baseView);
                            }
                        });
                    }
                });
                try {
                    emoteListLayout.addView(nb); // try to add each button to the list
                } catch (NullPointerException ee) {
                    ee.printStackTrace();
                    Snackbar.make(baseView, R.string.npe_add_snack, BaseTransientBottomBar.LENGTH_SHORT)
                            .show(); // let the user know that the list couldn't be found
                    return; // exit so no more time is wasted
                }
            }
        } catch (FileNotFoundException e) {
            // e.printStackTrace();
            // this is standard when no buttons have been created, so we won't do anything
        } catch (IOException e) {
            e.printStackTrace();
            Toast errorToast = Toast.makeText(context, R.string.button_load_ioe_snack, Toast.LENGTH_SHORT);
            errorToast.show(); // something happened in the storage controller, so let the user know
        }
    }

    // writeFile function
    // Writes out button data into designated file
    // accepts String name of button, String command assigned to button, String name of file to write to, context for file storage, view for snackbar
    // returns void
    public static void writeFile(String buttonName, String buttonCommand, String fileName, Context context, View baseView) {
        String buttonInfo = buttonName + "\n" + buttonCommand + "\n"; // store the button info with newlines
        File internalStorageDir = context.getFilesDir(); // get the directory we're working in
        File buttonStore = new File(internalStorageDir, fileName); // set the full path of the file

        try {
            // instantiate the writers with the filepath
            BufferedWriter writer = new BufferedWriter(
                    new FileWriter(buttonStore.toString(), true)
            );
            writer.write(buttonInfo); // write the button info using the writer
            writer.close(); // close the resource
            Snackbar.make(baseView, R.string.button_saved_snack, BaseTransientBottomBar.LENGTH_SHORT)
                    .show(); // let the user know that the button was saved

        } catch (FileNotFoundException e) {
            e.printStackTrace();
            Snackbar.make(baseView, R.string.buttons_save_fnfe_snack, BaseTransientBottomBar.LENGTH_SHORT)
                    .show(); // let the user know that something happened with our storage implementation
        } catch (IOException e) {
            e.printStackTrace();
            Snackbar.make(baseView, R.string.buttons_save_ioe_snack, BaseTransientBottomBar.LENGTH_SHORT)
                    .show(); // let the user know that something happened with the storage controller
        }
    }

    // deleteFile function
    // Deletes button data so a fragment is wiped clean
    // accepts String of the file we should delete, context for file storage, view for snackbar
    // returns void
    public static void deleteFile(String fileName, Context context, View baseView) {
        File internalStorageDir = context.getFilesDir(); // get the directory we're working in
        File buttonStore = new File(internalStorageDir, fileName); // set the fill path of the file
        buttonStore.delete(); // have the file delete itself
        Snackbar.make(baseView, R.string.buttons_deleted_snack, BaseTransientBottomBar.LENGTH_SHORT)
                .show(); // let the user know that the file was deleted
    }

    // hideKeyboard function
    // Simply collapses the softkeyboard
    // context for IME service, view for window token
    // returns void
    // credit for this function: https://stackoverflow.com/questions/1109022/close-hide-android-soft-keyboard/52155941#52155941
    public static void hideKeyboard(Context context, View view) {
        try {
            // use application level context to avoid unnecessary leaks.
            InputMethodManager inputManager = (InputMethodManager) context.getSystemService(Context.INPUT_METHOD_SERVICE);
            assert inputManager != null;
            inputManager.hideSoftInputFromWindow(view.getWindowToken(), InputMethodManager.HIDE_NOT_ALWAYS);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
