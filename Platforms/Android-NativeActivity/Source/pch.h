//
// pch.h
// Header for standard system include files.
//
// Used by the build system to generate the precompiled header. Note that no
// pch.cpp is needed and the pch.h is automatically included in all cpp files
// that are part of the project
//

#include <jni.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <math.h>

#include <map>
#include <vector>

#include <EGL/egl.h>
#include <GLES/gl.h>
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <android/sensor.h>
#include <android/log.h>
#include <memory>

#include "android_native_app_glue.h"
#include "UtilityAndroid.h"

#include "../Shared/Source/GameHeaders.h"
