package com.example.adapter;

import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

public class NewContact extends AppCompatActivity {
    private EditText txtId, txtName, txtPhone;
    private ImageView image;
    private Button btnAdd, btnCancel, btnDelete;
    private Intent intent;

    public NewContact() {
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_new_contact);
        intent = getIntent();
        txtId = findViewById(R.id.txtId);
        txtName = findViewById(R.id.txtFullname);
        txtPhone = findViewById(R.id.txtPhone);
        image = findViewById(R.id.imgContact);
        btnAdd = findViewById(R.id.btnAdd);
        btnCancel = findViewById(R.id.btnCancel);
        btnDelete = findViewById(R.id.btnDelete);

        if (intent != null) {
            txtId.setText(intent.getStringExtra("id"));
            txtName.setText(intent.getStringExtra("name"));
            txtPhone.setText(intent.getStringExtra("phone"));
        }
        btnDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                intent.putExtra("index", 10);
                setResult(1000, intent);
                finish();
            }
        });
        btnAdd.setOnClickListener(new View.OnClickListener() {
            @RequiresApi(api = Build.VERSION_CODES.N)
            @Override
            public void onClick(View v) {
                intent.putExtra("id", txtId.getText().toString());
                intent.putExtra("name", txtName.getText().toString());
                intent.putExtra("phone", txtPhone.getText().toString());
                setResult(MainActivity.REQUEST_CODE_ADD, intent);
                finish();
            }
        });
        btnCancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                setResult(RESULT_CANCELED, intent);
                finish();
            }
        });


    }
}