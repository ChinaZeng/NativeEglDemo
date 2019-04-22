//
// Created by zeng on 2019/4/22.
//

#include "android/log.h"

#ifndef NATIVEOPNEGLDEMO_JNILOG_H
#define NATIVEOPNEGLDEMO_JNILOG_H

#define LOGD(FORMAT, ...)  __android_log_print (ANDROID_LOG_DEBUG,"jniLog",FORMAT,##__VA_ARGS__)
#define LOGE(FORMAT, ...) __android_log_print (ANDROID_LOG_ERROR,"jniLog",FORMAT,##__VA_ARGS__)


#endif //NATIVEOPNEGLDEMO_JNILOG_H
