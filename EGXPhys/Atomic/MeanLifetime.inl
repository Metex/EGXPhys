/// @file EGXPhys/Atomic/RadioactiveDecay.inl
///
/// @brief Implimentation of mean lifetime calculations
/// @author Elliot Grafil 
/// @date 8/4/17


namespace EGXPhys{
	
	template<typename T>
	T MeanLifetime(const T& decayConstant){
		return 1.0/decayConstant;
	}
	
  	template<typename T>
	T MeanLifetimeViaHalfLife(const T& halfLife){
		return halfLife/log(2.0);
	}
	
	template<typename T>
	T MeanLifetimeViaDecayWidth(const T& decayWidth){
		return NISTConst::hbarIneVs/decayWidth;
	}  
}//namespace EGXPhys
