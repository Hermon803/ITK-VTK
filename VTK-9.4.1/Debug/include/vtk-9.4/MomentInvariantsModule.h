
#ifndef MOMENTINVARIANTS_EXPORT_H
#define MOMENTINVARIANTS_EXPORT_H

#ifdef MOMENTINVARIANTS_STATIC_DEFINE
#  define MOMENTINVARIANTS_EXPORT
#  define MOMENTINVARIANTS_NO_EXPORT
#else
#  ifndef MOMENTINVARIANTS_EXPORT
#    ifdef MomentInvariants_EXPORTS
        /* We are building this library */
#      define MOMENTINVARIANTS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define MOMENTINVARIANTS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef MOMENTINVARIANTS_NO_EXPORT
#    define MOMENTINVARIANTS_NO_EXPORT 
#  endif
#endif

#ifndef MOMENTINVARIANTS_DEPRECATED
#  define MOMENTINVARIANTS_DEPRECATED __declspec(deprecated)
#endif

#ifndef MOMENTINVARIANTS_DEPRECATED_EXPORT
#  define MOMENTINVARIANTS_DEPRECATED_EXPORT MOMENTINVARIANTS_EXPORT MOMENTINVARIANTS_DEPRECATED
#endif

#ifndef MOMENTINVARIANTS_DEPRECATED_NO_EXPORT
#  define MOMENTINVARIANTS_DEPRECATED_NO_EXPORT MOMENTINVARIANTS_NO_EXPORT MOMENTINVARIANTS_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MOMENTINVARIANTS_NO_DEPRECATED
#    define MOMENTINVARIANTS_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: MomentInvariantsModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* MOMENTINVARIANTS_EXPORT_H */
