
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

TH1D *getCleanHistoFromTree(const char *name_file, int numBins, double minX,
                            double maxX, int channel) {
  // get hist
  TH1D *h_spectrum = getHistoFromTree(name_file, numBins, minX, maxX, channel);
  // subtract channel background
  if (channel == 0) {
    // avreage of backgrounds of channel 0
    TH1D *h_back1_0 =
        getHistoFromTree("./data/background_1/RAW/DataR_background_1.root",
                         numBins, minX, maxX, 0);
    TH1D *h_back2_0 =
        getHistoFromTree("./data/background_2/RAW/DataR_background_2.root",
                         numBins, minX, maxX, 0);
    TH1D *h_back_0 = (TH1D *)h_back1_0->Clone("h_back_0");
    h_back_0->Reset();
    h_back_0->Add(h_back1_0, h_back2_0, 0.5, 0.5);
    h_spectrum->Add(h_back_0, -1);
  } else if (channel == 1) {
    // avreage of backgrounds of channel 1
    TH1D *h_back1_1 =
        getHistoFromTree("./data/background_1/RAW/DataR_background_1.root",
                         numBins, minX, maxX, 1);
    TH1D *h_back2_1 =
        getHistoFromTree("./data/background_2/RAW/DataR_background_2.root",
                         numBins, minX, maxX, 1);
    TH1D *h_back_1 = (TH1D *)h_back1_1->Clone("h_back_1");
    h_back_1->Reset();
    h_back_1->Add(h_back1_1, h_back2_1, 0.5, 0.5);
    h_spectrum->Add(h_back_1, -1);
  }
  // changing title
  h_spectrum->SetTitle("Cleaned spectrum");
  // h_spectrum->Sumw2();
  // return subtracted background
  return h_spectrum;
}
void CalibrateHisto(TH1D *h_uncal, float m, float q) { //Re-scaling of axis, as in the slides

	int max_bin = h_uncal->GetNbinsX(); // This method returns the number of bins in x of the histogram
	float max_kev = h_uncal->GetBinCenter(max_bin)*m + q;
	h_uncal->GetXaxis()->SetLimits(q,max_kev);
	if (m!=1 && q!=0) //This means that I actually changed the calibration!
	    h_uncal->SetXTitle("keV");

}
/*
void gaussian_fit(char *name_file, int numBins, double minX, double maxX, int channel) {

	// Canvas
	TCanvas *c[3];
	for (int i=0; i<3; i++)
	   c[i] = new TCanvas(Form("c%i",i));

	// Get a histo with gaussian peaks
	TH1D *h_na = getCleanHistoFromTree(name_file, numBins, minX, maxX, channel);
	c[0]->cd();
	h_na->Draw();
	
	// Get the two peaks of Na
	TSpectrum *s = new TSpectrum(30);
	int nPeaks;
	double *xPeaks;
	nPeaks = s->Search(h_na,1,"goff",0.12);
	xPeaks = s->GetPositionX();

	
	// I fit the two peaks with a Gaussian to get better values of centroids and sigmas

	int npoints;
	TH1F *h_fitted[0];
	float left_mk, right_mk, x_fit_min, x_fit_max, chisqr, mean, sigma;
	//int apertura_sx = 250; // arbitrary values. Per un calcolo raffinato si può fare un secondo
	//int apertura_dx = 450; // fit dove questi valori corrispondono alle sigma del primo fit...
	h_fitted[0] = (TH1F*)h_na->Clone(); // Clone on a new TH1F to show separately the fits
	x_fit_min = xPeaks[0] - left_mk; // fit left margin
	x_fit_max = xPeaks[0] + right_mk; // fit right margin
	// fit function
	TF1 *fit = new TF1("fit","gaus",x_fit_min,x_fit_max);
	fit->SetParameters(1,xPeaks[0]); // Fix the centroid from the already known x
	fit->SetNpx(1000); // Number of points to define the function
	// fit
	h_fitted[0]->Fit("fit","","",x_fit_min,x_fit_max);
	npoints = (fit->GetNumberFitPoints())-3;
	if (npoints>0) 
	    chisqr = fit->GetChisquare()/npoints;
	else
	    chisqr = 9999;
//	const = fit->GetParameter(0);
	mean = fit->GetParameter(1);
	sigma = fit->GetParameter(2);
	// Results
	cout << "Fit the peak n." << 1 << ": with TSpectrum x = " << xPeaks[0] << endl;
	cout << "                    with the fit    x = " << mean << " and sigma = " << sigma << endl;
	fit->Delete();
	
	// http://root.cern.ch/viewvc/trunk/tutorials/fit/multifit.C?view=markup

}*/
