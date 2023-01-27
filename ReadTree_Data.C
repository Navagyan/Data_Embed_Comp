// void ReadTree_Data(const char *tree, const char *ofile,const char* jobid) //xml (or grid mode)
 void ReadTree_Data(const char *tree="/star/u/nghimire/GPFS/Embed_Run17_New/Data_RawTree_Test/AddedTree/RawDataTree_iff.root", const char *ofile="ReadTree_Data_SL22b.root")//Interactive

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
    //int ffitPtsPoss[fMaxHit];

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

    TH1D *hVZ = new TH1D("hVZ", "hVZ", 125, -90, 90);
    // TH1D *hVZ_JP0 = new TH1D("hVZ_JP0","hVZ_JP0",125,-90,90);
    // TH1D *hVZ_JP1 = new TH1D("hVZ_JP1","hVZ_JP1",125,-90,90);
    TH1D *hVZ_JP2 = new TH1D("hVZ_JP2", "hVZ_JP2", 125, -90, 90);
    TH1D *hVZ_BHT3 = new TH1D("hVZ_BHT3", "hVZ_BHT3", 125, -90, 90);
 
    TH1D *hpT = new TH1D("pT", "pT", 100, 0, 40);
    TH1D *hpT_JP2 = new TH1D("pT_JP2", "pT_JP2", 100, 0, 40);
    TH1D *hpT_BHT3 = new TH1D("pT_BHT3", "pT_BHT3", 100, 0, 40);
 
    TH1D *heta = new TH1D("h_eta", "h_eta", 100, -1.4, 1.4);
    TH1D *heta_JP2 = new TH1D("h_eta_JP2", "h_eta_JP2", 100, -1.4, 1.4);
    TH1D *heta_BHT3 = new TH1D("h_eta_BHT3", "h_eta_BHT3", 100, -1.4, 1.4);
 
    TH1D *hphi = new TH1D("h_phi", "h_phi", 100, -3.4, 3.4);
    TH1D *hphi_JP2 = new TH1D("h_phi_JP2", "h_phi_JP2", 100, -3.4, 3.4);
    TH1D *hphi_BHT3 = new TH1D("h_phi_BHT3", "h_phi_BHT3", 100, -3.4, 3.4);
 
    TH1D *hfitPts = new TH1D("h_fitPts", "h_fitPts", 60, 0, 60);
    TH1D *hfitPts_JP2 = new TH1D("h_fitPts_JP2", "h_fitPts_JP2", 60, 0, 60);
    TH1D *hfitPts_BHT3 = new TH1D("h_fitPts_BHT3", "h_fitPts_BHT3", 60, 0, 60);
    TH1D *hfitPtsPoss = new TH1D("h_fitPtsPoss", "h_fitPtsPoss", 60, 0, 60);
    TH1D *hfitPtsPoss_JP2 = new TH1D("h_fitPtsPoss_JP2", "h_fitPtsPoss_JP2", 60, 0, 60);
    TH1D *hfitPtsPoss_BHT3 = new TH1D("h_fitPtsPoss_BHT3", "h_fitPtsPoss_BHT3", 60, 0, 60);

    TH1D *hfmaxpar = new TH1D("hfmaxpar","fmaxpar",120,0,120);
    TH1D *hfmaxpar_JP2 = new TH1D("hfmaxpar_JP2","fmaxpar_JP2",120,0,120);
    TH1D *hfmaxpar_BHT3 = new TH1D("hfmaxpar_BHT3","fmaxpar_BHT3",120,0,120);
    
    
    int ntry = fChain->GetEntries();
    cout << ntry << "\t to Entries in the Tree" << endl;

    //Event loop started
    for (int i = 0; i < ntry; i++)
    {
        fChain->GetEntry(i);
        if (fabs(fVZ) > 90)
            continue;
        int trig_JP0 = 0;
        int trig_JP1 = 0;
        int trig_JP2 = 0;
        int trig_BHT3 = 0;
        for (int trig = 0; trig < ftrigger->size(); trig++)
        {
            trigfile << ftrigger->at(trig) << endl;
            if (ftrigger->at(trig) == 570401)
            {
                trig_JP2 = 1;
            }
            if (ftrigger->at(trig) == 570201)
            {
                trig_BHT3 = 1;
            }
            // if(ftrigger->at(trig)==570403) {trig_JP1=1;}
            // if(ftrigger->at(trig)==570404) {trig_JP0=1;}
        }


        hVZ->Fill(fVZ);
        hfmaxpar->Fill(fmaxpar);
        if (trig_JP2)
        {
            hVZ_JP2->Fill(fVZ);
            hfmaxpar_JP2->Fill(fmaxpar); }
        if (trig_BHT3)
        {
            hVZ_BHT3->Fill(fVZ);
            hfmaxpar_BHT3->Fill(fmaxpar); 
        }
        // if(trig_JP1){hVZ_JP1->Fill(fVZ);}
        // if(trig_JP0){hVZ_JP0->Fill(fVZ);}

        for (int k = 0; k < fmaxpar; k++)
        {

            if (fp[k] < 2.0)
                continue;
            //if (fpT[k] < 5.0)
            //    continue;
            if (feta[k] >= 1 || feta[k] <= -1)
                continue;
            if (fdca[k] > 1.0)
                continue;   
            if(ffitPts[k]<15.0) 
                continue;

            hpT->Fill(fpT[k]);
            heta->Fill(feta[k]);
            hphi->Fill(fphi[k]);
            hfitPts->Fill(ffitPts[k]);
            hfitPtsPoss->Fill(ffitPtsPoss[k]);

            if (trig_JP2==1)
            {
                hpT_JP2->Fill(fpT[k]);
                heta_JP2->Fill(feta[k]);
                hphi_JP2->Fill(fphi[k]);
                hfitPts_JP2->Fill(ffitPts[k]);
                hfitPtsPoss_JP2->Fill(ffitPtsPoss[k]);

            } // JP2 Trigger

            if (trig_BHT3==1)
            {
                hpT_BHT3->Fill(fpT[k]);
                heta_BHT3->Fill(feta[k]);
                hphi_BHT3->Fill(fphi[k]);
                hfitPts_BHT3->Fill(ffitPts[k]);
                hfitPtsPoss_BHT3->Fill(ffitPtsPoss[k]);
            } // BHT3 Trigger
        }     // Track loop
    }         // Event loop
    outfile->Write();
    outfile->Close();
    trigfile.close();
    }
