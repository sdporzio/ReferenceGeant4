#include "sdp_actionInitialization.hh"
#include "sdp_primaryGeneratorAction.hh"
#include "sdp_runAction.hh"
#include "sdp_eventAction.hh"
#include "sdp_steppingAction.hh"

#include "G4ParticleGun.hh"
#include "G4Proton.hh"
#include "G4SystemOfUnits.hh"

// Construct/Deconstructor
sdp_actionInitialization::sdp_actionInitialization() : G4VUserActionInitialization()
{};
sdp_actionInitialization::~sdp_actionInitialization(){};

void sdp_actionInitialization::Build() const
{
  SetUserAction(new sdp_primaryGeneratorAction);

  sdp_runAction* runAction = new sdp_runAction;
  SetUserAction(runAction);

  sdp_eventAction* eventAction = new sdp_eventAction(runAction);
  SetUserAction(eventAction);

  sdp_steppingAction* steppingAction = new sdp_steppingAction(eventAction);
  SetUserAction(steppingAction);
}
