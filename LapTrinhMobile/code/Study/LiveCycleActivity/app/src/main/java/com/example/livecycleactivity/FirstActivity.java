package com.example.livecycleactivity;


import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.ActionMode;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class FirstActivity extends Activity {
    private String tag = "FirstActivityLog";
    Button btn;
    TextView textView;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout_first_activity); // phương thức này sẽ thực hiện việc nạp layout cho activity
        Log.i(tag, "onCreate()");   // Log.i dùng để in ra log thông báo
        btn = findViewById(R.id.btn);
        textView = findViewById(R.id.textView);
        btn.setOnClickListener(v -> {   // v-> đây là một biểu thức lambda (lambda expression). Nó có nghĩa là khi click vào button thì sẽ thực hiện hành động sau
//            Toast.makeText(this, "Hello", Toast.LENGTH_SHORT).show();

            // từ activity này chuyển sang activity khác ta dùng phương thức startActivity
            Intent intent = new Intent(this, ActivitySecond.class);
            // intent là một đối tượng có chức năng chuyển đổi từ activity này sang activity khác
            startActivity(intent);
        });
    }

    @Override
    protected void onStart() {
        super.onStart();
        Log.d(tag, "onStart");

    }

    @Override
    protected void onResume() {
        super.onResume();
        Log.d(tag, "onResume");

    }

    @Override
    protected void onPause() {
        super.onPause();
        Log.d(tag, "onPause");  // log.d dùng để in ra log thông báo

    }

    @Override
    protected void onStop() {
        super.onStop();
        Log.d(tag, "onStop");

    }

    @Override
    protected void onRestart() {
        super.onRestart();
        Log.d(tag, "onRestart");

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.d(tag, "onDestroy");

    }
}
