#ifndef sdp_actionInitialization_h
#define sdp_actionInitialization_h 1
#include "G4VUserActionInitialization.hh"

class sdp_actionInitialization : public G4VUserActionInitialization
{
  public:
    sdp_actionInitialization();
    virtual ~sdp_actionInitialization();
    virtual void Build() const;
  };

#endif