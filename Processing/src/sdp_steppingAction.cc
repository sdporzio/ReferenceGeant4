#include "sdp_steppingAction.hh"
#include "sdp_eventAction.hh"
#include "sdp_detectorConstruction.hh"
#include "sdp_anaTrack.hh"
#include "sdp_anaInteraction.hh"
#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4StepPoint.hh"
#include "globals.hh"
#include "G4SystemOfUnits.hh"


sdp_steppingAction::sdp_steppingAction(sdp_eventAction* eventAction)
: G4UserSteppingAction(),
  fEventAction(eventAction)
{}

sdp_steppingAction::~sdp_steppingAction()
{}

void sdp_steppingAction::UserSteppingAction(const G4Step* step)
{
  // Get the track associated with the step
  G4Track* track = step->GetTrack();
  G4int track_id = track->GetTrackID();
  G4int parent_id = track->GetParentID();
  G4String particle_name = track->GetParticleDefinition()->GetParticleName();
  // Take also prepoint and postpoint for good measure
  G4StepPoint* prepoint = step->GetPreStepPoint();
  G4StepPoint* postpoint = step->GetPostStepPoint();

  // Check if both start and end volumes are defined
  bool bothVolumesDefined = ( (prepoint->GetTouchableHandle()->GetVolume()) && (postpoint->GetTouchableHandle()->GetVolume()) );
   // Let's do this though, only if we don't risk crashing BACCARAT
  if (bothVolumesDefined)
  {
    // Ok, good to go, now let's check where we are in the geometry and if we're touching a wire
    std::string preVolume = prepoint->GetTouchableHandle()->GetVolume()->GetName();
    std::string postVolume = postpoint->GetTouchableHandle()->GetVolume()->GetName();
    std::string wireString = "Tube";
    bool wireNotInPre = !(preVolume.find(wireString) != std::string::npos);
    bool wireInPost = (postVolume.find(wireString) != std::string::npos);
    bool interactionIsToBeRecorded = (wireNotInPre && wireInPost);
    // If that's the case, we're in business, let's store info about this event
    if (interactionIsToBeRecorded)
    {
      sdp_anaInteraction thisInteraction;
      thisInteraction.trackId = track_id;
      thisInteraction.parentId = parent_id;
      thisInteraction.name = track->GetParticleDefinition()->GetParticleName();
      thisInteraction.pdg = track->GetParticleDefinition()->GetPDGEncoding();
      thisInteraction.parentId = track->GetParentID();

      if(!(prepoint->GetTouchableHandle()->GetVolume())) thisInteraction.preVolume = std::string("Unknown");
      else thisInteraction.preVolume = prepoint->GetTouchableHandle()->GetVolume()->GetName();

      if(!(postpoint->GetTouchableHandle()->GetVolume())) thisInteraction.postVolume = std::string("Unknown");
      else thisInteraction.postVolume = postpoint->GetTouchableHandle()->GetVolume()->GetName();

      if(!(prepoint->GetProcessDefinedStep())) thisInteraction.preProcess = std::string("Unknown");
      else thisInteraction.preProcess = prepoint->GetProcessDefinedStep()->GetProcessName();

      if(!(postpoint->GetProcessDefinedStep())) thisInteraction.postProcess = std::string("Unknown");
      else thisInteraction.postProcess = postpoint->GetProcessDefinedStep()->GetProcessName();  

      thisInteraction.xStart = prepoint->GetPosition()[0]/CLHEP::cm;
      thisInteraction.yStart = prepoint->GetPosition()[1]/CLHEP::cm;
      thisInteraction.zStart = prepoint->GetPosition()[2]/CLHEP::cm;
      thisInteraction.tStart = prepoint->GetLocalTime()/CLHEP::ns;
      thisInteraction.xEnd = postpoint->GetPosition()[0]/CLHEP::cm;
      thisInteraction.yEnd = postpoint->GetPosition()[1]/CLHEP::cm;
      thisInteraction.zEnd = postpoint->GetPosition()[2]/CLHEP::cm;
      thisInteraction.tEnd = postpoint->GetLocalTime()/CLHEP::ns;


      // MACRO TAKING CARE OF INCIDENCE ANGLE
      bool areVolumesDifferent = (preVolume!=postVolume);
      bool isTherePostVolume = (postpoint->GetPhysicalVolume());
      bool isTherePostSolid = (postpoint->GetTouchableHandle()->GetSolid());

      if(areVolumesDifferent & isTherePostSolid & isTherePostVolume)
      {
        // Get contact point in both reference system
        printf("EVENT %i\n", fEventAction->eNumber);
        double theta, phi;

        G4ThreeVector contactPoint_world = postpoint->GetPosition();
        printf("|_Contact coordinates (world): [%.1f,%.1f,%.1f]\n",contactPoint_world[0]/mm,contactPoint_world[1]/mm,contactPoint_world[2]/mm);

        G4ThreeVector contactPoint_local =  postpoint->GetTouchableHandle()->GetHistory()->GetTopTransform().TransformPoint(contactPoint_world);
        printf("|_Contact coordinates (local): [%.1f,%.1f,%.1f]\n",contactPoint_local[0]/mm,contactPoint_local[1]/mm,contactPoint_local[2]/mm);


        // Get the normal to the surface in that point (using local, and multiplying by -1 because we want the vector going towards the INSIDE the volume), and the momentum direction of the postpoint.
        G4ThreeVector norm_local = -1*postpoint->GetTouchableHandle()->GetSolid()->SurfaceNormal(contactPoint_local);
        norm_local = norm_local/norm_local.mag();
        theta = atan(sqrt(pow(norm_local[2],2.) + pow(norm_local[1],2.))/norm_local[0])*180./M_PI;
        phi = atan(norm_local[1]/norm_local[2])*180./M_PI;
        printf("|_Normal vector to surface (local): [%.1f,%.1f,%.1f] (%.1f,%.1f)\n",norm_local[0]/mm,norm_local[1]/mm,norm_local[2]/mm,norm_local.theta()*180./M_PI,norm_local.phi()*180./M_PI);

        // Or convert the direction of the normal to the surface in the world coordinates
        G4ThreeVector norm_world = (postpoint->GetTouchableHandle()->GetHistory()->GetTopTransform().Inverse().NetRotation())*norm_local;
        norm_world = norm_world/norm_world.mag();
        theta = atan(sqrt(pow(norm_world[2],2.) + pow(norm_world[1],2.))/norm_world[0])*180./M_PI;
        phi = atan(norm_world[1]/norm_world[2])*180./M_PI;
        printf("|_Normal vector to surface (world): [%.1f,%.1f,%.1f] (%.1f,%.1f)\n",norm_world[0]/mm,norm_world[1]/mm,norm_world[2]/mm,norm_world.theta()*180./M_PI,norm_world.phi()*180./M_PI);



        G4ThreeVector dir_world = postpoint->GetMomentumDirection();
        printf("|_Photon vector (world): [%.1f,%.1f,%.1f]\n",dir_world[0]/mm,dir_world[1]/mm,dir_world[2]/mm);
        dir_world = dir_world/dir_world.mag();

        // Convert the direction of the particle momentum in the local solid coordinates  (by rotating accordingly)
        G4ThreeVector dir_local = (postpoint->GetTouchableHandle()->GetHistory()->GetTopTransform().Inverse().NetRotation())*dir_world;
        dir_local = dir_local/dir_local.mag();
        printf("|_Photon vector (local): [%.1f,%.1f,%.1f]\n",dir_local[0]/mm,dir_local[1]/mm,dir_local[2]/mm);


        // Calculate angle between vectors
        G4double incidentAngle = acos(norm_local * dir_local)*180./M_PI;
        thisInteraction.incidentAngle = incidentAngle;
        // printf("|_Incident angle: %.1f rad.\n", acos(norm_local * dir_local));
        printf("|_Incident angle: %.1f degrees.\n\n", incidentAngle);
      }
      else thisInteraction.incidentAngle = -999.;

      
      fEventAction->fAnaInteraction.push_back(thisInteraction);
    }
  }


}
