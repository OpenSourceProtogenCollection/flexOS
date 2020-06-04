package com.jaredtamana.protogenssh.ui.eyes;

import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;
import androidx.lifecycle.ViewModel;

public class EyesViewModel extends ViewModel {

    private MutableLiveData<String> mText;

    public EyesViewModel() {
        mText = new MutableLiveData<>();
        mText.setValue("This is eyes fragment");
    }

    public LiveData<String> getText() {
        return mText;
    }
}