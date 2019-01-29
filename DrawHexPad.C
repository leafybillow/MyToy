double radius = 0.025;
double offset = 2*radius*TMath::Cos(TMath::Pi()/6.0);
double x_start = 0.9;
double y_start = 0.05;
#include "Maps.h"

void DrawHexPad(){

  int color[4]={11,5,6,7};
  TCanvas *c_hex = new TCanvas("c_hex","c_hex",800,800);
  c_hex->cd();
  
  int col;
  int row;
  int myID;

  for(int ichannel =0; ichannel<128;ichannel++){
    myID = J1_map[ichannel];
    col = GetCol(myID);
    row = GetRow(myID);
    DrawHex(PassXCtr(col,row),PassYCtr(row),color[0]);
    PrintChannel(ichannel,PassXCtr(col,row),PassYCtr(row));
  }

  for(int ichannel =0; ichannel<128;ichannel++){
    myID = J2_map[ichannel];
    col = GetCol(myID);
    row = GetRow(myID);
    DrawHex(PassXCtr(col,row),PassYCtr(row),color[1]);
    PrintChannel(ichannel,PassXCtr(col,row),PassYCtr(row));
  }
  

  for(int ichannel =0; ichannel<128;ichannel++){
    myID = J3_map[ichannel];
    col = GetCol(myID);
    row = GetRow(myID);
    DrawHex(PassXCtr(col,row),PassYCtr(row),color[2]);
    PrintChannel(ichannel,PassXCtr(col,row),PassYCtr(row));
  }
    
  for(int ichannel =0; ichannel<128;ichannel++){
    myID = J4_map[ichannel];
    col = GetCol(myID);
    row = GetRow(myID);
    DrawHex(PassXCtr(col,row),PassYCtr(row),color[3]);
    PrintChannel(ichannel,PassXCtr(col,row),PassYCtr(row));
  }
}

void DrawHex(double xcenter, double ycenter, int color){
  
  double pi = TMath::Pi();
  double phi = pi/3;
  
  double xpos[7] = {xcenter+radius*TMath::Sin(phi)};
  double ypos[7] = {ycenter+radius*TMath::Cos(phi)};

  for(int i =1; i<=6;i++){
    phi = phi + (pi/3);
    xpos[i] = xcenter + radius*TMath::Sin(phi);
    ypos[i] = ycenter + radius*TMath::Cos(phi);
  }
  
  TPolyLine *hex = new TPolyLine(7,xpos,ypos);
  hex->SetFillColor(color);
  hex->Draw("f");
  hex->Draw();
  
}

void PrintChannel(int ichannel, double x, double y){
  TText *text = new TText(x-0.015,y-0.01,Form("%d",ichannel));
  text->SetNDC(0);
  text->SetTextSize(0.02);
  text->Draw();
}

double PassYCtr(int row){ //col start from 0 ,start from bottom
  return y_start+row*(radius*3.0/2.0);
}

double PassXCtr(int col, int row){ //col, row start from 0, start from right
  if (row%2==0)
    return x_start-col*offset;
  else
    return x_start + offset/2 - col*offset;
}

int nrow( int col){
  if (col%2 ==0)
    return 20;
  else
    return 21;
}

int GetRow(int myID){

  if (myID%41<20)
    return (myID/41)*2;
  else
    return (myID/41)*2+1;
}

int GetCol(int myID){
  if(myID%41<20)
    return myID%41;
  else
    return myID%41-20;
}
