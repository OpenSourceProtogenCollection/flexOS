package com.jaredtamana.protogenssh.ui.eyes;

// imports for base Android
import android.app.AlertDialog;
import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.Toast;

// AndroidX imports
import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.preference.PreferenceManager;

// Project imports
import com.google.android.material.snackbar.BaseTransientBottomBar;
import com.google.android.material.snackbar.Snackbar;
import com.google.android.material.textfield.TextInputLayout;
import com.jaredtamana.protogenssh.R;
import com.jaredtamana.protogenssh.ui.Functions;

public class EyesFragment extends Fragment { // main fragment start

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        final View root = inflater.inflate(R.layout.fragment_home, container, false);
        final Button fabCreateScript = root.findViewById(R.id.fab);
        final LinearLayout mEmoteList = root.findViewById(R.id.scrollViewEmoteListLayout);
        Functions.readFile(mEmoteList, getString(R.string.eyesFile), getContext(), getActivity(), root.getRootView());
        fabCreateScript.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder mBuilder = new AlertDialog.Builder(getActivity());
                View mView = getLayoutInflater().inflate(R.layout.dialog_add_script, null);
                final TextInputLayout mScriptName = mView.findViewById(R.id.scriptName);
                final TextInputLayout mScriptPath = mView.findViewById(R.id.scriptPath);
                final RadioButton mRadioFullFace = mView.findViewById(R.id.radioFullFace);
                final RadioButton mRadioEyesOnly = mView.findViewById(R.id.radioEyesOnly);
                final RadioButton mRadioMouthOnly = mView.findViewById(R.id.radioMouthOnly);
                Button mBtnScriptCancel = mView.findViewById(R.id.btnCancelScript);
                Button mBtnScriptApply = mView.findViewById(R.id.btnApplyScript);
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
                        if (mScriptName.getEditText().getText().toString().trim().equals("")) { // WHY IS THIS SO GROSS
                            mScriptName.setError("Please add a name for this script.");
                            return;
                        } else if (mScriptPath.getEditText().getText().toString().trim().equals("")) { // GOD
                            mScriptPath.setError("Please add a valid command for this script.");
                            return;
                        }
                        Button nb = new Button(getActivity());
                        nb.setText(mScriptName.getEditText().getText().toString());
                        nb.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {
                                Functions.executeSSHcommand(mScriptPath.getEditText().getText().toString(), getContext(), root.getRootView());
                            }
                        });
                        try {
                            if (mRadioFullFace.isChecked()) {
                                Functions.writeFile(mScriptName.getEditText().getText().toString(), mScriptPath.getEditText().getText().toString(), getString(R.string.fullFaceFile), getContext(), root.getRootView());
                                } else if (mRadioEyesOnly.isChecked()) {
                                mEmoteList.addView(nb);
                                Functions.writeFile(mScriptName.getEditText().getText().toString(), mScriptPath.getEditText().getText().toString(), getString(R.string.eyesFile), getContext(), root.getRootView());
                            } else if (mRadioMouthOnly.isChecked()) {
                                Functions.writeFile(mScriptName.getEditText().getText().toString(), mScriptPath.getEditText().getText().toString(), getString(R.string.mouthFile), getContext(), root.getRootView());
                            } else {
                                Toast chooseCategoryToast = Toast.makeText(getContext(), "Please choose a category for this command.", Toast.LENGTH_SHORT);
                                chooseCategoryToast.setMargin(50, 50);
                                chooseCategoryToast.setGravity(Gravity.NO_GRAVITY, 0, 0);
                                chooseCategoryToast.show();
                                return;
                            }
                        } catch (NullPointerException ee) {
                            ee.printStackTrace();
                            Snackbar.make(root.getRootView(), "NullPointerException, not added", BaseTransientBottomBar.LENGTH_SHORT);
                            dialog.dismiss();
                            return;
                        }
                        Snackbar.make(root.getRootView(), "Added successfully", BaseTransientBottomBar.LENGTH_SHORT);
                        dialog.dismiss();
                    }
                });
            }
        });
        return root;
    }
}