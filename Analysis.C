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
		17300, 0, 17300, 0);
*/ 
cout << endl
     << "======================== Canisters ========================"
     << endl;

TH1D *ch_show = getCleanHistoFromTree("./data/Not_Exposed_Canister/RAW/DataR_Not_Exposed_Canister.root",
		11600, 200, 11800, 1);

TH1D *ch_nexp_can_0 = getCleanHistoFromTree("./data/Not_Exposed_Canister/RAW/DataR_Not_Exposed_Canister.root",
		6500, 500, 7000, 0);
TH1D *ch_nexp_can_1 = getCleanHistoFromTree("./data/Not_Exposed_Canister/RAW/DataR_Not_Exposed_Canister.root",
		11600, 200, 11800, 1);

TH1D *ch_exp_can_0 = getCleanHistoFromTree("./data/Exposed_Canister/RAW/DataR_Exposed_Canister.root",
		2860, 140, 3000, 0);
TH1D *ch_exp_can_1 = getCleanHistoFromTree("./data/Exposed_Canister/RAW/DataR_Exposed_Canister.root",
		7100, 200, 7300, 1);

TH1D *ch_cal_can_0 = getCleanHistoFromTree("./data/Calibrated_Canister/RAW/DataR_Calibrated_Canister.root",
		5500, 500, 6000, 0);
TH1D *ch_cal_can_1 = getCleanHistoFromTree("./data/Calibrated_Canister/RAW/DataR_Calibrated_Canister.root",
		7100, 200, 7300, 1);



/* /
cout << endl
     << "======================== RADIOACTIVE MATERIAL ========================"
     << endl;
TH1D *ch_europio_0 = getCleanHistoFromTree("./data/Europio/RAW/DataR_Europio.root",
		3450, 550, 4000, 0);
TH1D *ch_europio_1 = getCleanHistoFromTree("./data/Europio/RAW/DataR_Europio.root",
		6150, 150, 6300, 1);

//*
TH1D *ch_americio_0 = getCleanHistoFromTree("./data/Americio/RAW/DataR_Americio.root",
                                      17300, 0, 17300, 0);
TH1D *ch_americio_1 = getCleanHistoFromTree("./data/Americio/RAW/DataR_Americio.root",
                                      80, 300, 380, 1);
//                                      600, 40, 640, 1);
                                      //300, 200, 500, 1);
//*
TH1D *ch_cobalto_0 = getCleanHistoFromTree("./data/Cobalto/RAW/DataR_Cobalto.root",
                                      4000, 0, 4000, 0);
                                     //6500, 500, 7000, 0);
TH1D *ch_cobalto_1 = getCleanHistoFromTree("./data/Cobalto/RAW/DataR_Cobalto.root",
		5700, 300, 6000, 1);
                                 //    1285, 115, 1400, 1);
                                      //300, 200, 500, 1);
//*
TH1D *ch_sodio_0 = getCleanHistoFromTree("./data/Sodio/RAW/DataR_Sodio.root",
		3200, 400, 3600, 0);
                                   //////////////////   2290, 10, 2300, 0);
                                      //   3200, 400, 3600, 0);
TH1D *ch_sodio_1 = getCleanHistoFromTree("./data/Sodio/RAW/DataR_Sodio.root",
		3200, 400, 3600, 1);
                                      //2290, 10, 2300, 1);
                                      //   3200, 400, 3600, 1);
//*/
//*/

cout << endl
     << "==================== FINISHED CREATING HISTOGRAMS ===================="
     << endl
     << "======================== ANALYSIS AND PLOTTING ========================"
     << endl;


TCanvas *c_show = new TCanvas("Show test");
c_show->SetGridx();
c_show->SetGridy();
c_show->GetFrame()->SetFillColor(21);
c_show->GetFrame()->SetBorderMode(-1);
c_show->GetFrame()->SetBorderSize(5);

ch_show->SetTitle(" test ");
ch_show->SetName("americio spectrum");

gStyle->SetOptFit(0111);
gStyle->SetOptStat(11);
ch_show->Draw();
c_show->Update();
/* /
cout << endl
     << "======================== RADIOACTIVE MATERIAL ========================"
     << endl;
//* /
// Europio
cout << endl
     << "\t==================== europio ===================="
     << endl;
     
cout << endl
     << "\t\t==================== ch 0 ===================="
     << endl;
TCanvas *c_europio_0 = new TCanvas("europio channel 0");
c_europio_0->SetGridx();
c_europio_0->SetGridy();
c_europio_0->GetFrame()->SetFillColor(21);
c_europio_0->GetFrame()->SetBorderMode(-1);
c_europio_0->GetFrame()->SetBorderSize(5);

TF1 *fiteuropio0p1 = new TF1("europio0_p1", "gaus(0)", 100, 185);
TF1 *fiteuropio0p2 = new TF1("europio0_p2", "gaus(0)", 190, 310);
TF1 *fiteuropio0p3 = new TF1("europio0_p3", "gaus(0)", 495, 600);
TF1 *fiteuropio0p4 = new TF1("europio0_p4", "gaus(0)", 580, 720);
TF1 *fiteuropio0p5 = new TF1("europio0_p5", "gaus(0)", 710, 810);
TF1 *fiteuropio0p6 = new TF1("europio0_p6", "gaus(0)", 800, 940);
TF1 *fiteuropio0p7 = new TF1("europio0_p7", "gaus(0)", 940, 1110);
TF1 *fiteuropio0p8 = new TF1("europio0_p8", "gaus(0)", 1280, 1500);

TF1 *eur_tot_0 = new TF1("eur_tot_0", "gaus(0)+gaus(3)+gaus(6)+gaus(9)+gaus(12)+gaus(15)+gaus(18)+gaus(21)", 80, 1500);

double eur_par_0[24];

ch_europio_0->Fit("europio0_p1", "R");
ch_europio_0->Fit("europio0_p2", "R");
ch_europio_0->Fit("europio0_p3", "R");
ch_europio_0->Fit("europio0_p4", "R");
ch_europio_0->Fit("europio0_p5", "R");
ch_europio_0->Fit("europio0_p6", "R");
ch_europio_0->Fit("europio0_p7", "R");
ch_europio_0->Fit("europio0_p8", "R");

fiteuropio0p1->Draw("SAME");
//GetParameters(&eur_par_0[0]);
fiteuropio0p2->Draw("SAME");//GetParameters(&eur_par_0[3]);
fiteuropio0p3->Draw("SAME");//GetParameters(&eur_par_0[6]);
fiteuropio0p4->Draw("SAME");//GetParameters(&eur_par_0[9]);
fiteuropio0p5->Draw("SAME");//GetParameters(&eur_par_0[12]);
fiteuropio0p6->Draw("SAME");//GetParameters(&eur_par_0[15]);
fiteuropio0p7->Draw("SAME");//GetParameters(&eur_par_0[18]);
fiteuropio0p8->Draw("SAME");//GetParameters(&eur_par_0[21]);

eur_tot_0->SetParameters(eur_par_0);

//ch_europio_0->Fit("eur_tot_0", "R+");
//* /


ch_europio_0->SetTitle("europio spectrum via NaI detector");
ch_europio_0->SetName("europio spectrum");

gStyle->SetOptFit(0111);
gStyle->SetOptStat(11);
//ch_europio_0->Draw();
c_europio_0->Update();
//c_europio_0->SaveAs("plots/europio_0.png");
//* /
cout << endl
     << "\t\t==================== ch 1 ===================="
     << endl;
TCanvas *c_europio_1 = new TCanvas("europio channel 1");
c_europio_1->SetGridx();
c_europio_1->SetGridy();
c_europio_1->GetFrame()->SetFillColor(21);
c_europio_1->GetFrame()->SetBorderMode(-1);
c_europio_1->GetFrame()->SetBorderSize(5);

TF1 *fiteuropio1p0 = new TF1("europio1_p0", "gaus(0)", 02, 10);
TF1 *fiteuropio1p01 = new TF1("europio1_p01", "gaus(0)", 10, 15);
TF1 *fiteuropio1p1 = new TF1("europio1_p1", "gaus(0)", 85, 95);
TF1 *fiteuropio1p2 = new TF1("europio1_p2", "gaus(0)", 210, 220);
TF1 *fiteuropio1p3 = new TF1("europio1_p3", "gaus(0)", 310, 323);
TF1 *fiteuropio1p4 = new TF1("europio1_p4", "gaus(0)", 382, 390);
TF1 *fiteuropio1p5 = new TF1("europio1_p5", "gaus(0)", 412, 425);
TF1 *fiteuropio1p6 = new TF1("europio1_p6", "gaus(0)", 750, 767);
TF1 *fiteuropio1p7 = new TF1("europio1_p7", "gaus(0)", 845, 858);
TF1 *fiteuropio1p8 = new TF1("europio1_p8", "gaus(0)", 940, 954);
TF1 *fiteuropio1p9 = new TF1("europio1_p9", "gaus(0)", 1065, 1080);
TF1 *fiteuropio1p10 = new TF1("europio1_p10", "gaus(0)", 1095, 1103);
TF1 *fiteuropio1p11 = new TF1("europio1_p11", "gaus(0)", 1198, 1207);
TF1 *fiteuropio1p12 = new TF1("europio1_p12", "gaus(0)", 1283, 1295);
TF1 *fiteuropio1p13 = new TF1("europio1_p13", "gaus(0)", 1390, 1407);

TF1 *eur_tot_1 = new TF1("eur_tot_1", "gaus(0)+gaus(3)+gaus(6)+gaus(9)+gaus(12)+gaus(15)+gaus(18)+gaus(21)", 100, 1500);

double eur_par_1[24];

ch_europio_1->Fit("europio1_p0", "R");
ch_europio_1->Fit("europio1_p01", "R");
ch_europio_1->Fit("europio1_p1", "R");
ch_europio_1->Fit("europio1_p2", "R");
ch_europio_1->Fit("europio1_p3", "R");
ch_europio_1->Fit("europio1_p4", "R");
ch_europio_1->Fit("europio1_p5", "R");
ch_europio_1->Fit("europio1_p6", "R");
ch_europio_1->Fit("europio1_p7", "R");
ch_europio_1->Fit("europio1_p8", "R");
ch_europio_1->Fit("europio1_p9", "R");
ch_europio_1->Fit("europio1_p10", "R");
ch_europio_1->Fit("europio1_p11", "R");
ch_europio_1->Fit("europio1_p12", "R");
ch_europio_1->Fit("europio1_p13", "R");
//* /
fiteuropio1p0->Draw("SAME");
fiteuropio1p01->Draw("SAME");
fiteuropio1p1->Draw("SAME");//GetParameters(&eur_par_1[0]);
fiteuropio1p2->Draw("SAME");//GetParameters(&eur_par_1[3]);
fiteuropio1p3->Draw("SAME");//GetParameters(&eur_par_1[6]);
fiteuropio1p4->Draw("SAME");//GetParameters(&eur_par_1[9]);
fiteuropio1p5->Draw("SAME");//GetParameters(&eur_par_1[12]);
fiteuropio1p6->Draw("SAME");//GetParameters(&eur_par_1[15]);
fiteuropio1p7->Draw("SAME");//GetParameters(&eur_par_1[18]);
fiteuropio1p8->Draw("SAME");
fiteuropio1p9->Draw("SAME");
fiteuropio1p10->Draw("SAME");
fiteuropio1p11->Draw("SAME");//GetParameters(&eur_par_1[21]);
fiteuropio1p12->Draw("SAME");
fiteuropio1p13->Draw("SAME");
//*
eur_tot_0->SetParameters(eur_par_1);

//ch_europio_1->Fit("eur_tot_1", "R+");
* /
ch_europio_1->SetTitle("europio spectrum via HPGe detector");
ch_europio_1->SetName("europio spectrum");

gStyle->SetOptFit(0111);
gStyle->SetOptStat(11);

c_europio_1->Update();
c_europio_1->SaveAs("plots/europio_1.png");
//ch_europio_1->Draw();

//*
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

//TF1 *fitamericio0 = new TF1("americio0", "gaus(0)", 0, 1200);

//ch_americio_0->Fit("americio0", "R");

ch_americio_0->SetTitle("americio spectrum via NaI detector");
ch_americio_0->SetName("americio spectrum");

gStyle->SetOptFit(0111);
gStyle->SetOptStat(11);
ch_americio_0->Draw();
c_americio_0->Update();
//c_americio_0->SaveAs("plots/americio_0.png");
//* /
cout << endl
     << "\t\t==================== ch 1 ===================="
     << endl;
TCanvas *c_americio_1 = new TCanvas("americio channel 1");
c_americio_1->SetGridx();
c_americio_1->SetGridy();
c_americio_1->GetFrame()->SetFillColor(21);
c_americio_1->GetFrame()->SetBorderMode(-1);
c_americio_1->GetFrame()->SetBorderSize(5);

TF1 *fitamericio1 = new TF1("americio1", "gaus(0)", 30, 50);

ch_americio_1->Fit("americio1", "R");

ch_americio_1->SetTitle("americio spectrum via HPGe detector");
ch_americio_1->SetName("americio spectrum");

gStyle->SetOptFit(0111);
gStyle->SetOptStat(11);

c_americio_1->Update();
c_americio_1->SaveAs("plots/americio_1.png");
// cobalto
//* /
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

TF1 *fitcobalto0p1 = new TF1("cobalto0_p1", "gaus(0)", 1100, 1250);
TF1 *fitcobalto0p2 = new TF1("cobalto0_p2", "gaus(0)", 1240, 1450);

TF1 *cob_tot_0 = new TF1("cob_tot_0", "gaus(0)+gaus(3)", 1090, 1450);

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

TF1 *fitcobalto1p1 = new TF1("cobalto1_p1", "gaus(0)", 1150, 1163);
TF1 *fitcobalto1p2 = new TF1("cobalto1_p2", "gaus(0)", 1317, 1330);

//TF1 *cob_tot_1 = new TF1("cob_tot_1", "gaus(0)+gaus(3)", 1090, 1320);

//double cob_par_1[6];

ch_cobalto_1->Fit("cobalto1_p1", "R");
ch_cobalto_1->Fit("cobalto1_p2", "R");

fitcobalto1p1->Draw("SAME");//GetParameters(&cob_par_1[0]);
fitcobalto1p2->Draw("SAME");//GetParameters(&cob_par_1[3]);

//cob_tot_1->SetParameters(cob_par_1);


//ch_cobalto_1->Fit("cob_tot_1", "R+");
ch_cobalto_1->SetTitle("cobalto spectrum via HPGe detector");
ch_cobalto_1->SetName("cobalt spectrum");

gStyle->SetOptFit(0111);
gStyle->SetOptStat(11);

//c_cobalto_1->SetLogy();
c_cobalto_1->Update();
c_cobalto_1->SaveAs("plots/cobalto_1.png");

//* /
// sodio
cout << endl
     << "\t==================== Sodio ===================="
     << endl;
     
cout << endl
     << "\t\t==================== ch 0 ===================="
     << endl;
TCanvas *c_sodio_0 = new TCanvas("Sodio channel 0");
TF1 *fitsodio0 = new TF1("sodio0", "gaus(0)", 330, 460);
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
TF1 *fitsodio1 = new TF1("sodio1", "gaus(0)", 450, 490);
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
