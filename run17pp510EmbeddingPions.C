#include <iostream>
#include <vector>
#include "TFile.h"
#include "TNtuple.h"
#include "TTree.h"
#include "TH1.h"
#include "TH2.h"

//#include "StEvent/StEvent.h"
class StMuDstMaker;
class StMuDebug;
class StSpinDbMaker;
class StChain;
class StMaker;
class StMuMcTrack;
class StMuMcVertex;
StMuDstMaker *maker;

void run17pp510EmbeddingPions(const char *muFile, const char *geFile, const char *oFile) // grid mode
// void run17pp510EmbeddingPions(const char* muFile="/star/u/nghimire/GPFS/Embed_Run17/embedding/pp500_production_2017/Pythia6_pt7_9_100_20201502/P20ic.SL20c/2017/080/18080051/st_zerobias_adc_18080051_raw_2500011.MuDst.root",const char* geFile="/star/u/nghimire/GPFS/Embed_Run17/embedding/pp500_production_2017/Pythia6_pt7_9_100_20201502/P20ic.SL20c/2017/080/18080051/st_zerobias_adc_18080051_raw_2500011.geant.root", const char* oFile="test.root") //interactive mode
// void run17pp510EmbeddingPions(const char* muFile="/star/u/nghimire/GPFS/Embed_Run17/embedding/pp500_production_2017/Pythia6_pt15_20_100_20201502/P20ic.SL20c/2017/079/18079030/st_zerobias_adc_18079030_raw_0000009.MuDst.root",const char* geFile="/star/u/nghimire/GPFS/Embed_Run17/embedding/pp500_production_2017/Pythia6_pt15_20_100_20201502/P20ic.SL20c/2017/079/18079030/st_zerobias_adc_18079030_raw_0000009.geant.root", const char* oFile="test.root") //interactive mode
{

    gROOT->LoadMacro("$STAR/StRoot/StMuDSTMaker/COMMON/macros/loadSharedLibraries.C");
    gROOT->Macro("loadMuDst.C");
    loadSharedLibraries();

    gSystem->Load("StEvent");

    gSystem->Load("StSpinDbMaker");
    gSystem->Load("StDbBroker");
    gSystem->Load("St_db_Maker");
    gSystem->Load("StMcEvent");
    gSystem->Load("StMcEventMaker");
    gSystem->Load("StEEmcUtil");
    gSystem->Load("StJetSkimEvent");
    gSystem->Load("StMCAsymMaker");
    gSystem->Load("StTriggerUtilities");
    // included for MC information
    // gSystem->Load("StMuMcTrack");
    // gSystem->Load("StMuMcVertex");
    //////////////////////////////
    gSystem->Load("StDetectorDbMaker");
    gSystem->Load("StTpcDb");
    gSystem->Load("StDbUtilities");
    gSystem->Load("StMcEvent");
    gSystem->Load("StMcEventMaker");
    gSystem->Load("StDaqLib");
    gSystem->Load("StEmcRawMaker");
    gSystem->Load("StEmcADCtoEMaker");
    gSystem->Load("StEpcMaker");
    gSystem->Load("StEmcSimulatorMaker");
    gSystem->Load("StDbBroker");
    gSystem->Load("St_db_Maker");
    gSystem->Load("StEEmcUtil");
    gSystem->Load("StEEmcDbMaker");
    gSystem->Load("StSpinDbMaker");
    gSystem->Load("StEmcTriggerMaker");
    // gSystem->Load("StMCAsymMaker");
    gSystem->Load("StRandomSelector");
    gSystem->Load("libfastjet.so");
    gSystem->Load("libsiscone.so");
    gSystem->Load("libsiscone_spherical.so");
    gSystem->Load("libfastjetplugins.so");
    gSystem->Load("StJetFinder");
    gSystem->Load("StJetSkimEvent");
    gSystem->Load("StJets");
    gSystem->Load("StJetEvent");
    // gSystem->Load("StPythiaEvent");
    // gSystem->Load("StJetMaker");
    gSystem->Load("StTriggerFilterMaker");
    // gSystem->Load("StEEmcA2EMaker");

    gROOT->ProcessLine("#include <map>");
    gROOT->Macro("$STAR/StRoot/StMuDSTMaker/COMMON/macros/loadSharedLibraries.C");
    gROOT->Macro("LoadLogger.C"); // not quite sure what this does or where it is.
    cout << " loading done " << endl;

    const int fMaxHit = 3000;
    Int_t ffillNum;
    Int_t frunId;
    Int_t fevtNum;
    unsigned int fevTime;
    Double_t fvpdVz;
    Int_t frunNum;
    Int_t fspinBits;
    Int_t fspinconfig;
    Int_t frefmult;
    vector<int> ftrigger; 
    Int_t fmaxpar1;
    Int_t fmaxpar;

    Double_t fVZ;
    Double_t fVZ_pyth;
    Double_t fVY_pyth;
    Double_t fVX_pyth;
    Double_t fverRank;

    Int_t fTrackCounter1;
    Int_t fTrackCounter;
    Int_t bPartonId;
    Double_t bPartonx;
    Double_t bPartonE;
    Double_t bPartonP;
    Double_t bPartonPhi;
    Double_t bPartonEta;
    Double_t bPartonPt;
    Int_t yPartonId;
    Double_t yPartonx;
    Double_t yPartonE;
    Double_t yPartonP;
    Double_t yPartonPhi;
    Double_t yPartonEta;
    Double_t yPartonPt;
    Int_t fparton1Id;
    Double_t fparton1Eta;
    Double_t fparton1Phi;
    Double_t fparton1Pt;
    Double_t fparton1xBj;
    Double_t fparton1E;
    Int_t fparton2Id;
    Double_t fparton2Eta;
    Double_t fparton2Phi;
    Double_t fparton2Pt;
    Double_t fparton2xBj;
    Double_t fparton2E;
    Double_t partonicPtBin;
    Double_t fpT[fMaxHit];
    Double_t fp[fMaxHit];
    Double_t feta[fMaxHit];
    Double_t fphi[fMaxHit];
    Double_t fpT_pyth[fMaxHit];
    Double_t fp_pyth[fMaxHit];
    Double_t feta_pyth[fMaxHit];
    Double_t fphi_pyth[fMaxHit];
    Double_t fpId_pyth[fMaxHit];
    Double_t fnSigmaPion[fMaxHit];
    Double_t fnSigmaKaon[fMaxHit];
    Double_t fnSigmaProton[fMaxHit];
    Double_t fnSigmaElectron[fMaxHit];
    Short_t fcharge[fMaxHit];
    Double_t fdEdx[fMaxHit];
    Double_t fdca[fMaxHit];
    UShort_t ffitPts[fMaxHit];
    UShort_t ffitPtsPoss[fMaxHit];
    UShort_t fhitsdedx[fMaxHit];
    Double_t fPathLengthToF[fMaxHit];
    Double_t fBetaToF[fMaxHit];
    Int_t trueID[fMaxHit];

    TVector3 mcVertex;

    // Tower Information
    double fTowerEng;
    double fTowerEta;
    double fTowerPhi;

    TFile *fout = new TFile(oFile, "recreate");
    TTree *ftree = new TTree("ftree", "dihadron ");
    ftree->Branch("fevtNum", &fevtNum, "fevtNum/I");
    ftree->Branch("ffillNum", &ffillNum, "ffillNum/I");
    ftree->Branch("frunId", &frunId, "frunId/I");
    ftree->Branch("frunNum", &frunNum, "frunNum/I");
    ftree->Branch("fspinBits", &fspinBits, "fspinBits/I");
    ftree->Branch("fspinconfig", &fspinconfig, "fspinconfig/I");
    ftree->Branch("frefmult", &frefmult, "frefmult/I");
    // ftree->Branch("ftrigger",&ftrigger, "ftrigger/I");
    ftree->Branch("ftrigger", &ftrigger);
    
    ftree->Branch("fmaxpar1", &fmaxpar1, "fmaxpar1/I");
    ftree->Branch("fmaxpar", &fmaxpar, "fmaxpar/I");

    ftree->Branch("fVZ", &fVZ, "fVZ/D");
    ftree->Branch("fVZ_pyth", &fVZ_pyth, "fVZ_pyth/D");
    ftree->Branch("fVY_pyth", &fVY_pyth, "fVY_pyth/D");
    ftree->Branch("fVX_pyth", &fVX_pyth, "fVX_pyth/D");

    ftree->Branch("fverRank", &fverRank, "fverRank/D");

    ftree->Branch("bPartonId", &bPartonId, "bPartonId/I");
    ftree->Branch("bPartonx", &bPartonx, "bPartonx/D");
    ftree->Branch("bPartonE", &bPartonE, "bPartonE/D");
    ftree->Branch("bPartonP", &bPartonP, "bPartonP/D");
    ftree->Branch("bPartonPhi", &bPartonPhi, "bPartonPhi/D");
    ftree->Branch("bPartonEta", &bPartonEta, "bPartonEta/D");
    ftree->Branch("bPartonPt", &bPartonPt, "bPartonPt/D");
    ftree->Branch("yPartonId", &yPartonId, "yPartonId/I");
    ftree->Branch("yPartonx", &yPartonx, "yPartonx/D");
    ftree->Branch("yPartonE", &yPartonE, "yPartonE/D");
    ftree->Branch("yPartonP", &yPartonP, "yPartonP/D");
    ftree->Branch("yPartonPhi", &yPartonPhi, "yPartonPhi/D");
    ftree->Branch("yPartonEta", &yPartonEta, "yPartonEta/D");
    ftree->Branch("yPartonPt", &yPartonPt, "yPartonPt/D");
    ftree->Branch("fparton1Id", &fparton1Id, "fparton1Id/I");
    ftree->Branch("fparton1Eta", &fparton1Eta, "fparton1Eta/D");
    ftree->Branch("fparton1Phi", &fparton1Phi, "fparton1Phi/D");
    ftree->Branch("fparton1Pt", &fparton1Pt, "fparton1Pt/D");
    ftree->Branch("fparton1xBj", &fparton1xBj, "fparton1xBj/D");
    ftree->Branch("fparton1E", &fparton1E, "fparton1E/D");
    ftree->Branch("fparton2Id", &fparton2Id, "fparton2Id/I");
    ftree->Branch("fparton2Eta", &fparton2Eta, "fparton2Eta/D");
    ftree->Branch("fparton2Phi", &fparton2Phi, "fparton2Phi/D");
    ftree->Branch("fparton2Pt", &fparton2Pt, "fparton2Pt/D");
    ftree->Branch("fparton2xBj", &fparton2xBj, "fparton2xBj/D");
    ftree->Branch("fparton2E", &fparton2E, "fparton2E/D");
    ftree->Branch("partonicPtBin", &partonicPtBin, "partonicPtBin/D");
    ftree->Branch("fpT", fpT, "fpT[fmaxpar]/D");
    ftree->Branch("fp", fp, "fp[fmaxpar]/D");
    ftree->Branch("feta", feta, "feta[fmaxpar]/D");
    ftree->Branch("fphi", fphi, "fphi[fmaxpar]/D");
    ftree->Branch("fcharge", fcharge, "fcharge[fmaxpar]/S");
    // for true particle ID
    ftree->Branch("trueID", trueID, "trueID[fmaxpar]/I");
    //////////////////////
    ftree->Branch("fpT_pyth", fpT_pyth, "fpT_pyth[fmaxpar1]/D");
    ftree->Branch("fp_pyth", fp_pyth, "fp_pyth[fmaxpar1]/D");
    ftree->Branch("feta_pyth", feta_pyth, "feta_pyth[fmaxpar1]/D");
    ftree->Branch("fphi_pyth", fphi_pyth, "fphi_pyth[fmaxpar1]/D");
    ftree->Branch("fpId_pyth", fpId_pyth, "fpId_pyth[fmaxpar1]/D");
    ftree->Branch("fnSigmaPion", fnSigmaPion, "fnSigmaPion[fmaxpar]/D");
    ftree->Branch("fnSigmaKaon", fnSigmaKaon, "fnSigmaKaon[fmaxpar]/D");
    ftree->Branch("fnSigmaProton", fnSigmaProton, "fnSigmaProton[fmaxpar]/D");
    ftree->Branch("fnSigmaElectron", fnSigmaElectron, "fnSigmaElectron[fmaxpar]/D");
    ftree->Branch("fdEdx", fdEdx, "fdEdx[fmaxpar]/D");
    ftree->Branch("fdca", fdca, "fdca[fmaxpar]/D");
    ftree->Branch("ffitPts", ffitPts, "ffitPts[fmaxpar]/s");
    ftree->Branch("ffitPtsPoss", ffitPtsPoss, "ffitPtsPoss[fmaxpar]/s");
    ftree->Branch("fhitsdedx", fhitsdedx, "fhitsdedx[fmaxpar]/s");
    ftree->Branch("fPathLengthToF", fPathLengthToF, "fPathLengthToF[fmaxpar]/D");
    ftree->Branch("fBetaToF", fBetaToF, "fBetaToF[fmaxpar]/D");
    ftree->Branch("fevTime", &fevTime, "fevTime/i");
    ftree->Branch("fvpdVz", &fvpdVz, "fvpdVz/D");

    ftree->Branch("fTowerEng", &fTowerEng, "fTowerEng/D");
    ftree->Branch("fTowerEta", &fTowerEta, "fTowerEta/D");
    ftree->Branch("fTowerPhi", &fTowerPhi, "fTowerPhi/D");

    cout << "OutPut File name is : " << oFile << endl;

    chain = new StChain("StChain");
    chain->SetDebug(0);
    // setup IOMaker---can read in .dst.roo, .dst.xdf files

    StIOMaker *ioMaker = new StIOMaker();
    ioMaker->SetFile(geFile);
    ioMaker->SetIOMode("r");
    ioMaker->SetBranch("*", 0, "0");           // deactivate all branches
    ioMaker->SetBranch("geantBranch", 0, "r"); // activate geant Branch only

    StMuDebug::setLevel(0); // switch off some debug output
    char theFilter[80];
    sprintf(theFilter, ".MuDst.root:MuDst.root");
    maker = new StMuDstMaker(0, 0, "", muFile, theFilter, 1000); // set up maker in read mode
    // star database
    St_db_Maker *stDb = new St_db_Maker("StarDb", "MySQL:StarDb");
    // spin database
    StSpinDbMaker *spindb = new StSpinDbMaker;
    StMcEventMaker *mcEventMaker = new StMcEventMaker();
    StMCAsymMaker *weight = new StMCAsymMaker("MCAsym");

    // Instantiate MuDst Maker
    StMuDbReader *muDB = StMuDbReader::instance();
    // star database
    St_db_Maker *starDb = new St_db_Maker("StarDb", "MySQL:StarDb");
    // Spin Database
    StSpinDbMaker *spinDb = new StSpinDbMaker;

    // EndCap database
    StEEmcDbMaker *eemcDb = new StEEmcDbMaker;
    // Barrel ADC to energy maker;
    StEmcADCtoEMaker *adc = new StEmcADCtoEMaker;
    adc->saveAllStEvent(true);

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Open DataBase Connection for Spin Configuration @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    const char *database = "mysql://db04.star.bnl.gov:3416/RunLog?timeout=60";
    const char *user = "nghimire";
    const char *pass = "";
    TMySQLServer *mysql = TMySQLServer::Connect(database, user, pass);

    StTriggerSimuMaker *simuTrig = new StTriggerSimuMaker("StarTrigSimu");    simuTrig->useOfflineDB();
    // simuTrig->setMC(1); // Must be before individual detectors, to be passed
    simuTrig->setMC(2); // Must be before individual detectors, to be passed
    // BBC was not used in Run 9
    // simuTrig->useBbc();
    simuTrig->useBemc();
    simuTrig->useEemc();
    // simuTrig->bemc->setConfig(StBemcTriggerSimu::kOffline);
    simuTrig->bemc->setConfig(StBemcTriggerSimu::kOnline);
  
    chain->Init();
    Int_t nevents = maker->chain()->GetEntries();
    cout << nevents << " events in chain" << endl;
//To specify Fill direction
    int blue = 1;
    int yellow = 0;
   
  

    for (Int_t iev = 0; iev < nevents; iev++)
    {
        chain->Clear();
        int status= chain->Make(iev);
        if(status == kStSkip) continue;
        if(status % 10 == kStEOF || status % 10 == kStFatal) break;
        cout << status << "\t status of Event \t"<< iev<<endl; 
        StMuDst *mu = maker->muDst();
        // if(!mu){LOG_WARN<<"\t No MuDst\t"<<endm; continue;}
        if (!mu)
        {
            cout << "muDst is not defined" << endl;
        }
        StMuEvent *ev = maker->muDst()->event();
        StPythiaEvent *ge = weight->pythiaEvent();
        // if(!ev){LOG_WARN<<"\t No MuEvent\t"<<endm; continue;}
        if (!ev)
            continue;

        int runNum = ev->runNumber();
        mcVertex = ge->vertex();
        fVZ_pyth = mcVertex.Z();
        fVY_pyth = mcVertex.Y();
        fVX_pyth = mcVertex.X();

        int ver = mu->numberOfPrimaryVertices();
        cout << ver << "===========Number of Primary Vertex" << endl;


        // its looping over all the vertices need to take 1st rank vertex only to compare with picoDst;
        // find Outgoin Partons
        // cout << "Event OutPut" << ge->eventId() << "=============="<< endl;
        TParticle *line5particle = ge->particle(4); // parton from blue beam
        TParticle *line6particle = ge->particle(5); // parton from Yellow beam
        TParticle *line7particle = ge->particle(6); // parton from line7
        TParticle *line8particle = ge->particle(7); // parton from line8

        // cout << "myOut outgoing parton 1 ID = " << line7particle->GetPdgCode() << ", eta = "<<line7particle->Eta()<<", phi = "<<line7particle->Phi()<<endl;
        // cout << "myOut outgoing parton 2 ID = " << line8particle->GetPdgCode() << ", eta = "<<line8particle->Eta()<<", phi = "<<line8particle->Phi()<<endl;
        // 1st incoming particle
        bPartonId = line5particle->GetPdgCode();
        bPartonx = ge->x1();
        bPartonE = line5particle->Energy();
        bPartonP = line5particle->P();
        bPartonPhi = line5particle->Phi();
        bPartonEta = line5particle->Eta();
        bPartonPt = line5particle->Pt();
        // 2nd incoming particle
        yPartonId = line6particle->GetPdgCode();
        yPartonx = ge->x2();
        yPartonE = line6particle->Energy();
        yPartonP = line6particle->P();
        yPartonPhi = line6particle->Phi();
        yPartonEta = line6particle->Eta();
        yPartonPt = line6particle->Pt();
        // 1st outgoing particle
        fparton1Id = line7particle->GetPdgCode();
        fparton1Eta = line7particle->Eta();
        fparton1Phi = line7particle->Phi();
        fparton1Pt = line7particle->Pt();
        fparton1E = line7particle->Energy();
        fparton1xBj = ge->x1();
        // 2nd outgoing particle
        fparton2Id = line8particle->GetPdgCode();
        fparton2Eta = line8particle->Eta();
        fparton2Phi = line8particle->Phi();
        fparton2Pt = line8particle->Pt();
        fparton2E = line8particle->Energy();
        fparton2xBj = ge->x2();

        // partonic pT
        partonicPtBin = ge->pt();

        //------------pythia level particle loop----------------------
        int ntrk = ge->numberOfParticles();
        int pythia = ntrk;
        fTrackCounter1 = 0;
        for (int j = 0; j < ntrk; j++)
        {
            if (fabs(ge->particle(j)->Eta()) < 4)
            {
                fpT_pyth[fTrackCounter1] = ge->particle(j)->Pt();          // track->p().perp();
                fp_pyth[fTrackCounter1] = ge->particle(j)->P();            // track->p().mag();
                feta_pyth[fTrackCounter1] = ge->particle(j)->Eta();        // track->eta();
                fphi_pyth[fTrackCounter1] = ge->particle(j)->Phi();        // track->phi();
                fpId_pyth[fTrackCounter1] = ge->particle(j)->GetPdgCode(); // Pdg code
                fTrackCounter1++;
            }
        } // pythia track loop ended;
        fmaxpar1 = fTrackCounter1;


        StThreeVectorF vertexPos = ev->primaryVertexPosition();
        StMuPrimaryVertex *vertex = mu->primaryVertex(0);
        assert(vertex);
        fverRank = vertex->ranking();
        if (fverRank < 1e6)
            continue;

        //cout << "Ver Ranking: " << fverRank << endl;
        // if(fabs(vertexPos.x())>1. || fabs(vertexPos.y())>1.) continue;
        Double_t fvpdVz1;
        StBTofHeader const *btofHeader = (StBTofHeader *)mu->btofHeader();
        if (btofHeader)
            fvpdVz1 = btofHeader->vpdVz();

        if (fvpdVz1 != -999)
        {

            if (btofHeader)
                fvpdVz = btofHeader->vpdVz(); // causing error in my case only!!! need to see!!
        }

        int bx48 = ev->l0Trigger().bunchCrossingId();
        int fspinconfig = spindb->spin8usingBX48(bx48);
        // cout << fspinconfig << "======fspinconfig======="<< endl;
        if (fspinconfig != 51 && fspinconfig != 53 && fspinconfig != 83 && fspinconfig != 85)
            continue;

        ftrigger.clear();
        ftrigger = simuTrig->triggerIds();          

        TClonesArray *MuMcVertices = mu->mcArray(0);
        TClonesArray *MuMcTracks = mu->mcArray(1);
        Int_t NoMuMcVertices = MuMcVertices->GetEntriesFast();
        Int_t NoMuMcTracks = MuMcTracks->GetEntriesFast();

        cout << NoMuMcTracks << "\t Number of Mu MC Tracks" << endl;

        if (!NoMuMcVertices || !NoMuMcTracks)
        {
            cout << "This event has no MC information ==> skip it" << endl;
            continue;
        }


        int refMult = ev->refMult();
        int frunId = ev->runId();
        StRunInfo &runInfo = ev->runInfo();
        int fill = (int)(runInfo.beamFillNumber(blue));
        int fillNum = fill;
        int frunNum = ev->runNumber();
        int fevtNum = ev->eventNumber();
        int fspinBits = ev->l0Trigger().spinBits(frunId);
        int frefMult = refMult;
        fVZ = vertexPos.z();

        StEventInfo &evInfo = ev->eventInfo();
        unsigned int fevtime = evInfo.time();

        int fspinBits = ev->l0Trigger().spinBits(frunId);

        //-----------particle loop----------------
        int ntrk2 = mu->primaryTracks()->GetEntries();
        int geant = ntrk2;
        fTrackCounter = 0;
        for (int j = 0; j < ntrk2; j++)
        {
            StMuTrack *track = (StMuTrack *)mu->primaryTracks(j);
            // if(track->flag() < 0) continue;
            assert(track);
            // const StMuTrack *gTrk = (StMuTrack*) mu->globalTrack();
            const StMuTrack *gTrk = track->globalTrack();
            if (!gTrk)
            { // cout << "no gTrack so take primary track " << endl;
                gTrk = track;
            }

            // if(fabs(track->eta())<4.0)
            double eta = track->eta();
            int nHitsFit=gTrk->nHitsFit();
            //int nHitsFit = track->nHitsFit();
            double trackDCA = track->dcaGlobal().mag();

            if (fabs(eta)<1.5 && nHitsFit>12 && fabs(trackDCA)<3.)
            {
                fpT[fTrackCounter] = track->p().perp();
                fp[fTrackCounter] = track->p().mag();
                feta[fTrackCounter] = track->eta();
                fphi[fTrackCounter] = track->phi();
                fnSigmaPion[fTrackCounter] = track->nSigmaPion();
                fnSigmaKaon[fTrackCounter] = track->nSigmaKaon();
                fnSigmaProton[fTrackCounter] = track->nSigmaProton();
                fnSigmaElectron[fTrackCounter] = track->nSigmaElectron();
                fcharge[fTrackCounter] = track->charge();
                fdEdx[fTrackCounter] = (track->dEdx() * pow(10, 6));
                fdca[fTrackCounter] = track->dcaGlobal().mag();
                ffitPts[fTrackCounter] = gTrk->nHitsFit(); // This modification just to match the data of MuDst and PicoDst
                // ffitPts[fTrackCounter]     = track->nHitsFit(); //This modification just to match the data of MuDst and PicoDst
                fhitsdedx[fTrackCounter] = track->nHitsDedx();
                ffitPtsPoss[fTrackCounter] = gTrk->nHitsPoss(); // using gTrk just to match the data of MuDst and PicoDst
                // ffitPtsPoss[fTrackCounter]     =  track->nHitsPoss(); // using gTrk just to match the data of MuDst and PicoDst
                fPathLengthToF[fTrackCounter] = track->btofPidTraits().pathLength();
                fBetaToF[fTrackCounter] = track->btofPidTraits().beta();

                /*if (track->idTruth() <= 0 || track->idTruth() > NoMuMcTracks) {
                  cout << "Illegal idTruth " << track->idTruth() << " The track is ignored" << endl;
                  }
                  else {
                  StMuMcTrack *mcTrack = (StMuMcTrack*) MuMcTracks->UncheckedAt(track->idTruth()-1);
                  assert(mcTrack);

                  if (mcTrack->Id() = track->idTruth()) {
                  trueID[fTrackCounter]=mcTrack->GePid();
                  cout << "\t Hello StMuMcTrack\t "<<endl;

                  }
                //  cout << "Geant Particle Id = "<< mcTrack->GePid() << endl;
                if (mcTrack->Id() != track->idTruth()) {
                trueID[fTrackCounter]=-999.0;

                }
                //  cout << "Geant Particle Id = "<< mcTrack->GePid() << endl;
                //if(mcTrack->GePid()==8) pionpt_true[0] -> Fill(TrackPt);//pi plus geant id == 8
                //if(mcTrack->GePid()==9) pionpt_true[1] -> Fill(TrackPt);//pi minus geant id == 9
                } //check idTruth and trackid
                */
                fTrackCounter++;
            }//if Track Quality Cut
        } // Track loop

        fmaxpar = fTrackCounter;
        if (fmaxpar1 > 1 && fmaxpar > 1)
            ftree->Fill();
        cout << "check #'s pythia= " << pythia << " geant=" << geant << endl;


    } // event loop
    fout->cd();
    ftree->Write();
    fout->Close();
    cout << " done" << endl;
    flush(cout);
    mysql->Close();
    cout << "-----------------Job is done grab a beer Master--------------" << endl;
}
