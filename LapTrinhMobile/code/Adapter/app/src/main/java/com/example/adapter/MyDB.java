package com.example.adapter;

import android.content.Context;
import android.database.Cursor;
import android.database.DatabaseErrorHandler;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Build;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.annotation.RequiresApi;

import java.util.ArrayList;

public class MyDB extends SQLiteOpenHelper {
    public static final String TableName = "ContactTable";
    public static final String Id = "Id";
    public static final String Name = "Fullname";
    public static final String Phone = "Phonenumber";
    public static final String Image = "Image";

    public MyDB(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
    }

    public MyDB(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version, @Nullable DatabaseErrorHandler errorHandler) {
        super(context, name, factory, version, errorHandler);
    }

    @RequiresApi(api = Build.VERSION_CODES.P)
    // @RequiresApi(api = Build.VERSION_CODES.P) dùng để chỉ ra API nào mới có thể sử dụng được hàm này.
    //Build.VERSION_CODES.P là API 28
    public MyDB(@Nullable Context context, @Nullable String name, int version, @NonNull SQLiteDatabase.OpenParams openParams) {
        super(context, name, version, openParams);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        String sqlCreate = "CREATE TABLE " + TableName + "(" + Id + " INTEGER PRIMARY KEY, " + Name + " TEXT, " + Phone + " TEXT, " + Image + " TEXT)";
        sqLiteDatabase.execSQL(sqlCreate);
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
        sqLiteDatabase.execSQL("DROP TABLE IF EXISTS " + TableName);
        onCreate(sqLiteDatabase);
    }

    // lay tat ca cac dong trong bang table contact tra ve dang arraylist
    public ArrayList<Contact> getContactList() {
        ArrayList<Contact> contactList = new ArrayList<>();
        SQLiteDatabase db = this.getReadableDatabase();
        String sql = "select * from ContactTable";
        Cursor cursor = db.rawQuery(sql, null, null);
        while (cursor.moveToNext()) {
            int id = cursor.getInt(0);
            String name = cursor.getString(1);
            String phone = cursor.getString(2);
            String image = cursor.getString(3);
            contactList.add(new Contact(id, name, phone, image));
        }
        return contactList;
    }

    public void addContact(int id, String Fullname, String Phonenumber, String Image) {
        SQLiteDatabase db = this.getReadableDatabase();
        String sql = "insert into ContactTable (Id, Fullname, Phonenumber, Image) values (?,?,?,?)";
        db.execSQL(sql, new Object[]{id, Fullname, Phonenumber, Image});
        db.close();
    }

    public void upgradeContact(int id, String Fullname, String Phonenumber, String Image) {
        SQLiteDatabase db = this.getWritableDatabase();
        String sql = "update ContactTable set Fullname = ?, Phonenumber = ?, Image = ? where Id = ?";
        db.execSQL(sql, new Object[]{Fullname, Phonenumber, Image, id});
        db.close();
    }
}
