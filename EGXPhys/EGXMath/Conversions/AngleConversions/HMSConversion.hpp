/// @file EGXMath/Conversions/AngleConversions/HMSConversion.hpp
///
/// @brief Converts angle measurements in hours minutes seconds into various styles such as radians, degrees, DMS, HMS.
///
/// @author Elliot Grafil 
/// @date 3/29/18

/// @defgroup EGXMath-Conversions-AngleConversions-HMS HMS
/// @ingroup EGXMath-Conversions-AngleConversions


//=================================
// Header guard
#pragma once
//=================================
// Included dependencies
#include <cmath>  
#include <string>
#include "../../EGXMathConstants.hpp"

//=================================
// Forward declared dependencies

//=================================
//


namespace EGXMath
{
	/// @addtogroup EGXMath-Conversions-AngleConversions-HMS
	/// @{

	/**
	*   @brief Converts an angle in hours minutes seconds to radian.
	*		\f[\alpha_{rad}=\alpha_{rad}\f]
	*
	*	See https://en.wikipedia.org/wiki/Radian
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*   @return \f$\alpha_{rad}\ (rad)\f$ is the angle in radians.
	*	@see HMSToMilliradian() for conversion to milliradians.
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
	T HMSToRadian(const T& hour, const T& minute, const T& second);

	/**
	*   @brief Converts an angle in hours minutes seconds to milliradian.
	*		\f[\alpha_{mrad}=\alpha_{rad}*10^3\f]
	*
	*	See https://en.wikipedia.org/wiki/Milliradian 
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*   @return \f$\alpha_{mrad}\ (mrad)\f$ is the angle in milliradians.
	*	@see HMSToRadian() for conversion to radians.
	*	@see DegreeToMilliradian() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToMilliradian() for conversion from decimal degrees.
	*	@see RadianToMilliradian() for conversion from radians.
	*	@see IntegerDegreeToMilliradian() for conversion from integer degrees.
	*	@see BinaryDegreeToMilliradian() for conversion from binary degrees.
	*	@see TurnToMilliradian() for conversion from turns.
	*	@see GradianToMilliradian() for conversion from gradians.
	*	@see HoursMinutesSecondsToMilliradian() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToMilliradian() for conversion from degrees minutes seconds.
	*	@see CompassWindToMilliradian() for conversion from compass wind.
	*/
	template<typename T>
	T HMSToMilliradian(const T& hour, const T& minute, const T& second);

	/**
	*   @brief Converts an angle in hours minutes seconds to turn.
	*		\f[\alpha_{turn}=\alpha_{rad}\frac{1}{2 \pi}\f]
	*
	*	See https://en.wikipedia.org/wiki/Turn_(geometry)
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*   @return \f$\alpha_{turn}\ (turn)\f$ is the angle in turns.
	*	@see DegreeToTurn() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToTurn() for conversion from decimal degrees.
	*	@see RadianToTurn() for conversion from radians.
	*	@see IntegerDegreeToTurn() for conversion from integer degrees.
	*	@see BinaryDegreeToTurn() for conversion from binary degrees.
	*	@see TurnToTurn() for conversion from turns.
	*	@see GradianToTurn() for conversion from gradians.
	*	@see HoursMinutesSecondsToTurn() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToTurn() for conversion from degrees minutes seconds.
	*	@see CompassWindToTurn() for conversion from compass wind.
	*/
	template<typename T>
	T HMSToTurn(const T& hour, const T& minute, const T& second);

	/**
	*   @brief Converts an angle in hours minutes seconds to (decimal) degree.
	*		\f[\alpha_{deg}=\alpha_{rad}\frac{180}{\pi}\f]
	*
	*	See https://en.wikipedia.org/wiki/Degree_(angle) and https://en.wikipedia.org/wiki/Decimal_degrees
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*   @return \f$\alpha_{deg}\ (deg)\f$ is the angle in (decimal) degree.
	*	@see HMSToArcdegree() for alias.
	*	@see HMSToDegree() for alias.
	*	@see DegreeToDegree() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToDegree() for conversion from decimal degrees.
	*	@see RadianToDegree() for conversion from radians.
	*	@see IntegerDegreeToDegree() for conversion from integer degrees.
	*	@see BinaryDegreeToDegree() for conversion from binary degrees.
	*	@see TurnToDegree() for conversion from turns.
	*	@see GradianToDegree() for conversion from gradians.
	*	@see HoursMinutesSecondsToDegree() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToDegree() for conversion from degrees minutes seconds.
	*	@see CompassWindToDegree() for conversion from compass wind.
	*/
	template<typename T>
	T HMSToDegree(const T& hour, const T& minute, const T& second);

	/**
	*   @brief Converts an angle in hours minutes seconds to decimal degree.
	*		\f[\alpha_{deg}=\alpha_{rad}\frac{180}{\pi}\f]
	*
	*	See https://en.wikipedia.org/wiki/Degree_(angle) and https://en.wikipedia.org/wiki/Decimal_degrees
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*   @return \f$\alpha_{deg}\ (deg)\f$ is the angle in decimal degree.
	*	@see HMSToDegree() for alias.
	*	@see HMSToArcdegree() for alias.
	*	@see DegreeToDecimalDegree() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToDecimalDegree() for conversion from decimal degrees.
	*	@see RadianToDecimalDegree() for conversion from radians.
	*	@see IntegerDegreeToDecimalDegree() for conversion from integer degrees.
	*	@see BinaryDegreeToDecimalDegree() for conversion from binary degrees.
	*	@see TurnToDecimalDegree() for conversion from turns.
	*	@see GradianToDecimalDegree() for conversion from gradians.
	*	@see HoursMinutesSecondsToDecimalDegree() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToDecimalDegree() for conversion from degrees minutes seconds.
	*	@see CompassWindToDecimalDegree() for conversion from compass wind.
	*/
	template<typename T>
	T HMSToDecimalDegree(const T& hour, const T& minute, const T& second);

	/**
	*   @brief Converts an angle in hours minutes seconds to arcdegree (decimal degree).
	*		\f[\alpha_{deg}=\alpha_{rad}\frac{180}{\pi}\f]
	*
	*	See https://en.wikipedia.org/wiki/Degree_(angle) and https://en.wikipedia.org/wiki/Decimal_degrees
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*   @return \f$\alpha_{deg}\ (deg)\f$ is the angle in arcdegree (decimal degree).
	*	@see HMSToDegree() for alias.
	*	@see HMSToDecimalDegree() for alias.
	*	@see DegreeToArcdegree() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToArcdegree() for conversion from decimal degrees.
	*	@see RadianToArcdegree() for conversion from radians.
	*	@see IntegerDegreeToArcdegree() for conversion from integer degrees.
	*	@see BinaryDegreeToArcdegree() for conversion from binary degrees.
	*	@see TurnToArcdegree() for conversion from turns.
	*	@see GradianToArcdegree() for conversion from gradians.
	*	@see HoursMinutesSecondsToArcdegree() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToArcdegree() for conversion from degrees minutes seconds.
	*	@see CompassWindToArcdegree() for conversion from compass wind.
	*/
	template<typename T>
	T HMSToArcdegree(const T& hour, const T& minute, const T& second);

	/**
	*   @brief Converts an angle in hours minutes seconds to integer degree.
	*		\f[\alpha_{deg\ int}=round(\alpha_{rad}\frac{180}{\pi})\f]
	*
	*	See https://en.wikipedia.org/wiki/Degree_(angle) and https://en.wikipedia.org/wiki/Decimal_degrees
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*   @return \f$\alpha_{deg\ int}\ (deg)\f$ is the angle in integer degrees.
	*	@see DegreeToIntegerDegree() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToIntegerDegree() for conversion from decimal degrees.
	*	@see RadianToIntegerDegree() for conversion from radians.
	*	@see IntegerDegreeToIntegerDegree() for conversion from integer degrees.
	*	@see BinaryDegreeToIntegerDegree() for conversion from binary degrees.
	*	@see TurnToIntegerDegree() for conversion from turns.
	*	@see GradianToIntegerDegree() for conversion from gradians.
	*	@see HoursMinutesSecondsToIntegerDegree() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToIntegerDegree() for conversion from degrees minutes seconds.
	*	@see CompassWindToIntegerDegree() for conversion from compass wind.
	*/
	template<typename T>
	T HMSToIntegerDegree(const T& hour, const T& minute, const T& second);

	/**
	*   @brief Converts an angle in hours minutes seconds to binary degree (brad).
	*		\f[\alpha_{deg\ bin}=round(\alpha_{rad}\frac{2^{(n-1)}}{2 \pi})\f]
	*	Where \f$n\f$ is the number of bits avaliable to store the number. \f$n\f$ defaults to 8, the tradiational number for binary degrees.
	*
	*	See https://en.wikipedia.org/wiki/Binary_scaling#Binary_angles and https://www.globalspec.com/reference/14722/160210/Chapter-7-5-3-Binary-Angular-Measure
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*	@param bits \f$n\ (bit)\f$ is the number of bits avaliable to store the number. Defaults to 8.
	*   @return \f$\alpha_{deg\ bin}\ (brad)\f$ is the angle in binary degrees.
	*	@see DegreeToBinaryDegree() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToBinaryDegree() for conversion from decimal degrees.
	*	@see RadianToBinaryDegree() for conversion from radians.
	*	@see IntegerDegreeToBinaryDegree() for conversion from integer degrees.
	*	@see BinaryDegreeToBinaryDegree() for conversion from binary degrees.
	*	@see TurnToBinaryDegree() for conversion from turns.
	*	@see GradianToBinaryDegree() for conversion from gradians.
	*	@see HoursMinutesSecondsToBinaryDegree() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToBinaryDegree() for conversion from degrees minutes seconds.
	*	@see CompassWindToBinaryDegree() for conversion from compass wind.
	*/
	template<typename T, typename T2>
	T HMSToBinaryDegree(const T& hour, const T& minute, const T& second, const T2& bits = 8);

	/**
	*   @brief Converts an angle in hours minutes seconds to arcminute. Note that arcminutes are not equal to minutes.
	*		\f[\alpha_{arcmin}=\alpha_{rad}\frac{180 * 60}{\pi}\f]
	*
	*	See https://en.wikipedia.org/wiki/Minute_and_second_of_arc
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*   @return \f$\alpha_{arcmin}\ (arcmin)\f$ is the angle in arcminutes. Note that this is 1/60 of an degree. It is not equal to minutes.
	*	@see DegreeToArcminute() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToArcminute() for conversion from decimal degrees.
	*	@see RadianToArcminute() for conversion from radians.
	*	@see IntegerDegreeToArcminute() for conversion from integer degrees.
	*	@see BinaryDegreeToArcminute() for conversion from binary degrees.
	*	@see TurnToArcminute() for conversion from turns.
	*	@see GradianToArcminute() for conversion from gradians.
	*	@see HoursMinutesSecondsToArcminute() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToArcminute() for conversion from degrees minutes seconds.
	*	@see CompassWindToArcminute() for conversion from compass wind.
	*/
	template<typename T>
	T HMSToArcminute(const T& hour, const T& minute, const T& second);

	/**
	*   @brief Converts an angle in hours minutes seconds to arcsecond. Note that arcsecond are not equal to seconds.
	*		\f[\alpha_{arcsec}=\alpha_{rad}\frac{180 * 60 * 60}{\pi}\f]
	*
	*	See https://en.wikipedia.org/wiki/Minute_and_second_of_arc
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*   @return \f$\alpha_{arcsec}\ (arcsec)\f$ is the angle in arcseconds. Note that this is 1/60 of a arcminute, not minute. It is not equal to seconds.
	*	@see DegreeToArcsecond() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToArcsecond() for conversion from decimal degrees.
	*	@see RadianToArcsecond() for conversion from radians.
	*	@see IntegerDegreeToArcsecond() for conversion from integer degrees.
	*	@see BinaryDegreeToArcsecond() for conversion from binary degrees.
	*	@see TurnToArcsecond() for conversion from turns.
	*	@see GradianToArcsecond() for conversion from gradians.
	*	@see HoursMinutesSecondsToArcsecond() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToArcsecond() for conversion from degrees minutes seconds.
	*	@see CompassWindToArcsecond() for conversion from compass wind.
	*/
	template<typename T>
	T HMSToArcsecond(const T& hour, const T& minute, const T& second);

	/**
	*   @brief Converts an angle in hours minutes seconds to milliarcsecond.
	*		\f[\alpha_{mas}=\alpha_{rad}\frac{180 * 60 * 60 * 10^3}{\pi}\f]
	*
	*	See https://en.wikipedia.org/wiki/Minute_and_second_of_arc
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*   @return \f$\alpha_{mas}\ (mas)\f$ is the angle in milliarcseconds.
	*	@see DegreeToMilliarcsecond() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToMilliarcsecond() for conversion from decimal degrees.
	*	@see RadianToMilliarcsecond() for conversion from radians.
	*	@see IntegerDegreeToMilliarcsecond() for conversion from integer degrees.
	*	@see BinaryDegreeToMilliarcsecond() for conversion from binary degrees.
	*	@see TurnToMilliarcsecond() for conversion from turns.
	*	@see GradianToMilliarcsecond() for conversion from gradians.
	*	@see HoursMinutesSecondsToMilliarcsecond() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToMilliarcsecond() for conversion from degrees minutes seconds.
	*	@see CompassWindToMilliarcsecond() for conversion from compass wind.
	*/
	template<typename T>
	T HMSToMilliarcsecond(const T& hour, const T& minute, const T& second);

	/**
	*   @brief Converts an angle in hours minutes seconds to microarcsecond.
	*		\f[\alpha_{\mu as}=\alpha_{rad}\frac{180 * 60 * 60 * 10^6}{\pi}\f]
	*
	*	See https://en.wikipedia.org/wiki/Minute_and_second_of_arc
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*   @return \f$\alpha_{\mu as}\ (\mu as)\f$ is the angle in microarcseconds.
	*	@see DegreeToMicroarcsecond() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToMicroarcsecond() for conversion from decimal degrees.
	*	@see RadianToMicroarcsecond() for conversion from radians.
	*	@see IntegerDegreeToMicroarcsecond() for conversion from integer degrees.
	*	@see BinaryDegreeToMicroarcsecond() for conversion from binary degrees.
	*	@see TurnToMicroarcsecond() for conversion from turns.
	*	@see GradianToMicroarcsecond() for conversion from gradians.
	*	@see HoursMinutesSecondsToMicroarcsecond() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToMicroarcsecond() for conversion from degrees minutes seconds.
	*	@see CompassWindToMicroarcsecond() for conversion from compass wind.
	*/
	template<typename T>
	T HMSToMicroarcsecond(const T& hour, const T& minute, const T& second);

	/**
	*   @brief Converts an angle in hours minutes seconds to degrees minutes seconds (DMS). \f${DD}^{\circ}{MM}'{SS.SS}''\f$ format.
	*
	*	See https://en.wikipedia.org/wiki/Geographic_coordinate_conversion and https://en.wikipedia.org/wiki/Minute_and_second_of_arc
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*	@param integerDegree \f$degree\ (deg int)\f$ is the angle in degrees in whole numbers.
	*	@param arcminute \f$arcminute\ (arcmin)\f$ is the angle in arcminute in whole numbers. Note that this is 1/60 of an degree. It is not equal to minutes.
	*   @param arcsecond \f$arcsecond\ (arcsec)\f$ is the angle in arcsecond. Note that this is 1/60 of a arcminute, not minute. It is not equal to seconds.
	*	@see HMSToDMS() for alias.
	*	@see DegreeToDegreesMinutesSeconds() for conversion from (decimal) degrees and full explination.
	*	@see DecimalDegreeToDegreesMinutesSeconds() for conversion from decimal degrees.
	*	@see RadianToDegreesMinutesSeconds() for conversion from radians.
	*	@see IntegerDegreeToDegreesMinutesSeconds() for conversion from integer degrees.
	*	@see BinaryDegreeToDegreesMinutesSeconds() for conversion from binary degrees.
	*	@see TurnToDegreesMinutesSeconds() for conversion from turns.
	*	@see GradianToDegreesMinutesSeconds() for conversion from gradians.
	*	@see HoursMinutesSecondsToDegreesMinutesSeconds() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToDegreesMinutesSecondsS() for conversion from degrees minutes seconds.
	*	@see CompassWindToDegreesMinutesSeconds() for conversion from compass wind.
	*/
	template<typename T>
	void HMSToDegreesMinutesSeconds(const T& hour, const T& minute, const T& second, T& integerDegree, T& arcminute, T& arcsecond);

	/**
	*   @brief Converts an angle in hours minutes seconds to degrees minutes seconds (DMS). \f${DD}^{\circ}{MM}'{SS.SS}''\f$ format.
	*
	*	See https://en.wikipedia.org/wiki/Geographic_coordinate_conversion and https://en.wikipedia.org/wiki/Minute_and_second_of_arc
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*	@param integerDegree \f$degree\ (deg)\f$ is the angle in degrees in whole numbers.
	*	@param arcminute \f$arcminute\ (arcmin)\f$ is the angle in arcminute in whole numbers. Note that this is 1/60 of an degree. It is not equal to minutes.
	*   @param arcsecond \f$arcsecond\ (arcsec)\f$ is the angle in arcsecond. Note that this is 1/60 of a arcminute, not minute. It is not equal to seconds.
	*	@see HMSToDegreesMinutesSeconds() for alias.
	*	@see DegreeToDMS() for conversion from (decimal) degrees and full explination.
	*	@see DecimalDegreeToDMS() for conversion from decimal degrees.
	*	@see RadianToDMS() for conversion from radians.
	*	@see IntegerDegreeToDMS() for conversion from integer degrees.
	*	@see BinaryDegreeToDMS() for conversion from binary degrees.
	*	@see TurnToDMS() for conversion from turns.
	*	@see GradianToDMS() for conversion from gradians.
	*	@see HoursMinutesSecondsToDMS() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToDMS() for conversion from degrees minutes seconds.
	*	@see CompassWindToDMS() for conversion from compass wind.
	*/
	template<typename T>
	void HMSToDMS(const T& hour, const T& minute, const T& second, T& integerDegree, T& arcminute, T& arcsecond);

	/**
	*   @brief Converts an angle in hours minutes seconds to hours minutes seconds (HMS). \f${HH}^h{MM}^m{SS.SS}^s\f$ format.
	*		\f[hour2 = hour \f]
	*		\f[minute2 = minute\f]
	*		\f[second2 = second\f]
	*
	*	See and https://en.wikipedia.org/wiki/Right_ascension and https://en.wikipedia.org/wiki/Hour_angle
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*	@param hour2 \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute2 \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second2 \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*	@see HMSToHMS() for alias.
	*	@see DegreeToHoursMinutesSeconds() for conversion from (decimal) degrees and full explination.
	*	@see DecimalDegreeToHoursMinutesSeconds() for conversion from decimal degrees.
	*	@see RadianToHoursMinutesSeconds() for conversion from radians.
	*	@see IntegerDegreeToHoursMinutesSeconds() for conversion from integer degrees.
	*	@see BinaryDegreeToHoursMinutesSeconds() for conversion from binary degrees.
	*	@see TurnToHoursMinutesSeconds() for conversion from turns.
	*	@see GradianToHoursMinutesSeconds() for conversion from gradians.
	*	@see HoursMinutesSecondsToHoursMinutesSeconds() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToHoursMinutesSeconds() for conversion from degrees minutes seconds.
	*	@see CompassWindToHoursMinutesSeconds() for conversion from compass wind.
	*/
	template<typename T>
	void HMSToHoursMinutesSeconds(const T& hour, const T& minute, const T& second, T& hour2, T& minute2, T& second2);

	/**
	*   @brief Converts an angle in hours minutes seconds to gradian.
	*		\f[\alpha_{g}=\alpha_{rad}\frac{200}{\pi}\f]
	*
	*	See https://en.wikipedia.org/wiki/Gradian
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*   @return \f$\alpha_{g}\ (g)\f$ is the angle in gradians.
	*	@see HMSToGon() for alias.
	*	@see DegreeToGradian() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToGradian() for conversion from decimal degrees.
	*	@see RadianToGradian() for conversion from radians.
	*	@see IntegerDegreeToGradian() for conversion from integer degrees.
	*	@see BinaryDegreeToGradian() for conversion from binary degrees.
	*	@see TurnToGradian() for conversion from turns.
	*	@see GradianToGradian() for conversion from gradians.
	*	@see HoursMinutesSecondsToGradian() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToGradian() for conversion from degrees minutes seconds.
	*	@see CompassWindToGradian() for conversion from compass wind.
	*/
	template<typename T>
	T HMSToGradian(const T& hour, const T& minute, const T& second);

	/**
	*   @brief Converts an angle in hours minutes seconds to gradian.
	*		\f[\alpha_{g}=\alpha_{rad}\frac{200}{\pi}\f]
	*
	*	See https://en.wikipedia.org/wiki/Gradian
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*   @return \f$\alpha_{g}\ (g)\f$ is the angle in gradians.
	*	@see HMSToGradian() for alias.
	*	@see DegreeToGon() for conversion from (decimal) degrees.
	*	@see DecimalDegreeToGon() for conversion from decimal degrees.
	*	@see RadianToGon() for conversion from radians.
	*	@see IntegerDegreeToGon() for conversion from integer degrees.
	*	@see BinaryDegreeToGon() for conversion from binary degrees.
	*	@see TurnToGon() for conversion from turns.
	*	@see GradianToGon() for conversion from gradians.
	*	@see HoursMinutesSecondsToGon() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToGon() for conversion from degrees minutes seconds.
	*	@see CompassWindToGon() for conversion from compass wind.
	*/
	template<typename T>
	T HMSToGon(const T& hour, const T& minute, const T& second);

	/**
	*   @brief Converts an angle in hours minutes seconds to a n-Wind compass point name.
	*
	*	See https://en.wikipedia.org/wiki/Points_of_the_compass
	*	@param hour \f$hour\ (h)\f$ is the angle in hours in whole numbers.
	*	@param minute \f$minute\ (m)\f$ is the angle in minutes in whole numbers. Note that this is 1/60 of an hour. It is not equal to arcminutes.
	*   @param second \f$second\ (s)\f$ is the angle in seconds. Note that this is 1/60 of a minute. It is not equal to arcseconds.
	*	@param winds \f$winds\ (int)\f$ The number of points(names) that the compass should have. Must be 2,4,8,16 or 32.
	*   @param abbreviate \f$abbreviate\ (bool)\f$ should the compass point name be abbreviated.
	*   @return \f$point\ name\ (dimensionless)\f$ is the name of the compass point.
	*	@see DegreeToCompassWind() for full explination of conversion and conversion from (decimal) degrees.
	*	@see DecimalDegreeToCompassWind() for conversion from decimal degrees.
	*	@see RadianToCompassWind() for conversion from radians.
	*	@see IntegerDegreeToCompassWind() for conversion from integer degrees.
	*	@see BinaryDegreeToCompassWind() for conversion from binary degrees.
	*	@see TurnToCompassWind() for conversion from turns.
	*	@see GradianToCompassWind() for conversion from gradians.
	*	@see HoursMinutesSecondsToCompassWind() for conversion from hours minutes seconds.
	*	@see DegreesMinutesSecondsToCompassWind() for conversion from degrees minutes seconds.
	*	@see CompassWindToCompassWind() for conversion from degrees minutes seconds.
	*/
	template<typename T>
	std::string HMSToCompassWind(const T& hour, const T& minute, const T& second, const unsigned int winds, const bool abbreviate);


    /// @}
} //namespace EGXMath

#include "HMSConversion.inl"
