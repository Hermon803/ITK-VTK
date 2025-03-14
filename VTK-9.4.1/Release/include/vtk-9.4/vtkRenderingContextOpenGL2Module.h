
#ifndef VTKRENDERINGCONTEXTOPENGL2_EXPORT_H
#define VTKRENDERINGCONTEXTOPENGL2_EXPORT_H

#ifdef VTKRENDERINGCONTEXTOPENGL2_STATIC_DEFINE
#  define VTKRENDERINGCONTEXTOPENGL2_EXPORT
#  define VTKRENDERINGCONTEXTOPENGL2_NO_EXPORT
#else
#  ifndef VTKRENDERINGCONTEXTOPENGL2_EXPORT
#    ifdef RenderingContextOpenGL2_EXPORTS
        /* We are building this library */
#      define VTKRENDERINGCONTEXTOPENGL2_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKRENDERINGCONTEXTOPENGL2_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKRENDERINGCONTEXTOPENGL2_NO_EXPORT
#    define VTKRENDERINGCONTEXTOPENGL2_NO_EXPORT 
#  endif
#endif

#ifndef VTKRENDERINGCONTEXTOPENGL2_DEPRECATED
#  define VTKRENDERINGCONTEXTOPENGL2_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKRENDERINGCONTEXTOPENGL2_DEPRECATED_EXPORT
#  define VTKRENDERINGCONTEXTOPENGL2_DEPRECATED_EXPORT VTKRENDERINGCONTEXTOPENGL2_EXPORT VTKRENDERINGCONTEXTOPENGL2_DEPRECATED
#endif

#ifndef VTKRENDERINGCONTEXTOPENGL2_DEPRECATED_NO_EXPORT
#  define VTKRENDERINGCONTEXTOPENGL2_DEPRECATED_NO_EXPORT VTKRENDERINGCONTEXTOPENGL2_NO_EXPORT VTKRENDERINGCONTEXTOPENGL2_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKRENDERINGCONTEXTOPENGL2_NO_DEPRECATED
#    define VTKRENDERINGCONTEXTOPENGL2_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkRenderingContextOpenGL2Module.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"
/* AutoInit dependencies. */
#include "vtkRenderingContext2DModule.h"
#include "vtkRenderingCoreModule.h"
#include "vtkRenderingFreeTypeModule.h"
#include "vtkRenderingOpenGL2Module.h"


/* AutoInit implementations. */
#ifdef vtkRenderingContextOpenGL2_AUTOINIT_INCLUDE
#include vtkRenderingContextOpenGL2_AUTOINIT_INCLUDE
#endif
#ifdef vtkRenderingContextOpenGL2_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkRenderingContextOpenGL2)
#endif

#endif /* VTKRENDERINGCONTEXTOPENGL2_EXPORT_H */
