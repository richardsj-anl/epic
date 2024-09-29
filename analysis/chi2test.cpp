

void chi2test () {

    TString imagesDir = "~/Projects/ANL/bbcal/images_newGeo/pim/v2.1/";
    TFile dataFile("~/Projects/ANL/bbcal/FTBF_data/Energy_Distributions_with_Pions_MIP_calib.root", "READ");
    //TFile dataFile("~/Projects/ANL/bbcal/FTBF_data/Energy_Distributions_with_Pions.root", "READ");
    //TFile dataFile("~/Projects/ANL/bbcal/FTBF_data/cuts/Energy_Distributions_with_Pions.root", "READ");
    TFile mcFile("~/Projects/ANL/bbcal/histos_newGeo/v2.1/pimHistos.root", "READ");
    const int nE= 4;
    int Energy[nE] = {4, 6, 8, 10};
    int p = 0;
    int nbins = 300;
    Double_t residuals[nbins]; 
    Double_t x[nbins]; 

    gStyle->SetOptStat(0);
    gStyle->SetOptFit(111);

    for (int i=0; i<4; i++) {
        p = Energy[i];

        // Histos from Henry
        //TH1F *hE_data = (TH1F*) dataFile.Get(Form("h%dGeV", p));
        TH1F *hPion_data = (TH1F*) dataFile.Get(Form("h%dGeV_pion", p));

        // Histos from MonteCarlo sims
        //TH1F *hE_mc = (TH1F*) mcFile.Get(Form("h%dGeV", p));
        TH1F *hPion_mc_kBnom = (TH1F*) mcFile.Get(Form("hPimCal_%dGeV_APC_T_kBnom", p));
        //TH1F *hPion_mc_kBlow = (TH1F*) mcFile.Get(Form("hPimCal_%dGeV_APC_T_kBlow", p));
        //TH1F *hPion_mc_kBup = (TH1F*) mcFile.Get(Form("hPimCal_%dGeV_APC_T_kBup", p));
        //TH1F *hPion_mc_kBnom = (TH1F*) mcFile.Get(Form("hPimCal_%dGeV_APC_TC_kBnom", p));
        //TH1F *hPion_mc_kBlow = (TH1F*) mcFile.Get(Form("hPimCal_%dGeV_APC_TC_kBlow", p));
        //TH1F *hPion_mc_kBup = (TH1F*) mcFile.Get(Form("hPimCal_%dGeV_APC_TC_kBup", p));

        // Clone and Scale Histograms
        TH1F *hData = (TH1F*) (hPion_data->Clone("hData"));
        TH1F *hMC0= (TH1F*) (hPion_mc_kBnom->Clone("hMC0"));
        //TH1F *hMC1= (TH1F*) (hPion_mc_kBlow->Clone("hMC1"));
        //TH1F *hMC2= (TH1F*) (hPion_mc_kBup->Clone("hMC2"));

        Double_t xLow = 0.18*p;
        Double_t xUp = 0.60*p;
        //Double_t xLow = 0.20*p;
        //Double_t xUp = 0.65*p;
        hData->SetAxisRange(xLow, xUp);
        hMC0->SetAxisRange(xLow, xUp);
        //hMC1->SetAxisRange(0.20*p, 0.70*p);
        //hMC2->SetAxisRange(0.20*p, 0.70*p);

        //Double_t intH1= hData->Integral(hData->FindBin(1.0), nbins);
        //Double_t intH2= hMC->Integral(hMC->FindBin(1.0), nbins);
        Double_t intData= hData->Integral(hData->FindBin(xLow), hData->FindBin(xUp));
        Double_t intMC0= hMC0->Integral(hMC0->FindBin(xLow), hMC0->FindBin(xUp));
        //Double_t intMC1= hMC1->Integral();
        //Double_t intMC2= hMC2->Integral();
        Double_t factor0 = intData/intMC0;
        //Double_t factor1 = intData/intMC1;
        //Double_t factor2 = intData/intMC2;

        if (hMC0->GetSumw2N() == 0) hMC0->Sumw2(kTRUE);
        //if (hMC1->GetSumw2N() == 0) hMC1->Sumw2(kTRUE);
        //if (hMC2->GetSumw2N() == 0) hMC2->Sumw2(kTRUE);
        hMC0->Scale(factor0);
        //hMC1->Scale(factor1);
        //hMC2->Scale(factor2);

        // Apply the chi2test and retrieve the residuals
        auto test0 = hData->Chi2Test(hMC0, "WW CHI2/NDF", residuals);
        //auto test0 = hData->Chi2Test(hMC0, "WW P", residuals);
        //auto test1 = hData->Chi2Test(hMC1, "WW CHI2/NDF", residuals);
        //auto test2 = hData->Chi2Test(hMC2, "WW CHI2/NDF", residuals);

        TCanvas *c1 = new TCanvas(Form("c1%d", p),"Chistat Plot",1200,800);

        Double_t yUp = 0.015;
        //Double_t yUp = 0.35;
        hData->SetMaximum(yUp);
        hMC0->SetMaximum(yUp);
        hData->SetMinimum(0.);
        hMC0->SetMinimum(0.);

        hData->SetAxisRange(0., 1.20*p);
        hMC0->SetAxisRange(0., 1.20*p);

        //hMC2->SetMarkerColor(kRed);
        //hMC2->SetMarkerStyle(20);
        //hMC2->SetTitle(Form("%dGeV Pion Response, Chi2Test; E_{cal} [GeV]; Normalized Counts", p));
        //hMC2->Draw();

        //hMC1->SetMarkerColor(kGreen);
        //hMC1->SetMarkerStyle(20);
        //hMC1->Draw("sames");

        hData->SetMarkerColor(kCyan);
        hData->SetLineColor(kCyan+2);
        hData->SetMarkerStyle(20);
        hData->SetLineStyle(1);
        hData->SetTitle(Form("%dGeV Pion Energy Response Comparison; E_{cal} [GeV]; Normalized Counts", p));
        hData->Draw();
 
        hMC0->SetMarkerColor(kMagenta+2);
        hMC0->SetLineColor(kMagenta+2);
        hMC0->SetMarkerStyle(20);
        hMC0->SetLineStyle(1);
        hMC0->SetTitle(Form("%dGeV Pion Energy Response Comparison; E_{cal} [GeV]; Normalized Counts", p));
        hMC0->Draw("same");
        //hMC0->Draw("hist");
        //hData->Draw("hist same");

        //auto leg = new TLegend(0.11, 0.11, 0.40, 0.30);
        auto leg = new TLegend(0.61, 0.71, 0.89, 0.89);
        leg->AddEntry(hData, "Beam Test", "ep");
        leg->AddEntry(hMC0, "Monte Carlo", "ep");
        //leg->AddEntry(hMC1, "Sim, kB = 0.063 #frac{mm}{MeV}", "lep");
        //leg->AddEntry(hMC2, "Sim, kB = 0.189 #frac{mm}{MeV}", "lep");
        leg->Draw();

        auto pave = new TPaveText(0.61, 0.55, 0.89, 0.70, "brNDC");
        pave->SetFillColor(kOrange);
        pave->SetFillStyle(3018);
        pave->AddText(Form("#chi^{2}/ndf = %.2f", test0));
        ((TText*)pave->GetListOfLines()->Last())->SetTextColor(kMagenta+2);
        //pave->AddText(Form("#chi^{2}/ndf = %.2f", test1));
        //((TText*)pave->GetListOfLines()->Last())->SetTextColor(kGreen);
        //pave->AddText(Form("#chi^{2}/ndf = %.2f", test2));
        //((TText*)pave->GetListOfLines()->Last())->SetTextColor(kRed);
        pave->Draw();
    
        auto b = new TBox(xLow, 0.0, xUp, yUp);
        b->SetFillColor(kOrange);
        b->SetFillStyle(3018);
        b->Draw();

        c1->Print(imagesDir + Form("Chi2Test_Pion%dGeV.png", p));
    }
}
