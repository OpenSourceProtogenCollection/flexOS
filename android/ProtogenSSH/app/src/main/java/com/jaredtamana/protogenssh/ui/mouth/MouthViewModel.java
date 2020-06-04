package com.jaredtamana.protogenssh.ui.mouth;

import androidx.lifecycle.LiveData;
import androidx.lifecycle.MutableLiveData;
import androidx.lifecycle.ViewModel;

public class MouthViewModel extends ViewModel {

    private MutableLiveData<String> mText;

    public MouthViewModel() {
        mText = new MutableLiveData<>();
        mText.setValue("This is mouth fragment");
    }

    public LiveData<String> getText() {
        return mText;
    }
}