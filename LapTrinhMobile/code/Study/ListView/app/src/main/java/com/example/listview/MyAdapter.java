package com.example.listview;

import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.ArrayList;

public class MyAdapter extends BaseAdapter {
    final ArrayList<Product> listProducts;

    public MyAdapter(ArrayList<Product> listProducts) {
        this.listProducts = listProducts;
    }


    @Override
    public int getCount() {
        return listProducts.size();
    }

    @Override
    public Object getItem(int i) {
        return listProducts.get(i);
    }

    @Override
    public long getItemId(int i) {
        return listProducts.get(i).getProductID();
    }

    @Override
    public View getView(int i, View view, ViewGroup viewGroup) { // các tham số lần lượt là vị trí của item, view của item, viewgroup chứa item
        // phương thức này có tác dụng tạo ra view cho item
        // view ở đây là phần tử listView, nếu view != null thì không cần tạo mới
        // view này được sử dụng lại, chỉ việc cập nhật nội dung mới.
        // nếu null thì tạo mới
        View viewProduct;
        if (view == null) {
            viewProduct = View.inflate(viewGroup.getContext(), R.layout.product_view, null);
            // View.inflate() sẽ tạo ra 1 view mới từ layout
            // Các tham số lần lượt là context, layout, root
        } else {
            viewProduct = view;
        }

        // bind dữ liệu phần tử vào view
        Product product = (Product) getItem(i);
        ((TextView) viewProduct.findViewById(R.id.idproduct)).setText(String.format("ID = %d", product.productID));
        ((TextView) viewProduct.findViewById(R.id.nameproduct)).setText(String.format("Tên SP : %s", product.name));
        ((TextView) viewProduct.findViewById(R.id.priceproduct)).setText(String.format("Giá %d", product.price));
        return viewProduct;
    }
}
