
#ifndef VTKINFOVISLAYOUT_EXPORT_H
#define VTKINFOVISLAYOUT_EXPORT_H

#ifdef VTKINFOVISLAYOUT_STATIC_DEFINE
#  define VTKINFOVISLAYOUT_EXPORT
#  define VTKINFOVISLAYOUT_NO_EXPORT
#else
#  ifndef VTKINFOVISLAYOUT_EXPORT
#    ifdef InfovisLayout_EXPORTS
        /* We are building this library */
#      define VTKINFOVISLAYOUT_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKINFOVISLAYOUT_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKINFOVISLAYOUT_NO_EXPORT
#    define VTKINFOVISLAYOUT_NO_EXPORT 
#  endif
#endif

#ifndef VTKINFOVISLAYOUT_DEPRECATED
#  define VTKINFOVISLAYOUT_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKINFOVISLAYOUT_DEPRECATED_EXPORT
#  define VTKINFOVISLAYOUT_DEPRECATED_EXPORT VTKINFOVISLAYOUT_EXPORT VTKINFOVISLAYOUT_DEPRECATED
#endif

#ifndef VTKINFOVISLAYOUT_DEPRECATED_NO_EXPORT
#  define VTKINFOVISLAYOUT_DEPRECATED_NO_EXPORT VTKINFOVISLAYOUT_NO_EXPORT VTKINFOVISLAYOUT_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKINFOVISLAYOUT_NO_DEPRECATED
#    define VTKINFOVISLAYOUT_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkInfovisLayoutModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKINFOVISLAYOUT_EXPORT_H */
