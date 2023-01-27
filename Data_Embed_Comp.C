#include <iostream>
#include <fstream>
#include <string>

void Data_Embed_Comp(const char *data, const char *embed)
{
    // TFile *data_file = new TFile("/star/u/nghimire/pp500/IFF_Run17/PID/triggerBias/TreeProduction/PionPairStudy_NewTest/ReadTree_Test.root");
    TFile *data_file = new TFile(data);
    TFile *embed_file = new TFile(embed);

    TH1D *hdata_vz = (TH1D *)data_file->Get("hVZ");
    TH1D *hembed_vz = (TH1D *)embed_file->Get("hVZ_Embed");
    TH1D *hembed_vz_wt = (TH1D *)embed_file->Get("hVZ_Embed_wt");

    TH1D *hdata_pT = (TH1D *)data_file->Get("pT");
    TH1D *hembed_pT = (TH1D *)embed_file->Get("pT_Embed");
    TH1D *hdata_eta = (TH1D *)data_file->Get("h_eta");
    TH1D *hembed_eta = (TH1D *)embed_file->Get("h_eta");
    TH1D *hdata_phi = (TH1D *)data_file->Get("h_phi");
    TH1D *hembed_phi = (TH1D *)embed_file->Get("h_phi");
    TH1D *hdata_fitPts = (TH1D *)data_file->Get("h_fitPts");
    TH1D *hembed_fitPts = (TH1D *)embed_file->Get("h_fitPts");
    TH1D *hdata_fitPtsPoss = (TH1D *)data_file->Get("h_fitPtsPoss");
    TH1D *hembed_fitPtsPoss = (TH1D *)embed_file->Get("h_fitPtsPoss");

    TH1D *hdata_vz_JP2 = (TH1D *)data_file->Get("hVZ_JP2");

    TH1D *hembed_vz_JP2 = (TH1D *)embed_file->Get("hVZ_Embed_JP2");
    TH1D *hdata_vz_BHT3 = (TH1D *)data_file->Get("hVZ_BHT3");
    TH1D *hembed_vz_BHT3 = (TH1D *)embed_file->Get("hVZ_Embed_BHT3");

    TH1D *hdata_pT_JP2 = (TH1D *)data_file->Get("pT_JP2");
    TH1D *hdata_pT_BHT3 = (TH1D *)data_file->Get("pT_BHT3");
    TH1D *hembed_pT_JP2 = (TH1D *)embed_file->Get("pT_Embed_JP2");
    TH1D *hembed_pT_BHT3 = (TH1D *)embed_file->Get("pT_Embed_BHT3");

    TH1D *hdata_eta_JP2 = (TH1D *)data_file->Get("h_eta_JP2");
    TH1D *hdata_eta_BHT3 = (TH1D *)data_file->Get("h_eta_BHT3");
    TH1D *hembed_eta_JP2 = (TH1D *)embed_file->Get("h_eta_JP2");
    TH1D *hembed_eta_BHT3 = (TH1D *)embed_file->Get("h_eta_BHT3");

    TH1D *hdata_phi_JP2 = (TH1D *)data_file->Get("h_phi_JP2");
    TH1D *hdata_phi_BHT3 = (TH1D *)data_file->Get("h_phi_BHT3");
    TH1D *hembed_phi_JP2 = (TH1D *)embed_file->Get("h_phi_JP2");
    TH1D *hembed_phi_BHT3 = (TH1D *)embed_file->Get("h_phi_BHT3");

    TH1D *hdata_fitPts = (TH1D *)data_file->Get("h_fitPts");
    TH1D *hembed_fitPts = (TH1D *)embed_file->Get("h_fitPts");
    TH1D *hdata_fitPts_JP2 = (TH1D *)data_file->Get("h_fitPts_JP2");
    TH1D *hembed_fitPts_JP2 = (TH1D *)embed_file->Get("h_fitPts_JP2");
    TH1D *hdata_fitPts_BHT3 = (TH1D *)data_file->Get("h_fitPts_BHT3");
    TH1D *hembed_fitPts_BHT3 = (TH1D *)embed_file->Get("h_fitPts_BHT3");

    TH1D *hdata_fitPtsPoss = (TH1D *)data_file->Get("h_fitPtsPoss");
    TH1D *hembed_fitPtsPoss = (TH1D *)embed_file->Get("h_fitPtsPoss");
    TH1D *hdata_fitPtsPoss_JP2 = (TH1D *)data_file->Get("h_fitPtsPoss_JP2");
    TH1D *hembed_fitPtsPoss_JP2 = (TH1D *)embed_file->Get("h_fitPtsPoss_JP2");
    TH1D *hdata_fitPtsPoss_BHT3 = (TH1D *)data_file->Get("h_fitPtsPoss_BHT3");
    TH1D *hembed_fitPtsPoss_BHT3 = (TH1D *)embed_file->Get("h_fitPtsPoss_BHT3");

    TH1D *hpartonicpT_no_wt = (TH1D *)embed_file->Get("partonicpT_Embed_no_weighted");
    TH1D *hpartonicpT_wt = (TH1D *)embed_file->Get("partonicpT_Embed_weighted");

    TH1D *h_data_tackMult = (TH1D *)data_file->Get("hfmaxpar");
    TH1D *h_data_tackMult_JP2 = (TH1D *)data_file->Get("hfmaxpar_JP2");
    TH1D *h_data_tackMult_BHT3 = (TH1D *)data_file->Get("hfmaxpar_BHT3");

    TH1D *h_embed_tackMult = (TH1D *)embed_file->Get("hfmaxpar");
    TH1D *h_embed_tackMult_JP2 = (TH1D *)embed_file->Get("hfmaxpar_JP2");
    TH1D *h_embed_tackMult_BHT3 = (TH1D *)embed_file->Get("hfmaxpar_BHT3");

    // Function Declerations;
    void peak_bin_range(TH1D *, int);
    void peak_bin_range_fitMethod(TH1D *, TH1D *, int scale);

    void plot_diff(TH1D *, TH1D *);
    void plot_per_partonicpT(string hist_initial_name, TFile);
    void setBinError(TH1D *, TH1D *, TH1D *);
    // Calling Functions;
    // peak_bin_range(hembed_vz_JP2, 100);
    // peak_bin_range_fitMethod(hdata_vz_BHT3, hembed_vz_BHT3, 100);
    // peak_bin_range(hembed_vz_BHT3, 50);
    //   hpTBin to plot partonic pT per bin
    //   hVZ_JP2_pTBin to plot hVZ_JP2 per partonic bin
    string hpT_perpTBin = "hpTBin";
    string hVZ_JP2_perpTBin = "hVZ_JP2_pTBin";
    string hVZ_BHT3_perpTBin = "hVZ_BHT3_pTBin";

    plot_per_partonicpT(hpT_perpTBin, embed_file);
    plot_per_partonicpT(hVZ_JP2_perpTBin, embed_file);
    plot_per_partonicpT(hVZ_BHT3_perpTBin, embed_file);

    // Data Embedding comparision plots
    plot_diff(hdata_vz, hembed_vz);
    plot_diff(hdata_pT, hembed_pT);
    plot_diff(hdata_eta, hembed_eta);
    plot_diff(hdata_phi, hembed_phi);
    plot_diff(hdata_fitPts, hembed_fitPts);
    plot_diff(hdata_fitPtsPoss, hembed_fitPtsPoss);
    plot_diff(h_data_tackMult, h_embed_tackMult);

    ///// Trigger Seperated
    plot_diff(hdata_vz_JP2, hembed_vz_JP2);

    plot_diff(hdata_vz_BHT3, hembed_vz_BHT3);

    plot_diff(hdata_pT_JP2, hembed_pT_JP2);
    plot_diff(hdata_pT_BHT3, hembed_pT_BHT3);

    plot_diff(hdata_eta_JP2, hembed_eta_JP2);
    plot_diff(hdata_eta_BHT3, hembed_eta_BHT3);

    plot_diff(hdata_phi_JP2, hembed_phi_JP2);
    plot_diff(hdata_phi_BHT3, hembed_phi_BHT3);

    plot_diff(hdata_fitPts_JP2, hembed_fitPts_JP2);
    plot_diff(hdata_fitPts_BHT3, hembed_fitPts_BHT3);
    plot_diff(hdata_fitPtsPoss_BHT3, hembed_fitPtsPoss_BHT3);
    plot_diff(hdata_fitPtsPoss_JP2, hembed_fitPtsPoss_JP2);

    plot_diff(h_data_tackMult_JP2, h_embed_tackMult_JP2);
    plot_diff(h_data_tackMult_BHT3, h_embed_tackMult_BHT3);

    // Embed All trigger vs  JP2 triggered sample

    // plot_diff(hembed_vz, hembed_vz_JP2);
    // plot_diff(hembed_pT, hembed_pT_JP2);
    // plot_diff(hembed_eta, hembed_eta_JP2);
    // plot_diff(hembed_phi, hembed_phi_JP2);
    // plot_diff(hembed_fitPts, hembed_fitPts_JP2);
    // plot_diff(hembed_fitPtsPoss, hembed_fitPtsPoss_JP2);

    // Embed All trigger vs  BHT3 triggered sample
    // plot_diff(hembed_vz, hembed_vz_BHT3);
    // plot_diff(hembed_pT, hembed_pT_BHT3);
    // plot_diff(hembed_eta, hembed_eta_BHT3);
    // plot_diff(hembed_phi, hembed_phi_BHT3);
    // plot_diff(hembed_fitPts, hembed_fitPts_BHT3);
    // plot_diff(hembed_fitPtsPoss, hembed_fitPtsPoss_BHT3);

    // Embed JP2 vs Embed BHT3
    //  plot_diff(hembed_vz_JP2, hembed_vz_BHT3);
    //  plot_diff(hembed_pT_JP2, hembed_pT_BHT3);
    //  plot_diff(hembed_eta_JP2, hembed_eta_BHT3);
    //  plot_diff(hembed_phi_JP2, hembed_phi_BHT3);
    //  plot_diff(hembed_fitPts_JP2, hembed_fitPts_BHT3);
    //  plot_diff(hembed_fitPtsPoss_JP2, hembed_fitPtsPoss_BHT3);
}

plot_per_partonicpT(string hist_initial_name, TFile *embed_file)
{
    TCanvas *c1 = new TCanvas();
    TCanvas *c2 = new TCanvas();
    c1->cd()->SetLogy();
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
plot_diff(TH1D *hdata, TH1D *hembed)
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
    pad1->cd()->SetLogy();
    string hname = hembed->GetName();

    if (hname == "hVZ_Embed" || hname == "hVZ_Embed_BHT3" || hname == "hVZ_Embed_JP2" || hname == "hfmaxpar_JP2" || hname == "hfmaxpar" || hname == "hfmaxpar_BHT3")
    {
        pad1->cd()->SetLogy(0);
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
    h_Ratio->GetYaxis()->SetRangeUser(-0.5, 0.5);
    // h_Ratio->GetYaxis()->SetRangeUser(-1, 1);

    // calling Bin Error
    setBinError(h_Ratio, hdata, hembed);

    h_Ratio->Draw();
    string name;
    name = h_Ratio->GetName();
    cout << name << endl;

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
}