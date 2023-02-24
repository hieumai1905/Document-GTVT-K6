package com.example.restorestate;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    TextView message;
    Button button;

    private int m_lesson = 1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        message = findViewById(R.id.message);
        button = findViewById(R.id.button);

//        if (savedInstanceState != null) {
//            m_lesson = savedInstanceState.getInt("lesson");
//            updateMessage();
//        }

        button.setOnClickListener(view -> {
            m_lesson++;
            updateMessage();
        });
        updateMessage();

    }

    @Override
    protected void onRestoreInstanceState(@NonNull Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);
        m_lesson = savedInstanceState.getInt("lesson");
        updateMessage();
    }

    @Override
    protected void onSaveInstanceState(@NonNull Bundle outState) {
        super.onSaveInstanceState(outState);
        outState.putInt("lesson", m_lesson);
    }

    private void updateMessage() {
        message.setText("Lesson " + m_lesson);
    }
}