
#include "sdp_eventAction.hh"
#include "sdp_runAction.hh"
#include "sdp_anaTrack.hh"
#include "sdp_anaInteraction.hh"
#include "Randomize.hh"
#include "g4analysis.hh"
#include "G4RunManager.hh"
#include "G4Run.hh"
#include "G4Event.hh"
#include "G4VTrajectory.hh"
#include "G4RadioactiveDecayBaseMessenger.hh"
#include <time.h>



sdp_eventAction::sdp_eventAction(sdp_runAction* runAction)
: G4UserEventAction(),
  fRunAction(runAction)
{
  time(&startTime);
  time(&previousTime);
}
sdp_eventAction::~sdp_eventAction(){}

void sdp_eventAction::BeginOfEventAction(const G4Event* event)
{
  // Get the random seeds for this event
  fEventSeedIndex = CLHEP::HepRandom::getTheSeed();
  fEventSeed1 = CLHEP::HepRandom::getTheSeeds()[0];
  fEventSeed2 = CLHEP::HepRandom::getTheSeeds()[1];
  eNumber = event->GetEventID();

  fAnaTrack.clear();
  fAnaInteraction.clear();
}     

void sdp_eventAction::EndOfEventAction(const G4Event* event)
{
  G4bool isEventKilled = G4RunManager::GetRunManager()->GetCurrentEvent()->IsAborted();
  if(isEventKilled) return;

  // const G4Run* thisRun = G4RunManager::GetRunManager()->GetCurrentRun();
  G4int totNumber = G4RunManager::GetRunManager()->GetNumberOfEventsToBeProcessed();
  G4float perc = (eNumber/(float) totNumber)*100.;
  if((int) (perc*200000)%1000000==0)
  {
    time_t currentTime;
    time(&currentTime);
    G4double seconds = difftime(currentTime,previousTime);
    G4double totSeconds = difftime(currentTime,startTime);
    G4double secondsLeft = (totSeconds/float(perc))*(100-perc);
    G4double secondsLeft_alt = (seconds/float(5))*(100-perc);
    G4double aveLeft = (secondsLeft+secondsLeft_alt)/2.;
    printf("Processing event %i/%i [%.0f%%] | ST: %i s | PETA: %im %is / %im %is | ETA: %im %is\n",eNumber,totNumber, perc, int(seconds),
      int(floor(secondsLeft/60.)), int(secondsLeft)%60,
      int(floor(secondsLeft_alt/60.)), int(secondsLeft_alt)%60,
      int(floor(aveLeft/60.)), int(aveLeft)%60);

    previousTime = currentTime;

  }



  // printf("SUMMARY OF EVENT %i\n", (int) event->GetEventID());
  G4TrajectoryContainer* trajectoryContainer = event->GetTrajectoryContainer();
  G4int n_trajectories = 0;
  if (trajectoryContainer) n_trajectories = trajectoryContainer->entries();
  for(int i=0; i<n_trajectories; i++)
  {
    G4VTrajectory* currentTrack = (*trajectoryContainer)[i];
    // G4int tid = currentTrack->GetTrackID();
    // G4int gid = currentTrack->GetParentID();
    G4String pname = currentTrack->GetParticleName();
    // G4int pdg = currentTrack->GetPDGEncoding();
  }

  //primary positions: Alvine to Davide
  G4PrimaryVertex* pvertex=event->GetPrimaryVertex();
  G4ThreeVector vtx=pvertex->GetPosition();

  // Save metadata to the ROOT file
  auto analysisManager = G4AnalysisManager::Instance(); 
  G4int i = 0;
  analysisManager->FillNtupleIColumn(1,i,event->GetEventID()); i+=1;
  analysisManager->FillNtupleIColumn(1,i,fEventSeedIndex); i+=1;
  analysisManager->FillNtupleIColumn(1,i,fEventSeed1); i+=1;
  analysisManager->FillNtupleIColumn(1,i,fEventSeed2); i+=1;

  analysisManager->AddNtupleRow(1);


  for ( const auto &thisInteraction : fAnaInteraction )
  {
    G4int i = 0;
    G4AnalysisManager* man = G4AnalysisManager::Instance();
    man->FillNtupleIColumn(2,i,event->GetEventID()); i+=1;
    man->FillNtupleSColumn(2,i,thisInteraction.name); i+=1;
    man->FillNtupleIColumn(2,i,thisInteraction.pdg); i+=1;
    man->FillNtupleIColumn(2,i,thisInteraction.trackId); i+=1;
    man->FillNtupleIColumn(2,i,thisInteraction.parentId); i+=1;

    man->FillNtupleDColumn(2,i,thisInteraction.xStart); i+=1;
    man->FillNtupleDColumn(2,i,thisInteraction.yStart); i+=1;
    man->FillNtupleDColumn(2,i,thisInteraction.zStart); i+=1;
    man->FillNtupleDColumn(2,i,thisInteraction.tStart); i+=1;

    man->FillNtupleDColumn(2,i,thisInteraction.xEnd); i+=1;
    man->FillNtupleDColumn(2,i,thisInteraction.yEnd); i+=1;
    man->FillNtupleDColumn(2,i,thisInteraction.zEnd); i+=1;
    man->FillNtupleDColumn(2,i,thisInteraction.tEnd); i+=1;

    man->FillNtupleSColumn(2,i,thisInteraction.preVolume); i+=1;
    man->FillNtupleSColumn(2,i,thisInteraction.postVolume); i+=1;

    man->FillNtupleSColumn(2,i,thisInteraction.preProcess); i+=1;
    man->FillNtupleSColumn(2,i,thisInteraction.postProcess); i+=1;

    man->FillNtupleDColumn(2,i,thisInteraction.incidentAngle); i+=1;

    man->AddNtupleRow(2);
  }


}
