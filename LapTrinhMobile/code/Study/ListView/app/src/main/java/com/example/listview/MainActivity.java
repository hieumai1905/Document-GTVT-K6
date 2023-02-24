package com.example.listview;

import android.os.Build;
import android.support.annotation.RequiresApi;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class MainActivity extends AppCompatActivity {

    //    ArrayList<Product> listProducts;
//    ListView listView;
//    Button btnDeleteProduct;
//    MyAdapter myAdapter;
//
//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);
//        init();
//        addDataForList();
//        setAdapterForList();
//        //Lắng nghe bắt sự kiện một phần tử danh sách được chọn
//        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
//            @Override
//            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
//                Product product = (Product) myAdapter.getItem(position);
//                //Làm gì đó khi chọn sản phẩm (ví dụ tạo một Activity hiện thị chi tiết, biên tập ..)
//                Toast.makeText(MainActivity.this, product.name, Toast.LENGTH_LONG).show();
//            }
//        });
//        btnDeleteProduct.setOnClickListener(v -> {
//            // xóa sản phẩm
//            if (listProducts.size() > 0) {
//                int index = 0;
//                listProducts.remove(index);
//
//                // Thông báo cho ListView biết là có dữ liẹu thay đổi (cập nhật lại).
//                myAdapter.notifyDataSetChanged();
//            }
//        });
//    }
//
//    private void setAdapterForList() {
//        MyAdapter adapter = new MyAdapter(listProducts);
//        listView.setAdapter(adapter);
//    }
//
//    private void addDataForList() {
//        listProducts.add(new Product(1, "Iphone 6", 500));
//        listProducts.add(new Product(2, "Iphone 7", 700));
//        listProducts.add(new Product(3, "Sony Abc", 800));
//        listProducts.add(new Product(4, "Samsung XYZ", 900));
//        listProducts.add(new Product(5, "SP 5", 500));
//        listProducts.add(new Product(6, "SP 6", 700));
//        listProducts.add(new Product(7, "SP 7", 800));
//        listProducts.add(new Product(8, "SP 8", 900));
//    }
//
//    private void init() {
//        listProducts = new ArrayList<>();
//        listView = findViewById(R.id.listproduct);
//
//        btnDeleteProduct = findViewById(R.id.delete);
//
//    }
    ArrayList<Product> listProduct;
    MyAdapter productListViewAdapter;
    ListView listViewProduct;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //Khoi tao ListProduct
        listProduct = new ArrayList<>();
        listProduct.add(new Product(1, "Iphone 6", 500));
        listProduct.add(new Product(2, "Iphone 7", 700));
        listProduct.add(new Product(3, "Sony Abc", 800));
        listProduct.add(new Product(4, "Samsung XYZ", 900));
        listProduct.add(new Product(5, "SP 5", 500));
        listProduct.add(new Product(6, "SP 6", 700));
        listProduct.add(new Product(7, "SP 7", 800));
        listProduct.add(new Product(8, "SP 8", 900));

        productListViewAdapter = new MyAdapter(listProduct);

        listViewProduct = findViewById(R.id.listproduct);
        listViewProduct.setAdapter(productListViewAdapter);


        //Lắng nghe bắt sự kiện một phần tử danh sách được chọn
        listViewProduct.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Product product = (Product) productListViewAdapter.getItem(position);
                //Làm gì đó khi chọn sản phẩm (ví dụ tạo một Activity hiện thị chi tiết, biên tập ..)
                Toast.makeText(MainActivity.this, product.name, Toast.LENGTH_LONG).show();
            }
        });


        findViewById(R.id.delete).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (listProduct.size() > 0) {
                    //Xoá phần tử đầu tiên của danh sách
                    int productpost = 0;
                    listProduct.remove(productpost);
                    //Thông báo cho ListView biết dữ liệu đã thay đổi (cập nhật, xoá ...)
                    productListViewAdapter.notifyDataSetChanged();
                }
            }
        });

        findViewById(R.id.sort).setOnClickListener(new View.OnClickListener() {

            @RequiresApi(api = Build.VERSION_CODES.N)
            @Override
            public void onClick(View view) {
//                Collections.sort(listProduct, new Comparator<Product>() {
//                    @Override
//                    public int compare(Product o1, Product o2) {
//                        return o1.getPrice() > (o2.getPrice()) ? 1 : -1;
//                    }
//                });

                listProduct.sort((o1, o2) -> o1.getPrice() > (o2.getPrice()) ? 1 : -1);
                productListViewAdapter.notifyDataSetChanged();
            }
        });

    }
}