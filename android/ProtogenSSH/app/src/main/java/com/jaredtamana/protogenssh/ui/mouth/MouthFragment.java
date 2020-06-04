package com.jaredtamana.protogenssh.ui.mouth;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProviders;

import com.jaredtamana.protogenssh.R;

public class MouthFragment extends Fragment {

    private com.jaredtamana.protogenssh.ui.mouth.MouthViewModel eyesViewModel;

    public View onCreateView(@NonNull LayoutInflater inflater,
                             ViewGroup container, Bundle savedInstanceState) {
        eyesViewModel =
                ViewModelProviders.of(this).get(com.jaredtamana.protogenssh.ui.mouth.MouthViewModel.class);
        View root = inflater.inflate(R.layout.fragment_mouth, container, false);
        final TextView textView = root.findViewById(R.id.text_mouth);
        eyesViewModel.getText().observe(getViewLifecycleOwner(), new Observer<String>() {
            @Override
            public void onChanged(@Nullable String s) {
                textView.setText(s);
            }
        });
        return root;
    }
}