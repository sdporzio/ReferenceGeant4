#ifndef sdp_primaryGeneratorAction_h
#define sdp_primaryGeneratorAction_h 1
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4GeneralParticleSource.hh"


class G4ParticleGun;
class G4GeneralParticleSource;
class G4Event;

class sdp_primaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    sdp_primaryGeneratorAction();
    virtual ~sdp_primaryGeneratorAction();
    
    virtual void GeneratePrimaries(G4Event*);

    const G4GeneralParticleSource* GetParticleSource() const { return fParticleSource; }
  
  private:
    G4GeneralParticleSource* fParticleSource;
    G4ParticleGun* fParticleGun;
};

#endif