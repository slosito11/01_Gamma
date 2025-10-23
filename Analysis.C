//basic commands
#include <iostream>
#include <map>

//our predefinded thinghies
#include "get_hist.hh"

//getting all the raw data by channel
//TH1D *h_autunite_0 = getHistoFromTree("./data/Autunite/RAW/DataR_Autunite.root",
//                                      17300, 0, 17300, 0);
//TH1D *h_autunite_1 = getHistoFromTree("./data/Autunite/RAW/DataR_Autunite.root",
//                                      17300, 0, 17300, 1);
//TH1D *h_abano_0 = getHistoFromTree(
//    "./data/Abano_terme/RAW/DataR_Abano_terme.root", 17300, 0, 17300, 0);
//TH1D *h_abano_1 = getHistoFromTree(
//    "./data/Abano_terme/RAW/DataR_Abano_terme.root", 17300, 0, 17300, 1);
//TH1D *h_americio_0 = getHistoFromTree("./data/Americio/RAW/DataR_Americio.root",
//                                      17300, 0, 17300, 0);
//TH1D *h_americio_1 = getHistoFromTree("./data/Americio/RAW/DataR_Americio.root",
//                                      17300, 0, 17300, 1);
//TH1D *h_cal_can_0 = getHistoFromTree(
//    "./data/Calibrated_Canister/RAW/DataR_Calibrated_Canister.root", 17300, 0,
//    17300, 0);
//TH1D *h_cal_can_1 = getHistoFromTree(
//    "./data/Calibrated_Canister/RAW/DataR_Calibrated_Canister.root", 17300, 0,
//    17300, 1);
//TH1D *h_caricatore_0 =
//    getHistoFromTree("./data/Caricatore_cell/RAW/DataR_Caricatore_cell.root",
//                     17300, 0, 17300, 0);
//TH1D *h_caricatore_1 =
//    getHistoFromTree("./data/Caricatore_cell/RAW/DataR_Caricatore_cell.root",
//                     17300, 0, 17300, 1);
//TH1D *h_cobalto_0 = getHistoFromTree("./data/Cobalto/RAW/DataR_Cobalto.root",
//                                     17300, 0, 17300, 0);
//TH1D *h_cobalto_1 = getHistoFromTree("./data/Cobalto/RAW/DataR_Cobalto.root",
//                                     17300, 0, 17300, 1);
//TH1D *h_europio_0 = getHistoFromTree("./data/Europio/RAW/DataR_Europio.root",
//                                     17300, 0, 17300, 0);
//TH1D *h_europio_1 = getHistoFromTree("./data/Europio/RAW/DataR_Europio.root",
//                                     17300, 0, 17300, 1);
//TH1D *h_exp_can_0 =
//    getHistoFromTree("./data/Exposed_Canister/RAW/DataR_Exposed_Canister.root",
//                     17300, 0, 17300, 0);
//TH1D *h_exp_can_1 =
//    getHistoFromTree("./data/Exposed_Canister/RAW/DataR_Exposed_Canister.root",
//                     17300, 0, 17300, 1);
//TH1D *h_legno_0 = getHistoFromTree(
//    "./data/Legno_Mada/RAW/DataR_Legno_Mada.root", 17300, 0, 17300, 0);
//TH1D *h_legno_1 = getHistoFromTree(
//    "./data/Legno_Mada/RAW/DataR_Legno_Mada.root", 17300, 0, 17300, 1);
//TH1D *h_nexp_can_0 = getHistoFromTree(
//    "./data/Not_Exposed_Canister/RAW/DataR_Not_Exposed_Canister.root", 17300, 0,
//    17300, 0);
//TH1D *h_nexp_can_1 = getHistoFromTree(
//    "./data/Not_Exposed_Canister/RAW/DataR_Not_Exposed_Canister.root", 17300, 0,
//    17300, 1);
//TH1D *h_porcini_0 = getHistoFromTree("./data/Porcini/RAW/DataR_Porcini.root",
//                                     17300, 0, 17300, 0);
//TH1D *h_porcini_1 = getHistoFromTree("./data/Porcini/RAW/DataR_Porcini.root",
//                                     17300, 0, 17300, 1);
TH1D *h_sodio_0 =
    getHistoFromTree("./data/Sodio/RAW/DataR_Sodio.root", 17300, 0, 17300, 0);
TH1D *h_sodio_1 =
    getHistoFromTree("./data/Sodio/RAW/DataR_Sodio.root", 17300, 0, 17300, 0);
TH1D *ch_sodio_0 =
    getCleanHistoFromTree("./data/Sodio/RAW/DataR_Sodio.root", 17300, 0, 17300, 0);
TH1D *ch_sodio_1 =
    getCleanHistoFromTree("./data/Sodio/RAW/DataR_Sodio.root", 17300, 0, 17300, 0);

TCanvas *c1 = new TCanvas("No background");
ch_sodio_1->Draw();
