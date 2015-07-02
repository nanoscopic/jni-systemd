#include"com_codechild_SystemDTools.h"
#include<jni.h>
#include<stdio.h>

JNIEnv* create_vm();
JavaVM* jvm;

int main( int argc, char *argv[] ) {
    printf("test\n");
    JNIEnv *env = create_vm();
    printf("test2\n");
    
    jstring buf = (*env)->NewStringUTF( env, "blah" );
    jint res = Java_com_codechild_SystemDTools_sd_1notify( env, 0, 0, buf );
    
    (*jvm)->DestroyJavaVM( jvm );
    
    return 0;
}

JNIEnv* create_vm() {
    JNIEnv* env;
    JavaVMInitArgs args;
    JavaVMOption options[1];
    
    /* There is a new JNI_VERSION_1_4, but it doesn't add anything for the purposes of our example. */
    args.version = JNI_VERSION_1_6;
    args.nOptions = 1;
    options[0].optionString = "-Djava.class.path=/cygdrive/c/proj/jni_systemd";
    args.options = options;
    args.ignoreUnrecognized = JNI_FALSE;
    
    JNI_CreateJavaVM(&jvm, (void **)&env, &args);
    return env;
}