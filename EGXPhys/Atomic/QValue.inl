/// @file EGXPhys/Atomic/QValue.inl
///
/// @brief Implimentation of Q-value calculations
/// @author Elliot Grafil (Metex)
/// @date 8/18/17


namespace EGXPhys{
	
	template<typename T>
	T QValueInMeV(const T projectileInu, const T targetInu, const T massProduct1Inu, const T massProduct2Inu) {
		return (projectileInu + targetInu - massProduct1Inu - massProduct2Inu) * (T)NISTConst::atomicMassConstantInMeVPercSquared;
	}

	template<typename T>
	T QValueInJ(const T projectileInu, const T targetInu, const T massProduct1Inu, const T massProduct2Inu) {
		return (projectileInu + targetInu - massProduct1Inu - massProduct2Inu) * (T)NISTConst::atomicMassConstantInJPercSquared;
	}

	    // -------------- Alpha ----------------------
    
    template<typename T>
    T QValueAlphaDecayInMeV(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - (T)NISTConst::alphaParticleMassInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInMeVPercSquared;
	}
	
	template<typename T>
    T QValueAlphaDecayInJ(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - (T)NISTConst::alphaParticleMassInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInJPercSquared;
	}	
    
    template<typename T>
    T QValueDoubleAlphaDecayInMeV(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - 2.0 * (T)NISTConst::alphaParticleMassInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInMeVPercSquared;
	}
    
    template<typename T>
    T QValueDoubleAlphaDecayInJ(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - 2.0 * (T)NISTConst::alphaParticleMassInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInJPercSquared;
	}
    
    // -------------- Beta Minus----------------------
    
   	template<typename T>
    T QValueBetaMinusDecayInMeV(const T massParentInu, const T massDaughterInu){
		return ( massParentInu - massDaughterInu ) * (T)NISTConst::atomicMassConstantInMeVPercSquared;
    	//return (massParentInu - (T)NISTConst::electronMassInu - (massDaughterInu - (T)NISTConst::electronMassInu ) ) * (T)NISTConst::atomicMassConstantInMeVPercSquared;
	}
	
	template<typename T>
    T QValueBetaMinusDecayInJ(const T massParentInu, const T massDaughterInu){
		return (massParentInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInJPercSquared;
    	//return (massParentInu - (T)NISTConst::electronMassInu - (massDaughterInu - (T)NISTConst::electronMassInu ) ) * (T)NISTConst::atomicMassConstantInJPercSquared;
	}	
    
    template<typename T>
    T QValueDoubleBetaMinusDecayInMeV(const T massParentInu, const T massDaughterInu){
		return (massParentInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInMeVPercSquared;
    	//return (massParentInu - 2.0 * (T)NISTConst::electronMassInu - (massDaughterInu - 2.0 * (T)NISTConst::electronMassInu ) ) * (T)NISTConst::atomicMassConstantInMeVPercSquared;
	}
    
    template<typename T>
    T QValueDoubleBetaMinusDecayInJ(const T massParentInu, const T massDaughterInu){
		return (massParentInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInJPercSquared;
    	//return (massParentInu - 2.0 * (T)NISTConst::electronMassInu - (massDaughterInu - 2.0 * (T)NISTConst::electronMassInu ) ) * (T)NISTConst::atomicMassConstantInJPercSquared;
	}
    
    // -------------- Beta Plus ----------------------
    // Note positron mass = electron mass
    
    template<typename T>
    T QValueBetaPlusDecayInMeV(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - (T)NISTConst::electronMassInu - (massDaughterInu + (T)NISTConst::electronMassInu ) ) * (T)NISTConst::atomicMassConstantInMeVPercSquared;
	}
    
	template<typename T>
    T QValueBetaPlusDecayInJ(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - (T)NISTConst::electronMassInu - (massDaughterInu + (T)NISTConst::electronMassInu ) ) * (T)NISTConst::atomicMassConstantInJPercSquared;
	}
    
    template<typename T>
    T QValueDoubleBetaPlusDecayInMeV(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - 2.0 * (T)NISTConst::electronMassInu - (massDaughterInu + 2.0 * (T)NISTConst::electronMassInu ) ) * (T)NISTConst::atomicMassConstantInMeVPercSquared;
	}
    
    template<typename T>
    T QValueDoubleBetaPlusDecayInJ(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - 2.0 * (T)NISTConst::electronMassInu - (massDaughterInu + 2.0 * (T)NISTConst::electronMassInu ) ) * (T)NISTConst::atomicMassConstantInJPercSquared;
	}
    
    // -------------- Electron Capture ----------------------
    
	template<typename T>
	T QValueElectronCaptureInMeV(const T massParentInu, const T massDaughterInu, const T neutronBindingEnergyInMeV) {
		return (massParentInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInMeVPercSquared - neutronBindingEnergyInMeV;
	}

	template<typename T>
	T QValueElectronCaptureInJ(const T massParentInu, const T massDaughterInu, const T neutronBindingEnergyInJ) {
		return (massParentInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInJPercSquared - neutronBindingEnergyInJ;
	}

	template<typename T>
	T QValueDoubleElectronCaptureInMeV(const T massParentInu, const T massDaughterInu, const T neutronBindingEnergyInMeV) {
		return (massParentInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInMeVPercSquared - neutronBindingEnergyInMeV;
	}

	template<typename T>
	T QValueDoubleElectronCaptureInJ(const T massParentInu, const T massDaughterInu, const T neutronBindingEnergyInJ) {
		return (massParentInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInJPercSquared - neutronBindingEnergyInJ;
	}
    
    // -------------- Neutron ----------------------
    
    template<typename T>
    T QValueNeutronDecayInMeV(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - (T)NISTConst::neutronMassInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInMeVPercSquared;
	}
    
	template<typename T>
    T QValueNeutronDecayInJ(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - (T)NISTConst::neutronMassInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInJPercSquared;
	}
    
    template<typename T>
    T QValueDoubleNeutronDecayInMeV(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - 2.0 * (T)NISTConst::neutronMassInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInMeVPercSquared;
	}
    
    template<typename T>
    T QValueDoubleNeutronDecayInJ(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - 2.0 * (T)NISTConst::neutronMassInu - massDaughterInu) * (T)NISTConst::atomicMassConstantInJPercSquared;
	}
    
    // -------------- Proton ----------------------
    
    template<typename T>
    T QValueProtonDecayInMeV(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - (T)NISTConst::protonMassInu - massDaughterInu - (T)NISTConst::electronMassInu) * (T)NISTConst::atomicMassConstantInMeVPercSquared;
	}
    
	template<typename T>
    T QValueProtonDecayInJ(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - (T)NISTConst::protonMassInu - massDaughterInu - (T)NISTConst::electronMassInu) * (T)NISTConst::atomicMassConstantInJPercSquared;
	}
    
    template<typename T>
    T QValueDoubleProtonDecayInMeV(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - 2.0 * (T)NISTConst::protonMassInu - massDaughterInu - 2.0 * (T)NISTConst::electronMassInu) * (T)NISTConst::atomicMassConstantInMeVPercSquared;
	}
    
    template<typename T>
    T QValueDoubleProtonDecayInJ(const T massParentInu, const T massDaughterInu){
    	return (massParentInu - 2.0 * (T)NISTConst::protonMassInu - massDaughterInu - 2.0 * (T)NISTConst::electronMassInu) * (T)NISTConst::atomicMassConstantInJPercSquared;
	}
}//namespace EGXPhys
