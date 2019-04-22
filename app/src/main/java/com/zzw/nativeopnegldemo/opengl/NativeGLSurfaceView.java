package com.zzw.nativeopnegldemo.opengl;

import android.content.Context;
import android.util.AttributeSet;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

/**
 * Created by zzw on 2019/4/22
 * Des:
 */
public class NativeGLSurfaceView extends SurfaceView implements SurfaceHolder.Callback {
    private NationOpenGL mNationOpenGL;

    public NativeGLSurfaceView(Context context) {
        this(context, null);
    }

    public NativeGLSurfaceView(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public NativeGLSurfaceView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        mNationOpenGL = new NationOpenGL();
        getHolder().addCallback(this);
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        mNationOpenGL.nativeSurfaceCreate(holder.getSurface());
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        mNationOpenGL.nativeSurfaceChanged(width, height);
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        mNationOpenGL.nativeSurfaceDestroyed();
    }
}
