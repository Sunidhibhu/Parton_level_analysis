#include <iostream>
#include <fstream>
#include <TLorentzVector.h>
#include <vector>
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TCanvas.h"

struct JetInfo {
    int index;
    float pt;
};

void Delphes_output_1()
{


TH1D *jet1_Pt = new TH1D("jet1_Pt ", "jet1_Pt ", 50, -1, 1500);
TH1D *jet1_Eta = new TH1D("jet1_Eta ", "jet1_Eta ", 30, -5, 5);
TH1D *jet1_Phi = new TH1D("jet1_Phi ", "jet1_Phi ", 50, -4, 4);
TH1D *forward_jet_mass = new TH1D("forward_jet_mass ", "forward_jet_mass ", 50, 0, 200);
TH1D *jet2_Pt = new TH1D("jet2_Pt ", "jet2_Pt ", 50, 0, 200);
TH1D *jet2_Eta = new TH1D("jet2_Eta ", "jet2_Eta ", 30, 5, 5);
TH1D *jet2_Phi = new TH1D("jet2_Phi ", "jet2_Phi ", 50, -4, 4);
TH1D *jet2_mass = new TH1D("jet2_mass ", "jet2_mass ", 50, 0, 200);
TH1D *jet3_Pt = new TH1D("jet3_Pt ", "jet3_Pt ", 50, 0, 300);
TH1D *jet3_Eta = new TH1D("jet3_Eta ", "jet3_Eta ", 30, -5, 5);
TH1D *jet3_Phi = new TH1D("jet3_Phi ", "jet3_Phi ", 50, -4, 4);
TH1D *jet3_mass = new TH1D("jet3_mass ", "jet3_mass ", 50, 0, 300);
TH1D *jet4_Pt = new TH1D("jet4_Pt ", "jet4_Pt ", 50, 0, 300);
TH1D *jet4_Eta = new TH1D("jet4_Eta ", "jet4_Eta ", 30, -5, 5);
TH1D *jet4_Phi = new TH1D("jet4_Phi ", "jet4_Phi ", 50, -4, 4);
TH1D *Genjet1_Pt = new TH1D("Genjet1_Pt ", "Genjet1_Pt ", 50, -1, 1500);
TH1D *Genjet1_Eta = new TH1D("Genjet1_Eta ", "Genjet1_Eta ", 30, -5, 5);
TH1D *Genjet1_Phi = new TH1D("Genjet1_Phi ", "Genjet1_Phi ", 50, -4, 4);
TH1D *Genjet2_Pt = new TH1D("Genjet2_Pt ", "Genjet2_Pt ", 50, 0, 200);
TH1D *Genjet2_Eta = new TH1D("Genjet2_Eta ", "Genjet2_Eta ", 30, 5, 5);
TH1D *Genjet2_Phi = new TH1D("Genjet2_Phi ", "Genjet2_Phi ", 50, -4, 4);
TH1D *Genjet2_mass = new TH1D("Genjet2_mass ", "Genjet2_mass ", 50, 0, 200);
TH1D *Genjet3_Pt = new TH1D("Genjet3_Pt ", "Genjet3_Pt ", 50, 0, 300);
TH1D *Genjet3_Eta = new TH1D("Genjet3_Eta ", "Genjet3_Eta ", 30, -5, 5);
TH1D *Genjet3_Phi = new TH1D("Genjet3_Phi ", "Genjet3_Phi ", 50, -4, 4);
TH1D *Genjet3_mass = new TH1D("Genjet3_mass ", "Genjet3_mass ", 50, 0, 300);
TH1D *Genjet4_Pt = new TH1D("Genjet4_Pt ", "Genjet4_Pt ", 50, 0, 300);
TH1D *Genjet4_Eta = new TH1D("Genjet4_Eta ", "Genjet4_Eta ", 30, -5, 5);
TH1D *Genjet4_Phi = new TH1D("Genjet4_Phi ", "Genjet4_Phi ", 50, -4, 4);
TH1D *electron1_Pt = new TH1D("electron1_Pt ", "electron1_Pt ", 50, 20, 500);
TH1D *electron1_Eta = new TH1D("electron1_Eta ", "electron1_Eta ", 50, -4, 4);
TH1D *electron1_Phi = new TH1D("electron1_Phi ", "electron1_Phi ", 50, -4, 4);
TH1D *electron2_Pt = new TH1D("electron2_Pt ", "electron2_Pt ", 50, 0, 200);
TH1D *electron2_Eta = new TH1D("electron2_Eta ", "electron2_Eta ", 50, -4, 4);
TH1D *electron2_Phi = new TH1D("electron2_Phi ", "electron2_Phi ", 50, -4, 4);
TH1D *electron3_Pt = new TH1D("electron3_Pt ", "electron3_Pt ", 50, 0, 200);
TH1D *electron3_Eta = new TH1D("electron3_Eta ", "electron3_Eta ", 50, -4, 4);
TH1D *electron3_Phi = new TH1D("electron3_Phi ", "electron3_Phi ", 50, -4, 4);
TH1D *btag_mass = new TH1D("btag_mass ", "btag_mass ", 100, 0, 30);
TH1D *btag_Pt = new TH1D("btag_Pt ", "btag_Pt ", 50, 10, 350);
TH1D *btag_Eta = new TH1D("btag_Eta ", "btag_Eta ", 100, -4, 4);
TH1D *btag_Phi = new TH1D("btag_Phi ", "btag_Phi ", 100, -4, 4);
TH1D *top_mass = new TH1D("top_mass ", "top_mass ", 20, 30, 250);
TH1D *W_mass = new TH1D("W_mass ", "W_mass ", 20, 30, 150);
TH1D *Z_mass = new TH1D("Z_mass ", "Z_mass ", 20, 30, 150);
TH1D *Met_met = new TH1D("Met_met  ", "Met_met  ", 50, 0, 700);
TH1D *Met_Eta = new TH1D("Met_Eta ", "Met_Eta ", 50, -8, 6);
TH1D *Met_Phi = new TH1D("Met_Phi ", "Met_Phi ", 40, -5, 5);
TH1D *Met_mass = new TH1D("MET_mass ", "MET_mass ", 40, -5, 5);
TH1D *cutFlowHist = new TH1D("cutFlowHist", "Cut Flow", 10, 0, 200);
TH1D *eventCountHist = new TH1D("eventCountHist", "Event Count", 10, 0, 10);
TH1D *Jet_distribution = new TH1D("Number of jets distribution ", "Number of jets distribution", 30, 0, 20);
TH1D *GenJet_distribution = new TH1D("Number of Genjets distribution ", "Number of Genjets distribution", 30, 0, 20);
TH1D *Jet_Pt = new TH1D("Jet_Pt ", "Jet_Pt ", 50, 0, 200);

TFile *f = new TFile("Detector_level.root");

TTree *Delphes1 = (TTree*)f->Get("Delphes");

// Declaration of leaves type
   Int_t           Jet_size;
   Float_t         Jet_PT[14];
   Float_t         Jet_Eta[14];
   Float_t         Jet_Phi[14];
   Float_t         Jet_Mass[14];
   UInt_t          Jet_BTag[14];
   Int_t           GenJet_size;
   Float_t         GenJet_PT[14];
   Float_t         GenJet_Eta[14];
   Float_t         GenJet_Phi[14];
   Float_t         GenJet_Mass[14];
   Int_t           Electron_size;
   Float_t         Electron_PT[4];
   Float_t         Electron_Eta[4];
   Float_t         Electron_Phi[4];
   Float_t         Electron_T[4];
   Float_t         Particle_Mass[3920];
   Float_t         Particle_PT[3920];
   Int_t           Particle_size;
   Float_t         MissingET_MET[1];
   Float_t         MissingET_Eta[1];
   Float_t         MissingET_Phi[1];
   UInt_t          MissingET_fBits[1];
   Int_t           MissingET_size;
   
// Set branch addresses
   
   
   Delphes1->SetBranchAddress("Jet.PT",Jet_PT);
   Delphes1->SetBranchAddress("Jet.Eta",Jet_Eta);
   Delphes1->SetBranchAddress("Jet.Phi",Jet_Phi);
   Delphes1->SetBranchAddress("Jet_size",&Jet_size);
   Delphes1->SetBranchAddress("Jet.Mass",Jet_Mass);
   Delphes1->SetBranchAddress("Jet.BTag",Jet_BTag);
   Delphes1->SetBranchAddress("GenJet.PT",GenJet_PT);
   Delphes1->SetBranchAddress("GenJet.Eta",GenJet_Eta);
   Delphes1->SetBranchAddress("GenJet.Phi",GenJet_Phi);
   Delphes1->SetBranchAddress("GenJet_size",&GenJet_size);
   Delphes1->SetBranchAddress("GenJet.Mass",GenJet_Mass);
   Delphes1->SetBranchAddress("Electron.PT",Electron_PT);
   Delphes1->SetBranchAddress("Electron.Eta",Electron_Eta);
   Delphes1->SetBranchAddress("Electron.Phi",Electron_Phi);
   Delphes1->SetBranchAddress("Electron_size",&Electron_size);
   Delphes1->SetBranchAddress("Particle.Mass",Particle_Mass);
   Delphes1->SetBranchAddress("Particle.PT",Particle_PT);
   Delphes1->SetBranchAddress("Particle_size",&Particle_size);
   Delphes1->SetBranchAddress("MissingET.MET",MissingET_MET);
   Delphes1->SetBranchAddress("MissingET.Eta",MissingET_Eta);
   Delphes1->SetBranchAddress("MissingET.Phi",MissingET_Phi);
   Delphes1->SetBranchAddress("MissingET_size",&MissingET_size);

 Int_t nentries = (Int_t)Delphes1->GetEntries(); 

/*int totalEvents = 0;
int eventsWithFourJets = 0;
int btagevents = 0;
int eventsWithleptons = 0;
int eventsWithMET = 0;*/

int cutStage = 0;
int eventCount = nentries;
 


 for (Int_t i = 0; i < nentries; i++) {
 // for (Int_t i = 0; i < 10; i++) {
  // totalEvents++; 
  cutStage++;
   cout<< i << "\n" ;
        Delphes1->GetEntry(i);
       // printf("%d\n",Jet_size);
      //hpt1->Fill(Jet_size);  
//----------------------------------------------------------------------------------------------------------------------------------------------------------------





TLorentzVector bTag;



int btag_index = -1;
for (int j = 0; j < Jet_size; j++) {
// cout << Jet_size << "\n" ;  
    
    if (Jet_BTag[j] == 1) {
        bTag.SetPtEtaPhiM(Jet_PT[j], Jet_Eta[j], Jet_Phi[j], Jet_Mass[j]);
        btag_index = j;
    //    btagevents++;
    //btag_mass->Fill(bTag.M());   
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
std::vector<JetInfo> leadingJets;

Jet_distribution->Fill(Jet_size);

for (int j = 0; j < Jet_size; j++) {
  //  if (j != btag_index ) { 
        leadingJets.push_back({j, Jet_PT[j]});
  //  }

Jet_Pt->Fill(Jet_PT[j]);

    
}




//cout<< "No.of jets =" << leadingJets.size() << "\n";   

std::sort(leadingJets.begin(), leadingJets.end(), [](const JetInfo& a, const JetInfo& b) {
    return a.pt > b.pt;
});

    if (!leadingJets.empty()){
    
    jet1_Pt->Fill(Jet_PT[leadingJets[0].index]);
    jet1_Eta->Fill(Jet_Eta[leadingJets[0].index]);
    jet1_Phi->Fill(Jet_Phi[leadingJets[0].index]);  
    }
    if (leadingJets.size() > 1){
    
    jet2_Pt->Fill(Jet_PT[leadingJets[1].index]); 
    jet2_Eta->Fill(Jet_Eta[leadingJets[1].index]);
    jet2_Phi->Fill(Jet_Phi[leadingJets[1].index]);
    }
    
    if (leadingJets.size() > 2){
    jet3_Pt->Fill(Jet_PT[leadingJets[2].index]);
    jet3_Eta->Fill(Jet_Eta[leadingJets[2].index]);
    jet3_Phi->Fill(Jet_Phi[leadingJets[2].index]);
    }
     
    if (leadingJets.size() > 3){
    jet4_Pt->Fill(Jet_PT[leadingJets[3].index]);
    jet4_Eta->Fill(Jet_Eta[leadingJets[3].index]);
    jet4_Phi->Fill(Jet_Phi[leadingJets[3].index]);
    }


    TLorentzVector Jet1;
   if (!leadingJets.empty()) { Jet1.SetPtEtaPhiM(Jet_PT[leadingJets[0].index], Jet_Eta[leadingJets[0].index], Jet_Phi[leadingJets[0].index], Jet_Mass[leadingJets[0].index]);}
  
    




    TLorentzVector Jet2;
    TLorentzVector Jet3;
    TLorentzVector Jet4;

    if (leadingJets.size() > 1) {
        Jet2.SetPtEtaPhiM(Jet_PT[leadingJets[1].index], Jet_Eta[leadingJets[1].index], Jet_Phi[leadingJets[1].index], Jet_Mass[leadingJets[1].index]);}
       
    //   cout<< " jet2 eta =" << Jet_Eta[leadingJets[1].index] << "\n";   
       
       if (leadingJets.size() > 2) {
           Jet3.SetPtEtaPhiM(Jet_PT[leadingJets[2].index], Jet_Eta[leadingJets[2].index], Jet_Phi[leadingJets[2].index], Jet_Mass[leadingJets[2].index]);}

             if (leadingJets.size() > 3) {
                Jet4.SetPtEtaPhiM(Jet_PT[leadingJets[3].index], Jet_Eta[leadingJets[3].index], Jet_Phi[leadingJets[3].index], Jet_Mass[leadingJets[3].index]);}
    
//------------------------------------------------------------------------------------------------------------------------------------------------------------------    
GenJet_distribution->Fill(GenJet_size);
 std::vector<JetInfo> leadingGenJets;

for (int j = 0; j < GenJet_size; j++) {
  //  if (j != btag_index ) { 
        leadingGenJets.push_back({j, GenJet_PT[j]});
  //  }


}

//cout<< "No.of jets =" << leadingJets.size() << "\n";   

std::sort(leadingGenJets.begin(), leadingGenJets.end(), [](const JetInfo& a, const JetInfo& b) {
    return a.pt > b.pt;
});


    TLorentzVector GenJet1;
   if (!leadingGenJets.empty()) { GenJet1.SetPtEtaPhiM(GenJet_PT[leadingGenJets[0].index], GenJet_Eta[leadingGenJets[0].index], GenJet_Phi[leadingGenJets[0].index], GenJet_Mass[leadingGenJets[0].index]);}
  
    




    TLorentzVector GenJet2;
    TLorentzVector GenJet3;
    TLorentzVector GenJet4;

    if (leadingGenJets.size() > 1) {
        GenJet2.SetPtEtaPhiM(GenJet_PT[leadingGenJets[1].index], GenJet_Eta[leadingGenJets[1].index], GenJet_Phi[leadingGenJets[1].index], GenJet_Mass[leadingGenJets[1].index]);}
       
      // cout<< " jet2 eta =" << Jet_Eta[leadingGenJets[1].index] << "\n";   
       
       if (leadingGenJets.size() > 2) {
           GenJet3.SetPtEtaPhiM(GenJet_PT[leadingGenJets[2].index], GenJet_Eta[leadingGenJets[2].index], GenJet_Phi[leadingGenJets[2].index], GenJet_Mass[leadingGenJets[2].index]);}

             if (leadingGenJets.size() > 3) {
                GenJet4.SetPtEtaPhiM(GenJet_PT[leadingGenJets[3].index], GenJet_Eta[leadingGenJets[3].index], GenJet_Phi[leadingGenJets[3].index], GenJet_Mass[leadingGenJets[3].index]);}
    
    

    
   


//------------------------------------------------------------------------------------------------------------------------------------------------------------------
   std::vector<JetInfo> electrons;
   for (int j = 0; j < Electron_size; j++) {
   electrons.push_back({j, Electron_PT[j]});
                                          }
 // cout<< "No.of electrons =" << electrons.size() << "\n";                                       
   std::sort(electrons.begin(), electrons.end(), [](const JetInfo& a, const JetInfo& b) {
    return a.pt > b.pt;
});
     
   TLorentzVector electron1;
     
    if (!electrons.empty() && electrons.size() > 0) { electron1.SetPtEtaPhiM(Electron_PT[electrons[0].index], Electron_Eta[electrons[0].index], Electron_Phi[electrons[0].index], Electron_PT[electrons[0].index]);}  
   
   TLorentzVector electron2;
   
   if (electrons.size() > 1) { electron2.SetPtEtaPhiM(Electron_PT[electrons[1].index], Electron_Eta[electrons[1].index], Electron_Phi[electrons[1].index], Electron_PT[electrons[1].index]);}  
   
   TLorentzVector electron3;
   
   if (electrons.size() > 2) { electron3.SetPtEtaPhiM(Electron_PT[electrons[2].index], Electron_Eta[electrons[2].index], Electron_Phi[electrons[2].index], Electron_PT[electrons[2].index]);}  
                                        
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
   std::vector<JetInfo> Mets;
   for (int j = 0; j < MissingET_size; j++) {
   Mets.push_back({j, MissingET_MET[j]});
                                          }
                                      
   std::sort(Mets.begin(), Mets.end(), [](const JetInfo& a, const JetInfo& b) {
    return a.pt > b.pt;
});
   TLorentzVector Met;
   
  if(!Mets.empty()) {Met.SetPtEtaPhiM(MissingET_MET[Mets[0].index], MissingET_Eta[Mets[0].index], MissingET_Phi[Mets[0].index], MissingET_MET[Mets[0].index] );}
    
        
    
  //  cout<< "No.of neutrinos =" << MissingET_size << "\n"; 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------   
    TLorentzVector top;
    TLorentzVector W_boson;
    TLorentzVector Z_boson;
   
    
    top = bTag + Jet2 + Jet3;
    W_boson = electron1 + Met;
    Z_boson = electron2 + electron3;
    
  //  std::ofstream outputFile("event_counts.txt");
  
/*cout << "Electron cut events in cutFlowHist: " << cutFlowHist->GetBinContent(cutFlowHist->GetXaxis()->FindBin("Electron cut")) << endl;
cout << "MET cut events in cutFlowHist: " << cutFlowHist->GetBinContent(cutFlowHist->GetXaxis()->FindBin("MET cut")) << endl;
cout << "Jet cut events in cutFlowHist: " << cutFlowHist->GetBinContent(cutFlowHist->GetXaxis()->FindBin("Jet cut")) << endl;*/
  
  
   TFile outputFile1 ("outputFile1.C", "recreate"); 
    if(Jet_size == 4 && Electron_size == 3 && MissingET_size == 1) {
    
  //  eventsWithFourJetsAndThreeElectrons++;
  //  electron1_mass->Fill(electron1.M());
  //  electron2_mass->Fill(electron2.M());
  //  electron3_mass->Fill(electron3.M());
  //  MET_mass->Fill(Met.M());
  
    top_mass->Fill(top.M());         
    W_mass->Fill(W_boson.M());
    Z_mass->Fill(Z_boson.M());
    btag_Pt->Fill(bTag.Pt());
    btag_Eta->Fill(bTag.Eta());
    btag_Phi->Fill(bTag.Phi()); 
    
    electron1_Pt->Fill(electron1.Pt());
    electron1_Eta->Fill(electron1.Eta());
    electron1_Phi->Fill(electron1.Phi());
    electron2_Pt->Fill(electron2.Pt());
    electron2_Eta->Fill(electron2.Eta());
    electron2_Phi->Fill(electron2.Phi());
    electron3_Pt->Fill(electron3.Pt());
    electron3_Eta->Fill(electron3.Eta());
    electron3_Phi->Fill(electron3.Phi());
    Met_met->Fill(Met.E());
    Met_Eta->Fill(Met.Eta());
    Met_Phi->Fill(Met.Phi());
      
   
    
     
    
     top_mass->Write();         
    W_mass->Write();
    Z_mass->Write();
    btag_Pt->Write();
    btag_Eta->Write();
    btag_Phi->Write(); 
     
    electron1_Pt->Write();
    electron1_Eta->Write();
    electron1_Phi->Write();
    electron2_Pt->Write();
    electron2_Eta->Write();
    electron2_Phi->Write();
    electron3_Pt->Write();
    electron3_Eta->Write();
    electron3_Phi->Write();
    Met_met->Write();
    Met_Eta->Write();
    Met_Phi->Write();
    cutFlowHist->Write();
    
    
    
     
/*    double norm = (0.003741E-06*1000*200);   //Integrated luminosity = 200 fb-1 ;
    
     
    top_mass->Scale(norm);         
    W_mass->Scale(norm);  
    Z_mass->Scale(norm ) ; 
    btag_Pt->Scale(norm );  
    btag_Eta->Scale(norm );  
    btag_Phi->Scale(norm ) ; 
    forward_jet_Pt->Scale(norm ) ; 
    forward_jet_Eta->Scale(norm );  
    forward_jet_Phi->Scale(norm )  ; 
    jet2_Pt->Scale(norm )  ;
    jet2_Eta->Scale(norm ) ; 
    jet2_Phi->Scale(norm )  ;
    jet3_Pt->Scale(norm )  ;
    jet3_Eta->Scale(norm ) ; 
    jet3_Phi->Scale(norm )  ;
    electron1_Pt->Scale(norm ) ; 
    electron1_Eta->Scale(norm ) ; 
    electron1_Phi->Scale(norm )  ;
    electron2_Pt->Scale(norm )  ;
    electron2_Eta->Scale(norm ) ; 
    electron2_Phi->Scale(norm )  ;
    electron3_Pt->Scale(norm )  ;
    electron3_Eta->Scale(norm ) ; 
    electron3_Phi->Scale(norm )  ;
    Met_met->Scale(norm )  ;
    Met_Eta->Scale(norm )  ;
    Met_Phi->Scale(norm )   ;
      */
     }

   /* jet1_Pt->Fill(Jet1.Pt());
    jet1_Eta->Fill(Jet1.Eta());
    jet1_Phi->Fill(Jet1.Phi()); 
    jet2_Pt->Fill(Jet2.Pt()); 
    jet2_Eta->Fill(Jet2.Eta());
    jet2_Phi->Fill(Jet2.Phi());
    jet3_Pt->Fill(Jet3.Pt());
    jet3_Eta->Fill(Jet3.Eta());
    jet3_Phi->Fill(Jet3.Phi()); 
    jet4_Pt->Fill(Jet4.Pt());
    jet4_Eta->Fill(Jet4.Eta());
    jet4_Phi->Fill(Jet4.Phi()); */
    Genjet1_Pt->Fill(GenJet1.Pt());
    Genjet1_Eta->Fill(GenJet1.Eta());
    Genjet1_Phi->Fill(GenJet1.Phi()); 
    Genjet2_Pt->Fill(GenJet2.Pt()); 
    Genjet2_Eta->Fill(GenJet2.Eta());
    Genjet2_Phi->Fill(GenJet2.Phi());
    Genjet3_Pt->Fill(GenJet3.Pt());
    Genjet3_Eta->Fill(GenJet3.Eta());
    Genjet3_Phi->Fill(GenJet3.Phi()); 
    Genjet4_Pt->Fill(GenJet4.Pt());
    Genjet4_Eta->Fill(GenJet4.Eta());
    Genjet4_Phi->Fill(GenJet4.Phi()); 
    
    
    jet1_Pt->Write();
    jet1_Eta->Write();
    jet1_Phi->Write(); 
    jet2_Pt->Write(); 
    jet2_Eta->Write();
    jet2_Phi->Write();
    jet3_Pt->Write();
    jet3_Eta->Write();
    jet3_Phi->Write();
    jet4_Pt->Write();
    jet4_Eta->Write();
    jet4_Phi->Write(); 
    Jet_distribution->Write();
    Genjet1_Pt->Write();
    Genjet1_Eta->Write();
    Genjet1_Phi->Write(); 
    Genjet2_Pt->Write(); 
    Genjet2_Eta->Write();
    Genjet2_Phi->Write();
    Genjet3_Pt->Write();
    Genjet3_Eta->Write();
    Genjet3_Phi->Write();
    Genjet4_Pt->Write();
    Genjet4_Eta->Write();
    Genjet4_Phi->Write(); 
    GenJet_distribution->Write();
    Jet_Pt->Write();
    
    
    outputFile1.Close();
    
    
    
 eventCount--;
 eventCountHist->Fill(cutStage, eventCount);
 
  if(Electron_size == 3){
  
      cutFlowHist->Fill("Electron cut", ++cutStage);
      
      cout << "Events remaining after electron cut: " << eventCount << endl;
  
         if(electron1.Pt() > 20 && electron2.Pt() > 20 && electron3.Pt() > 20 ){
  
             cutFlowHist->Fill("Electron_Pt_cut", ++cutStage);
             cout << "Events remaining after electron pt cut: " << eventCount << endl;
               if(electron1.Eta() < 2.5 && electron2.Eta() < 2.5 && electron3.Eta() < 2.5){
  
                 cutFlowHist->Fill("Electron_Eta_cut", ++cutStage);
                 cout << "Events remaining after electron eta cut: " << eventCount << endl;
                    if(MissingET_size == 1 ) {
 
                      cutFlowHist->Fill("MET cut", ++cutStage);
                      cout << "Events remaining after MET cut: " << eventCount << endl;
                        if(Met.Pt() > 25){
 
                           cutFlowHist->Fill("Met_Pt_cut", ++cutStage);
                           cout << "Events remaining after MET pt cut: " << eventCount << endl;
                           if(Jet_size == 4 ) {

                             cutFlowHist->Fill("Jet cut", ++cutStage );
                             cout << "Events remaining after Jet cut: " << eventCount << endl;         
                               
                           //    cout << "Jet_size: " << Jet_size << ", Jet_BTag[0]: " << Jet_BTag[0] << endl;
                                                                 
                                 if(Jet1.Pt() >25 && Jet2.Pt() > 25 && Jet3.Pt() > 25){
 
                                   cutFlowHist->Fill("Jet_Pt_cut", ++cutStage);
                                   cout << "Events remaining after Jet pt cut: " << eventCount << endl;
                                   if(Jet1.Eta() > 2.5  ){
 
                                     cutFlowHist->Fill("forwardjet_Eta_cut", ++cutStage);
                                     cout << "Events remaining after forward jet cut: " << eventCount << endl;
                                        for (int j = 0; j < Jet_size ==1 ; j++) {
                                             if (Jet_BTag[j] == 1){
                                                       cutFlowHist->Fill("bTag_jet", ++cutStage);                                           
                                                                cout << "Events remaining after forward jet cut: " << eventCount << endl;                                                                                                                  }                                           
                                                                                                                     }
  
                                                                                                                   }
  
                                                                                                                 }
                                                                                                                 
                                                                                                            }
  
                                                                                                        }
  
                                                                                                     }
  
                                                                                                 }
  
                                                                                              }
  
                                                                                          }
                                                                                          
                                                                                       
  
  //  cutFlowHist->Fill("All cuts passed", 1);

/*outputFile << "Total Events: " << totalEvents << std::endl;
outputFile << "Events with 4 Jets and 3 Electrons: " << eventsWithFourJetsAndThreeElectrons << std::endl;

outputFile.close();*/


/*cout << "Total Events: " << totalEvents << endl;
cout << "Events with 3 leptons: " << eventsWithleptons << endl;
cout << "Events with 1 MET: " << eventsWithMET<< endl;
cout << "Events with 4 Jets: " << eventsWithFourJets << endl;
cout << "btag events: " << btagevents << endl; */


}


TCanvas *c1 = new TCanvas();

top_mass ->Draw();
c1->SaveAs("top_mass.png");


TCanvas *c2 = new TCanvas();

W_mass ->Draw();
c2->SaveAs("W_mass.png");

TCanvas *c3 = new TCanvas();

Z_mass ->Draw();
c3->SaveAs("Z_mass.png");

TCanvas *c4 = new TCanvas();

electron1_Pt ->Draw();
c4->SaveAs("electron1_Pt.png");


TCanvas *c5 = new TCanvas();

electron1_Eta ->Draw();
c5->SaveAs("electron1_Eta.png");

TCanvas *c6 = new TCanvas();

electron1_Phi ->Draw();
c6->SaveAs("electron1_Phi.png");

TCanvas *c7 = new TCanvas();

Met_met ->Draw();
c7->SaveAs("Met_met.png");

TCanvas *c8 = new TCanvas();

btag_Pt ->Draw();
c8->SaveAs("btag_Pt.png");

TCanvas *c9 = new TCanvas();

btag_Eta ->Draw();
c9->SaveAs("btag_Eta.png");

TCanvas *c10 = new TCanvas();

btag_Phi ->Draw();
c10->SaveAs("btag_Phi.png");

TCanvas *c11 = new TCanvas();

jet1_Pt ->Draw();
c11->SaveAs("jet1_Pt.png");

TCanvas *c12 = new TCanvas();

jet1_Eta ->Draw();
c12->SaveAs("jet1_Eta.png");

TCanvas *c13 = new TCanvas();

jet1_Phi ->Draw();
c13->SaveAs("jet1_Phi.png");

TCanvas *c14 = new TCanvas();

jet2_Pt ->Draw();
c14->SaveAs("jet2_Pt.png");

TCanvas *c15 = new TCanvas();

jet2_Eta ->Draw();
c15->SaveAs("jet2_Eta.png");

TCanvas *c16 = new TCanvas();

jet2_Phi ->Draw();
c16->SaveAs("jet2_Phi.png");

TCanvas *c17 = new TCanvas();

jet3_Pt ->Draw();
c17->SaveAs("jet3_Pt.png");

TCanvas *c18 = new TCanvas();

jet3_Eta ->Draw();
c18->SaveAs("jet3_Eta.png");

TCanvas *c19 = new TCanvas();

jet3_Phi ->Draw();
c19->SaveAs("jet3_Phi.png");

TCanvas *c20 = new TCanvas();

electron2_Pt ->Draw();
c20->SaveAs("electron2_Pt.png");


TCanvas *c21 = new TCanvas();

electron2_Eta ->Draw();
c21->SaveAs("electron2_Eta.png");

TCanvas *c22 = new TCanvas();

electron2_Phi ->Draw();
c22->SaveAs("electron2_Phi.png");

TCanvas *c23 = new TCanvas();

electron3_Pt ->Draw();
c20->SaveAs("electron3_Pt.png");


TCanvas *c24 = new TCanvas();

electron3_Eta ->Draw();
c24->SaveAs("electron3_Eta.png");

TCanvas *c25 = new TCanvas();

electron3_Phi ->Draw();
c25->SaveAs("electron3_Phi.png");

TCanvas *c26 = new TCanvas();

Met_Eta ->Draw();
c26->SaveAs("Met_Eta.png");

TCanvas *c27 = new TCanvas();

Met_Phi ->Draw();
c27->SaveAs("Met_Phi.png");

TCanvas *c28 = new TCanvas();

Jet_distribution ->Draw();
c28->SaveAs("Jet_distribution.png");

TCanvas *c29 = new TCanvas();

jet4_Pt ->Draw();
c29->SaveAs("jet4_Pt.png");

TCanvas *c30 = new TCanvas();

jet4_Eta ->Draw();
c30->SaveAs("jet4_Eta.png");

TCanvas *c31 = new TCanvas();

jet4_Phi ->Draw();
c31->SaveAs("jet4_Phi.png");

TCanvas *c32 = new TCanvas();

Genjet1_Pt ->Draw();
c32->SaveAs("Genjet1_Pt.png");

TCanvas *c33 = new TCanvas();

Genjet1_Eta ->Draw();
c33->SaveAs("Genjet1_Eta.png");

TCanvas *c34 = new TCanvas();

Genjet1_Phi ->Draw();
c34->SaveAs("Genjet1_Phi.png");

TCanvas *c35 = new TCanvas();

Genjet2_Pt ->Draw();
c35->SaveAs("Genjet2_Pt.png");

TCanvas *c36 = new TCanvas();

Genjet2_Eta ->Draw();
c36->SaveAs("Genjet2_Eta.png");

TCanvas *c37 = new TCanvas();

Genjet2_Phi ->Draw();
c37->SaveAs("Genjet2_Phi.png");

TCanvas *c38 = new TCanvas();

Genjet3_Pt ->Draw();
c38->SaveAs("Genjet3_Pt.png");

TCanvas *c39 = new TCanvas();

Genjet3_Eta ->Draw();
c39->SaveAs("Genjet3_Eta.png");

TCanvas *c40 = new TCanvas();

Genjet3_Phi ->Draw();
c40->SaveAs("Genjet3_Phi.png");

TCanvas *c41 = new TCanvas();

GenJet_distribution ->Draw();
c41->SaveAs("GenJet_distribution.png");

TCanvas *c42 = new TCanvas();

Genjet4_Pt ->Draw();
c42->SaveAs("Genjet4_Pt.png");

TCanvas *c43 = new TCanvas();

Genjet4_Eta ->Draw();
c43->SaveAs("Genjet4_Eta.png");

TCanvas *c44 = new TCanvas();

Genjet4_Phi ->Draw();
c44->SaveAs("Genjet4_Phi.png");


TCanvas *c45 = new TCanvas();

Jet_Pt ->Draw();
c45->SaveAs("Jet_Pt.png");




TCanvas *cutFlowCanvas = new TCanvas();


cutFlowCanvas->SetLogy();
cutFlowHist->Draw("hist");

for (int i = 1; i <= cutFlowHist->GetNbinsX(); ++i) {
    TString label = cutFlowHist->GetXaxis()->GetBinLabel(i);
    double binContent = cutFlowHist->GetBinContent(i);

    // Add the number of events as text at the top of each bin
     if (i == 1 || eventCountHist->GetBinContent(i) != eventCountHist->GetBinContent(i - 1)) {
    TText *text = new TText(i, binContent, Form("%.0f events", eventCountHist->GetBinContent(i)));
    text->SetTextAlign(22); // Centered
    text->SetTextSize(0.03);
    cutFlowCanvas->cd()->Update();
    text->Draw();
}


}
cutFlowCanvas->SaveAs("cutFlow_log.png");



f->Close();

}





























