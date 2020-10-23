#include "sdp_materials.hh"

#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "G4Element.hh"
#include "G4Isotope.hh"
#include "G4Material.hh"


sdp_materials::sdp_materials()
{

  G4double atomicNumber = 1.;
  G4double massOfMole = 1.008*g/mole;
  G4double density = 1.e-25*g/cm3;
  G4double temperature = 2.73*kelvin;
  G4double pressure = 3.e-18*pascal;
  vacuum = new G4Material("vacuum",atomicNumber,massOfMole,density,kStateGas,temperature,pressure); 

}
sdp_materials::~sdp_materials(){}
