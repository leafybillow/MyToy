void PlotLabel(){

   const char *month[12]  = {"January","February","March","April","May",
      "June","July","August","September","October","November",
			     "December"};

   TH1D *h1 = new TH1D("h1","h1",12,0,12);

   for(int i=0;i<12;i++){
     h1->Fill(month[i],i+1);
   }
   // h1->LabelsOption("h"); // horizontal label
   // h1->LabelsOption("v"); // vertical label
   // h1->LabelsOption("u"); // draw label up
   // h1->LabelsOption("d"); // draw label down
   h1->Draw();
   
}
