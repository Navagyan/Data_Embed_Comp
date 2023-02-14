// void ReadTree_Data(const char *tree, const char *ofile,const char* jobid) //xml (or grid mode)
void ReadTree_Data(const char *tree = "/star/u/nghimire/GPFS/Embed_Run17_New/Data_RawTree_Test/AddedTree/RawDataTree_iff.root", const char *ofile = "ReadTree_Data_SL22b.root") // Interactive

{

    TH1::SetDefaultSumw2();
    TChain *fChain = new TChain("ftree");
    fChain->Add(tree);
    TFile *outfile = new TFile(ofile, "recreate");
    cout << fChain->GetEntries() << endl;

    const int fMaxHit = 3000;
    int fmaxpar;
    double fVZ;
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

    vector<int> *ftrigger;

    ofstream trigfile("TrigFile_Data.txt");

    fChain->SetBranchAddress("fVZ", &fVZ);
    fChain->SetBranchAddress("fpT", fpT);
    fChain->SetBranchAddress("fp", fp);
    fChain->SetBranchAddress("fmaxpar", &fmaxpar);
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

    // No Trig Seperated
    // Event Level
    TH1D *hVZ_noTrigSelec = new TH1D("hVZ_Data_noTrigSelec", "hVZ_Data_noTrigSelec", 125, -90, 90);
    TH1D *hVZ = new TH1D("hVZ_Data", "hVZ_Data", 125, -90, 90);

    // Track Level

    TH1D *hpT = new TH1D("pT_Data", "pT_Data", 100, 0, 40);
    TH1D *heta = new TH1D("heta_Data", "heta_Data", 100, -1.4, 1.4);
    TH1D *hphi = new TH1D("hphi_Data", "hphi_Data", 100, -3.4, 3.4);
    TH1D *hfitPts = new TH1D("hfitPts_Data", "hfitPts_Data", 60, 0, 60);
    TH1D *hfitPtsPoss = new TH1D("hfitPtsPoss_Data", "hfitPtsPoss_Data", 60, 0, 60);
    TH1D *hfmaxpar = new TH1D("hfmaxpar_Data", "hfmaxpar_Data", 120, 0, 120);

    TH1D *hfhitsdedx = new TH1D("hfhitsdedx_Data", "hfhitsdedx_Data", 60, 0, 60);
    TH1D *hfdEdx = new TH1D("hfdEdx_Data", "hfdEdx_Data", 100, -2, 2);
    TH1D *hnSigmaPion = new TH1D("hfnSigmaPion_Data", "hfnSigmaPion_Data", 100, -10, 10);
    TH1D *hnSigmaKaon = new TH1D("hfnSigmaKaon_Data", "hfnSigmaKaon_Data", 100, -10, 10);
    TH1D *hnSigmaProton = new TH1D("hfnSigmaProton_Data", "hfnSigmaProton_Data", 100, -10, 10);
    TH1D *hnSigmaElectron = new TH1D("hfnSigmaElectron_Data", "hfnSigmaElectron_Data", 100, -10, 10);

    // Trig Separated
    // Event Level
    TH1D *hVZ_JP0VPDMB30 = new TH1D("hVZ_Data_JP0VPDMB30", "hVZ_Data_JP0VPDMB30", 125, -90, 90);
    TH1D *hVZ_JP1VPDMB30 = new TH1D("hVZ_Data_JP1VPDMB30", "hVZ_Data_JP1VPDMB30", 125, -90, 90);
    TH1D *hVZ_JP2 = new TH1D("hVZ_Data_JP2", "hVZ_Data_JP2", 125, -90, 90);
    TH1D *hVZ_BHT3 = new TH1D("hVZ_Data_BHT3", "hVZ_Data_BHT3", 125, -90, 90);
    TH1D *hVZ_BHT1VPDMB30 = new TH1D("hVZ_Data_BHT1VPDMB30", "hVZ_Data_BHT1VPDMB30", 125, -90, 90);
    TH1D *hVZ_BHT2BBCMB = new TH1D("hVZ_Data_BHT2BBCMB", "hVZ_Data_BHT2BBCMB", 125, -90, 90);
    TH1D *hVZ_JPsiHTTP = new TH1D("hVZ_Data_JPsiHTTP", "hVZ_Data_JPsiHTTP", 125, -90, 90);
    TH1D *hVZ_VPDMB30 = new TH1D("hVZ_Data_VPDMB30", "hVZ_Data_VPDMB30", 125, -90, 90);
    TH1D *hVZ_JP0VPDMBLt30 = new TH1D("hVZ_Data_JP0VPDMBLt30", "hVZ_Data_JP0VPDMBLt30", 125, -90, 90);
    TH1D *hVZ_JP0VPDMBGt30 = new TH1D("hVZ_Data_JP0VPDMBGt30", "hVZ_Data_JP0VPDMBGt30", 125, -90, 90);
    TH1D *hVZ_JP1VPDMBLt30 = new TH1D("hVZ_Data_JP1VPDMBLt30", "hVZ_Data_JP1VPDMBLt30", 125, -90, 90);
    TH1D *hVZ_JP1VPDMBGt30 = new TH1D("hVZ_Data_JP1VPDMBGt30", "hVZ_Data_JP1VPDMBGt30", 125, -90, 90);

    // Track Level
    //=============================Track pT========================================
    TH1D *hpT_JP0VPDMB30 = new TH1D("pT_Data_JP0VPDMB30", "pT_Data_JP0VPDMB30", 100, 0, 40);
    TH1D *hpT_JP1VPDMB30 = new TH1D("pT_Data_JP1VPDMB30", "pT_Data_JP1VPDMB30", 100, 0, 40);
    TH1D *hpT_JP2 = new TH1D("pT_Data_JP2", "pT_Data_JP2", 100, 0, 40);
    TH1D *hpT_BHT3 = new TH1D("pT_Data_BHT3", "pT_Data_BHT3", 100, 0, 40);
    TH1D *hpT_BHT1VPDMB30 = new TH1D("pT_Data_BHT1VPDMB30", "pT_Data_BHT1VPDMB30", 100, 0, 40);
    TH1D *hpT_BHT2BBCMB = new TH1D("pT_Data_BHT2BBCMB", "pT_Data_BHT2BBCMB", 100, 0, 40);
    TH1D *hpT_JPsiHTTP = new TH1D("pT_Data_JPsiHTTP", "pT_Data_JPsiHTTP", 100, 0, 40);
    TH1D *hpT_VPDMB30 = new TH1D("pT_Data_VPDMB30", "pT_Data_VPDMB30", 100, 0, 40);
    //=============================Track eta========================================
    TH1D *heta_JP0VPDMB30 = new TH1D("heta_Data_JP0VPDMB30", "heta_Data_JP0VPDMB30", 100, -1.4, 1.4);
    TH1D *heta_JP1VPDMB30 = new TH1D("heta_Data_JP1VPDMB30", "heta_Data_JP1VPDMB30", 100, -1.4, 1.4);
    TH1D *heta_JP2 = new TH1D("heta_Data_JP2", "heta_Data_JP2", 100, -1.4, 1.4);
    TH1D *heta_BHT3 = new TH1D("heta_Data_BHT3", "heta_Data_BHT3", 100, -1.4, 1.4);
    TH1D *heta_BHT1VPDMB30 = new TH1D("heta_Data_BHT1VPDMB30", "heta_Data_BHT1VPDMB30", 100, -1.4, 1.4);
    TH1D *heta_BHT2BBCMB = new TH1D("heta_Data_BHT2BBCMB", "heta_Data_BHT2BBCMB", 100, -1.4, 1.4);
    TH1D *heta_JPsiHTTP = new TH1D("heta_Data_JPsiHTTP", "heta_Data_JPsiHTTP", 100, -1.4, 1.4);
    TH1D *heta_VPDMB30 = new TH1D("heta_Data_VPDMB30", "heta_Data_VPDMB30", 100, -1.4, 1.4);
    //=============================Track phi========================================
    TH1D *hphi_JP0VPDMB30 = new TH1D("hphi_Data_JP0VPDMB30", "hphi_Data_JP0VPDMB30", 100, -3.4, 3.4);
    TH1D *hphi_JP1VPDMB30 = new TH1D("hphi_Data_JP1VPDMB30", "hphi_Data_JP1VPDMB30", 100, -3.4, 3.4);
    TH1D *hphi_JP2 = new TH1D("hphi_Data_JP2", "hphi_Data_JP2", 100, -3.4, 3.4);
    TH1D *hphi_BHT3 = new TH1D("hphi_Data_BHT3", "hphi_Data_BHT3", 100, -3.4, 3.4);
    TH1D *hphi_BHT1VPDMB30 = new TH1D("hphi_Data_BHT1VPDMB30", "hphi_Data_BHT1VPDMB30", 100, -3.4, 3.4);
    TH1D *hphi_BHT2BBCMB = new TH1D("hphi_Data_BHT2BBCMB", "hphi_Data_BHT2BBCMB", 100, -3.4, 3.4);
    TH1D *hphi_JPsiHTTP = new TH1D("hphi_Data_JPsiHTTP", "hphi_Data_JPsiHTTP", 100, -3.4, 3.4);
    TH1D *hphi_VPDMB30 = new TH1D("hphi_Data_VPDMB30", "hphi_Data_VPDMB30", 100, -3.4, 3.4);
    //=============================Track fitPts========================================
    TH1D *hfitPts_JP0VPDMB30 = new TH1D("hfitPts_Data_JP0VPDMB30", "hfitPts_Data_JP0VPDMB30", 60, 0, 60);
    TH1D *hfitPts_JP1VPDMB30 = new TH1D("hfitPts_Data_JP1VPDMB30", "hfitPts_Data_JP1VPDMB30", 60, 0, 60);
    TH1D *hfitPts_JP2 = new TH1D("hfitPts_Data_JP2", "hfitPts_Data_JP2", 60, 0, 60);
    TH1D *hfitPts_BHT3 = new TH1D("hfitPts_Data_BHT3", "hfitPts_Data_BHT3", 60, 0, 60);
    TH1D *hfitPts_BHT1VPDMB30 = new TH1D("hfitPts_Data_BHT1VPDMB30", "hfitPts_Data_BHT1VPDMB30", 60, 0, 60);
    TH1D *hfitPts_BHT2BBCMB = new TH1D("hfitPts_Data_BHT2BBCMB", "hfitPts_Data_BHT2BBCMB", 60, 0, 60);
    TH1D *hfitPts_JPsiHTTP = new TH1D("hfitPts_Data_JPsiHTTP", "hfitPts_Data_JPsiHTTP", 60, 0, 60);
    TH1D *hfitPts_VPDMB30 = new TH1D("hfitPts_Data_VPDMB30", "hfitPts_Data_VPDMB30", 60, 0, 60);
    //=============================Track fitPtsPss========================================
    TH1D *hfitPtsPoss_JP0VPDMB30 = new TH1D("hfitPtsPoss_Data_JP0VPDMB30", "hfitPtsPoss_Data_JP0VPDMB30", 60, 0, 60);
    TH1D *hfitPtsPoss_JP1VPDMB30 = new TH1D("hfitPtsPoss_Data_JP1VPDMB30", "hfitPtsPoss_Data_JP1VPDMB30", 60, 0, 60);
    TH1D *hfitPtsPoss_JP2 = new TH1D("hfitPtsPoss_Data_JP2", "hfitPtsPoss_Data_JP2", 60, 0, 60);
    TH1D *hfitPtsPoss_BHT3 = new TH1D("hfitPtsPoss_Data_BHT3", "hfitPtsPoss_Data_BHT3", 60, 0, 60);
    TH1D *hfitPtsPoss_BHT1VPDMB30 = new TH1D("hfitPtsPoss_Data_BHT1VPDMB30", "hfitPtsPoss_Data_BHT1VPDMB30", 60, 0, 60);
    TH1D *hfitPtsPoss_BHT2BBCMB = new TH1D("hfitPtsPoss_Data_BHT2BBCMB", "hfitPtsPoss_Data_BHT2BBCMB", 60, 0, 60);
    TH1D *hfitPtsPoss_JPsiHTTP = new TH1D("hfitPtsPoss_Data_JPsiHTTP", "hfitPtsPoss_Data_JPsiHTTP", 60, 0, 60);
    TH1D *hfitPtsPoss_VPDMB30 = new TH1D("hfitPtsPoss_Data_VPDMB30", "hfitPtsPoss_Data_VPDMB30", 60, 0, 60);
    //=============================Track hitsdedx========================================
    TH1D *hfhitsdedx_JP0VPDMB30 = new TH1D("hfhitsdedx_Data_JP0VPDMB30", "hfhitsdedx_Data_JP0VPDMB30", 60, 0, 60);
    TH1D *hfhitsdedx_JP1VPDMB30 = new TH1D("hfhitsdedx_Data_JP1VPDMB30", "hfhitsdedx_Data_JP1VPDMB30", 60, 0, 60);
    TH1D *hfhitsdedx_JP2 = new TH1D("hfhitsdedx_Data_JP2", "hfhitsdedx_Data_JP2", 60, 0, 60);
    TH1D *hfhitsdedx_BHT3 = new TH1D("hfhitsdedx_Data_BHT3", "hfhitsdedx_Data_BHT3", 60, 0, 60);
    TH1D *hfhitsdedx_BHT1VPDMB30 = new TH1D("hfhitsdedx_Data_BHT1VPDMB30", "hfhitsdedx_Data_BHT1VPDMB30", 60, 0, 60);
    TH1D *hfhitsdedx_BHT2BBCMB = new TH1D("hfhitsdedx_Data_BHT2BBCMB", "hfhitsdedx_Data_BHT2BBCMB", 60, 0, 60);
    TH1D *hfhitsdedx_JPsiHTTP = new TH1D("hfhitsdedx_Data_JPsiHTTP", "hfhitsdedx_Data_JPsiHTTP", 60, 0, 60);
    TH1D *hfhitsdedx_VPDMB30 = new TH1D("hfhitsdedx_Data_VPDMB30", "hfhitsdedx_Data_VPDMB30", 60, 0, 60);
    //=============================Track dEdx========================================
    TH1D *hfdEdx_JP0VPDMB30 = new TH1D("hfdEdx_Data_JP0VPDMB30", "hfdEdx_Data_JP0VPDMB30", 100, -2, 2);
    TH1D *hfdEdx_JP1VPDMB30 = new TH1D("hfdEdx_Data_JP1VPDMB30", "hfdEdx_Data_JP1VPDMB30", 100, -2, 2);
    TH1D *hfdEdx_JP2 = new TH1D("hfdEdx_Data_JP2", "hfdEdx_Data_JP2", 100, -2, 2);
    TH1D *hfdEdx_BHT3 = new TH1D("hfdEdx_Data_BHT3", "hfdEdx_Data_BHT3", 100, -2, 2);
    TH1D *hfdEdx_BHT1VPDMB30 = new TH1D("hfdEdx_Data_BHT1VPDMB30", "hfdEdx_Data_BHT1VPDMB30", 100, -2, 2);
    TH1D *hfdEdx_BHT2BBCMB = new TH1D("hfdEdx_Data_BHT2BBCMB", "hfdEdx_Data_BHT2BBCMB", 100, -2, 2);
    TH1D *hfdEdx_JPsiHTTP = new TH1D("hfdEdx_Data_JPsiHTTP", "hfdEdx_Data_JPsiHTTP", 100, -2, 2);
    TH1D *hfdEdx_VPDMB30 = new TH1D("hfdEdx_Data_VPDMB30", "hfdEdx_Data_VPDMB30", 100, -2, 2);
    //=============================Track nSigmaPion========================================
    TH1D *hnSigmaPion_JP0VPDMB30 = new TH1D("hnSigmaPion_Data_JP0VPDMB30", "hnSigmaPion_Data_JP0VPDMB30", 100, -10, 10);
    TH1D *hnSigmaPion_JP1VPDMB30 = new TH1D("hnSigmaPion_Data_JP1VPDMB30", "hnSigmaPion_Data_JP1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaPion_JP2 = new TH1D("hnSigmaPion_Data_JP2", "hnSigmaPion_Data_JP2", 100, -10, 10);
    TH1D *hnSigmaPion_BHT3 = new TH1D("hnSigmaPion_Data_BHT3", "hnSigmaPion_Data_BHT3", 100, -10, 10);
    TH1D *hnSigmaPion_BHT1VPDMB30 = new TH1D("hnSigmaPion_Data_BHT1VPDMB30", "hnSigmaPion_Data_BHT1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaPion_BHT2BBCMB = new TH1D("hnSigmaPion_Data_BHT2BBCMB", "hnSigmaPion_Data_BHT2BBCMB", 100, -10, 10);
    TH1D *hnSigmaPion_JPsiHTTP = new TH1D("hnSigmaPion_Data_JPsiHTTP", "hnSigmaPion_Data_JPsiHTTP", 100, -10, 10);
    TH1D *hnSigmaPion_VPDMB30 = new TH1D("hnSigmaPion_Data_VPDMB30", "hnSigmaPion_Data_VPDMB30", 100, -10, 10);

    //=============================Track nSigmaKaon========================================
    TH1D *hnSigmaKaon_JP0VPDMB30 = new TH1D("hnSigmaKaon_Data_JP0VPDMB30", "hnSigmaKaon_Data_JP0VPDMB30", 100, -10, 10);
    TH1D *hnSigmaKaon_JP1VPDMB30 = new TH1D("hnSigmaKaon_Data_JP1VPDMB30", "hnSigmaKaon_Data_JP1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaKaon_JP2 = new TH1D("hnSigmaKaon_Data_JP2", "hnSigmaKaon_Data_JP2", 100, -10, 10);
    TH1D *hnSigmaKaon_BHT3 = new TH1D("hnSigmaKaon_Data_BHT3", "hnSigmaKaon_Data_BHT3", 100, -10, 10);
    TH1D *hnSigmaKaon_BHT1VPDMB30 = new TH1D("hnSigmaKaon_Data_BHT1VPDMB30", "hnSigmaKaon_Data_BHT1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaKaon_BHT2BBCMB = new TH1D("hnSigmaKaon_Data_BHT2BBCMB", "hnSigmaKaon_Data_BHT2BBCMB", 100, -10, 10);
    TH1D *hnSigmaKaon_JPsiHTTP = new TH1D("hnSigmaKaon_Data_JPsiHTTP", "hnSigmaKaon_Data_JPsiHTTP", 100, -10, 10);
    TH1D *hnSigmaKaon_VPDMB30 = new TH1D("hnSigmaKaon_Data_VPDMB30", "hnSigmaKaon_Data_VPDMB30", 100, -10, 10);
    //=============================Track nSigmaProton========================================
    TH1D *hnSigmaProton_JP0VPDMB30 = new TH1D("hnSigmaProton_Data_JP0VPDMB30", "hnSigmaProton_Data_JP0VPDMB30", 100, -10, 10);
    TH1D *hnSigmaProton_JP1VPDMB30 = new TH1D("hnSigmaProton_Data_JP1VPDMB30", "hnSigmaProton_Data_JP1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaProton_JP2 = new TH1D("hnSigmaProton_Data_JP2", "hnSigmaProton_Data_JP2", 100, -10, 10);
    TH1D *hnSigmaProton_BHT3 = new TH1D("hnSigmaProton_Data_BHT3", "hnSigmaProton_Data_BHT3", 100, -10, 10);
    TH1D *hnSigmaProton_BHT1VPDMB30 = new TH1D("hnSigmaProton_Data_BHT1VPDMB30", "hnSigmaProton_Data_BHT1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaProton_BHT2BBCMB = new TH1D("hnSigmaProton_Data_BHT2BBCMB", "hnSigmaProton_Data_BHT2BBCMB", 100, -10, 10);
    TH1D *hnSigmaProton_JPsiHTTP = new TH1D("hnSigmaProton_Data_JPsiHTTP", "hnSigmaProton_Data_JPsiHTTP", 100, -10, 10);
    TH1D *hnSigmaProton_VPDMB30 = new TH1D("hnSigmaProton_Data_VPDMB30", "hnSigmaProton_Data_VPDMB30", 100, -10, 10);

    //=============================Track nSigmaElectron========================================
    TH1D *hnSigmaElectron_JP0VPDMB30 = new TH1D("hnSigmaElectron_Data_JP0VPDMB30", "hnSigmaElectron_Data_JP0VPDMB30", 100, -10, 10);
    TH1D *hnSigmaElectron_JP1VPDMB30 = new TH1D("hnSigmaElectron_Data_JP1VPDMB30", "hnSigmaElectron_Data_JP1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaElectron_JP2 = new TH1D("hnSigmaElectron_Data_JP2", "hnSigmaElectron_Data_JP2", 100, -10, 10);
    TH1D *hnSigmaElectron_BHT3 = new TH1D("hnSigmaElectron_Data_BHT3", "hnSigmaElectron_Data_BHT3", 100, -10, 10);
    TH1D *hnSigmaElectron_BHT1VPDMB30 = new TH1D("hnSigmaElectron_Data_BHT1VPDMB30", "hnSigmaElectron_Data_BHT1VPDMB30", 100, -10, 10);
    TH1D *hnSigmaElectron_BHT2BBCMB = new TH1D("hnSigmaElectron_Data_BHT2BBCMB", "hnSigmaElectron_Data_BHT2BBCMB", 100, -10, 10);
    TH1D *hnSigmaElectron_JPsiHTTP = new TH1D("hnSigmaElectron_Data_JPsiHTTP", "hnSigmaElectron_Data_JPsiHTTP", 100, -10, 10);
    TH1D *hnSigmaElectron_VPDMB30 = new TH1D("hnSigmaElectron_Data_VPDMB30", "hnSigmaElectron_Data_VPDMB30", 100, -10, 10);

    int ntry = fChain->GetEntries();
    cout << ntry << "\t to Entries in the Tree" << endl;

    // Event loop started
    for (int i = 0; i < ntry; i++)
    // for (int i = 0; i < 2000; i++)
    {

        if (i % 100000 == 0)
        {
            cout << "\t Event num\t" << i << endl;
        }
        fChain->GetEntry(i);
        if (fabs(fVZ) > 90)
            continue;

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
            // cout << ftrigger->at(trig) << "\t Trigger id\t "
            //<< "\t Event NUm\t" << i < <
            // endl;
            trigfile << ftrigger->at(trig) << endl;

            if (ftrigger->at(trig) == 570401)
            {

                trig_JP2 = 1;
                // cout << ftrigger->at(trig) << "\t JP2 trigger 570401\t" << trig_JP2 << "\t event\t" << i << endl;
                // cout << "Hello\t" << trig_JP2 << endl;

            } // JP2 trigger Flag
            // else if (ftrigger->at(trig) != 570403)
            if (ftrigger->at(trig) == 570403)
            {

                // cout << ftrigger->at(trig) << "\t JP1 trigger 570403\t" << trig_JP2 << "\t event\t" << i << endl;
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
                // cout << ftrigger->at(trig) << "\t JP0 trigger 570404\t" << trig_JP2 << "\t event\t" << i << endl;
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

            } // BHT3 trigger Flag
            if (ftrigger->at(trig) == 570215)
            {
                trig_BHT2BBCMB = 1;
            }

            if (ftrigger->at(trig) == 570214)
            {
                trig_BHT1VPDMB30 = 1;
            }

            if (ftrigger->at(trig) == 570229 || ftrigger->at(trig) == 570219 || ftrigger->at(trig) == 570209)
            {
                trig_JPsiHTTP = 1;
            }
            if (ftrigger->at(trig) == 570001)
            {
                trig_VPDMB30 = 1;
            }

        } // frigger Loop
        hVZ_noTrigSelec->Fill(fVZ);
        if (trig_JP2 != 1 && trig_JP0VPDMB30 != 1 && trig_JP1VPDMB30 != 1 && trig_BHT3 != 1 && trig_BHT1VPDMB30 != 1 && trig_BHT2BBCMB != 1 && trig_JPsiHTTP != 1 && trig_VPDMB30 != 1)
            continue;
        hVZ->Fill(fVZ);
        hfmaxpar->Fill(fmaxpar);
        if (trig_JP2 == 1)
        {
            hVZ_JP2->Fill(fVZ);
        }
        if (trig_BHT3 == 1)
        {
            hVZ_BHT3->Fill(fVZ);
        }

        if (trig_JP0VPDMB30 == 1)
        {
            hVZ_JP0VPDMB30->Fill(fVZ);
        }

        if (trig_JP1VPDMB30 == 1)
        {
            hVZ_JP1VPDMB30->Fill(fVZ);
        }

        if (trig_BHT1VPDMB30 == 1)
        {
            hVZ_BHT1VPDMB30->Fill(fVZ);
        }
        if (trig_BHT2BBCMB == 1)
        {
            hVZ_BHT2BBCMB->Fill(fVZ);
        }
        if (trig_JPsiHTTP == 1)
        {
            hVZ_JPsiHTTP->Fill(fVZ);
        }
        if (trig_VPDMB30 == 1)
        {
            hVZ_VPDMB30->Fill(fVZ);
        }

        for (int k = 0; k < fmaxpar; k++)
        {

            if (fp[k] < 2.0)
                continue;

            if (feta[k] >= 1 || feta[k] <= -1)
                continue;
            if (fdca[k] > 1.0)
                continue;
            if (ffitPts[k] < 15.0)
                continue;

            hpT->Fill(fpT[k]);
            heta->Fill(feta[k]);
            hphi->Fill(fphi[k]);
            hfitPts->Fill(ffitPts[k]);
            hfitPtsPoss->Fill(ffitPtsPoss[k]);
            hfhitsdedx->Fill(fhitsdedx[k]);
            hfdEdx->Fill(fdEdx[k]);
            hnSigmaPion->Fill(fnSigmaPion[k]);
            hnSigmaKaon->Fill(fnSigmaKaon[k]);
            hnSigmaProton->Fill(fnSigmaProton[k]);
            hnSigmaElectron->Fill(fnSigmaElectron[k]);

            if (trig_JP2 == 1)
            {
                hpT_JP2->Fill(fpT[k]);
                heta_JP2->Fill(feta[k]);
                hphi_JP2->Fill(fphi[k]);
                hfitPts_JP2->Fill(ffitPts[k]);
                hfitPtsPoss_JP2->Fill(ffitPtsPoss[k]);
                hfhitsdedx_JP2->Fill(fhitsdedx[k]);
                hfdEdx_JP2->Fill(fdEdx[k]);
                hnSigmaPion_JP2->Fill(fnSigmaPion[k]);
                hnSigmaKaon_JP2->Fill(fnSigmaKaon[k]);
                hnSigmaProton_JP2->Fill(fnSigmaProton[k]);
                hnSigmaElectron_JP2->Fill(fnSigmaElectron[k]);

            } // JP2 Trigger
            if (trig_JP0VPDMB30 == 1)
            {
                hpT_JP0VPDMB30->Fill(fpT[k]);
                heta_JP0VPDMB30->Fill(feta[k]);
                hphi_JP0VPDMB30->Fill(fphi[k]);
                hfitPts_JP0VPDMB30->Fill(ffitPts[k]);
                hfitPtsPoss_JP0VPDMB30->Fill(ffitPtsPoss[k]);
                hfhitsdedx_JP0VPDMB30->Fill(fhitsdedx[k]);
                hfdEdx_JP0VPDMB30->Fill(fdEdx[k]);
                hnSigmaPion_JP0VPDMB30->Fill(fnSigmaPion[k]);
                hnSigmaKaon_JP0VPDMB30->Fill(fnSigmaKaon[k]);
                hnSigmaProton_JP0VPDMB30->Fill(fnSigmaProton[k]);
                hnSigmaElectron_JP0VPDMB30->Fill(fnSigmaElectron[k]);
            }
            if (trig_JP1VPDMB30 == 1)
            {
                hpT_JP1VPDMB30->Fill(fpT[k]);
                heta_JP1VPDMB30->Fill(feta[k]);
                hphi_JP1VPDMB30->Fill(fphi[k]);
                hfitPts_JP1VPDMB30->Fill(ffitPts[k]);
                hfitPtsPoss_JP1VPDMB30->Fill(ffitPtsPoss[k]);
                hfhitsdedx_JP1VPDMB30->Fill(fhitsdedx[k]);
                hfdEdx_JP1VPDMB30->Fill(fdEdx[k]);
                hnSigmaPion_JP1VPDMB30->Fill(fnSigmaPion[k]);
                hnSigmaKaon_JP1VPDMB30->Fill(fnSigmaKaon[k]);
                hnSigmaProton_JP1VPDMB30->Fill(fnSigmaProton[k]);
                hnSigmaElectron_JP1VPDMB30->Fill(fnSigmaElectron[k]);
            }

            if (trig_BHT3 == 1)
            {
                hpT_BHT3->Fill(fpT[k]);
                heta_BHT3->Fill(feta[k]);
                hphi_BHT3->Fill(fphi[k]);
                hfitPts_BHT3->Fill(ffitPts[k]);
                hfitPtsPoss_BHT3->Fill(ffitPtsPoss[k]);
                hfhitsdedx_BHT3->Fill(fhitsdedx[k]);
                hfdEdx_BHT3->Fill(fdEdx[k]);
                hnSigmaPion_BHT3->Fill(fnSigmaPion[k]);
                hnSigmaKaon_BHT3->Fill(fnSigmaKaon[k]);
                hnSigmaProton_BHT3->Fill(fnSigmaProton[k]);
                hnSigmaElectron_BHT3->Fill(fnSigmaElectron[k]);
            } // BHT3 Trigger

            if (trig_BHT1VPDMB30 == 1)
            {
                hpT_BHT1VPDMB30->Fill(fpT[k]);
                heta_BHT1VPDMB30->Fill(feta[k]);
                hphi_BHT1VPDMB30->Fill(fphi[k]);
                hfitPts_BHT1VPDMB30->Fill(ffitPts[k]);
                hfitPtsPoss_BHT1VPDMB30->Fill(ffitPtsPoss[k]);
                hfhitsdedx_BHT1VPDMB30->Fill(fhitsdedx[k]);
                hfdEdx_BHT1VPDMB30->Fill(fdEdx[k]);
                hnSigmaPion_BHT1VPDMB30->Fill(fnSigmaPion[k]);
                hnSigmaKaon_BHT1VPDMB30->Fill(fnSigmaKaon[k]);
                hnSigmaProton_BHT1VPDMB30->Fill(fnSigmaProton[k]);
                hnSigmaElectron_BHT1VPDMB30->Fill(fnSigmaElectron[k]);
            }
            if (trig_BHT2BBCMB == 1)
            {
                hpT_BHT2BBCMB->Fill(fpT[k]);
                heta_BHT2BBCMB->Fill(feta[k]);
                hphi_BHT2BBCMB->Fill(fphi[k]);
                hfitPts_BHT2BBCMB->Fill(ffitPts[k]);
                hfitPtsPoss_BHT2BBCMB->Fill(ffitPtsPoss[k]);
                hfhitsdedx_BHT2BBCMB->Fill(fhitsdedx[k]);
                hfdEdx_BHT2BBCMB->Fill(fdEdx[k]);
                hnSigmaPion_BHT2BBCMB->Fill(fnSigmaPion[k]);
                hnSigmaKaon_BHT2BBCMB->Fill(fnSigmaKaon[k]);
                hnSigmaProton_BHT2BBCMB->Fill(fnSigmaProton[k]);
                hnSigmaElectron_BHT2BBCMB->Fill(fnSigmaElectron[k]);
            }
            if (trig_JPsiHTTP == 1)
            {
                hpT_JPsiHTTP->Fill(fpT[k]);
                heta_JPsiHTTP->Fill(feta[k]);
                hphi_JPsiHTTP->Fill(fphi[k]);
                hfitPts_JPsiHTTP->Fill(ffitPts[k]);
                hfitPtsPoss_JPsiHTTP->Fill(ffitPtsPoss[k]);
                hfhitsdedx_JPsiHTTP->Fill(fhitsdedx[k]);
                hfdEdx_JPsiHTTP->Fill(fdEdx[k]);
                hnSigmaPion_JPsiHTTP->Fill(fnSigmaPion[k]);
                hnSigmaKaon_JPsiHTTP->Fill(fnSigmaKaon[k]);
                hnSigmaProton_JPsiHTTP->Fill(fnSigmaProton[k]);
                hnSigmaElectron_JPsiHTTP->Fill(fnSigmaElectron[k]);
            }
            if (trig_VPDMB30 == 1)
            {
                hpT_VPDMB30->Fill(fpT[k]);
                heta_VPDMB30->Fill(feta[k]);
                hphi_VPDMB30->Fill(fphi[k]);
                hfitPts_VPDMB30->Fill(ffitPts[k]);
                hfitPtsPoss_VPDMB30->Fill(ffitPtsPoss[k]);
                hfhitsdedx_VPDMB30->Fill(fhitsdedx[k]);
                hfdEdx_VPDMB30->Fill(fdEdx[k]);
                hnSigmaPion_VPDMB30->Fill(fnSigmaPion[k]);
                hnSigmaKaon_VPDMB30->Fill(fnSigmaKaon[k]);
                hnSigmaProton_VPDMB30->Fill(fnSigmaProton[k]);
                hnSigmaElectron_VPDMB30->Fill(fnSigmaElectron[k]);
            }

        } // Track loop
    }     // Event loop
    outfile->Write();
    outfile->Close();
    trigfile.close();
}
