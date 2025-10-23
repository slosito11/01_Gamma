
// Digitizer data from the LAB

struct slimport_data_t {
  UShort_t Channel;
  ULong64_t Timestamp;
  UShort_t Board;
  UShort_t Energy;
  // UShort_t   EnergyShort;
  UInt_t Flags;
};

TH1D *getHistoFromTree(const char *name_file, int numBins, double minX,
                       double maxX, int channel) {
  // variables
  slimport_data_t indata;
  TFile *infile = new TFile(name_file);
  TTree *intree = (TTree *)infile->Get("Data_R");
  // TBranch *inbranch = intree->GetBranch("Channel_0");
  intree->SetBranchAddress("Energy", &indata.Energy);
  intree->SetBranchAddress("Channel", &indata.Channel);
  TH1D *h_spectrum =
      new TH1D("h_spectrum", "Total spectrum", numBins, minX, maxX);
  // histogram filling
  for (int i = 0; i < intree->GetEntries(); i++) {
    intree->GetEntry(i);
    if (indata.Channel == channel) {
      h_spectrum->Fill(indata.Energy * 2. + 100.);
    }
  }
  // return
  return h_spectrum;
}


// get the backgrounds
TH1D *h_back1_0 = getHistoFromTree(
    "./data/background_1/RAW/DataR_background_1.root", 17300, 0, 17300, 0);
TH1D *h_back1_1 = getHistoFromTree(
    "./data/background_1/RAW/DataR_background_1.root", 17300, 0, 17300, 1);
TH1D *h_back2_0 = getHistoFromTree(
    "./data/background_2/RAW/DataR_background_2.root", 17300, 0, 17300, 0);
TH1D *h_back2_1 = getHistoFromTree(
    "./data/background_2/RAW/DataR_background_2.root", 17300, 0, 17300, 1);

// avreage of backgrounds of channel 0
TH1D *h_back_0 = (TH1D *)h_back1_0->Clone("h_back_0");
h_back_0->Reset();
h_back_0->Add(h_back1_0, h_back2_0, 0.5, 0.5);

// avreage of backgrounds of channel 1
TH1D *h_back_1 = (TH1D *)h_back1_1->Clone("h_back_1");
h_back_1->Reset();
h_back_1->Add(h_back1_1, h_back2_1, 0.5, 0.5);

TH1D* getCleanHistoFromTree(const char *name_file, int numBins, double minX,
                       double maxX, int channel) {
  // get hist
  TH1D *h_spectrum = getHistoFromTree(name_file, numBins, minX, maxX, channel);
  // subtract channel background
  if (channel == 0) {

    h_spectrum->Add(h_back_0, -1);
  }
  else if (channel == 1) {
    h_spectrum->Add(h_back_1, -1);
  }
  //changing title
  h_spectrum->SetTitle("Cleaned spectrum");
  //return subtracted background
  return h_spectrum;
}

