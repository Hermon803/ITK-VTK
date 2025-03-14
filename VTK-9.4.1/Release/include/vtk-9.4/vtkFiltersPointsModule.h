
#ifndef VTKFILTERSPOINTS_EXPORT_H
#define VTKFILTERSPOINTS_EXPORT_H

#ifdef VTKFILTERSPOINTS_STATIC_DEFINE
#  define VTKFILTERSPOINTS_EXPORT
#  define VTKFILTERSPOINTS_NO_EXPORT
#else
#  ifndef VTKFILTERSPOINTS_EXPORT
#    ifdef FiltersPoints_EXPORTS
        /* We are building this library */
#      define VTKFILTERSPOINTS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VTKFILTERSPOINTS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VTKFILTERSPOINTS_NO_EXPORT
#    define VTKFILTERSPOINTS_NO_EXPORT 
#  endif
#endif

#ifndef VTKFILTERSPOINTS_DEPRECATED
#  define VTKFILTERSPOINTS_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKFILTERSPOINTS_DEPRECATED_EXPORT
#  define VTKFILTERSPOINTS_DEPRECATED_EXPORT VTKFILTERSPOINTS_EXPORT VTKFILTERSPOINTS_DEPRECATED
#endif

#ifndef VTKFILTERSPOINTS_DEPRECATED_NO_EXPORT
#  define VTKFILTERSPOINTS_DEPRECATED_NO_EXPORT VTKFILTERSPOINTS_NO_EXPORT VTKFILTERSPOINTS_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKFILTERSPOINTS_NO_DEPRECATED
#    define VTKFILTERSPOINTS_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkFiltersPointsModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKFILTERSPOINTS_EXPORT_H */
