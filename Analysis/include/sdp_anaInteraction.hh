#ifndef sdp_anaInteraction_h
#define sdp_anaInteraction_h 1

#include "globals.hh"


class sdp_anaInteraction
{
  public:
    sdp_anaInteraction();
    virtual ~sdp_anaInteraction();

    G4String name;
    G4int pdg;
    G4int interactionId;
    G4int trackId;
    G4int parentId;
    G4int nSteps;
    G4double xStart, yStart, zStart;
    G4double pxStart, pyStart, pzStart;
    G4double eStart, kStart, tStart;
    G4double xEnd, yEnd, zEnd;
    G4double pxEnd, pyEnd, pzEnd;
    G4double eEnd, kEnd, tEnd;
    G4String preVolume, postVolume;
    G4String preProcess, postProcess;
    G4double incidentAngle;
};

#endif
