
#ifndef VTKIOPLY_EXPORT_H
#define VTKIOPLY_EXPORT_H

#ifdef VTKIOPLY_STATIC_DEFINE
#  define VTKIOPLY_EXPORT
#  define VTKIOPLY_NO_EXPORT
#else
#  ifndef VTKIOPLY_EXPORT
#    ifdef IOPLY_EXPORTS
        /* We are building this library */
#      define VTKIOPLY_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIOPLY_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIOPLY_NO_EXPORT
#    define VTKIOPLY_NO_EXPORT 
#  endif
#endif

#ifndef VTKIOPLY_DEPRECATED
#  define VTKIOPLY_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIOPLY_DEPRECATED_EXPORT
#  define VTKIOPLY_DEPRECATED_EXPORT VTKIOPLY_EXPORT VTKIOPLY_DEPRECATED
#endif

#ifndef VTKIOPLY_DEPRECATED_NO_EXPORT
#  define VTKIOPLY_DEPRECATED_NO_EXPORT VTKIOPLY_NO_EXPORT VTKIOPLY_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIOPLY_NO_DEPRECATED
#    define VTKIOPLY_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkIOPLYModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKIOPLY_EXPORT_H */
