package com.example.cc.ccjni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = (TextView) findViewById(R.id.cc);
        Hellojni hellojni = new Hellojni();
        String s = hellojni.sayHello("ssssssssssssss");
        int cc = hellojni.sum(1,2);
        tv.setText(s+"   "+cc);
    }
}
