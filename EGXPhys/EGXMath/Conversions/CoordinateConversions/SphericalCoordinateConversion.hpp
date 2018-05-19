/// @file EGXMath/Conversions/CoordinateConversions/SphericalCoordinateConversion.hpp
///
/// @brief Converts a set of coordinates fom Spherical into Cartesian, Polar ect.
///
/// @author Elliot Grafil (Metex)
/// @date 5/18/18

/// @defgroup EGXMath-Conversions-CoordinateConversions-Spherical Spherical
/// @ingroup EGXMath-Conversions-CoordinateConversions
//=================================
// Header guard
#pragma once
//=================================
// Included dependencies
#include <math.h>  
#include <string>
#include "../../EGXMathConstants.hpp"

//=================================
// Forward declared dependencies

//=================================
//


namespace EGXMath
{
	/// @addtogroup EGXMath-Conversions-CoordinateConversions-Spherical
	/// @{
	
	//// Degrees
	/**
	*   @brief Converts an angle in (decimal) degrees to radians.
	*		\f[\alpha_{rad}=\alpha_{deg}\frac{\pi}{180}\f]
	*
	*	See https://en.wikipedia.org/wiki/Radian
	*   @param decimalDegree \f$\alpha_{deg}\ (deg)\f$ is the angle in decimal degrees.
	*   @return \f$\alpha_{rad}\ (rad)\f$ is the angle in radians.
	*	@see DecimalDegreeToRadian() for alias.
	*	@see DegreeToMilliradian() for conversion to milliradians.
	*	@see DegreeToRadian() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToRadian() for conversion from decimal degrees.
	*	@see RadianToRadian() for conversion from radians.
	*	@see IntegerDegreeToRadian() for conversion from integer degrees.
	*	@see BinaryDegreeToRadian() for conversion from binary degrees.
	*	@see TurnToRadian() for conversion from turns.
	*	@see GradianToRadian() for conversion from gradians.
	*	@see HoursMinutesSecondsToRadian() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToRadian() for conversion from degrees minutes seconds.
	*	@see CompassWindToRadian() for conversion from compass wind.
	*/
	template<typename T>
	T DegreeToRadian(const T& decimalDegree);

    void SphericalCordinatesOfPointGivenCenter(const double centerR, const double centerAzimuth, const double centerZenith,
        const double pointR, const double pointAzimuth, const double pointZenith,
        double &R, double &Azimuth, double &Zenith);
    void SphericalToCartesian(const double R, const double Azimuth, const double Zenith,
        double &X, double &Y, double &Z);


	/// @}
} //namespace EGXMath

#include "SphericalCoordinateConversion.inl"
