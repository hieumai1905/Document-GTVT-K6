package com.example.imageview;

import android.graphics.drawable.Drawable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.content.res.AppCompatResources;
import android.view.View;
import android.widget.ImageButton;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {
    ImageView imgView;
    ImageButton imgBtn;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        imgView = findViewById(R.id.imgView);
        imgBtn = findViewById(R.id.imgBtn);
        imgBtn.setOnClickListener(v -> {
            Drawable drawable = AppCompatResources.getDrawable(MainActivity.this, R.drawable.anh1);
            imgView.setImageDrawable(drawable);
        });
        imgView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Drawable drawable = AppCompatResources.getDrawable(MainActivity.this, R.drawable.img1);
                imgView.setImageDrawable(drawable);
            }
        });
    }
}