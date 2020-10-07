#ifndef sdp_runAction_h
#define sdp_runAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

class sdp_eventAction;
class G4Run;
class G4GenericMessenger;

class sdp_runAction : public G4UserRunAction
{
  public:
    sdp_runAction();
    virtual ~sdp_runAction();

    virtual void BeginOfRunAction(const G4Run*);
    virtual void   EndOfRunAction(const G4Run*);

  private:
    sdp_eventAction* fEventAction;
    G4int fRunSeed;
};

#endif