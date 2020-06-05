package com.jaredtamana.protogenssh.ui.settings;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
//import androidx.security.crypto.EncryptedSharedPreferences;
//import androidx.security.crypto.MasterKeys;

import com.google.android.material.textfield.TextInputEditText;
import com.jaredtamana.protogenssh.R;
import com.jaredtamana.protogenssh.ui.Functions;

public class SettingsFragment extends Fragment { // main fragment start


    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        View root = inflater.inflate(R.layout.fragment_settings, container, false);
        Button mFullFaceReset = root.findViewById(R.id.btnFullFaceReset);
        Button mEyesOnlyReset = root.findViewById(R.id.btnEyesOnlyReset);
        Button mMouthOnlyReset = root.findViewById(R.id.btnMouthOnlyReset);
        Button mFullReset = root.findViewById(R.id.btnFullReset);
        Button mCredentialsSave = root.findViewById(R.id.btnCredentialsSave);
        final TextInputEditText mInputUsername = root.findViewById(R.id.inputUsername);
        final TextInputEditText mInputPort = root.findViewById(R.id.inputPort);
        final TextInputEditText mInputPassword = root.findViewById(R.id.inputPassword);
        mFullFaceReset.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder builder = new AlertDialog.Builder(getContext());
                builder.setTitle(R.string.buttons_delete_title);
                builder.setMessage(R.string.buttons_delete_text);
                builder.setPositiveButton(R.string.yes, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        Functions.deleteFile(getString(R.string.fullFaceFile), getContext(), getView());
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
                public void onClick(View v) {
                    if (mInputUsername.getEditableText().toString().trim().equals("")){
                        mInputUsername.setError(getString(R.string.username_empty_error));
                        return;
                    }
                    if (mInputPort.getEditableText().toString().trim().equals("")){
                        mInputPort.setError(getString(R.string.port_empty_error));
                        return;
                    }
                    SharedPreferences credentialPrefs = getActivity().getSharedPreferences("credentials", Context.MODE_PRIVATE);
                    SharedPreferences.Editor editor = credentialPrefs.edit();
                    editor.putString(getString(R.string.usernae_sharedprop), mInputUsername.getEditableText().toString());
                    editor.putInt(getString(R.string.port_sharedprop), Integer.parseInt(mInputPort.getEditableText().toString()));
                    editor.putString(getString(R.string.password_sharedprop), mInputPassword.getEditableText().toString()); // I want to implement encryption as shown below but am having issues
                    editor.apply();
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
        }

        return root;
    }
}
