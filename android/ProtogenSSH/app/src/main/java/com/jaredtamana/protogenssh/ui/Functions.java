package com.jaredtamana.protogenssh.ui;

import android.app.Activity;
import android.content.Context;
import android.os.StrictMode;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.Toast;

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
    static public int executeSSHcommand(String command, Context context) {
        String user = "pi";
        String password = "raspberry";
        String host = "192.168.4.1";
        int port = 22;
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
            Toast errorToast = Toast.makeText(context, "JSch exception, you're probably disconnected from the RasPi", Toast.LENGTH_LONG);
            errorToast.setMargin(50, 50);
            errorToast.show();
        }
        return 0;
    }

    public static void readFile(LinearLayout emoteListLayout, String fileName, final Context context, Activity activity) {
        System.out.println("entering readfile");
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
                        Functions.executeSSHcommand(buttonCommand, context);
                    }
                });
                try {
                    emoteListLayout.addView(nb);
                } catch (NullPointerException ee) {
                    ee.printStackTrace();
                    Toast errorToast = Toast.makeText(context, "NullPointerException, not added", Toast.LENGTH_SHORT);
                    errorToast.setMargin(50, 50);
                    errorToast.show();
                    return;
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
            Toast errorToast = Toast.makeText(context, "Buttons not loaded: IOException", Toast.LENGTH_SHORT);
            errorToast.setMargin(50, 50);
            errorToast.show();
        }
    }


    public static void writeFile(String buttonName, String buttonCommand, String fileName, Context context) {
        String buttonInfo = buttonName + "\n" + buttonCommand + "\n";
        File internalStorageDir = context.getFilesDir();
        File buttonStore = new File(internalStorageDir, fileName);

        try {
            BufferedWriter writer = new BufferedWriter(
                    new FileWriter(buttonStore.toString(), true)
            );
            writer.write(buttonInfo);
            writer.close();
            Toast successToast = Toast.makeText(context, "Button saved", Toast.LENGTH_SHORT);
            successToast.setMargin(50, 50);
            successToast.show();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
            Toast errorToast = Toast.makeText(context, "Button not saved: FileNotFoundException", Toast.LENGTH_SHORT);
            errorToast.setMargin(50, 50);
            errorToast.show();
        } catch (IOException e) {
            e.printStackTrace();
            Toast errorToast = Toast.makeText(context, "Button not saved: IOException", Toast.LENGTH_SHORT);
            errorToast.setMargin(50, 50);
            errorToast.show();
        }
    }
}
