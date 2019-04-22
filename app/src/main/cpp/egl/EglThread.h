//
// Created by zeng on 2019/4/22.
//

#ifndef NATIVEOPNEGLDEMO_EGLTHREAD_H
#define NATIVEOPNEGLDEMO_EGLTHREAD_H

#include <EGL/eglplatform.h>
#include "pthread.h"
#include "android/native_window.h"
#include "EglHelper.h"
#include <unistd.h>
#include "GLES2/gl2.h"


#define RENDER_MODULE_AUTO 1
#define RENDER_MODULE_MANUAL 2

class EglThread {
public:
    pthread_t mEglThread = -1;
    ANativeWindow *mANativeWindow = NULL;

    int mRenderType = RENDER_MODULE_MANUAL;

    bool isCreate = false;
    bool isChange = false;
    bool isExit = false;
    bool isStart = false;

    int surfaceWidth = 0;
    int surfaceHeight = 0;


    typedef void(*OnCreate)();
    OnCreate onCreate;

    typedef void(*OnChange)(int width, int height);
    OnChange onChange;

    typedef void(*OnDraw)();
    OnDraw onDraw;


    pthread_mutex_t pthread_mutex;
    pthread_cond_t pthread_cond;

public:
    EglThread();

    ~EglThread();

    //生命周期对应响应
    void onSurfaceCreate(EGLNativeWindowType window);

    void onSurfaceChange(int width, int height);

    //设置模式
    void setRenderModule(int renderModule);

    void notifyRender();

    //设置回调
    void callBackOnCreate(OnCreate onCreate);

    void callBackOnChange(OnChange onChange);

    void callBackOnDraw(OnDraw onDraw);


};


#endif //NATIVEOPNEGLDEMO_EGLTHREAD_H
