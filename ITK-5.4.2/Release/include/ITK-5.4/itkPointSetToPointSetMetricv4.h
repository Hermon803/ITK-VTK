/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         https://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkPointSetToPointSetMetricv4_h
#define itkPointSetToPointSetMetricv4_h

#include "itkPointSetToPointSetMetricWithIndexv4.h"

namespace itk
{
/** \class PointSetToPointSetMetricv4
 * \brief Computes similarity between two point sets.
 *
 * This class is templated over the type of the two point-sets.  It
 * expects a Transform to be plugged in for each of fixed and moving
 * point sets. The transforms default to IdentityTransform types. This particular
 * class is the base class for a hierarchy of point-set to point-set metrics.
 *
 * This class computes a value that measures the similarity between the fixed
 * point-set and the moving point-set in the moving domain. The fixed point set
 * is transformed into the virtual domain by computing the inverse of the
 * fixed transform, then transformed into the moving domain using the
 * moving transform.
 *
 * Since the \c PointSet class permits each \c Point to be associated with a
 * \c PixelType, there are potential applications which could make use of
 * this additional information.  For example, the derived \c LabeledPointSetToPointSetMetric
 * class uses the \c PixelType as a \c LabelEnum for estimating total metric values
 * and gradients from the individual label-wise point subset metric and derivatives
 *
 * If a virtual domain is not defined by the user, one of two things happens:
 * 1) If the moving transform is a global type, then the virtual domain is
 * left undefined and every point is considered to be within the virtual domain.
 * 2) If the moving transform is a local-support type, then the virtual domain
 * is taken during initialization from the moving transform displacement field,
 * and all fixed points are verified to be within the virtual domain after
 * transformation by the inverse fixed transform. Points outside the virtual
 * domain are not used. See GetNumberOfValidPoints() to verify how many fixed
 * points were used during evaluation.
 *
 * See ObjectToObjectMetric documentation for more discussion on the virtual domain.
 *
 * \note When used with an RegistrationParameterScalesEstimator estimator, a VirtualDomainPointSet
 * must be defined and assigned to the estimator, for use in shift estimation.
 * The virtual domain point set can be retrieved from the metric using the
 * GetVirtualTransformedPointSet() method.
 *
 * \ingroup ITKMetricsv4
 */

template <typename TFixedPointSet,
          typename TMovingPointSet = TFixedPointSet,
          class TInternalComputationValueType = double>
class ITK_TEMPLATE_EXPORT PointSetToPointSetMetricv4
  : public PointSetToPointSetMetricWithIndexv4<TFixedPointSet, TMovingPointSet, TInternalComputationValueType>
{
public:
  ITK_DISALLOW_COPY_AND_MOVE(PointSetToPointSetMetricv4);

  /** Standard class type aliases. */
  using Self = PointSetToPointSetMetricv4;
  using Superclass =
    PointSetToPointSetMetricWithIndexv4<TFixedPointSet, TMovingPointSet, TInternalComputationValueType>;
  using Pointer = SmartPointer<Self>;
  using ConstPointer = SmartPointer<const Self>;

  /** \see LightObject::GetNameOfClass() */
  itkOverrideGetNameOfClassMacro(PointSetToPointSetMetricv4);

  /**  Type of the measure. */
  using typename Superclass::MeasureType;

  /**  Type of the parameters. */
  using typename Superclass::ParametersType;
  using typename Superclass::ParametersValueType;
  using typename Superclass::NumberOfParametersType;

  /**  Type of the derivative. */
  using typename Superclass::DerivativeType;

  /** Transform types from Superclass*/
  using typename Superclass::FixedTransformType;
  using typename Superclass::FixedTransformPointer;
  using typename Superclass::FixedInputPointType;
  using typename Superclass::FixedOutputPointType;
  using typename Superclass::FixedTransformParametersType;

  using typename Superclass::MovingTransformType;
  using typename Superclass::MovingTransformPointer;
  using typename Superclass::MovingInputPointType;
  using typename Superclass::MovingOutputPointType;
  using typename Superclass::MovingTransformParametersType;

  using typename Superclass::JacobianType;
  using typename Superclass::FixedTransformJacobianType;
  using typename Superclass::MovingTransformJacobianType;

  using DisplacementFieldTransformType = typename Superclass::MovingDisplacementFieldTransformType;

  /** Dimension type */
  using typename Superclass::DimensionType;

  /**  Type of the fixed point set. */
  using FixedPointSetType = TFixedPointSet;
  using FixedPointType = typename TFixedPointSet::PointType;
  using FixedPixelType = typename TFixedPointSet::PixelType;
  using FixedPointsContainer = typename TFixedPointSet::PointsContainer;

  static constexpr DimensionType FixedPointDimension = Superclass::FixedPointDimension;

  /**  Type of the moving point set. */
  using MovingPointSetType = TMovingPointSet;
  using MovingPointType = typename TMovingPointSet::PointType;
  using MovingPixelType = typename TMovingPointSet::PixelType;
  using MovingPointsContainer = typename TMovingPointSet::PointsContainer;

  static constexpr DimensionType MovingPointDimension = Superclass::MovingPointDimension;

  /**
   * typedefs for the data types used in the point set metric calculations.
   * It is assumed that the constants of the fixed point set, such as the
   * point dimension, are the same for the "common space" in which the metric
   * calculation occurs.
   */
  static constexpr DimensionType PointDimension = Superclass::PointDimension;

  using typename Superclass::PointType;
  using typename Superclass::PixelType;
  using CoordinateType = typename PointType::CoordRepType;
  using CoordRepType = CoordinateType;
  using PointsContainer = FixedPointsContainer;
  using PointsConstIterator = typename PointsContainer::ConstIterator;
  using typename Superclass::PointIdentifier;

  /** Typedef for points locator class to speed up finding neighboring points */
  using typename Superclass::PointsLocatorType;
  using NeighborsIdentifierType = typename PointsLocatorType::NeighborsIdentifierType;

  using typename Superclass::FixedTransformedPointSetType;
  using typename Superclass::MovingTransformedPointSetType;

  using typename Superclass::DerivativeValueType;
  using typename Superclass::LocalDerivativeType;

  /** Types for the virtual domain */
  using VirtualImageType = typename Superclass::VirtualImageType;
  using typename Superclass::VirtualImagePointer;
  using typename Superclass::VirtualPixelType;
  using typename Superclass::VirtualRegionType;
  using typename Superclass::VirtualSizeType;
  using typename Superclass::VirtualSpacingType;
  using VirtualOriginType = typename Superclass::VirtualPointType;
  using typename Superclass::VirtualPointType;
  using typename Superclass::VirtualDirectionType;
  using VirtualRadiusType = typename Superclass::VirtualSizeType;
  using typename Superclass::VirtualIndexType;
  using typename Superclass::VirtualPointSetType;
  using typename Superclass::VirtualPointSetPointer;

  /**
   * Function to be defined in the appropriate derived classes.  Calculates
   * the local metric value for a single point.  The \c PixelType may or
   * may not be used.  See class description for further explanation.
   */
  virtual MeasureType
  GetLocalNeighborhoodValue(const PointType &, const PixelType & pixel) const = 0;

  /**
   * Calculates the local derivative for a single point.
   * The default implementation calls  GetLocalNeighborhoodValueAndDerivative.
   * The \c PixelType may or may not be used.  See class
   * description for further explanation.
   * Default implementation calls GetLocalNeighborhoodValueAndDerivative.
   */
  virtual LocalDerivativeType
  GetLocalNeighborhoodDerivative(const PointType &, const PixelType & pixel) const;

  /**
   * Calculates the local value/derivative for a single point.  The \c PixelType may or
   * may not be used.  See class description for further explanation.
   */
  virtual void
  GetLocalNeighborhoodValueAndDerivative(const PointType &,
                                         MeasureType &,
                                         LocalDerivativeType &,
                                         const PixelType & pixel) const = 0;


protected:
  PointSetToPointSetMetricv4() = default;
  ~PointSetToPointSetMetricv4() override = default;

private:
  MeasureType
  GetLocalNeighborhoodValueWithIndex(const PointIdentifier &,
                                     const PointType & point,
                                     const PixelType & pixel) const override
  {
    return this->GetLocalNeighborhoodValue(point, pixel);
  };

  LocalDerivativeType
  GetLocalNeighborhoodDerivativeWithIndex(const PointIdentifier &,
                                          const PointType & point,
                                          const PixelType & pixel) const override
  {
    return this->GetLocalNeighborhoodDerivative(point, pixel);
  };

  void
  GetLocalNeighborhoodValueAndDerivativeWithIndex(const PointIdentifier &,
                                                  const PointType &     point,
                                                  MeasureType &         measure,
                                                  LocalDerivativeType & derivative,
                                                  const PixelType &     pixel) const override
  {
    this->GetLocalNeighborhoodValueAndDerivative(point, measure, derivative, pixel);
  };
};
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#  include "itkPointSetToPointSetMetricv4.hxx"
#endif

#endif
