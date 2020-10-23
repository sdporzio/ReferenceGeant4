#include "sdp_primaryGeneratorAction.hh"
#include "sdp_detectorConstruction.hh"

#include "G4ParticleGun.hh"
#include "G4RunManager.hh"
#include "G4GeneralParticleSource.hh"
#include "G4Proton.hh"
#include "G4IonTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "Randomize.hh"

#include "G4SolidStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolume.hh"


sdp_primaryGeneratorAction::sdp_primaryGeneratorAction()
: G4VUserPrimaryGeneratorAction(),
  fParticleSource(0)
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);
}

sdp_primaryGeneratorAction::~sdp_primaryGeneratorAction(){}

// Generate primary particles
void sdp_primaryGeneratorAction::GeneratePrimaries(G4Event* event)
{

  G4double x_start = 10*mm;
  G4double y_start = 0*mm;
  G4double z_start = 0*mm;

  G4String particleName;
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* photon
    = particleTable->FindParticle(particleName="opticalphoton");
  fParticleGun->SetParticleDefinition(photon);
  fParticleGun->SetParticleEnergy(500.0*keV);
  // fParticleGun->SetParticleEnergy(5.48*MeV);

  fParticleGun->SetParticlePosition(G4ThreeVector(x_start,y_start,z_start));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(-1,0,0));

  // Isotropic generation
  // G4double cosT = -1.0 + G4UniformRand()*2.0; // ISOTROPIC
  // G4double phi = G4UniformRand()*M_PI*2.;
  // G4double sinT = sqrt(1-cosT*cosT);
  // G4ThreeVector direction(sinT*sin(phi),sinT*cos(phi),cosT);
  // fParticleGun->SetParticleMomentumDirection(direction);
  
  fParticleGun->GeneratePrimaryVertex(event);
};
