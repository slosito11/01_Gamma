// basic commands
#include <iostream>
#include <map>

// our predefinded thinghies
#include "get_hist.hh"
// #include "peaksearch.hh"

cout << endl
     << "==================== CREATING HISTOGRAMS ====================" << endl;
// getting all the raw data by channel
/*
TH1D *h_autunite_0 = getHistoFromTree("./data/Autunite/RAW/DataR_Autunite.root",
                                      17300, 0, 17300, 0);
TH1D *h_autunite_1 = getHistoFromTree("./data/Autunite/RAW/DataR_Autunite.root",
                                      17300, 0, 17300, 1);
TH1D *h_abano_0 = getHistoFromTree(
    "./data/Abano_terme/RAW/DataR_Abano_terme.root", 17300, 0, 17300, 0);
TH1D *h_abano_1 = getHistoFromTree(
    "./data/Abano_terme/RAW/DataR_Abano_terme.root", 17300, 0, 17300, 1);
TH1D *h_americio_0 = getHistoFromTree("./data/Americio/RAW/DataR_Americio.root",
                                      17300, 0, 17300, 0);
TH1D *h_americio_1 = getHistoFromTree("./data/Americio/RAW/DataR_Americio.root",
                                      17300, 0, 17300, 1);
TH1D *h_cal_can_0 = getHistoFromTree(
    "./data/Calibrated_Canister/RAW/DataR_Calibrated_Canister.root", 17300, 0,
    17300, 0);
TH1D *h_cal_can_1 = getHistoFromTree(
    "./data/Calibrated_Canister/RAW/DataR_Calibrated_Canister.root", 17300, 0,
    17300, 1);
TH1D *h_caricatore_0 =
    getHistoFromTree("./data/Caricatore_cell/RAW/DataR_Caricatore_cell.root",
                     17300, 0, 17300, 0);
TH1D *h_caricatore_1 =
    getHistoFromTree("./data/Caricatore_cell/RAW/DataR_Caricatore_cell.root",
                     17300, 0, 17300, 1);
TH1D *h_cobalto_0 = getHistoFromTree("./data/Cobalto/RAW/DataR_Cobalto.root",
                                     17300, 0, 17300, 0);
TH1D *h_cobalto_1 = getHistoFromTree("./data/Cobalto/RAW/DataR_Cobalto.root",
                                     17300, 0, 17300, 1);
TH1D *h_europio_0 = getHistoFromTree("./data/Europio/RAW/DataR_Europio.root",
                                     17300, 0, 17300, 0);
TH1D *h_europio_1 = getHistoFromTree("./data/Europio/RAW/DataR_Europio.root",
                                     17300, 0, 17300, 1);
TH1D *h_exp_can_0 =
    getHistoFromTree("./data/Exposed_Canister/RAW/DataR_Exposed_Canister.root",
                     17300, 0, 17300, 0);
TH1D *h_exp_can_1 =
    getHistoFromTree("./data/Exposed_Canister/RAW/DataR_Exposed_Canister.root",
                     17300, 0, 17300, 1);
TH1D *h_legno_0 = getHistoFromTree(
    "./data/Legno_Mada/RAW/DataR_Legno_Mada.root", 17300, 0, 17300, 0);
TH1D *h_legno_1 = getHistoFromTree(
    "./data/Legno_Mada/RAW/DataR_Legno_Mada.root", 17300, 0, 17300, 1);
TH1D *h_nexp_can_0 = getHistoFromTree(
    "./data/Not_Exposed_Canister/RAW/DataR_Not_Exposed_Canister.root", 17300, 0,
    17300, 0);
TH1D *h_nexp_can_1 = getHistoFromTree(
    "./data/Not_Exposed_Canister/RAW/DataR_Not_Exposed_Canister.root", 17300, 0,
    17300, 1);
TH1D *h_porcini_0 = getHistoFromTree("./data/Porcini/RAW/DataR_Porcini.root",
                                     17300, 0, 17300, 0);
TH1D *h_porcini_1 = getHistoFromTree("./data/Porcini/RAW/DataR_Porcini.root",
                                     17300, 0, 17300, 1);
TH1D *h_sodio_0 =
    getHistoFromTree("./data/Sodio/RAW/DataR_Sodio.root", 3200, 400, 3600, 0);
TH1D *h_sodio_1 =
    getHistoFromTree("./data/Sodio/RAW/DataR_Sodio.root", 3200, 400, 3600, 1);
*/

TH1D *ch_americio_0 = getCleanHistoFromTree("./data/Americio/RAW/DataR_Americio.root",
                                      17300, 0, 17300, 0);
TH1D *ch_americio_1 = getCleanHistoFromTree("./data/Americio/RAW/DataR_Americio.root",
                                      300, 200, 500, 1);
//*
TH1D *ch_cobalto_0 = getCleanHistoFromTree("./data/Cobalto/RAW/DataR_Cobalto.root",
                                     6500, 500, 7000, 0);
TH1D *ch_cobalto_1 = getCleanHistoFromTree("./data/Cobalto/RAW/DataR_Cobalto.root",
                                     17285, 115, 17300, 1);
//*
TH1D *ch_sodio_0 = getCleanHistoFromTree("./data/Sodio/RAW/DataR_Sodio.root",
                                         3200, 400, 3600, 0);
TH1D *ch_sodio_1 = getCleanHistoFromTree("./data/Sodio/RAW/DataR_Sodio.root",
                                         3200, 400, 3600, 1);
//*/

cout << endl
     << "==================== FINISHED CREATING HISTOGRAMS ===================="
     << endl
     << "======================== ANALYSIS AND PLOTTING ========================"
     << endl;

// americio
cout << endl
     << "\t==================== americio ===================="
     << endl;
     
cout << endl
     << "\t\t==================== ch 0 ===================="
     << endl;
TCanvas *c_americio_0 = new TCanvas("americio channel 0");
c_americio_0->SetGridx();
c_americio_0->SetGridy();
c_americio_0->GetFrame()->SetFillColor(21);
c_americio_0->GetFrame()->SetBorderMode(-1);
c_americio_0->GetFrame()->SetBorderSize(5);

TF1 *fitamericio0 = new TF1("americio0", "gaus(0)", 1250, 1550);

ch_americio_0->Fit("americio0", "R");

ch_americio_0->SetTitle("americio spectrum via NaI detector");
ch_americio_0->SetName("americio spectrum");

gStyle->SetOptFit(0111);
gStyle->SetOptStat(11);

c_americio_0->Update();
//c_americio_0->SaveAs("plots/americio_0.png");

cout << endl
     << "\t\t==================== ch 1 ===================="
     << endl;
TCanvas *c_americio_1 = new TCanvas("americio channel 1");
c_americio_1->SetGridx();
c_americio_1->SetGridy();
c_americio_1->GetFrame()->SetFillColor(21);
c_americio_1->GetFrame()->SetBorderMode(-1);
c_americio_1->GetFrame()->SetBorderSize(5);

TF1 *fitamericio1 = new TF1("americio1", "gaus(0)", 335, 385);

ch_americio_1->Fit("americio1", "R");

ch_americio_1->SetTitle("americio spectrum via HPGe detector");
ch_americio_1->SetName("americio spectrum");

gStyle->SetOptFit(0111);
gStyle->SetOptStat(11);

c_americio_1->Update();
c_americio_1->SaveAs("plots/americio_1.png");
// cobalto
//*
cout << endl
     << "\t==================== Cobalt ===================="
     << endl;
     
cout << endl
     << "\t\t==================== ch 0 ===================="
     << endl;

TCanvas *c_cobalto_0 = new TCanvas("cobalto channel 0");
c_cobalto_0->SetGridx();
c_cobalto_0->SetGridy();
c_cobalto_0->GetFrame()->SetFillColor(21);
c_cobalto_0->GetFrame()->SetBorderMode(-1);
c_cobalto_0->GetFrame()->SetBorderSize(5);

TF1 *fitcobalto0p1 = new TF1("cobalto0_p1", "gaus(0)", 2700, 3200);
TF1 *fitcobalto0p2 = new TF1("cobalto0_p2", "gaus(0)", 3200, 3700);

TF1 *cob_tot_0 = new TF1("cob_tot_0", "gaus(0)+gaus(3)", 2600, 3800);

double cob_par_0[6];

ch_cobalto_0->Fit("cobalto0_p1", "R");
ch_cobalto_0->Fit("cobalto0_p2", "R");

fitcobalto0p1->GetParameters(&cob_par_0[0]);
fitcobalto0p1->GetParameters(&cob_par_0[3]);

cob_tot_0->SetParameters(cob_par_0);

ch_cobalto_0->Fit("cob_tot_0", "R+");

ch_cobalto_0->SetTitle("cobalto spectrum via NaI detector");
ch_cobalto_0->SetName("cobalt spectrum");

gStyle->SetOptFit(0111);
gStyle->SetOptStat(11);

c_cobalto_0->Update();
c_cobalto_0->SaveAs("plots/cobalto_0.png");

cout << endl
     << "\t\t==================== ch 1 ===================="
     << endl;
TCanvas *c_cobalto_1 = new TCanvas("cobalto channel 1");
c_cobalto_1->SetGridx();
c_cobalto_1->SetGridy();
c_cobalto_1->GetFrame()->SetFillColor(21);
c_cobalto_1->GetFrame()->SetBorderMode(-1);
c_cobalto_1->GetFrame()->SetBorderSize(5);

TF1 *fitcobalto1p1 = new TF1("cobalto1_p1", "gaus(0)", 5150, 5250);
TF1 *fitcobalto1p2 = new TF1("cobalto1_p2", "gaus(0)", 5800, 5900);

TF1 *cob_tot_1 = new TF1("cob_tot_1", "gaus(0)+gaus(3)", 5150, 5900);

double cob_par_1[6];

ch_cobalto_1->Fit("cobalto1_p1", "R");
ch_cobalto_1->Fit("cobalto1_p2", "R");

fitcobalto1p1->GetParameters(&cob_par_1[0]);
fitcobalto1p2->GetParameters(&cob_par_1[3]);

cob_tot_1->SetParameters(cob_par_1);


ch_cobalto_1->Fit("cob_tot_1", "R+");
ch_cobalto_1->SetTitle("cobalto spectrum via HPGe detector");
ch_cobalto_1->SetName("cobalt spectrum");

gStyle->SetOptFit(0111);
gStyle->SetOptStat(11);

//c_cobalto_1->SetLogy();
c_cobalto_1->Update();
c_cobalto_1->SaveAs("plots/cobalto_1.png");

//*
// sodio
cout << endl
     << "\t==================== Sodio ===================="
     << endl;
     
cout << endl
     << "\t\t==================== ch 0 ===================="
     << endl;
TCanvas *c_sodio_0 = new TCanvas("Sodio channel 0");
TF1 *fitsodio0 = new TF1("sodio0", "gaus(0)", 1250, 1550);
fitsodio0->SetParameters(0, 1500);
fitsodio0->SetParameters(1, 18000);
fitsodio0->SetParameters(2, 120);
ch_sodio_0->Fit("sodio0", "R");
c_sodio_0->SetGridx();
c_sodio_0->SetGridy();
c_sodio_0->GetFrame()->SetFillColor(21);
c_sodio_0->GetFrame()->SetBorderMode(-1);
c_sodio_0->GetFrame()->SetBorderSize(5);
ch_sodio_0->SetTitle("Sodio spectrum via NaI detector");
ch_sodio_0->SetName("sodium spectrum");
gStyle->SetOptFit(0111);
gStyle->SetOptStat(11);
c_sodio_0->Update();
c_sodio_0->SaveAs("plots/sodio_0.png");

cout << endl
     << "\t\t==================== ch 1 ===================="
     << endl;
TCanvas *c_sodio_1 = new TCanvas("Sodio channel 1");
TF1 *fitsodio1 = new TF1("sodio1", "gaus(0)", 2200, 2500);
fitsodio1->SetParameters(0, 1500);
fitsodio1->SetParameters(1, 18000);
fitsodio1->SetParameters(2, 120);
ch_sodio_1->Fit("sodio1", "R");
c_sodio_1->SetGridx();
c_sodio_1->SetGridy();
c_sodio_1->GetFrame()->SetFillColor(21);
c_sodio_1->GetFrame()->SetBorderMode(-1);
c_sodio_1->GetFrame()->SetBorderSize(5);
ch_sodio_1->SetTitle("Sodio spectrum via HPGe detector");
ch_sodio_1->SetName("sodium spectrum");
gStyle->SetOptFit(0111);
gStyle->SetOptStat(11);
c_sodio_1->Update();
c_sodio_1->SaveAs("plots/sodio_1.png");
//*/
