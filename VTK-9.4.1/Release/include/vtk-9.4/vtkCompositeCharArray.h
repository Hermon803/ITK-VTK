// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkCompositeCharArray
 * @brief   composite implicit array of char.
 *
 * vtkCompositeCharArray is a composite implicit array of values of type char.
 * see vtkCompositeArray, vtkCompositeImplicitBackend
 *
 * This file is generated by vtkImplicitArrays.cmake
 */

#ifndef vtkCompositeCharArray_h
#define vtkCompositeCharArray_h

#include "vtkCompositeArray.h" // Real Superclass
#include "vtkCommonCoreModule.h"     // For export macro
#include "vtkDataArray.h"

// Fake the superclass for the wrappers.
#ifndef __VTK_WRAP__
#define vtkDataArray vtkCompositeArray<char>
#endif
VTK_ABI_NAMESPACE_BEGIN
class vtkDataArrayCollection;

class VTKCOMMONCORE_EXPORT vtkCompositeCharArray : public vtkDataArray
{
public:
  vtkImplicitArrayTypeMacro(vtkCompositeCharArray, vtkDataArray);
#ifndef __VTK_WRAP__
#undef vtkDataArray
#endif

  static vtkCompositeCharArray* New();
  static vtkCompositeCharArray* ExtendedNew();
  void PrintSelf(ostream& os, vtkIndent indent) override;

  // This macro expands to the set of method declarations that
  // make up the interface of vtkImplicitArray, which is ignored
  // by the wrappers.
#if defined(__VTK_WRAP__) || defined(__WRAP_GCCXML__)
  vtkCreateReadOnlyWrappedArrayInterface(char);
#endif

  /**
   * A faster alternative to SafeDownCast for downcasting vtkAbstractArrays.
   */
  static vtkCompositeCharArray* FastDownCast(vtkAbstractArray* source)
  {
    return static_cast<vtkCompositeCharArray*>(Superclass::FastDownCast(source));
  }

  /**
   * Set the underlying arrays to use.
   */
  void ConstructBackend(vtkDataArrayCollection* arrays);

protected:
  vtkCompositeCharArray();
  ~vtkCompositeCharArray() override;

private:
  typedef vtkCompositeArray<char> RealSuperclass;

  vtkCompositeCharArray(const vtkCompositeCharArray&) = delete;
  void operator=(const vtkCompositeCharArray&) = delete;
};

// Define vtkArrayDownCast implementation:
vtkArrayDownCast_FastCastMacro(vtkCompositeCharArray);

VTK_ABI_NAMESPACE_END
#endif
// VTK-HeaderTest-Exclude: TYPEMACRO
