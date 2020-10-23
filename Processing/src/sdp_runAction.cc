#include "sdp_runAction.hh"
#include "sdp_detectorConstruction.hh"
#include "G4GenericMessenger.hh"
#include "G4RunManager.hh"
#include "g4analysis.hh"


sdp_runAction::sdp_runAction() : G4UserRunAction()
{

  // Create the root manager
  auto analysisManager = G4Analysis::ManagerInstance("root");
  G4cout << "Using " << analysisManager->GetType() << G4endl;
  G4cout << "Using " << analysisManager->GetFileName() << G4endl;


  // Default settings
  analysisManager->SetNtupleMerging(true);
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetFileName("ptfe");

  // Create the metadata branch
  analysisManager->CreateNtuple("metadata", "Metadata");              //ntuple-ID 0
  analysisManager->CreateNtupleIColumn("seed_run");
  analysisManager->FinishNtuple();

  // Create the data branch
  analysisManager->CreateNtuple("event_data", "EventData");             //ntuple-ID 1
  analysisManager->CreateNtupleIColumn("event_number");
  analysisManager->CreateNtupleIColumn("seed_event_index");
  analysisManager->CreateNtupleIColumn("seed_event1");
  analysisManager->CreateNtupleIColumn("seed_event2");

  // Create the interaction branch
  analysisManager->CreateNtuple("interaction_data", "InteractionData");             //ntuple-ID 2
  analysisManager->CreateNtupleIColumn("event_number");
  analysisManager->CreateNtupleSColumn("particle_name");
  analysisManager->CreateNtupleIColumn("particle_pdg");
  analysisManager->CreateNtupleIColumn("tracks_id");
  analysisManager->CreateNtupleIColumn("parent_id");
 
  // Coordinates start
  analysisManager->CreateNtupleDColumn("xStart");
  analysisManager->CreateNtupleDColumn("yStart");
  analysisManager->CreateNtupleDColumn("zStart");
  analysisManager->CreateNtupleDColumn("tStart");
  // Coordinates end
  analysisManager->CreateNtupleDColumn("xEnd");
  analysisManager->CreateNtupleDColumn("yEnd");
  analysisManager->CreateNtupleDColumn("zEnd");
  analysisManager->CreateNtupleDColumn("tEnd");

  // Volume information
  analysisManager->CreateNtupleSColumn("preVolume");
  analysisManager->CreateNtupleSColumn("postVolume");

  // Process information
  analysisManager->CreateNtupleSColumn("preProcess");
  analysisManager->CreateNtupleSColumn("postProcess");

  // Angle status
  analysisManager->CreateNtupleDColumn("incidentAngle");

  analysisManager->FinishNtuple();
}

sdp_runAction::~sdp_runAction()
{}

void sdp_runAction::BeginOfRunAction(const G4Run*)
{
  // Create ROOT file
  auto analysisManager = G4AnalysisManager::Instance();
  analysisManager->OpenFile();
}     

void sdp_runAction::EndOfRunAction(const G4Run* run)
{
  // Get the detector (for metadata purposes)
  const sdp_detectorConstruction* myDetector
      = static_cast<const sdp_detectorConstruction*>
        (G4RunManager::GetRunManager()->GetUserDetectorConstruction());

  // Save metadata to the ROOT file
  auto analysisManager = G4AnalysisManager::Instance(); G4int i = 0;
  analysisManager->FillNtupleIColumn(0,i,CLHEP::HepRandom::getTheSeed()); i+=1;
  analysisManager->AddNtupleRow(0);
  analysisManager->Write();
  analysisManager->CloseFile();
}