

double gaus (double *x, double *parG) {
    // [constant] * gaus([x], [mean], [sigma], norm=false)
    return parG[0] * TMath::Gaus(x[0], parG[1], parG[2], false);
}


double crystalball_function (double *x, double *parCB) {
    // [constant] * crystalball_function([x], [alpha], [n], [sigma], [mean])
    return parCB[0] * ROOT::Math::crystalball_function(x[0], parCB[1], parCB[2], parCB[3], parCB[4]);
}


double res (double *x, double *parERes) {
    auto rm = TMath::Sqrt(x[0]); 
    return TMath::Sqrt((parERes[0]/rm * parERes[0]/rm) + (parERes[1] * parERes[1]));
}


void beamCalibrationPlots () {

    gStyle->SetOptStat(0);
    gStyle->SetOptFit(111);

    TString eleHistoDir = "~/Projects/ANL/bbcal/histos_newGeo/v2.1/";
    TString eleImagesDir = "~/Projects/ANL/bbcal/images_newGeo/ele/v2.1/";
    TString eleHistoFileName = "beamCalibrationHistos.root";
    TFile eleHistoFile(eleHistoDir + eleHistoFileName, "READ");

    TString pimHistoDir = "~/Projects/ANL/bbcal/histos_newGeo/v2.1/";
    TString pimImagesDir = "~/Projects/ANL/bbcal/images_newGeo/pim/v2.1/";
    TString pimHistoFileName = "pimHistos.root";
    TFile pimHistoFile(pimHistoDir + pimHistoFileName, "READ");

    TFile dataFile("~/Projects/ANL/bbcal/FTBF_data/Energy_Distributions_with_Pions.root", "READ");

    const int nE= 4;
    int Energy[nE] = {4, 6, 8, 10};
    auto nbins = 300;
    int r = 10000;  // [mm]
    float threshold = 0.0010;  // [GeV]
    int p = 0;
    double parG[3];
    double parCB[5];
    double parERes[2];

    Double_t residuals[nbins]; 
    Double_t x[nbins]; 

    Double_t ETrue[nE];
    Double_t eETrue[nE] = {0};

    Double_t E[nE];
    Double_t eE[nE];
    Double_t ERes[nE];
    Double_t eERes[nE];
    Double_t Sig[nE];
    Double_t eSig[nE];

    Double_t EA[nE];
    Double_t eEA[nE];
    Double_t EResA[nE];
    Double_t eEResA[nE];
    Double_t SigA[nE];
    Double_t eSigA[nE];

    Double_t EAT[nE];
    Double_t eEAT[nE];
    Double_t EResAT[nE];
    Double_t eEResAT[nE];
    Double_t SigAT[nE];
    Double_t eSigAT[nE];
    
    Double_t EATC[nE];
    Double_t eEATC[nE];
    Double_t EResATC[nE];
    Double_t eEResATC[nE];
    Double_t SigATC[nE];
    Double_t eSigATC[nE];
    
    for (int i=0; i<nE; i++) {
        p = Energy[i];
        
        //// --------------------------------------------------------------------
        //// Plot Number of Photoelectrons
        //// --------------------------------------------------------------------
        //TString cNameNpe = Form("c_Npe%d", p);
        //TCanvas *cNpe = new TCanvas(cNameNpe, cNameNpe, 1200, 800);

        //TH1F *hNpe = (TH1F*) eleHistoFile.Get(Form("hNpe_r%dm_%dGeV_cut0", r/1000, p));
        ////hNpe->SetAxisRange(0.5*p, 1.5*p);
        //hNpe->Draw();

        //cNpe->Print(eleImagesDir + Form("Npe_%dGeV.png", p));
        //// --------------------------------------------------------------------


        //// --------------------------------------------------------------------
        //// Plot Number of Photoelectrons
        //// --------------------------------------------------------------------
        //TString cNameNpePoisson = Form("c_NpePoisson%d", p);
        //TCanvas *cNpePoisson = new TCanvas(cNameNpePoisson, cNameNpePoisson, 1200, 800);

        //TH1F *hNpePoisson = (TH1F*) eleHistoFile.Get(Form("hNpePoisson_r%dm_%dGeV_cut0", r/1000, p));
        ////hNpe->SetAxisRange(0.5*p, 1.5*p);
        //hNpePoisson->Draw();

        //cNpePoisson->Print(eleImagesDir + Form("NpePoisson_%dGeV.png", p));
        //// --------------------------------------------------------------------


        // --------------------------------------------------------------------
        // Plot Thrown Energy and Fit
        // --------------------------------------------------------------------
        // ele
        TString cNameThrown = Form("c_Thrown%d", p);
        TCanvas *cThrown = new TCanvas(cNameThrown, cNameThrown, 1200, 800);

        TH1F *hEThrown = (TH1F*) eleHistoFile.Get(Form("hEleTrue_%dGeV", p));
        hEThrown->SetAxisRange(0.5*p, 1.5*p);
        hEThrown->Draw();
        ETrue[i] = hEThrown->GetMean();

        // Fit Thrown Energy
        TString fThrownName = Form("ThrownFit_r%dm_%dGeV", r/1000, p);
        TF1 *ThrownFitG = new TF1(fThrownName, gaus, 3.6, 4.4, 3);
        if (p==4) {
            ThrownFitG->SetParameters(1400.0, 4.00, 0.1);
        } else if (p==6) {
            ThrownFitG->SetRange(5.5, 6.5);
            ThrownFitG->SetParameters(1000.0, 6.00, 0.2);
        } else if (p==8) {
            ThrownFitG->SetRange(7.4, 8.6);
            ThrownFitG->SetParameters(1000.0, 8.00, 0.2);
        } else if (p==10) {
            ThrownFitG->SetRange(9.2, 10.8);
            ThrownFitG->SetParameters(1000.0, 10.00, 0.2);
        }
        ThrownFitG->SetParNames("const", "mean", "#sigma");
        hEThrown->Fit(fThrownName, "R");
        ThrownFitG->GetParameters(parG);
        ThrownFitG->SetParameters(parG);
        hEThrown->Fit(fThrownName, "R");
        ThrownFitG->Draw("sames");

        cThrown->Print(eleImagesDir + Form("Ele_%dGeV_Thrown_%dm.png", p, r/1000));
        // --------------------------------------------------------------------


        // --------------------------------------------------------------------
        // Plot Projected Y Endpoints
        // --------------------------------------------------------------------
        //----ele----
        TString cNameY = Form("c_Y%d", p);
        TCanvas *cY = new TCanvas(cNameY, cNameY, 1200, 800);

        TH1F *hY = (TH1F*) eleHistoFile.Get(Form("EndY_r%dm_%dGeV", r/1000, p));
        hY->SetLineColor(kBlack);
        hY->SetLineWidth(2);
        hY->Draw();

        // Fit Projected Y
        TString fYName = Form("YFit_r%dm_%dGeV", r/1000, p);
        TF1 *YFitG = new TF1(fYName, gaus, -42.6, 42.6, 3);
        YFitG->SetParameters(50.0, -5.0, 1.0);
        YFitG->SetParLimits(2, 0.0, 100.0);
        YFitG->SetParNames("const", "mean", "#sigma");
        hY->Fit(fYName, "R");
        YFitG->GetParameters(parG);
        YFitG->SetParameters(parG);
        hY->Fit(fYName, "R");
        YFitG->Draw("sames");

        cY->Print(eleImagesDir + Form("Ele_%dGeV_endY_%dm.png", p, r/1000));
        
        ////----pim----
        TString cNameYPim = Form("c_YPim%d", p);
        TCanvas *cYPim = new TCanvas(cNameYPim, cNameYPim, 1200, 800);

        TH1F *hYPim = (TH1F*) pimHistoFile.Get(Form("Pim_EndY_r%dm_%dGeV_kBnom", r/1000, p));
        hYPim->SetLineColor(kBlack);
        hYPim->SetLineWidth(2);
        hYPim->Draw();

        // Fit Projected Y
        TString fYPimName = Form("YPimFit_r%dm_%dGeV", r/1000, p);
        TF1 *YPimFitG = new TF1(fYPimName, gaus, -42.6, 42.6, 3);
        YPimFitG->SetParameters(50.0, -5.0, 1.0);
        YPimFitG->SetParLimits(2, 0.0, 100.0);
        YPimFitG->SetParNames("const", "mean", "#sigma");
        hYPim->Fit(fYPimName, "R");
        YPimFitG->GetParameters(parG);
        YPimFitG->SetParameters(parG);
        hYPim->Fit(fYPimName, "R");
        YPimFitG->Draw("sames");

        cYPim->Print(pimImagesDir + Form("Pim_%dGeV_endY_%dm.png", p, r/1000));
        // --------------------------------------------------------------------


        // --------------------------------------------------------------------
        // Plot Projected Z Endpoints
        // --------------------------------------------------------------------
        //----ele----
        TString cNameZ = Form("c_Z%d", p);
        TCanvas *cZ = new TCanvas(cNameZ, cNameZ, 1200, 800);

        TH1F *hZ = (TH1F*) eleHistoFile.Get(Form("EndZ_r%dm_%dGeV", r/1000, p));
        hZ->SetLineColor(kBlack);
        hZ->SetLineWidth(2);
        hZ->Draw();

        // Fit Projected Z
        TString fZName = Form("ZFit_r%dm_%dGeV", r/1000, p);
        TF1 *ZFitG = new TF1(fZName, gaus, -80.0, 80.0, 3);
        ZFitG->SetParameters(50.0, 0.0, 1.0);
        ZFitG->SetParLimits(2, 0.0, 100.0);
        ZFitG->SetParNames("const", "mean", "#sigma");
        hZ->Fit(fZName, "R");
        ZFitG->GetParameters(parG);
        ZFitG->SetParameters(parG);
        hZ->Fit(fZName, "R");
        ZFitG->Draw("sames");

        cZ->Print(eleImagesDir + Form("Ele_%dGeV_endZ_%dm.png", p, r/1000));

        //----pim----
        TString cNameZPim = Form("c_ZPim%d", p);
        TCanvas *cZPim = new TCanvas(cNameZPim, cNameZPim, 1200, 800);

        TH1F *hZPim = (TH1F*) pimHistoFile.Get(Form("Pim_EndZ_r%dm_%dGeV_kBnom", r/1000, p));
        hZPim->SetLineColor(kBlack);
        hZPim->SetLineWidth(2);
        hZPim->Draw();

        // Fit Projected Z
        TString fZPimName = Form("ZPimFit_r%dm_%dGeV", r/1000, p);
        TF1 *ZPimFitG = new TF1(fZPimName, gaus, -40.0, 40.0, 3);
        ZPimFitG->SetParameters(3000.0, 0.0, 1.0);
        ZPimFitG->SetParLimits(2, 0.0, 100.0);
        ZPimFitG->SetParNames("const", "mean", "#sigma");
        hZPim->Fit(fZPimName, "R");
        ZPimFitG->GetParameters(parG);
        ZPimFitG->SetParameters(parG);
        hZPim->Fit(fZPimName, "R");
        ZPimFitG->Draw("sames");

        cZPim->Print(pimImagesDir + Form("Pim_%dGeV_endZ_%dm.png", p, r/1000));
        // --------------------------------------------------------------------


        // --------------------------------------------------------------------
        // Plot 2D Projected Endpoints
        // --------------------------------------------------------------------
        //----ele----
        TString cName = Form("c_%d", p);
        TCanvas *c = new TCanvas(cName, cName, 1200, 800);
        
        TH2F *hBeam = (TH2F*) eleHistoFile.Get(Form("EndY_EndZ_r%dm_%dGeV", r/1000, p));
        hBeam->Draw();

        TLine lT;
        lT.SetLineColor(kBlack);
        lT.SetLineWidth(4);
        lT.SetLineStyle(kDashed);
        lT.DrawLine(-100, 42.6, 100, 42.6);

        TLine lB;
        lB.SetLineColor(kBlack);
        lB.SetLineWidth(4);
        lB.SetLineStyle(kDashed);
        lB.DrawLine(-100, -42.6, 100, -42.6);

        TPaveText pave(0.3, 0.77, 0.7, 0.90, "brNDC");
        pave.AddText(Form("#sigma_{y} = %.1fcm", YFitG->GetParameter(2)/10));
        pave.AddText(Form("#sigma_{z} = %.1fcm", ZFitG->GetParameter(2)/10));
        pave.Draw();

        c->Print(eleImagesDir + Form("Ele_%dGeV_%dm.png", p, r/1000));

        ////----pim----
        TString cPimName = Form("cPim_%d", p);
        TCanvas *cPim = new TCanvas(cPimName, cPimName, 1200, 800);
        
        TH2F *hPimBeam = (TH2F*) pimHistoFile.Get(Form("Pim_EndY_EndZ_r%dm_%dGeV_kBnom", r/1000, p));
        hPimBeam->Draw();

        TLine lTPim;
        lTPim.SetLineColor(kBlack);
        lTPim.SetLineWidth(4);
        lTPim.SetLineStyle(kDashed);
        lTPim.DrawLine(-100, 42.6, 100, 42.6);

        TLine lBPim;
        lBPim.SetLineColor(kBlack);
        lBPim.SetLineWidth(4);
        lBPim.SetLineStyle(kDashed);
        lBPim.DrawLine(-100, -42.6, 100, -42.6);

        TPaveText pavePim(0.3, 0.77, 0.7, 0.90, "brNDC");
        pavePim.AddText(Form("#sigma_{y} = %.1fcm", YPimFitG->GetParameter(2)/10));
        pavePim.AddText(Form("#sigma_{z} = %.1fcm", ZPimFitG->GetParameter(2)/10));
        pavePim.Draw();

        cPim->Print(pimImagesDir + Form("Pim_%dGeV_%dm.png", p, r/1000));
        // --------------------------------------------------------------------


        // --------------------------------------------------------------------
        // Plot Deposited Energy and Fit
        // --------------------------------------------------------------------
        TString cNameDep = Form("c_DepA%d", p);
        TCanvas *cDep = new TCanvas(cNameDep, cNameDep, 1200, 800);

        TH1F *hDep = (TH1F*) eleHistoFile.Get(Form("hEleDep_r%dm_%dGeV_cut0", r/1000, p));
        hDep->SetLineColor(kBlack);
        hDep->SetLineWidth(2);
        hDep->Draw();

        // Fit Deposited Energy
        TString fNameDep = Form("DepFit_r%d_%dGeV", r/1000, p);
        TF1 *DepFitCB = new TF1(fNameDep, crystalball_function, 0.02*p, 0.15*p, 5);
        if (p==4) {
            DepFitCB->SetParameters(18000.0, 1.00, 1.0, 0.02, 0.4);
        } else if (p==6) {
            DepFitCB->SetRange(0.02*p, 0.15*p);
            DepFitCB->SetParameters(22000.0, 1.00, 1.0, 0.02, 0.6);
        } else if (p==8) {
            DepFitCB->SetRange(0.02*p, 0.15*p);
            DepFitCB->SetParameters(22000.0, 1.00, 1.0, 0.02, 0.8);
        } else if (p==10) {
            DepFitCB->SetRange(0.02*p, 0.15*p);
            DepFitCB->SetParameters(22000.0, 1.00, 1.0, 0.02, 1.0);
        }
        DepFitCB->SetParNames("const", "#alpha", "n", "#sigma", "mean");
        hDep->Fit(fNameDep, "R");
        DepFitCB->GetParameters(parCB);
        DepFitCB->SetParameters(parCB);
        hDep->Fit(fNameDep, "R");
        DepFitCB->Draw("sames");
        
        cDep->Print(eleImagesDir + Form("Ele_%dGeV_Dep_%dm.png", p, r/1000));

        // Calculate Energy Resolution
        Sig[i] = DepFitCB->GetParameter(3);
        eSig[i] = DepFitCB->GetParError(3);
        E[i] = DepFitCB->GetParameter(4);
        eE[i] = DepFitCB->GetParError(4);
        ERes[i] = Sig[i] / E[i];
        eERes[i] = ERes[i] * TMath::Sqrt((eSig[i]/Sig[i])*(eSig[i]/Sig[i]) + (eE[i]/E[i])*(eE[i]/E[i]));
        // --------------------------------------------------------------------

        
        // --------------------------------------------------------------------
        // Plot Deposited Energy after Threshold Cut and Fit
        // --------------------------------------------------------------------
        // Threshold by Cell
        TString cNameDepAT = Form("c_DepAT%d", p);
        TCanvas *cDepAT = new TCanvas(cNameDepAT, cNameDepAT, 1200, 800);

        TH1F *hDepAT = (TH1F*) eleHistoFile.Get(Form("hEleDep_r%dm_%dGeV_cut2", r/1000, p));
        hDepAT->SetLineColor(kBlack);
        hDepAT->SetLineWidth(2);
        hDepAT->Draw();

        // Fit Deposited Energy after Threshold Cut
        TString fNameDepAT = Form("DepATFit_r%dm_%dGeV", r/1000, p);
        TF1 *DepATFitCB = new TF1(fNameDepAT, crystalball_function, 0.02*p, 0.15*p, 5);
        if (p==4) {
            DepATFitCB->SetParameters(20000.0, 1.00, 1.0, 0.02, 0.4);
        } else if (p==6) {
            DepATFitCB->SetRange(0.02*p, 0.15*p);
            DepATFitCB->SetParameters(22000.0, 1.00, 1.0, 0.02, 0.6);
        } else if (p==8) {
            DepATFitCB->SetRange(0.02*p, 0.15*p);
            DepATFitCB->SetParameters(22000.0, 1.00, 1.0, 0.02, 0.8);
        } else if (p==10) {
            DepATFitCB->SetRange(0.02*p, 0.15*p);
            DepATFitCB->SetParameters(22000.0, 1.00, 1.0, 0.02, 1.0);
        }
        DepATFitCB->SetParNames("const", "#alpha", "n", "#sigma", "mean");
        hDepAT->Fit(fNameDepAT, "R");
        DepATFitCB->GetParameters(parCB);
        DepATFitCB->SetParameters(parCB);
        hDepAT->Fit(fNameDepAT, "R");
        DepATFitCB->Draw("sames");
        
        cDepAT->Print(eleImagesDir + Form("Ele_%dGeV_DepAT_%dm_T_%.1fMeV.png", p, r/1000, threshold*1000));

        // Calculate Energy Resolution after Threshold Cut
        SigAT[i] = DepATFitCB->GetParameter(3);
        eSigAT[i] = DepATFitCB->GetParError(3);
        EAT[i] = DepATFitCB->GetParameter(4);
        eEAT[i] = DepATFitCB->GetParError(4);
        EResAT[i] = SigAT[i] / EAT[i];
        eEResAT[i] = EResAT[i] * TMath::Sqrt((eSigAT[i]/SigAT[i])*(eSigAT[i]/SigAT[i]) + (eEAT[i]/EAT[i])*(eEAT[i]/EAT[i]));
        // --------------------------------------------------------------------


        // --------------------------------------------------------------------
        // Plot Deposited Energy after Centrality and Threshold Cuts and Fit
        // --------------------------------------------------------------------
        // By Cell
        TString cNameDepATC = Form("c_DepATC%d", p);
        TCanvas *cDepATC = new TCanvas(cNameDepATC, cNameDepATC, 1200, 800);

        TH1F *hDepATC = (TH1F*) eleHistoFile.Get(Form("hEleDep_r%dm_%dGeV_cut3", r/1000, p));
        hDepATC->SetLineColor(kBlack);
        hDepATC->SetLineWidth(2);
        hDepATC->Draw();

        // Fit Deposited Energy after Threshold and Centrality Cut
        TString fNameDepATC = Form("DepATCFit_r%dm_%dGeV", r/1000, p);
        TF1 *DepATCFitCB = new TF1(fNameDepATC, crystalball_function, 0.02*p, 0.15*p, 5);
        if (p==4) {
            DepATCFitCB->SetParameters(10000.0, 1.00, 1.0, 0.02, 0.4);
        } else if (p==6) {
            DepATCFitCB->SetRange(0.02*p, 0.15*p);
            DepATCFitCB->SetParameters(14000.0, 1.00, 1.0, 0.02, 0.6);
        } else if (p==8) {
            DepATCFitCB->SetRange(0.02*p, 0.15*p);
            DepATCFitCB->SetParameters(16000.0, 1.00, 1.0, 0.02, 0.8);
        } else if (p==10) {
            DepATCFitCB->SetRange(0.02*p, 0.15*p);
            DepATCFitCB->SetParameters(16000.0, 1.00, 1.0, 0.02, 1.0);
        }
        DepATCFitCB->SetParNames("const", "#alpha", "n", "#sigma", "mean");
        hDepATC->Fit(fNameDepATC, "R");
        DepATCFitCB->GetParameters(parCB);
        DepATCFitCB->SetParameters(parCB);
        hDepATC->Fit(fNameDepATC, "R");
        DepATCFitCB->Draw("sames");
        
        cDepATC->Print(eleImagesDir + Form("Ele_%dGeV_DepATC_%dm_T_%.1fMeV.png", p, r/1000, threshold*1000));

        // Calculate Energy Resolution after Threshold Cut
        SigATC[i] = DepATCFitCB->GetParameter(3);
        eSigATC[i] = DepATCFitCB->GetParError(3);
        EATC[i] = DepATCFitCB->GetParameter(4);
        eEATC[i] = DepATCFitCB->GetParError(4);
        EResATC[i] = SigATC[i] / EATC[i];
        eEResATC[i] = EResATC[i] * TMath::Sqrt((eSigATC[i]/SigATC[i])*(eSigATC[i]/SigATC[i]) + (eEATC[i]/EATC[i])*(eEATC[i]/EATC[i]));
        // --------------------------------------------------------------------


        //// --------------------------------------------------------------------
        //// Plot Deposited Energy by Cell after Threshold Cut
        //// --------------------------------------------------------------------
        //for (int g=0; g<4; g++) {
        //    for (int l=0; l<4; l++) {
        //        TString cNameCh = Form("c_Cell_g%d_l%d_%dGeV", g, l, p);
        //        TCanvas *cCh = new TCanvas(cNameCh, cNameCh, 1200, 800);
        //        gPad->SetLogy();

        //        TH1F *hBefore = (TH1F*) eleHistoFile.Get(Form("hEleDep_%dGeV_cell(%d,%d)_cut%d", p, g, l, 0));
        //        TH1F *hAfterT = (TH1F*) eleHistoFile.Get(Form("hEleDep_%dGeV_cell(%d,%d)_cut%d", p, g, l, 1));
        //        hBefore->SetLineColor(kRed);
        //        hAfterT->SetLineColor(kBlue);
        //        hBefore->Draw();
        //        hAfterT->Draw("sames");

        //        cCh->Print(eleImagesDir + Form("Ele_%dGeV_Dep_%dm_threshold_%.1fMeV_g%dl%d.png", p, r/1000, threshold*1000, g, l));
        //    }
        //}
        // --------------------------------------------------------------------


        // --------------------------------------------------------------------
        // Plot Calibrated Energy
        // --------------------------------------------------------------------
        TString cCalName= Form("c_Cal%d", p);
        TCanvas *cCal = new TCanvas(cCalName, cCalName, 1200, 800);
        gPad->SetLogy();

        TH1F *hPion_data = (TH1F*) dataFile.Get(Form("h%dGeV_pion", p));
        TH1F *hData = (TH1F*) (hPion_data->Clone("hData"));
        hData->SetAxisRange(0.1, 1.8*p);
        hData->SetMaximum(0.4);
        //Double_t intData= hData->Integral();
        Double_t intData= hData->Integral(hData->FindBin(0.2*p), hData->FindBin(1.0*p));
        hData->SetLineColor(kBlack);
        hData->SetLineWidth(2);
        hData->SetTitle(Form("e/#pi %dGeV; E_{cal}; Normalized Counts", p));
        hData->Draw();

        TH1F *hEleCal = (TH1F*) eleHistoFile.Get(Form("hEleCal_r%dm_%dGeV_cut3", r/1000, p));
        TH1F *hMCE = (TH1F*) (hEleCal->Clone("hMCE"));
        hMCE->SetAxisRange(0.1, 1.5*p);
        //Double_t intMCE = hMCE->Integral();
        Double_t intMCE = hMCE->Integral(hMCE->FindBin(0.2*p), hMCE->FindBin(1.0*p));
        Double_t factorE = 1 / intMCE;
        if (hMCE->GetSumw2N() == 0) hMCE->Sumw2(kTRUE);
        hMCE->Scale(factorE);
        hMCE->SetLineColor(kBlue+2);
        hMCE->SetLineWidth(2);
        hMCE->Draw("sames");

        //TH1F *hPion_mc_kBnom = (TH1F*) pimHistoFile.Get(Form("hPimCal_%dGeV_APC_T_kBnom", p));
        TH1F *hPion_mc_kBnom = (TH1F*) pimHistoFile.Get(Form("hPimCal_%dGeV_APC_TC_kBnom", p));
        TH1F *hMC0= (TH1F*) (hPion_mc_kBnom->Clone("hMC0"));
        hMC0->SetAxisRange(0.1, 1.8*p);
        //Double_t intMC0= hMC0->Integral();
        Double_t intMC0= hMC0->Integral(hMC0->FindBin(0.2*p), hMC0->FindBin(1.0*p));
        Double_t factor0 = intData/intMC0;
        if (hMC0->GetSumw2N() == 0) hMC0->Sumw2(kTRUE);
        hMC0->Scale(factor0);
        hMC0->SetLineColor(kBlue);
        hMC0->SetLineWidth(2);
        hMC0->Draw("sames");

        ////TH1F *hPion_mc_kBlow = (TH1F*) pimHistoFile.Get(Form("hPimCal_%dGeV_APC_T_kBlow", p));
        //TH1F *hPion_mc_kBlow = (TH1F*) pimHistoFile.Get(Form("hPimCal_%dGeV_APC_TC_kBlow", p));
        //TH1F *hMC1= (TH1F*) (hPion_mc_kBlow->Clone("hMC1"));
        //hMC1->SetAxisRange(0.1, 1.8*p);
        //Double_t intMC1= hMC1->Integral();
        ////Double_t intMC1= hMC1->Integral(hData->FindBin(3.0), hData->FindBin(4.0));
        //Double_t factor1 = intData/intMC1;
        //if (hMC1->GetSumw2N() == 0) hMC1->Sumw2(kTRUE);
        //hMC1->Scale(factor1);
        //hMC1->SetLineColor(kGreen);
        //hMC1->SetLineWidth(2);
        //hMC1->Draw("sames");

        ////TH1F *hPion_mc_kBup = (TH1F*) pimHistoFile.Get(Form("hPimCal_%dGeV_APC_T_kBup", p));
        //TH1F *hPion_mc_kBup = (TH1F*) pimHistoFile.Get(Form("hPimCal_%dGeV_APC_TC_kBup", p));
        //TH1F *hMC2= (TH1F*) (hPion_mc_kBup->Clone("hMC2"));
        //hMC2->SetAxisRange(0.1, 1.8*p);
        //Double_t intMC2= hMC2->Integral();
        ////Double_t intMC2= hMC2->Integral(hData->FindBin(3.0), hData->FindBin(4.0));
        //Double_t factor2 = intData/intMC2;
        //if (hMC2->GetSumw2N() == 0) hMC2->Sumw2(kTRUE);
        //hMC2->Scale(factor2);
        //hMC2->SetLineColor(kRed);
        //hMC2->SetLineWidth(2);
        //hMC2->Draw("sames");

        //auto leg = new TLegend(0.65, 0.65, 0.90, 0.90);
        //leg->AddEntry(hMCE, "e- Sim", "lep");
        //leg->AddEntry(hData, "#pi- Data", "lep");
        //leg->AddEntry(hMC0, "Sim, kB = 0.126 #frac{mm}{MeV}", "lep");
        ////leg->AddEntry(hMC1, "Sim, kB = 0.063 #frac{mm}{MeV}", "lep");
        ////leg->AddEntry(hMC2, "Sim, kB = 0.189 #frac{mm}{MeV}", "lep");
        //leg->Draw();

        hData->SetAxisRange(3.0, 4.5);
        hMC0->SetAxisRange(3.0, 4.5);
        //hMC1->SetAxisRange(3.0, 4.5);
        //hMC2->SetAxisRange(3.0, 4.5);
        //auto test0 = hData->Chi2Test(hMC0, "WW P", residuals);
        auto test0 = hData->Chi2Test(hMC0, "WW CHI2/NDF", residuals);
        //auto test1 = hData->Chi2Test(hMC1, "WW CHI2/NDF", residuals);
        //auto test2 = hData->Chi2Test(hMC2, "WW CHI2/NDF", residuals);
        
        //cCal->Print(pimImagesDir + Form("ElePimCal_%dGeV.png", p));
        cCal->Print(pimImagesDir + Form("ElePimCal_C_%dGeV.png", p));


    }

    // Energy Resolution from Beam Test
    Double_t EBT[nE] = {0.048, 0.043, 0.039, 0.036};
    auto gEResBT = new TGraph(nE, ETrue, EBT);
    gEResBT->SetTitle("Beam Test");
    //double parERes[2];
    //auto EResFitBT = new TF1("EResFitBT", res, 0.0, 1.0, 2);
    //EResFitBT->SetLineColor(kGreen);
    //EResFitBT->SetLineStyle(kDashed);
    //EResFitBT->SetParNames("A", "B");
    //EResFitBT->SetParameters(0.0468, 0.02043);
    //gEResBT->Fit("EResFitBT");  //!!!Do not use the "R" option with TGraph!!!
    //EResFitBT->GetParameters(parERes);
    //EResFitBT->SetParameters(parERes);
    //gEResBT->Fit("EResFitBT");
    gEResBT->SetMarkerColor(kCyan);
    gEResBT->SetMarkerStyle(21);
    gEResBT->SetMarkerSize(2);

    // Fit Energy Resolution
    auto gERes= new TGraphErrors(nE, ETrue, ERes, eETrue, eERes);
    gERes->SetTitle("Simulation");
    //auto EResFit = new TF1("EResFit", res, 0.0, 1.0, 2);
    //EResFit->SetLineColor(kRed);
    //EResFit->SetParNames("A", "B");
    //EResFit->SetParameters(0.0468, 0.02043);
    //gERes->Fit("EResFit");  //!!!Do not use the "R" option with TGraph!!!
    //EResFit->GetParameters(parERes);
    //EResFit->SetParameters(parERes);
    //gERes->Fit("EResFit");
    gERes->SetMarkerColor(kRed);
    gERes->SetMarkerStyle(20);
    gERes->SetMarkerSize(1);

    // Fit Energy Resolution after Threshold Cut
    auto gEResAT= new TGraphErrors(nE, ETrue, EResAT, eETrue, eEResAT);
    gEResAT->SetTitle("Simulation A&T");
    //auto EResFitT = new TF1("EResFitT", res, 0.0, 1.0, 2);
    //EResFitT->SetLineColor(kBlue);
    //EResFitT->SetParNames("A", "B");
    //EResFitT->SetParameters(0.0468, 0.02043);
    //gEResT->Fit("EResFitT");  //!!!Do not use the "R" option with TGraph!!!
    //EResFitT->GetParameters(parERes);
    //EResFitT->SetParameters(parERes);
    //gEResT->Fit("EResFitT");
    gEResAT->SetMarkerColor(kBlue);
    gEResAT->SetMarkerStyle(20);
    gEResAT->SetMarkerSize(1);

    // Fit Energy Resolution after Threshold and Centrality Cut
    auto gEResATC= new TGraphErrors(nE, ETrue, EResATC, eETrue, eEResATC);
    //gEResCT->SetTitle("Simulation with Threshold and Centrality Cuts Applied");
    gEResATC->SetTitle("Simulation");
    //gEResATC->SetTitle("Simulation A,T,&C");
    //auto EResFitCT = new TF1("EResFitCT", res, 0.0, 1.0, 2);
    //EResFitCT->SetLineColor(kMagenta);
    //EResFitCT->SetParNames("A", "B");
    //EResFitCT->SetParameters(0.0468, 0.02043);
    //gEResCT->Fit("EResFitCT");  //!!!Do not use the "R" option with TGraph!!!
    //EResFitCT->GetParameters(parERes);
    //EResFitCT->SetParameters(parERes);
    //gEResCT->Fit("EResFitCT");
    gEResATC->SetMarkerColor(kMagenta+2);
    gEResATC->SetMarkerStyle(20);
    gEResATC->SetMarkerSize(2);

    //// Plot Energy Resolution
    //TCanvas *c_gERes = new TCanvas("c_gERes", "c_gERes", 1200, 800);
    //c_gERes->SetGrid();
    //gERes->SetMinimum(0.03);
    //gERes->SetMaximum(0.05);
    //gERes->SetTitle("Energy Resolution; E_{true}; #sigma_{E}/E");
    //gERes->SetMarkerStyle(7);
    //gERes->Draw("AP");
    //TLine lConst(3.5, EResFit->GetParameter(1), 10.5, EResFit->GetParameter(1));
    //lConst.SetLineColor(kOrange+2);
    //lConst.SetLineWidth(4);
    //lConst.SetLineStyle(kDashed);
    //lConst.Draw("sames");
    //TPaveText pt(0.3, 0.73, 0.6, 0.89, "brNDC");
    //pt.AddText("Fit Function:  #frac{#sigma_{E}}{E} = #frac{A}{#sqrt{E}} #oplus B");
    //pt.Draw();
    //c_gERes->Print(eleImagesDir + "ERes.png");

    //// Plot Energy Resolution after Threshold Cut
    //TCanvas *c_gEResT = new TCanvas("c_gEResT", "c_gEResT", 1200, 800);
    //c_gEResT->SetGrid();
    //gEResT->SetMinimum(0.03);
    //gEResT->SetMaximum(0.05);
    //gEResT->SetTitle("Energy Resolution after Threshold Cut; E_{true}; #sigma_{E}/E");
    //gEResT->SetMarkerStyle(7);
    //gEResT->Draw("AP");
    //TLine lConstT(3.5, EResFitT->GetParameter(1), 10.5, EResFitT->GetParameter(1));
    //lConstT.SetLineColor(kOrange+2);
    //lConstT.SetLineWidth(4);
    //lConstT.SetLineStyle(kDashed);
    //lConstT.Draw("sames");
    ////TPaveText ptT(0.3, 0.73, 0.6, 0.89, "brNDC");
    ////ptT.AddText("Fit Function:  #frac{#sigma_{E}}{E} = #frac{A}{#sqrt{E}} #oplus B");
    //pt.Draw();
    //c_gEResT->Print(eleImagesDir + "EResT.png");

    TCanvas *c_EResCompare = new TCanvas("c_EResCompare", "c_EResCompare", 1200, 800);
    c_EResCompare->SetGrid();

    auto mg = new TMultiGraph();
    mg->SetMinimum(0.0);
    mg->SetMaximum(0.07);
    mg->Add(gEResBT);
    //mg->Add(gERes);
    //mg->Add(gEResAT);
    mg->Add(gEResATC);
    mg->Draw("AP");
    mg->GetXaxis()->SetLimits(2.0, 12.0);
    mg->GetXaxis()->SetTitle("E_{true}");
    mg->GetYaxis()->SetTitle("#sigma_{E}/E");
    mg->GetHistogram()->SetTitle("Electron Energy Resolution Comparison");

    Double_t sigDiff4 = TMath::Sqrt(EBT[0]*EBT[0] - (EResATC[0]*EResATC[0] - 0.027*0.027));
    Double_t sigDiff6 = TMath::Sqrt(EBT[1]*EBT[1] - (EResATC[1]*EResATC[1] - 0.027*0.027));
    Double_t sigDiff8 = TMath::Sqrt(EBT[2]*EBT[2] - (EResATC[2]*EResATC[2] - 0.027*0.027));
    Double_t sigDiff10 = TMath::Sqrt(EBT[3]*EBT[3] - (EResATC[3]*EResATC[3] - 0.027*0.027));
    
    TPaveText pt(0.11, 0.11, 0.50, 0.50, "trNDC");
    //pt.AddText(     "                   Data     MC     Adjust");
    //pt.AddText(Form(" 4GeV:       0.048,   %.3f,    %.4f", EResATC[0], sigDiff4));
    //pt.AddText(Form(" 6GeV:       0.043,   %.3f,    %.4f", EResATC[1], sigDiff6));
    //pt.AddText(Form(" 8GeV:       0.039,   %.3f,    %.4f", EResATC[2], sigDiff8));
    //pt.AddText(Form("10GeV:       0.036,   %.3f,    %.3f", EResATC[3], sigDiff10));
    //pt.AddText(     "                   Data    MC     Beam");
    //pt.AddText(Form(" 4GeV:       0.048   %.3f    3.5%%", EResATC[0]));
    //pt.AddText(Form(" 6GeV:       0.043   %.3f    3.2%%", EResATC[1]));
    //pt.AddText(Form(" 8GeV:       0.039   %.3f    2.8%%", EResATC[2]));
    //pt.AddText(Form("10GeV:       0.036   %.3f    2.6%%", EResATC[3]));
    pt.AddText(     "                   Data    MC     Beam");
    pt.AddText(Form(" 4GeV:       0.048,   %.3f,    2.7%%", EResATC[0]));
    pt.AddText(Form(" 6GeV:       0.043,   %.3f,    2.7%%", EResATC[1]));
    pt.AddText(Form(" 8GeV:       0.039,   %.3f,    2.7%%", EResATC[2]));
    pt.AddText(Form("10GeV:       0.036,   %.3f,    2.7%%", EResATC[3]));
    //pt.AddText(     "         BeamTest  SimAT");
    //pt.AddText(Form(" 4GeV:    0.048,   %.3f", EResAT[0]));
    //pt.AddText(Form(" 6GeV:    0.043,   %.3f", EResAT[1]));
    //pt.AddText(Form(" 8GeV:    0.039,   %.3f", EResAT[2]));
    //pt.AddText(Form("10GeV:    0.036,   %.3f", EResAT[3]));
    pt.Draw();

    //TPaveText pt(0.70, 0.74, 0.90, 0.84, "brNDC");
    //pt.AddText("Fit Function:  #frac{#sigma_{E}}{E} = #frac{A}{#sqrt{E}} #oplus B");
    //pt.Draw();
    //c_EResCompare->Update();  //force drawing of canvas to generate the fit TPaveStats
    //auto statsBT = (TPaveStats*) gEResBT->GetListOfFunctions()->FindObject("stats");
    //auto statsERes = (TPaveStats*) gERes->GetListOfFunctions()->FindObject("stats");
    //auto statsEResT = (TPaveStats*) gEResT->GetListOfFunctions()->FindObject("stats");
    //auto statsEResCT = (TPaveStats*) gEResCT->GetListOfFunctions()->FindObject("stats");
    //if (statsBT && statsERes && statsEResT && statsEResCT) {
    //    statsBT->SetTextColor(kGreen);
    //    statsERes->SetTextColor(kRed);
    //    statsEResT->SetTextColor(kBlue);
    //    statsEResCT->SetTextColor(kMagenta);
    //    statsBT->SetX1NDC(0.12); statsBT->SetX2NDC(0.32); statsBT->SetY1NDC(0.84);
    //    statsERes->SetX1NDC(0.33); statsERes->SetX2NDC(0.53); statsERes->SetY1NDC(0.84);
    //    statsEResT->SetX1NDC(0.54); statsEResT->SetX2NDC(0.74); statsEResT->SetY1NDC(0.84);
    //    statsEResCT->SetX1NDC(0.75); statsEResCT->SetX2NDC(0.95); statsEResCT->SetY1NDC(0.84);
    //    c_EResCompare->Modified();
    //}

    auto leg = new TLegend(0.65, 0.75, 0.90, 0.90);
    leg->AddEntry(gEResBT, "Beam Test", "ep");
    leg->AddEntry(gEResATC, "Monte Carlo", "ep");
    leg->Draw();
        
    //c_EResCompare->BuildLegend();
    c_EResCompare->Print(eleImagesDir + Form("EResCompare_T_%.1fMeV.png", threshold*1000));

}

