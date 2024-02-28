// std headers
#include <iostream>
#include <vector>
#include <string>

// root headers
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"

// AnalysisTree headers
#include "BranchConfig.hpp"
#include "Configuration.hpp"
#include "DataHeader.hpp"
#include "EventHeader.hpp"
#include "Detector.hpp"
#include "Matching.hpp"
#include "Track.hpp"
#include "Chain.hpp"

// additional module headers
#include "IdxConstants/IdxConstants.h"
#include "DuplicateRemover/DuplicateRemover.h"
#include "MultiplicityTool/MultiplicityTool.h"

using std::vector;
using std::string;

using namespace AnalysisTree;

using std::cout;
using std::endl;

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


	// set branch for detectors and matchings
	t.SetBranchAddress("VtxTracks2SimParticles.", &mMatchingVtx2Sim);
    t.SetBranchAddress("VtxTracks2TofHits.", &mMatchingVtx2Tof);
    t.SetBranchAddress("TofHits2SimParticles.", &mMatchingTof2Sim);
    t.SetBranchAddress("RecEventHeader.", &mRecEventHeader);  
    t.SetBranchAddress("SimEventHeader.", &mSimEventHeader);  
    t.SetBranchAddress("SimParticles.", &mSimTracks);
    t.SetBranchAddress("VtxTracks.", &mVtxTracks);  
    t.SetBranchAddress("TofHits.", &mTofHits);  

	// multiplicity tool
	const int nEv = t.GetEntries();
    cout << "[LOG] Reading tracks, there will be " << nEv << " events." << endl;
	MultiplitityTool* mMultTool = new MultiplitityTool();
	mMultTool->Init();
	mMultTool->EnableMc(true);

	// duplicated MC particle remover
	DuplicateRemover* mDupRmver = new DuplicateRemover();
	mDupRmver->Init();

	std::unique_ptr<TFile> tf(new TFile("test.root", "recreate"));
	tf->cd();

	for (auto iEv=0; iEv<nEv; iEv++) {
		t.GetEntry(iEv);
		for (auto const& McParticle : *mSimTracks) {
            int motherId = McParticle.GetField<int>(IdxSimMotherId);
            if (motherId != -1) { continue; } // not primary track
            if (mDupRmver->Make(McParticle)) { continue; }
			// int pid = McParticle.GetPid();
			// if (fabs(pid) != 2212 && fabs(pid) != 2112) { continue; }
            float McEta = McParticle.GetEta();
			float mass = McParticle.GetMass();
			lvec.SetPxPyPzE(
				McParticle.GetPx(),
				McParticle.GetPy(),
				McParticle.GetPz(),
				McParticle.GetEnergy()
			);
			lvec.Boost(0, 0, vz);
			float EtaRaw = lvec.PseudoRapidity();
			// cout << "[DEBUG]: eta " << McEta << " -> " << EtaRaw;
			// cout << " | " << McParticle.GetPx();
			// cout << " | " << McParticle.GetPy();
			// cout << " | " << McParticle.GetPz();
			// cout << " | " << McParticle.GetEnergy();
			// cout << " | " << pz << endl;
			hEta->Fill(McEta);
			hEtaRaw->Fill(EtaRaw);
		}
	}

	tf->Write();
	tf->Close();


	return 0;
}
