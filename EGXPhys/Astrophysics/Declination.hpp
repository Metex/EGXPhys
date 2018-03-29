/// @file EGXPhys/Astrophysics/Declination.hpp
///
/// @brief Calculates co-ordinate transformations of Declination.
///
/// @author Elliot Grafil (Metex)
/// @date 3/29/18

/// @defgroup EGXPhys-Astrophysics-Declination Declination
/// @ingroup EGXPhys-Astrophysics

//=================================
// Header guard
#pragma once
//=================================
// Included dependencies
#include <math.h>  

#include "AstrophysicsConstants.hpp"
#include "./../EGXMath/EGXMath.hpp"
//=================================
// Forward declared dependencies

//=================================
//


namespace EGXPhys
{
	/// @addtogroup EGXPhys-Astrophysics-Declination
	/// @{
	
	/**
	*   @brief Converts right ascensions \f$(\alpha_{RA})\f$ from hours \f$(RA_h)\f$, minutes \f$(RA_m)\f$ and seconds\f$(RA_s)\f$ to radians.
	*   		\f[\alpha_{rad}=\frac{pi}{180.0}(15 RA_h + \frac{RA_m}{4.0} + \frac{RA_s}{240.0})\f]
	*   See http://en.wikipedia.org/wiki/Right_ascension, http://en.wikipedia.org/wiki/Sidereal_hour_angle
	*
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*	@return \f$\alpha_{rad}\ (rad)\f$ is the angle in radians.
	*	@see HoursMinutesSecondsToRadian() for alias.
	*	@see HMSToRadian() for alias.
	*	@see RightAscensionToDegree() for conversion from (decimal) degrees.
	*/
	template<typename T>
	T DeclinationToDegree(const T& integerDegrees, const T& arcminutes, const T& arcseconds);

	template<typename T>
	void DegreeToDeclination(const T& decimalDegree, T& degrees, T& arcminutes, T& arcseconds);



	
	

	// Declination to Radians. Delination is in Sexagesimal(traditional degrees) system.
	// !!!WARNING!! Will return with0.0 rads pointing up Z axis and pi/2 pointing at positive X-axis
	// Think Spherical Co-ordinate system http://en.wikipedia.org/wiki/Spherical_coordinate_system
	
//https://en.wikipedia.org/wiki/Declination
	template<typename T>
	T DeclinationToRadian(const T& integerDegrees, const T& arcminutes, const T& arcseconds);

	template<typename T>
	void RadianToDeclination(const T& radians, T& degrees, T& arcminutes, T& arcseconds);


    /// @}
} //namespace EGXPhys

#include "Declination.inl"
