/*
    Index of branches and channels for analysis tree.
    Author: Yige Huang
    Date: 21.04.2024
    Version: v1.0
    Current analysis tree version: v2.3.2 (for CBM analysis)
    No guarantee for higher or lower patch!!!
*/

// Note: this alias is called Indey instead of Index
using Indey_t=int;

#define __VTXTRACK_IDX__
#define __TOFHIT_IDX__
#define __SIMPARTICLE_IDX__
#define __MCEVENT_IDX__
#define __RECEVENT_IDX__

// VtxTracks
#ifdef __VTXTRACK_IDX__
    // float
    extern const Indey_t IdxVtxChi2;
    extern const Indey_t IdxVtxDcax;
    extern const Indey_t IdxVtxDcay;
    extern const Indey_t IdxVtxDcaz;
    extern const Indey_t IdxVtxEta; // pseudorapidity
    extern const Indey_t IdxVtxP;
    extern const Indey_t IdxVtxPt;
    extern const Indey_t IdxVtxPx;
    extern const Indey_t IdxVtxPy;
    extern const Indey_t IdxVtxPz;
    extern const Indey_t IdxVtxPhi; // azimuthal angle 
    extern const Indey_t IdxVtxVtxChi2; // chi2 to primary vertex

    // integer
    extern const Indey_t IdxVtxNdf;
    extern const Indey_t IdxVtxNhits; // number of hits (total MVD+STS)
    extern const Indey_t IdxVtxCharge;

    // init
    constexpr Indey_t IdxVtxChi2 = 0;
    constexpr Indey_t IdxVtxDcax = 2;
    constexpr Indey_t IdxVtxDcay = 3;
    constexpr Indey_t IdxVtxDcaz = 4;
    constexpr Indey_t IdxVtxEta = -3; 
    constexpr Indey_t IdxVtxP = -7;
    constexpr Indey_t IdxVtxPt = -2;
    constexpr Indey_t IdxVtxPx = -4;
    constexpr Indey_t IdxVtxPy = -5;
    constexpr Indey_t IdxVtxPz = -6;
    constexpr Indey_t IdxVtxPhi = -1;
    constexpr Indey_t IdxVtxVtxChi2 = 1;  
    constexpr Indey_t IdxVtxNdf = 0;
    constexpr Indey_t IdxVtxNhits = 2; // number of hits (total MVD+STS)
    constexpr Indey_t IdxVtxCharge = 1;
#endif

// TofHits
#ifdef __TOFHIT_IDX__
    // float
    extern const Indey_t IdxTofDx;
    extern const Indey_t IdxTofDy;
    extern const Indey_t IdxTofDz;
    extern const Indey_t IdxTofL; // track length
    extern const Indey_t IdxTofMass2; // mass square
    extern const Indey_t IdxTofPhi;
    extern const Indey_t IdxTofRigi; // p * q, this maybe in lab frame, not cm frame

    // init
    constexpr Indey_t IdxTofDx = 4;
    constexpr Indey_t IdxTofDy = 5;
    constexpr Indey_t IdxTofDz = 6;
    constexpr Indey_t IdxTofL = 1;
    constexpr Indey_t IdxTofMass2 = 0;
    constexpr Indey_t IdxTofPhi = -1;
    constexpr Indey_t IdxTofRigi = 3;
#endif

// SimParticles
#ifdef __SIMPARTICLE_IDX__
    // float
    extern const Indey_t IdxSimEta;
    extern const Indey_t IdxSimP;
    extern const Indey_t IdxSimPt;
    extern const Indey_t IdxSimPx;
    extern const Indey_t IdxSimPy;
    extern const Indey_t IdxSimPz;
    extern const Indey_t IdxSimPhi;
    extern const Indey_t IdxSimRap; // rapidity (lab frame)

    // integer
    extern const Indey_t IdxSimMotherId; // -1 for primary
    extern const Indey_t IdxSimPdgId;

    // init
    constexpr Indey_t IdxSimEta = -6;
    constexpr Indey_t IdxSimP = -10;
    constexpr Indey_t IdxSimPt = -2;
    constexpr Indey_t IdxSimPx = -7;
    constexpr Indey_t IdxSimPy = -8;
    constexpr Indey_t IdxSimPz = -9;
    constexpr Indey_t IdxSimPhi = -1;
    constexpr Indey_t IdxSimRap = -3;
    constexpr Indey_t IdxSimMotherId = 0;
    constexpr Indey_t IdxSimPdgId = -4;
#endif

// McEvent
#ifdef __MCEVENT_IDX__
    // float
    extern const Indey_t IdxMcB;
    extern const Indey_t IdxMcVx;
    extern const Indey_t IdxMcVy;
    extern const Indey_t IdxMcVz;

    // init
    constexpr Indey_t IdxMcB = 1;
    constexpr Indey_t IdxMcVx = -1;
    constexpr Indey_t IdxMcVy = -2;
    constexpr Indey_t IdxMcVz = -3;
#endif

// RecEvent
#ifdef __RECEVENT_IDX__
    // float
    extern const Indey_t IdxRecVtxChi2;
    extern const Indey_t IdxRecVx;
    extern const Indey_t IdxRecVy;
    extern const Indey_t IdxRecVz;

    // integer
    extern const Indey_t IdxRecMult; // total multiplicity in STS+MVD

    // init
    constexpr Indey_t IdxRecVtxChi2 = 0;
    constexpr Indey_t IdxRecVx = -1;
    constexpr Indey_t IdxRecVy = -2;
    constexpr Indey_t IdxRecVz = -3;
    constexpr Indey_t IdxRecMult = 0;
#endif
