void NoiseRMS(){
  
  TRandom *rdngen = new TRandom3(0);
  TH1D *h_strip = new TH1D("h_strip","Simulated Gaussian Noise, #sigma = 48.0",512,-100,100);
  h_strip->Reset();
  for(int i=0;i<512;i++){
    Double_t noise = rdngen->Gaus(0,48.0);
    h_strip->SetBinContent(i+1,noise);
  }
  h_strip->Draw();

}
