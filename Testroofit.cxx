#include <RooRealVar.h>
#include <RooAbsReal.h>
#include <RooAbsPdf.h>
#include <RooRealIntegral.h>
#include <RooArgSet.h>
#include <RooAddPdf.h>
#include <RooFFTConvPdf.h>

#include <TH1.h>
#include <TFile.h>
#include <TCanvas.h>

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


using namespace std;

int main()
{
    //Define objects needed
    TFile * f = new TFile("spe.root","recreate");
    TH1D * Fe = new TH1D("Fe","Fe",512,0.5,512.5);
    TH1D * NaX = new TH1D("NaX","NaX",512,0.5,512.5);
    //Read in data
    ifstream fin("Exp_1/Fe.Asc",ios::in);
    double test_a;
    int test_b;
    for(int i = 0 ; i < 512 ; i++)
    {
        fin >> test_a;
        fin >> test_b;
        Fe->SetBinContent((int)test_a+1,(int)test_b);
    }
    fin.close();
    fin.open("Exp_1/NAX.Asc",ios::in);
    for(int i = 0 ; i < 512 ; i++)
    {
        fin >> test_a;
        fin >> test_b;
        cout<<test_a<<test_b<<endl;
        NaX->SetBinContent((int)test_a+1,(int)test_b);
    }
    Fe->Write();
    NaX->Write();
    //fit setup


    return 0;
}

void Testroofit()
{
    main();
}
