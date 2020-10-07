#ifndef sdp_physicsList_h
#define sdp_physicsList_h 1

#include "G4VModularPhysicsList.hh"

class sdp_physicsList: public G4VModularPhysicsList
{
public:
  sdp_physicsList();
  virtual ~sdp_physicsList();

  virtual void SetCuts();
};


#endif