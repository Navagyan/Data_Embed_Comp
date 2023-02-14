#include <iostream>
#include <fstream>
#include <string>

// void ReadTree_Embed(const char *tree, const char *ofile, const char *jobid) // Grid mode
//   void ReadTree_Embed(const char *tree="/star/u/nghimire/GPFS/Embed_Run17_New/Embed_RawTree_Test/AddedTree/RawEmbedTree_18113048_iff.root", const char *ofile="ReadTree_18113048_iff.root")//Test mode
// void ReadTree_Embed(const char *tree = "/star/u/nghimire/GPFS/Embed_Run17_New/Embed_RawTree_Test/AddedTree/RawEmbedTree_iff.root", const char *ofile = "ReadTree_Embed_No_partonicpT_wt.root")
void ReadTree_Embed(const char *tree = "/star/u/nghimire/GPFS/Embed_Run17_New/Embed_RawTree_Test/AddTrees/RawEmbedTree_18113012_iff.root", const char *ofile = "ReadTree_Test.root")
{
    TH1::SetDefaultSumw2();
    TChain *fChain = new TChain("ftree");
    fChain->Add(tree);
    TFile *outfile = new TFile(ofile, "recreate");

    const int fMaxHit = 3000;
    int fmaxpar;
    double fVZ;
    double fVZ_pyth;

    double fpT[fMaxHit];
    double fp[fMaxHit];
    double feta[fMaxHit];
    double fphi[fMaxHit];
    double fdca[fMaxHit];
    UShort_t ffitPts[fMaxHit];
    UShort_t ffitPtsPoss[fMaxHit];
    UShort_t fhitsdedx[fMaxHit];

    Double_t fdEdx[fMaxHit];
    Double_t fnSigmaPion[fMaxHit];
    Double_t fnSigmaKaon[fMaxHit];
    Double_t fnSigmaProton[fMaxHit];
    Double_t fnSigmaElectron[fMaxHit];

    double partonicPtBin;
    vector<int> *ftrigger;
    double fparton1Eta;
    double fparton1Phi;
    double fparton2Eta;
    double fparton2Phi;

    double pi = 3.14159265359;

    ofstream trigfile("TrigFile_Embed.txt");

    void bad_event_finders(string infile, string badEvent_file, double fVZ, double weight, double partonicPtBin, int eventNum);

    fChain->SetBranchAddress("fVZ", &fVZ);
    fChain->SetBranchAddress("fVZ_pyth", &fVZ_pyth);
    fChain->SetBranchAddress("fpT", fpT);
    fChain->SetBranchAddress("fp", fp);
    fChain->SetBranchAddress("fmaxpar", &fmaxpar);
    fChain->SetBranchAddress("partonicPtBin", &partonicPtBin);
    fChain->SetBranchAddress("feta", feta);
    fChain->SetBranchAddress("fphi", fphi);
    fChain->SetBranchAddress("ffitPts", ffitPts);
    fChain->SetBranchAddress("ffitPtsPoss", ffitPtsPoss);
    fChain->SetBranchAddress("fdca", fdca);
    fChain->SetBranchAddress("ftrigger", &ftrigger);
    fChain->SetBranchAddress("fhitsdedx", fhitsdedx);
    fChain->SetBranchAddress("fdEdx", fdEdx);

    fChain->SetBranchAddress("fnSigmaPion", fnSigmaPion);
    fChain->SetBranchAddress("fnSigmaKaon", fnSigmaKaon);
    fChain->SetBranchAddress("fnSigmaProton", fnSigmaProton);
    fChain->SetBranchAddress("fnSigmaElectron", fnSigmaElectron);

    fChain->SetBranchAddress("fparton1Eta", &fparton1Eta);
    fChain->SetBranchAddress("fparton1Phi", &fparton1Phi);
    fChain->SetBranchAddress("fparton2Eta", &fparton2Eta);
    fChain->SetBranchAddress("fparton2Phi", &fparton2Phi);

    // No Trig Seperated
    // Event Level
    TH1D *hVZ = new TH1D("hVZ_Embed", "hVZ_Embed", 125, -90, 90);
    TH1D *hVZ_wt = new TH1D("hVZ_Embed_wt", "hVZ_Embed_wt", 125, -90, 90);
    TH2D *hVZ_vs_hVZ_pyth = new TH2D("hVZ_vs_hVZ_pyth", "hVZ_vs_hVZ_pyth", 125, -90, 90, 125, -90, 90);

    TH1D *hVer_diff = new TH1D("hVer_diff", "hVer_diff", 100, -10, 10);

    // Track Level

    TH1D *hpartonicpT_wt = new TH1D("partonicpT_Embed_weighted", "partonicpT_Embed_weighted", 100, 0, 60);
    TH1D *hpartonicpT_no_wt = new TH1D("partonicpT_Embed_no_weighted", "partonicpT_Embed_no_weighted", 100, 0, 60);

    TH1D *hpT = new TH1D("pT_Embed", "pT_Embed", 100, 0, 40);
    TH1D *heta = new TH1D("heta_Embed", "heta_Embed", 100, -1.4, 1.4);
    TH1D *hphi = new TH1D("hphi_Embed", "hphi_Embed", 100, -3.4, 3.4);
    TH1D *hfitPts = new TH1D("hfitPts_Embed", "hfitPts_Embed", 60, 0, 60);
    TH1D *hfitPtsPoss = new TH1D("hfitPtsPoss_Embed", "hfitPtsPoss_Embed", 60, 0, 60);
    TH1D *hfmaxpar = new TH1D("hfmaxpar_Embed", "hfmaxpar_Embed", 120, 0, 120);

    TH1D *hfhitsdedx = new TH1D("hfhitsdedx_Embed", "hfhitsdedx_Embed", 60, 0, 60);
    TH1D *hfdEdx = new TH1D("hfdEdx_Embed", "hfdEdx_Embed", 100, -2, 2);
    TH1D *hnSigmaPion = new TH1D("hfnSigmaPion_Embed", "hfnSigmaPion_Embed", 100, -10, 10);
    TH1D *hnSigmaKaon = new TH1D("hfnSigmaKaon_Embed", "hfnSigmaKaon_Embed", 100, -10, 10);
    TH1D *hnSigmaProton = new TH1D("hfnSigmaProton_Embed", "hfnSigmaProton_Embed", 100, -10, 10);
    TH1D *hnSigmaElectron = new TH1D("hfnSigmaElectron_Embed", "hfnSigmaElectron_Embed", 100, -10, 10);

    // Trig Separated
    // Event Level
    TH1D *hVZ_JP0VPDMB30 = new TH1D("hVZ_Embed_JP0VPDMB30", "hVZ_Embed_JP0VPDMB30", 125, -90, 90);
    TH1D *hVZ_JP1VPDMB30 = new TH1D("hVZ_Embed_JP1VPDMB30", "hVZ_Embed_JP1VPDMB30", 125, -90, 90);
    TH1D *hVZ_JP2 = new TH1D("hVZ_Embed_JP2", "hVZ_Embed_JP2", 125, -90, 90);
    TH1D *hVZ_BHT3 = new TH1D("hVZ_Embed_BHT3", "hVZ_Embed_BHT3", 125, -90, 90);
    TH1D *hVZ_BHT1VPDMB30 = new TH1D("hVZ_Embed_BHT1VPDMB30", "hVZ_Embed_BHT1VPDMB30", 125, -90, 90);
    TH1D *hVZ_BHT2BBCMB = new TH1D("hVZ_Embed_BHT2BBCMB", "hVZ_Embed_BHT2BBCMB", 125, -90, 90);
    TH1D *hVZ_JPsiHTTP = new TH1D("hVZ_Embed_JPsiHTTP", "hVZ_Embed_JPsiHTTP", 125, -90, 90);
    TH1D *hVZ_VPDMB30 = new TH1D("hVZ_Embed_VPDMB30", "hVZ_Embed_VPDMB30", 125, -90, 90);
    TH1D *hVZ_JP0VPDMBLt30 = new TH1D("hVZ_Embed_JP0VPDMBLt30", "hVZ_Embed_JP0VPDMBLt30", 125, -90, 90);
    TH1D *hVZ_JP0VPDMBGt30 = new TH1D("hVZ_Embed_JP0VPDMBGt30", "hVZ_Embed_JP0VPDMBGt30", 125, -90, 90);
    TH1D *hVZ_JP1VPDMBLt30 = new TH1D("hVZ_Embed_JP1VPDMBLt30", "hVZ_Embed_JP1VPDMBLt30", 125, -90, 90);
    TH1D *hVZ_JP1VPDMBGt30 = new TH1D("hVZ_Embed_JP1VPDMBGt30", "hVZ_Embed_JP1VPDMBGt30", 125, -90, 90);

    // Track Level
    //=============================Track pT========================================
    TH1D *hpT_JP0VPDMB30 = new TH1D("pT_Embed_JP0VPDMB30", "pT_Embed_JP0VPDMB30", 100, 0, 40);
    TH1D *hpT_JP1VPDMB30 = new TH1D("pT_Embed_JP1VPDMB30", "pT_Embed_JP1VPDMB30", 100, 0, 40);
    TH1D *hpT_JP2 = new TH1D("pT_Embed_JP2", "pT_Embed_JP2", 100, 0, 40);
    TH1D *hpT_BHT3 = new TH1D("pT_Embed_BHT3", "pT_Embed_BHT3", 100, 0, 40);
    TH1D *hpT_BHT1VPDMB30 = new TH1D("pT_Embed_BHT1VPDMB30", "pT_Embed_BHT1VPDMB30", 100, 0, 40);
    TH1D *hpT_BHT2BBCMB = new TH1D("pT_Embed_BHT2BBCMB", "pT_Embed_BHT2BBCMB", 100, 0, 40);
    TH1D *hpT_JPsiHTTP = new TH1D("pT_Embed_JPsiHTTP", "pT_Embed_JPsiHTTP", 100, 0, 40);
    TH1D *hpT_VPDMB30 = new TH1D("pT_Embed_VPDMB30", "pT_Embed_VPDMB30", 100, 0, 40);
    //=============================Track eta========================================
    TH1D *heta_JP0VPDMB30 = new TH1D("heta_Embed_JP0VPDMB30", "heta_Embed_JP0VPDMB30", 100, -1.4, 1.4);
    TH1D *heta_JP1VPDMB30 = new TH1D("heta_Embed_JP1VPDMB30", "heta_Embed_JP1VPDMB30", 100, -1.4, 1.4);
    TH1D *heta_JP2 = new TH1D("heta_Embed_JP2", "heta_Embed_JP2", 100, -1.4, 1.4);
    TH1D *heta_BHT3 = new TH1D("heta_Embed_BHT3", "heta_Embed_BHT3", 100, -1.4, 1.4);
    TH1D *heta_BHT1VPDMB30 = new TH1D("heta_Embed_BHT1VPDMB30", "heta_Embed_BHT1VPDMB30", 100, -1.4, 1.4);
    TH1D *heta_BHT2BBCMB = new TH1D("heta_Embed_BHT2BBCMB", "heta_Embed_BHT2BBCMB", 100, -1.4, 1.4);
    TH1D *heta_JPsiHTTP = new TH1D("heta_Embed_JPsiHTTP", "heta_Embed_JPsiHTTP", 100, -1.4, 1.4);
    TH1D *heta_VPDMB30 = new TH1D("heta_Embed_VPDMB30", "heta_Embed_VPDMB30", 100, -1.4, 1.4);
    //=============================Track phi========================================
    TH1D *hphi_JP0VPDMB30 = new TH1D("hphi_Embed_JP0VPDMB30", "hphi_Embed_JP0VPDMB30", 100, -3.4, 3.4);
    TH1D *hphi_JP1VPDMB30 = new TH1D("hphi_Embed_JP1VPDMB30", "hphi_Embed_JP1VPDMB30", 100, -3.4, 3.4);
    TH1D *hphi_JP2 = new TH1D("hphi_Embed_JP2", "hphi_Embed_JP2", 100, -3.4, 3.4);
    TH1D *hphi_BHT3 = new TH1D("hphi_Embed_BHT3", "hphi_Embed_BHT3", 100, -3.4, 3.4);
    TH1D *hphi_BHT1VPDMB30 = new TH1D("hphi_Embed_BHT1VPDMB30", "hphi_Embed_BHT1VPDMB30", 100, -3.4, 3.4);
    TH1D *hphi_BHT2BBCMB = new TH1D("hphi_Embed_BHT2BBCMB", "hphi_Embed_BHT2BBCMB", 100, -3.4, 3.4);
    TH1D *hphi_JPsiHTTP = new TH1D("hphi_Embed_JPsiHTTP", "hphi_Embed_JPsiHTTP", 100, -3.4, 3.4);
    TH1D *hphi_VPDMB30 = new TH1D("hphi_Embed_VPDMB30", "hphi_Embed_VPDMB30", 100, -3.4, 3.4);
    //=============================Track fitPts========================================
    TH1D *hfitPts_JP0VPDMB30 = new TH1D("hfitPts_Embed_JP0VPDMB30", "hfitPts_Embed_JP0VPDMB30", 60, 0, 60);
    TH1D *hfitPts_JP1VPDMB30 = new TH1D("hfitPts_Embed_JP1VPDMB30", "hfitPts_Embed_JP1VPDMB30", 60, 0, 60);
    TH1D *hfitPts_JP2 = new TH1D("hfitPts_Embed_JP2", "hfitPts_Embed_JP2", 60, 0, 60);
    TH1D *hfitPts_BHT3 = new TH1D("hfitPts_Embed_BHT3", "hfitPts_Embed_BHT3", 60, 0, 60);
    TH1D *hfitPts_BHT1VPDMB30 = new TH1D("hfitPts_Embed_BHT1VPDMB30", "hfitPts_Embed_BHT1VPDMB30", 60, 0, 60);
    TH1D *hfitPts_BHT2BBCMB = new TH1D("hfitPts_Embed_BHT2BBCMB", "hfitPts_Embed_BHT2BBCMB", 60, 0, 60);
    TH1D *hfitPts_JPsiHTTP = new TH1D("hfitPts_Embed_JPsiHTTP", "hfitPts_Embed_JPsiHTTP", 60, 0, 60);
    TH1D *hfitPts_VPDMB30 = new TH1D("hfitPts_Embed_VPDMB30", "hfitPts_Embed_VPDMB30", 60, 0, 60);
    //=============================Track fitPtsPss========================================
    TH1D *hfitPtsPoss_JP0VPDMB30 = new TH1D("hfitPtsPoss_Embed_JP0VPDMB30", "hfitPtsPoss_Embed_JP0VPDMB30", 60, 0, 60);
    TH1D *hfitPtsPoss_JP1VPDMB30 = new TH1D("hfitPtsPoss_Embed_JP1VPDMB30", "hfitPtsPoss_Embed_JP1VPDMB30", 60, 0, 60);
    TH1D *hfitPtsPoss_JP2 = new TH1D("hfitPtsPoss_Embed_JP2", "hfitPtsPoss_Embed_JP2", 60, 0, 60);
    TH1D *hfitPtsPoss_BHT3 = new TH1D("hfitPtsPoss_Embed_BHT3", "hfitPtsPoss_Embed_BHT3", 60, 0, 60);
    TH1D *hfitPtsPoss_BHT1VPDMB30 = new TH1D("hfitPtsPoss_Embed_BHT1VPDMB30", "hfitPtsPoss_Embed_BHT1VPDMB30", 60, 0, 60);
    TH1D *hfitPtsPoss_BHT2BBCMB = new TH1D("hfitPtsPoss_Embed_BHT2BBCMB", "hfitPtsPoss_Embed_BHT2BBCMB", 60, 0, 60);
    TH1D *hfitPtsPoss_JPsiHTTP = new TH1D("hfitPtsPoss_Embed_JPsiHTTP", "hfitPtsPoss_Embed_JPsiHTTP", 60, 0, 60);
    TH1D *hfitPtsPoss_VPDMB30 = new TH1D("hfitPtsPoss_Embed_VPDMB30", "hfitPtsPoss_Embed_VPDMB30", 60, 0, 60);
    //=============================Track hitsdedx========================================
    TH1D *hfhitsdedx_JP0VPDMB30 = new TH1D("hfhitsdedx_Embed_JP0VPDMB30", "hfhitsdedx_Embed_JP0VPDMB30", 60, 0, 60);
    TH1D *hfhitsdedx_JP1VPDMB30 = new TH1D("hfhitsdedx_Embed_JP1VPDMB30", "hfhitsdedx_Embed_JP1VPDMB30", 60, 0, 60);
    TH1D *hfhitsdedx_JP2 = new TH1D("hfhitsdedx_Embed_JP2", "hfhitsdedx_Embed_JP2", 60, 0, 60);
    TH1D *hfhitsdedx_BHT3 = new TH1D("hfhitsdedx_Embed_BHT3", "hfhitsdedx_Embed_BHT3", 60, 0, 60);
    TH1D *hfhitsdedx_BHT1VPDMB30 = new TH1D("hfhitsdedx_Embed_BHT1VPDMB30", "hfhitsdedx_Embed_BHT1VPDMB30", 60, 0, 60);
    TH1D *hfhitsdedx_BHT2BBCMB = new TH1D("hfhitsdedx_Embed_BHT2BBCMB", "hfhitsdedx_Embed_BHT2BBCMB", 60, 0, 60);
    TH1D *hfhitsdedx_JPsiHTTP = new TH1D("hfhitsdedx_Embed_JPsiHTTP", "hfhitsdedx_Embed_JPsiHTTP", 60, 0, 60);
    TH1D *hfhitsdedx_VPDMB30 = new TH1D("hfhitsdedx_Embed_VPDMB30", "hfhitsdedx_Embed_VPDMB30", 60, 0, 60);
    //=============================Track dEdx========================================
    TH1D *hfdEdx_JP0VPDMB30 = new TH1D("hfdEdx_Embed_JP0VPDMB30", "hfdEdx_Embed_JP0VPDMB30", 100, -2, 2);
    TH1D *hfdEdx_JP1VPDMB30 = new TH1D("hfdEdx_Embed_JP1VPDMB30", "hfdEdx_Embed_JP1VPDMB30", 100, -2, 2);
    TH1D *hfdEdx_JP2 = new TH1D("hfdEdx_Embed_JP2", "hfdEdx_Embed_JP2", 100, -2, 2);
    TH1D *hfdEdx_BHT3 = new TH1D("hfdEdx_Embed_BHT3", "hfdEdx_Embed_BHT3", 100, -2, 2);
    TH1D *hfdEdx_BHT1VPDMB30 = new TH1D("hfdEdx_Embed_BHT1VPDMB30", "hfdEdx_Embed_BHT1VPDMB30", 100, -2, 2);
    TH1D *hfdEdx_BHT2BBCMB = new TH1D("hfdEdx_Embed_BHT2BBCMB", "hfdEdx_Embed_BHT2BBCMB", 100, -2, 2);
    TH1D *hfdEdx_JPsiHTTP = new TH1D("hfdEdx_Embed_JPsiHTTP", "hfdEdx_Embed_JPsiHTTP", 100, -2, 2);
    TH1D *hfdEdx_VPDMB30 = new TH1D("hfdEdx_Embed_VPDMB30", "hfdEdx_Embed_VPDMB30", 100, -2, 2);
    //=============================Track nSigmaPion========================================
    TH1D *hnSigmaPion_JP0VPDMB30 = new TH1D("hnSigmaPion_Embed_JP0VPDMB30", "hnSigmaPion_Embed_JP0VPDMB30", 100, -10, 10);
    TH1D *hnSigmaPion_JP1VPDMB30 = new TH1D("hnSigmaPion_Embed_JP1VPDMB30", "hnSigmaPion_Embed_JP1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaPion_JP2 = new TH1D("hnSigmaPion_Embed_JP2", "hnSigmaPion_Embed_JP2", 100, -10, 10);
    TH1D *hnSigmaPion_BHT3 = new TH1D("hnSigmaPion_Embed_BHT3", "hnSigmaPion_Embed_BHT3", 100, -10, 10);
    TH1D *hnSigmaPion_BHT1VPDMB30 = new TH1D("hnSigmaPion_Embed_BHT1VPDMB30", "hnSigmaPion_Embed_BHT1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaPion_BHT2BBCMB = new TH1D("hnSigmaPion_Embed_BHT2BBCMB", "hnSigmaPion_Embed_BHT2BBCMB", 100, -10, 10);
    TH1D *hnSigmaPion_JPsiHTTP = new TH1D("hnSigmaPion_Embed_JPsiHTTP", "hnSigmaPion_Embed_JPsiHTTP", 100, -10, 10);
    TH1D *hnSigmaPion_VPDMB30 = new TH1D("hnSigmaPion_Embed_VPDMB30", "hnSigmaPion_Embed_VPDMB30", 100, -10, 10);

    //=============================Track nSigmaKaon========================================
    TH1D *hnSigmaKaon_JP0VPDMB30 = new TH1D("hnSigmaKaon_Embed_JP0VPDMB30", "hnSigmaKaon_Embed_JP0VPDMB30", 100, -10, 10);
    TH1D *hnSigmaKaon_JP1VPDMB30 = new TH1D("hnSigmaKaon_Embed_JP1VPDMB30", "hnSigmaKaon_Embed_JP1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaKaon_JP2 = new TH1D("hnSigmaKaon_Embed_JP2", "hnSigmaKaon_Embed_JP2", 100, -10, 10);
    TH1D *hnSigmaKaon_BHT3 = new TH1D("hnSigmaKaon_Embed_BHT3", "hnSigmaKaon_Embed_BHT3", 100, -10, 10);
    TH1D *hnSigmaKaon_BHT1VPDMB30 = new TH1D("hnSigmaKaon_Embed_BHT1VPDMB30", "hnSigmaKaon_Embed_BHT1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaKaon_BHT2BBCMB = new TH1D("hnSigmaKaon_Embed_BHT2BBCMB", "hnSigmaKaon_Embed_BHT2BBCMB", 100, -10, 10);
    TH1D *hnSigmaKaon_JPsiHTTP = new TH1D("hnSigmaKaon_Embed_JPsiHTTP", "hnSigmaKaon_Embed_JPsiHTTP", 100, -10, 10);
    TH1D *hnSigmaKaon_VPDMB30 = new TH1D("hnSigmaKaon_Embed_VPDMB30", "hnSigmaKaon_Embed_VPDMB30", 100, -10, 10);
    //=============================Track nSigmaProton========================================
    TH1D *hnSigmaProton_JP0VPDMB30 = new TH1D("hnSigmaProton_Embed_JP0VPDMB30", "hnSigmaProton_Embed_JP0VPDMB30", 100, -10, 10);
    TH1D *hnSigmaProton_JP1VPDMB30 = new TH1D("hnSigmaProton_Embed_JP1VPDMB30", "hnSigmaProton_Embed_JP1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaProton_JP2 = new TH1D("hnSigmaProton_Embed_JP2", "hnSigmaProton_Embed_JP2", 100, -10, 10);
    TH1D *hnSigmaProton_BHT3 = new TH1D("hnSigmaProton_Embed_BHT3", "hnSigmaProton_Embed_BHT3", 100, -10, 10);
    TH1D *hnSigmaProton_BHT1VPDMB30 = new TH1D("hnSigmaProton_Embed_BHT1VPDMB30", "hnSigmaProton_Embed_BHT1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaProton_BHT2BBCMB = new TH1D("hnSigmaProton_Embed_BHT2BBCMB", "hnSigmaProton_Embed_BHT2BBCMB", 100, -10, 10);
    TH1D *hnSigmaProton_JPsiHTTP = new TH1D("hnSigmaProton_Embed_JPsiHTTP", "hnSigmaProton_Embed_JPsiHTTP", 100, -10, 10);
    TH1D *hnSigmaProton_VPDMB30 = new TH1D("hnSigmaProton_Embed_VPDMB30", "hnSigmaProton_Embed_VPDMB30", 100, -10, 10);

    //=============================Track nSigmaElectron========================================
    TH1D *hnSigmaElectron_JP0VPDMB30 = new TH1D("hnSigmaElectron_Embed_JP0VPDMB30", "hnSigmaElectron_Embed_JP0VPDMB30", 100, -10, 10);
    TH1D *hnSigmaElectron_JP1VPDMB30 = new TH1D("hnSigmaElectron_Embed_JP1VPDMB30", "hnSigmaElectron_Embed_JP1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaElectron_JP2 = new TH1D("hnSigmaElectron_Embed_JP2", "hnSigmaElectron_Embed_JP2", 100, -10, 10);
    TH1D *hnSigmaElectron_BHT3 = new TH1D("hnSigmaElectron_Embed_BHT3", "hnSigmaElectron_Embed_BHT3", 100, -10, 10);
    TH1D *hnSigmaElectron_BHT1VPDMB30 = new TH1D("hnSigmaElectron_Embed_BHT1VPDMB30", "hnSigmaElectron_Embed_BHT1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaElectron_BHT2BBCMB = new TH1D("hnSigmaElectron_Embed_BHT2BBCMB", "hnSigmaElectron_Embed_BHT2BBCMB", 100, -10, 10);
    TH1D *hnSigmaElectron_JPsiHTTP = new TH1D("hnSigmaElectron_Embed_JPsiHTTP", "hnSigmaElectron_Embed_JPsiHTTP", 100, -10, 10);
    TH1D *hnSigmaElectron_VPDMB30 = new TH1D("hnSigmaElectron_Embed_VPDMB30", "hnSigmaElectron_Embed_VPDMB30", 100, -10, 10);

    TH1D *hparton1Phi = new TH1D("hparton1Phi", "hparton1Phi", 100, -3.5, 3.5);

    // string hVZ_BHT3_peak_range_file = "hVZ_BHT3_peak_range_fitMethod.txt";

    string hVZ_BHT3_peak_range_file = "hVZ_Embed_BHT3_peak_range_aveMethod.txt";
    // string hVZ_BHT3_peak_range_file = "hVZ_BHT3_peak_range_fitMethod_Test.txt";
    string BHT3_badEvent_file = "hVZ_BHT3_badEvents.txt";

    Float_t partPtRange[14] = {2., 3., 4., 5., 7., 9., 11., 15., 20., 25., 35., 45., 55., 1000.};

    const char *PtRange_name[14] = {"2", "3", "4", "5", "7", "9", "11", "15", "20", "25", "35", "45", "55", "1000"};
    // weight from full Embedding sample
    //  Float_t Weight[13]={1.539887e-04,7.783662e-05,1.175011e-05,5.688997e-06,1.778670e-06,3.506588e-07,1.233275e-07,2.334919e-08,7.873147e-09,2.547234e-09,1.894544e-09,9.889473e-11,2.612142e-11};
    // Float_t Weight[13] = {1.539887e-04, 7.783662e-05, 1.175011e-05, 5.688997e-06, 1.778670e-06, 3.506588e-07, 1.233275e-07, 2.334919e-08, 7.873147e-09, 2.547234e-09, 1.894544e-09, 9.889473e-11, 2.612142e-11};
    // Weight for 40 Run

    // Float_t Weight[13] = {1.113913e-03,3.681974e-04,7.695773e-05,2.967876e-05,1.035020e-05,2.310203e-06,7.110883e-07, 1.499063e-07,4.769596e-08,1.670059e-08,6.956749e-09,6.601747e-10,1.255034e-10};

    // New Embedding for 100 Runs
    Float_t Weight[13] = {6.018185e-4, 1.874061e-04, 5.753168e-05, 1.726453e-05, 5.351992e-06, 1.618383e-06, 4.854301e-07, 1.464371e-07, 4.348023e-08, 1.300922e-08, 3.883460e-09, 1.229574e-09, 3.740591e-10};

    // Calculate Weight Right here//
    // Run17

    // Calculate Weight from Run13 Zilong Table

    // Float_t pTweight[13] = {0};
    // const int nbins = 13;
    // const int nptBin = 13;
    // TH1D *hpT_bin[nbins];
    // Double_t binLumi[nptBin] = {0};
    // Double_t binWt[nptBin] = {0};
    // Double_t fudge[nptBin] = {0.73, 0.89, 0.95, 0.97, 1.0, 0.99, 0.99, 0.99, 1.0, 1.0, 1.0, 0.99, 1.0};
    // Double_t crossSection[nptBin] = {28.7, 5.87, 1.69, 0.859, 0.178, 0.0509, 0.0251, 0.00532, 0.00106, 0.//000371, 4.58e-5, 8.31e-6, 2.59e-6};
    //
    // Double_t numEvents[nptBin] = {486442, 318342, 297264, 504850, 336350, 318115, 523236, 366573, 238804, //269903, 113973, 69696, 65343};
    //
    // for (int mBin = 0; mBin < nptBin; mBin++)
    //
    //{
    //    hpT_bin[mBin] = new TH1D(Form("hpTBin%s_%s", PtRange_name[mBin], PtRange_name[mBin + 1]), Form//("hpT    Bin%s_%s", PtRange_name[mBin], PtRange_name[mBin + 1]), 100, 0, 40);
    //    binLumi[mBin] = (numEvents[mBin] * crossSection[12]) / (crossSection[mBin] * numEvents[12]); // //bin     luminosity
    //    binWt[mBin] = (fudge[mBin]) / (binLumi[mBin]);
    //    // binWt[mBin] = 1. / (binLumi[mBin] * fudge[mBin]);                                            // //Bin     weight for partonic p    T weighting.
    //    pTweight[mBin] = binWt[mBin];
    //    cout << pTweight[mBin] << "\t pT weight" << endl;
    //}

    Float_t pTweight[13] = {0};
    const int nbins = 13;
    TH1D *hpT_bin[nbins];
    TH1D *hVZ_JP2_pTBin[nbins];
    TH1D *hVZ_pTBin[nbins];
    TH1D *hVZ_BHT3_pTBin[nbins];
    double fudge_factor[nbins] = {0.73, 0.89, 0.95, 0.97, 1.0, 0.99, 0.99, 0.99, 1.0, 1.0, 1.0, 0.99, 1.0};
    for (int jj = 0; jj < nbins; jj++)
    {

        hVZ_pTBin[jj] = new TH1D(Form("hVZ_pTBin%s_%s", PtRange_name[jj], PtRange_name[jj + 1]), Form("hVZ_pTBin%s_%s", PtRange_name[jj], PtRange_name[jj + 1]), 125, -90, 90);
        hVZ_JP2_pTBin[jj] = new TH1D(Form("hVZ_JP2_pTBin%s_%s", PtRange_name[jj], PtRange_name[jj + 1]), Form("hVZ_JP2_pTBin%s_%s", PtRange_name[jj], PtRange_name[jj + 1]), 125, -90, 90);
        hVZ_BHT3_pTBin[jj] = new TH1D(Form("hVZ_BHT3_pTBin%s_%s", PtRange_name[jj], PtRange_name[jj + 1]), Form("hVZ_BHT3_pTBin%s_%s", PtRange_name[jj], PtRange_name[jj + 1]), 125, -90, 90);
        hpT_bin[jj] = new TH1D(Form("hpTBin%s_%s", PtRange_name[jj], PtRange_name[jj + 1]), Form("hpTBin%s_%s", PtRange_name[jj], PtRange_name[jj + 1]), 100, 0, 40);
        // pTweight[jj] = Weight[jj] / Weight[nbins - 1];
        pTweight[jj] = (Weight[jj] * fudge_factor[jj]) / Weight[nbins - 1];
        // cout << pTweight[jj] << "\t partonic weight " << endl;
    }
    double ptw = 0;

    int ntry = fChain->GetEntries();
    cout << ntry << "\t Entries in the Tree" << endl;
    // Event loop
    for (int i = 0; i < ntry; i++)
    // for (int i = 0; i < 2000; i++)
    {
        if (i % 100000 == 0)
        {
            cout << "\t Event num\t" << i << endl;
        }

        fChain->GetEntry(i);
        // cout << fVZ << "\t fVZ\t " << endl;
        if (fabs(fVZ) > 90)
            continue; // new changed previously it was after assiging the weight//
        if (fabs(fVZ_pyth) > 90)
            continue;

        // if (partonicPtBin > 2 && partonicPtBin < 11)
        //    continue;
        // cout << ver_diff << "\tdifference in vertex\t" << endl;
        double ver_diff = 0;
        ver_diff = (fVZ - fVZ_pyth);

        hVer_diff->Fill(ver_diff);
        hVZ_vs_hVZ_pyth->Fill(fVZ, fVZ_pyth);
        if (fabs(ver_diff) > 2)
            continue;
        // hparton1Phi->Fill(fparton1Phi);
        if (fparton1Phi > pi)
            fparton1Phi = fparton1Phi - 2. * pi;
        if (fparton1Phi < (-1) * pi)
            fparton1Phi = fparton1Phi + 2. * pi;
        if (fparton2Phi > pi)
            fparton2Phi = fparton2Phi - 2. * pi;
        if (fparton2Phi < (-1) * pi)
            fparton2Phi = fparton2Phi + 2. * pi;
        hparton1Phi->Fill(fparton1Phi);

        // if (partonicPtBin<15) continue;
        for (int bin = 0; bin < 13; bin++)

        {
            if (bin < 12 && partonicPtBin >= partPtRange[bin] && partonicPtBin < partPtRange[bin + 1])
            {
                ptw = pTweight[bin];
                // cout << ptw << "partonic weight for partonic pT" << partonicPtBin << endl;
            }
            if (bin == 12 && partonicPtBin >= partPtRange[bin])
            {
                ptw = pTweight[bin];
            }
        }

        int trig_JP0VPDMB30 = 0;
        int trig_JP1VPDMB30 = 0;
        int trig_JP0VPDMBLt30 = 0;
        int trig_JP0VPDMBGt30 = 0;
        int trig_JP1VPDMBLt30 = 0;
        int trig_JP1VPDMBGt30 = 0;
        int trig_JP2 = 0;
        int trig_BHT3 = 0;
        int trig_BHT1VPDMB30 = 0;
        int trig_BHT2BBCMB = 0;
        int trig_JPsiHTTP = 0;
        int trig_VPDMB30 = 0;

        for (int trig = 0; trig < ftrigger->size(); trig++)
        {
            // cout << ftrigger->at(trig) << "\t Trigger id " << endl;
            trigfile << ftrigger->at(trig) << endl;

            if (ftrigger->at(trig) == 570401)
            {
                // Skipping the bad Events for JP2
                // if (i != 20170 && i != 20231 && i != 20265 && i != 92457 && i != 92511 && i != 92547 && i != 20074 && i != 20303 && i != 20371 && i != 54026 && i != 99435 && i != 125032 && i != 140880 && i != 214509 && i != 8934 && i != 9253 && i != 42589 && i != 51456 && i != 57997 && i != 67499 && i != 78421 && i != 92583 && i != 92626 && i != 92654 && i != 100722 && i != 112921 && i != 153503 && i != 163740 && i != 164041 && i != 198201 && i != 229057 && i != 247538 && i != 310677 && i != 311624)
                //{
                trig_JP2 = 1;
                // cout << "Hello\t" << trig_JP2 << endl;
                // } // JP2 bad Events
            } // JP2 trigger Flag
            // else if (ftrigger->at(trig) != 570403)
            if (ftrigger->at(trig) == 570403)
            {

                trig_JP1VPDMB30 = 1;
                if (fabs(fVZ) < 30)
                {
                    trig_JP1VPDMBLt30 = 1;
                }
                if (fabs(fVZ) > 30)
                {
                    trig_JP1VPDMBGt30 = 1;
                }
            }

            if (ftrigger->at(trig) == 570404)
            {

                trig_JP0VPDMB30 = 1;
                if (fabs(fVZ) < 30)
                {
                    trig_JP0VPDMBLt30 = 1;
                }
                if (fabs(fVZ) > 30)
                {
                    trig_JP0VPDMBGt30 = 1;
                }
            }

            if (ftrigger->at(trig) == 570201)
            {
                trig_BHT3 = 1;
                // if (partonicPtBin > 15)
                //{
                //     // Skipping the bad Event for BHT3 trigger
                //     if (i == 1350 && i == 1417 && i == 3307 && i == 20170 && i == 20231 && i == 22134 && i == 26350 && i == 26356 && i == 26420 && i == 39561 && i == 54146 && i == 62849 && i == 64507 && i == 64564 && i == 75710 && i == 96284 && i == 101496 && i == 101555 && i == 105142 && i == 118748 && i == 125431 && i == 148581 && i == 149213 && i == 149277 && i == 156859 && i == 156921 && i == 157817 && i == 160316 && i == 164784 && i == 176495 && i == 189990 && i == 190606 && i == 212404 && i == 219113 && i == 220937 && i == 220996 && i == 223414 && i == 223469 && i == 235870 && i == 235935 && i == 239104 && i == 239157 && i == 252016 && i == 261112 && i == 261407 && i == 262373 && i == 262437 && i == 268683 && i == 269578 && i == 269889 && i == 271482 && i == 289695 && i == 290640 && i == 290707 && i == 296771 && i == 305521 && i == 310781 && i == 1350 && i == 1417 && i == 3307 && i == 20170 && i == 20231 && i == 20265 && i == 22134 && i == 22196 && i == 22236 && i == 26350 && i == 26356 && i == 26420 && i == 39561 && i == 39655 && i == 45351 && i == 45381 && i == 54146 && i == 54214 && i == 62849 && i == 64507 && i == 64564 && i == 64601 && i == 75710 && i == 96284 && i == 101496 && i == 101555 && i == 105142 && i == 118748 && i == 125431 && i == 148581 && i == 149213 && i == 149277 && i == 156859 && i == 156921 && i == 157817 && i == 160316 && i == 164784 && i == 164853 && i == 164909 && i == 176495 && i == 176559 && i == 189990 && i == 190606 && i == 212404 && i == 219113 && i == 220937 && i == 220996 && i == 223414 && i == 223469 && i == 235870 && i == 235935 && i == 239104 && i == 239157 && i == 243190 && i == 252016 && i == 261112 && i == 261407 && i == 262373 && i == 262437 && i == 268683 && i == 269578 && i == 269889 && i == 271482 && i == 285453 && i == 289695 && i == 290640 && i == 290707 && i == 290746 && i == 291711 && i == 296771 && i == 296861 && i == 305521 && i == 308513 && i == 310781 && i == 1456 && i == 11721 && i == 26451 && i == 32864 && i == 51641 && i == 51670 && i == 101594 && i == 103553 && i == 103588 && i == 118786 && i == 135407 && i == 135442 && i == 156624 && i == 156958 && i == 162610 && i == 162642 && i == 164888 && i == 164892 && i == 171514 && i == 176598 && i == 223502 && i == 225119 && i == 239190 && i == 252073 && i == 252102 && i == 252734 && i == 252769 && i == 261150 && i == 270659 && i == 274242 && i == 285491 && i == 308550 && i == 310848 && i == 310885)
                //     {
                //         trig_BHT3 = 1;
                //     } // BHT3 Bad Events
                // }     // partonic pT Bin
            } // BHT3 trigger Flag
            if (ftrigger->at(trig) == 570215)
            {
                trig_BHT2BBCMB = 1;
            }
            if (ftrigger->at(trig) == 570214)
            {
                trig_BHT1VPDMB30 = 1;
            }

            if (ftrigger->at(trig) == 570229)
            {
                trig_JPsiHTTP = 1;
            }
            if (trig_JP2 != 1 && trig_JP0VPDMB30 != 1 && trig_JP1VPDMB30 != 1 && trig_BHT3 != 1 && trig_BHT1VPDMB30 != 1 && trig_BHT2BBCMB != 1 && trig_JPsiHTTP != 1)
            {
                trig_VPDMB30 = 1;
            }

        } // frigger Loop

        if (trig_JP2 != 1 && trig_JP0VPDMB30 != 1 && trig_JP1VPDMB30 != 1 && trig_BHT3 != 1 && trig_BHT1VPDMB30 != 1 && trig_BHT2BBCMB != 1 && trig_JPsiHTTP != 1 && trig_VPDMB30 != 1)
            continue;

        // if(verweight<0) continue;
        // cout << partonicPtBin << "\t partonicPt\t "<< ptw<< "\t weight\t"<<endl;

        // vertex weight for all triggers from 2nd pol fit at the tail and gaus fit at the centeral region
        double VZ_wt_Alltrig = 0;
        VZ_wt_Alltrig = 0.01105 + (-0.008031) * pow(fVZ, 1) + (-3.185e-6) * pow(fVZ, 2) + 1.298 * exp(-0.5 * pow(((fVZ - (-2.464)) / 22.17), 2)) + 0.3261 + (0.007586) * pow(fVZ, 1) + (6.005e-5) * pow(fVZ, 2);

        // VZ_wt_Alltrig = 1.502 + (-0.003938) * pow(fVZ, 1.) + (-0.0007609) * pow(fVZ, 2.) + (1.456e-06) * pow(fVZ, 3.) + (1.85e-07) * pow(fVZ, 4.) + (-1.42e-10) * pow(fVZ, 5.) + (-1.33e-11) * pow(fVZ, 6.);

        hVZ->Fill(fVZ, ptw);
        hVZ_wt->Fill(fVZ, ptw * VZ_wt_Alltrig);
        hfmaxpar->Fill(fmaxpar, ptw);

        for (int bin = 0; bin < 13; bin++)
        {
            if (bin < 12 && partonicPtBin >= partPtRange[bin] && partonicPtBin < partPtRange[bin + 1])
            {
                // ptw = pTweight[bin];
                hVZ_pTBin[bin]->Fill(fVZ, ptw);
                if (trig_JP2 == 1)
                {
                    hVZ_JP2_pTBin[bin]->Fill(fVZ, ptw);
                }
                if (trig_BHT3 == 1)
                {
                    hVZ_BHT3_pTBin[bin]->Fill(fVZ, ptw);
                }
                // hpT_bin[bin]->Fill(fpT[k]);
                //   cout << ptw << "partonic weight for partonic pT" << partonicPtBin << endl;
            }
            if (bin == 12 && partonicPtBin >= partPtRange[bin])
            {
                hVZ_pTBin[bin]->Fill(fVZ, ptw);
                if (trig_JP2 == 1)
                {
                    hVZ_JP2_pTBin[bin]->Fill(fVZ, ptw);
                }
                if (trig_BHT3 == 1)
                {
                    hVZ_BHT3_pTBin[bin]->Fill(fVZ, ptw);
                }
                // hpT_bin[bin]->Fill(fpT[k]);
                //   cout << ptw << "partonic weight for partonic pT" << partonicPtBin << endl;
                //    ptw = pTweight[bin];
            }
        } // partonic pT for Loop

        if (trig_JP0VPDMB30 == 1)
        {
            // bad_event_finders(std::string infile, std::string badEvent_file, double fVZ, double weight, double partonicPtBin, int eventNum)
            //    bad_event_finders(hVZ_JP2_peak_range_file, JP2_badEvent_file, fVZ, ptw, partonicPtBin, i);
            hVZ_JP0VPDMB30->Fill(fVZ, ptw * VZ_wt_Alltrig);

        } // JP0VPDMB30 Trigger Flag
        // if (trig_JP0VPDMBLt30 == 1)
        //{
        //     // bad_event_finders(std::string infile, std::string badEvent_file, double fVZ, double weight, double partonicPtBin, int eventNum)
        //     //    bad_event_finders(hVZ_JP2_peak_range_file, JP2_badEvent_file, fVZ, ptw, partonicPtBin, i);
        //     hVZ_JP0VPDMBLt30->Fill(fVZ, ptw * VZ_wt_Alltrig);
        //
        //} // JP0VPDMBGt30 Trigger Flag
        // if (trig_JP0VPDMBGt30 == 1)
        //{
        //     // bad_event_finders(std::string infile, std::string badEvent_file, double fVZ, double weight, double partonicPtBin, int eventNum)
        //     //    bad_event_finders(hVZ_JP2_peak_range_file, JP2_badEvent_file, fVZ, ptw, partonicPtBin, i);
        //     hVZ_JP0VPDMBGt30->Fill(fVZ, ptw * VZ_wt_Alltrig);

        //} // JP0VPDMBGt30 Trigger Flag

        if (trig_JP1VPDMB30 == 1)
        {
            // bad_event_finders(std::string infile, std::string badEvent_file, double fVZ, double weight, double partonicPtBin, int eventNum)
            //    bad_event_finders(hVZ_JP2_peak_range_file, JP2_badEvent_file, fVZ, ptw, partonicPtBin, i);
            hVZ_JP1VPDMB30->Fill(fVZ, ptw * VZ_wt_Alltrig);

        } // JP1VPDMB30 Trigger Flag
          // if (trig_JP1VPDMBLt30 == 1)
          // {
          //     // bad_event_finders(std::string infile, std::string badEvent_file, double fVZ, double weight, double partonicPtBin, int eventNum)
          //     //    bad_event_finders(hVZ_JP2_peak_range_file, JP2_badEvent_file, fVZ, ptw, partonicPtBin, i);
          //     hVZ_JP1VPDMBLt30->Fill(fVZ, ptw * VZ_wt_Alltrig);
          //
          // } // JP1VPDMBGt30 Trigger Flag
        // if (trig_JP1VPDMBGt30 == 1)
        //{
        //     // bad_event_finders(std::string infile, std::string badEvent_file, double fVZ, double weight, double partonicPtBin, int eventNum)
        //     //    bad_event_finders(hVZ_JP2_peak_range_file, JP2_badEvent_file, fVZ, ptw, partonicPtBin, i);
        //     hVZ_JP1VPDMBGt30->Fill(fVZ, ptw * VZ_wt_Alltrig);
        //
        //} // JP1VPDMBGt30 Trigger Flag

        if (trig_JP2 == 1)
        {
            // bad_event_finders(std::string infile, std::string badEvent_file, double fVZ, double weight, double partonicPtBin, int eventNum)
            //    bad_event_finders(hVZ_JP2_peak_range_file, JP2_badEvent_file, fVZ, ptw, partonicPtBin, i);
            hVZ_JP2->Fill(fVZ, ptw * VZ_wt_Alltrig);

        } // JP2 Trigger Flag

        if (trig_BHT3 == 1)
        {
            // bad_event_finders(std::string infile, std::string badEvent_file, double fVZ, double weight, double partonicPtBin, int eventNum)
            //    bad_event_finders(hVZ_BHT3_peak_range_file, BHT3_badEvent_file, fVZ, ptw, partonicPtBin, i);
            hVZ_BHT3->Fill(fVZ, ptw * VZ_wt_Alltrig);

        } // BHT3 trigger Flag
        if (trig_BHT1VPDMB30 == 1)
        {
            hVZ_BHT1VPDMB30->Fill(fVZ, ptw * VZ_wt_Alltrig);
        }
        if (trig_BHT2BBCMB == 1)
        {
            hVZ_BHT2BBCMB->Fill(fVZ, ptw);
        }
        if (trig_JPsiHTTP == 1)
        {
            hVZ_JPsiHTTP->Fill(fVZ, ptw * VZ_wt_Alltrig);
        }
        if (trig_VPDMB30 == 1)
        {
            hVZ_VPDMB30->Fill(fVZ, ptw * VZ_wt_Alltrig);
        }

        // cout << partonicPtBin << "\t partonicPtBin\t" << ptw << "\t weight\t " << endl;

        hpartonicpT_wt->Fill(partonicPtBin, ptw);
        hpartonicpT_no_wt->Fill(partonicPtBin);

        // hpartonicpT->Sumw2();
        for (int k = 0; k < fmaxpar; k++)
        {
            if (fp[k] < 2.0)
                continue;
            // if (fpT[k] < 5.0)
            //     continue;
            if (feta[k] >= 1 || feta[k] <= -1)
                continue;
            if (fdca[k] > 1.0)
                continue;
            if (ffitPts[k] < 15.0)
                continue;

            double dRs = 0;
            double dR1 = sqrt(pow(fphi[k] - fparton1Phi, 2) + pow(feta[k] - fparton1Eta, 2));
            double dR2 = sqrt(pow(fphi[k] - fparton2Phi, 2) + pow(feta[k] - fparton2Eta, 2));

            if (dR1 > dR2)
            {
                dRs = dR2;
            }

            else
            {
                dRs = dR1;
            }

            for (int bin = 0; bin < 13; bin++)

            {
                if (bin < 12 && partonicPtBin >= partPtRange[bin] && partonicPtBin < partPtRange[bin + 1])
                {
                    // ptw = pTweight[bin];

                    hpT_bin[bin]->Fill(fpT[k], ptw);
                    // hpT_bin[bin]->Fill(fpT[k]);
                    //  cout << ptw << "partonic weight for partonic pT" << partonicPtBin << endl;
                }
                if (bin == 12 && partonicPtBin >= partPtRange[bin])
                {

                    hpT_bin[bin]->Fill(fpT[k], ptw);
                    // hpT_bin[bin]->Fill(fpT[k]);
                    //  cout << ptw << "partonic weight for partonic pT" << partonicPtBin << endl;
                    //   ptw = pTweight[bin];
                }
            }
            // if (dRs > 0.5)
            //     continue;
            hpT->Fill(fpT[k], ptw * VZ_wt_Alltrig);
            heta->Fill(feta[k], ptw * VZ_wt_Alltrig);
            hphi->Fill(fphi[k], ptw * VZ_wt_Alltrig);
            hfitPts->Fill(ffitPts[k], ptw * VZ_wt_Alltrig);
            hfitPtsPoss->Fill(ffitPtsPoss[k], ptw * VZ_wt_Alltrig);
            hfhitsdedx->Fill(fhitsdedx[k], ptw * VZ_wt_Alltrig);
            hfdEdx->Fill(fdEdx[k], ptw * VZ_wt_Alltrig);
            hnSigmaPion->Fill(fnSigmaPion[k], ptw * VZ_wt_Alltrig);
            hnSigmaKaon->Fill(fnSigmaKaon[k], ptw * VZ_wt_Alltrig);
            hnSigmaProton->Fill(fnSigmaProton[k], ptw * VZ_wt_Alltrig);
            hnSigmaElectron->Fill(fnSigmaElectron[k], ptw * VZ_wt_Alltrig);
            if (trig_JP0VPDMB30 == 1)
            {
                // bad_event_finders(std::string infile, std::string badEvent_file, double fVZ, double weight, double partonicPtBin, int eventNum)
                //    bad_event_finders(hVZ_JP2_peak_range_file, JP2_badEvent_file, fVZ, ptw, partonicPtBin, i);
                hpT_JP0VPDMB30->Fill(fpT[k], ptw * VZ_wt_Alltrig);
                heta_JP0VPDMB30->Fill(feta[k], ptw * VZ_wt_Alltrig);
                hphi_JP0VPDMB30->Fill(fphi[k], ptw * VZ_wt_Alltrig);
                hfitPts_JP0VPDMB30->Fill(ffitPts[k], ptw * VZ_wt_Alltrig);
                hfitPtsPoss_JP0VPDMB30->Fill(ffitPtsPoss[k], ptw * VZ_wt_Alltrig);
                hfhitsdedx_JP0VPDMB30->Fill(fhitsdedx[k], ptw * VZ_wt_Alltrig);
                hfdEdx_JP0VPDMB30->Fill(fdEdx[k], ptw * VZ_wt_Alltrig);
                hnSigmaPion_JP0VPDMB30->Fill(fnSigmaPion[k], ptw * VZ_wt_Alltrig);
                hnSigmaKaon_JP0VPDMB30->Fill(fnSigmaKaon[k], ptw * VZ_wt_Alltrig);
                hnSigmaProton_JP0VPDMB30->Fill(fnSigmaProton[k], ptw * VZ_wt_Alltrig);
                hnSigmaElectron_JP0VPDMB30->Fill(fnSigmaElectron[k], ptw * VZ_wt_Alltrig);

            } // JP0VPDMB30 Trigger Flag
            if (trig_JP1VPDMB30 == 1)
            {
                // bad_event_finders(std::string infile, std::string badEvent_file, double fVZ, double weight, double partonicPtBin, int eventNum)
                //    bad_event_finders(hVZ_JP2_peak_range_file, JP2_badEvent_file, fVZ, ptw, partonicPtBin, i);
                hpT_JP1VPDMB30->Fill(fpT[k], ptw * VZ_wt_Alltrig);
                heta_JP1VPDMB30->Fill(feta[k], ptw * VZ_wt_Alltrig);
                hphi_JP1VPDMB30->Fill(fphi[k], ptw * VZ_wt_Alltrig);
                hfitPts_JP1VPDMB30->Fill(ffitPts[k], ptw * VZ_wt_Alltrig);
                hfitPtsPoss_JP1VPDMB30->Fill(ffitPtsPoss[k], ptw * VZ_wt_Alltrig);
                hfhitsdedx_JP1VPDMB30->Fill(fhitsdedx[k], ptw * VZ_wt_Alltrig);
                hfdEdx_JP1VPDMB30->Fill(fdEdx[k], ptw * VZ_wt_Alltrig);
                hnSigmaPion_JP1VPDMB30->Fill(fnSigmaPion[k], ptw * VZ_wt_Alltrig);
                hnSigmaKaon_JP1VPDMB30->Fill(fnSigmaKaon[k], ptw * VZ_wt_Alltrig);
                hnSigmaProton_JP1VPDMB30->Fill(fnSigmaProton[k], ptw * VZ_wt_Alltrig);
                hnSigmaElectron_JP1VPDMB30->Fill(fnSigmaElectron[k], ptw * VZ_wt_Alltrig);

            } // JP0VPDMB30 Trigger Flag
            if (trig_JP2 == 1)
            {
                // bad_event_finders(std::string infile, std::string badEvent_file, double fVZ, double weight, double partonicPtBin, int eventNum)
                //    bad_event_finders(hVZ_JP2_peak_range_file, JP2_badEvent_file, fVZ, ptw, partonicPtBin, i);
                // cout << fpT[k] << "\t fpT\t" << endl;
                hpT_JP2->Fill(fpT[k], ptw * VZ_wt_Alltrig);
                heta_JP2->Fill(feta[k], ptw * VZ_wt_Alltrig);
                hphi_JP2->Fill(fphi[k], ptw * VZ_wt_Alltrig);
                hfitPts_JP2->Fill(ffitPts[k], ptw * VZ_wt_Alltrig);
                hfitPtsPoss_JP2->Fill(ffitPtsPoss[k], ptw * VZ_wt_Alltrig);
                hfhitsdedx_JP2->Fill(fhitsdedx[k], ptw * VZ_wt_Alltrig);
                hfdEdx_JP2->Fill(fdEdx[k], ptw * VZ_wt_Alltrig);
                hnSigmaPion_JP2->Fill(fnSigmaPion[k], ptw * VZ_wt_Alltrig);
                hnSigmaKaon_JP2->Fill(fnSigmaKaon[k], ptw * VZ_wt_Alltrig);
                hnSigmaProton_JP2->Fill(fnSigmaProton[k], ptw * VZ_wt_Alltrig);
                hnSigmaElectron_JP2->Fill(fnSigmaElectron[k], ptw * VZ_wt_Alltrig);

            } // JP0VPDMB30 Trigger Flag

            if (trig_BHT3 == 1)
            {
                hpT_BHT3->Fill(fpT[k], ptw * VZ_wt_Alltrig);
                heta_BHT3->Fill(feta[k], ptw * VZ_wt_Alltrig);
                hphi_BHT3->Fill(fphi[k], ptw * VZ_wt_Alltrig);
                hfitPts_BHT3->Fill(ffitPts[k], ptw * VZ_wt_Alltrig);
                hfitPtsPoss_BHT3->Fill(ffitPtsPoss[k], ptw * VZ_wt_Alltrig);
                hfhitsdedx_BHT3->Fill(fhitsdedx[k], ptw * VZ_wt_Alltrig);
                hfdEdx_BHT3->Fill(fdEdx[k], ptw * VZ_wt_Alltrig);
                hnSigmaPion_BHT3->Fill(fnSigmaPion[k], ptw * VZ_wt_Alltrig);
                hnSigmaKaon_BHT3->Fill(fnSigmaKaon[k], ptw * VZ_wt_Alltrig);
                hnSigmaProton_BHT3->Fill(fnSigmaProton[k], ptw * VZ_wt_Alltrig);
                hnSigmaElectron_BHT3->Fill(fnSigmaElectron[k], ptw * VZ_wt_Alltrig);

            } // BHT3 Trigger
            if (trig_BHT1VPDMB30 == 1)
            {
                hpT_BHT1VPDMB30->Fill(fpT[k], ptw * VZ_wt_Alltrig);
                heta_BHT1VPDMB30->Fill(feta[k], ptw * VZ_wt_Alltrig);
                hphi_BHT1VPDMB30->Fill(fphi[k], ptw * VZ_wt_Alltrig);
                hfitPts_BHT1VPDMB30->Fill(ffitPts[k], ptw * VZ_wt_Alltrig);
                hfitPtsPoss_BHT1VPDMB30->Fill(ffitPtsPoss[k], ptw * VZ_wt_Alltrig);
                hfhitsdedx_BHT1VPDMB30->Fill(fhitsdedx[k], ptw * VZ_wt_Alltrig);
                hfdEdx_BHT1VPDMB30->Fill(fdEdx[k], ptw * VZ_wt_Alltrig);
                hnSigmaPion_BHT1VPDMB30->Fill(fnSigmaPion[k], ptw * VZ_wt_Alltrig);
                hnSigmaKaon_BHT1VPDMB30->Fill(fnSigmaKaon[k], ptw * VZ_wt_Alltrig);
                hnSigmaProton_BHT1VPDMB30->Fill(fnSigmaProton[k], ptw * VZ_wt_Alltrig);
                hnSigmaElectron_BHT1VPDMB30->Fill(fnSigmaElectron[k], ptw * VZ_wt_Alltrig);
            }
            if (trig_BHT2BBCMB == 1)
            {
                hpT_BHT2BBCMB->Fill(fpT[k], ptw * VZ_wt_Alltrig);
                heta_BHT2BBCMB->Fill(feta[k], ptw * VZ_wt_Alltrig);
                hphi_BHT2BBCMB->Fill(fphi[k], ptw * VZ_wt_Alltrig);
                hfitPts_BHT2BBCMB->Fill(ffitPts[k], ptw * VZ_wt_Alltrig);
                hfitPtsPoss_BHT2BBCMB->Fill(ffitPtsPoss[k], ptw * VZ_wt_Alltrig);
                hfhitsdedx_BHT2BBCMB->Fill(fhitsdedx[k], ptw * VZ_wt_Alltrig);
                hfdEdx_BHT2BBCMB->Fill(fdEdx[k], ptw * VZ_wt_Alltrig);
                hnSigmaPion_BHT2BBCMB->Fill(fnSigmaPion[k], ptw * VZ_wt_Alltrig);
                hnSigmaKaon_BHT2BBCMB->Fill(fnSigmaKaon[k], ptw * VZ_wt_Alltrig);
                hnSigmaProton_BHT2BBCMB->Fill(fnSigmaProton[k], ptw * VZ_wt_Alltrig);
                hnSigmaElectron_BHT2BBCMB->Fill(fnSigmaElectron[k], ptw * VZ_wt_Alltrig);
            }
            if (trig_JPsiHTTP == 1)
            {
                hpT_JPsiHTTP->Fill(fpT[k], ptw * VZ_wt_Alltrig);
                heta_JPsiHTTP->Fill(feta[k], ptw * VZ_wt_Alltrig);
                hphi_JPsiHTTP->Fill(fphi[k], ptw * VZ_wt_Alltrig);
                hfitPts_JPsiHTTP->Fill(ffitPts[k], ptw * VZ_wt_Alltrig);
                hfitPtsPoss_JPsiHTTP->Fill(ffitPtsPoss[k], ptw * VZ_wt_Alltrig);
                hfhitsdedx_JPsiHTTP->Fill(fhitsdedx[k], ptw * VZ_wt_Alltrig);
                hfdEdx_JPsiHTTP->Fill(fdEdx[k], ptw * VZ_wt_Alltrig);
                hnSigmaPion_JPsiHTTP->Fill(fnSigmaPion[k], ptw * VZ_wt_Alltrig);
                hnSigmaKaon_JPsiHTTP->Fill(fnSigmaKaon[k], ptw * VZ_wt_Alltrig);
                hnSigmaProton_JPsiHTTP->Fill(fnSigmaProton[k], ptw * VZ_wt_Alltrig);
                hnSigmaElectron_JPsiHTTP->Fill(fnSigmaElectron[k], ptw * VZ_wt_Alltrig);
            }
            if (trig_VPDMB30 == 1)
            {
                hpT_VPDMB30->Fill(fpT[k], ptw * VZ_wt_Alltrig);
                heta_VPDMB30->Fill(feta[k], ptw * VZ_wt_Alltrig);
                hphi_VPDMB30->Fill(fphi[k], ptw * VZ_wt_Alltrig);
                hfitPts_VPDMB30->Fill(ffitPts[k], ptw * VZ_wt_Alltrig);
                hfitPtsPoss_VPDMB30->Fill(ffitPtsPoss[k], ptw * VZ_wt_Alltrig);
                hfhitsdedx_VPDMB30->Fill(fhitsdedx[k], ptw * VZ_wt_Alltrig);
                hfdEdx_VPDMB30->Fill(fdEdx[k], ptw * VZ_wt_Alltrig);
                hnSigmaPion_VPDMB30->Fill(fnSigmaPion[k], ptw * VZ_wt_Alltrig);
                hnSigmaKaon_VPDMB30->Fill(fnSigmaKaon[k], ptw * VZ_wt_Alltrig);
                hnSigmaProton_VPDMB30->Fill(fnSigmaProton[k], ptw * VZ_wt_Alltrig);
                hnSigmaElectron_VPDMB30->Fill(fnSigmaElectron[k], ptw * VZ_wt_Alltrig);
            }
        } // Track Loop

    } // Event loop ended

    outfile->Write();
    outfile->Close();
    trigfile.close();

} // Main Function ends
// Helper function to find out the bad Event numbers for different triggers
bad_event_finders(std::string infile, std::string badEvent_file, double fVZ, double weight, double partonicPtBin, int eventNum)
{
    // cout << infile << "\tinfile\t" << endl;
    // cout << badEvent_file << "\toutfile\t" << endl;
    ifstream file(Form("%s", infile));
    // Files are being overwritten for each event, so it should be write in append mode and do not forget to sort unique Event Number once file is written
    ofstream badEventsfile;
    badEventsfile.open(Form("%s", badEvent_file), std::ios_base::app);

    if (!file.is_open())
    {
        cout << "\tFile could not found\t" << endl;
    }
    // cout << "\t Hello Hello\t"<< "\t BHT3 events\t" << eventNum << endl;
    double loweredge, higheredge;

    while (file >> loweredge >> higheredge)
    {

        // badEventsfile << loweredge << "\t lowerEdge\t" << higheredge << "\t higherEdge \t" << endl;
        if (weight > 100000)
        {

            if ((loweredge < fVZ && fVZ < higheredge))
            {
                cout << fVZ << "\t vertex AAAA\t" << weight << "\t weight\t" << partonicPtBin << "\t partonic pT Bin\t" << eventNum << "\tEvent Num\t" << endl;
                badEventsfile << fVZ << "\t vertex\t" << weight << "\t weight\t" << partonicPtBin << "\t partonic pT Bin\t" << eventNum << "\tEvent Num\t" << endl;
                // cout << fVZ << "\t vertex AAAA\t" << weight << "\t weight\t" << partonicPtBin << "\t partonic pT Bin\t" << eventNum << "\tEvent Num\t" << endl;
                // badEventsfile << fVZ << "\t vertex\t" << weight << "\t weight\t" << partonicPtBin << "\t partonic pT Bin\t" << eventNum << "\tEvent Num\t" << endl;
                break;
            } // loweredge<fVZ<higheredge

        } // weight

    } // while loop
    badEventsfile.close();

} // bad_event_finders