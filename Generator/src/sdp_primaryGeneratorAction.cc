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

  G4String particleName;
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* alpha
    = particleTable->FindParticle(particleName="alpha");
  fParticleGun->SetParticleDefinition(alpha);
  fParticleGun->SetParticleEnergy(5.48*MeV);

  fParticleGun->SetParticlePosition(G4ThreeVector(0,0,0));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
  
  fParticleGun->GeneratePrimaryVertex(event);
};
