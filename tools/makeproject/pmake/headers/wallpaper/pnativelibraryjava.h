const char PNATIVELIBRARYJAVA_STR[] = 
"/*\n"
" * Copyright 2012 - 2014 Future Interface. All rights reserved.\n"
" */\n"
"package com.fi.tech;\n"
"\n"
"import android.content.Context;\n"
"\n"
"public class PNativeLibrary \n"
"{\n"
"    public static final int STATE_LOADED = 0;\n"
"    public static final int STATE_UNINITIALIZED = 1;\n"
"    public static final int STATE_INITIALIZED = 2;\n"
"    public static final int STATE_ERROR = 3;\n"
"\n"
"    private int mState;\n"
"\n"
"    private static PNativeLibrary mInstance = null;\n"
"\n"
"    private static native boolean initializeLibraryNative(Context context);\n"
"\n"
"    public static PNativeLibrary getInstance() \n"
"    {\n"
"        if (mInstance == null) \n"
"        {\n"
"            mInstance = new PNativeLibrary();\n"
"        }\n"
"        return mInstance;\n"
"    }\n"
"\n"
"    private PNativeLibrary() \n"
"    {\n"
"        System.loadLibrary(\"fi\");\n"
"        mState = STATE_LOADED;\n"
"    }\n"
"\n"
"    public void initialize(Context context) \n"
"    {\n"
"        if (mState != STATE_INITIALIZED) \n"
"        {\n"
"            if (initializeLibraryNative(context)) \n"
"            {\n"
"                mState = STATE_INITIALIZED;\n"
"            } \n"
"            else \n"
"            {\n"
"                mState = STATE_UNINITIALIZED;\n"
"            }\n"
"        }\n"
"    }\n"
"\n"
"    public void uninitialize() \n"
"    {\n"
"        // Called by native code.\n"
"        mState = STATE_UNINITIALIZED;\n"
"    }\n"
"\n"
"    public int getState() \n"
"    {\n"
"        return mState;\n"
"    }\n"
"\n"
"    public boolean isInitialized()\n"
"    {\n"
"        return mState == STATE_INITIALIZED;\n"
"    }\n"
"\n"
"    // FIXME: add unload mechanism to this native library.\n"
"    // http://codethesis.com/sites/default/index.php?servlet=4&content=2\n"
"}\n"
;
