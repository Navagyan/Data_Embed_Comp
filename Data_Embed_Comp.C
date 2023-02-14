#include <iostream>
#include <fstream>
#include <string>

void Data_Embed_Comp(const char *data, const char *embed)
{
    // TFile *data_file = new TFile("/star/u/nghimire/pp500/IFF_Run17/PID/triggerBias/TreeProduction/PionPairStudy_NewTest/ReadTree_Test.root");
    TFile *data_file = new TFile(data);
    TFile *embed_file = new TFile(embed);
    // Data
    // No Trig Seperated
    // Event Level
    TH1D *hData_VZ_noTrigSelec = (TH1D *)data_file->Get("hVZ_Data_noTrigSelec");
    TH1D *hData_VZ = (TH1D *)data_file->Get("hVZ_Data");
    // Track Level
    TH1D *hData_pT = (TH1D *)data_file->Get("pT_Data");
    TH1D *hData_eta = (TH1D *)data_file->Get("heta_Data");
    TH1D *hData_phi = (TH1D *)data_file->Get("hphi_Data");
    TH1D *hData_fitPts = (TH1D *)data_file->Get("hfitPts_Data");
    TH1D *hData_fitPtsPoss = (TH1D *)data_file->Get("hfitPtsPoss_Data");
    TH1D *hData_fmaxpar = (TH1D *)data_file->Get("hfmaxpar_Data");
    TH1D *hData_fhitsdedx = (TH1D *)data_file->Get("hfhitsdedx_Data");
    TH1D *hData_fdEdx = (TH1D *)data_file->Get("hfdEdx_Data");
    TH1D *hData_nSigmaPion = (TH1D *)data_file->Get("hfnSigmaPion_Data");
    TH1D *hData_nSigmaKaon = (TH1D *)data_file->Get("hfnSigmaKaon_Data");
    TH1D *hData_nSigmaProton = (TH1D *)data_file->Get("hfnSigmaProton_Data");
    TH1D *hData_nSigmaElectron = (TH1D *)data_file->Get("hfnSigmaElectron_Data");

    // Trig Separated
    // Event Level
    TH1D *hData_VZ_JP0VPDMB30 = (TH1D *)data_file->Get("hVZ_Data_JP0VPDMB30");
    TH1D *hData_VZ_JP1VPDMB30 = (TH1D *)data_file->Get("hVZ_Data_JP1VPDMB30");
    TH1D *hData_VZ_JP2 = (TH1D *)data_file->Get("hVZ_Data_JP2");
    TH1D *hData_VZ_BHT3 = (TH1D *)data_file->Get("hVZ_Data_BHT3");
    TH1D *hData_VZ_BHT1VPDMB30 = (TH1D *)data_file->Get("hVZ_Data_BHT1VPDMB30");
    TH1D *hData_VZ_BHT2BBCMB = (TH1D *)data_file->Get("hVZ_Data_BHT2BBCMB");
    TH1D *hData_VZ_JPsiHTTP = (TH1D *)data_file->Get("hVZ_Data_JPsiHTTP");
    TH1D *hData_VZ_VPDMB30 = (TH1D *)data_file->Get("hVZ_Data_VPDMB30");
    TH1D *hData_VZ_JP0VPDMBLt30 = (TH1D *)data_file->Get("hVZ_Data_JP0VPDMBLt30");
    TH1D *hData_VZ_JP0VPDMBGt30 = (TH1D *)data_file->Get("hVZ_Data_JP0VPDMBGt30");
    TH1D *hData_VZ_JP1VPDMBLt30 = (TH1D *)data_file->Get("hVZ_Data_JP1VPDMBLt30");
    TH1D *hData_VZ_JP1VPDMBGt30 = (TH1D *)data_file->Get("hVZ_Data_JP1VPDMBGt30");

    // Track Level
    //=============================Track pT========================================
    TH1D *hData_pT_JP0VPDMB30 = (TH1D *)data_file->Get("pT_Data_JP0VPDMB30");
    TH1D *hData_pT_JP1VPDMB30 = (TH1D *)data_file->Get("pT_Data_JP1VPDMB30");
    TH1D *hData_pT_JP2 = (TH1D *)data_file->Get("pT_Data_JP2");
    TH1D *hData_pT_BHT3 = (TH1D *)data_file->Get("pT_Data_BHT3");
    TH1D *hData_pT_BHT1VPDMB30 = (TH1D *)data_file->Get("pT_Data_BHT1VPDMB30");
    TH1D *hData_pT_BHT2BBCMB = (TH1D *)data_file->Get("pT_Data_BHT2BBCMB");
    TH1D *hData_pT_JPsiHTTP = (TH1D *)data_file->Get("pT_Data_JPsiHTTP");
    TH1D *hData_pT_VPDMB30 = (TH1D *)data_file->Get("pT_Data_VPDMB30");
    //=============================Track eta========================================
    TH1D *hData_eta_JP0VPDMB30 = (TH1D *)data_file->Get("heta_Data_JP0VPDMB30");
    TH1D *hData_eta_JP1VPDMB30 = (TH1D *)data_file->Get("heta_Data_JP1VPDMB30");
    TH1D *hData_eta_JP2 = (TH1D *)data_file->Get("heta_Data_JP2");
    TH1D *hData_eta_BHT3 = (TH1D *)data_file->Get("heta_Data_BHT3");
    TH1D *hData_eta_BHT1VPDMB30 = (TH1D *)data_file->Get("heta_Data_BHT1VPDMB30");
    TH1D *hData_eta_BHT2BBCMB = (TH1D *)data_file->Get("heta_Data_BHT2BBCMB");
    TH1D *hData_eta_JPsiHTTP = (TH1D *)data_file->Get("heta_Data_JPsiHTTP");
    TH1D *hData_eta_VPDMB30 = (TH1D *)data_file->Get("heta_Data_VPDMB30");
    //=============================Track phi========================================
    TH1D *hData_phi_JP0VPDMB30 = (TH1D *)data_file->Get("hphi_Data_JP0VPDMB30");
    TH1D *hData_phi_JP1VPDMB30 = (TH1D *)data_file->Get("hphi_Data_JP1VPDMB30");
    TH1D *hData_phi_JP2 = (TH1D *)data_file->Get("hphi_Data_JP2");
    TH1D *hData_phi_BHT3 = (TH1D *)data_file->Get("hphi_Data_BHT3");
    TH1D *hData_phi_BHT1VPDMB30 = (TH1D *)data_file->Get("hphi_Data_BHT1VPDMB30");
    TH1D *hData_phi_BHT2BBCMB = (TH1D *)data_file->Get("hphi_Data_BHT2BBCMB");
    TH1D *hData_phi_JPsiHTTP = (TH1D *)data_file->Get("hphi_Data_JPsiHTTP");
    TH1D *hData_phi_VPDMB30 = (TH1D *)data_file->Get("hphi_Data_VPDMB30");
    //=============================Track fitPts========================================
    TH1D *hData_fitPts_JP0VPDMB30 = (TH1D *)data_file->Get("hfitPts_Data_JP0VPDMB30");
    TH1D *hData_fitPts_JP1VPDMB30 = (TH1D *)data_file->Get("hfitPts_Data_JP1VPDMB30");
    TH1D *hData_fitPts_JP2 = (TH1D *)data_file->Get("hfitPts_Data_JP2");
    TH1D *hData_fitPts_BHT3 = (TH1D *)data_file->Get("hfitPts_Data_BHT3");
    TH1D *hData_fitPts_BHT1VPDMB30 = (TH1D *)data_file->Get("hfitPts_Data_BHT1VPDMB30");
    TH1D *hData_fitPts_BHT2BBCMB = (TH1D *)data_file->Get("hfitPts_Data_BHT2BBCMB");
    TH1D *hData_fitPts_JPsiHTTP = (TH1D *)data_file->Get("hfitPts_Data_JPsiHTTP");
    TH1D *hData_fitPts_VPDMB30 = (TH1D *)data_file->Get("hfitPts_Data_VPDMB30");
    //=============================Track fitPtsPss========================================
    TH1D *hData_fitPtsPoss_JP0VPDMB30 = (TH1D *)data_file->Get("hfitPtsPoss_Data_JP0VPDMB30");
    TH1D *hData_fitPtsPoss_JP1VPDMB30 = (TH1D *)data_file->Get("hfitPtsPoss_Data_JP1VPDMB30");
    TH1D *hData_fitPtsPoss_JP2 = (TH1D *)data_file->Get("hfitPtsPoss_Data_JP2");
    TH1D *hData_fitPtsPoss_BHT3 = (TH1D *)data_file->Get("hfitPtsPoss_Data_BHT3");
    TH1D *hData_fitPtsPoss_BHT1VPDMB30 = (TH1D *)data_file->Get("hfitPtsPoss_Data_BHT1VPDMB30");
    TH1D *hData_fitPtsPoss_BHT2BBCMB = (TH1D *)data_file->Get("hfitPtsPoss_Data_BHT2BBCMB");
    TH1D *hData_fitPtsPoss_JPsiHTTP = (TH1D *)data_file->Get("hfitPtsPoss_Data_JPsiHTTP");
    TH1D *hData_fitPtsPoss_VPDMB30 = (TH1D *)data_file->Get("hfitPtsPoss_Data_VPDMB30");
    //=============================Track hitsdedx========================================
    TH1D *hData_fhitsdedx_JP0VPDMB30 = (TH1D *)data_file->Get("hfhitsdedx_Data_JP0VPDMB30");
    TH1D *hData_fhitsdedx_JP1VPDMB30 = (TH1D *)data_file->Get("hfhitsdedx_Data_JP1VPDMB30");
    TH1D *hData_fhitsdedx_JP2 = (TH1D *)data_file->Get("hfhitsdedx_Data_JP2");
    TH1D *hData_fhitsdedx_BHT3 = (TH1D *)data_file->Get("hfhitsdedx_Data_BHT3");
    TH1D *hData_fhitsdedx_BHT1VPDMB30 = (TH1D *)data_file->Get("hfhitsdedx_Data_BHT1VPDMB30");
    TH1D *hData_fhitsdedx_BHT2BBCMB = (TH1D *)data_file->Get("hfhitsdedx_Data_BHT2BBCMB");
    TH1D *hData_fhitsdedx_JPsiHTTP = (TH1D *)data_file->Get("hfhitsdedx_Data_JPsiHTTP");
    TH1D *hData_fhitsdedx_VPDMB30 = (TH1D *)data_file->Get("hfhitsdedx_Data_VPDMB30");
    //=============================Track dEdx========================================
    TH1D *hData_fdEdx_JP0VPDMB30 = (TH1D *)data_file->Get("hfdEdx_Data_JP0VPDMB30");
    TH1D *hData_fdEdx_JP1VPDMB30 = (TH1D *)data_file->Get("hfdEdx_Data_JP1VPDMB30");
    TH1D *hData_fdEdx_JP2 = (TH1D *)data_file->Get("hfdEdx_Data_JP2");
    TH1D *hData_fdEdx_BHT3 = (TH1D *)data_file->Get("hfdEdx_Data_BHT3");
    TH1D *hData_fdEdx_BHT1VPDMB30 = (TH1D *)data_file->Get("hfdEdx_Data_BHT1VPDMB30");
    TH1D *hData_fdEdx_BHT2BBCMB = (TH1D *)data_file->Get("hfdEdx_Data_BHT2BBCMB");
    TH1D *hData_fdEdx_JPsiHTTP = (TH1D *)data_file->Get("hfdEdx_Data_JPsiHTTP");
    TH1D *hData_fdEdx_VPDMB30 = (TH1D *)data_file->Get("hfdEdx_Data_VPDMB30");
    //=============================Track nSigmaPion========================================
    TH1D *hData_nSigmaPion_JP0VPDMB30 = (TH1D *)data_file->Get("hnSigmaPion_Data_JP0VPDMB30");
    TH1D *hData_nSigmaPion_JP1VPDMB30 = (TH1D *)data_file->Get("hnSigmaPion_Data_JP1VPDMB30");
    TH1D *hData_nSigmaPion_JP2 = (TH1D *)data_file->Get("hnSigmaPion_Data_JP2");
    TH1D *hData_nSigmaPion_BHT3 = (TH1D *)data_file->Get("hnSigmaPion_Data_BHT3");
    TH1D *hData_nSigmaPion_BHT1VPDMB30 = (TH1D *)data_file->Get("hnSigmaPion_Data_BHT1VPDMB30");
    TH1D *hData_nSigmaPion_BHT2BBCMB = (TH1D *)data_file->Get("hnSigmaPion_Data_BHT2BBCMB");
    TH1D *hData_nSigmaPion_JPsiHTTP = (TH1D *)data_file->Get("hnSigmaPion_Data_JPsiHTTP");
    TH1D *hData_nSigmaPion_VPDMB30 = (TH1D *)data_file->Get("hnSigmaPion_Data_VPDMB30");

    //=============================Track nSigmaKaon========================================
    TH1D *hData_nSigmaKaon_JP0VPDMB30 = (TH1D *)data_file->Get("hnSigmaKaon_Data_JP0VPDMB30");
    TH1D *hData_nSigmaKaon_JP1VPDMB30 = (TH1D *)data_file->Get("hnSigmaKaon_Data_JP1VPDMB30");
    TH1D *hData_nSigmaKaon_JP2 = (TH1D *)data_file->Get("hnSigmaKaon_Data_JP2");
    TH1D *hData_nSigmaKaon_BHT3 = (TH1D *)data_file->Get("hnSigmaKaon_Data_BHT3");
    TH1D *hData_nSigmaKaon_BHT1VPDMB30 = (TH1D *)data_file->Get("hnSigmaKaon_Data_BHT1VPDMB30");
    TH1D *hData_nSigmaKaon_BHT2BBCMB = (TH1D *)data_file->Get("hnSigmaKaon_Data_BHT2BBCMB");
    TH1D *hData_nSigmaKaon_JPsiHTTP = (TH1D *)data_file->Get("hnSigmaKaon_Data_JPsiHTTP");
    TH1D *hData_nSigmaKaon_VPDMB30 = (TH1D *)data_file->Get("hnSigmaKaon_Data_VPDMB30");
    //=============================Track nSigmaProton========================================
    TH1D *hData_nSigmaProton_JP0VPDMB30 = (TH1D *)data_file->Get("hnSigmaProton_Data_JP0VPDMB30");
    TH1D *hData_nSigmaProton_JP1VPDMB30 = (TH1D *)data_file->Get("hnSigmaProton_Data_JP1VPDMB30");
    TH1D *hData_nSigmaProton_JP2 = (TH1D *)data_file->Get("hnSigmaProton_Data_JP2");
    TH1D *hData_nSigmaProton_BHT3 = (TH1D *)data_file->Get("hnSigmaProton_Data_BHT3");
    TH1D *hData_nSigmaProton_BHT1VPDMB30 = (TH1D *)data_file->Get("hnSigmaProton_Data_BHT1VPDMB30");
    TH1D *hData_nSigmaProton_BHT2BBCMB = (TH1D *)data_file->Get("hnSigmaProton_Data_BHT2BBCMB");
    TH1D *hData_nSigmaProton_JPsiHTTP = (TH1D *)data_file->Get("hnSigmaProton_Data_JPsiHTTP");
    TH1D *hData_nSigmaProton_VPDMB30 = (TH1D *)data_file->Get("hnSigmaProton_Data_VPDMB30");

    //=============================Track nSigmaElectron========================================
    TH1D *hData_nSigmaElectron_JP0VPDMB30 = (TH1D *)data_file->Get("hnSigmaElectron_Data_JP0VPDMB30");
    TH1D *hData_nSigmaElectron_JP1VPDMB30 = (TH1D *)data_file->Get("hnSigmaElectron_Data_JP1VPDMB30");
    TH1D *hData_nSigmaElectron_JP2 = (TH1D *)data_file->Get("hnSigmaElectron_Data_JP2");
    TH1D *hData_nSigmaElectron_BHT3 = (TH1D *)data_file->Get("hnSigmaElectron_Data_BHT3");
    TH1D *hData_nSigmaElectron_BHT1VPDMB30 = (TH1D *)data_file->Get("hnSigmaElectron_Data_BHT1VPDMB30");
    TH1D *hData_nSigmaElectron_BHT2BBCMB = (TH1D *)data_file->Get("hnSigmaElectron_Data_BHT2BBCMB");
    TH1D *hData_nSigmaElectron_JPsiHTTP = (TH1D *)data_file->Get("hnSigmaElectron_Data_JPsiHTTP");
    TH1D *hData_nSigmaElectron_VPDMB30 = (TH1D *)data_file->Get("hnSigmaElectron_Data_VPDMB30");

    //============================= Embedding ========================================
    TH1D *hEmbed_VZ = (TH1D *)embed_file->Get("hVZ_Embed");
    TH1D *hEmbed_VZ_wt = (TH1D *)embed_file->Get("hVZ_Embed_wt");
    TH2D *hEmbed_VZ_vs_hVZ_pyth = (TH2D *)embed_file->Get("hVZ_vs_hVZ_pyth");
    TH1D *hEmbed_Ver_diff = (TH1D *)embed_file->Get("hVZ_hVZ_pyth");

    // Track Level
    TH1D *hEmbed_pT_wt = (TH1D *)embed_file->Get("pT_Embed_wt");
    TH1D *hEmbed_partonicpT_wt = (TH1D *)embed_file->Get("partonicpT_Embed_weighted");

    TH1D *hEmbed_pT_noptwt = (TH1D *)embed_file->Get("pT_Embed_noptwt");
    TH1D *hEmbed_pT = (TH1D *)embed_file->Get("pT_Embed");
    TH1D *hEmbed_eta = (TH1D *)embed_file->Get("heta_Embed");
    TH1D *hEmbed_phi = (TH1D *)embed_file->Get("hphi_Embed");
    TH1D *hEmbed_fitPts = (TH1D *)embed_file->Get("hfitPts_Embed");
    TH1D *hEmbed_fitPtsPoss = (TH1D *)embed_file->Get("hfitPtsPoss_Embed");
    TH1D *hEmbed_fmaxpar = (TH1D *)embed_file->Get("hfmaxpar_Embed");

    TH1D *hEmbed_fhitsdedx = (TH1D *)embed_file->Get("hfhitsdedx_Embed");
    TH1D *hEmbed_fdEdx = (TH1D *)embed_file->Get("hfdEdx_Embed");
    TH1D *hEmbed_nSigmaPion = (TH1D *)embed_file->Get("hfnSigmaPion_Embed");
    TH1D *hEmbed_nSigmaKaon = (TH1D *)embed_file->Get("hfnSigmaKaon_Embed");
    TH1D *hEmbed_nSigmaProton = (TH1D *)embed_file->Get("hfnSigmaProton_Embed");
    TH1D *hEmbed_nSigmaElectron = (TH1D *)embed_file->Get("hfnSigmaElectron_Embed");

    // Trig Separated
    // Event Level
    TH1D *hEmbed_VZ_JP0VPDMB30 = (TH1D *)embed_file->Get("hVZ_Embed_JP0VPDMB30");
    TH1D *hEmbed_VZ_JP1VPDMB30 = (TH1D *)embed_file->Get("hVZ_Embed_JP1VPDMB30");
    TH1D *hEmbed_VZ_JP2 = (TH1D *)embed_file->Get("hVZ_Embed_JP2");
    TH1D *hEmbed_VZ_BHT3 = (TH1D *)embed_file->Get("hVZ_Embed_BHT3");
    TH1D *hEmbed_VZ_BHT1VPDMB30 = (TH1D *)embed_file->Get("hVZ_Embed_BHT1VPDMB30");
    TH1D *hEmbed_VZ_BHT2BBCMB = (TH1D *)embed_file->Get("hVZ_Embed_BHT2BBCMB");
    TH1D *hEmbed_VZ_JPsiHTTP = (TH1D *)embed_file->Get("hVZ_Embed_JPsiHTTP");
    TH1D *hEmbed_VZ_VPDMB30 = (TH1D *)embed_file->Get("hVZ_Embed_VPDMB30");
    TH1D *hEmbed_VZ_JP0VPDMBLt30 = (TH1D *)embed_file->Get("hVZ_Embed_JP0VPDMBLt30");
    TH1D *hEmbed_VZ_JP0VPDMBGt30 = (TH1D *)embed_file->Get("hVZ_Embed_JP0VPDMBGt30");
    TH1D *hEmbed_VZ_JP1VPDMBLt30 = (TH1D *)embed_file->Get("hVZ_Embed_JP1VPDMBLt30");
    TH1D *hEmbed_VZ_JP1VPDMBGt30 = (TH1D *)embed_file->Get("hVZ_Embed_JP1VPDMBGt30");

    // Track Level
    //=============================Track pT========================================
    TH1D *hEmbed_pT_JP0VPDMB30 = (TH1D *)embed_file->Get("pT_Embed_JP0VPDMB30");
    TH1D *hEmbed_pT_JP1VPDMB30 = (TH1D *)embed_file->Get("pT_Embed_JP1VPDMB30");
    TH1D *hEmbed_pT_JP2 = (TH1D *)embed_file->Get("pT_Embed_JP2");
    TH1D *hEmbed_pT_BHT3 = (TH1D *)embed_file->Get("pT_Embed_BHT3");
    TH1D *hEmbed_pT_BHT1VPDMB30 = (TH1D *)embed_file->Get("pT_Embed_BHT1VPDMB30");
    TH1D *hEmbed_pT_BHT2BBCMB = (TH1D *)embed_file->Get("pT_Embed_BHT2BBCMB");
    TH1D *hEmbed_pT_JPsiHTTP = (TH1D *)embed_file->Get("pT_Embed_JPsiHTTP");
    TH1D *hEmbed_pT_VPDMB30 = (TH1D *)embed_file->Get("pT_Embed_VPDMB30");
    //=============================Track eta========================================
    TH1D *hEmbed_eta_JP0VPDMB30 = (TH1D *)embed_file->Get("heta_Embed_JP0VPDMB30");
    TH1D *hEmbed_eta_JP1VPDMB30 = (TH1D *)embed_file->Get("heta_Embed_JP1VPDMB30");
    TH1D *hEmbed_eta_JP2 = (TH1D *)embed_file->Get("heta_Embed_JP2");
    TH1D *hEmbed_eta_BHT3 = (TH1D *)embed_file->Get("heta_Embed_BHT3");
    TH1D *hEmbed_eta_BHT1VPDMB30 = (TH1D *)embed_file->Get("heta_Embed_BHT1VPDMB30");
    TH1D *hEmbed_eta_BHT2BBCMB = (TH1D *)embed_file->Get("heta_Embed_BHT2BBCMB");
    TH1D *hEmbed_eta_JPsiHTTP = (TH1D *)embed_file->Get("heta_Embed_JPsiHTTP");
    TH1D *hEmbed_eta_VPDMB30 = (TH1D *)embed_file->Get("heta_Embed_VPDMB30");
    //=============================Track phi========================================
    TH1D *hEmbed_phi_JP0VPDMB30 = (TH1D *)embed_file->Get("hphi_Embed_JP0VPDMB30");
    TH1D *hEmbed_phi_JP1VPDMB30 = (TH1D *)embed_file->Get("hphi_Embed_JP1VPDMB30");
    TH1D *hEmbed_phi_JP2 = (TH1D *)embed_file->Get("hphi_Embed_JP2");
    TH1D *hEmbed_phi_BHT3 = (TH1D *)embed_file->Get("hphi_Embed_BHT3");
    TH1D *hEmbed_phi_BHT1VPDMB30 = (TH1D *)embed_file->Get("hphi_Embed_BHT1VPDMB30");
    TH1D *hEmbed_phi_BHT2BBCMB = (TH1D *)embed_file->Get("hphi_Embed_BHT2BBCMB");
    TH1D *hEmbed_phi_JPsiHTTP = (TH1D *)embed_file->Get("hphi_Embed_JPsiHTTP");
    TH1D *hEmbed_phi_VPDMB30 = (TH1D *)embed_file->Get("hphi_Embed_VPDMB30");
    //=============================Track fitPts========================================
    TH1D *hEmbed_fitPts_JP0VPDMB30 = (TH1D *)embed_file->Get("hfitPts_Embed_JP0VPDMB30");
    TH1D *hEmbed_fitPts_JP1VPDMB30 = (TH1D *)embed_file->Get("hfitPts_Embed_JP1VPDMB30");
    TH1D *hEmbed_fitPts_JP2 = (TH1D *)embed_file->Get("hfitPts_Embed_JP2");
    TH1D *hEmbed_fitPts_BHT3 = (TH1D *)embed_file->Get("hfitPts_Embed_BHT3");
    TH1D *hEmbed_fitPts_BHT1VPDMB30 = (TH1D *)embed_file->Get("hfitPts_Embed_BHT1VPDMB30");
    TH1D *hEmbed_fitPts_BHT2BBCMB = (TH1D *)embed_file->Get("hfitPts_Embed_BHT2BBCMB");
    TH1D *hEmbed_fitPts_JPsiHTTP = (TH1D *)embed_file->Get("hfitPts_Embed_JPsiHTTP");
    TH1D *hEmbed_fitPts_VPDMB30 = (TH1D *)embed_file->Get("hfitPts_Embed_VPDMB30");
    //=============================Track fitPtsPss========================================
    TH1D *hEmbed_fitPtsPoss_JP0VPDMB30 = (TH1D *)embed_file->Get("hfitPtsPoss_Embed_JP0VPDMB30");
    TH1D *hEmbed_fitPtsPoss_JP1VPDMB30 = (TH1D *)embed_file->Get("hfitPtsPoss_Embed_JP1VPDMB30");
    TH1D *hEmbed_fitPtsPoss_JP2 = (TH1D *)embed_file->Get("hfitPtsPoss_Embed_JP2");
    TH1D *hEmbed_fitPtsPoss_BHT3 = (TH1D *)embed_file->Get("hfitPtsPoss_Embed_BHT3");
    TH1D *hEmbed_fitPtsPoss_BHT1VPDMB30 = (TH1D *)embed_file->Get("hfitPtsPoss_Embed_BHT1VPDMB30");
    TH1D *hEmbed_fitPtsPoss_BHT2BBCMB = (TH1D *)embed_file->Get("hfitPtsPoss_Embed_BHT2BBCMB");
    TH1D *hEmbed_fitPtsPoss_JPsiHTTP = (TH1D *)embed_file->Get("hfitPtsPoss_Embed_JPsiHTTP");
    TH1D *hEmbed_fitPtsPoss_VPDMB30 = (TH1D *)embed_file->Get("hfitPtsPoss_Embed_VPDMB30");
    //=============================Track hitsdedx========================================
    TH1D *hEmbed_fhitsdedx_JP0VPDMB30 = (TH1D *)embed_file->Get("hfhitsdedx_Embed_JP0VPDMB30");
    TH1D *hEmbed_fhitsdedx_JP1VPDMB30 = (TH1D *)embed_file->Get("hfhitsdedx_Embed_JP1VPDMB30");
    TH1D *hEmbed_fhitsdedx_JP2 = (TH1D *)embed_file->Get("hfhitsdedx_Embed_JP2");
    TH1D *hEmbed_fhitsdedx_BHT3 = (TH1D *)embed_file->Get("hfhitsdedx_Embed_BHT3");
    TH1D *hEmbed_fhitsdedx_BHT1VPDMB30 = (TH1D *)embed_file->Get("hfhitsdedx_Embed_BHT1VPDMB30");
    TH1D *hEmbed_fhitsdedx_BHT2BBCMB = (TH1D *)embed_file->Get("hfhitsdedx_Embed_BHT2BBCMB");
    TH1D *hEmbed_fhitsdedx_JPsiHTTP = (TH1D *)embed_file->Get("hfhitsdedx_Embed_JPsiHTTP");
    TH1D *hEmbed_fhitsdedx_VPDMB30 = (TH1D *)embed_file->Get("hfhitsdedx_Embed_VPDMB30");
    //=============================Track dEdx========================================
    TH1D *hEmbed_fdEdx_JP0VPDMB30 = (TH1D *)embed_file->Get("hfdEdx_Embed_JP0VPDMB30");
    TH1D *hEmbed_fdEdx_JP1VPDMB30 = (TH1D *)embed_file->Get("hfdEdx_Embed_JP1VPDMB30");
    TH1D *hEmbed_fdEdx_JP2 = (TH1D *)embed_file->Get("hfdEdx_Embed_JP2");
    TH1D *hEmbed_fdEdx_BHT3 = (TH1D *)embed_file->Get("hfdEdx_Embed_BHT3");
    TH1D *hEmbed_fdEdx_BHT1VPDMB30 = (TH1D *)embed_file->Get("hfdEdx_Embed_BHT1VPDMB30");
    TH1D *hEmbed_fdEdx_BHT2BBCMB = (TH1D *)embed_file->Get("hfdEdx_Embed_BHT2BBCMB");
    TH1D *hEmbed_fdEdx_JPsiHTTP = (TH1D *)embed_file->Get("hfdEdx_Embed_JPsiHTTP");
    TH1D *hEmbed_fdEdx_VPDMB30 = (TH1D *)embed_file->Get("hfdEdx_Embed_VPDMB30");
    //=============================Track nSigmaPion========================================
    TH1D *hEmbed_nSigmaPion_JP0VPDMB30 = (TH1D *)embed_file->Get("hnSigmaPion_Embed_JP0VPDMB30");
    TH1D *hEmbed_nSigmaPion_JP1VPDMB30 = (TH1D *)embed_file->Get("hnSigmaPion_Embed_JP1VPDMB30");
    TH1D *hEmbed_nSigmaPion_JP2 = (TH1D *)embed_file->Get("hnSigmaPion_Embed_JP2");
    TH1D *hEmbed_nSigmaPion_BHT3 = (TH1D *)embed_file->Get("hnSigmaPion_Embed_BHT3");
    TH1D *hEmbed_nSigmaPion_BHT1VPDMB30 = (TH1D *)embed_file->Get("hnSigmaPion_Embed_BHT1VPDMB30");
    TH1D *hEmbed_nSigmaPion_BHT2BBCMB = (TH1D *)embed_file->Get("hnSigmaPion_Embed_BHT2BBCMB");
    TH1D *hEmbed_nSigmaPion_JPsiHTTP = (TH1D *)embed_file->Get("hnSigmaPion_Embed_JPsiHTTP");
    TH1D *hEmbed_nSigmaPion_VPDMB30 = (TH1D *)embed_file->Get("hnSigmaPion_Embed_VPDMB30");

    //=============================Track nSigmaKaon========================================
    TH1D *hEmbed_nSigmaKaon_JP0VPDMB30 = (TH1D *)embed_file->Get("hnSigmaKaon_Embed_JP0VPDMB30");
    TH1D *hEmbed_nSigmaKaon_JP1VPDMB30 = (TH1D *)embed_file->Get("hnSigmaKaon_Embed_JP1VPDMB30");
    TH1D *hEmbed_nSigmaKaon_JP2 = (TH1D *)embed_file->Get("hnSigmaKaon_Embed_JP2");
    TH1D *hEmbed_nSigmaKaon_BHT3 = (TH1D *)embed_file->Get("hnSigmaKaon_Embed_BHT3");
    TH1D *hEmbed_nSigmaKaon_BHT1VPDMB30 = (TH1D *)embed_file->Get("hnSigmaKaon_Embed_BHT1VPDMB30");
    TH1D *hEmbed_nSigmaKaon_BHT2BBCMB = (TH1D *)embed_file->Get("hnSigmaKaon_Embed_BHT2BBCMB");
    TH1D *hEmbed_nSigmaKaon_JPsiHTTP = (TH1D *)embed_file->Get("hnSigmaKaon_Embed_JPsiHTTP");
    TH1D *hEmbed_nSigmaKaon_VPDMB30 = (TH1D *)embed_file->Get("hnSigmaKaon_Embed_VPDMB30");
    //=============================Track nSigmaProton========================================
    TH1D *hEmbed_nSigmaProton_JP0VPDMB30 = (TH1D *)embed_file->Get("hnSigmaProton_Embed_JP0VPDMB30");
    TH1D *hEmbed_nSigmaProton_JP1VPDMB30 = (TH1D *)embed_file->Get("hnSigmaProton_Embed_JP1VPDMB30");
    TH1D *hEmbed_nSigmaProton_JP2 = (TH1D *)embed_file->Get("hnSigmaProton_Embed_JP2");
    TH1D *hEmbed_nSigmaProton_BHT3 = (TH1D *)embed_file->Get("hnSigmaProton_Embed_BHT3");
    TH1D *hEmbed_nSigmaProton_BHT1VPDMB30 = (TH1D *)embed_file->Get("hnSigmaProton_Embed_BHT1VPDMB30");
    TH1D *hEmbed_nSigmaProton_BHT2BBCMB = (TH1D *)embed_file->Get("hnSigmaProton_Embed_BHT2BBCMB");
    TH1D *hEmbed_nSigmaProton_JPsiHTTP = (TH1D *)embed_file->Get("hnSigmaProton_Embed_JPsiHTTP");
    TH1D *hEmbed_nSigmaProton_VPDMB30 = (TH1D *)embed_file->Get("hnSigmaProton_Embed_VPDMB30");

    //=============================Track nSigmaElectron========================================
    TH1D *hEmbed_nSigmaElectron_JP0VPDMB30 = (TH1D *)embed_file->Get("hnSigmaElectron_Embed_JP0VPDMB30");
    TH1D *hEmbed_nSigmaElectron_JP1VPDMB30 = (TH1D *)embed_file->Get("hnSigmaElectron_Embed_JP1VPDMB30");
    TH1D *hEmbed_nSigmaElectron_JP2 = (TH1D *)embed_file->Get("hnSigmaElectron_Embed_JP2");
    TH1D *hEmbed_nSigmaElectron_BHT3 = (TH1D *)embed_file->Get("hnSigmaElectron_Embed_BHT3");
    TH1D *hEmbed_nSigmaElectron_BHT1VPDMB30 = (TH1D *)embed_file->Get("hnSigmaElectron_Embed_BHT1VPDMB30");
    TH1D *hEmbed_nSigmaElectron_BHT2BBCMB = (TH1D *)embed_file->Get("hnSigmaElectron_Embed_BHT2BBCMB");
    TH1D *hEmbed_nSigmaElectron_JPsiHTTP = (TH1D *)embed_file->Get("hnSigmaElectron_Embed_JPsiHTTP");
    TH1D *hEmbed_nSigmaElectron_VPDMB30 = (TH1D *)embed_file->Get("hnSigmaElectron_Embed_VPDMB30");

    TH1D *hEmbed_partonicpT_no_wt = (TH1D *)embed_file->Get("partonicpT_Embed_no_weighted");
    TH1D *hEmbed_parton1Phi = (TH1D *)embed_file->Get("hparton1Phi");
    //====================================================================================================================================================//

    // Function Declerations;
    void vertexfit(TH1D *, TH1D *);
    void peak_bin_range(TH1D *, int);
    void peak_bin_range_fitMethod(TH1D *, TH1D *, int scale);

    void plot_diff(TH1D *, TH1D *, int SetLogy = 0);
    void plot_per_partonicpT(string hist_initial_name, TFile);
    void setBinError(TH1D *, TH1D *, TH1D *);
    Trig_Combine Combine(string, TFile *, TFile *);

    //    Calling Functions;
    // vertexfit(hVZdata_JPComb, hVZembed_JPComb);
    // vertexfit(hVZdata_JPComb, hVZembed_JPComb);
    // vertexfit(hdata_vz, hembed_vz);
    // vertexfit(hVZdata_JPComb, hVZembed_JPComb);
    // vertexfit(hdata_vz, hVZembed_JPComb_wt);
    // vertexfit(hdata_vz, hembed_vz);
    //  peak_bin_range(hembed_vz_JP2, 100);
    //  peak_bin_range_fitMethod(hdata_vz_BHT3, hembed_vz_BHT3, 100);
    //  peak_bin_range(hembed_vz_BHT3, 50);
    //    hpTBin to plot partonic pT per bin
    //    hVZ_JP2_pTBin to plot hVZ_JP2 per partonic bin

    Trig_Combine trigCombine_hVZ = Combine("hVZ", data_file, embed_file);
    Trig_Combine trigCombine_hpT = Combine("pT", data_file, embed_file);
    Trig_Combine trigCombine_heta = Combine("heta", data_file, embed_file);
    Trig_Combine trigCombine_hphi = Combine("hphi", data_file, embed_file);
    Trig_Combine trigCombine_hfitPts = Combine("hfitPts", data_file, embed_file);
    Trig_Combine trigCombine_hfitPtsPoss = Combine("hfitPtsPoss", data_file, embed_file);
    Trig_Combine trigCombine_hfhitsdedx = Combine("hfhitsdedx", data_file, embed_file);
    Trig_Combine trigCombine_hfdEdx = Combine("hfdEdx", data_file, embed_file);
    Trig_Combine trigCombine_hnSigmaPion = Combine("hnSigmaPion", data_file, embed_file);
    Trig_Combine trigCombine_hnSigmaKaon = Combine("hnSigmaKaon", data_file, embed_file);
    Trig_Combine trigCombine_hnSigmaProton = Combine("hnSigmaProton", data_file, embed_file);
    Trig_Combine trigCombine_hnSigmaElectron = Combine("hnSigmaElectron", data_file, embed_file);
    //  TCanvas *c_comb = new TCanvas();
    //  AA.hEmbed_Comb->Draw();
    //  c_comb->SaveAs("./hVZ_Trigger_Comb_Embed.pdf");
    //  AA.hData_Comb->Draw();
    //  c_comb->SaveAs("./hVZ_Trigger_Comb_Data.pdf");
    string hpT_perpTBin = "hpTBin";
    string hVZ_JP2_perpTBin = "hVZ_JP2_pTBin";
    string hVZ_BHT3_perpTBin = "hVZ_BHT3_pTBin";
    string hVZ_perpTBin = "hVZ_pTBin";
    // plot_per_partonicpT(hVZ_perpTBin, embed_file);
    // plot_per_partonicpT(hpT_perpTBin, embed_file);
    //  plot_per_partonicpT(hVZ_JP2_perpTBin, embed_file);
    //  plot_per_partonicpT(hVZ_BHT3_perpTBin, embed_file);

    //// Data Embedding comparision plots
    // plot_diff(hdata_vz, hVZ_Embed_wt);
    //    plot_diff(hdata_vz, hembed_vz);
    // plot_diff(hdata_pT, hembed_pT);
    // plot_diff(hDatapT_Comb, hEmbedpT_Comb);
    //    plot_diff(hdata_eta, hembed_eta);
    //    plot_diff(hdata_phi, hembed_phi);
    //    plot_diff(hdata_fitPts, hembed_fitPts);
    //    plot_diff(hdata_fitPtsPoss, hembed_fitPtsPoss);
    //    plot_diff(h_data_tackMult, h_embed_tackMult);

    /////// Trigger Seperated
    // plot_diff(hdata_vz_JP2, hembed_vz_JP2);

    // plot_diff(hdata_vz_BHT3, hembed_vz_BHT3);
    // TCanvas *cvz = new TCanvas();
    // hDatavz_Comb->Scale(1 / hDatavz_Comb->Integral());
    // hEmbedvz_Comb->Scale(1 / hEmbedvz_Comb->Integral());
    // hEmbedvz_Comb->SetLineColor(kRed);
    // hEmbedvz_Comb->Draw();
    // hDatavz_Comb->Draw("same");
    // cvz->SaveAs("./vz_Test.pdf");

    // plot_diff(hDatapT_Comb, hEmbedpT_Comb);
    // plot_diff(hDatavz_Comb, hEmbedvz_Comb);
    plot_diff(trigCombine_hVZ.hData_Comb, trigCombine_hVZ.hEmbed_Comb, 0);
    plot_diff(trigCombine_hpT.hData_Comb, trigCombine_hpT.hEmbed_Comb, 1);
    plot_diff(trigCombine_heta.hData_Comb, trigCombine_heta.hEmbed_Comb, 1);
    plot_diff(trigCombine_hphi.hData_Comb, trigCombine_hphi.hEmbed_Comb, 1);
    plot_diff(trigCombine_hfitPts.hData_Comb, trigCombine_hfitPts.hEmbed_Comb, 1);
    plot_diff(trigCombine_hfitPtsPoss.hData_Comb, trigCombine_hfitPtsPoss.hEmbed_Comb, 0);
    plot_diff(trigCombine_hfhitsdedx.hData_Comb, trigCombine_hfhitsdedx.hEmbed_Comb, 0);
    plot_diff(trigCombine_hfdEdx.hData_Comb, trigCombine_hfdEdx.hEmbed_Comb, 0);
    plot_diff(trigCombine_hnSigmaPion.hData_Comb, trigCombine_hnSigmaPion.hEmbed_Comb, 0);
    plot_diff(trigCombine_hnSigmaKaon.hData_Comb, trigCombine_hnSigmaKaon.hEmbed_Comb, 0);
    plot_diff(trigCombine_hnSigmaProton.hData_Comb, trigCombine_hnSigmaProton.hEmbed_Comb, 0);
    plot_diff(trigCombine_hnSigmaElectron.hData_Comb, trigCombine_hnSigmaElectron.hEmbed_Comb, 0);
    //    plot_diff(hdata_pT_JP2, hembed_pT_JP2);
    //    plot_diff(hdata_pT_JP1VPDMB30, hembed_pT_JP1VPDMB30);
    //    plot_diff(hdata_pT_JP0VPDMB30, hembed_pT_JP0VPDMB30);
    //      plot_diff(hdata_pT_BHT3, hembed_pT_BHT3);

    // plot_diff(hdata_eta_JP2, hembed_eta_JP2);
    // plot_diff(hdata_eta_BHT3, hembed_eta_BHT3);

    // plot_diff(hdata_phi_JP2, hembed_phi_JP2);
    // plot_diff(hdata_phi_BHT3, hembed_phi_BHT3);

    // plot_diff(hdata_fitPts_JP2, hembed_fitPts_JP2);
    // plot_diff(hdata_fitPts_BHT3, hembed_fitPts_BHT3);
    // plot_diff(hdata_fitPtsPoss_BHT3, hembed_fitPtsPoss_BHT3);
    // plot_diff(hdata_fitPtsPoss_JP2, hembed_fitPtsPoss_JP2);

    // plot_diff(h_data_tackMult_JP2, h_embed_tackMult_JP2);
    // plot_diff(h_data_tackMult_BHT3, h_embed_tackMult_BHT3);

    // Embed All trigger vs  JP2 triggered sample

    // plot_diff(hembed_vz, hembed_vz_JP2);
    // plot_diff(hembed_pT, hembed_pT_JP2);
    //  plot_diff(hembed_eta, hembed_eta_JP2);
    //  plot_diff(hembed_phi, hembed_phi_JP2);
    //  plot_diff(hembed_fitPts, hembed_fitPts_JP2);
    //  plot_diff(hembed_fitPtsPoss, hembed_fitPtsPoss_JP2);

    // Embed All trigger vs  BHT3 triggered sample
    // plot_diff(hembed_vz, hembed_vz_BHT3);
    // plot_diff(hembed_pT, hembed_pT_BHT3);
    // plot_diff(hembed_eta, hembed_eta_BHT3);
    // plot_diff(hembed_phi, hembed_phi_BHT3);
    // plot_diff(hembed_fitPts, hembed_fitPts_BHT3);
    // plot_diff(hembed_fitPtsPoss, hembed_fitPtsPoss_BHT3);

    // Embed JP2 vs Embed BHT3
    // plot_diff(hembed_vz_JP2, hembed_vz_BHT3);
    // plot_diff(hembed_pT_JP2, hembed_pT_BHT3);
    //  plot_diff(hembed_eta_JP2, hembed_eta_BHT3);
    //  plot_diff(hembed_phi_JP2, hembed_phi_BHT3);
    //  plot_diff(hembed_fitPts_JP2, hembed_fitPts_BHT3);
    //  plot_diff(hembed_fitPtsPoss_JP2, hembed_fitPtsPoss_BHT3);
}

vertexfit(TH1D *hdata, TH1D *hembed)
{
    TCanvas *c_comp = new TCanvas("canv_comp", "canv_comp", 900, 700);
    // c_comp->cd()->SetLogy();
    gStyle->SetOptStat(0);
    gStyle->SetPadGridX(0);
    gStyle->SetPadGridY(0);
    hdata->Sumw2();
    hembed->Sumw2();
    hdata->Scale(1 / hdata->Integral());
    hembed->Scale(1 / hembed->Integral());
    hembed->SetLineColor(kRed);

    TPad *pad1 = new TPad("pad1", "pad1", 0.0, 0.3, 1.0, 1.0);
    pad1->SetBottomMargin(0.0);
    pad1->Draw();
    pad1->cd();
    hdata->SetMinimum(0);
    hdata->Draw();
    hembed->Draw("same");

    TLegend *leg = new TLegend(0.8, 0.7, 0.9, 0.9);
    leg->AddEntry(hdata, "Data");
    leg->AddEntry(hembed, "Embed");
    leg->Draw();
    // pad1->Update();
    c_comp->Update();
    c_comp->cd();
    TPad *pad2 = new TPad("pad2", "pad2", 0.0, 0.0, 1.0, 0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.2);
    pad2->Draw();
    pad2->cd();

    TH1D *h_Ratio = (TH1D *)hdata->Clone();

    h_Ratio->Divide(hembed);
    h_Ratio->GetYaxis()->SetTitle("#frac{Data}{Embed}");
    h_Ratio->GetYaxis()->CenterTitle();

    // TF1* verfit=new TF1("verfit","[0]*TMath::Gaus(x,[1],[2])");

    TF1 *verfit_gaus = new TF1("verfit_gaus", "gaus", -40, 40);
    TF1 *polfit = new TF1("polfit", "pol2", 40, 90);
    TF1 *polfit_2 = new TF1("polfit_2", "pol2", -40, -90);
    // verfit_gaus->SetLineColor(kRed);

    // TF1 *verfit = new TF1("verfit", "pol6", -90, 90);
    // h_Ratio->Fit(verfit, "R");

    // h_Ratio->Fit(verfit_gaus);
    // h_Ratio->Fit(polfit);
    polfit->SetLineColor(kBlue);
    polfit_2->SetLineColor(kBlue);
    h_Ratio->Fit(polfit, "R");
    h_Ratio->Fit(polfit_2, "R");
    h_Ratio->Fit(verfit_gaus, "R");
    // cout << verfit_gaus->GetParameter(0) << "\t 1.206\t" << endl;

    TF1 *verfit = new TF1("verfit", "[0]+[1]*x+[2]*x*x +[3]*TMath::Gaus(x,[4],[5])+[6]+[7]*x+[8]*x*x", -90, 90);

    verfit->SetParameter(0, polfit->GetParameter(0));
    verfit->SetParameter(1, polfit->GetParameter(1));
    verfit->SetParameter(2, polfit->GetParameter(2));
    verfit->SetParameter(3, verfit_gaus->GetParameter(0));
    verfit->SetParameter(4, verfit_gaus->GetParameter(1));
    verfit->SetParLimits(5, verfit_gaus->GetParameter(2) - 5, verfit_gaus->GetParameter(2) + 5);
    verfit->SetParameter(6, polfit_2->GetParameter(0));
    verfit->SetParameter(7, polfit_2->GetParameter(1));
    verfit->SetParameter(8, polfit_2->GetParameter(2));

    //  h_Ratio->Fit(polfit, "R");

    h_Ratio->Fit(verfit);
    // h_Ratio->Draw();
    //  polfit_2->Draw("same");

    string name = hembed->GetName();
    cout << name << "\t Name" << endl;
    cout << name << "\t Name" << endl;
    cout << name << "\t Name" << endl;
    cout << name << "\t Name" << endl;
    cout << name << "\t Name" << endl;
    //// h_Ratio->Fit("pol0");
    //// h_Ratio->GetYaxis()->SetRangeUser(-0.5, 0.5);
    // h_Ratio->GetYaxis()->SetRangeUser(-1, 1);

    //

    c_comp->SaveAs(Form("./%s_fit.pdf", name));
    hdata->Clear();
    hembed->Clear();
}
plot_per_partonicpT(string hist_initial_name, TFile *embed_file)
{
    TCanvas *c1 = new TCanvas();
    TCanvas *c2 = new TCanvas();
    c1->cd()->SetLogy();
    if (hist_initial_name == "hVZ_pTBin")
    {
        c1->cd()->SetLogy(0);
        cout << hist_initial_name << "\t hist name\t" << endl;
    }
    const char *PtRange_name[14] = {"2", "3", "4", "5", "7", "9", "11", "15", "20", "25", "35", "45", "55", "1000"};
    const int nbins = 13;
    TH1D *hpT_bin[13];
    for (int bin = 0; bin < nbins; bin++)
    {
        const char *hist_name = Form("%s%s_%s", hist_initial_name, PtRange_name[bin], PtRange_name[bin + 1]);
        cout << hist_name << endl;
        hpT_bin[bin] = (TH1D *)embed_file->Get(hist_name);
        cout << hpT_bin[bin]->GetEntries() << "\t GetEntries" << endl;
        hpT_bin[bin]->Draw();
        c1->SaveAs(Form("./%s.pdf", hist_name));
        c1->Clear();
    }
}

peak_bin_range(TH1D *hVZ_embed, int multiplier = 50)
{
    string hist_name = hVZ_embed->GetName();
    ofstream outfile(Form("%s_peak_range_aveMethod.txt", hist_name));
    double TotBinContent = 0;
    double avgBinContent = 0;
    double TotBin = 0;

    for (int bin = 0; bin < hVZ_embed->GetNbinsX(); bin++)
    {
        if (hVZ_embed->GetBinContent(bin) == 0)
            continue;
        // cout << hVZ_embed->GetBinContent(bin) << "\t Bin Content for Bin\t"<<bin<<"  "<<hVZ_embed->GetBinLowEdge(bin)<< "\t Bin Low Edge\t"<<hVZ_embed->GetBinLowEdge(bin)+hVZ_embed->GetBinWidth(bin)<<"\t Bin High Edge" <<endl;
        TotBinContent = TotBinContent + hVZ_embed->GetBinContent(bin);
        TotBin = TotBin + bin;
    }
    avgBinContent = TotBinContent / TotBin;

    cout << avgBinContent << "\t ave Bin Content\t" << endl;

    for (int bin = 0; bin < hVZ_embed->GetNbinsX(); bin++)
    {
        if (hVZ_embed->GetBinContent(bin) == 0)
            continue;
        double bincontent = hVZ_embed->GetBinContent(bin);
        double maxbincontent = avgBinContent * multiplier;
        // cout << bincontent<<"\t binContent\t"<<endl;

        if (bincontent > maxbincontent)
        {
            outfile << hVZ_embed->GetBinLowEdge(bin) << "\t \t" << hVZ_embed->GetBinLowEdge(bin) + hVZ_embed->GetBinWidth(bin) << endl;
            // cout << hVZ_embed->GetBinContent(bin) << "\tBin Content for Bin\t" << bin << "  " << hVZ_embed->GetBinLowEdge(bin) << "\tBin Low Edge\t" << hVZ_embed->GetBinLowEdge(bin) + hVZ_embed->GetBinWidth(bin) << "\tBin High Edge\t" << endl;
        }
    }
    outfile.close();
}

peak_bin_range_fitMethod(TH1D *hdata, TH1D *hembed, int scale = 5)
{
    string hist_name = hdata->GetName();
    ofstream outfile(Form("%s_peak_range_fitMethod.txt", hist_name));
    hdata->Sumw2();
    hembed->Sumw2();
    hdata->Scale(1 / hdata->Integral());
    hembed->Scale(1 / hembed->Integral());
    hembed->SetLineColor(kRed);
    TF1 *fit_hdata = new TF1("fit_hdata", "gaus");
    hdata->Fit(fit_hdata);
    for (int bin = 1; bin <= hdata->GetNbinsX(); bin++)
    {
        double binContent = hdata->GetBinContent(bin);
        double fitValue = fit_hdata->Eval(hdata->GetBinCenter(bin));
        double embed_binContent = hembed->GetBinContent(bin);
        // cout << binContent << "\t Bin Content\t" << endl;
        // cout << fitValue << "\t fitValue \t" << endl;
        if (fitValue > (scale * embed_binContent))
        {
            // cout << embed_binContent << "\t Embed Bin Content\t" << endl;
            // cout << hembed->GetBinContent(bin) << "\tBin Content for Bin\t" << bin << "  " << hembed->GetBinLowEdge(bin) << "\tBin Low Edge\t" << hembed->GetBinLowEdge(bin) + hembed->GetBinWidth(bin) << "\tBin High Edge\t" << endl;
            outfile << hembed->GetBinLowEdge(bin) << "\t \t" << hembed->GetBinLowEdge(bin) + hembed->GetBinWidth(bin) << endl;
        }
    }
    outfile.close();
}
plot_diff(TH1D *hdata, TH1D *hembed, int setlogy)
{
    TCanvas *c_comp = new TCanvas("canv_comp", "canv_comp", 900, 700);
    // c_comp->cd()->SetLogy();
    gStyle->SetOptStat(0);
    gStyle->SetPadGridX(0);
    gStyle->SetPadGridY(0);
    hdata->Sumw2();
    hembed->Sumw2();
    hdata->Scale(1 / hdata->Integral());
    hembed->Scale(1 / hembed->Integral());
    hembed->SetLineColor(kRed);
    TPad *pad1 = new TPad("pad1", "pad1", 0.0, 0.3, 1.0, 1.0);
    pad1->SetBottomMargin(0);
    pad1->Draw();
    pad1->cd()->SetLogy(setlogy);
    string hname = hdata->GetName();

    if (hname == "hVZ")
    {

        hdata->Rebin(5);
        hembed->Rebin(5);
        //    cout << hembed->GetName() << "\t hVZ_Embed"<<endl;
    }

    // hdata->Fit("gaus");
    hembed->Draw();
    hdata->Draw("same");

    TLegend *leg = new TLegend(0.8, 0.7, 0.9, 0.9);
    leg->AddEntry(hdata, "Data");
    leg->AddEntry(hembed, "Embed");
    leg->Draw();
    c_comp->Update();

    c_comp->cd();
    TPad *pad2 = new TPad("pad2", "pad2", 0.0, 0.0, 1.0, 0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.2);
    pad2->Draw();
    pad2->cd();

    TH1D *h_Ratio = (TH1D *)hdata->Clone();

    h_Ratio->Add(hembed, -1);
    h_Ratio->Divide(hdata);
    h_Ratio->GetYaxis()->SetTitle("#frac{Data-Embed}{Data}");
    h_Ratio->GetYaxis()->CenterTitle();
    // h_Ratio->Fit("pol0");
    // h_Ratio->GetYaxis()->SetRangeUser(-0.5, 0.5);
    h_Ratio->GetYaxis()->SetRangeUser(-1, 1);

    // calling Bin Error
    setBinError(h_Ratio, hdata, hembed);

    h_Ratio->Draw();
    string name;

    name = h_Ratio->GetName();

    c_comp->SaveAs(Form("%s.pdf", name));
    hdata->Clear();
    hembed->Clear();
}
void setBinError(TH1D *h_Ratio, TH1D *hdata, TH1D *hembed)

{
    for (int bin = 1; bin <= h_Ratio->GetNbinsX(); bin++)
    {
        double data_binContent = hdata->GetBinContent(bin);
        double embed_binContent = hembed->GetBinContent(bin);
        double data_binError = hdata->GetBinError(bin);
        double embed_binError = hembed->GetBinError(bin);
        if (data_binContent == 0 || embed_binContent == 0)
            continue;

        double hRatio_binError = (double)(embed_binContent / data_binContent) * sqrt(pow((embed_binError / embed_binContent), 2) + pow((data_binError / data_binContent), 2));

        h_Ratio->SetBinError(hRatio_binError, bin);
        // cout << data_binContent << "\t Data Bin Content\t" << endl;
        // cout << data_binError << "\t Data Bin Error\t" << endl;
        // cout << embed_binContent << "\t Embed Bin Content\t" << endl;
        // cout << embed_binError << "\t Embed Bin Error\t" << endl;
        // cout << h_Ratio->GetBinError(bin) << "\t bin error for Bin\t" << bin << endl;
    }
} // Set Bin Error Function ends

struct Trig_Combine
{
    TH1D *hData_Comb;
    TH1D *hEmbed_Comb;
};
Trig_Combine Combine(string quant, TFile *data_file, TFile *embed_file)
{

    Trig_Combine hists;
    double PsWtJP2 = 1;
    double PsWtJP1 = (1 / 6.37);
    double PsWtJP0 = (1 / 57.881);
    double PsWtBHT3 = 1;
    double PsWtBHT2 = 1.0;
    double PsWtBHT1 = 1.44;
    double PsWtJpsiHTTP = 1;
    double PsWtVPDMB30 = (1 / 1960);
    // Embedding Trigger Combine
    TH1D *hEmbedJP2 = (TH1D *)embed_file->Get(Form("%s_Embed_JP2", quant));
    TH1D *hEmbedJP1 = (TH1D *)embed_file->Get(Form("%s_Embed_JP1VPDMB30", quant));
    TH1D *hEmbedJP0 = (TH1D *)embed_file->Get(Form("%s_Embed_JP0VPDMB30", quant));
    TH1D *hEmbedBHT3 = (TH1D *)embed_file->Get(Form("%s_Embed_BHT3", quant));
    TH1D *hEmbedBHT2 = (TH1D *)embed_file->Get(Form("%s_Embed_BHT2BBCMB", quant));
    TH1D *hEmbedBHT1 = (TH1D *)embed_file->Get(Form("%s_Embed_BHT1VPDMB30", quant));
    TH1D *hEmbedJPsiHTTP = (TH1D *)embed_file->Get(Form("%s_Embed_JPsiHTTP", quant));
    TH1D *hEmbedVPDMB30 = (TH1D *)embed_file->Get(Form("%s_Embed_VPDMB30", quant));

    hists.hEmbed_Comb = (TH1D *)hEmbedJP2->Clone();
    hists.hEmbed_Comb->Add(hEmbedJP0, PsWtJP0);
    hists.hEmbed_Comb->Add(hEmbedJP1, PsWtJP1);
    hists.hEmbed_Comb->Add(hEmbedBHT3, PsWtBHT3);
    hists.hEmbed_Comb->Add(hEmbedBHT2, PsWtBHT2);
    hists.hEmbed_Comb->Add(hEmbedBHT1, PsWtBHT1);
    hists.hEmbed_Comb->Add(hEmbedJPsiHTTP, PsWtJpsiHTTP);
    hists.hEmbed_Comb->Add(hEmbedVPDMB30, PsWtVPDMB30);
    hists.hEmbed_Comb->SetName(Form("%s_TriggerCombine_Embed", quant));
    // Data Trigger Combine
    cout << quant << "\t quant \t" << endl;
    TH1D *hDataJP2 = (TH1D *)data_file->Get(Form("%s_Data_JP2", quant));
    TH1D *hDataJP1 = (TH1D *)data_file->Get(Form("%s_Data_JP1VPDMB30", quant));
    TH1D *hDataJP0 = (TH1D *)data_file->Get(Form("%s_Data_JP0VPDMB30", quant));
    TH1D *hDataBHT3 = (TH1D *)data_file->Get(Form("%s_Data_BHT3", quant));
    TH1D *hDataBHT2 = (TH1D *)data_file->Get(Form("%s_Data_BHT2BBCMB", quant));
    TH1D *hDataBHT1 = (TH1D *)data_file->Get(Form("%s_Data_BHT1VPDMB30", quant));
    TH1D *hDataJPsiHTTP = (TH1D *)data_file->Get(Form("%s_Data_JPsiHTTP", quant));
    TH1D *hDataVPDMB30 = (TH1D *)data_file->Get(Form("%s_Data_VPDMB30", quant));

    hists.hData_Comb = (TH1D *)hDataJP2->Clone();
    hists.hData_Comb->Add(hDataJP0, PsWtJP0);
    hists.hData_Comb->Add(hDataJP1, PsWtJP1);
    hists.hData_Comb->Add(hDataBHT3, PsWtBHT3);
    hists.hData_Comb->Add(hDataBHT2, PsWtBHT2);
    hists.hData_Comb->Add(hDataBHT1, PsWtBHT1);
    hists.hData_Comb->Add(hDataJPsiHTTP, PsWtJpsiHTTP);
    hists.hData_Comb->Add(hDataVPDMB30, PsWtVPDMB30);
    hists.hData_Comb->SetName(Form("%s_TriggerCombine_Data", quant));
    // hists.hEmbed_Comb->Draw();
    return hists;
}