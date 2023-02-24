package com.example.viewgroup;

import static android.view.Gravity.CENTER;

import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Gravity;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);

        LinearLayout layout = new LinearLayout(this);
        layout.setOrientation(LinearLayout.VERTICAL);
        layout.setBackgroundColor(0xFF00FF00);

        TextView textView = new TextView(this);
        textView.setText("Text view Here");
        textView.setTextColor(Color.RED);
        textView.setGravity(CENTER);

        layout.addView(textView);

        Button button = new Button(this);
        button.setText("Button Here");
        layout.addView(button);

        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.WRAP_CONTENT,
                LinearLayout.LayoutParams.WRAP_CONTENT
        );
        button.setLayoutParams(params);

        setContentView(layout);
    }
}