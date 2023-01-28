package com.example.firstappcntt4;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.RadioButton;
import android.widget.Spinner;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    EditText txtName, txtPhone;
    RadioButton rdoMale, rdoFemale;
    Spinner spnCity;
    Button addRecord;
    ListView listRecord;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setComponents();
    }

    private void setComponents() {
        txtName = findViewById(R.id.txtName);
        txtPhone = findViewById(R.id.txtPhone);
        rdoMale = findViewById(R.id.rdoMale);
        rdoFemale = findViewById(R.id.rdoFemale);
        spnCity = findViewById(R.id.spnCity);
        addRecord = findViewById(R.id.addRecord);
        listRecord = findViewById(R.id.listRecord);
        addRecord.setOnClickListener(addRecordListener);
    }

    private View.OnClickListener addRecordListener = new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            String name = txtName.getText().toString();
            String phone = txtPhone.getText().toString();
            String male = rdoMale.isChecked() ? "Nam" : "Nữ";
            String city = spnCity.getSelectedItem().toString();
            String result = name + " - " + male + " - " + phone + " - " + city;
            List<String> list = new ArrayList<>();
            for (int i = 0; i < listRecord.getCount(); i++) {
                list.add(listRecord.getItemAtPosition(i).toString());
            }
            list.add(result);
            ArrayAdapter<String> adapter = new ArrayAdapter<String>(MainActivity.this, android.R.layout.simple_list_item_1, list);
            listRecord.setAdapter(adapter);
            clearOption();
        }
    };

    private void clearOption() {
        txtName.setText("");
        txtPhone.setText("");
        rdoMale.setChecked(false);
        rdoFemale.setChecked(false);
        spnCity.setSelection(0);
    }

}