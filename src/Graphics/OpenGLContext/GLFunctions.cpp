#include "GLFunctions.h"

#ifdef OS_WINDOWS

#define glGetProcAddress wglGetProcAddress
#define GL_GET_PROC_ADR(proc_type, proc_name) g_##proc_name = (proc_type) glGetProcAddress(#proc_name)

#elif defined(ODROID) || defined(VC)

#define GL_GET_PROC_ADR(proc_type, proc_name) g_##proc_name = (proc_type) dlsym(gles2so, #proc_name);

#elif defined(EGL)

#include <EGL/egl.h>
#include <EGL/eglext.h>
#define glGetProcAddress eglGetProcAddress
#define GL_GET_PROC_ADR(proc_type, proc_name) g_##proc_name = (proc_type) glGetProcAddress(#proc_name)

#elif defined(OS_LINUX)

#include <X11/Xutil.h>
typedef XID GLXContextID;
typedef XID GLXPixmap;
typedef XID GLXDrawable;
typedef XID GLXPbuffer;
typedef XID GLXWindow;
typedef XID GLXFBConfigID;
typedef struct __GLXcontextRec *GLXContext;
typedef struct __GLXFBConfigRec *GLXFBConfig;
#define GLX_GLXEXT_PROTOTYPES
#include <GL/glxext.h>
#define glGetProcAddress glXGetProcAddress
#define GL_GET_PROC_ADR(proc_type, proc_name) g_##proc_name = (proc_type) glGetProcAddress((const GLubyte*)#proc_name)

#elif defined(OS_MAC_OS_X)
#include <dlfcn.h>

static void* AppleGLGetProcAddress (const char *name)
{
    static void* image = NULL;
    if (NULL == image)
    image = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", RTLD_LAZY);

    return (image ? dlsym(image, name) : NULL);
}
#define glGetProcAddress AppleGLGetProcAddress
#define GL_GET_PROC_ADR(proc_type, proc_name) g_##proc_name = (proc_type) glGetProcAddress(#proc_name)

#elif defined(OS_IOS)
#include <dlfcn.h>

static void* IOSGLGetProcAddress (const char *name)
{
    return dlsym(RTLD_DEFAULT, name);
}

#define glGetProcAddress IOSGLGetProcAddress
#define GL_GET_PROC_ADR(proc_type, proc_name) g_##proc_name = (proc_type)glGetProcAddress(#proc_name)

#endif

//GL Fucntions

#ifdef OS_WINDOWS
PFNGLACTIVETEXTUREPROC g_glActiveTexture;
PFNGLBLENDCOLORPROC g_glBlendColor;
#elif defined(EGL) || defined(OS_IOS)
PFNGLBLENDFUNCPROC g_glBlendFunc;
PFNGLPIXELSTOREIPROC g_glPixelStorei;
PFNGLCLEARCOLORPROC g_glClearColor;
PFNGLCULLFACEPROC g_glCullFace;
PFNGLDEPTHFUNCPROC g_glDepthFunc;
PFNGLDEPTHMASKPROC g_glDepthMask;
PFNGLDISABLEPROC g_glDisable;
PFNGLENABLEPROC g_glEnable;
PFNGLPOLYGONOFFSETPROC g_glPolygonOffset;
PFNGLSCISSORPROC g_glScissor;
PFNGLVIEWPORTPROC g_glViewport;
PFNGLBINDTEXTUREPROC g_glBindTexture;
PFNGLTEXIMAGE2DPROC g_glTexImage2D;
PFNGLTEXPARAMETERIPROC g_glTexParameteri;
PFNGLGETINTEGERVPROC g_glGetIntegerv;
PFNGLGETSTRINGPROC g_glGetString;
PFNGLREADPIXELSPROC g_glReadPixels;
PFNGLTEXSUBIMAGE2DPROC g_glTexSubImage2D;
PFNGLDRAWARRAYSPROC g_glDrawArrays;
PFNGLGETERRORPROC g_glGetError;
PFNGLDRAWELEMENTSPROC g_glDrawElements;
PFNGLLINEWIDTHPROC g_glLineWidth;
PFNGLCLEARPROC g_glClear;
PFNGLGETFLOATVPROC g_glGetFloatv;
PFNGLDELETETEXTURESPROC g_glDeleteTextures;
PFNGLGENTEXTURESPROC g_glGenTextures;
PFNGLTEXPARAMETERFPROC g_glTexParameterf;
PFNGLACTIVETEXTUREPROC g_glActiveTexture;
PFNGLBLENDCOLORPROC g_glBlendColor;
PFNGLREADBUFFERPROC g_glReadBuffer;
PFNGLFINISHPROC g_glFinish;
#endif
PFNGLCREATESHADERPROC g_glCreateShader;
PFNGLCOMPILESHADERPROC g_glCompileShader;
PFNGLSHADERSOURCEPROC g_glShaderSource;
PFNGLCREATEPROGRAMPROC g_glCreateProgram;
PFNGLATTACHSHADERPROC g_glAttachShader;
PFNGLLINKPROGRAMPROC g_glLinkProgram;
PFNGLUSEPROGRAMPROC g_glUseProgram;
PFNGLGETUNIFORMLOCATIONPROC g_glGetUniformLocation;
PFNGLUNIFORM1IPROC g_glUniform1i;
PFNGLUNIFORM1FPROC g_glUniform1f;
PFNGLUNIFORM2FPROC g_glUniform2f;
PFNGLUNIFORM2IPROC g_glUniform2i;
PFNGLUNIFORM4IPROC g_glUniform4i;
PFNGLUNIFORM4FPROC g_glUniform4f;
PFNGLUNIFORM3FVPROC g_glUniform3fv;
PFNGLUNIFORM4FVPROC g_glUniform4fv;
PFNGLDETACHSHADERPROC g_glDetachShader;
PFNGLDELETESHADERPROC g_glDeleteShader;
PFNGLDELETEPROGRAMPROC g_glDeleteProgram;
PFNGLGETPROGRAMINFOLOGPROC g_glGetProgramInfoLog;
PFNGLGETSHADERINFOLOGPROC g_glGetShaderInfoLog;
PFNGLGETSHADERIVPROC g_glGetShaderiv;
PFNGLGETPROGRAMIVPROC g_glGetProgramiv;

PFNGLENABLEVERTEXATTRIBARRAYPROC g_glEnableVertexAttribArray;
PFNGLDISABLEVERTEXATTRIBARRAYPROC g_glDisableVertexAttribArray;
PFNGLVERTEXATTRIBPOINTERPROC g_glVertexAttribPointer;
PFNGLBINDATTRIBLOCATIONPROC g_glBindAttribLocation;
PFNGLVERTEXATTRIB1FPROC g_glVertexAttrib1f;
PFNGLVERTEXATTRIB4FPROC g_glVertexAttrib4f;
PFNGLVERTEXATTRIB4FVPROC g_glVertexAttrib4fv;

// multitexture functions
PFNGLDEPTHRANGEFPROC g_glDepthRangef;
PFNGLCLEARDEPTHFPROC g_glClearDepthf;

PFNGLDRAWBUFFERSPROC g_glDrawBuffers;
PFNGLBINDFRAMEBUFFERPROC g_glBindFramebuffer;
PFNGLDELETEFRAMEBUFFERSPROC g_glDeleteFramebuffers;
PFNGLGENFRAMEBUFFERSPROC g_glGenFramebuffers;
PFNGLFRAMEBUFFERTEXTURE2DPROC g_glFramebufferTexture2D;
PFNGLTEXIMAGE2DMULTISAMPLEPROC g_glTexImage2DMultisample;
PFNGLTEXSTORAGE2DMULTISAMPLEPROC g_glTexStorage2DMultisample;
PFNGLGENRENDERBUFFERSPROC g_glGenRenderbuffers;
PFNGLBINDRENDERBUFFERPROC g_glBindRenderbuffer;
PFNGLRENDERBUFFERSTORAGEPROC g_glRenderbufferStorage;
PFNGLFRAMEBUFFERRENDERBUFFERPROC g_glFramebufferRenderbuffer;
PFNGLDELETERENDERBUFFERSPROC g_glDeleteRenderbuffers;
PFNGLCHECKFRAMEBUFFERSTATUSPROC g_glCheckFramebufferStatus;
PFNGLBLITFRAMEBUFFERPROC g_glBlitFramebuffer;
PFNGLGENVERTEXARRAYSPROC g_glGenVertexArrays;
PFNGLBINDVERTEXARRAYPROC g_glBindVertexArray;
PFNGLDELETEVERTEXARRAYSPROC g_glDeleteVertexArrays;
PFNGLGENBUFFERSPROC g_glGenBuffers;
PFNGLBINDBUFFERPROC g_glBindBuffer;
PFNGLBUFFERDATAPROC g_glBufferData;
PFNGLMAPBUFFERPROC g_glMapBuffer;
PFNGLMAPBUFFERRANGEPROC g_glMapBufferRange;
PFNGLUNMAPBUFFERPROC g_glUnmapBuffer;
PFNGLDELETEBUFFERSPROC g_glDeleteBuffers;
PFNGLBINDIMAGETEXTUREPROC g_glBindImageTexture;
PFNGLMEMORYBARRIERPROC g_glMemoryBarrier;
PFNGLGETSTRINGIPROC g_glGetStringi;
PFNGLINVALIDATEFRAMEBUFFERPROC g_glInvalidateFramebuffer;
PFNGLBUFFERSTORAGEPROC g_glBufferStorage;
PFNGLFENCESYNCPROC g_glFenceSync;
PFNGLCLIENTWAITSYNCPROC g_glClientWaitSync;
PFNGLDELETESYNCPROC g_glDeleteSync;

PFNGLGETUNIFORMBLOCKINDEXPROC g_glGetUniformBlockIndex;
PFNGLUNIFORMBLOCKBINDINGPROC g_glUniformBlockBinding;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC g_glGetActiveUniformBlockiv;
PFNGLGETUNIFORMINDICESPROC g_glGetUniformIndices;
PFNGLGETACTIVEUNIFORMSIVPROC g_glGetActiveUniformsiv;
PFNGLBINDBUFFERBASEPROC g_glBindBufferBase;
PFNGLBUFFERSUBDATAPROC g_glBufferSubData;

PFNGLGETPROGRAMBINARYPROC g_glGetProgramBinary;
PFNGLPROGRAMBINARYPROC g_glProgramBinary;
PFNGLPROGRAMPARAMETERIPROC g_glProgramParameteri;

PFNGLTEXSTORAGE2DPROC g_glTexStorage2D;
PFNGLTEXTURESTORAGE2DPROC g_glTextureStorage2D;
PFNGLTEXTURESUBIMAGE2DPROC g_glTextureSubImage2D;
PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC g_glTextureStorage2DMultisample;
PFNGLTEXTUREPARAMETERIPROC g_glTextureParameteri;
PFNGLTEXTUREPARAMETERFPROC g_glTextureParameterf;
PFNGLCREATETEXTURESPROC g_glCreateTextures;
PFNGLCREATEBUFFERSPROC g_glCreateBuffers;
PFNGLCREATEFRAMEBUFFERSPROC g_glCreateFramebuffers;
PFNGLNAMEDFRAMEBUFFERTEXTUREPROC g_glNamedFramebufferTexture;
PFNGLDRAWELEMENTSBASEVERTEXPROC g_glDrawElementsBaseVertex;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC g_glFlushMappedBufferRange;

void initGLFunctions()
{
#ifdef VC
	void *gles2so = dlopen("/opt/vc/lib/libbrcmGLESv2.so", RTLD_NOW);
#elif defined(ODROID)
	void *gles2so = dlopen("/usr/lib/arm-linux-gnueabihf/libGLESv2.so", RTLD_NOW);
#endif
#ifdef OS_WINDOWS
	GL_GET_PROC_ADR(PFNGLACTIVETEXTUREPROC, glActiveTexture);
	GL_GET_PROC_ADR(PFNGLBLENDCOLORPROC, glBlendColor);
#elif defined(EGL) || defined(OS_IOS)
	GL_GET_PROC_ADR(PFNGLBLENDFUNCPROC, glBlendFunc);
	GL_GET_PROC_ADR(PFNGLPIXELSTOREIPROC, glPixelStorei);
	GL_GET_PROC_ADR(PFNGLCLEARCOLORPROC, glClearColor);
	GL_GET_PROC_ADR(PFNGLCULLFACEPROC, glCullFace);
	GL_GET_PROC_ADR(PFNGLDEPTHFUNCPROC, glDepthFunc);
	GL_GET_PROC_ADR(PFNGLDEPTHMASKPROC, glDepthMask);
	GL_GET_PROC_ADR(PFNGLDISABLEPROC, glDisable);
	GL_GET_PROC_ADR(PFNGLENABLEPROC, glEnable);
	GL_GET_PROC_ADR(PFNGLPOLYGONOFFSETPROC, glPolygonOffset);
	GL_GET_PROC_ADR(PFNGLSCISSORPROC, glScissor);
	GL_GET_PROC_ADR(PFNGLVIEWPORTPROC, glViewport);
	GL_GET_PROC_ADR(PFNGLBINDTEXTUREPROC, glBindTexture);
	GL_GET_PROC_ADR(PFNGLTEXIMAGE2DPROC, glTexImage2D);
	GL_GET_PROC_ADR(PFNGLTEXPARAMETERIPROC, glTexParameteri);
	GL_GET_PROC_ADR(PFNGLGETINTEGERVPROC, glGetIntegerv);
	GL_GET_PROC_ADR(PFNGLGETSTRINGPROC, glGetString);
	GL_GET_PROC_ADR(PFNGLREADPIXELSPROC, glReadPixels);
	GL_GET_PROC_ADR(PFNGLTEXSUBIMAGE2DPROC, glTexSubImage2D);
	GL_GET_PROC_ADR(PFNGLDRAWARRAYSPROC, glDrawArrays);
	GL_GET_PROC_ADR(PFNGLGETERRORPROC, glGetError);
	GL_GET_PROC_ADR(PFNGLDRAWELEMENTSPROC, glDrawElements);
	GL_GET_PROC_ADR(PFNGLLINEWIDTHPROC, glLineWidth);
	GL_GET_PROC_ADR(PFNGLCLEARPROC, glClear);
	GL_GET_PROC_ADR(PFNGLGETFLOATVPROC, glGetFloatv);
	GL_GET_PROC_ADR(PFNGLDELETETEXTURESPROC, glDeleteTextures);
	GL_GET_PROC_ADR(PFNGLGENTEXTURESPROC, glGenTextures);
	GL_GET_PROC_ADR(PFNGLTEXPARAMETERFPROC, glTexParameterf);
	GL_GET_PROC_ADR(PFNGLACTIVETEXTUREPROC, glActiveTexture);
	GL_GET_PROC_ADR(PFNGLBLENDCOLORPROC, glBlendColor);
	GL_GET_PROC_ADR(PFNGLREADBUFFERPROC, glReadBuffer);
	GL_GET_PROC_ADR(PFNGLFINISHPROC, glFinish);
#endif

	GL_GET_PROC_ADR(PFNGLCREATESHADERPROC, glCreateShader);
	GL_GET_PROC_ADR(PFNGLCOMPILESHADERPROC, glCompileShader);
	GL_GET_PROC_ADR(PFNGLSHADERSOURCEPROC, glShaderSource);
	GL_GET_PROC_ADR(PFNGLCREATEPROGRAMPROC, glCreateProgram);
	GL_GET_PROC_ADR(PFNGLATTACHSHADERPROC, glAttachShader);
	GL_GET_PROC_ADR(PFNGLLINKPROGRAMPROC, glLinkProgram);
	GL_GET_PROC_ADR(PFNGLUSEPROGRAMPROC, glUseProgram);
	GL_GET_PROC_ADR(PFNGLGETUNIFORMLOCATIONPROC, glGetUniformLocation);
	GL_GET_PROC_ADR(PFNGLUNIFORM1IPROC, glUniform1i);
	GL_GET_PROC_ADR(PFNGLUNIFORM1FPROC, glUniform1f);
	GL_GET_PROC_ADR(PFNGLUNIFORM2FPROC, glUniform2f);
	GL_GET_PROC_ADR(PFNGLUNIFORM2IPROC, glUniform2i);
	GL_GET_PROC_ADR(PFNGLUNIFORM4IPROC, glUniform4i);
	GL_GET_PROC_ADR(PFNGLUNIFORM4FPROC, glUniform4f);
	GL_GET_PROC_ADR(PFNGLUNIFORM3FVPROC, glUniform3fv);
	GL_GET_PROC_ADR(PFNGLUNIFORM4FVPROC, glUniform4fv);
	GL_GET_PROC_ADR(PFNGLDETACHSHADERPROC, glDetachShader);
	GL_GET_PROC_ADR(PFNGLDELETESHADERPROC, glDeleteShader);
	GL_GET_PROC_ADR(PFNGLDELETEPROGRAMPROC, glDeleteProgram);
	GL_GET_PROC_ADR(PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog);
	GL_GET_PROC_ADR(PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog);
	GL_GET_PROC_ADR(PFNGLGETSHADERIVPROC, glGetShaderiv);
	GL_GET_PROC_ADR(PFNGLGETPROGRAMIVPROC, glGetProgramiv);

	GL_GET_PROC_ADR(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray);
	GL_GET_PROC_ADR(PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray);
	GL_GET_PROC_ADR(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer);
	GL_GET_PROC_ADR(PFNGLBINDATTRIBLOCATIONPROC, glBindAttribLocation);
	GL_GET_PROC_ADR(PFNGLVERTEXATTRIB1FPROC, glVertexAttrib1f);
	GL_GET_PROC_ADR(PFNGLVERTEXATTRIB4FPROC, glVertexAttrib4f);
	GL_GET_PROC_ADR(PFNGLVERTEXATTRIB4FVPROC, glVertexAttrib4fv);

	GL_GET_PROC_ADR(PFNGLDEPTHRANGEFPROC, glDepthRangef);
	GL_GET_PROC_ADR(PFNGLCLEARDEPTHFPROC, glClearDepthf);

	GL_GET_PROC_ADR(PFNGLDRAWBUFFERSPROC, glDrawBuffers);
	GL_GET_PROC_ADR(PFNGLBINDFRAMEBUFFERPROC, glBindFramebuffer);
	GL_GET_PROC_ADR(PFNGLDELETEFRAMEBUFFERSPROC, glDeleteFramebuffers);
	GL_GET_PROC_ADR(PFNGLGENFRAMEBUFFERSPROC, glGenFramebuffers);
	GL_GET_PROC_ADR(PFNGLFRAMEBUFFERTEXTURE2DPROC, glFramebufferTexture2D);
	GL_GET_PROC_ADR(PFNGLTEXIMAGE2DMULTISAMPLEPROC, glTexImage2DMultisample);
	GL_GET_PROC_ADR(PFNGLTEXSTORAGE2DMULTISAMPLEPROC, glTexStorage2DMultisample);
	GL_GET_PROC_ADR(PFNGLGENRENDERBUFFERSPROC, glGenRenderbuffers);
	GL_GET_PROC_ADR(PFNGLBINDRENDERBUFFERPROC, glBindRenderbuffer);
	GL_GET_PROC_ADR(PFNGLRENDERBUFFERSTORAGEPROC, glRenderbufferStorage);
	GL_GET_PROC_ADR(PFNGLFRAMEBUFFERRENDERBUFFERPROC, glFramebufferRenderbuffer);
	GL_GET_PROC_ADR(PFNGLDELETERENDERBUFFERSPROC, glDeleteRenderbuffers);
	GL_GET_PROC_ADR(PFNGLCHECKFRAMEBUFFERSTATUSPROC, glCheckFramebufferStatus);
	GL_GET_PROC_ADR(PFNGLBLITFRAMEBUFFERPROC, glBlitFramebuffer);
	GL_GET_PROC_ADR(PFNGLGENVERTEXARRAYSPROC, glGenVertexArrays);
	GL_GET_PROC_ADR(PFNGLBINDVERTEXARRAYPROC, glBindVertexArray);
	GL_GET_PROC_ADR(PFNGLDELETEVERTEXARRAYSPROC, glDeleteVertexArrays);
	GL_GET_PROC_ADR(PFNGLGENBUFFERSPROC, glGenBuffers);
	GL_GET_PROC_ADR(PFNGLBINDBUFFERPROC, glBindBuffer);
	GL_GET_PROC_ADR(PFNGLBUFFERDATAPROC, glBufferData);
	GL_GET_PROC_ADR(PFNGLMAPBUFFERPROC, glMapBuffer);
	GL_GET_PROC_ADR(PFNGLMAPBUFFERRANGEPROC, glMapBufferRange);
	GL_GET_PROC_ADR(PFNGLUNMAPBUFFERPROC, glUnmapBuffer);
	GL_GET_PROC_ADR(PFNGLDELETEBUFFERSPROC, glDeleteBuffers);
	GL_GET_PROC_ADR(PFNGLBINDIMAGETEXTUREPROC, glBindImageTexture);
	GL_GET_PROC_ADR(PFNGLMEMORYBARRIERPROC, glMemoryBarrier);
	GL_GET_PROC_ADR(PFNGLGETSTRINGIPROC, glGetStringi);
	GL_GET_PROC_ADR(PFNGLINVALIDATEFRAMEBUFFERPROC, glInvalidateFramebuffer);
	GL_GET_PROC_ADR(PFNGLBUFFERSTORAGEPROC, glBufferStorage);
	GL_GET_PROC_ADR(PFNGLFENCESYNCPROC, glFenceSync);
	GL_GET_PROC_ADR(PFNGLCLIENTWAITSYNCPROC, glClientWaitSync);
	GL_GET_PROC_ADR(PFNGLDELETESYNCPROC, glDeleteSync);

	GL_GET_PROC_ADR(PFNGLGETUNIFORMBLOCKINDEXPROC, glGetUniformBlockIndex);
	GL_GET_PROC_ADR(PFNGLUNIFORMBLOCKBINDINGPROC, glUniformBlockBinding);
	GL_GET_PROC_ADR(PFNGLGETACTIVEUNIFORMBLOCKIVPROC, glGetActiveUniformBlockiv);
	GL_GET_PROC_ADR(PFNGLGETUNIFORMINDICESPROC, glGetUniformIndices);
	GL_GET_PROC_ADR(PFNGLGETACTIVEUNIFORMSIVPROC, glGetActiveUniformsiv);
	GL_GET_PROC_ADR(PFNGLBINDBUFFERBASEPROC, glBindBufferBase);
	GL_GET_PROC_ADR(PFNGLBUFFERSUBDATAPROC, glBufferSubData);

	GL_GET_PROC_ADR(PFNGLGETPROGRAMBINARYPROC, glGetProgramBinary);
	GL_GET_PROC_ADR(PFNGLPROGRAMBINARYPROC, glProgramBinary);
	GL_GET_PROC_ADR(PFNGLPROGRAMPARAMETERIPROC, glProgramParameteri);

	GL_GET_PROC_ADR(PFNGLTEXSTORAGE2DPROC, glTexStorage2D);
	GL_GET_PROC_ADR(PFNGLTEXTURESTORAGE2DPROC, glTextureStorage2D);
	GL_GET_PROC_ADR(PFNGLTEXTURESUBIMAGE2DPROC, glTextureSubImage2D);
	GL_GET_PROC_ADR(PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC, glTextureStorage2DMultisample);

	GL_GET_PROC_ADR(PFNGLTEXTUREPARAMETERIPROC, glTextureParameteri);
	GL_GET_PROC_ADR(PFNGLTEXTUREPARAMETERFPROC, glTextureParameterf);
	GL_GET_PROC_ADR(PFNGLCREATETEXTURESPROC, glCreateTextures);
	GL_GET_PROC_ADR(PFNGLCREATEBUFFERSPROC, glCreateBuffers);
	GL_GET_PROC_ADR(PFNGLCREATEFRAMEBUFFERSPROC, glCreateFramebuffers);
	GL_GET_PROC_ADR(PFNGLNAMEDFRAMEBUFFERTEXTUREPROC, glNamedFramebufferTexture);
	GL_GET_PROC_ADR(PFNGLDRAWELEMENTSBASEVERTEXPROC, glDrawElementsBaseVertex);
	GL_GET_PROC_ADR(PFNGLFLUSHMAPPEDBUFFERRANGEPROC, glFlushMappedBufferRange);
}
