#include"com_codechild_SystemDTools.h"
#include<systemd/sd-daemon.h>

JNIEXPORT jint JNICALL Java_com_codechild_SystemDTools_sd_1notify( JNIEnv *env, jobject self, jint do_unset, jstring state ) {
    const char *str = (*env)->GetStringUTFChars( env, state, 0 );
    int res = sd_notify( (int) do_unset, str );
    (*env)->ReleaseStringUTFChars( env, state, 0 );
    return (jint) res;
}
