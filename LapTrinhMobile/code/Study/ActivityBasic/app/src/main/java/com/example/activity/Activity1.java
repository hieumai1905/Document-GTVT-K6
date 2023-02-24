package com.example.activity;

import android.content.Intent;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class Activity1 extends AppCompatActivity {
    static final int REQUEST_CODE_ACTIVITY_SECOND = 2;
    Button btnEdit;
    EditText txtEdit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_1);

        txtEdit = (EditText) findViewById(R.id.template);
        btnEdit = (Button) findViewById(R.id.btnEdit);

        btnEdit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Activity1.this, Activity2.class);
                intent.putExtra("text", txtEdit.getText().toString());
                startActivityForResult(intent, REQUEST_CODE_ACTIVITY_SECOND);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == REQUEST_CODE_ACTIVITY_SECOND && resultCode == RESULT_OK) {
            txtEdit.setText(data.getStringExtra("text"));
        }
    }
}