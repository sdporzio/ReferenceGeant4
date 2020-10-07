#ifndef sdp_detectorConstruction_h
#define sdp_detectorConstruction_h 1
#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;
class G4GenericMessenger;
class G4VSolid;
class sdp_surfaceGenerator;

// Construction class for the detector
class sdp_detectorConstruction : public G4VUserDetectorConstruction
{
  public:
    sdp_detectorConstruction();
    virtual ~sdp_detectorConstruction();

    virtual G4VPhysicalVolume* Construct();

  private:
    G4GenericMessenger* fMessenger; // Generic messenger class
    G4int fHoleType;
    G4float fHoleWidth;
    G4float fHoleOffset;

};

#endif