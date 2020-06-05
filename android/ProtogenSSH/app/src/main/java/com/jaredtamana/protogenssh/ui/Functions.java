package com.jaredtamana.protogenssh.ui;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.StrictMode;
import android.view.Gravity;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.Toast;

import com.google.android.material.snackbar.BaseTransientBottomBar;
import com.google.android.material.snackbar.Snackbar;
import com.jaredtamana.protogenssh.R;
import com.jcraft.jsch.ChannelExec;
import com.jcraft.jsch.JSch;
import com.jcraft.jsch.JSchException;
import com.jcraft.jsch.Session;

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
    // accepts string of command
    // returns void
    static public int executeSSHcommand(String command, Context context, View baseView) {
        // String user = "pi";
        SharedPreferences sharedPreferences = context.getSharedPreferences("credentials", Context.MODE_PRIVATE);
        String user = sharedPreferences.getString("username", "pi");
        String password = sharedPreferences.getString("password", "raspberry");
        String host = "192.168.4.1";
        int port = sharedPreferences.getInt("port", 22);
        StrictMode.ThreadPolicy policy = new StrictMode.ThreadPolicy.Builder()
                .permitAll().build();
        StrictMode.setThreadPolicy(policy);
        try {
            JSch jsch = new JSch();
            Session session = jsch.getSession(user, host, port);
            session.setPassword(password);
            java.util.Properties config = new java.util.Properties();
            config.put("StrictHostKeyChecking", "no");
            session.setConfig(config);
            session.setTimeout(1000);
            session.connect();
            ChannelExec channel = (ChannelExec) session.openChannel("exec");
            channel.setCommand(command);
            channel.connect(10000);
            channel.disconnect();

        } catch (JSchException e) {
            e.printStackTrace();
            Snackbar.make(baseView, R.string.connect_failed_snack, BaseTransientBottomBar.LENGTH_LONG)
            .show();
        }
        return 0;
    }

    public static void readFile(LinearLayout emoteListLayout, String fileName, final Context context, Activity activity, final View baseView) {
        File internalStorageDir = context.getFilesDir();
        try {
            FileInputStream fileInputStream = context.openFileInput(fileName);
            InputStreamReader inputStreamReader = new InputStreamReader(fileInputStream);

            BufferedReader reader = new BufferedReader(inputStreamReader);
            while (reader.ready()) {
                String buttonName = reader.readLine();
                final String buttonCommand = reader.readLine();
                Button nb = new Button(activity);
                nb.setText(buttonName);
                nb.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        Functions.executeSSHcommand(buttonCommand, context, baseView);
                    }
                });
                try {
                    emoteListLayout.addView(nb);
                } catch (NullPointerException ee) {
                    ee.printStackTrace();
                    Snackbar.make(baseView, R.string.npe_add_snack, BaseTransientBottomBar.LENGTH_SHORT)
                            .show();
                    return;
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
            Toast errorToast = Toast.makeText(context, R.string.button_load_ioe_snack, Toast.LENGTH_SHORT);
            errorToast.setGravity(Gravity.NO_GRAVITY, 0, 0);
            errorToast.setMargin(50, 50);
            errorToast.show();
        }
    }


    public static void writeFile(String buttonName, String buttonCommand, String fileName, Context context, View baseView) {
        String buttonInfo = buttonName + "\n" + buttonCommand + "\n";
        File internalStorageDir = context.getFilesDir();
        File buttonStore = new File(internalStorageDir, fileName);

        try {
            BufferedWriter writer = new BufferedWriter(
                    new FileWriter(buttonStore.toString(), true)
            );
            writer.write(buttonInfo);
            writer.close();
            Snackbar.make(baseView, R.string.button_saved_snack, BaseTransientBottomBar.LENGTH_SHORT)
                    .show();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
            Snackbar.make(baseView, R.string.buttons_save_fnfe_snack, BaseTransientBottomBar.LENGTH_SHORT)
                    .show();
        } catch (IOException e) {
            e.printStackTrace();
            Snackbar.make(baseView, R.string.buttons_save_ioe_snack, BaseTransientBottomBar.LENGTH_SHORT)
                    .show();
        }
    }

    public static void deleteFile(String fileName, Context context, View baseView){
        File internalStorageDir = context.getFilesDir();
        File buttonStore = new File(internalStorageDir, fileName);
        buttonStore.delete();
        Snackbar.make(baseView, R.string.buttons_deleted_snack, BaseTransientBottomBar.LENGTH_SHORT)
                .show();
    }
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
