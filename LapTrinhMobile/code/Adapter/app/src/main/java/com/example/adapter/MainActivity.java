package com.example.adapter;

import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;
import java.util.Comparator;

@RequiresApi(api = Build.VERSION_CODES.N)

public class MainActivity extends AppCompatActivity {
    public static final int REQUEST_CODE_ADD = 1;
    private ArrayList<Contact> listContact;
    private Adapter adapter;
    private EditText txtSearch;
    private ListView listViewContact;
    private FloatingActionButton btnNewContact;
    private int selectedItem;
    static MyDB db;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        listContact = new ArrayList<>();

        // add to database
        db = new MyDB(this, "ContactTable", null, 1);
        db.addContact(1, "mai van hieu", "0123456789", "image");
        db.addContact(2, "mai van hieu", "0123456789", "image");
        db.addContact(3, "mai van hieu", "0123456789", "image");
        db.addContact(4, "mai van hieu", "0123456789", "image");

        listContact = db.getContactList();

        adapter = new Adapter(listContact, this);
        txtSearch = findViewById(R.id.etSearch);
        listViewContact = findViewById((R.id.lstContact));
        btnNewContact = findViewById(R.id.btnAdd);
        listViewContact.setAdapter(adapter);
        setEventForListView();
    }

    private void setEventForListView() {
        txtSearch.addTextChangedListener(new TextWatcher() {

            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                adapter.getFilter().filter(s);
            }

            @Override
            public void afterTextChanged(Editable s) {

            }
        });

        btnNewContact.setOnClickListener(v -> {
            startActivityForResult(new Intent(MainActivity.this, NewContact.class), REQUEST_CODE_ADD);
        });

        listViewContact.setOnItemClickListener((parent, view, position, id) -> {
            selectedItem = position;
            Intent intent = new Intent(MainActivity.this, NewContact.class);
            Contact contact = listContact.get(position);
            intent.putExtra("id", String.valueOf(contact.getId()));
            intent.putExtra("name", contact.getName());
            intent.putExtra("phone", contact.getPhone());
            startActivityForResult(intent, REQUEST_CODE_ADD);
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        Toast.makeText(getApplicationContext(), String.valueOf(resultCode), Toast.LENGTH_LONG).show();
        if (requestCode == REQUEST_CODE_ADD) {
            if (resultCode == REQUEST_CODE_ADD) {
                for (int i = 0; i < listContact.size(); i++) {
                    if (listContact.get(i).getId() == Integer.parseInt(data.getStringExtra("id"))) {
                        listContact.get(i).setName(data.getStringExtra("name"));
                        listContact.get(i).setPhone(data.getStringExtra("phone"));
                        break;
                    }
                }
            }
            if (resultCode == 1000) {
                listContact.remove(selectedItem);
            }
            adapter.notifyDataSetChanged();
        }
        if (requestCode == 1000) {
            listContact.remove(selectedItem);
            adapter.notifyDataSetChanged();
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = new MenuInflater(this);
        inflater.inflate(R.menu.actionmenu, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @RequiresApi(api = Build.VERSION_CODES.N)
    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()) {
            case R.id.mnuSortName:
                listContact.sort((contact1, contact2) -> {
                    String name1 = contact1.getName().split(" ")[contact1.getName().split(" ").length - 1];
                    String name2 = contact2.getName().split(" ")[contact2.getName().split(" ").length - 1];
                    return name1.compareTo(name2);
                });
                break;
            case R.id.mnuSortPhone:
                listContact.sort(Comparator.comparing(Contact::getPhone));
                break;

            case R.id.mnuCall:
                Intent intent = new Intent(Intent.ACTION_DIAL);
                intent.setData(Uri.parse("tel:" + listContact.get(selectedItem).getPhone()));
                startActivity(intent);
                break;
            case R.id.mnuSend:
                Intent intent1 = new Intent(Intent.ACTION_SEND);
                intent1.setType("text/plain");
                intent1.putExtra(Intent.EXTRA_TEXT, listContact.get(selectedItem).getPhone());
                startActivity(intent1);
                break;
            case R.id.mnuLink:
                Intent intent2 = new Intent(Intent.ACTION_VIEW);
                intent2.setData(Uri.parse("https://www.google.com/search?q=" + listContact.get(selectedItem).getName()));
                startActivity(intent2);
                break;
            default:
                break;
        }
        adapter.notifyDataSetChanged();
        return super.onOptionsItemSelected(item);
    }

}
