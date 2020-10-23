### TUNABLE PARAMETERS
export SDP_PROJECTNAME="incidentAngleTest"
export SDP_NEVENTS=5
export SDP_RANDOMSEED=100
export SDP_VISUAL=1
export SDP_OUTDIR="/Users/sdporzio/Data/Temp"

### DERIVED PARAMETERS
export SDP_FILENAME="${SDP_PROJECTNAME}_${SDP_NEVENTS}-ev_${SDP_RANDOMSEED}-s.root"

### SOURCE GEANT4 (LOC-DEPENDING)
if [ "$GAL" == "/Users/sdporzio/MOUNT/GALILEO" ]
then
  source /Users/sdporzio/Software/geant4.10.06.p01/install/bin/geant4.sh
else
  source /cvmfs/lz.opensciencegrid.org/external/Geant4/10.06.p01/x86_64-centos7-gcc8-opt/bin/geant4.sh
fi

### COMPILE AND RUN
# rm -rf Build/*
cd Build
cmake ../
make -j 4 && ./Main/sdp_main ${SDP_NEVENTS} ${SDP_RANDOMSEED} ${SDP_VISUAL} 
