#ifndef sdp_eventAction_h
#define sdp_eventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include <vector>

class G4Event;
class sdp_runAction;
class sdp_anaTrack;

class sdp_eventAction : public G4UserEventAction
{
  public:
    sdp_eventAction(sdp_runAction* runAction);
    virtual ~sdp_eventAction();
    
    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);

    void AddEnDep(G4String volumeName, G4double edep)
    {
      fEnDep_vector[volumeName].push_back(edep);
      fEnDep[volumeName] += edep;
    }

    
    // Too lazy to put it in private and write methods
    std::map<G4int,sdp_anaTrack> fAnaTrack;


  private:
    sdp_runAction* fRunAction;
    std::map<G4String,std::vector<G4double>> fEnDep_vector;
    std::map<G4String,G4double> fEnDep; // MeV?
    G4long fEventSeedIndex, fEventSeed1, fEventSeed2;
    time_t startTime, previousTime;
};

#endif
