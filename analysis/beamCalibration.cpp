

TH1F* hDepAHits(int Energy, int nbins, int r, int cut){
    TH1F* h = new TH1F(Form("hDepA_r%dm_%dGeV_cut%d", r/1000, Energy, cut),
                       Form("e- %d GeV Attenuated, r = %dm, cut:%d; E_{dep}; bin count", Energy, r/1000, cut),
                       nbins, 0.0, 0.2*Energy);
    return h;
}


TH1F* hDepAPHits(int Energy, int nbins, int r, int cut){
    TH1F* h = new TH1F(Form("hDepAP_r%dm_%dGeV_cut%d", r/1000, Energy, cut),
                       Form("e- %d GeV Attenuation, r = %dm, cut:%d; E_{dep}; bin count", Energy, r/1000, cut),
                       nbins, 0.0, 0.2*Energy);
    return h;
}


TH1F* hDepAPCHits(int Energy, int nbins, int r, int cut){
    TH1F* h = new TH1F(Form("hDepAPC_r%dm_%dGeV_cut%d", r/1000, Energy, cut),
                       Form("e- %d GeV Attenuated, Poissonian Smeared, and Corrected back, r = %dm, cut:%d; E_{dep}; bin count", Energy, r/1000, cut),
                       nbins, 0.0, 0.2*Energy);
    return h;
}


TH1F hCellHits(int Energy, int nbins, int grid, int layer, int cut){
    TH1F h(Form("hEleDep_%dGeV_cell(%d,%d)_cut%d", Energy, grid, layer, cut),
           Form("e- %d GeV Nominal Energy, cell(%d,%d); E_{dep} [GeV]; bin count", Energy, grid, layer),
           nbins, -0.001*Energy, 0.075*Energy);
    return h;
}


TH1F hCellAHits(int Energy, int nbins, int r, int g, int l, int cut){
    TH1F h(Form("hCellA_r%dm_%dGeV_g%d_l%d_cut%d", r/1000, Energy, g, l, cut),
                       Form("e- %d GeV Attenuated, cell(%d, %d); E_{dep}; bin count", Energy, g, l),
                       nbins, 0.0, 0.2*Energy);
    return h;
}


TH1F hCellAPHits(int Energy, int nbins, int r, int g, int l, int cut){
    TH1F h(Form("hCellAP_r%dm_%dGeV_g%d_l%d_cut%d", r/1000, Energy, g, l, cut),
                       Form("e- %d GeV Attenuated and Smeared, cell(%d, %d); E_{dep}; bin count", Energy, g, l),
                       nbins, 0.0, 0.2*Energy);
    return h;
}


TH1F hCellAPCHits(int Energy, int nbins, int r, int g, int l, int cut){
    TH1F h(Form("hCellAPC_r%dm_%dGeV_g%d_l%d_cut%d", r/1000, Energy, g, l, cut),
                       Form("e- %d GeV Attenuated, Smeared, and Corrected, cell(%d, %d); E_{dep}; bin count", Energy, g, l),
                       nbins, 0.0, 0.2*Energy);
    return h;
}


TH1F* hAttenFactor(int Energy, int nbins, int r, int cut){
    TH1F* h = new TH1F(Form("hAttenFactor%dm_%dGeV_cut%d", r/1000, Energy, cut),
                       Form("e- %d GeV, Attenuation Factor Cut%d; npePerGeV(distance)/npePerGeV(0); bin count", Energy, cut),
                       nbins, 0.75, 1.0);
    return h;
}


TH1F hSipmHits(int Energy, int nbins, int grid, int layer, int cut){
    TH1F h(Form("hDep_%dGeV_sipm(%d,%d)_cut%d", Energy, grid, layer, cut),
           Form("e- %d GeV Nominal Energy, sipm(%d,%d); E_{dep} [GeV]; bin count", Energy, grid, layer),
           nbins, -0.001*Energy, 0.075*Energy);
    return h;
}


TH1F hSipmAHits(int Energy, int nbins, int grid, int layer, int cut){
    TH1F h(Form("hDepA_%dGeV_sipm(%d,%d)_cut%d", Energy, grid, layer, cut),
           Form("e- %d GeV Attenuated Energy, sipm(%d,%d); E_{dep} [GeV]; bin count", Energy, grid, layer),
           nbins, -0.001*Energy, 0.075*Energy);
    return h;
}


TH1F hSipmAPHits(int Energy, int nbins, int grid, int layer, int cut){
    TH1F h(Form("hDepAP_%dGeV_sipm(%d,%d)_cut%d", Energy, grid, layer, cut),
           Form("e- %d GeV Attenuated and Smeared Energy, sipm(%d,%d); E_{dep} [GeV]; bin count", Energy, grid, layer),
           nbins, -0.001*Energy, 0.075*Energy);
    return h;
}


TH1F hSipmAPCHits(int Energy, int nbins, int grid, int layer, int cut){
    TH1F h(Form("hDepAPC_%dGeV_sipm(%d,%d)_cut%d", Energy, grid, layer, cut),
           Form("e- %d GeV Attenuated, Smeared, and Corrected Back Energy, sipm(%d,%d); E_{dep} [GeV]; bin count", Energy, grid, layer),
           nbins, -0.001*Energy, 0.075*Energy);
    return h;
}


TH1F* hNpeHits(int Energy, int nbins, int r, int cut){
    TH1F* h = new TH1F(Form("hNpe_r%dm_%dGeV_cut%d", r/1000, Energy, cut),
                       Form("e- %d GeV Number of Photoelectrons, r = %dm, cut:%d; npe; bin count", Energy, r/1000, cut),
               nbins, 0.0, 2000*Energy);
    return h;
}


TH1F* hNpePoissonHits(int Energy, int nbins, int r, int cut){
    TH1F* h = new TH1F(Form("hNpePoisson_r%dm_%dGeV_cut%d", r/1000, Energy, cut),
                       Form("e- %d GeV Number of Photoelectrons Poisson Smeared, r = %dm, cut:%d; npe; bin count", Energy, r/1000, cut),
                       nbins, 0.0, 2000*Energy);
    return h;
}


TH1F* hHits(int Energy, int nbins, int r, int cut){
    TH1F* h = new TH1F(Form("hEleDep_r%dm_%dGeV_cut%d", r/1000, Energy, cut),
                       Form("e- %d GeV Deposited Energy, r = %dm, cut:%d; E_{dep} [GeV]; bin count", Energy, r/1000, cut),
                       nbins, -0.001*Energy, 0.2*Energy);
    return h;
}


TH1F* hHitsDep(int Energy, int nbins, int r, int cut){
    TH1F* h = new TH1F(Form("hEleDep_r%dm_%dGeV_cut%d", r/1000, Energy, cut),
                       Form("e- %d GeV Deposited Energy, r = %dm, cut:%d; E_{dep} [GeV]; bin count", Energy, r/1000, cut),
                       nbins, -0.01*Energy, 0.2*Energy);
    return h;
}


TH1F* hHitsCal(int Energy, int nbins, int r, int cut){
    TH1F* h = new TH1F(Form("hEleCal_r%dm_%dGeV_cut%d", r/1000, Energy, cut),
                       Form("e- %d GeV Deposited Energy, r = %dm, cut:%d; E_{cal} [GeV]; bin count", Energy, r/1000, cut),
                       nbins, -0.01*Energy, 2.0*Energy);
    return h;
}


TH1F hCTHits(int Energy, int nbins, int r, float threshold){
    TH1F h(Form("hEleDepCentral_r%dm_%dGeV_threshold%.1fMeV", r/1000, Energy, threshold*1000),
           Form("e- %d GeV Centrality Assured Deposited Energy, r = %dm, threshold = %.1fMeV; E_{dep} [GeV]; bin count", Energy, r/1000, threshold*1000),
           nbins, 0.0, 0.2*Energy);
    return h;
}


TH1F hRowHits(int Energy, int nbins, int grid, float threshold){
    TH1F h(Form("hEleDep_%dGeV_grid%d", Energy, grid),
           Form("e- %d GeV Deposited Energy, Grid = %d, Threshold = %.1fMeV; E_{dep} [GeV]; bin count", Energy, grid, threshold*1000),
           nbins, 0.025*Energy, 0.15*Energy);
    return h;
}


TH1F* hCal(int Energy, int nbins){
    TH1F* h = new TH1F(Form("hEleCal_%dGeV", Energy),
                       Form("e^{-} %d GeV Ratio of Deposited Energy and Sampling Fraction; E_{cal} [GeV]; bin count", Energy),
                       nbins, -0.1*Energy, 1.5*Energy);
    return h;
}


TH1F hPimDep(int Energy, int nbins, int nkB){
    TString kBString[4] = {"kBnom", "kBlow", "kBup", "kBzero"};
    TH1F h(Form("hPimDep_%dGeV_%s", Energy, kBString[nkB].Data()),
           Form("#pi- %d GeV Deposited Energy; E_{cal} [GeV]; bin count", Energy),
           nbins, -0.01*Energy, 0.15*Energy);
    return h;
}


TH1F hPimCal(int Energy, int nbins, int nkB){
    TString kBString[4] = {"kBnom", "kBlow", "kBup", "kBzero"};
    TH1F h(Form("hPimCal_%dGeV_%s", Energy, kBString[nkB].Data()),
           Form("#pi- %d GeV Calibrated Energy; E_{cal} [GeV]; bin count", Energy),
           nbins, -0.1*Energy, 1.5*Energy);
    return h;
}


TH1F hEndY(int Energy, int nbins, int r){
    TH1F h(Form("EndY_r%dm_%dGeV", r/1000, Energy),
           Form("e- %d GeV (Projected) Y, r = %dm; (Projected) MCParticles.endpoint.y [mm]; bin count", Energy, r/1000),
           nbins, -100, 100);
    return h;
}


TH1F hEndZ(int Energy, int nbins, int r){
    TH1F h(Form("EndZ_r%dm_%dGeV", r/1000, Energy),
           Form("e- %d GeV (Projected) Z, r = %dm; (Projected) MCParticles.endpoint.z [mm]; bin count", Energy, r/1000),
           nbins, -100, 100);
    return h;
}


TH2F hBeamProfile(int Energy, int nbins, int r){
    TH2F h(Form("EndY_EndZ_r%dm_%dGeV", r/1000, Energy),
           Form("e- %d GeV (Projected) Y/Z, r = %dm; (Projected) MCParticles.endpoint.z [mm]; (Projected) MCParticles.endpoint.y [mm]", Energy, r/1000),
           nbins, -100, 100, nbins, -100, 100);
    return h;
}


TH1F hTrue(int Energy, int nbins){
    TH1F h(Form("hEleTrue_%dGeV", Energy),
           Form("e- %d GeV Thrown Energy; E_{true}; bin count", Energy),
           nbins, 0.0, 1.5*Energy);
    return h;
}


double SylvestersFormula (double *x, double *parSyl) {
    // [I0] * ([alpha] * Exp(-[x]/[lambda1]) + (1-[alpha]) * Exp(-[x]/[lambda2]))
    return parSyl[0] * (parSyl[1] * TMath::Exp(-x[0]/parSyl[2]) + (1-parSyl[1]) * TMath::Exp(-x[0]/parSyl[3]));
}


void beamCalibration(){


    //--------------------------------------------------------------------------
    //---------------------------Control Panel----------------------------------
    auto nbins = 300;
    int r = 10000;  // [mm]
    float threshold = 0.0010;  // [GeV]
    
    TString imagesDir = "~/Projects/ANL/bbcal/images_newGeo/ele/v2.1/";
    TString simDir = "~/Projects/ANL/bbcal/sims_newGeo/v2.1/";
    TString histoDir = "~/Projects/ANL/bbcal/histos_newGeo/v2.1/";
    TString histoFileName = "beamCalibrationHistos.root";

    TFile outFile(histoDir + histoFileName, "UPDATE");
    outFile.Delete("*;*");  // Delete all objects from memory and file
    //outFile.Close();


    const int nE = 4;
    Double_t Energy[nE] = {4, 6, 8, 10};
    Double_t SF[nE];
    
    auto treename = "events";
    int p = 4;

    //--------------------------------------------------------------------------
    // ScFi Attenuation
    //--------------------------------------------------------------------------
    
    // Random number genertor
    TRandom* rand = new TRandom();

    int npePreAtten = 1100;
    //double lightGuideEffFactor[10] = {0.75/0.65, 0.73/0.65, 0.70/0.65, 0.68/0.65, 0.66/0.65,
    //                                  0.65/0.65, 0.52/0.65, 0.50/0.65, 0.49/0.65, 0.48/0.65};
    double lightGuideEffFactor[10] = {1.151630, 1.117192, 1.084063, 1.053218, 1.021398,
                                      0.992446, 0.801124, 0.775977, 0.752811, 0.736212};
    int length = 58;  // [cm]

    // Current Function
    TF1 *yValuesCurrent = new TF1("yValuesCurrent", SylvestersFormula, 0.0, length, 4);
    double parSyl[4] = {1.37130409e+02, 1.81201485e-01, 6.08666936e+01, 4.18209843e+02};

    yValuesCurrent->SetParameters(parSyl);
    yValuesCurrent->SetParNames("I0", "#alpha", "#lambda_{1}", "#lambda_{2}");
    double currentToNpeFactor = npePreAtten / yValuesCurrent->Eval(0);

    // Number of photoelectrons per GeV Function
    TF1 *npePerGeV = new TF1("Number of PhotoElectrons per GeV", SylvestersFormula, 0.0, length, 4);
    npePerGeV->SetParameters(parSyl);
    npePerGeV->SetParameter(0, parSyl[0] * currentToNpeFactor);

    TCanvas *cNpePerGev = new TCanvas("npePerGev", "npePerGeV", 1200, 800);
    cNpePerGev->SetGrid();
    npePerGeV->Draw();
    npePerGeV->GetXaxis()->SetTitle("Length [cm]");
    npePerGeV->GetYaxis()->SetTitle("NPE/GeV");
    cNpePerGev->Print(imagesDir + "npePerGeV.png");
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------

    for (int i=0; i<nE; i++) {
        p = Energy[i];

        // Create Histograms
        TH2F hBeam = hBeamProfile(p, nbins, r);
        TH1F hY = hEndY(p, nbins, r);
        TH1F hZ = hEndZ(p, nbins, r);
        TH1F *hDep = hHits(p, nbins, r, 0);
        TH1F *hAttenFactor_N = hAttenFactor(p, nbins, r, 1);
        TH1F *hAttenFactor_S = hAttenFactor(p, nbins, r, 2);
        TH1F *hNpeA = hNpeHits(p, nbins, r, 0);
        TH1F *hNpeAP = hNpePoissonHits(p, nbins, r, 0);
        TH1F *hNpeA_N = hNpeHits(p, nbins, r, 1);
        TH1F *hNpeAP_N = hNpePoissonHits(p, nbins, r, 1);
        TH1F *hNpeA_S = hNpeHits(p, nbins, r, 2);
        TH1F *hNpeAP_S = hNpePoissonHits(p, nbins, r, 2);
        TH1F *hDepA_N = hDepAHits(p, nbins, r, 1);
        TH1F *hDepAP_N = hDepAPHits(p, nbins, r, 1);
        TH1F *hDepAPC_N = hDepAPCHits(p, nbins, r, 1);
        TH1F *hDepA_S = hDepAHits(p, nbins, r, 2);
        TH1F *hDepAP_S = hDepAPHits(p, nbins, r, 2);
        TH1F *hDepAPC_S = hDepAPCHits(p, nbins, r, 2);
        TH1F *hDepAPC_T = hHitsDep(p, nbins, r, 2);
        TH1F *hDepAPC_TC = hHitsDep(p, nbins, r, 3);
        TH1F *hCalAPC_TC = hHitsCal(p, nbins, r, 3);
        TH1F hCT = hCTHits(p, nbins, r, threshold);
        TH1F hETrue = hTrue(p, nbins);
        //TH1F *hECal = hCal(p, nbins);
        TH1F hSipmA[4][10];
        TH1F hSipmAP[4][10];
        TH1F hSipmAPC[4][10];
        for (int g=0; g<4; g++) {
            for (int l=0; l<10; l++) {
                hSipmA[g][l] = hSipmAHits(p, 500, g, l, 1);
                hSipmAP[g][l] = hSipmAPHits(p, 500, g, l, 1);
                hSipmAPC[g][l] = hSipmAPCHits(p, 500, g, l, 1);
            }
        }

        TH1F hTest = TH1F(Form("hNpe%dGeV", p),
                          Form("e- %d GeV Number of Photoelectrons at Distance; npe; bin count", p),
                          nbins, 0.0, 1.5*p);

        // Set up input file chain
        TChain *chain = new TChain(treename);
        chain->Add(Form(simDir + "Ele_%dGeV_%dm_100000.edm4hep.root", p, r/1000));

        // Initialize reader
        TTreeReader tree_reader(chain);

        // Access whatever data-members you need
        TTreeReaderArray<float> array_e(tree_reader, "EcalBabyBarrelScFiHits.energy");
        TTreeReaderArray<float> array_hitX(tree_reader, "EcalBabyBarrelScFiHits.position.x");
        TTreeReaderArray<uint64_t> array_c(tree_reader, "EcalBabyBarrelScFiHits.cellID");
        TTreeReaderArray<int> array_gs(tree_reader, "MCParticles.generatorStatus");
        TTreeReaderArray<double> array_x(tree_reader, "MCParticles.endpoint.x");
        TTreeReaderArray<double> array_y(tree_reader, "MCParticles.endpoint.y");
        TTreeReaderArray<double> array_z(tree_reader, "MCParticles.endpoint.z");
        TTreeReaderArray<double> array_mass(tree_reader, "MCParticles.mass");
        TTreeReaderArray<float> array_px(tree_reader, "MCParticles.momentum.x");
        TTreeReaderArray<float> array_py(tree_reader, "MCParticles.momentum.y");
        TTreeReaderArray<float> array_pz(tree_reader, "MCParticles.momentum.z");

        // Loop through data-members and fill histograms
        while (tree_reader.Next()) {

            // Project Endpoints to leading surface of BBCal
            auto endX = 0.0;
            auto endY = 0.0;
            auto endZ = 0.0;
            for (int k=0; k<array_gs.GetSize(); k++) {
                if (array_gs[k]==1) {
                    endX = array_x[k];  //depth
                    endY = array_y[k];  //height
                    endZ = array_z[k];  //width
                }
            }
            auto projY = -r*endY/endX;  //negative to cancel -x
            auto projZ = -r*endZ/endX;  //negative to cancel -x
            hBeam.Fill(projZ, projY);
            hY.Fill(projY);
            hZ.Fill(projZ);
            
        // Layer and Grid with              LAYER                    
        // Array Indices        1---2------3--------4----------5------6
        //            \   G  1 |-| 0,0 |  0,1  |   0,2   |    0,3    |-| Row0
        //----BEAM-----\  R  2 |-| 1,0 |  1,1  |   1,2   |    1,3    |-| Row1
        //-------------/  I  3 |-| 2,0 |  2,1  |   2,2   |    2,3    |-| Row2
        //            /   D  4 |-| 3,0 |  3,1  |   3,2   |    3,3    |-| Row3
        //                      ---------------------------------------
            Double_t Esum = 0.0;
            Double_t EsumA_N = 0.0;
            Double_t EsumAP_N = 0.0;
            Double_t EsumAPC_N = 0.0;
            Double_t EsumA_S = 0.0;
            Double_t EsumAP_S = 0.0;
            Double_t EsumAPC_S = 0.0;
            Double_t EsumAPC_T = 0.0;
            Double_t EsumAPC_TC = 0.0;
            Double_t SumNpeA = 0.0;
            Double_t SumNpeAP = 0.0;
            Double_t SumNpeA_N = 0.0;
            Double_t SumNpeAP_N = 0.0;
            Double_t SumNpeA_S = 0.0;
            Double_t SumNpeAP_S = 0.0;
            Double_t CellSum[4][4] = {0};
            Double_t CellSumAPC_T[4][4] = {0};
            Double_t CellSumAPC_TC[4][4] = {0};
            Double_t SipmSum[4][10] = {0};
            Double_t SipmSumA[4][10] = {0};
            Double_t SipmSumAP[4][10] = {0};
            Double_t SipmSumAPC[4][10] = {0};
            Double_t SipmSumA_N[4][10] = {0};
            Double_t SipmSumAP_N[4][10] = {0};
            Double_t SipmSumAPC_N[4][10] = {0};
            Double_t SipmSumNpeA_N[4][10] = {0};
            Double_t SipmSumNpeAP_N[4][10] = {0};
            Double_t SipmSumA_S[4][10] = {0};
            Double_t SipmSumAP_S[4][10] = {0};
            Double_t SipmSumAPC_S[4][10] = {0};
            Double_t SipmSumNpeA_S[4][10] = {0};
            Double_t SipmSumNpeAP_S[4][10] = {0};
            Double_t Sipm2CellSumA[4][4] = {0};
            Double_t Sipm2CellSumAP[4][4] = {0};
            Double_t Sipm2CellSumAPC[4][4] = {0};

            for (Int_t ii=0; ii<array_e.GetSize(); ii++){
                // Bit Masking to retrieve cellID
                uint64_t cellID = array_c[ii];
                uint64_t gridAND = 1023;  // 2e10 - 1
                uint64_t layerAND = 63;  // 2e6 - 1
                auto Grid = (cellID >> 24) & gridAND;
                auto Layer = (cellID >> 14) & layerAND;
                Esum += array_e[ii]; 
                Double_t e = array_e[ii];

                // Delineation for seperating cells into sipms
                Double_t hitX = array_hitX[ii];
                double r1 = r + 8.0 + 20.74 + 20.74;
                double r2 = r + 8.0 + 20.74 + 41.48 + 20.3;
                double r3 = r + 8.0 + 20.74 + 41.48 + 20.3 + 20.3;
                double r4 = r + 8.0 + 20.74 + 41.48 + 61.0 + 24.7;
                double r5 = r + 8.0 + 20.74 + 41.48 + 61.0 + 24.7 + 24.7;
                double r6 = r + 8.0 + 20.74 + 41.48 + 61.0 + 24.7 + 24.7 + 24.7;
                bool L3_1 = hitX < r1;
                bool L3_2 = r1 <= hitX;
                bool L4_1 = hitX < r2;
                bool L4_2 = r2 <= hitX < r3;
                bool L4_3 = r3 <= hitX;
                bool L5_1 = hitX < r4;
                bool L5_2 = r4 <= hitX < r5;
                bool L5_3 = r5 <= hitX < r6;
                bool L5_4 = r6 <= hitX;

                // Add deposited energy to appropriate cell and sipm
                for (int g=0; g<4; g++) {
                    for (int l=0; l<4; l++) {
                        int grid = g+1; 
                        int layer = l+2; 
                        if (Grid==grid && Layer==layer) {
                            CellSum[g][l] += e;
                            if (Layer == 2) {
                                SipmSum[g][0] += e;
                            } else if (Layer == 3) {
                                if (L3_1) {SipmSum[g][1] += e;}
                                else if (L3_2) {SipmSum[g][2] += e;}
                            } else if (Layer == 4) {
                                if (L4_1) {SipmSum[g][3] += e;}
                                else if (L4_2) {SipmSum[g][4] += e;}
                                else if (L4_3) {SipmSum[g][5] += e;}
                            } else if (Layer == 5) {
                                if (L5_1) {SipmSum[g][6] += e;}
                                else if (L5_2) {SipmSum[g][7] += e;}
                                else if (L5_3) {SipmSum[g][8] += e;}
                                else if (L5_4) {SipmSum[g][9] += e;}
                            }
                        } 
                    }
                }
            }
            hDep->Fill(Esum);

            // Calculate Thrown energy and Sampling Fraction
            auto mass = 0.0;
            auto px = 0.0;
            auto py = 0.0;
            auto pz = 0.0;
            for (Int_t j=0; j<array_mass.GetSize(); j++){
                if (array_gs[j] == 1){
                    mass += array_mass[j];
                    px += array_px[j];
                    py += array_py[j];
                    pz += array_pz[j];
                }
            }
            auto Ethrown = TMath::Sqrt(px*px + py*py + pz*pz + mass*mass);
            hETrue.Fill(Ethrown);
            SF[i] = Esum/Ethrown;

            // Attenuation North
            double dist_N;
            double distParam_N;
            double attenuationFactor_N;
            double npeA_N;
            double eneA_N;
            double npeAP_N;
            double eneAP_N;
            double eneAC_N;
            double eneAPC_N;

            for (int g=0; g<4; g++) {
                for (int l=0; l<10; l++) {
                    npePerGeV->SetParameter(0, parSyl[0] * currentToNpeFactor * lightGuideEffFactor[l]);

                    dist_N = (length/2.0) - (projZ/10.0);  // [cm]
                    distParam_N = npePerGeV->Eval(dist_N);  // npe per GeV at dist
                    attenuationFactor_N = distParam_N / npePerGeV->Eval(0);

                    npeA_N = std::round(distParam_N * SipmSum[g][l] / SF[i]);  // npe at dist
                    eneA_N = npeA_N / npePerGeV->Eval(0) * SF[i];  // Energy at dist
                    npeAP_N = rand->Poisson(npeA_N);  // npe at dist with Poisson smearing
                    eneAP_N = npeAP_N / npePerGeV->Eval(0) * SF[i];  // Energy at dist with Poisson smearing
                    eneAC_N = eneA_N / attenuationFactor_N;  // Energy corrected for attenuation
                    eneAPC_N = eneAP_N / attenuationFactor_N;  // Poisson smeared energy corrected for attenuation

                    EsumA_N += eneA_N;
                    EsumAP_N += eneAP_N;
                    EsumAPC_N += eneAPC_N;
                    SumNpeA_N += npeA_N;
                    SumNpeAP_N += npeAP_N;
                    SipmSumA_N[g][l] += eneA_N;
                    SipmSumAP_N[g][l] += eneAP_N;
                    SipmSumAPC_N[g][l] += eneAPC_N;
                    SipmSumNpeA_N[g][l] += npeA_N;
                    SipmSumNpeAP_N[g][l] += npeAP_N;
                }
            }
            hAttenFactor_N->Fill(attenuationFactor_N);
            hDepA_N->Fill(EsumA_N);
            hDepAP_N->Fill(EsumAP_N);
            hDepAPC_N->Fill(EsumAPC_N);
            hNpeA_N->Fill(SumNpeA_N);
            hNpeAP_N->Fill(SumNpeAP_N);
            
            // Attenuation South
            double dist_S;
            double distParam_S;
            double attenuationFactor_S;
            double npeA_S;
            double eneA_S;
            double npeAP_S;
            double eneAP_S;
            double eneAC_S;
            double eneAPC_S;
            
            for (int g=0; g<4; g++) {
                for (int l=0; l<10; l++) {
                    npePerGeV->SetParameter(0, parSyl[0] * currentToNpeFactor * lightGuideEffFactor[l]);

                    dist_S = (length/2.0) + (projZ/10.0);  // [cm]
                    distParam_S = npePerGeV->Eval(dist_S);  // npe per GeV at dist
                    attenuationFactor_S = distParam_S / npePerGeV->Eval(0);

                    npeA_S = std::round(distParam_S * SipmSum[g][l] / SF[i]);  // npe at dist
                    eneA_S = npeA_S / npePerGeV->Eval(0) * SF[i];  // Energy at dist
                    npeAP_S = rand->Poisson(npeA_S);  // npe at dist with Poisson smearing
                    eneAP_S = npeAP_S / npePerGeV->Eval(0) * SF[i];  // Energy at dist with Poisson smearing
                    eneAC_S = eneA_S / attenuationFactor_S;  // Energy corrected for attenuation
                    eneAPC_S = eneAP_S / attenuationFactor_S;  // Poisson smeared energy corrected for attenuation

                    EsumA_S += eneA_S;
                    EsumAP_S += eneAP_S;
                    EsumAPC_S += eneAPC_S;
                    SumNpeA_S += npeA_S;
                    SumNpeAP_S += npeAP_S;
                    SipmSumA_S[g][l] += eneA_S;
                    SipmSumAP_S[g][l] += eneAP_S;
                    SipmSumAPC_S[g][l] += eneAPC_S;
                    SipmSumNpeA_S[g][l] += npeA_S;
                    SipmSumNpeAP_S[g][l] += npeAP_S;
                }
            }
            hAttenFactor_S->Fill(attenuationFactor_S);
            hDepA_S->Fill(EsumA_S);
            hDepAP_S->Fill(EsumAP_S);
            hDepAPC_S->Fill(EsumAPC_S);
            hNpeA_S->Fill(SumNpeA_S);
            hNpeAP_S->Fill(SumNpeAP_S);

            SumNpeA = TMath::Sqrt(SumNpeA_N*SumNpeA_S);
            SumNpeAP = TMath::Sqrt(SumNpeAP_N*SumNpeAP_S);
            hNpeA->Fill(SumNpeA_S);
            hNpeAP->Fill(SumNpeAP_S);
            
            // Combine North and South sides
            for (int g=0; g<4; g++) {
                for (int l=0; l<10; l++) {
                    SipmSumA[g][l] = TMath::Sqrt(SipmSumA_N[g][l]*SipmSumA_S[g][l]);
                    SipmSumAP[g][l] = TMath::Sqrt(SipmSumAP_N[g][l]*SipmSumAP_S[g][l]);
                    SipmSumAPC[g][l] = TMath::Sqrt(SipmSumAPC_N[g][l]*SipmSumAPC_S[g][l]);
                    hSipmA[g][l].Fill(SipmSumA[g][l]);
                    hSipmAP[g][l].Fill(SipmSumAP[g][l]);
                    hSipmAPC[g][l].Fill(SipmSumAPC[g][l]);
                }
            }

            // Sum Sipms to Cells
            for (int g=0; g<4; g++) {
                for (int l=0; l<10; l++) {
                    if (l==0) {
                        Sipm2CellSumA[g][0] += SipmSumA[g][l];
                        Sipm2CellSumAP[g][0] += SipmSumAP[g][l];
                        Sipm2CellSumAPC[g][0] += SipmSumAPC[g][l];
                    } else if (l==1) {
                        Sipm2CellSumA[g][1] += SipmSumA[g][l];
                        Sipm2CellSumAP[g][1] += SipmSumAP[g][l];
                        Sipm2CellSumAPC[g][1] += SipmSumAPC[g][l];
                    } else if (l==2) {
                        Sipm2CellSumA[g][1] += SipmSumA[g][l];
                        Sipm2CellSumAP[g][1] += SipmSumAP[g][l];
                        Sipm2CellSumAPC[g][1] += SipmSumAPC[g][l];
                    } else if (l==3) {
                        Sipm2CellSumA[g][2] += SipmSumA[g][l];
                        Sipm2CellSumAP[g][2] += SipmSumAP[g][l];
                        Sipm2CellSumAPC[g][2] += SipmSumAPC[g][l];
                    } else if (l==4) {
                        Sipm2CellSumA[g][2] += SipmSumA[g][l];
                        Sipm2CellSumAP[g][2] += SipmSumAP[g][l];
                        Sipm2CellSumAPC[g][2] += SipmSumAPC[g][l];
                    } else if (l==5) {
                        Sipm2CellSumA[g][2] += SipmSumA[g][l];
                        Sipm2CellSumAP[g][2] += SipmSumAP[g][l];
                        Sipm2CellSumAPC[g][2] += SipmSumAPC[g][l];
                    } else if (l==6) {
                        Sipm2CellSumA[g][3] += SipmSumA[g][l];
                        Sipm2CellSumAP[g][3] += SipmSumAP[g][l];
                        Sipm2CellSumAPC[g][3] += SipmSumAPC[g][l];
                    } else if (l==7) {
                        Sipm2CellSumA[g][3] += SipmSumA[g][l];
                        Sipm2CellSumAP[g][3] += SipmSumAP[g][l];
                        Sipm2CellSumAPC[g][3] += SipmSumAPC[g][l];
                    } else if (l==8) {
                        Sipm2CellSumA[g][3] += SipmSumA[g][l];
                        Sipm2CellSumAP[g][3] += SipmSumAP[g][l];
                        Sipm2CellSumAPC[g][3] += SipmSumAPC[g][l];
                    } else if (l==9) {
                        Sipm2CellSumA[g][3] += SipmSumA[g][l];
                        Sipm2CellSumAP[g][3] += SipmSumAP[g][l];
                        Sipm2CellSumAPC[g][3] += SipmSumAPC[g][l];
                    }
                }
            }

            // Threshold Cut
            for (int g=0; g<4; g++) {
                for (int l=0; l<4; l++) {
                    if (Sipm2CellSumAP[g][l] > threshold) {
                        CellSumAPC_T[g][l] = Sipm2CellSumAPC[g][l];
                        EsumAPC_T += CellSumAPC_T[g][l];
                    }
                }
            }
            if (EsumAPC_T > 0.0) {
                hDepAPC_T->Fill(EsumAPC_T);
            }
            

            // Centality Cut
            Double_t MaxCell = 0.0;
            int maxG = 0;
            int maxL = 0;
            for (int g=0; g<4; g++) {
                for (int l=0; l<4; l++) {
                    if (CellSumAPC_T[g][l]>MaxCell) {
                        MaxCell = CellSumAPC_T[g][l];
                        maxG = g;
                        maxL = l;
                    }
                }
            }
            if (maxG!=0 && maxG!=3 && maxL!=0 && maxL!=3) {
                for (int g=0; g<4; g++) {
                    for (int l=0; l<4; l++) {
                        CellSumAPC_TC[g][l] = CellSumAPC_T[g][l];
                        EsumAPC_TC += CellSumAPC_TC[g][l];
                    }
                }
                hDepAPC_TC->Fill(EsumAPC_TC);
                hCalAPC_TC->Fill(EsumAPC_TC/SF[i]);
            }
        }
        std::cout << Form("Histograms Filled: %d GeV e- Deposited Energy", p) << std::endl;

        //// Restart a Next() loop from the first entry.
        //tree_reader.Restart();

        //// Calculate Calibrated Energy
        //while(tree_reader.Next()) {
        //    auto Esum = 0.0;
        //    for (Int_t j=0; j<array_e.GetSize(); j++){
        //        Esum += array_e[j]; 
        //    }
        //    auto Ecal = Esum / SF[i];
        //    hECal->Fill(Ecal);
        //}
        //std::cout << Form("Histogram Filled: %d GeV e- Calibrated Energy", p) << std::endl;

        // Write Histos
        hDep->Write();
        hDepA_N->Write();
        hDepA_S->Write();
        hDepAP_N->Write();
        hDepAP_S->Write();
        hDepAPC_N->Write();
        hDepAPC_S->Write();
        hDepAPC_T->Write();
        hDepAPC_TC->Write();
        hCalAPC_TC->Write();
        hNpeA->Write();
        hNpeAP->Write();
        hETrue.Write();
        hBeam.Write();
        hY.Write();
        hZ.Write();

        delete chain;
    }


    TCanvas *c_gSF = new TCanvas("c_gSF", "c_gSF", 1200, 800);
    c_gSF->SetGrid();

    auto gSF = new TGraph(nE, Energy, SF);
    gSF->SetTitle("Sampling Fractions vs Energy of Generated Particles");
    gSF->GetXaxis()->SetTitle("E[GeV]");
    gSF->GetYaxis()->SetTitle("SF");
    gSF->GetYaxis()->SetTitleOffset(1.5);
    gSF->SetLineColor(kRed+1);
    gSF->SetLineWidth(2);
    gSF->SetMarkerColor(kBlue);
    gSF->SetMarkerSize(2);
    gSF->SetMarkerStyle(21);
    gSF->Draw("ACP");

    c_gSF->Print(imagesDir + "SF.png");
}

