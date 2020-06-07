package com.jaredtamana.protogenssh.ui.settings;

// base imports
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.os.Build;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

// AndroidX imports
import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.security.crypto.EncryptedSharedPreferences;
import androidx.security.crypto.MasterKeys;

// Material imports
import com.google.android.material.snackbar.BaseTransientBottomBar;
import com.google.android.material.snackbar.Snackbar;
import com.google.android.material.textfield.TextInputEditText;

// Self imports
import com.jaredtamana.protogenssh.R;
import com.jaredtamana.protogenssh.ui.Functions;


public class SettingsFragment extends Fragment { // main fragment start


    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        View root = inflater.inflate(R.layout.fragment_settings, container, false); // create fragment view
        // reference declarations
        Button mFullFaceReset = root.findViewById(R.id.btnFullFaceReset);
        Button mEyesOnlyReset = root.findViewById(R.id.btnEyesOnlyReset);
        Button mMouthOnlyReset = root.findViewById(R.id.btnMouthOnlyReset);
        Button mFullReset = root.findViewById(R.id.btnFullReset);
        Button mCredentialsSave = root.findViewById(R.id.btnCredentialsSave);
        final TextInputEditText mInputHost = root.findViewById(R.id.inputHost);
        final TextInputEditText mInputPort = root.findViewById(R.id.inputPort);
        final TextInputEditText mInputUsername = root.findViewById(R.id.inputUsername);
        final TextInputEditText mInputPassword = root.findViewById(R.id.inputPassword);
        final int sdk = Build.VERSION.SDK_INT;
        mFullFaceReset.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) { // when Reset Full Face Buttons button is clicked
                AlertDialog.Builder builder = new AlertDialog.Builder(getContext()); // begin building dialog
                builder.setTitle(R.string.buttons_delete_title); // set title
                builder.setMessage(R.string.buttons_delete_text); // set body text
                builder.setPositiveButton(R.string.yes, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) { // when yes button is pressed
                        Functions.deleteFile(getString(R.string.fullFaceFile), getContext(), getView()); // delete file
                    }
                });
                builder.setNegativeButton(R.string.no, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) { // when no button is pressed
                        // do nothing
                    }
                });
                AlertDialog dialog = builder.create(); // instantiate dialog
                dialog.show(); // show dialog
            }
        });
        mEyesOnlyReset.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder builder = new AlertDialog.Builder(getContext());
                builder.setTitle(R.string.buttons_delete_title);
                builder.setMessage(R.string.buttons_delete_text);
                builder.setPositiveButton(R.string.yes, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Functions.deleteFile(getString(R.string.eyesFile), getContext(), getView());
                    }
                });
                builder.setNegativeButton(R.string.no, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        // nothing
                    }
                });
                AlertDialog dialog = builder.create();
                dialog.show();
            }
        });
        mMouthOnlyReset.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder builder = new AlertDialog.Builder(getContext());
                builder.setTitle(R.string.buttons_delete_title);
                builder.setMessage(R.string.buttons_delete_text);
                builder.setPositiveButton(R.string.yes, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Functions.deleteFile(getString(R.string.mouthFile), getContext(), getView());
                    }
                });
                builder.setNegativeButton(R.string.no, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        // nothing
                    }
                });
                AlertDialog dialog = builder.create();
                dialog.show();
            }
        });
        mFullReset.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder builder = new AlertDialog.Builder(getContext());
                builder.setTitle(R.string.buttons_delete_title);
                builder.setMessage(R.string.all_buttons_delete_text);
                builder.setPositiveButton(R.string.all_buttons_yes, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Functions.deleteFile(getString(R.string.fullFaceFile), getContext(), getView());
                        Functions.deleteFile(getString(R.string.eyesFile), getContext(), getView());
                        Functions.deleteFile(getString(R.string.mouthFile), getContext(), getView());
                    }
                });
                builder.setNegativeButton(R.string.all_buttons_no, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        // nothing
                    }
                });
                AlertDialog dialog = builder.create();
                dialog.show();
            }
        });
        try {
            mCredentialsSave.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) { // when save button is clicked
                    if (mInputUsername.getEditableText().toString().trim().equals("")) { // if username field is empty
                        mInputUsername.setError(getString(R.string.username_empty_error)); // set error flag on field
                        return; // stop before exception is thrown
                    }
                    if (mInputPort.getEditableText().toString().trim().equals("")) { // if port field is empty
                        mInputPort.setError(getString(R.string.port_empty_error)); // set error flag on field
                        return; // stop before exception is thrown
                    }
                    if (mInputHost.getEditableText().toString().trim().equals("")) { // if host field is empty
                        mInputHost.setError(getString(R.string.host_empty_error)); // set error flag on field
                        return; // stop before exception is thrown
                    }

                    SharedPreferences sharedPreferences;

                    if (sdk >= 23) {
                        String masterKeyAlias;
                        try {
                            masterKeyAlias = MasterKeys.getOrCreate(MasterKeys.AES256_GCM_SPEC);
                            sharedPreferences = EncryptedSharedPreferences.create(
                                    "secret_shared_prefs",
                                    masterKeyAlias,
                                    getContext(),
                                    EncryptedSharedPreferences.PrefKeyEncryptionScheme.AES256_SIV,
                                    EncryptedSharedPreferences.PrefValueEncryptionScheme.AES256_GCM
                            );
                        } catch (Exception e) {
                            e.printStackTrace();
                            Snackbar.make(getView(), "Failed to create encryption keys (IOException or SecurityException)", BaseTransientBottomBar.LENGTH_LONG)
                                    .show();
                            return;
                        }
                    } else {
                        sharedPreferences = getActivity().getSharedPreferences("credentials", Context.MODE_PRIVATE); // get credentials file
                    }

                    SharedPreferences.Editor editor = sharedPreferences.edit();
                    editor.putString(getString(R.string.host_sharedprop), mInputHost.getEditableText().toString());
                    editor.putInt(getString(R.string.port_sharedprop), Integer.parseInt(mInputPort.getEditableText().toString())); // change port key to input
                    editor.putString(getString(R.string.username_sharedprop), mInputUsername.getEditableText().toString()); // change username key to input
                    editor.putString(getString(R.string.password_sharedprop), mInputPassword.getEditableText().toString());
                    editor.apply(); // apply changes
                    Functions.hideKeyboard(getContext(), getView()); // hide the keyboard, it's no longer needed
                    Snackbar.make(getView(), R.string.cred_save_success_snack, BaseTransientBottomBar.LENGTH_SHORT)
                            .show(); // when credentials are successfully committed, send a snackbar to the user
                }


     /*           String masterKeyAlias = MasterKeys.getOrCreate(MasterKeys.AES256_GCM_SPEC);

                SharedPreferences sharedPreferences = EncryptedSharedPreferences.create(
                        "secret_shared_prefs",
                        masterKeyAlias,
                        getContext(),
                        EncryptedSharedPreferences.PrefKeyEncryptionScheme.AES256_SIV,
                        EncryptedSharedPreferences.PrefValueEncryptionScheme.AES256_GCM
                );

                // use the shared preferences and editor as you normally would
                SharedPreferences.Editor editor = sharedPreferences.edit();
                */
            });
        } catch (Exception e) {
            e.printStackTrace();
            Functions.hideKeyboard(getContext(), getView()); // hide the keyboard, it's no longer needed
            Snackbar.make(getView(), R.string.cred_save_fail_snack, BaseTransientBottomBar.LENGTH_LONG)
                    .show(); // send a snackbar letting user know an error occurred
        }

        return root;
    }
}
