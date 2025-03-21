// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkIndexedIntArray
 * @brief   indexed implicit array of int.
 *
 * vtkIndexedIntArray is an indexed implicit array of values of type int.
 * see vtkIndexedArray, vtkIndexedImplicitBackend
 *
 * This file is generated by vtkImplicitArrays.cmake
 */

#ifndef vtkIndexedIntArray_h
#define vtkIndexedIntArray_h

#include "vtkIndexedArray.h" // Real Superclass
#include "vtkCommonCoreModule.h"     // For export macro
#include "vtkDataArray.h"

// Fake the superclass for the wrappers.
#ifndef __VTK_WRAP__
#define vtkDataArray vtkIndexedArray<int>
#endif
VTK_ABI_NAMESPACE_BEGIN
class VTKCOMMONCORE_EXPORT vtkIndexedIntArray : public vtkDataArray
{
public:
  vtkImplicitArrayTypeMacro(vtkIndexedIntArray, vtkDataArray);
#ifndef __VTK_WRAP__
#undef vtkDataArray
#endif

  static vtkIndexedIntArray* New();
  static vtkIndexedIntArray* ExtendedNew();
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // This macro expands to the set of method declarations that
  // make up the interface of vtkImplicitArray, which is ignored
  // by the wrappers.
#if defined(__VTK_WRAP__) || defined(__WRAP_GCCXML__)
  vtkCreateReadOnlyWrappedArrayInterface(int);
#endif

  /**
   * A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
   */
  static vtkIndexedIntArray* FastDownCast(vtkAbstractArray* source)
  {
    return static_cast<vtkIndexedIntArray*>(Superclass::FastDownCast(source));
  }

  ///@{
  /**
   * Set which indexes from array should be exposed.
   */
  void ConstructBackend(vtkIdList* indexes, vtkDataArray* array);
  void ConstructBackend(vtkDataArray* indexes, vtkDataArray* array);
  ///@}

protected:
  vtkIndexedIntArray();
  ~vtkIndexedIntArray() override;

private:
  typedef vtkIndexedArray<int> RealSuperclass;

  vtkIndexedIntArray(const vtkIndexedIntArray&) = delete;
  void operator=(const vtkIndexedIntArray&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkIndexedIntArray);

VTK_ABI_NAMESPACE_END
#endif
// VTK-HeaderTest-Exclude: TYPEMACRO
