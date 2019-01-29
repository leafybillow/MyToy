void ColorTest(){
  TMultiGraph *mg = new TMultiGraph();

  int red_phase = 33;
  int blue_phase = 66+17;
  int green_phase = 0;
  TGraph *g_colorband[100];
  TColor *band_color[100];
  double x[100];
  double y[100];
  for(int i=0;i<100;i++){
    x[i] =  i;
    y[i] = -0.3;
    band_color[i] = new TColor(2001+i,get_rgb(i,red_phase),get_rgb(i,green_phase),get_rgb(i,blue_phase));
    g_colorband[i] = new TGraph(1,&x[i],&y[i]);
    g_colorband[i]->SetMarkerStyle(21);
    g_colorband[i]->SetMarkerColor(2001+i);
    g_colorband[i]->SetMarkerSize(4);
    mg->Add(g_colorband[i],"p");
  }



  double red[100];
  double green[100];
  double blue[100];
  double x[100];

  for(int i=0;i<100;i++){
    x[100] = i;
    red[i] =get_rgb(i,red_phase);
    green[i] = get_rgb(i,green_phase);
    blue[i] = get_rgb(i,blue_phase);
  }

  TGraph *g_red =new TGraph(100,x,red);
  TGraph *g_green = new TGraph(100,x,green) ;
  TGraph *g_blue = new TGraph(100,x,blue);
  
  g_red->SetLineColor(2);
  g_red->SetLineWidth(3);
  g_blue->SetLineColor(4);
  g_blue->SetLineWidth(3);
  g_green->SetLineColor(3);
  g_green->SetLineWidth(3);

  mg->Add(g_red,"l");
  mg->Add(g_green,"l");
  mg->Add(g_blue,"l");

  mg->Draw("A");
}


double get_rgb(int i, double phase){

  // double rgb = ((i - phase)/50.0);
  // if(rgb>1)
  //   rgb = 2-rgb;
  // if(rgb<0)
  //   rgb = 0.0;

  // double rgb;
  // double x = (i-phase)/100;
  // rgb = -0.5*TMath::Cos(x*2*TMath::Pi())+0.5;

  double base = 0;
  double top = 1;
  double x = (i-phase+30)/130;
  // if(x<0)
  //   x = ceil(x) -x;
  // if(x>0)
    x = x-floor(x);
  
  double rgb;
  if(x>=0 && x<1.0/3)
    rgb = base;
  if(x>=1.0/3 && x<1.0/2)
    rgb = base+ (top-base)*6*(x-1.0/3) ;
  if(x>=1.0/2 && x<5.0/6)
    rgb = top;
  if(x>=5.0/6 && x<=1.0)
    rgb =top -(top-base)*6*(x-5.0/6);
  
  return rgb;


  
}
