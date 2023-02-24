package com.example.adapter;

import android.app.Activity;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.Filter;
import android.widget.Filterable;
import android.widget.TextView;

import java.util.ArrayList;

public class Adapter extends BaseAdapter implements Filterable {
    private ArrayList<Contact> listContact;
    private ArrayList<Contact> listContactBackup;
    private Activity context;
    private LayoutInflater inflater;

    public Adapter() {
    }

    public Adapter(ArrayList<Contact> data, Activity activity) {
        this.listContact = data;
        this.context = activity;
        this.inflater = (LayoutInflater) activity.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    }

    @Override
    public int getCount() {
        return listContact.size();
    }

    @Override
    public Object getItem(int i) {
        return listContact.get(i);
    }

    @Override
    public long getItemId(int i) {
        return listContact.get(i).getId();
    }

    @Override
    public View getView(int i, View view, ViewGroup viewGroup) {
        View viewContact = view;
        if (view == null) {
            viewContact = inflater.inflate(R.layout.contactitem, null);
        }
        ((TextView) viewContact.findViewById(R.id.txtName)).setText(listContact.get(i).getName());
        ((TextView) viewContact.findViewById(R.id.txtPhone)).setText(listContact.get(i).getPhone());
        return viewContact;
    }

    @Override
    public Filter getFilter() {
        return new Filter() {
            @Override
            protected FilterResults performFiltering(CharSequence charSequence) {
                FilterResults filterResults = new FilterResults();
                if (listContactBackup == null) {
                    listContactBackup = new ArrayList<>(listContact);
                }
                if (charSequence == null || charSequence.length() == 0) {
                    filterResults.values = listContactBackup;
                    filterResults.count = listContactBackup.size();
                } else {
                    ArrayList<Contact> listContactFilter = new ArrayList<>();
                    for (Contact contact : listContactBackup) {
                        if (contact.getName().toLowerCase().contains(charSequence.toString().toLowerCase())) {
                            listContactFilter.add(contact);
                        }
                    }
                    filterResults.values = listContactFilter;
                    filterResults.count = listContactFilter.size();
                }
                return filterResults;
            }

            @Override
            protected void publishResults(CharSequence charSequence, FilterResults filterResults) {
                listContact = (ArrayList<Contact>) filterResults.values;
                notifyDataSetChanged();
            }
        };
    }

}
