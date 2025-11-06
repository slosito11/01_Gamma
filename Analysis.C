// basic commands
#include <fstream>
#include <iostream>
#include <map>

// our predefinded thinghies
#include "get_hist.hh"
// #include "peaksearch.hh"

cout << endl
     << "==================== CREATING HISTOGRAMS ====================" << endl;

// getting all the raw data by channel
cout << endl
     << "======================== Mineral Samples ========================"
     << endl;

TH1D *ch_autunite_0 = getCleanHistoFromTree(
    "./data/Autunite/RAW/DataR_Autunite.root", 2200, 200, 2400, 0);
TH1D *ch_autunite_1 = getCleanHistoFromTree(
    "./data/Autunite/RAW/DataR_Autunite.root", 5700, 300, 6000, 1);
/*
TH1D *ch_caricatore_0 =
    getCleanHistoFromTree("./data/Caricatore_cell/RAW/DataR_Caricatore_cell.root",
                     17300, 0, 17300, 0);
TH1D *ch_caricatore_1 =
    getCleanHistoFromTree("./data/Caricatore_cell/RAW/DataR_Caricatore_cell.root",
                     11340, 160, 11500, 1);

TH1D *ch_abano_0 = getCleanHistoFromTree(
    "./data/Abano_terme/RAW/DataR_Abano_terme.root", 6300, 500, 6800, 0);
TH1D *ch_abano_1 = getCleanHistoFromTree(
    "./data/Abano_terme/RAW/DataR_Abano_terme.root", 11240, 260, 11500, 1);
//*/
cout << endl
     << "======================== Biological Samples ========================"
     << endl;

TH1D *ch_porcini_0 =
getCleanHistoFromTree("./data/Porcini/RAW/DataR_Porcini.root", 7300, 0, 7300,
0); TH1D *ch_porcini_1 =
getCleanHistoFromTree("./data/Porcini/RAW/DataR_Porcini.root", 11080, 220,
11300, 1); TH1D *ch_legno_0 = getCleanHistoFromTree(
    "./data/Legno_Mada/RAW/DataR_Legno_Mada.root", 4500, 500, 5000, 0);
TH1D *ch_legno_1 = getCleanHistoFromTree(
    "./data/Legno_Mada/RAW/DataR_Legno_Mada.root", 6810, 190, 7000, 1);

//*/
//*
cout << endl
     << "======================== Canisters ========================" << endl;

TH1D *h_nexp_can_0 = getHistoFromTree(
    "./data/Not_Exposed_Canister/RAW/DataR_Not_Exposed_Canister.root", 2200,
    300, 2500, 0);

//		6500, 500, 7000, 0);
TH1D *h_nexp_can_1 = getHistoFromTree(
    "./data/Not_Exposed_Canister/RAW/DataR_Not_Exposed_Canister.root", 3700,
    300, 4000, 1);
//		11600, 200, 11800, 1);

TH1D *h_exp_can_0 =
    getHistoFromTree("./data/Exposed_Canister/RAW/DataR_Exposed_Canister.root",
                     2200, 300, 2500, 0);
//		3500, 500, 5000, 0);
TH1D *h_exp_can_1 =
    getHistoFromTree("./data/Exposed_Canister/RAW/DataR_Exposed_Canister.root",
                     3700, 300, 4000, 1);
//		7100, 200, 7300, 1);

TH1D *ch_exp_can_0 = (TH1D *)h_exp_can_0->Clone("ch_exp_can_0");
ch_exp_can_0->Add(h_nexp_can_0, -1);
TH1D *t_bg_0 = (TH1D *)ch_exp_can_0->ShowBackground(22); // draws...
ch_exp_can_0->Add(t_bg_0, -1);
CalibrateHisto(ch_exp_can_0, 0.824364, -25.84, 2200, 300, 2500);

TH1D *ch_exp_can_1 = (TH1D *)h_exp_can_1->Clone("ch_exp_can_1");
ch_exp_can_1->Add(h_nexp_can_1, -1);
TH1D *t_bg_1 = (TH1D *)ch_exp_can_1->ShowBackground(22); // draws...
ch_exp_can_1->Add(t_bg_1, -1);
CalibrateHisto(ch_exp_can_1, 0.462430, 0.17, 3700, 300, 4000);

TH1D *h_cal_can_0 = getHistoFromTree(
    "./data/Calibrated_Canister/RAW/DataR_Calibrated_Canister.root", 2200, 300,
    2500, 0);
//		5500, 500, 6000, 0);
TH1D *h_cal_can_1 = getHistoFromTree(
    "./data/Calibrated_Canister/RAW/DataR_Calibrated_Canister.root", 3700, 300,
    4000, 1);
//		7100, 200, 7300, 1);
TH1D *ch_cal_can_0 = (TH1D *)h_cal_can_0->Clone("ch_cal_can_0");
ch_cal_can_0->Add(h_nexp_can_0, -1);
TH1D *t_bg_01 = (TH1D *)ch_cal_can_0->ShowBackground(22); // draws...
ch_cal_can_0->Add(t_bg_01, -1);
CalibrateHisto(ch_cal_can_0, 0.824364, -25.84, 2200, 300, 2500);

TH1D *ch_cal_can_1 = (TH1D *)h_cal_can_1->Clone("ch_cal_can_1");
ch_cal_can_1->Add(h_nexp_can_1, -1);
TH1D *t_bg_11 = (TH1D *)ch_cal_can_1->ShowBackground(22); // draws...
ch_cal_can_1->Add(t_bg_11, -1);
CalibrateHisto(ch_cal_can_1, 0.462430, 0.17, 3700, 300, 4000);

//*/
cout << endl
     << "======================== RADIOACTIVE MATERIAL ========================"
     << endl;
TH1D *ch_europio_0 = getCleanHistoFromTree(
    "./data/Europio/RAW/DataR_Europio.root", 1700, 200, 1900, 0);
TH1D *ch_europio_1 = getCleanHistoFromTree(
    "./data/Europio/RAW/DataR_Europio.root", 3050, 150, 3200, 1);
//*
TH1D *ch_americio_0 = getCleanHistoFromTree(
    "./data/Americio/RAW/DataR_Americio.root", 10000, 0, 10000, 0);
TH1D *ch_americio_1 = getHistoFromTree(
    "./data/Americio/RAW/DataR_Americio.root", 40, 100, 140, 1);

TH1D *t_back1_1 = getHistoFromTree(
    "./data/background_1/RAW/DataR_background_1.root", 40, 100, 140, 1);
TH1D *t_back2_1 = getHistoFromTree(
    "./data/background_2/RAW/DataR_background_2.root", 40, 100, 140, 1);

TH1D *t_back_1 = (TH1D *)t_back1_1->Clone("h_back_1");
t_back_1->Reset();
t_back_1->Add(t_back1_1, t_back2_1, 0.5, 0.5);
ch_americio_1->Add(t_back_1, -1);
// changing title
ch_americio_1->SetTitle("Cleaned spectrum");
CalibrateHisto(ch_americio_1, 0.462430, 0.17, 40, 100, 140);

//                                      600, 40, 640, 1);
// 300, 200, 500, 1);
//*
TH1D *ch_cobalto_0 = getCleanHistoFromTree(
    "./data/Cobalto/RAW/DataR_Cobalto.root", 1600, 200, 1800, 0);
// 6500, 500, 7000, 0);
TH1D *ch_cobalto_1 = getCleanHistoFromTree(
    "./data/Cobalto/RAW/DataR_Cobalto.root", 400, 2500, 2900, 1);
//    1285, 115, 1400, 1);
// 300, 200, 500, 1);
//*
TH1D *ch_sodio_0 = getCleanHistoFromTree("./data/Sodio/RAW/DataR_Sodio.root",
                                         1550, 200, 1750, 0);
//////////////////   2290, 10, 2300, 0);
//   3200, 400, 3600, 0);
TH1D *ch_sodio_1 = getCleanHistoFromTree("./data/Sodio/RAW/DataR_Sodio.root",
                                         1720, 1080, 2800, 1);
// 2290, 10, 2300, 1);
//    3200, 400, 3600, 1);
// */
cout
    << endl
    << "==================== FINISHED CREATING HISTOGRAMS ===================="
    << endl
    << "======================== ANALYSIS AND PLOTTING ========================"
    << endl;
/*
TCanvas *c_show = new TCanvas("Show test");
c_show->SetGridx();
c_show->SetGridy();
c_show->GetFrame()->SetFillColor(21);
c_show->GetFrame()->SetBorderMode(-1);
c_show->GetFrame()->SetBorderSize(5);

ch_show->SetTitle(" test ");
ch_show->SetName("americio spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);
ch_show->Draw();
c_show->Update();
//*/
//*
cout << endl
     << "======================== MINERAL SAMPLES ========================"
     << endl;
// Autunite
cout << endl << "\t==================== Autunite ====================" << endl;

cout << endl << "\t\t==================== ch 0 ====================" << endl;
TCanvas *c_autunite_0 = new TCanvas("autunite channel 0");
c_autunite_0->SetGridx();
c_autunite_0->SetGridy();
c_autunite_0->GetFrame()->SetFillColor(21);
c_autunite_0->GetFrame()->SetBorderMode(-1);
c_autunite_0->GetFrame()->SetBorderSize(5);

//*
TF1 *fitautunite0p1 = new TF1("autunite0_p1", "gaus(0)", 260, 320);
TF1 *fitautunite0p2 = new TF1("autunite0_p2", "gaus(0)", 318, 382);
TF1 *fitautunite0p3 = new TF1("autunite0_p3", "gaus(0)", 560, 650);
//TF1 *fitautunite0p4 = new TF1("autunite0_p4", "gaus(0)", 1070, 1180);
//TF1 *fitautunite0p5 = new TF1("autunite0_p5", "gaus(0)", 1700, 1810);

ch_autunite_0->Fit("autunite0_p1", "R");
ch_autunite_0->Fit("autunite0_p2", "R");
ch_autunite_0->Fit("autunite0_p3", "R");
//ch_autunite_0->Fit("autunite0_p4", "R");
//ch_autunite_0->Fit("autunite0_p5", "R");

fitautunite0p1->Draw("SAME");
fitautunite0p2->Draw("SAME");
fitautunite0p3->Draw("SAME");
//fitautunite0p4->Draw("SAME");
//fitautunite0p5->Draw("SAME");

ch_autunite_0->SetTitle("autunite spectrum via NaI detector");
ch_autunite_0->SetName("autunite spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);
c_autunite_0->Update();
c_autunite_0->SaveAs("plots/autunite_0.png");

double I_aut_01 = ch_autunite_1->Integral(148, 213);
cout << endl << "\t Integral gives : " << I_aut_01 << endl;
double I_aut_02 = ch_autunite_1->Integral(220, 291);
cout << endl << "\t Integral gives : " << I_aut_02 << endl;
double I_aut_03 = ch_autunite_1->Integral(523, 621);
cout << endl << "\t Integral gives : " << I_aut_03 << endl;

//* /
cout << endl << "\t\t==================== ch 1 ====================" << endl;
TCanvas *c_autunite_1 = new TCanvas("autunite channel 1");
c_autunite_1->SetGridx();
c_autunite_1->SetGridy();
c_autunite_1->GetFrame()->SetFillColor(21);
c_autunite_1->GetFrame()->SetBorderMode(-1);
c_autunite_1->GetFrame()->SetBorderSize(5);

TF1 *fitautunite1p1 = new TF1("autunite1_p1", "gaus(0)", 292, 298);
TF1 *fitautunite1p2 = new TF1("autunite1_p2", "gaus(0)", 348, 355);
TF1 *fitautunite1p3 = new TF1("autunite1_p3", "gaus(0)", 606, 612);

ch_autunite_1->Fit("autunite1_p1", "R");
ch_autunite_1->Fit("autunite1_p2", "R");
ch_autunite_1->Fit("autunite1_p3", "R");

fitautunite1p1->Draw("SAME");
fitautunite1p2->Draw("SAME");
fitautunite1p3->Draw("SAME"); // GetParameters(&eur_par_1[0]);

ch_autunite_1->SetTitle("autunite spectrum via HPGe detector");
ch_autunite_1->SetName("autunite spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

c_autunite_1->Update();
c_autunite_1->SaveAs("plots/autunite_1.png");

double I_aut_11 = ch_autunite_1->Integral(334, 344);
cout << endl << "\t Integral gives : " << I_aut_11 << endl;
double I_aut_12 = ch_autunite_1->Integral(456, 468);
cout << endl << "\t Integral gives : " << I_aut_12 << endl;
double I_aut_13 = ch_autunite_1->Integral(1011, 1025);
cout << endl << "\t Integral gives : " << I_aut_13 << endl;

/*
// Abano
cout << endl
     << "\t==================== Abano Terme ===================="
     << endl;

cout << endl
     << "\t\t==================== ch 0 ===================="
     << endl;
TCanvas *c_abano_0 = new TCanvas("abano channel 0");
c_abano_0->SetGridx();
c_abano_0->SetGridy();
c_abano_0->GetFrame()->SetFillColor(21);
c_abano_0->GetFrame()->SetBorderMode(-1);
c_abano_0->GetFrame()->SetBorderSize(5);

ch_abano_0->SetTitle("abano spectrum via NaI detector");
ch_abano_0->SetName("abano spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);
ch_abano_0->Draw();
c_abano_0->Update();
c_abano_0->SaveAs("plots/abano_0.png");
//* /
cout << endl
     << "\t\t==================== ch 1 ===================="
     << endl;
TCanvas *c_abano_1 = new TCanvas("abano channel 1");
c_abano_1->SetGridx();
c_abano_1->SetGridy();
c_abano_1->GetFrame()->SetFillColor(21);
c_abano_1->GetFrame()->SetBorderMode(-1);
c_abano_1->GetFrame()->SetBorderSize(5);

ch_abano_1->Draw();
ch_abano_1->SetTitle("abano spectrum via HPGe detector");
ch_abano_1->SetName("abano spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

c_abano_1->Update();
c_abano_1->SaveAs("plots/abano_1.png");
// Caricatore
cout << endl
     << "\t==================== Caricatore ===================="
     << endl;

cout << endl
     << "\t\t==================== ch 0 ===================="
     << endl;
TCanvas *c_caricatore_0 = new TCanvas("caricatore channel 0");
c_caricatore_0->SetGridx();
c_caricatore_0->SetGridy();
c_caricatore_0->GetFrame()->SetFillColor(21);
c_caricatore_0->GetFrame()->SetBorderMode(-1);
c_caricatore_0->GetFrame()->SetBorderSize(5);

ch_caricatore_0->SetTitle("caricatore spectrum via NaI detector");
ch_caricatore_0->SetName("caricatore spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);
ch_caricatore_0->Draw();
c_caricatore_0->Update();
c_caricatore_0->SaveAs("plots/caricatore_0.png");
//* /
cout << endl
     << "\t\t==================== ch 1 ===================="
     << endl;
TCanvas *c_caricatore_1 = new TCanvas("caricatore channel 1");
c_caricatore_1->SetGridx();
c_caricatore_1->SetGridy();
c_caricatore_1->GetFrame()->SetFillColor(21);
c_caricatore_1->GetFrame()->SetBorderMode(-1);
c_caricatore_1->GetFrame()->SetBorderSize(5);
//* /
ch_caricatore_1->Draw();
ch_caricatore_1->SetTitle("caricatore spectrum via HPGe detector");
ch_caricatore_1->SetName("caricatore spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

c_caricatore_1->Update();
c_caricatore_1->SaveAs("plots/caricatore_1.png");

//*
cout << endl
     << "======================== BIOLOGICAL SAMPLES ========================"
     << endl;
// Legno
cout << endl
     << "\t==================== Legno ===================="
     << endl;

cout << endl
     << "\t\t==================== ch 0 ===================="
     << endl;
TCanvas *c_legno_0 = new TCanvas("legno channel 0");
c_legno_0->SetGridx();
c_legno_0->SetGridy();
c_legno_0->GetFrame()->SetFillColor(21);
c_legno_0->GetFrame()->SetBorderMode(-1);
c_legno_0->GetFrame()->SetBorderSize(5);

ch_legno_0->SetTitle("legno spectrum via NaI detector");
ch_legno_0->SetName("legno spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);
ch_legno_0->Draw();
c_legno_0->Update();
c_legno_0->SaveAs("plots/legno_0.png");
//* /
cout << endl
     << "\t\t==================== ch 1 ===================="
     << endl;
TCanvas *c_legno_1 = new TCanvas("legno channel 1");
c_legno_1->SetGridx();
c_legno_1->SetGridy();
c_legno_1->GetFrame()->SetFillColor(21);
c_legno_1->GetFrame()->SetBorderMode(-1);
c_legno_1->GetFrame()->SetBorderSize(5);

ch_legno_1->Draw();
ch_legno_1->SetTitle("legno spectrum via HPGe detector");
ch_legno_1->SetName("legno spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

c_legno_1->Update();
c_legno_1->SaveAs("plots/legno_1.png");

//*/
// Porcini
cout << endl
     << "\t==================== Procini ===================="
     << endl;

cout << endl
     << "\t\t==================== ch 0 ===================="
     << endl;
TCanvas *c_porcini_0 = new TCanvas("porcini channel 0");
c_porcini_0->SetGridx();
c_porcini_0->SetGridy();
c_porcini_0->GetFrame()->SetFillColor(21);
c_porcini_0->GetFrame()->SetBorderMode(-1);
c_porcini_0->GetFrame()->SetBorderSize(5);


ch_porcini_0->Draw();
ch_porcini_0->SetTitle("porcini spectrum via NaI detector");
ch_porcini_0->SetName("porcini spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);
c_porcini_0->Update();
c_porcini_0->SaveAs("plots/porcini_0.png");
//* /
cout << endl
     << "\t\t==================== ch 1 ===================="
     << endl;
TCanvas *c_porcini_1 = new TCanvas("porcini channel 1");
c_porcini_1->SetGridx();
c_porcini_1->SetGridy();
c_porcini_1->GetFrame()->SetFillColor(21);
c_porcini_1->GetFrame()->SetBorderMode(-1);
c_porcini_1->GetFrame()->SetBorderSize(5);

ch_porcini_1->Draw();
ch_porcini_1->SetTitle("porcini spectrum via HPGe detector");
ch_porcini_1->SetName("porcini spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

c_porcini_1->Update();
c_porcini_1->SaveAs("plots/porcini_1.png");

/* /
cout << endl
     << "======================== CANISTERS ========================" << endl;
/* // Not Exposed Canister
cout << endl
     << "\t==================== Not Exposed Canister ===================="
     << endl;

cout << endl
     << "\t\t==================== ch 0 ===================="
     << endl;
TCanvas *c_nexp_can_0 = new TCanvas("nexp_can channel 0");
c_nexp_can_0->SetGridx();
c_nexp_can_0->SetGridy();
c_nexp_can_0->GetFrame()->SetFillColor(21);
c_nexp_can_0->GetFrame()->SetBorderMode(-1);
c_nexp_can_0->GetFrame()->SetBorderSize(5);

ch_nexp_can_0->Draw();

ch_nexp_can_0->SetTitle("nexp_can spectrum via NaI detector");
ch_nexp_can_0->SetName("nexp_can spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);
c_nexp_can_0->Update();
c_nexp_can_0->SaveAs("plots/nexp_can_0.png");
//* /
cout << endl
     << "\t\t==================== ch 1 ===================="
     << endl;
TCanvas *c_nexp_can_1 = new TCanvas("nexp_can channel 1");
c_nexp_can_1->SetGridx();
c_nexp_can_1->SetGridy();
c_nexp_can_1->GetFrame()->SetFillColor(21);
c_nexp_can_1->GetFrame()->SetBorderMode(-1);
c_nexp_can_1->GetFrame()->SetBorderSize(5);

ch_nexp_can_1->Draw();

ch_nexp_can_1->SetTitle("nexp_can spectrum via HPGe detector");
ch_nexp_can_1->SetName("nexp_can spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

c_nexp_can_1->Update();
c_nexp_can_1->SaveAs("plots/nexp_can_1.png");

//*/
// Exposed Canister
//*
cout << endl
     << "\t==================== Exposed Canister ====================" << endl;

cout << endl << "\t\t==================== ch 0 ====================" << endl;
TCanvas *c_exp_can_0 = new TCanvas("exp_can channel 0");
c_exp_can_0->SetGridx();
c_exp_can_0->SetGridy();
c_exp_can_0->GetFrame()->SetFillColor(21);
c_exp_can_0->GetFrame()->SetBorderMode(-1);
c_exp_can_0->GetFrame()->SetBorderSize(5);

TF1 *fitexp_can0p1 = new TF1("exp_can0_p1", "gaus(0)", 265, 315);
TF1 *fitexp_can0p2 = new TF1("exp_can0_p2", "gaus(0)", 320, 385);
TF1 *fitexp_can0p3 = new TF1("exp_can0_p3", "gaus(0)", 570, 660);
//TF1 *fitexp_can0p4 = new TF1("exp_can0_p4", "gaus(0)", 1080, 1180);
//TF1 *fitexp_can0p5 = new TF1("exp_can0_p5", "gaus(0)", 1700, 1800);

ch_exp_can_0->Fit("exp_can0_p1", "R");
ch_exp_can_0->Fit("exp_can0_p2", "R");
ch_exp_can_0->Fit("exp_can0_p3", "R");
//ch_exp_can_0->Fit("exp_can0_p4", "R");
//ch_exp_can_0->Fit("exp_can0_p5", "R");

fitexp_can0p1->Draw("SAME");
fitexp_can0p2->Draw("SAME");
fitexp_can0p3->Draw("SAME");
//fitexp_can0p4->Draw("SAME");
//fitexp_can0p5->Draw("SAME");

ch_exp_can_0->SetTitle("exp_can spectrum via NaI detector");
ch_exp_can_0->SetName("exp_can spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);
c_exp_can_0->Update();
c_exp_can_0->SaveAs("plots/exp_can_0.png");

double I_exp_can_01 = ch_exp_can_1->Integral(53, 115);
cout << endl << "\t Integral gives : " << I_exp_can_01 << endl;
double I_exp_can_02 = ch_exp_can_1->Integral(118, 195);
cout << endl << "\t Integral gives : " << I_exp_can_02 << endl;
double I_exp_can_03 = ch_exp_can_1->Integral(428, 516);
cout << endl << "\t Integral gives : " << I_exp_can_03 << endl;
//* /
cout << endl << "\t\t==================== ch 1 ====================" << endl;
TCanvas *c_exp_can_1 = new TCanvas("exp_can channel 1");
c_exp_can_1->SetGridx();
c_exp_can_1->SetGridy();
c_exp_can_1->GetFrame()->SetFillColor(21);
c_exp_can_1->GetFrame()->SetBorderMode(-1);
c_exp_can_1->GetFrame()->SetBorderSize(5);

TF1 *fitexp_can1p1 = new TF1("exp_can1_p1", "gaus(0)", 239, 246);
TF1 *fitexp_can1p2 = new TF1("exp_can1_p2", "gaus(0)", 290, 300);
TF1 *fitexp_can1p3 = new TF1("exp_can1_p3", "gaus(0)", 349, 355);
TF1 *fitexp_can1p4 = new TF1("exp_can1_p4", "gaus(0)", 606, 612);
//TF1 *fitexp_can1p5 = new TF1("exp_can1_p5", "gaus(0)", 1118, 1125);
//TF1 *fitexp_can1p6 = new TF1("exp_can1_p6", "gaus(0)", 1760, 1768);

ch_exp_can_1->Fit("exp_can1_p1", "R");
ch_exp_can_1->Fit("exp_can1_p2", "R");
ch_exp_can_1->Fit("exp_can1_p3", "R");
ch_exp_can_1->Fit("exp_can1_p4", "R");
//ch_exp_can_1->Fit("exp_can1_p5", "R");
//ch_exp_can_1->Fit("exp_can1_p6", "R");

fitexp_can1p1->Draw("SAME");
fitexp_can1p2->Draw("SAME");
fitexp_can1p3->Draw("SAME");
fitexp_can1p4->Draw("SAME");
//fitexp_can1p5->Draw("SAME");
//fitexp_can1p6->Draw("SAME");

ch_exp_can_1->SetTitle("exp_can spectrum via HPGe detector");
ch_exp_can_1->SetName("exp_can spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

c_exp_can_1->Update();
c_exp_can_1->SaveAs("plots/exp_can_1.png");

double I_exp_can_11 = ch_exp_can_1->Integral(220, 232);
cout << endl << "\t Integral gives : " << I_exp_can_11 << endl;
double I_exp_can_12 = ch_exp_can_1->Integral(329, 343);
cout << endl << "\t Integral gives : " << I_exp_can_12 << endl;
double I_exp_can_13 = ch_exp_can_1->Integral(456, 467);
cout << endl << "\t Integral gives : " << I_exp_can_13 << endl;
double I_exp_can_14 = ch_exp_can_1->Integral(1008, 1024);
cout << endl << "\t Integral gives : " << I_exp_can_14 << endl;
//*
// cal_can
cout << endl
     << "\t==================== Calibrated Canister ===================="
     << endl;

cout << endl << "\t\t==================== ch 0 ====================" << endl;
TCanvas *c_cal_can_0 = new TCanvas("cal_can channel 0");
c_cal_can_0->SetGridx();
c_cal_can_0->SetGridy();
c_cal_can_0->GetFrame()->SetFillColor(21);
c_cal_can_0->GetFrame()->SetBorderMode(-1);
c_cal_can_0->GetFrame()->SetBorderSize(5);

TF1 *fitcal_can0p1 = new TF1("cal_can0_p1", "gaus(0)", 260, 315);
TF1 *fitcal_can0p2 = new TF1("cal_can0_p2", "gaus(0)", 315, 380);
TF1 *fitcal_can0p3 = new TF1("cal_can0_p3", "gaus(0)", 560, 660);
//TF1 *fitcal_can0p4 = new TF1("cal_can0_p4", "gaus(0)", 1060, 1170);
//TF1 *fitcal_can0p5 = new TF1("cal_can0_p5", "gaus(0)", 1710, 1800);

ch_cal_can_0->Fit("cal_can0_p1", "R");
ch_cal_can_0->Fit("cal_can0_p2", "R");
ch_cal_can_0->Fit("cal_can0_p3", "R");
//ch_cal_can_0->Fit("cal_can0_p4", "R");
//ch_cal_can_0->Fit("cal_can0_p5", "R");

fitcal_can0p1->Draw("SAME");
fitcal_can0p2->Draw("SAME");
fitcal_can0p3->Draw("SAME");
//fitcal_can0p4->Draw("SAME");
//fitcal_can0p5->Draw("SAME");

ch_cal_can_0->SetTitle("cal_can spectrum via NaI detector");
ch_cal_can_0->SetName("cal_can spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);
c_cal_can_0->Update();
c_cal_can_0->SaveAs("plots/cal_can_0.png");

double I_cal_can_01 = ch_cal_can_0->Integral(50, 111);
cout << endl << "\t Integral gives : " << I_cal_can_01 << endl;
double I_cal_can_02 = ch_cal_can_0->Integral(120, 191);
cout << endl << "\t Integral gives : " << I_cal_can_02 << endl;
double I_cal_can_03 = ch_cal_can_0->Integral(423, 520);
cout << endl << "\t Integral gives : " << I_cal_can_03 << endl;
//* /
cout << endl << "\t\t==================== ch 1 ====================" << endl;
TCanvas *c_cal_can_1 = new TCanvas("cal_can channel 1");
c_cal_can_1->SetGridx();
c_cal_can_1->SetGridy();
c_cal_can_1->GetFrame()->SetFillColor(21);
c_cal_can_1->GetFrame()->SetBorderMode(-1);
c_cal_can_1->GetFrame()->SetBorderSize(5);

TF1 *fitcal_can1p1 = new TF1("cal_can1_p1", "gaus(0)", 239, 245);
TF1 *fitcal_can1p2 = new TF1("cal_can1_p2", "gaus(0)", 290, 300);
TF1 *fitcal_can1p3 = new TF1("cal_can1_p3", "gaus(0)", 348, 354);
TF1 *fitcal_can1p4 = new TF1("cal_can1_p4", "gaus(0)", 605, 613);
//TF1 *fitcal_can1p4 = new TF1("cal_can1_p4", "gaus(0)", 1116, 1124);
//TF1 *fitcal_can1p5 = new TF1("cal_can1_p5", "gaus(0)", 1755, 1770);

ch_cal_can_1->Fit("cal_can1_p1", "R");
ch_cal_can_1->Fit("cal_can1_p2", "R");
ch_cal_can_1->Fit("cal_can1_p3", "R");
ch_cal_can_1->Fit("cal_can1_p4", "R");
//ch_cal_can_1->Fit("cal_can1_p4", "R");
//ch_cal_can_1->Fit("cal_can1_p5", "R");

fitcal_can1p1->Draw("SAME");
fitcal_can1p2->Draw("SAME");
fitcal_can1p3->Draw("SAME");
fitcal_can1p4->Draw("SAME");
//fitcal_can1p4->Draw("SAME");
//fitcal_can1p5->Draw("SAME");

ch_cal_can_1->SetTitle("cal_can spectrum via HPGe detector");
ch_cal_can_1->SetName("cal_can spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

c_cal_can_1->Update();
c_cal_can_1->SaveAs("plots/cal_can_1.png");
// ch_cal_can_1->Draw();
double I_cal_can_11 = ch_cal_can_1->Integral(219, 228);
cout << endl << "\t Integral gives : " << I_cal_can_11 << endl;
double I_cal_can_12 = ch_cal_can_1->Integral(334, 345);
cout << endl << "\t Integral gives : " << I_cal_can_12 << endl;
double I_cal_can_13 = ch_cal_can_1->Integral(454, 469);
cout << endl << "\t Integral gives : " << I_cal_can_13 << endl;
double I_cal_can_14 = ch_cal_can_1->Integral(1009, 1027);
cout << endl << "\t Integral gives : " << I_cal_can_14 << endl;

//*/
cout << endl
     << "======================== RADIOACTIVE MATERIAL ========================"
     << endl;
//* /
// Europio
cout << endl << "\t==================== europio ====================" << endl;

cout << endl << "\t\t==================== ch 0 ====================" << endl;
TCanvas *c_europio_0 = new TCanvas("europio channel 0");
c_europio_0->SetGridx();
c_europio_0->SetGridy();
c_europio_0->GetFrame()->SetFillColor(21);
c_europio_0->GetFrame()->SetBorderMode(-1);
c_europio_0->GetFrame()->SetBorderSize(5);

TF1 *fiteuropio0p1 = new TF1("europio0_p1", "gaus(0)", 220, 260);
TF1 *fiteuropio0p2 = new TF1("europio0_p2", "gaus(0)", 308, 379);
TF1 *fiteuropio0p3 = new TF1("europio0_p3", "gaus(0)", 730, 830);
TF1 *fiteuropio0p4 = new TF1("europio0_p4", "gaus(0)", 920, 1020);
TF1 *fiteuropio0p5 = new TF1("europio0_p5", "gaus(0)", 1040, 1160);
TF1 *fiteuropio0p6 = new TF1("europio0_p6", "gaus(0)", 1350, 1455);

ch_europio_0->Fit("europio0_p1", "R");
ch_europio_0->Fit("europio0_p2", "R");
ch_europio_0->Fit("europio0_p3", "R");
ch_europio_0->Fit("europio0_p4", "R");
ch_europio_0->Fit("europio0_p5", "R");
ch_europio_0->Fit("europio0_p6", "R");

fiteuropio0p1->Draw("SAME");
fiteuropio0p2->Draw("SAME");
fiteuropio0p3->Draw("SAME");
fiteuropio0p4->Draw("SAME");
fiteuropio0p5->Draw("SAME");
fiteuropio0p6->Draw("SAME");

ch_europio_0->SetTitle("europio spectrum via NaI detector");
ch_europio_0->SetName("europio spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);
c_europio_0->Update();
c_europio_0->SaveAs("plots/europio_0.png");

double I_eur_01 = ch_europio_0->Integral(99, 147);
cout << endl << "\t Integral gives : " << I_eur_01 << endl;
double I_eur_02 = ch_europio_0->Integral(207, 286);
cout << endl << "\t Integral gives : " << I_eur_02 << endl;
double I_eur_03 = ch_europio_0->Integral(732, 829);
cout << endl << "\t Integral gives : " << I_eur_03 << endl;
double I_eur_04 = ch_europio_0->Integral(950, 1052);
cout << endl << "\t Integral gives : " << I_eur_04 << endl;
double I_eur_05 = ch_europio_0->Integral(1110, 1228);
cout << endl << "\t Integral gives : " << I_eur_05 << endl;
double I_eur_06 = ch_europio_0->Integral(1473, 1607);
cout << endl << "\t Integral gives : " << I_eur_06 << endl;
//* /
cout << endl << "\t\t==================== ch 1 ====================" << endl;
TCanvas *c_europio_1 = new TCanvas("europio channel 1");
c_europio_1->SetGridx();
c_europio_1->SetGridy();
c_europio_1->GetFrame()->SetFillColor(21);
c_europio_1->GetFrame()->SetBorderMode(-1);
c_europio_1->GetFrame()->SetBorderSize(5);

TF1 *fiteuropio1p1 = new TF1("europio1_p1", "gaus(0)", 70, 78);
TF1 *fiteuropio1p2 = new TF1("europio1_p2", "gaus(0)", 81, 95);
TF1 *fiteuropio1p3 = new TF1("europio1_p3", "gaus(0)", 119, 124);
TF1 *fiteuropio1p4 = new TF1("europio1_p4", "gaus(0)", 240, 249);
TF1 *fiteuropio1p5 = new TF1("europio1_p5", "gaus(0)", 340, 349);
TF1 *fiteuropio1p6 = new TF1("europio1_p6", "gaus(0)", 365, 371);
TF1 *fiteuropio1p7 = new TF1("europio1_p7", "gaus(0)", 409, 413);
TF1 *fiteuropio1p8 = new TF1("europio1_p8", "gaus(0)", 441, 448);
TF1 *fiteuropio1p9 = new TF1("europio1_p9", "gaus(0)", 775, 783);
TF1 *fiteuropio1p10 = new TF1("europio1_p10", "gaus(0)", 863, 870);
TF1 *fiteuropio1p11 = new TF1("europio1_p11", "gaus(0)", 960, 967);
TF1 *fiteuropio1p12 = new TF1("europio1_p12", "gaus(0)", 1081, 1089);
TF1 *fiteuropio1p13 = new TF1("europio1_p13", "gaus(0)", 1108, 1116);
TF1 *fiteuropio1p14 = new TF1("europio1_p14", "gaus(0)", 1400, 1415);

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
ch_europio_1->Fit("europio1_p14", "R");
//* 0
fiteuropio1p1->Draw("SAME");
fiteuropio1p2->Draw("SAME");
fiteuropio1p3->Draw("SAME");
fiteuropio1p4->Draw("SAME");
fiteuropio1p5->Draw("SAME");
fiteuropio1p6->Draw("SAME");
fiteuropio1p7->Draw("SAME");
fiteuropio1p8->Draw("SAME");
fiteuropio1p9->Draw("SAME");
fiteuropio1p10->Draw("SAME");
fiteuropio1p11->Draw("SAME");
fiteuropio1p12->Draw("SAME");
fiteuropio1p13->Draw("SAME");
fiteuropio1p14->Draw("SAME");

ch_europio_1->SetTitle("europio spectrum via HPGe detector");
ch_europio_1->SetName("europio spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

c_europio_1->Update();
c_europio_1->SaveAs("plots/europio_1.png");
// ch_europio_1->Draw();

double I_eur_11 = ch_europio_1->Integral(4, 17);
cout << endl << "\t Integral gives : " << I_eur_11 << endl;
double I_eur_12 = ch_europio_1->Integral(26, 54);
cout << endl << "\t Integral gives : " << I_eur_12 << endl;
double I_eur_13 = ch_europio_1->Integral(109, 118);
cout << endl << "\t Integral gives : " << I_eur_13 << endl;
double I_eur_14 = ch_europio_1->Integral(374, 385);
cout << endl << "\t Integral gives : " << I_eur_14 << endl;
double I_eur_15 = ch_europio_1->Integral(589, 600);
cout << endl << "\t Integral gives : " << I_eur_15 << endl;
double I_eur_16 = ch_europio_1->Integral(640, 650);
cout << endl << "\t Integral gives : " << I_eur_16 << endl;
double I_eur_17 = ch_europio_1->Integral(734, 744);
cout << endl << "\t Integral gives : " << I_eur_17 << endl;
double I_eur_18 = ch_europio_1->Integral(804, 818);
cout << endl << "\t Integral gives : " << I_eur_18 << endl;
double I_eur_19 = ch_europio_1->Integral(1528, 1541);
cout << endl << "\t Integral gives : " << I_eur_19 << endl;
double I_eur_110 = ch_europio_1->Integral(1718, 1731);
cout << endl << "\t Integral gives : " << I_eur_110 << endl;
double I_eur_111 = ch_europio_1->Integral(1927, 1941);
cout << endl << "\t Integral gives : " << I_eur_111 << endl;
double I_eur_112 = ch_europio_1->Integral(2191, 2204);
cout << endl << "\t Integral gives : " << I_eur_112 << endl;
double I_eur_113 = ch_europio_1->Integral(2246, 2261);
cout << endl << "\t Integral gives : " << I_eur_113 << endl;
double I_eur_114 = ch_europio_1->Integral(2882, 2903);
cout << endl << "\t Integral gives : " << I_eur_114 << endl;
//* /
// americio
cout << endl << "\t==================== americio ====================" << endl;

cout << endl << "\t\t==================== ch 0 ====================" << endl;
TCanvas *c_americio_0 = new TCanvas("americio channel 0");
c_americio_0->SetGridx();
c_americio_0->SetGridy();
c_americio_0->GetFrame()->SetFillColor(21);
c_americio_0->GetFrame()->SetBorderMode(-1);
c_americio_0->GetFrame()->SetBorderSize(5);

ch_americio_0->SetTitle("americio spectrum via NaI detector");
ch_americio_0->SetName("americio spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);
ch_americio_0->Draw();
c_americio_0->Update();
c_americio_0->SaveAs("plots/americio_0.png");
//* /
cout << endl << "\t\t==================== ch 1 ====================" << endl;
TCanvas *c_americio_1 = new TCanvas("americio channel 1");
c_americio_1->SetGridx();
c_americio_1->SetGridy();
c_americio_1->GetFrame()->SetFillColor(21);
c_americio_1->GetFrame()->SetBorderMode(-1);
c_americio_1->GetFrame()->SetBorderSize(5);

TF1 *fitamericio1 = new TF1("americio1", "gaus(0)", 57, 62); // 124, 134);

ch_americio_1->Fit("americio1", "R");

ch_americio_1->SetTitle("americio spectrum via HPGe detector");
ch_americio_1->SetName("americio spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

c_americio_1->Update();
c_americio_1->SaveAs("plots/americio_1.png");
double I_amer_1 = ch_americio_1->Integral(24, 33);
cout << endl << "\t Integral gives : " << I_amer_1 << endl;
//  cobalto
//* /
cout << endl << "\t==================== Cobalt ====================" << endl;

cout << endl << "\t\t==================== ch 0 ====================" << endl;

TCanvas *c_cobalto_0 = new TCanvas("cobalto channel 0");
c_cobalto_0->SetGridx();
c_cobalto_0->SetGridy();
c_cobalto_0->GetFrame()->SetFillColor(21);
c_cobalto_0->GetFrame()->SetBorderMode(-1);
c_cobalto_0->GetFrame()->SetBorderSize(5);

TF1 *fitcobalto0p1 =
    new TF1("cobalto0_p1", "gaus(0)", 1115, 1235); // 1380,1525);
TF1 *fitcobalto0p2 = new TF1("cobalto0_p2", "gaus(0)", 1265,
                             1390); // 1570, 1735);

ch_cobalto_0->Fit("cobalto0_p1", "R");
ch_cobalto_0->Fit("cobalto0_p2", "R");
// ch_cobalto_0->ShowBackground(22);

fitcobalto0p1->Draw("SAME");
fitcobalto0p2->Draw("SAME");

ch_cobalto_0->SetTitle("cobalto spectrum via NaI detector");
ch_cobalto_0->SetName("cobalt spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

c_cobalto_0->Update();
c_cobalto_0->SaveAs("plots/cobalto_0.png");
double I_cob_00 = ch_cobalto_0->Integral(1193, 1317);
cout << endl << "\t Integral gives : " << I_cob_00 << endl;
double I_cob_01 = ch_cobalto_0->Integral(1386, 1512);
cout << endl << "\t Integral gives : " << I_cob_01 << endl;

cout << endl << "\t\t==================== ch 1 ====================" << endl;
TCanvas *c_cobalto_1 = new TCanvas("cobalto channel 1");
c_cobalto_1->SetGridx();
c_cobalto_1->SetGridy();
c_cobalto_1->GetFrame()->SetFillColor(21);
c_cobalto_1->GetFrame()->SetBorderMode(-1);
c_cobalto_1->GetFrame()->SetBorderSize(5);

TF1 *fitcobalto1p1 = new TF1("cobalto1_p1", "gaus(0)", 1168, 1178);
// 2524,2545);
TF1 *fitcobalto1p2 = new TF1("cobalto1_p2", "gaus(0)", 1328, 1336);
// 2870, 2889);

ch_cobalto_1->Fit("cobalto1_p1", "R");
ch_cobalto_1->Fit("cobalto1_p2", "R");
ch_cobalto_1->Draw();
//
fitcobalto1p1->Draw("SAME"); // GetParameters(&cob_par_1[0]);
fitcobalto1p2->Draw("SAME"); // GetParameters(&cob_par_1[3]);

ch_cobalto_1->SetTitle("cobalto spectrum via HPGe detector");
ch_cobalto_1->SetName("cobalt spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

// c_cobalto_1->SetLogy();
c_cobalto_1->Update();
c_cobalto_1->SaveAs("plots/cobalto_1.png");
double I_cob_10 = ch_cobalto_1->Integral(27, 43);
cout << endl << "\t Integral gives : " << I_cob_10 << endl;
double I_cob_11 = ch_cobalto_1->Integral(371, 388);
cout << endl << "\t Integral gives : " << I_cob_11 << endl;

//* /
// sodio
cout << endl << "\t==================== Sodio ====================" << endl;

cout << endl << "\t\t==================== ch 0 ====================" << endl;
TCanvas *c_sodio_0 = new TCanvas("Sodio channel 0");
c_sodio_0->SetGridx();
c_sodio_0->SetGridy();
c_sodio_0->GetFrame()->SetFillColor(21);
c_sodio_0->GetFrame()->SetBorderMode(-1);
c_sodio_0->GetFrame()->SetBorderSize(5);

TF1 *fitsodio0 = new TF1("sodio0", "gaus(0)", 455, 560);     // 590, 710);
TF1 *fitsodio01 = new TF1("sodio01", "gaus(0)", 1220, 1325); // 1515, 1640);

ch_sodio_0->Fit("sodio0", "R");
ch_sodio_0->Fit("sodio01", "R");

fitsodio0->Draw("SAME");
fitsodio01->Draw("SAME");

ch_sodio_0->SetTitle("Sodio spectrum via NaI detector");
ch_sodio_0->SetName("sodium spectrum");
// ch_sodio_0->ShowBackground(22);

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

c_sodio_0->Update();
c_sodio_0->SaveAs("plots/sodio_0.png");

int I_sodio_0 = ch_sodio_0->Integral(392, 512);
cout << endl << "\t Integral gives : " << I_sodio_0 << endl;
double I_sodio_01 = ch_sodio_0->Integral(1317, 1436);
cout << endl << "\t Integral gives : " << I_sodio_01 << endl;

cout << endl << "\t\t==================== ch 1 ====================" << endl;
TCanvas *c_sodio_1 = new TCanvas("Sodio channel 1");
c_sodio_1->SetGridx();
c_sodio_1->SetGridy();
c_sodio_1->GetFrame()->SetFillColor(21);
c_sodio_1->GetFrame()->SetBorderMode(-1);
c_sodio_1->GetFrame()->SetBorderSize(5);

TF1 *fitsodio1 = new TF1("sodio1", "gaus(0)", 506, 516);   // 1095, 1115);
TF1 *fitsodio2 = new TF1("sodio2", "gaus(0)", 1270, 1279); // 2745, 2764);

ch_sodio_1->Fit("sodio1", "R");
ch_sodio_1->Fit("sodio2", "R");
ch_sodio_1->Draw();

fitsodio1->Draw("SAME");
fitsodio2->Draw("SAME");
//
ch_sodio_1->SetTitle("Sodio spectrum via HPGe detector");
ch_sodio_1->SetName("sodium spectrum");

gStyle->SetOptFit(0000);
gStyle->SetOptStat(00);

c_sodio_1->Update();
c_sodio_1->SaveAs("plots/sodio_1.png");

double I_sodio_1 = ch_sodio_1->Integral(12, 37);
cout << endl << "\t Integral gives : " << I_sodio_1 << endl;
double I_sodio_2 = ch_sodio_1->Integral(1667, 1683);
cout << endl << "\t Integral gives : " << I_sodio_2 << endl;
//*/

double *autunite0p1 = fitautunite0p1->GetParameters();
const double *Eautunite0p1 = fitautunite0p1->GetParErrors();
double *autunite0p2 = fitautunite0p2->GetParameters();
const double *Eautunite0p2 = fitautunite0p2->GetParErrors();
double *autunite0p3 = fitautunite0p3->GetParameters();
const double *Eautunite0p3 = fitautunite0p3->GetParErrors();

double *autunite1p1 = fitautunite1p1->GetParameters();
const double *Eautunite1p1 = fitautunite1p1->GetParErrors();
double *autunite1p2 = fitautunite1p2->GetParameters();
const double *Eautunite1p2 = fitautunite1p2->GetParErrors();
double *autunite1p3 = fitautunite1p3->GetParameters();
const double *Eautunite1p3 = fitautunite1p3->GetParErrors();

double *exp_can0p1 = fitexp_can0p1->GetParameters();
const double *Eexp_can0p1 = fitexp_can0p1->GetParErrors();
double *exp_can0p2 = fitexp_can0p2->GetParameters();
const double *Eexp_can0p2 = fitexp_can0p2->GetParErrors();
double *exp_can0p3 = fitexp_can0p3->GetParameters();
const double *Eexp_can0p3 = fitexp_can0p3->GetParErrors();

double *exp_can1p1 = fitexp_can1p1->GetParameters();
const double *Eexp_can1p1 = fitexp_can1p1->GetParErrors();
double *exp_can1p2 = fitexp_can1p2->GetParameters();
const double *Eexp_can1p2 = fitexp_can1p2->GetParErrors();
double *exp_can1p3 = fitexp_can1p3->GetParameters();
const double *Eexp_can1p3 = fitexp_can1p3->GetParErrors();
double *exp_can1p4 = fitexp_can1p4->GetParameters();
const double *Eexp_can1p4 = fitexp_can1p4->GetParErrors();

double *cal_can0p1 = fitcal_can0p1->GetParameters();
const double *Ecal_can0p1 = fitcal_can0p1->GetParErrors();
double *cal_can0p2 = fitcal_can0p2->GetParameters();
const double *Ecal_can0p2 = fitcal_can0p2->GetParErrors();
double *cal_can0p3 = fitcal_can0p3->GetParameters();
const double *Ecal_can0p3 = fitcal_can0p3->GetParErrors();

double *cal_can1p1 = fitcal_can1p1->GetParameters();
const double *Ecal_can1p1 = fitcal_can1p1->GetParErrors();
double *cal_can1p2 = fitcal_can1p2->GetParameters();
const double *Ecal_can1p2 = fitcal_can1p2->GetParErrors();
double *cal_can1p3 = fitcal_can1p3->GetParameters();
const double *Ecal_can1p3 = fitcal_can1p3->GetParErrors();
double *cal_can1p4 = fitcal_can1p4->GetParameters();
const double *Ecal_can1p4 = fitcal_can1p4->GetParErrors();

double *europio0p1 = fiteuropio0p1->GetParameters();
const double *Eeuropio0p1 = fiteuropio0p1->GetParErrors();
double *europio0p2 = fiteuropio0p2->GetParameters();
const double *Eeuropio0p2 = fiteuropio0p2->GetParErrors();
double *europio0p3 = fiteuropio0p3->GetParameters();
const double *Eeuropio0p3 = fiteuropio0p3->GetParErrors();
double *europio0p4 = fiteuropio0p4->GetParameters();
const double *Eeuropio0p4 = fiteuropio0p4->GetParErrors();
double *europio0p5 = fiteuropio0p5->GetParameters();
const double *Eeuropio0p5 = fiteuropio0p5->GetParErrors();
double *europio0p6 = fiteuropio0p6->GetParameters();
const double *Eeuropio0p6 = fiteuropio0p6->GetParErrors();

double *europio1p1 = fiteuropio1p1->GetParameters();
const double *Eeuropio1p1 = fiteuropio1p1->GetParErrors();
double *europio1p2 = fiteuropio1p2->GetParameters();
const double *Eeuropio1p2 = fiteuropio1p2->GetParErrors();
double *europio1p3 = fiteuropio1p3->GetParameters();
const double *Eeuropio1p3 = fiteuropio1p3->GetParErrors();
double *europio1p4 = fiteuropio1p4->GetParameters();
const double *Eeuropio1p4 = fiteuropio1p4->GetParErrors();
double *europio1p5 = fiteuropio1p5->GetParameters();
const double *Eeuropio1p5 = fiteuropio1p5->GetParErrors();
double *europio1p6 = fiteuropio1p6->GetParameters();
const double *Eeuropio1p6 = fiteuropio1p6->GetParErrors();
double *europio1p7 = fiteuropio1p7->GetParameters();
const double *Eeuropio1p7 = fiteuropio1p7->GetParErrors();
double *europio1p8 = fiteuropio1p8->GetParameters();
const double *Eeuropio1p8 = fiteuropio1p8->GetParErrors();
double *europio1p9 = fiteuropio1p9->GetParameters();
const double *Eeuropio1p9 = fiteuropio1p9->GetParErrors();
double *europio1p10 = fiteuropio1p10->GetParameters();
const double *Eeuropio1p10 = fiteuropio1p10->GetParErrors();
double *europio1p11 = fiteuropio1p11->GetParameters();
const double *Eeuropio1p11 = fiteuropio1p11->GetParErrors();
double *europio1p12 = fiteuropio1p12->GetParameters();
const double *Eeuropio1p12 = fiteuropio1p12->GetParErrors();
double *europio1p13 = fiteuropio1p13->GetParameters();
const double *Eeuropio1p13 = fiteuropio1p13->GetParErrors();
double *europio1p14 = fiteuropio1p14->GetParameters();
const double *Eeuropio1p14 = fiteuropio1p14->GetParErrors();

double *americio1 = fitamericio1->GetParameters();
const double *Eamericio1 = fitamericio1->GetParErrors();

double *cobalto1 = fitcobalto1p1->GetParameters();
const double *Ecobalto1 = fitcobalto1p1->GetParErrors();
double *cobalto2 = fitcobalto1p2->GetParameters();
const double *Ecobalto2 = fitcobalto1p2->GetParErrors();

double *cobalto0 = fitcobalto0p1->GetParameters();
const double *Ecobalto0 = fitcobalto0p1->GetParErrors();
double *cobalto01 = fitcobalto0p2->GetParameters();
const double *Ecobalto01 = fitcobalto0p2->GetParErrors();

double *sodio1 = fitsodio1->GetParameters();
const double *Esodio1 = fitsodio1->GetParErrors();
double *sodio2 = fitsodio2->GetParameters();
const double *Esodio2 = fitsodio2->GetParErrors();

double *sodio0 = fitsodio0->GetParameters();
const double *Esodio0 = fitsodio0->GetParErrors();
double *sodio01 = fitsodio01->GetParameters();
const double *Esodio01 = fitsodio01->GetParErrors();

std::ofstream outFile;
std::string filetowrite = "thing.csv";
outFile.open(filetowrite, std::ios_base::out);
if (!outFile)
  std::cout << "Failed to open the output file\n";
else {
  cout << "Writing to " << filetowrite << endl;
  outFile
      << "sample,chnl,peak_nmbr,const,mean,sigma,dconst,dmean,dsigma,Int"
      << endl
      << "sodio," << 0 << "," << 1 << "," << sodio0[0] << "," << sodio0[1]
      << "," << sodio0[2] << "," << Esodio0[0] << "," << Esodio0[1] << ","
      << Esodio0[2] << "," << I_sodio_0 << endl
      << "sodio," << 0 << "," << 2 << "," << sodio01[0] << "," << sodio01[1]
      << "," << sodio01[2] << "," << Esodio01[0] << "," << Esodio01[1] << ","
      << Esodio01[2] << "," << I_sodio_01 << endl
      << "sodio," << 1 << "," << 1 << "," << sodio1[0] << "," << sodio1[1]
      << "," << sodio1[2] << "," << Esodio1[0] << "," << Esodio1[1] << ","
      << Esodio1[2] << "," << I_sodio_1 << endl
      << "sodio," << 1 << "," << 2 << "," << sodio2[0] << "," << sodio2[1]
      << "," << sodio2[2] << "," << Esodio2[0] << "," << Esodio2[1] << ","
      << Esodio2[2] << "," << I_sodio_2 << endl
      << "cobalto," << 0 << "," << 1 << "," << cobalto0[0] << "," << cobalto0[1]
      << "," << cobalto0[2] << "," << Ecobalto0[0] << "," << Ecobalto0[1] << ","
      << Ecobalto0[2] << "," << I_cob_00 << endl
      << "cobalto," << 0 << "," << 2 << "," << cobalto01[0] << ","
      << cobalto01[1] << "," << cobalto01[2] << "," << Ecobalto01[0] << ","
      << Ecobalto01[1] << "," << Ecobalto01[2] << "," << I_cob_01 << endl
      << "cobalto," << 1 << "," << 1 << "," << cobalto1[0] << "," << cobalto1[1]
      << "," << cobalto1[2] << "," << Ecobalto1[0] << "," << Ecobalto1[1] << ","
      << Ecobalto1[2] << "," << I_cob_10 << endl
      << "cobalto," << 1 << "," << 2 << "," << cobalto2[0] << "," << cobalto2[1]
      << "," << cobalto2[2] << "," << Ecobalto2[0] << "," << Ecobalto2[1] << ","
      << Ecobalto2[2] << "," << I_cob_11 << endl
      << "americio," << 1 << "," << 1 << "," << americio1[0] << ","
      << americio1[1] << "," << americio1[2] << "," << Eamericio1[0] << ","
      << Eamericio1[1] << "," << Eamericio1[2] << "," << I_amer_1 << endl
      << "europio," << 0 << "," << 1 << "," << europio0p1[0] << ","
      << europio0p1[1] << "," << europio0p1[2] << "," << Eeuropio0p1[0] << ","
      << Eeuropio0p1[1] << "," << Eeuropio0p1[2] << "," << I_eur_01 << endl
      << "europio," << 0 << "," << 2 << "," << europio0p2[0] << ","
      << europio0p2[1] << "," << europio0p2[2] << "," << Eeuropio0p2[0] << ","
      << Eeuropio0p2[1] << "," << Eeuropio0p2[2] << "," << I_eur_02 << endl
      << "europio," << 0 << "," << 3 << "," << europio0p3[0] << ","
      << europio0p3[1] << "," << europio0p3[2] << "," << Eeuropio0p3[0] << ","
      << Eeuropio0p3[1] << "," << Eeuropio0p3[2] << "," << I_eur_03 << endl
      << "europio," << 0 << "," << 4 << "," << europio0p4[0] << ","
      << europio0p4[1] << "," << europio0p4[2] << "," << Eeuropio0p4[0] << ","
      << Eeuropio0p4[1] << "," << Eeuropio0p4[2] << "," << I_eur_04 << endl
      << "europio," << 0 << "," << 5 << "," << europio0p5[0] << ","
      << europio0p5[1] << "," << europio0p5[2] << "," << Eeuropio0p5[0] << ","
      << Eeuropio0p5[1] << "," << Eeuropio0p5[2] << "," << I_eur_05 << endl
      << "europio," << 0 << "," << 6 << "," << europio0p6[0] << ","
      << europio0p6[1] << "," << europio0p6[2] << "," << Eeuropio0p6[0] << ","
      << Eeuropio0p6[1] << "," << Eeuropio0p6[2] << "," << I_eur_06
      << endl
      // << "europio," << 1 << "," << 1 << "," << europio1p1[0] << ","
      // << europio1p1[1] << "," << europio1p1[2] << "," << Eeuropio1p1[0] <<
      // ","
      // << Eeuropio1p1[1] << "," << Eeuropio1p1[2] << "," << I_eur_11 << endl
      // << "europio," << 1 << "," << 2 << "," << europio1p2[0] << ","
      // << europio1p2[1] << "," << europio1p2[2] << "," << Eeuropio1p2[0] <<
      // ","
      // << Eeuropio1p2[1] << "," << Eeuropio1p2[2] << "," << I_eur_12 << endl
      << "europio," << 1 << "," << 3 << "," << europio1p3[0] << ","
      << europio1p3[1] << "," << europio1p3[2] << "," << Eeuropio1p3[0] << ","
      << Eeuropio1p3[1] << "," << Eeuropio1p3[2] << "," << I_eur_13 << endl
      << "europio," << 1 << "," << 4 << "," << europio1p4[0] << ","
      << europio1p4[1] << "," << europio1p4[2] << "," << Eeuropio1p4[0] << ","
      << Eeuropio1p4[1] << "," << Eeuropio1p4[2] << "," << I_eur_14 << endl
      << "europio," << 1 << "," << 5 << "," << europio1p5[0] << ","
      << europio1p5[1] << "," << europio1p5[2] << "," << Eeuropio1p5[0] << ","
      << Eeuropio1p5[1] << "," << Eeuropio1p5[2] << "," << I_eur_15 << endl
      << "europio," << 1 << "," << 6 << "," << europio1p6[0] << ","
      << europio1p6[1] << "," << europio1p6[2] << "," << Eeuropio1p6[0] << ","
      << Eeuropio1p6[1] << "," << Eeuropio1p6[2] << "," << I_eur_16 << endl
      << "europio," << 1 << "," << 7 << "," << europio1p7[0] << ","
      << europio1p7[1] << "," << europio1p7[2] << "," << Eeuropio1p7[0] << ","
      << Eeuropio1p7[1] << "," << Eeuropio1p7[2] << "," << I_eur_17 << endl
      << "europio," << 1 << "," << 8 << "," << europio1p8[0] << ","
      << europio1p8[1] << "," << europio1p8[2] << "," << Eeuropio1p8[0] << ","
      << Eeuropio1p8[1] << "," << Eeuropio1p8[2] << "," << I_eur_18 << endl
      << "europio," << 1 << "," << 9 << "," << europio1p9[0] << ","
      << europio1p9[1] << "," << europio1p9[2] << "," << Eeuropio1p9[0] << ","
      << Eeuropio1p9[1] << "," << Eeuropio1p9[2] << "," << I_eur_19 << endl
      << "europio," << 1 << "," << 10 << "," << europio1p10[0] << ","
      << europio1p10[1] << "," << europio1p10[2] << "," << Eeuropio1p10[0]
      << "," << Eeuropio1p10[1] << "," << Eeuropio1p10[2] << "," << I_eur_110
      << endl
      << "europio," << 1 << "," << 11 << "," << europio1p11[0] << ","
      << europio1p11[1] << "," << europio1p11[2] << "," << Eeuropio1p11[0]
      << "," << Eeuropio1p11[1] << "," << Eeuropio1p11[2] << "," << I_eur_111
      << endl
      << "europio," << 1 << "," << 12 << "," << europio1p12[0] << ","
      << europio1p12[1] << "," << europio1p12[2] << "," << Eeuropio1p12[0]
      << "," << Eeuropio1p12[1] << "," << Eeuropio1p12[2] << "," << I_eur_112
      << endl
      << "europio," << 1 << "," << 13 << "," << europio1p13[0] << ","
      << europio1p13[1] << "," << europio1p13[2] << "," << Eeuropio1p13[0]
      << "," << Eeuropio1p13[1] << "," << Eeuropio1p13[2] << "," << I_eur_113
      << endl
      << "europio," << 1 << "," << 14 << "," << europio1p14[0] << ","
      << europio1p14[1] << "," << europio1p14[2] << "," << Eeuropio1p14[0]
      << "," << Eeuropio1p14[1] << "," << Eeuropio1p14[2] << "," << I_eur_114
      << endl
      << "cal_can," << 0 << "," << 1 << "," << cal_can0p1[0] << "," << cal_can0p1[1]
      << "," << cal_can0p1[2] << "," << Ecal_can0p1[0] << "," << Ecal_can0p1[1] << ","
      << Ecal_can0p1[2] << "," << I_cal_can_01 << endl
      << "cal_can," << 0 << "," << 2 << "," << cal_can0p2[0] << "," << cal_can0p2[1]
      << "," << cal_can0p2[2] << "," << Ecal_can0p2[0] << "," << Ecal_can0p2[1] << ","
      << Ecal_can0p2[2] << "," << I_cal_can_02 << endl
      << "cal_can," << 0 << "," << 3 << "," << cal_can0p3[0] << "," << cal_can0p3[1]
      << "," << cal_can0p3[2] << "," << Ecal_can0p3[0] << "," << Ecal_can0p3[1] << ","
      << Ecal_can0p3[2] << "," << I_cal_can_03 << endl
      << "cal_can," << 1 << "," << 1 << "," << cal_can1p1[0] << "," << cal_can1p1[1]
      << "," << cal_can1p1[2] << "," << Ecal_can1p1[0] << "," << Ecal_can1p1[1] << ","
      << Ecal_can1p1[2] << "," << I_cal_can_11 << endl
      << "cal_can," << 1 << "," << 2 << "," << cal_can1p2[0] << "," << cal_can1p2[1]
      << "," << cal_can1p2[2] << "," << Ecal_can1p2[0] << "," << Ecal_can1p2[1] << ","
      << Ecal_can1p2[2] << "," << I_cal_can_12 << endl
      << "cal_can," << 1 << "," << 3 << "," << cal_can1p3[0] << "," << cal_can1p3[1]
      << "," << cal_can1p3[2] << "," << Ecal_can1p3[0] << "," << Ecal_can1p3[1] << ","
      << Ecal_can1p3[2] << "," << I_cal_can_13 << endl
      << "cal_can," << 1 << "," << 4 << "," << cal_can1p4[0] << "," << cal_can1p4[1]
      << "," << cal_can1p4[2] << "," << Ecal_can1p4[0] << "," << Ecal_can1p4[1] << ","
      << Ecal_can1p4[2] << "," << I_cal_can_14 << endl
      << "exp_can," << 0 << "," << 1 << "," << exp_can0p1[0] << "," << exp_can0p1[1]
      << "," << exp_can0p1[2] << "," << Eexp_can0p1[0] << "," << Eexp_can0p1[1] << ","
      << Eexp_can0p1[2] << "," << I_exp_can_01 << endl
      << "exp_can," << 0 << "," << 2 << "," << exp_can0p2[0] << "," << exp_can0p2[1]
      << "," << exp_can0p2[2] << "," << Eexp_can0p2[0] << "," << Eexp_can0p2[1] << ","
      << Eexp_can0p2[2] << "," << I_exp_can_02 << endl
      << "exp_can," << 0 << "," << 3 << "," << exp_can0p3[0] << "," << exp_can0p3[1]
      << "," << exp_can0p3[2] << "," << Eexp_can0p3[0] << "," << Eexp_can0p3[1] << ","
      << Eexp_can0p3[2] << "," << I_exp_can_03 << endl
      << "exp_can," << 1 << "," << 1 << "," << exp_can1p1[0] << "," << exp_can1p1[1]
      << "," << exp_can1p1[2] << "," << Eexp_can1p1[0] << "," << Eexp_can1p1[1] << ","
      << Eexp_can1p1[2] << "," << I_exp_can_11 << endl
      << "exp_can," << 1 << "," << 2 << "," << exp_can1p2[0] << "," << exp_can1p2[1]
      << "," << exp_can1p2[2] << "," << Eexp_can1p2[0] << "," << Eexp_can1p2[1] << ","
      << Eexp_can1p2[2] << "," << I_exp_can_12 << endl
      << "exp_can," << 1 << "," << 3 << "," << exp_can1p3[0] << "," << exp_can1p3[1]
      << "," << exp_can1p3[2] << "," << Eexp_can1p3[0] << "," << Eexp_can1p3[1] << ","
      << Eexp_can1p3[2] << "," << I_exp_can_13 << endl
      << "exp_can," << 1 << "," << 4 << "," << exp_can1p4[0] << "," << exp_can1p4[1]
      << "," << exp_can1p4[2] << "," << Eexp_can1p4[0] << "," << Eexp_can1p4[1] << ","
      << Eexp_can1p4[2] << "," << I_exp_can_14 << endl
      << "autunite," << 0 << "," << 1 << "," << autunite0p1[0] << ","
      << autunite0p1[1] << "," << autunite0p1[2] << "," << Eautunite0p1[0] << ","
      << Eautunite0p1[1] << "," << Eautunite0p1[2] << "," << I_aut_01 << endl
      << "autunite," << 0 << "," << 2 << "," << autunite0p2[0] << ","
      << autunite0p2[1] << "," << autunite0p2[2] << "," << Eautunite0p2[0] << ","
      << Eautunite0p2[1] << "," << Eautunite0p2[2] << "," << I_aut_02 << endl
      << "autunite," << 0 << "," << 3 << "," << autunite0p3[0] << ","
      << autunite0p3[1] << "," << autunite0p3[2] << "," << Eautunite0p3[0] << ","
      << Eautunite0p3[1] << "," << Eautunite0p3[2] << "," << I_aut_03 << endl
      << "autunite," << 1 << "," << 1 << "," << autunite1p1[0] << ","
      << autunite1p1[1] << "," << autunite1p1[2] << "," << Eautunite1p1[0] << ","
      << Eautunite1p1[1] << "," << Eautunite1p1[2] << "," << I_aut_11 << endl
      << "autunite," << 1 << "," << 2 << "," << autunite1p2[0] << ","
      << autunite1p2[1] << "," << autunite1p2[2] << "," << Eautunite1p2[0] << ","
      << Eautunite1p2[1] << "," << Eautunite1p2[2] << "," << I_aut_12 << endl
      << "autunite," << 1 << "," << 3 << "," << autunite1p3[0] << ","
      << autunite1p3[1] << "," << autunite1p3[2] << "," << Eautunite1p3[0] << ","
      << Eautunite1p3[1] << "," << Eautunite1p3[2] << "," << I_aut_13 << endl;
  outFile.close();
}
