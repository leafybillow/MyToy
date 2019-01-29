void Moller_theta(){

  TF1 *f_prim = new TF1("f_prim","TMath::Sqrt(2*0.511*(1.0/x-1.0/1000))*1000",0,1000);
  f_prim->SetTitle("Moller Scattering: #theta_{lab} vs E' ");
  f_prim->GetYaxis()->SetTitle("#theta_{lab}/mrad");
  f_prim->GetXaxis()->SetTitle("Primary Ekin/ MeV");


  TF1 *f_min = new TF1("f_min","6.875",0,8880);
  f_min->SetLineStyle(2);
  f_min->SetLineColor(4);
  TF1 *f_max = new TF1("f_max","10.625",0,8880);
  f_max->SetLineStyle(2);
  f_max->SetLineColor(4);
  
  //recontruct secondary electron
  // double eprim[880];
  // double theta_sec[880];
  // double e_sec;
  // for(int i=0;i<880;i++){
  //   eprim[i]=i*10;  //MeV
  //   e_sec = 8800 - eprim[i];
  //   if(i==0)
  //     theta_sec[i]=0;
  //   else
  //     theta_sec[i] = eprim[i]/e_sec*f_prim(eprim[i]);
  // }

  // TGraph *g_sec=new TGraph(880,eprim,theta_sec);
  // g_sec->SetLineWidth(2);
  
  f_prim->Draw();
  f_prim->GetYaxis()->SetRangeUser(0,200);
  // f_max->Draw("same");
  // f_min->Draw("same");
  //  g_sec->Draw("same");

  TLegend *leg = new TLegend(0.1,0.9,0.25,0.75);
  leg->AddEntry(f_prim,"Primary","l");
  //  leg->AddEntry(g_sec,"Secondary","l");
  //leg->Draw("same");
}

