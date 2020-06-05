package com.jaredtamana.protogenssh.ui.home;

// imports for base Android
import android.app.AlertDialog;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.Toast;

// AndroidX imports
import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModelProviders;

// Project imports
import com.jaredtamana.protogenssh.R;
import com.jaredtamana.protogenssh.ui.eyes.EyesFragment;
import com.jaredtamana.protogenssh.ui.mouth.MouthFragment;
import com.jaredtamana.protogenssh.ui.Functions;

@SuppressWarnings("ALL")
public class HomeFragment extends Fragment { // main fragment start

    private HomeViewModel homeViewModel;

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        homeViewModel =
                ViewModelProviders.of(this).get(HomeViewModel.class);
        final View root = inflater.inflate(R.layout.fragment_home, container, false);
        Button fabCreateScript = (Button) root.findViewById(R.id.fab);
        final LinearLayout mEmoteList = (LinearLayout) root.findViewById(R.id.scrollViewEmoteListLayout);
        Functions.readFile(mEmoteList, "buttonsMouthOnly.txt", getContext(), getActivity());
        fabCreateScript.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                AlertDialog.Builder mBuilder = new AlertDialog.Builder(getActivity());
                View mView = getLayoutInflater().inflate(R.layout.dialog_add_script, null);
                final EditText mScriptName = (EditText) mView.findViewById(R.id.scriptName);
                final EditText mScriptPath = (EditText) mView.findViewById(R.id.scriptPath);
                final RadioButton mRadioFullFace = (RadioButton) mView.findViewById(R.id.radioFullFace);
                final RadioButton mRadioEyesOnly = (RadioButton) mView.findViewById(R.id.radioEyesOnly);
                final RadioButton mRadioMouthOnly = (RadioButton) mView.findViewById(R.id.radioMouthOnly);
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
                        if (mScriptName.getText().toString().trim().equals("")) { // WHY IS THIS SO GROSS
                            mScriptName.setError("Please add a name for this script.");
                            return;
                        } else if (mScriptPath.getText().toString().trim().equals("")) { // GOD
                            mScriptPath.setError("Please add a valid command for this script.");
                            return;
                        }
                        Button nb = new Button(getActivity());
                        nb.setText(mScriptName.getText().toString());
                        nb.setOnClickListener(new View.OnClickListener() {
                            @Override
                            public void onClick(View v) {
                                Functions.executeSSHcommand(mScriptPath.getText().toString(), getContext());
                            }
                        });
                        try {
                            if (mRadioFullFace.isChecked()) {
                                mEmoteList.addView(nb);
                                Functions.writeFile(mScriptName.getText().toString(), mScriptPath.getText().toString(), "buttonsFullFace.txt", getContext());
                            } else if (mRadioEyesOnly.isChecked()) {
                                Functions.writeFile(mScriptName.getText().toString(), mScriptPath.getText().toString(), "buttonsEyesOnly.txt", getContext());
                            } else if (mRadioMouthOnly.isChecked()) {
                                Functions.writeFile(mScriptName.getText().toString(), mScriptPath.getText().toString(), "buttonsMouthOnly.txt", getContext());
                            } else {
                                Toast chooseCategoryToast = Toast.makeText(getContext(), "Please choose a category for this command.", Toast.LENGTH_SHORT);
                                chooseCategoryToast.setMargin(50, 50);
                                chooseCategoryToast.show();
                                return;
                            }
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
}