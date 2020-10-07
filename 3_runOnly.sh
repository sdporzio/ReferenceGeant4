### TUNABLE PARAMETERS
export SDP_NEVENTS=0
export SDP_RANDOMSEED=100
export SDP_VISUAL=1
export SDP_OUTDIR="/Users/sdporzio/Data/Temp"

### DERIVED PARAMETERS
export SDP_FILENAME="${SDP_HOLEOFFSET}-off_${SDP_NEVENTS}-ev_${SDP_RANDOMSEED}-s.root"

### SOURCE GEANT4 (LOC-DEPENDING)
if [ "$GAL" == "/Users/sdporzio/MOUNT/GALILEO" ]
then
  source /Users/sdporzio/Software/geant4.10.06.p01/install/bin/geant4.sh
else
  source /cvmfs/lz.opensciencegrid.org/external/Geant4/10.06.p01/x86_64-centos7-gcc8-opt/bin/geant4.sh
fi

### RUN
cd Build
./Main/sdp_main ${SDP_NEVENTS} ${SDP_RANDOMSEED} ${SDP_VISUAL} 