#include "sdp_detectorConstruction.hh"
#include "sdp_materials.hh"

#include "G4RunManager.hh"
#include "G4GenericMessenger.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"
#include "G4SubtractionSolid.hh"

#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4Orb.hh"
#include "G4Paraboloid.hh"
#include "G4Trd.hh"
#include "G4Tubs.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4Material.hh"
#include "g4analysis.hh"

#include <cmath>
#include <iostream>

// Construct/Deconstructor
sdp_detectorConstruction::sdp_detectorConstruction() : G4VUserDetectorConstruction(),
  fMessenger(nullptr)
{
  fMessenger = new G4GenericMessenger(this,"/sdp/","");
}
sdp_detectorConstruction::~sdp_detectorConstruction()
{
  delete fMessenger;
}

// Construct function
G4VPhysicalVolume* sdp_detectorConstruction::Construct()
{
  // HARD-CODED SETTINGS
  // Option to switch on/off checking of volumes overlaps
  G4bool checkOverlaps = false;

  // MATERIALS
  G4NistManager* nist = G4NistManager::Instance();
  sdp_materials* materials = new sdp_materials();
  G4Material* glass = nist->FindOrBuildMaterial("G4_GLASS_LEAD");
  G4Material* alum = nist->FindOrBuildMaterial("G4_ALUMINUM_OXIDE");

  // WORLD PARAMETERS
  G4double world_sizeXYZ = 50*cm;
  // BUILD THE WORLD
  G4Box* solidWorld =    
    new G4Box("World",   //name
       world_sizeXYZ*0.5, world_sizeXYZ*0.5, world_sizeXYZ*0.5);   //size  
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,   //solid
                        glass,   //material
                        "World");   //name   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,   //no rotation
                      G4ThreeVector(),   //location
                      logicWorld,   //logical volume
                      "World",   //name
                      0,   //mother logical volume
                      false,   //no boolean operation
                      0,   //copy number
                      checkOverlaps);   //overlaps checking
  logicWorld->SetVisAttributes(G4Colour(0.,0.,0.,0.));   //assign colour


  // BUILD SUBTRACTION CYLINDER
  G4Tubs* solidSubtTubs =
    new G4Tubs("SubtTubs",   //name
                      0*mm,   //rmin: inner radius
                      25.4/2.*mm,   //rmax: outer radius
                      31.75/2.*mm,   //dz: z half-length
                      0.,   //sphi: starting phi (rad)
                      M_PI*2.);   //dphi: segment angle (rad)
  // BUILD SUBTRACTION PARABOLOID
  G4Paraboloid* solidSubtParaboloid =
    new G4Paraboloid("SubtParaboloid",   //name
                      49.25/2.*mm,   //dz: z half-length
                      0*mm,   //r1: radius at -z half-length
                      100/2.*mm);   //r2: radius at +z half-length (>r1)
  // OBTAIN THE MIRROR
  G4VSolid* solidMirror = 
    new G4SubtractionSolid("Mirror",   //name
      solidSubtTubs,   //solid 1
      solidSubtParaboloid,   //solid2
      0,   //rotation
      G4ThreeVector(0,25.4*mm,11.92*mm));   //translation
  G4LogicalVolume* logicMirror =                         
    new G4LogicalVolume(solidMirror,   //solid
                        glass,   //material
                        "Mirror");   //name
  G4VPhysicalVolume* physMirror = 
      new G4PVPlacement(0,   //no rotation
                        G4ThreeVector(),   //location
                        logicMirror,   //logical volume
                        "Mirror",   //name
                        logicWorld,   //mother logical volume
                        false,   //no boolean operation
                        0,   //copy number
                        checkOverlaps);   //overlaps checking
    logicMirror->SetVisAttributes(G4Colour(0.2,0.2,0.8,0.9));   //assign colour




  // Always return the whole world
  return physWorld;
}
