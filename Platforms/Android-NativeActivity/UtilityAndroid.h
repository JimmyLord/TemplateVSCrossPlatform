#ifndef __UtilityAndroid_H__
#define __UtilityAndroid_H__

extern android_app* g_pAndroidApp;

char* LoadCompleteFile(const char* filename, long* length);
double MyGetSystemTime();

#endif //__UtilityAndroid_H__
