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
  G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
  G4Material* water = nist->FindOrBuildMaterial("G4_WATER");
  G4Material* glass = nist->FindOrBuildMaterial("G4_GLASS_LEAD");
  G4Material* alum = nist->FindOrBuildMaterial("G4_ALUMINUM_OXIDE");
  G4Material* vacuum = materials->vacuum;


  // SIZE PARAMETERS
  G4double worldSize= 10*cm;
  G4double boxSizeOuter = 5.2*cm;
  G4double boxSizeInner = 5*cm;
  G4double tubeRadius = 3*mm;
  G4double tubeLength = 6*mm;

  // BUILD THE WORLD
  G4Box* solidWorld =    
    new G4Box("World",   //name
       worldSize*.5, worldSize*.5, worldSize*.5);   //size  
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,   //solid
                        air,   //material
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



  // BUILD SUBTRACTION BOX OUTER
  G4Box* solidBoxOuter =    
    new G4Box("BoxOuter",   //name
       boxSizeOuter*.5, boxSizeOuter*.5, boxSizeOuter*.5);   //size  
  // BUILD SUBTRACTION BOX INNER
  G4Box* solidBoxInner =    
    new G4Box("BoxInner",   //name
       boxSizeInner*.5, boxSizeInner*.5, boxSizeInner*.5);   //size  
  // OBTAIN THE BOX
  G4VSolid* solidBox = 
    new G4SubtractionSolid("Box",   //name
      solidBoxOuter,   //solid 1
      solidBoxInner,   //solid2
      0,   //rotation
      G4ThreeVector());   //translation
  G4LogicalVolume* logicBox =                         
    new G4LogicalVolume(solidBox,   //solid
                        glass,   //material
                        "Box");   //name
  G4VPhysicalVolume* physBox = 
      new G4PVPlacement(0,   //no rotation
                        G4ThreeVector(),   //location
                        logicBox,   //logical volume
                        "Box",   //name
                        logicWorld,   //mother logical volume
                        false,   //no boolean operation
                        0,   //copy number
                        checkOverlaps);   //overlaps checking
    logicBox->SetVisAttributes(G4Colour(0.,1.,1.,0.3));   //assign colour

  // VACUUM
  G4LogicalVolume* logicVacuum =                         
    new G4LogicalVolume(solidBoxInner,   //solid
                        vacuum,   //material
                        "Vacuum");   //name
  G4RotationMatrix* myRot = new G4RotationMatrix;
  myRot->rotateZ(180*deg);
  myRot->rotateX(45*deg);
  G4VPhysicalVolume* physVacuum = 
      new G4PVPlacement(0,   //no rotation
                        G4ThreeVector(-10*mm,2*mm,0),   //location
                        logicVacuum,   //logical volume
                        "Vacuum",   //name
                        logicBox,   //mother logical volume
                        false,   //no boolean operation
                        0,   //copy number
                        checkOverlaps);   //overlaps checking
    logicVacuum->SetVisAttributes(G4Colour(0.,.4,0.,.2));   //assign colour


  // TUBE
  // G4Tubs* solidTube =    
  //   new G4Tubs("Tube",   //name
  //      0.,   // rmin: inner radius
  //      tubeRadius*.5,   // rmax: outer radius
  //      tubeLength*.5,   // dz: z half-length
  //      0.,   // sphi: starting phi angle
  //      2.*M_PI);   // dphi: angle of segment in radians
  G4Box* solidTube =    
    new G4Box("Tube", 5.*mm, 5.*mm, 5.*mm); // ALTERNATIVE TUBE
  G4LogicalVolume* logicTube =                         
    new G4LogicalVolume(solidTube,   //solid
                        alum,   //material
                        "Tube");   //name   
  myRot = new G4RotationMatrix;
  myRot->rotateZ(-45*deg);
  myRot->rotateX(90*deg);
  G4VPhysicalVolume* physTube = 
    new G4PVPlacement(myRot,   //no rotation
                      G4ThreeVector(-1.*mm,-4.*mm,0.),   //location
                      logicTube,   //logical volume
                      "Tube",   //name
                      logicVacuum,   //mother logical volume
                      false,   //no boolean operation
                      0,   //copy number
                      checkOverlaps);   //overlaps checking
  logicTube->SetVisAttributes(G4Colour(.4,.05,.05,.2));   //assign colour

  // Always return the whole world
  return physWorld;
}
