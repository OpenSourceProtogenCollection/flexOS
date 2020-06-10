package com.jaredtamana.protogenssh.ui.mouth;

// imports for base Android

import android.app.AlertDialog;
import android.os.Bundle;
import android.os.Handler;
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

// Material imports
import com.google.android.material.snackbar.BaseTransientBottomBar;
import com.google.android.material.snackbar.Snackbar;
import com.google.android.material.textfield.TextInputLayout;

// Self imports
import com.jaredtamana.protogenssh.R;
import com.jaredtamana.protogenssh.ui.Functions;

public class MouthFragment extends Fragment { // main fragment start

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        final View root = inflater.inflate(R.layout.fragment_home, container, false); // create fragment view
        Button fabCreateScript = root.findViewById(R.id.fab); // declare FAB reference
        final LinearLayout mEmoteList = root.findViewById(R.id.scrollViewEmoteListLayout); // declare emote scrollView reference
        Functions.readFile(mEmoteList, getString(R.string.mouthFile), getContext(), getActivity(), root.getRootView()); // read this fragment's data file and load the necessary buttons
        fabCreateScript.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // inflate dialog
                View mView = getLayoutInflater().inflate(R.layout.dialog_add_script, null);
                // declaring references
                AlertDialog.Builder mBuilder = new AlertDialog.Builder(getActivity());
                final TextInputLayout mScriptName = mView.findViewById(R.id.scriptName);
                final TextInputLayout mScriptPath = mView.findViewById(R.id.scriptPath);
                final RadioButton mRadioFullFace = mView.findViewById(R.id.radioFullFace);
                final RadioButton mRadioEyesOnly = mView.findViewById(R.id.radioEyesOnly);
                final RadioButton mRadioMouthOnly = mView.findViewById(R.id.radioMouthOnly);
                Button mBtnScriptCancel = mView.findViewById(R.id.btnCancelScript);
                Button mBtnScriptApply = mView.findViewById(R.id.btnApplyScript);
                mBuilder.setView(mView); // associate dialog builder with view
                final AlertDialog dialog = mBuilder.create(); // instantiate dialog
                dialog.show(); // show dialog
                mBtnScriptCancel.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        dialog.dismiss(); // when cancel button is clicked, dismiss dialog
                    }
                });
                // when apply button is clicked
                mBtnScriptApply.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        if (mScriptName.getEditText().getText().toString().trim().equals("")) { // if the name box is empty
                            mScriptName.setError("Please add a name for this script."); // create an alert on that box
                            return; // return OnClick so we don't commit the change
                        } else {
                            mScriptName.setError(null); // remove any error on the box
                        }
                        if (mScriptPath.getEditText().getText().toString().trim().equals("")) { // if the command box is empty
                            mScriptPath.setError("Please add a valid command for this script."); // create an alert on that box
                            return; // return OnClick so we don't commit the change
                        } else {
                            mScriptPath.setError(null); // remove any error on the box
                        }
                        Button nb = new Button(getActivity()); // create a new button
                        nb.setText(mScriptName.getEditText().getText().toString()); // set the text to the contents of the name box
                        nb.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) { // when this button is clicked
                                Handler h = new Handler();
                                h.post(new Runnable() {
                                    @Override
                                    public void run() {
                                        Functions.executeSSHcommand(mScriptPath.getEditText().getText().toString(), getContext(), root.getRootView()); // call executeSSHcommand with the command box contents
                                    }
                                });
                            }
                        });
                        try {
                            // check every radio button and write the button details to the corresponding file
                            if (mRadioFullFace.isChecked()) {
                                Functions.writeFile(mScriptName.getEditText().getText().toString(), mScriptPath.getEditText().getText().toString(), getString(R.string.fullFaceFile), getContext(), root.getRootView());
                            } else if (mRadioEyesOnly.isChecked()) {
                                Functions.writeFile(mScriptName.getEditText().getText().toString(), mScriptPath.getEditText().getText().toString(), getString(R.string.eyesFile), getContext(), root.getRootView());
                            } else if (mRadioMouthOnly.isChecked()) {
                                mEmoteList.addView(nb); // add button to the scrollView on this fragment
                                Functions.writeFile(mScriptName.getEditText().getText().toString(), mScriptPath.getEditText().getText().toString(), getString(R.string.mouthFile), getContext(), root.getRootView());
                            } else { // no radio buttons are checked, send a toast asking for one to be selected
                                Toast chooseCategoryToast = Toast.makeText(getContext(), "Please choose a category for this command.", Toast.LENGTH_SHORT);
                                chooseCategoryToast.show();
                                return; // so that we don't hit an exception
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
