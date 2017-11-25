//
// Created by cc on 2017/11/11.
//
//自己创建一个c文件，实现自己定义的native方法，也就是.h文件中的方法
//引入自己生成的.h头文件
#include <com_example_cc_ccjni_Hellojni.h>
#include <string.h>
#include <android/log.h>

//返回一个字符串
JNIEXPORT jstring JNICALL Java_com_example_cc_ccjni_Hellojni_cc
        (JNIEnv * env, jobject jobj){
    return (*env)->NewStringUTF(env,"HelloWorld 我是用jni调用出来的字符串");
}

JNIEXPORT jint JNICALL Java_com_example_cc_ccjni_Hellojni_sum
        (JNIEnv *env, jobject jobjectj, jint a, jint b){
          int c = a+b;
          printf("printf c sum=%d\n", c);
          return c;
}


char* _JString2CStr(JNIEnv* env, jstring jstr) {

    char* rtn;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env,"GBK");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if(alen > 0) {
        rtn = (char*)malloc(alen+1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba,0);
    return rtn;
}

JNIEXPORT jstring JNICALL Java_com_example_cc_ccjni_Hellojni_sayHello
        (JNIEnv * env, jobject jobj, jstring jstr){
    char* fromJava = _JString2CStr(env,jstr);
    //char* fromJava = "cccccccccccc";
    char* fromC = "add I am from c";
    strcat(fromJava,fromC);
    return (*env)->NewStringUTF(env,fromJava);
}
