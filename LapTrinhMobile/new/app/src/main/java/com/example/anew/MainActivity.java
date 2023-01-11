package com.example.anew;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    Button btnShow;
    TextView textView3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // tham chieu
        btnShow = findViewById(R.id.btnShow);

        // thiet lap lai thuoc tinh cho view bang setter
        textView3.setText("Name");
        btnShow.setText("SHOW");

        // bat su kien
        btnShow.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // xu ly su kien
                Toast.makeText(MainActivity.this, textView3.getText(), Toast.LENGTH_SHORT).show();
                // nghia la hien thi ra o  thong bao co noi dung la textView3.getText() va hien thi nhanh nhat
                // Toast la 1 thong bao
                // MainActivity.this la tham chieu toi MainActivity
                // Toast.LENGTH_SHORT la thoi gian hien thi thong bao
            }
        });
    }
}