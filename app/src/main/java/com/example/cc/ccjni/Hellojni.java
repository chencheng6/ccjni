package com.example.cc.ccjni;

/**
 * Created by cc on 2017/11/11.
 */

public class Hellojni {
    {
        System.loadLibrary("ccjni");
    }
    public native String cc();
    public native int sum(int x, int y);
    public native String sayHello(String s);
}
