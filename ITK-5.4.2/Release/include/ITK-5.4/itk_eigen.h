/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef itk_eigen_h
#define itk_eigen_h

/* Usage:
 *  ITK_EIGEN(Eigenvalues)
 *  If using a Eigen3 header containing non MPL2 code
 *  It would generate errors when using internal Eigen, but not with system Eigen.
 *  And only if ITK_USE_EIGEN_MPL2_ONLY is ON (enabled in CI and Dashboards).
 *  This prevents including non mpl2 code in internal code.
 *  For example, the following contains non MPL2 code:
 *  ITK_EIGEN(SparseCholesky)
 */

/* Re-using internal Eigen3 in other project:
 * A project can re-use the internal Eigen3, not dealing with this header
 * nor with the ITK_EIGEN macro (intended for internal usage only).
 *
\code{.cmake}
find_package(ITK REQUIRED COMPONENTS
  ITKCommon
  ITKEigen3
  )
include(H:/Tool/ITK-5.4.2/ITK-5.4.2-Source/CMake/UseITK.cmake)
if(DEFINED ITKInternalEigen3_DIR)
  set(Eigen3_DIR H:/Tool/ITK-5.4.2/Build/ITKInternalEigen3-build)
endif()
message(STATUS "From ITK: Eigen3_DIR: ")
find_package(Eigen3 REQUIRED CONFIG)
add_executable(main main.cpp)
target_link_libraries(main PUBLIC )
target_link_libraries(main PUBLIC Eigen3::Eigen)
\endcode
 *
 * Then, the user can use Eigen3 as usual:
 * #include "Eigen/Eigenvalues"
 * This is intended to facilitate bridging third party libraries and algorithms
 * which currently use Eigen3 internally.
 * For an example check the module: https://github.com/phcerdan/ITKTotalVariation
 */

/* Helper macro to stringify
 * dev: If not stringified, the macro cannot be used twice in the same header. */
#define ITK_EIGEN_STR(x) #x

/* Use the eigen library configured for ITK.  */
/* #undef ITK_USE_SYSTEM_EIGEN */
#ifdef ITK_USE_SYSTEM_EIGEN
#define ITK_EIGEN(x) ITK_EIGEN_STR(Eigen/x)
#else
// ITK should only be using MPL2 Eigen code internally.
/* #undef ITK_USE_EIGEN_MPL2_ONLY */
#ifdef ITK_USE_EIGEN_MPL2_ONLY
#ifndef EIGEN_MPL2_ONLY
#define EIGEN_MPL2_ONLY
#endif
#endif
#define ITK_EIGEN(x) ITK_EIGEN_STR(itkeigen/Eigen/x)
#endif

#endif
