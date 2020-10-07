// G4 INCLUDES
#include "G4RunManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "QBBC.hh"
#include "Randomize.hh"
// PROJECTS INCLUDE
#include "sdp_detectorConstruction.hh"
#include "sdp_physicsList.hh"
#include "sdp_actionInitialization.hh"


// MAIN FUNCTION
int main(int argc,char** argv)
{
  // DEFAULT SETTINGS
  G4int nEvents = 1;
  G4int visual = 0;
  G4int seed = 111;
  // INLINE OVERRIDES
  if(argc>1) nEvents = std::stoi(argv[1]);
  if(argc>2) seed = std::stoi(argv[2]);
  if(argc>3) visual = std::stoi(argv[3]);

  // SET RANDOM SEED
  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine());
  CLHEP::HepRandom::setTheSeed(seed);

  // INITIALIZE THE UI CLASS
  G4UIExecutive* ui = 0;
  ui = new G4UIExecutive(argc, argv);

  // DEFAULT RUN MANAGER INITIALIZATION
  G4RunManager* runManager = new G4RunManager;

  // MANDATORY USER INITIALIZATION CLASSES
  // Detector class
  sdp_detectorConstruction* myDetector = new sdp_detectorConstruction();
  runManager->SetUserInitialization(myDetector);
  // Physics list class
  G4VModularPhysicsList* myPhysicsList = new QBBC;
  // G4VModularPhysicsList* myPhysicsList = new sdp_physicsList();
  myPhysicsList->SetVerboseLevel(1);
  runManager->SetUserInitialization(myPhysicsList);
  // Action class
  sdp_actionInitialization* myAction = new sdp_actionInitialization();
  runManager->SetUserInitialization(myAction);

  // OPTIONAL CLASSES
  // Visualization class
  G4VisManager* visManager = new G4VisExecutive;
  // UI class
  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  UImanager->ApplyCommand("/control/execute Macros/initialize.mac");

  // RUN TIME FOR VISUAL
  if(visual)
  {
    visManager->Initialize();
    UImanager->ApplyCommand("/control/execute Macros/initialize_vis.mac");
    UImanager->ApplyCommand("/run/beamOn "+std::to_string(nEvents));
    ui->SessionStart();
  }
  // BATCH RUN
  if(!visual)
  {
    runManager->Initialize();
    runManager->BeamOn(nEvents); 
  }

  delete ui;
  delete runManager;
  delete visManager;


}