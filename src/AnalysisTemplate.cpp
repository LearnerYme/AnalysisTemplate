#include <iostream>
#include <vector>
#include <string>

#include "BranchConfig.hpp"
#include "Configuration.hpp"
#include "Constants.hpp"
#include "Container.hpp"
#include "DataHeader.hpp"
#include "Detector.hpp"
#include "EventHeader.hpp"
#include "Hit.hpp"
#include "IndexedObject.hpp"
#include "Matching.hpp"
#include "Module.hpp"
#include "Particle.hpp"
#include "Track.hpp"
#include "Chain.hpp"

#include "IdxConstants.h"

using namespace AnalysisTree;
using std::vector;
using std::string;

// main

int main(int argc, char** argv) {

	Chain t(
		vector<string>({"file.list"}),
		vector<string>({"rTree"})
	);
	float BeamRapidity = 1.62179;

	Configuration* cfg = t.GetConfiguration();

	// 
    EventHeader* mSimEventHeader = new EventHeader();
    EventHeader* mRecEventHeader = new EventHeader();
    Particles* mSimTracks = new Particles();
    HitDetector* mTofHits = new HitDetector();
    TrackDetector* mVtxTracks = new TrackDetector();

	// mathing between detectors
	Matching* mMatchingVtx2Sim = new Matching();
    Matching* mMatchingVtx2Tof = new Matching();
    Matching* mMatchingTof2Sim = new Matching();

	// for quick test
	t.Print("");

	return 0;
}
