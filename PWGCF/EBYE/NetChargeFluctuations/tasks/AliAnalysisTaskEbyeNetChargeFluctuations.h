#ifndef AliAnalysisTaskEbyeNetChargeFluctuations_H
#define AliAnalysisTaskEbyeNetChargeFluctuations_H

class TH1F;
class TH1I;
class TH2;
class THn;
class TH1D;
class TList;
class AliAODtrack;
class AliAnalysisUtils;
class TTree;
class AliAODEvent;
class AliVEvent;
class TString;
class TObjArray;

#include "AliAnalysisTaskSE.h"
#include "AliEventCuts.h"
#include "THnSparse.h"
#include "THn.h"
#include "TTreeStream.h"


class AliAnalysisTaskEbyeNetChargeFluctuations : public AliAnalysisTaskSE
{
public:
    AliAnalysisTaskEbyeNetChargeFluctuations();
    AliAnalysisTaskEbyeNetChargeFluctuations(const char *name);
    virtual                 ~AliAnalysisTaskEbyeNetChargeFluctuations();
    
    virtual void            UserCreateOutputObjects();
    virtual void            UserExec(Option_t* option);
    virtual void            Terminate(Option_t* option);
    virtual void            doAODEvent();
    virtual void            doMCAODEvent();
    void                    SetAnalysisType(Int_t IsMC){fAnalysisType = IsMC;};
    void                    FillMCEffMatrix();            // Prepare efficiency matrix
    AliEventCuts 	        fEventCuts;                   // Event cuts
    
private:
    Bool_t ProperVertex(AliVEvent *event) const;
    Bool_t AcceptTrack(AliAODTrack* aodtrack) const;
    
    
    AliAODEvent            *fAOD;                   // input event
    TClonesArray           *fArrayMC;               // array of MC particles
    TTree                  *fTree;                  // Tree for real Data
    TTree                  *fTreeMCrec;             // Tree for MC rec
    TTree                  *fTreeMCallrec;          // Tree for MC rec
    TTree                  *fTreeMCgen;             // Tree for MC gen
    TTree                  *fTreeMCallgen;          // Tree for MC gen
    TTree                  *fTreeTrackCuts;
    TTree                  *fTreeMCTrackCuts;
    TTreeSRedirector       *fTreeSRedirector;       // temp tree to dump output
    
    Int_t                   fAnalysisType;          // "MC",  "AOD"
    TH1F                   *fhCent;                 // helper histogram for centrality
    TH1D                   *fHistCentralityMultSelection; // centrality class selection by AliMultSelection

    TList                  *fOutputList;            // output list
    Float_t                 fEta;                   // pseudo rapidity
    Float_t                 fpT;                    // transverse momentum
    Float_t                 fPhi;
    Short_t                 fCharge;                // charge information
    Float_t                 fEtaMCall;              // pseudo rapidity
    Float_t                 fpTMCall;               // transverse momentum
    Float_t                 fPhiMCall;
    Short_t                 fChargeMCall;           // charge information
    Float_t                 fCentrality;            // centrality information
    Int_t                   fPos;                   // positive charged particles
    Int_t                   fNeg;                   // negative charged particles
    Int_t                   fMomentsCross;          // moment of positive and negative charged particles
    Int_t                   fMomentsPos;            // moment of positive charged particles
    Int_t                   fMomentsNeg;            // moment of negative charged particles
    Int_t                   EventNumber;
    
    Float_t                 fEtaMCgen;              // MC gen pseudo rapidity
    Float_t                 fpTMCgen;               // MC gen transverse momentum
    Float_t                 fPhiMCgen;
    Short_t                 fChargegen;             // charge information
    Float_t                 fEtaMCallgen;           // MC gen pseudo rapidity
    Float_t                 fpTMCallgen;            // MC gen transverse momentum
    Float_t                 fPhiMCallgen;
    Short_t                 fChargeMCallgen;        // charge information    
 //   Float_t                 fEtaMC;               // MC rec pseudo rapidity
 //   Float_t                 fpTMC;                // MC rec transverse momentum
    Double_t                fVxMax;                 // vxmax
    Double_t                fVyMax;                 // vymax
    Double_t                fVzMax;                 // vzmax
    
    Int_t                   fRunNumber;
    Int_t                   genPos;                 // MC gen positive charged particles
    Int_t                   genNeg;                 // MC gen negative charged particles
    Int_t                   genNch;                 // MC gen negative charged particles
    Int_t                   genMomentsCross;        // MC gen moment of positive and negative charged particles
    Int_t                   genMomentsPos;          // MC gen moment of positive charged particles
    Int_t                   genMomentsNeg;          // MC gen moment of negative charged particles
    
    Int_t                   recPos;                 // MC rec positive charged particles
    Int_t                   recNeg;                 // MC rec negative charged particles
    Int_t                   recNch;                 // MC rec total charged particles
    Int_t                   Nch;
    Int_t                   recMomentsCross;        // MC rec moment of positive and negative charged particles
    Int_t                   recMomentsPos;          // MC rec moment of positive charged particles
    Int_t                   recMomentsNeg;          // MC rec moment of negative charged particles
    
    Int_t                   allrecPos;              // MC all rec positive charged particles
    Int_t                   allrecNeg;              // MC all rec negative charged particles
    Int_t                   allrecNch;              // MC all rec total charged particles
    Int_t                   allrecMomentsCross;     // MC all rec moment of pos and neg charged particles
    Int_t                   allrecMomentsPos;       // MC all rec moment of positive charged particles
    Int_t                   allrecMomentsNeg;       // MC all rec moment of negative charged particles
    
    Int_t                   allgenPos;              // MC all gen positive charged particles
    Int_t                   allgenNeg;              // MC all gen negative charged particles
    Int_t                   allgenNch;              // MC all rec total charged particles

    Int_t                   allgenMomentsCross;     // MC all gen moment of positive and negative charged particles
    Int_t                   allgenMomentsPos;       // MC all gen moment of positive charged particles
    Int_t                   allgenMomentsNeg;       // MC all gen moment of negative charged particles
    
    Int_t                   pdg;
    Int_t                   pdgMom;
    Int_t                   pdgMomPhysicalPrim;
    Int_t                   pdgMomPrim ;
    Int_t                   pdgPhysicalPrim ;
    Int_t                   pdgPrim ;
    
    Int_t                   allpdg;
    Int_t                   allpdgMom;
    Int_t                   allpdgMomPhysicalPrim;
    Int_t                   allpdgMomPrim ;
    Int_t                   allpdgPhysicalPrim ;
    Int_t                   allpdgPrim ;
    
    Int_t                   pdggen;
    Int_t                   pdgMomgen;
    Int_t                   pdgMomPhysicalPrimgen;
    Int_t                   pdgMomPrimgen;
    Int_t                   pdgPhysicalPrimgen ;
    Int_t                   pdgPrimgen;
    
    Int_t                   allpdggen;
    Int_t                   allpdgMomgen;
    Int_t                   allpdgMomPhysicalPrimgen;
    Int_t                   allpdgMomPrimgen;
    Int_t                   allpdgPhysicalPrimgen ;
    Int_t                   allpdgPrimgen;
    
    Double_t                fEtaDown;
    Double_t                fEtaUp;
    
    // control and QA histograms
    //
    THnF                    *fHistPosEffMatrixRec;     // histogram efficiency matrix --> reconstructed traks
    THnF                    *fHistNegEffMatrixRec;     // histogram efficiency matrix --> generated traks
    THnF                    *fHistPosEffMatrixGen;     // histogram efficiency matrix --> reconstructed pions
    THnF                    *fHistNegEffMatrixGen;     // histogram efficiency matrix --> generated pions
    
    TH1I                    *fHistVertexNconributors;  // vertex contributors number
    TH1I                    *fHistVertexStats;         // Vertex reconstruction statistics
    TH1D                    *fHistVx;                  // Vx hist
    TH1D                    *fHistVy;                  // Vy hist
    TH1D                    *fHistVz;                  // Vz hist
    
    TH2F                    *fHistZVertexCent;
    TH1I                    *fEventStatistics;         // cut-by-cut counter of events
    TH1D                    *fHistClustersTPC;
    TH1D                    *fHistChi2perNDF;
    TH1F                    *hGenPt;
    TH1F                    *hGenPhi;
    TH1F                    *hGenEta;
    TH1F                    *hTrackPt;
    TH1F                    *hTrackPhi;
    TH1F                    *hTrackEta;
    TH1F                    *hTrackPtallrec;
    TH1F                    *hTrackPhiallrec;
    TH1F                    *hTrackEtaallrec;
    
    AliAnalysisTaskEbyeNetChargeFluctuations(const AliAnalysisTaskEbyeNetChargeFluctuations&);
    AliAnalysisTaskEbyeNetChargeFluctuations& operator=(const AliAnalysisTaskEbyeNetChargeFluctuations&);
    ClassDef(AliAnalysisTaskEbyeNetChargeFluctuations, 1);
};


#endif
