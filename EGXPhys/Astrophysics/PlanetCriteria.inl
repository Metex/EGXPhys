/// @file EGXPhys/Astrophysics/PlanetCriteria.inl
///
/// @brief Implimentation of planet criteria calculations
/// @author Elliot Grafil 
/// @date 7/31/17


namespace EGXPhys{
	
	
	template<typename T>
    T PlanetSimilarityIndex( const T& planetMeanRadius, const T& referenceMeanRadius, const T& planetBulkDensity, const T& referenceBulkDensity, const T& planetEscapeVelocity, const T& referenceEscapeVelocity, const T& planetSurfaceTemperature, const T& referenceSurfaceTemperature ){
    	return sqrt( 
			PlanetSimilarityIndexInterior(planetMeanRadius, referenceMeanRadius, planetBulkDensity, referenceBulkDensity)
			*
			PlanetSimilarityIndexSurface(planetEscapeVelocity, referenceEscapeVelocity, planetSurfaceTemperature, referenceSurfaceTemperature)
		);
	}
	
	template<typename T>
    T EarthSimilarityIndex( const T& planetMeanRadius, const T& planetBulkDensity, const T& planetEscapeVelocity, const T& planetSurfaceTemperature){
    	return PlanetSimilarityIndex( planetMeanRadius, earthVolumetricMeanRadius, planetBulkDensity, earthDensity, planetEscapeVelocity, earthEscapeVelocity, planetSurfaceTemperature, earthAverageSurfaceTempreture);
	}
	
	template<typename T>
    T PlanetSimilarityIndexInterior( const T& planetMeanRadius, const T& referenceMeanRadius, const T& planetBulkDensity, const T& referenceBulkDensity ){
		return sqrt( 
			pow(1.0 - fabs( (planetMeanRadius - referenceMeanRadius) / (planetMeanRadius + referenceMeanRadius) ), 0.57) 
			*
			pow(1.0 - fabs( (planetBulkDensity - referenceBulkDensity) / (planetBulkDensity + referenceBulkDensity) ), 1.07)
		); 	
	}
	
	template<typename T>
    T EarthSimilarityIndexInterior( const T& planetMeanRadius, const T& planetBulkDensity){
    	return PlanetSimilarityIndexInterior(planetMeanRadius, earthVolumetricMeanRadius, planetBulkDensity, earthDensity);
	}
	
	
	template<typename T>
    T PlanetSimilarityIndexSurface(const T& planetEscapeVelocity, const T& referenceEscapeVelocity, const T& planetSurfaceTemperature, const T& referenceSurfaceTemperature ){
    	return sqrt( 
			pow(1.0 - fabs( (planetEscapeVelocity - referenceEscapeVelocity) / (planetEscapeVelocity + referenceEscapeVelocity) ), 0.70) 
			*
			pow(1.0 - fabs( (planetSurfaceTemperature - referenceSurfaceTemperature) / (planetSurfaceTemperature + referenceSurfaceTemperature) ), 5.58)
		); 
	}
	
	template<typename T>
    T EarthSimilarityIndexSurface(const T& planetEscapeVelocity, const T& planetSurfaceTemperature){
    	return PlanetSimilarityIndexSurface(planetEscapeVelocity, earthEscapeVelocity, planetSurfaceTemperature, earthAverageSurfaceTempreture);
	}
    
    
    
    

}//namespace EGXPhys
