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

void Delphes_output_generate()
{


TH1D *jet1_Pt = new TH1D("jet1_Pt ", "jet1_Pt ", 50, -1, 600);
TH1D *jet1_Eta = new TH1D("jet1_Eta ", "jet1_Eta ", 30, -6, 6);
TH1D *jet1_Phi = new TH1D("jet1_Phi ", "jet1_Phi ", 50, -4, 4);
TH1D *forward_jet_mass = new TH1D("forward_jet_mass ", "forward_jet_mass ", 50, 0, 200);
TH1D *jet2_Pt = new TH1D("jet2_Pt ", "jet2_Pt ", 50, 0, 400);
TH1D *jet2_Eta = new TH1D("jet2_Eta ", "jet2_Eta ", 30, -4, 4);
TH1D *jet2_Phi = new TH1D("jet2_Phi ", "jet2_Phi ", 50, -4, 4);
TH1D *jet2_mass = new TH1D("jet2_mass ", "jet2_mass ", 50, 0, 200);
TH1D *jet3_Pt = new TH1D("jet3_Pt ", "jet3_Pt ", 50, 0, 400);
TH1D *jet3_Eta = new TH1D("jet3_Eta ", "jet3_Eta ", 30, -4, 4);
TH1D *jet3_Phi = new TH1D("jet3_Phi ", "jet3_Phi ", 50, -4, 4);
TH1D *jet3_mass = new TH1D("jet3_mass ", "jet3_mass ", 50, 0, 300);
TH1D *jet4_Pt = new TH1D("jet4_Pt ", "jet4_Pt ", 50, 0, 300);
TH1D *jet4_Eta = new TH1D("jet4_Eta ", "jet4_Eta ", 30, -5, 5);
TH1D *jet4_Phi = new TH1D("jet4_Phi ", "jet4_Phi ", 50, -4, 4);
TH1D *electron1_Pt = new TH1D("electron1_Pt ", "electron1_Pt ", 50, 0, 600);
TH1D *electron1_Eta = new TH1D("electron1_Eta ", "electron1_Eta ", 50, -4, 4);
TH1D *electron1_Phi = new TH1D("electron1_Phi ", "electron1_Phi ", 50, -4, 4);
TH1D *electron2_Pt = new TH1D("electron2_Pt ", "electron2_Pt ", 50, 0, 600);
TH1D *electron2_Eta = new TH1D("electron2_Eta ", "electron2_Eta ", 50, -4, 4);
TH1D *electron2_Phi = new TH1D("electron2_Phi ", "electron2_Phi ", 50, -4,4);
TH1D *electron3_Pt = new TH1D("electron3_Pt ", "electron3_Pt ", 50, 0, 600);
TH1D *electron3_Eta = new TH1D("electron3_Eta ", "electron3_Eta ", 50, -4, 4);
TH1D *electron3_Phi = new TH1D("electron3_Phi ", "electron3_Phi ", 50, -4, 4);
TH1D *btag_mass = new TH1D("btag_mass ", "btag_mass ", 100, 0, 30);
TH1D *btag_Pt = new TH1D("btag_Pt ", "btag_Pt ", 50, 0, 300);
TH1D *btag_Eta = new TH1D("btag_Eta ", "btag_Eta ", 100, -5, 5);
TH1D *btag_Phi = new TH1D("btag_Phi ", "btag_Phi ", 100, -5, 5);
TH1D *balgo_Pt = new TH1D("balgo_Pt ", "balgo_Pt ", 50, 0, 300);
TH1D *balgo_Eta = new TH1D("balgo_Eta ", "balgo_Eta ", 100, -5, 5);
TH1D *balgo_Phi = new TH1D("balgo_Phi ", "balgo_Phi ", 100, -5, 5);
//TH1D *top_mass = new TH1D("top_mass ", "top_mass ", 20, 30, 250);
TH1D *top_pt = new TH1D("top_pt ", "top_pt ", 20, 30, 500);
TH1D *W_mass = new TH1D("W_mass ", "W_mass ", 20, 30, 150);
TH1D *Z_mass = new TH1D("Z_mass ", "Z_mass ", 20, 30, 150);
TH1D *Met_met = new TH1D("Met_met  ", "Met_met  ", 50, 0, 400);
TH1D *Met_Eta = new TH1D("Met_Eta ", "Met_Eta ", 50, -8, 8);
TH1D *Met_Phi = new TH1D("Met_Phi ", "Met_Phi ", 40, -5, 5);
TH1D *Met_mass = new TH1D("MET_mass ", "MET_mass ", 40, -4, 4);
TH1D *cutFlowHist = new TH1D("cutFlowHist", "Cut Flow", 10, 0, 200);


TFile *f = new TFile("Detector_level.root");

TTree *Delphes1 = (TTree*)f->Get("Delphes");

// Declaration of leaves type
   Int_t           Jet_size;
   Float_t         Jet_PT[14];
   Float_t         Jet_Eta[14];
   Float_t         Jet_Phi[14];
   Float_t         Jet_Mass[14];
   UInt_t          Jet_BTag[14];
   UInt_t          Jet_BTagAlgo[14];
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
   Delphes1->SetBranchAddress("Jet.BTagAlgo",Jet_BTag);
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


 


 for (Int_t i = 0; i < nentries ; i++) {
//  for (Int_t i = 0; i < 1000; i++) {
  // totalEvents++; 
//  cutStage++;
   cout<< i << "\n" ;
        Delphes1->GetEntry(i);
       // printf("%d\n",Jet_size);
      //hpt1->Fill(Jet_size);  
//----------------------------------------------------------------------------------------------------------------------------------------------------------------


//if(Jet_size == 4 && Electron_size == 3 && MissingET_size == 1 ) {

//std::vector<JetInfo> leadingJets;
TLorentzVector bTag;
TLorentzVector normalJets1;
TLorentzVector normalJets2;
TLorentzVector normalJets3;



int btag_index = -1;
int balgo_index = -1;
int normal_j1_index=-1;
int normal_j2_index=-1;
int normal_j3_index=-1;



for (int j = 0; j < Jet_size; j++) 
{

    //cout<<"jjjjjj"<<j<<endl;
	TLorentzVector Jet;
	Jet.SetPtEtaPhiM(Jet_PT[j], Jet_Eta[j], Jet_Phi[j], Jet_Mass[j]);
	if (Jet_BTag[j] == 1  ) 
	{
    	//btag_Pt->Fill(Jet.Pt());
    	//btag_Eta->Fill(Jet.Eta());
    	//btag_Phi->Fill(Jet.Phi()); 
   	//Jet = bTag;
   	int bj = j;
    	btag_index = bj;
    	
    	// btag_Pt ->Fill( Jet.Pt());
        // btag_Eta ->Fill( Jet.Eta());
        // btag_Phi->Fill(Jet.Phi()); 
      //   break;
    	}
    
      
    
    
	//std::vector<JetInfo> Jet;
	//Jet.push_back({j, Jet_PT[j]});
  
  	 if  (btag_index!=-1)
  	 { 
  	 
  	 if(Jet.Pt() > 25 )
  	 {   
  	 btag_Pt ->Fill( Jet.Pt());
         btag_Eta ->Fill( Jet.Eta());
         btag_Phi->Fill(Jet.Phi());
         } 
  	 //leadingJets.push_back({j, Jet_PT[j]});
  	 }

       

}
  
 //if(btag_index!=-1)
 //{
 	
 	
 	
 	for (int i = 0; i < Jet_size; i++) 

//cout << "Jet_Pt " << Jet_PT[i] << "\n";
 	{
        TLorentzVector Jet1;
        Jet1.SetPtEtaPhiM(Jet_PT[i], Jet_Eta[i], Jet_Phi[i], Jet_Mass[i]);
        {
        if(i!=btag_index && abs(Jet1.Eta()) > 2.5 && Jet1.Pt() > 30.0 && Jet1.E() > 300.0)
        {
        int Bi = i;
      //  normalJets1=Jet1;
        normal_j1_index= Bi;
    //    }
        
   //     if(abs(Jet1.Eta()) > 2.5 && Jet1.Pt() > 30.0 && Jet1.E() > 300.0)
    //    {
        jet1_Pt->Fill(Jet1.Pt());
        jet1_Eta->Fill(Jet1.Eta());
        jet1_Phi->Fill(Jet1.Phi());
   //     }
      //  break;
        }
        
        }
    //    }
        
        
        for (int k = 0; k < Jet_size; k++) 
        {   

        TLorentzVector Jet2;

        Jet2.SetPtEtaPhiM(Jet_PT[k], Jet_Eta[k], Jet_Phi[k], Jet_Mass[k]);
        {
        if(k!=btag_index && k!=normal_j1_index )
        {
        int Bk = k;
       // normalJets2=Jet2;
        normal_j2_index= Bk;
     //   }
        if(Jet2.Pt() > 25 && abs(Jet2.Eta()) < 2.0 )
        {
        jet2_Pt->Fill(Jet2.Pt());
        jet2_Eta->Fill(Jet2.Eta());
        jet2_Phi->Fill(Jet2.Phi());
        }
     // break;
        }
        
        }
        //}
        
        
        for (int l = 0; l < Jet_size; l++) 
        {   

        TLorentzVector Jet3;

        Jet3.SetPtEtaPhiM(Jet_PT[l], Jet_Eta[l], Jet_Phi[l], Jet_Mass[l]);
        {
        if(l!=btag_index && l!=normal_j1_index && l!=normal_j2_index ) 
        {
        int Bl = l;
     //   normalJets3=Jet3;
        normal_j3_index= Bl;
     //   }
        if(Jet3.Pt() > 25 && abs(Jet3.Eta()) < 2.0 )
        {
        jet3_Pt->Fill(Jet3.Pt());
        jet3_Eta->Fill(Jet3.Eta());
        jet3_Phi->Fill(Jet3.Phi());
     //   break;
        }
    
        }
         TLorentzVector top;
         top = bTag + Jet2 + Jet3;
       //  top_mass->Fill(top.M());
       
       if(top.Pt() > 30){
         top_pt->Fill(top.Pt());
         }
        }
        }
        }
        
        }
        
    //for (int k = j+1; k < Jet_size; k++) 
    //{
    //for (int l = k+1; l < Jet_size; l++) 
    //{
 	/*	TLorentzVector Jet1;

 		Jet1.SetPtEtaPhiM(Jet_PT[i], Jet_Eta[i], Jet_Phi[i], Jet_Mass[i]);
        {
        if(i!=btag_index)
 		{
 		int Bj = i;
 		normalJets=Jet1;
 		normal_j_index= Bj;
		}
		jet1_Pt->Fill(normalJets.Pt());
        jet1_Eta->Fill(normalJets.Eta());
    		//jet1_Eta->Fill(Jet_Eta[leadingJets[0].index]);
    		//jet1_Phi->Fill(Jet_Phi[leadingJets[0].index]);  
		
 		}
 	}
 //}
 
  	for (int j = 0; j < Jet_size; j++) 
 {

cout<<"normal jet pt"<<normalJets.Pt()<<endl;
 }
 */
//------------------------------------------------------------------------------------------------------------------------------------------------------------------ 
 //std::vector<JetInfo> leadingJets;

//Jet_distribution->Fill(Jet_size);

/*for (int j = 0; j < Jet_size; j++) {
    if (j != btag_index ) { 
        leadingJets.push_back({j});
                          }

//Jet_Pt->Fill(Jet_PT[j]);

    
                                    }   */
  
  
  
  
    
   


//------------------------------------------------------------------------------------------------------------------------------------------------------------------
       
        int normal_e1_index=-1;
	int normal_e2_index=-1;
	int normal_e3_index=-1;
        
        
        
        TLorentzVector electron1;
	TLorentzVector electron2;
	TLorentzVector electron3;
  
        for (int i = 0; i < Electron_size; i++) 

 	{
        TLorentzVector electron1;
        electron1.SetPtEtaPhiM(Electron_PT[i], Electron_Eta[i], Electron_Phi[i], Electron_PT[i]);
        {
        
        //int Bi = i;
       // normal_e1_index= Bi;
    
        if(electron1.Pt() > 20 && abs(electron1.Eta()) < 2.5 )
        {
        
        int Bi = i;
        normal_e1_index= Bi;
        electron1_Pt->Fill(electron1.Pt());
        electron1_Eta->Fill(electron1.Eta());
        electron1_Phi->Fill(electron1.Phi());
        }
        }
        
    //    }
        
        
        
        for (int k = 0; k < Electron_size; k++) 
        {   

        TLorentzVector electron2;

        electron2.SetPtEtaPhiM(Electron_PT[k], Electron_Eta[k], Electron_Phi[k], Electron_PT[k]);
        {
        if (k!=normal_e1_index && electron2.Pt() > 20.0 && abs(electron2.Eta()) < 2.5)
        {
        int Bk = k;
      
        normal_e2_index= Bk;
    
      //  if(electron2.Pt() > 20.0 && abs(electron2.Eta()) < 2.5 )
     //   {
        electron2_Pt->Fill(electron2.Pt());
        electron2_Eta->Fill(electron2.Eta());
        electron2_Phi->Fill(electron2.Phi());
     //   }
//cout <<"electron2_Eta= " <<  electron2_Eta->Integral() << "\n";
        }
        
        }
  //      }
        
        
        for (int l = 0; l < Electron_size; l++) 
        {   

        TLorentzVector electron3;

        electron3.SetPtEtaPhiM(Electron_PT[l], Electron_Eta[l], Electron_Phi[l],Electron_PT[l]);
        {
        if( l!=normal_e1_index && l!=normal_e2_index && electron3.Pt() > 20.0 && abs(electron3.Eta()) < 2.5) 
        {
        int Bl = l;
     
        normal_e3_index= Bl;
     
     //   if(electron3.Pt() > 20.0 && abs(electron3.Eta()) < 2.5 )
     //   {
        electron3_Pt->Fill(electron3.Pt());
        electron3_Eta->Fill(electron3.Eta());
        electron3_Phi->Fill(electron3.Phi());
     //   }
        
        }
    
        } 
        
        TLorentzVector Z_boson;
        Z_boson = electron2 + electron3;
        Z_mass->Fill(Z_boson.M());
    //    }
  
  
  
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
   
 
                                        
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
   
    int normal_m1_index=-1;
    TLorentzVector Met;
   
    for (int i = 0; i < MissingET_size; i++) 

 	{
        TLorentzVector Met;
        Met.SetPtEtaPhiM(MissingET_MET[i], MissingET_Eta[i], MissingET_Phi[i], MissingET_MET[i]);
        {
        
        int Bi = i;
        normal_m1_index= Bi;
   
        if(Met.Pt() > 25)
        {
        Met_met->Fill(Met.Pt());
        Met_Eta->Fill(Met.Eta());
        Met_Phi->Fill(Met.Phi());
        }
        
        }
       
       TLorentzVector W_boson;
       W_boson = electron1 + Met;
       W_mass->Fill(W_boson.M()); 
        }
        }
        }
        }
        
 //  cout <<"electron2_Eta= " <<  electron2_Eta->Integral() << "\n";
   
  } 
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
 
   
 
  
  
   TFile outputFile1 ("outputFile_scale_1lakh.root", "recreate"); 
  //  if(Jet_size == 3 && Electron_size == 3 && MissingET_size == 1 && b_Jets.size() == 1) {
    
  
 //  top_mass->Scale(1.0/top_mass->Integral());   
   top_pt->Scale(1.0/top_pt->Integral());         
    W_mass->Scale(1.0/W_mass->Integral());  
    Z_mass->Scale(1.0/Z_mass->Integral() ) ; 
    btag_Pt->Scale(1.0/btag_Pt->Integral() );  
    btag_Eta->Scale(1.0/btag_Eta->Integral());  
    btag_Phi->Scale(1.0/btag_Phi->Integral() ) ; 
    jet1_Pt->Scale(1.0/jet1_Pt->Integral() ) ; 
    jet1_Eta->Scale(1.0/jet1_Eta->Integral() );  
    jet1_Phi->Scale(1.0/jet1_Phi->Integral() )  ; 
    jet2_Pt->Scale(1.0/jet2_Pt->Integral() )  ;
    jet2_Eta->Scale(1.0/jet2_Eta->Integral() ) ; 
    jet2_Phi->Scale(1.0/jet2_Phi->Integral() )  ;
    jet3_Pt->Scale(1.0/jet3_Pt->Integral() )  ;
    jet3_Eta->Scale(1.0/jet3_Eta->Integral() ) ; 
    jet3_Phi->Scale(1.0/jet3_Phi->Integral() )  ;
    electron1_Pt->Scale(1.0/electron1_Pt->Integral() ) ; 
    electron1_Eta->Scale(1.0/electron1_Eta->Integral() ) ; 
    electron1_Phi->Scale(1.0/electron1_Phi->Integral() )  ;
    electron2_Pt->Scale(1.0/electron2_Pt->Integral() )  ;
    electron2_Eta->Scale(1.0/electron2_Eta->Integral() ) ; 
    
    electron2_Phi->Scale(1.0/electron2_Phi->Integral() )  ;
    electron3_Pt->Scale(1.0/electron3_Pt->Integral() )  ;
    electron3_Eta->Scale(1.0/electron3_Eta->Integral() ) ; 
    electron3_Phi->Scale(1.0/electron3_Phi->Integral() )  ;
    Met_met->Scale(1.0/Met_met->Integral() )  ;
    Met_Eta->Scale(1.0/Met_Eta->Integral() )  ;
    Met_Phi->Scale(1.0/Met_Phi->Integral() )   ;
    
     
  //  top_mass->Write(); 
    top_pt->Write();         
    W_mass->Write();
    Z_mass->Write();
    btag_Pt->Write();
    btag_Eta->Write();
    btag_Phi->Write(); 
    balgo_Pt->Write();
    balgo_Eta->Write();
    balgo_Phi->Write(); 
     
  
   
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
  //  cutFlowHist->Write();
    
   // }
   
  
     
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
     
//    double norm = (0.003741E-06*1000*200);   //Integrated luminosity = 200 fb-1 ;
    
     
    
      
  //   }

    
   
    
    
    outputFile1.Close();
 //}   
    
    



//}


TCanvas *c1 = new TCanvas();

top_pt ->Draw();
c1->SaveAs("top_pt.png");


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

/*TCanvas *c28 = new TCanvas();

balgo_Pt ->Draw();
c28->SaveAs("balgo_Pt.png");

TCanvas *c29 = new TCanvas();

balgo_Eta ->Draw();
c29->SaveAs("balgo_Eta.png");

TCanvas *c30 = new TCanvas();

balgo_Phi ->Draw();
c30->SaveAs("balgo_Phi.png");*/

f->Close();

}





























