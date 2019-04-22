package com.zzw.nativeopnegldemo.opengl;

import android.view.Surface;

/**
 * Created by zzw on 2019/4/22
 * Des:
 */
public class NationOpenGL {

    static {
        System.loadLibrary("native-lib");
    }

    public native void nativeSurfaceCreate(Surface surface);

    public native void nativeSurfaceChanged(int width, int height);

    public native void nativeSurfaceDestroyed();

}
