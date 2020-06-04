package com.jaredtamana.protogenssh.ui.home;

// imports for base Android
import android.app.AlertDialog;
import android.os.Bundle;
import android.os.StrictMode;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.Toast;

// java io imports
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.File;
import java.io.InputStreamReader;

// AndroidX imports
import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModelProviders;

// Project imports, including JSch binary
import com.jaredtamana.protogenssh.R;
import com.jcraft.jsch.ChannelExec;
import com.jcraft.jsch.JSch;
import com.jcraft.jsch.JSchException;
import com.jcraft.jsch.Session;
import com.jaredtamana.protogenssh.ui.eyes.EyesFragment;
import com.jaredtamana.protogenssh.ui.mouth.MouthFragment;

@SuppressWarnings("ALL")
public class HomeFragment extends Fragment { // main fragment start

    private HomeViewModel homeViewModel;

    // executeSSHcommand function
    // Creates an SSH session and sends a single command before immediately closing the connection again
    // accepts string of command
    // returns void
    public void executeSSHcommand(String command) {
        String user = "pi";
        String password = "***REMOVED***";
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
            Toast errorToast = Toast.makeText(getContext(), "JSch exception, you're probably disconnected from the RasPi", Toast.LENGTH_LONG);
            errorToast.setMargin(50, 50);
            errorToast.show();
        }
    }

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        homeViewModel =
                ViewModelProviders.of(this).get(HomeViewModel.class);
        final View root = inflater.inflate(R.layout.fragment_home, container, false);
        Button fabCreateScript = (Button) root.findViewById(R.id.fab);
        final LinearLayout mEmoteList = (LinearLayout) root.findViewById(R.id.scrollViewEmoteListLayout);
        readFile(mEmoteList);
        fabCreateScript.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder mBuilder = new AlertDialog.Builder(getActivity());
                View mView = getLayoutInflater().inflate(R.layout.dialog_add_script, null);
                final EditText mScriptName = (EditText) mView.findViewById(R.id.scriptName);
                final EditText mScriptPath = (EditText) mView.findViewById(R.id.scriptPath);
                RadioButton mRadioFullFace = (RadioButton) mView.findViewById(R.id.radioFullFace);
                RadioButton mRadioEyesOnly = (RadioButton) mView.findViewById(R.id.radioEyesOnly);
                RadioButton mRadioMouthOnly = (RadioButton) mView.findViewById(R.id.radioMouthOnly);
                Button mBtnScriptCancel = (Button) mView.findViewById(R.id.btnCancelScript);
                Button mBtnScriptApply = (Button) mView.findViewById(R.id.btnApplyScript);
                mBuilder.setView(mView);
                final AlertDialog dialog = mBuilder.create();
                dialog.show();
                mBtnScriptCancel.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        dialog.dismiss();
                    }
                });
                mBtnScriptApply.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        Button nb = new Button(getActivity());
                        nb.setText(mScriptName.getText().toString());
                        nb.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {
                                executeSSHcommand(mScriptPath.getText().toString());
                            }
                        });
                        try {
                            mEmoteList.addView(nb);
                            writeFile(mScriptName.getText().toString(), mScriptPath.getText().toString());
                        } catch (NullPointerException ee) {
                            ee.printStackTrace();
                            Toast errorToast = Toast.makeText(getContext(), "NullPointerException, not added", Toast.LENGTH_SHORT);
                            errorToast.setMargin(50, 50);
                            errorToast.show();
                            dialog.dismiss();
                            return;
                        }
                        Toast successToast = Toast.makeText(getContext(), "Added successfully", Toast.LENGTH_SHORT);
                        successToast.setMargin(50, 50);
                        successToast.show();

                        dialog.dismiss();
                    }
                });
            }
        });
        return root;
    }

    public void writeFile(String buttonName, String buttonCommand) {
        String buttonInfo = buttonName + "\n" + buttonCommand + "\n";
        File internalStorageDir = getContext().getFilesDir();
        File buttonStore = new File(internalStorageDir, "buttons.txt");

        try {
            BufferedWriter writer = new BufferedWriter(
                    new FileWriter(buttonStore.toString(), true)
            );
            writer.write(buttonInfo);
            writer.close();
            Toast successToast = Toast.makeText(getContext(), "Button saved", Toast.LENGTH_SHORT);
            successToast.setMargin(50, 50);
            successToast.show();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
            Toast errorToast = Toast.makeText(getContext(), "Button not saved: FileNotFoundException", Toast.LENGTH_SHORT);
            errorToast.setMargin(50, 50);
            errorToast.show();
        } catch (IOException e) {
            e.printStackTrace();
            Toast errorToast = Toast.makeText(getContext(), "Button not saved: IOException", Toast.LENGTH_SHORT);
            errorToast.setMargin(50, 50);
            errorToast.show();
        }
    }

    public void readFile(LinearLayout emoteListLayout) {
        System.out.println("entering readfile");
        File internalStorageDir = getContext().getFilesDir();
        File buttonStore = new File(internalStorageDir, "buttons.txt");
        System.out.println(buttonStore.getAbsolutePath().toString());
        if (buttonStore.exists()) {
            System.out.println("File found");
            try {
                FileInputStream fileInputStream = getContext().openFileInput("buttons.txt");
                InputStreamReader inputStreamReader = new InputStreamReader(fileInputStream);

                BufferedReader reader = new BufferedReader(inputStreamReader);String lines;
                StringBuffer stringBuffer = new StringBuffer();
                while (reader.ready()) {
                    String buttonName = reader.readLine();
                    final String buttonCommand = reader.readLine();
                    Button nb = new Button(getActivity());
                    nb.setText(buttonName);
                    nb.setOnClickListener(new View.OnClickListener() {
                        @Override
                        public void onClick(View v) {
                            executeSSHcommand(buttonCommand);
                        }
                    });
                    try {
                        emoteListLayout.addView(nb);
                        Toast successToast = Toast.makeText(getContext(), "Button loaded", Toast.LENGTH_SHORT);
                        successToast.setMargin(50, 50);
                        successToast.show();
                    } catch (NullPointerException ee) {
                        ee.printStackTrace();
                        Toast errorToast = Toast.makeText(getContext(), "NullPointerException, not added", Toast.LENGTH_SHORT);
                        errorToast.setMargin(50, 50);
                        errorToast.show();
                        return;
                    }
                    Toast successToast = Toast.makeText(getContext(), "Added successfully", Toast.LENGTH_SHORT);
                    successToast.setMargin(50, 50);
                    successToast.show();
                }
            } catch (FileNotFoundException e) {
                e.printStackTrace();
                Toast errorToast = Toast.makeText(getContext(), "Buttons not loaded: FileNotFoundException", Toast.LENGTH_SHORT);
                errorToast.setMargin(50, 50);
                errorToast.show();
            } catch (IOException e) {
                e.printStackTrace();
                Toast errorToast = Toast.makeText(getContext(), "Buttons not loaded: IOException", Toast.LENGTH_SHORT);
                errorToast.setMargin(50, 50);
                errorToast.show();
            }
        } else {
            System.out.println("File not found");
        }
    }
}