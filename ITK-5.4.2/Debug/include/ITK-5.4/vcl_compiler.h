#ifndef vcl_compiler_h_
#define vcl_compiler_h_

//:
// \file
// This file is generated from vcl_compiler.h.in
// to provide compile-time configured information
//
//
//
/* The following *_VERSION* variables are set by the cmake 'project' command */
#define VXL_VERSION       5.1.0.0
#define VXL_VERSION_MAJOR 5
#define VXL_VERSION_MINOR 1
#define VXL_VERSION_PATCH 0
#define VXL_VERSION_TWEAK 0

/* The version of the CXX compiler used when VXL was built */
#define VXL_COMPILED_CXX_STANDARD_VERSION 201103L

/* Test external applications to ensure that compatible compiler C++ standard API are used
 * by assuming that compiler standards are backwards (but not forwards) compatible with each
 * other.  Strange behaviors may occur if external applications do not use the same compiler
 * and compiler language featues (i.e. compiler flags). */
#if !defined(_MSC_VER) //MSVC does not consistently define __cplusplus
// https://developercommunity.visualstudio.com/content/problem/139261/msvc-incorrectly-defines-cplusplus.html
#if VXL_COMPILED_CXX_STANDARD_VERSION > __cplusplus
#warning "WARNING:  The current project is configured to use a C++ standard version older than the C++ standard used for this build of VXL"
#endif
#endif

#define VXL_LEGACY_FUTURE_REMOVE 1
#define VXL_RUN_FAILING_TESTS 0
#define VXL_USE_HISTORICAL_IMPLICIT_CONVERSIONS 1
#define VXL_USE_HISTORICAL_PROTECTED_IVARS 1


// -------------------- handy macros ---------------------------------------

//: VCL_COMMA
//
// Handy for passing things with commas in them to CPP macros.  e.g.
// DO_MACRO(pair<A,B>) can be replaced by DO_MACRO(pair<A VCL_COMMA B>).
#define VCL_COMMA ,

//----------------------------------------------------------------------------
#if defined(NDEBUG)
# define VXL_USED_IN_DEBUG(x)
/* Valgrind does not support "long double" types and this results
 * in numerous false positive memory errors being reported.
 * Turn off tests involving "long double" types by default
 * when compiling in "Debug" mode.
 * You can override this behavior by including a compiler
 * flag of -DINCLUDE_LONG_DOUBLE_TESTS when compiling
 * in debug mode to enable these tests.
 */
# define INCLUDE_LONG_DOUBLE_TESTS
#else
# define VXL_USED_IN_DEBUG(x) x
#endif

//----------------------------------------------------------------------
// constant initializer issues.
#if VXL_LEGACY_FUTURE_REMOVE
#if defined(__clang__) || defined(__GNUC__)

#pragma GCC poison VXL_CONSTEXPR_FUNC                    //"ERROR: VXL_CONSTEXPR_FUNC deprecated, use C++11 constexpr"
#pragma GCC poison VXL_CONSTEXPR_VAR                     //"ERROR: VXL_CONSTEXPR_VAR deprecated, use C++11 constexpr"
#pragma GCC poison VXL_FULLCXX11SUPPORT                  //"ERROR: ONLY VXL_FULLCXX11SUPPORT supported"
#pragma GCC poison VCL_STATIC_CONST_INIT_INT_DECL        //"ERROR: repace VCL_STATIC_CONST_INIT_INT_DECL with ' = '"
#pragma GCC poison VCL_STATIC_CONST_INIT_INT_DEFN        //"ERROR: VCL_STATIC_CONST_INIT_INT_DEFN is a noop"
#pragma GCC poison VCL_STATIC_CONST_INIT_FLOAT_DECL      //"ERROR: repace VCL_STATIC_CONST_INIT_FLOAT_DECL with ' = '"
#pragma GCC poison VCL_STATIC_CONST_INIT_FLOAT_DEFN      //"ERROR: VCL_STATIC_CONST_INIT_FLOAT_DEFN is a noop"
#pragma GCC poison VCL_SAFE_BOOL_TRUE                    //"ERROR: Use true for VCL_SAFE_BOOL_TRUE"
#pragma GCC poison VCL_SAFE_BOOL_DEFINE                  //"ERROR: VCL_SAFE_BOOL_DEFINE is a noop in C++11"

/* Check for C99 versions of is[finite|inf|nan|normal] in <cmath> */
#pragma GCC poison VXL_HAS_STD_ISFINITE                  //"ERROR:  Use C++11 cmath"
#pragma GCC poison VXL_HAS_STD_ISINF                     //"ERROR:  Use C++11 cmath"
#pragma GCC poison VXL_HAS_STD_ISNAN                     //"ERROR:  Use C++11 cmath"
#pragma GCC poison VXL_HAS_STD_ISNORMAL                  //"ERROR:  Use C++11 cmath"
#pragma GCC poison VXL_IEEEFP_HAS_FINITE                 //"ERROR:  Use C++11 cmath"
#pragma GCC poison VXL_C_MATH_HAS_FINITEF                //"ERROR:  Use C++11 cmath"
#pragma GCC poison VXL_C_MATH_HAS_FINITE                 //"ERROR:  Use C++11 cmath"
#pragma GCC poison VXL_C_MATH_HAS_FINITEL                //"ERROR:  Use C++11 cmath"
#pragma GCC poison VXL_C_MATH_HAS_SQRTF                  //"ERROR:  Use C++11 cmath"
#pragma GCC poison VXL_STDLIB_HAS_QSORT                  //"ERROR:  Use C++11 cstdlib"

#pragma GCC poison VXL_STDLIB_HAS_LRAND48                //"ERROR:  Use C++11 cstdlib"
#pragma GCC poison VXL_STDLIB_HAS_DRAND48                //"ERROR:  drand48 is a posix functions and not generally portable. Use C++ <random> features"
#pragma GCC poison VXL_STDLIB_HAS_SRAND48                //"ERROR:  srand48 is a posix functions and not generally portable. Use C++ <random> features"

#pragma GCC poison VCL_FREEBSD                           //"ERROR: VCL_FREBSD has no use in VXL"
#pragma GCC poison VCL_VOID_RETURN                       //"ERROR: VCL_VOID_RETURN has no use in VXL"
#pragma GCC poison VCL_CYGWIN_GCC                        //"ERROR: VCL_CYGWIN_GCC has no use in VXL"

//REDUNDANT WITH write_compiler_detection_header
#pragma GCC poison VCL_HAS_EXPORT                        //"ERROR: Removed in favor of write_compiler_detection_header detections"
#pragma GCC poison VCL_HAS_BOOL                          //"ERROR: Removed in favor of write_compiler_detection_header detections"
#pragma GCC poison VCL_HAS_TYPENAME                      //"ERROR: Removed in favor of write_compiler_detection_header detections"
#pragma GCC poison VCL_HAS_MUTABLE                       //"ERROR: Removed in favor of write_compiler_detection_header detections"
#pragma GCC poison VCL_HAS_DYNAMIC_CAST                  //"ERROR: Removed in favor of write_compiler_detection_header detections"
#pragma GCC poison VCL_HAS_RTTI                          //"ERROR: Removed in favor of write_compiler_detection_header detections"
#pragma GCC poison VCL_DEFAULT_VALUE                     //"ERROR: Removed in favor of write_compiler_detection_header detections"
#pragma GCC poison VCL_HAS_MEMBER_TEMPLATES              //"ERROR: Removed in favor of write_compiler_detection_header detections"
#pragma GCC poison VCL_CAN_DO_STATIC_TEMPLATE_MEMBER     //"ERROR: Removed in favor of write_compiler_detection_header detections"
#pragma GCC poison VCL_CAN_DO_NON_TYPE_FUNCTION_TEMPLATE_PARAMETER //"ERROR: Removed in favor of write_compiler_detection_header detections"
#pragma GCC poison VCL_HAS_EXCEPTIONS                    //"ERROR: Removed in favor of write_compiler_detection_header detections"
#pragma GCC poison VCL_HAS_NAMESPACE                     //"ERROR: Removed in favor of write_compiler_detection_header detections"

#pragma GCC poison VCL_INCLUDE_CXX_0X                    //"ERROR: VCL_INCLUDE_CXX_0X is always 0 in C++11"
#pragma GCC poison VCL_MEMORY_HAS_SHARED_PTR             //"ERRROR: VCL_MEMORY_HAS_SHARED_PTR is always 1 in C++11"
#pragma GCC poison VCL_MEMORY_HAS_TR1_SHARED_PTR         //"ERROR: VCL_MEMORY_HAS_TR1_SHARED_PTR is always 0 in C++11"
#pragma GCC poison VCL_TR1_MEMORY_HAS_SHARED_PTR         //"ERROR: VCL_TR1_MEMORY_HAS_SHARED_PTR is always 0 in C++11"
#pragma GCC poison VCL_USE_ATOMIC_COUNT                  //"ERROR: VCL_USE_ATOMIC_COUNT is always defined in C++11"
#pragma GCC poison VCL_CXX_HAS_TR1                       //"ERROR: C++11 never has TR1"

#pragma GCC poison VCL_CXX_HAS_HEADER_CASSERT            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CSETJMP            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CSTDIO             //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CTIME              //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CCTYPE             //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CLIMITS            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CSIGNAL            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CWCHAR             //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CERRNO             //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CLOCALE            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CSTDARG            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CSTRING            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CWCTYPE            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CMATH              //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_CSTDDEF            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_ALGORITHM          //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_IOMANIP            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_LIST               //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_OSTREAM            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_STREAMBUF          //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_BITSET             //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_IOS                //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_LOCALE             //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_QUEUE              //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_STRING             //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_COMPLEX            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_IOSFWD             //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_MAP                //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_SET                //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_TYPEINFO           //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_DEQUE              //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_IOSTREAM           //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_MEMORY             //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_SSTREAM            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_UTILITY            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_EXCEPTION          //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_ISTREAM            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_NEW                //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_STACK              //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_VALARRAY           //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_FSTREAM            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_ITERATOR           //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_NUMERIC            //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_STDEXCEPT          //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_VECTOR             //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_FUNCTIONAL         //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CXX_HAS_HEADER_STRSTREAM          //"ERROR: C++11 headers are mandatory"
#pragma GCC poison VCL_CHAR_IS_SIGNED                    //"ERROR: Use std::numeric_limits<char>::is_signed instead of VCL_CHAR_IS_SIGNED"
#pragma GCC poison VCL_HAS_LONG_LONG                     //"ERROR:  C++11 always defines long long and unsigned long long."

#pragma GCC poison VXL_COMPILER_IS_GNU_4                 //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_40                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_41                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_42                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_43                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_5                 //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_50                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_51                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_52                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_53                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_6                 //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_60                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_61                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_62                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_63                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_7                 //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_70                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_71                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VXL_COMPILER_IS_GNU_72                //"VXL no longer supplies aliases for compiler versions, use the compiler defines directly"

// TODO:  REMOVE LATER #pragma GCC poison VXL_LEGACY_ERROR_REPORTING            //"ERROR: Legacy error reporting no longer supported."
#pragma GCC poison VCL_VC_DOTNET                         //"error: VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VCL_VC_9                              //"error: VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VCL_VC_10                             //"error: VXL no longer supplies aliases for compiler versions, use the compiler defines directly"
#pragma GCC poison VCL_VC_11                             //"error: VXL no longer supplies aliases for compiler versions, use the compiler defines directly"

#endif // defined(__clang__) || defined(__GNUC__)

#if defined(_MSC_VER)
#  if _MSC_VER < 1900
#   error "Invalid _MSC_VER version. Visual Studio 2015 = Version 14.x is needed to support C++11 features"
#  endif // <1900
#endif // _MSC_VER
#endif

#ifdef VNL_CONFIG_LEGACY_METHODS
#include "vcl_legacy_aliases.h"
#endif

// Specialization for deprecation messages are needed to support various
// compilers prior to c++14 support.  After C++14 support is mandated
// This macro can be replaced with [[deprecated]] language features.
#  ifndef VXL_DEPRECATED
     //MSVC does not consistently define __cplusplus
     //https://developercommunity.visualstudio.com/content/problem/139261/msvc-incorrectly-defines-cplusplus.html
#    if !defined(_MSC_VER) && (VXL_COMPILED_CXX_STANDARD_VERSION > 201402L)
#      define VXL_DEPRECATED [[deprecated]]
#      define VXL_DEPRECATED_MSG(MSG) [[deprecated(MSG)]]
#    elif defined(__clang__) || defined(__GNUC__)
#      define VXL_DEPRECATED __attribute__((__deprecated__))
#      define VXL_DEPRECATED_MSG(MSG) __attribute__((__deprecated__(MSG)))
#    elif defined(_MSC_VER)
#      define VXL_DEPRECATED __declspec(deprecated)
#      define VXL_DEPRECATED_MSG(MSG) __declspec(deprecated(MSG))
#    else
#      define VXL_DEPRECATED
#      define VXL_DEPRECATED_MSG(MSG)
#    endif
#  endif

#if !VXL_LEGACY_FUTURE_REMOVE
#define VXL_DELETED_FUNCTION =delete
#else
#define VXL_DELETED_FUNCTION "USE CXX11 =delete"
#endif

#endif // vcl_compiler_h_
