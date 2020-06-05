package com.jaredtamana.protogenssh.ui.home;

// imports for base Android
import android.app.AlertDialog;
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

// Project imports
import com.google.android.material.textfield.TextInputLayout;
import com.jaredtamana.protogenssh.R;
import com.jaredtamana.protogenssh.ui.Functions;

public class HomeFragment extends Fragment { // main fragment start

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {

        final View root = inflater.inflate(R.layout.fragment_home, container, false);
        Button fabCreateScript = root.findViewById(R.id.fab);
        final LinearLayout mEmoteList = root.findViewById(R.id.scrollViewEmoteListLayout);
        Functions.readFile(mEmoteList, getString(R.string.fullFaceFile), getContext(), getActivity());
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
                                Functions.executeSSHcommand(mScriptPath.getEditText().getText().toString(), getContext());
                            }
                        });
                        try {
                            if (mRadioFullFace.isChecked()) {
                                mEmoteList.addView(nb);
                                Functions.writeFile(mScriptName.getEditText().getText().toString(), mScriptPath.getEditText().getText().toString(), getString(R.string.fullFaceFile), getContext());
                            } else if (mRadioEyesOnly.isChecked()) {
                                Functions.writeFile(mScriptName.getEditText().getText().toString(), mScriptPath.getEditText().getText().toString(), getString(R.string.eyesFile), getContext());
                            } else if (mRadioMouthOnly.isChecked()) {
                                Functions.writeFile(mScriptName.getEditText().getText().toString(), mScriptPath.getEditText().getText().toString(), getString(R.string.mouthFile), getContext());
                            } else {
                                Toast chooseCategoryToast = Toast.makeText(getContext(), "Please choose a category for this command.", Toast.LENGTH_SHORT);
                                chooseCategoryToast.setMargin(50, 50);
                                chooseCategoryToast.setGravity(Gravity.NO_GRAVITY, 0, 0);
                                chooseCategoryToast.show();
                                return;
                            }
                        } catch (NullPointerException ee) {
                            ee.printStackTrace();
                            Toast errorToast = Toast.makeText(getContext(), "NullPointerException, not added", Toast.LENGTH_SHORT);
                            errorToast.setGravity(Gravity.NO_GRAVITY, 0, 0);
                            errorToast.setMargin(50, 50);
                            errorToast.show();
                            dialog.dismiss();
                            return;
                        }
                        Toast successToast = Toast.makeText(getContext(), "Added successfully", Toast.LENGTH_SHORT);
                        successToast.setGravity(Gravity.NO_GRAVITY, 0, 0);
                        successToast.setMargin(50, 50);
                        successToast.show();

                        dialog.dismiss();
                    }
                });
            }
        });
        return root;
    }
}