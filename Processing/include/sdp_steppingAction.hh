#ifndef sdp_steppingAction_h
#define sdp_steppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class sdp_eventAction;

class sdp_steppingAction : public G4UserSteppingAction
{
  public:
    sdp_steppingAction(sdp_eventAction* eventAction);
    virtual ~sdp_steppingAction();

    virtual void UserSteppingAction(const G4Step*);

  private:
    sdp_eventAction*  fEventAction;
};

#endif