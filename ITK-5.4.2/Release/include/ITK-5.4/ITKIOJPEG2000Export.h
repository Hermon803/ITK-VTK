
#ifndef ITKIOJPEG2000_EXPORT_H
#define ITKIOJPEG2000_EXPORT_H

#ifdef ITK_STATIC
#  define ITKIOJPEG2000_EXPORT
#  define ITKIOJPEG2000_HIDDEN
#else
#  ifndef ITKIOJPEG2000_EXPORT
#    ifdef ITKIOJPEG2000_EXPORTS
        /* We are building this library */
#      define ITKIOJPEG2000_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define ITKIOJPEG2000_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef ITKIOJPEG2000_HIDDEN
#    define ITKIOJPEG2000_HIDDEN 
#  endif
#endif

#ifndef ITKIOJPEG2000_DEPRECATED
#  define ITKIOJPEG2000_DEPRECATED __declspec(deprecated)
#endif

#ifndef ITKIOJPEG2000_DEPRECATED_EXPORT
#  define ITKIOJPEG2000_DEPRECATED_EXPORT ITKIOJPEG2000_EXPORT ITKIOJPEG2000_DEPRECATED
#endif

#ifndef ITKIOJPEG2000_DEPRECATED_NO_EXPORT
#  define ITKIOJPEG2000_DEPRECATED_NO_EXPORT ITKIOJPEG2000_HIDDEN ITKIOJPEG2000_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef ITKIOJPEG2000_NO_DEPRECATED
#    define ITKIOJPEG2000_NO_DEPRECATED
#  endif
#endif

#endif /* ITKIOJPEG2000_EXPORT_H */
