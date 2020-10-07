#ifndef sdp_anaTrack_h
#define sdp_anaTrack_h 1

#include "globals.hh"


class sdp_anaTrack
{
  public:
    sdp_anaTrack();
    virtual ~sdp_anaTrack();

    G4String name;
    G4int pdg;
    G4int trackId;
    G4int parentId;
    G4double xStart, yStart, zStart;
    G4double pxStart, pyStart, pzStart;
    G4double eStart, kStart, tStart;
    G4double xEnd, yEnd, zEnd;
    G4double pxEnd, pyEnd, pzEnd;
    G4double eEnd, kEnd, tEnd;
    G4String volumeStart, volumeEnd;
    G4double distTravelled;
    G4double enDeposited_tot;
    G4bool enteredHole, enteredCollection, exitedCollection;
};

#endif
