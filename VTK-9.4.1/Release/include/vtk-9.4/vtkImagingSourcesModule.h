
#ifndef VTKIMAGINGSOURCES_EXPORT_H
#define VTKIMAGINGSOURCES_EXPORT_H

#ifdef VTKIMAGINGSOURCES_STATIC_DEFINE
#  define VTKIMAGINGSOURCES_EXPORT
#  define VTKIMAGINGSOURCES_NO_EXPORT
#else
#  ifndef VTKIMAGINGSOURCES_EXPORT
#    ifdef ImagingSources_EXPORTS
        /* We are building this library */
#      define VTKIMAGINGSOURCES_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKIMAGINGSOURCES_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKIMAGINGSOURCES_NO_EXPORT
#    define VTKIMAGINGSOURCES_NO_EXPORT 
#  endif
#endif

#ifndef VTKIMAGINGSOURCES_DEPRECATED
#  define VTKIMAGINGSOURCES_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKIMAGINGSOURCES_DEPRECATED_EXPORT
#  define VTKIMAGINGSOURCES_DEPRECATED_EXPORT VTKIMAGINGSOURCES_EXPORT VTKIMAGINGSOURCES_DEPRECATED
#endif

#ifndef VTKIMAGINGSOURCES_DEPRECATED_NO_EXPORT
#  define VTKIMAGINGSOURCES_DEPRECATED_NO_EXPORT VTKIMAGINGSOURCES_NO_EXPORT VTKIMAGINGSOURCES_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKIMAGINGSOURCES_NO_DEPRECATED
#    define VTKIMAGINGSOURCES_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkImagingSourcesModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKIMAGINGSOURCES_EXPORT_H */
