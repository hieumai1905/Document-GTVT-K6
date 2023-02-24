package com.example.activity;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class Activity2 extends AppCompatActivity {

    Button btnEdit;
    EditText txtEdit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_2);
        btnEdit = findViewById(R.id.btnFinsh);
        txtEdit = findViewById(R.id.txtEdit);
        txtEdit.setText(getIntent().getStringExtra("text"));
        btnEdit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent();
                intent.putExtra("text", txtEdit.getText().toString());
                setResult(RESULT_OK, intent);
                finish();
            }
        });
    }
}