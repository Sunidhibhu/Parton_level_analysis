#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <TLorentzVector.h>
#include "TFile.h"
#include "TMath.h"
#include "TTree.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "conversions.h"



struct JetInfo
{
	int index;
	double pt;
};

void Delphes_output_tWZj_1()
{

    /*TH1D *jet2_Pt = new TH1D("jet2_Pt ", "jet2_Pt ", 50, -1, 600);
    TH1D *jet2_Eta = new TH1D("jet2_Eta ", "jet2_Eta ", 30, -6, 6);
    TH1D *jet2_Phi = new TH1D("jet2_Phi ", "jet2_Phi ", 50, -4, 4);*/
    TH1D *forwJet_Pt = new TH1D("forwJet_Pt ", "forwJet_Pt ", 50, 0, 600);
    TH1D *forwJet_Eta = new TH1D("forwJet_Eta ", "forwJet_Eta ", 50, -6, 6);
    TH1D *forwJet_Phi = new TH1D("forwJet_Phi ", "forwJet_Phi ", 50, -3.5, 3.5);
    //TH1D *forward_jet_mass = new TH1D("forward_jet_mass ", "forward_jet_mass ", 50, 0, 200);
    TH1D *W_jet1_Pt = new TH1D("W_jet1_Pt ", "W_jet1_Pt ", 50, 0, 400);
    TH1D *W_jet1_Eta = new TH1D("W_jet1_Eta ", "W_jet1_Eta ", 50, -5, 5);
    TH1D *W_jet1_Phi = new TH1D("W_jet1_Phi ", "W_jet1_Phi ", 50, -3.5, 3.5);
    TH1D *W_jet2_Pt = new TH1D("W_jet2_Pt ", "W_jet2_Pt ", 50, 0, 500);
    TH1D *W_jet2_Eta = new TH1D("W_jet2_Eta ", "W_jet2_Eta ", 50, -6, 6);
    TH1D *W_jet2_Phi = new TH1D("W_jet2_Phi ", "W_jet2_Phi ", 50, -3.5, 3.5);
    TH1D *Z_e1_Pt = new TH1D("Z_e1_Pt ", "Z_e1_Pt ", 50, 0, 500);
    TH1D *Z_e1_Eta = new TH1D("Z_e1_Eta ", "Z_e1_Eta ", 50, -4, 4);
    TH1D *Z_e1_Phi = new TH1D("Z_e1_Phi ", "Z_e1_Phi ", 50, -3.5, 3.5);
    TH1D *Z_e2_Pt = new TH1D("Z_e2_Pt ", "Z_e2_Pt ", 50, 0, 500);
    TH1D *Z_e2_Eta = new TH1D("Z_e2_Eta ", "Z_e2_Eta ", 50, -4, 4);
    TH1D *Z_e2_Phi = new TH1D("Z_e2_Phi ", "Z_e2_Phi ", 50, -3.5, 3.5);
    /*TH1D *jet3_Pt = new TH1D("jet3_Pt ", "jet3_Pt ", 50, -1, 600);
    TH1D *jet3_Eta = new TH1D("jet3_Eta ", "jet3_Eta ", 30, -6, 6);
    TH1D *jet3_Phi = new TH1D("jet3_Phi ", "jet3_Phi ", 50, -4, 4);*/
    TH1D *W_e1_Pt = new TH1D("W_e1_Pt ", "W_e1_Pt ", 50, 0, 400);
    TH1D *W_e1_Eta = new TH1D("W_e1_Eta ", "W_e1_Eta ", 30, -4, 4);
    TH1D *W_e1_Phi = new TH1D("W_e1_Phi ", "W_e1_Phi ", 50, -3.5, 3.5);
    TH1D *No_of_Jet = new TH1D("No_of_Jet ", "No_of_Jet ", 50, 0, 20);
    TH1D *No_of_b_Jet = new TH1D("No_of_b_Jet ", "No_of_b_Jet ", 50, 0, 20);
    TH1D *No_of_electron = new TH1D("No_of_electron ", "No_of_electron ", 50, 0, 10);
    TH1D *No_of_muon = new TH1D("No_of_muon ", "No_of_muon ", 50, 0, 10);
    TH1D *No_of_electron_plus_muon = new TH1D("No_of_electron_plus_muon ", "No_of_electron_plus_muon ", 50, 0, 10);
    TH1D *btag_Pt = new TH1D("btag_Pt ", "btag_Pt ", 50, 0, 500);
    TH1D *btag_Eta = new TH1D("btag_Eta ", "btag_Eta ", 100, -5, 5);
    TH1D *btag_Phi = new TH1D("btag_Phi ", "btag_Phi ", 100, -3.5, 3.5);
    // TH1D *top_mass = new TH1D("top_mass ", "top_mass ", 20, 30, 250);
    TH1D *top_reco_mass = new TH1D("top_reco_mass ", "top_reco_mass ", 50, 50, 400);
    TH1D *W_boson_transverse_mass = new TH1D("W_boson_transverse_mass ", "W_boson_transverse_mass ", 100, 0, 250);
    TH1D *Z_mass = new TH1D("Z_mass ", "Z_mass ", 100, 50, 250);
    TH1D *Met_met = new TH1D("Met_met  ", "Met_met  ", 50, 0, 400);
    TH1D *Met_Eta = new TH1D("Met_Eta ", "Met_Eta ", 50, -6, 6);
    TH1D *Met_Phi = new TH1D("Met_Phi ", "Met_Phi ", 50, -3.5, 3.5);
   // TH1D *Met_mass = new TH1D("MET_mass ", "MET_mass ", 40, -4, 4);
   // TH1D *cutFlowHist = new TH1D("cutFlowHist", "Cut Flow", 10, 0, 200);
    TH1D *W_top_mass = new TH1D("W_top_mass ", "W_top_mass ", 20, 30, 150);
    TH1D *W_boson_reco_mass = new TH1D("W_boson_reco_mass ", "W_boson_reco_mass ", 20, 30, 150);
    TH1D *Z_boson_reco_mass = new TH1D("Z_boson_reco_mass ", "Z_boson_reco_mass ", 20, 30, 150);
    TH1D *deltaEta_W_jet1_forw = new TH1D("deltaEta_W_jet1_forw", "deltaEta between forward jet and jet1 from W boson", 50, -10, 8);
    TH1D *deltaEta_W_jet2_forw = new TH1D("deltaEta_W_jet2_forw", "deltaEta between forward jet and jet2 from W boson", 50, -10, 8);
    TH1D *deltaEta_b_quark_forw = new TH1D("deltaEta_b_quark_forw", "deltaEta between forward jet and b quark", 50, -10, 8);
    TH1D *deltaPhi_W_jet1_forw = new TH1D("deltaPhi_W_jet1_forw", "deltaPhi_W_jet1_forw", 50, -3.5, 3.5);
    TH1D *deltaPhi_W_jet2_forw = new TH1D("deltaPhi_W_jet2_forw", "deltaPhi_W_jet2_forw", 50, -3.5, 3.5);
    TH1D *deltaPhi_b_quark_forw = new TH1D("deltaPhi_b_quark_forw", "deltaPhi_b_quark_forw", 50, -3.5, 3.5);
    TH1D *deltaR_W_jet1_forw = new TH1D("deltaR_W_jet1_forw", "deltaR_W_jet1_forw", 50, -2, 10);
    TH1D *deltaR_W_jet2_forw = new TH1D("deltaR_W_jet2_forw", "deltaR_W_jet2_forw", 50, -2, 10);
    TH1D *deltaR_b_quark_forw = new TH1D("deltaR_b_quark_forw", "deltaR_b_quark_forw", 50, -2, 10);
    TH1D *deltaEta_W_top_forw = new TH1D("deltaEta_W_top_forw", "deltaEta_W_top_forw", 50, -10, 8);
    //---------------------------------------------------------------------------------------------------------------------------------------------------
    TFile *f = new TFile("tvvj_Yt_UFO_all_decay_detector.root");

    TTree *Delphes1 = (TTree *)f->Get("Delphes");

    // Declaration of leaves type----------------------------------------------------------------------------------------------------------------------
    Int_t Jet_size;
    Float_t Jet_PT[14];
    Float_t Jet_Eta[14];
    Float_t Jet_Phi[14];
    Float_t Jet_Mass[14];
    UInt_t Jet_BTag[14];
    Int_t Electron_size;
    Float_t Electron_PT[4];
    Float_t Electron_Eta[4];
    Float_t Electron_Phi[4];
    Int_t Electron_Charge[4];
    Float_t Electron_T[4];
    Int_t Muon_size;
    Float_t Muon_PT[4];
    Float_t Muon_Eta[4];
    Float_t Muon_Phi[4];
    Int_t Muon_Charge[4];
    Float_t Particle_Mass[3920];
    Float_t Particle_PT[3920];
    Int_t Particle_size;
    Float_t MissingET_MET[1];
    Float_t MissingET_Eta[1];
    Float_t MissingET_Phi[1];
    Int_t MissingET_size;
     Int_t Photon_size;
    Float_t Photon_PT[4];
    Float_t Photon_Eta[4];
    Float_t Photon_Phi[4];
   // Int_t Photon_Charge[4];

    // Set branch addresses----------------------------------------------------------------------------------------------------------------------------

    Delphes1->SetBranchAddress("Jet.PT", Jet_PT);
    Delphes1->SetBranchAddress("Jet.Eta", Jet_Eta);
    Delphes1->SetBranchAddress("Jet.Phi", Jet_Phi);
    Delphes1->SetBranchAddress("Jet_size", &Jet_size);
    Delphes1->SetBranchAddress("Jet.Mass", Jet_Mass);
    Delphes1->SetBranchAddress("Jet.BTag", Jet_BTag);
    Delphes1->SetBranchAddress("Electron.PT", Electron_PT);
    Delphes1->SetBranchAddress("Electron.Eta", Electron_Eta);
    Delphes1->SetBranchAddress("Electron.Phi", Electron_Phi);
    Delphes1->SetBranchAddress("Electron.Charge", Electron_Charge);
    Delphes1->SetBranchAddress("Electron_size", &Electron_size);
    Delphes1->SetBranchAddress("Muon.PT", Muon_PT);
    Delphes1->SetBranchAddress("Muon.Eta", Muon_Eta);
    Delphes1->SetBranchAddress("Muon.Phi", Muon_Phi);
    Delphes1->SetBranchAddress("Muon.Charge", Muon_Charge);
    Delphes1->SetBranchAddress("Muon_size", &Muon_size);
    Delphes1->SetBranchAddress("Particle.Mass", Particle_Mass);
    Delphes1->SetBranchAddress("Particle.PT", Particle_PT);
    Delphes1->SetBranchAddress("Particle_size", &Particle_size);
    Delphes1->SetBranchAddress("MissingET.MET", MissingET_MET);
    Delphes1->SetBranchAddress("MissingET.Eta", MissingET_Eta);
    Delphes1->SetBranchAddress("MissingET.Phi", MissingET_Phi);
    Delphes1->SetBranchAddress("MissingET_size", &MissingET_size);
    Delphes1->SetBranchAddress("Photon.PT", Photon_PT);
    Delphes1->SetBranchAddress("Photon.Eta", Photon_Eta);
    Delphes1->SetBranchAddress("Photon.Phi", Photon_Phi);
  //  Delphes1->SetBranchAddress("Photon.Charge", Photon_Charge);
    Delphes1->SetBranchAddress("Photon_size", &Photon_size);

    Int_t nentries = (Int_t)Delphes1->GetEntries();

    for (Int_t i = 0; i < nentries; i++)
  //  {
  //  for (Int_t i = 0; i < 100; i++)
    {

        cout << i << "\n";
      
        Delphes1->GetEntry(i);

        //----------------------------------------------------------------------------------------------------------------------------------------------------------------
           
        const float MUON_MASS = 0.1056583745;
        const float ELE_MASS  = 0.000511;

        //lepton cuts
        const float LEP_PT_CUT = 20;
        const float EL_ETA_CUT = 2.5;
        const float MU_ETA_CUT = 2.4;
        const float JET_PT_CUT = 25;
        const float JET_ETA_CUT = 2.5;
        const float JET_DELTA_R_CUT = 0.5;
        const float MET_PT_CUT = 20;

        std::vector<TLorentzVector> vec_Ele;
        std::vector<TLorentzVector> vec_Mu;
        std::vector<int> vec_Jet;
        std::vector<JetInfo> b_Jet;
        std::vector<JetInfo> Jets;
        std::vector<JetInfo>ve;
        std::vector<JetInfo>ek;


        TLorentzVector isolated_Jet;
       // TLorentzVector Jet;
        TLorentzVector Jet_1;
        TLorentzVector Jet_2;
        TLorentzVector Jet_3;

        //---------------------------------------------------------------------------------------------------------------------------------------------------
        int btag_index;
        int forw_jet_index;
        int isolated_jet_index;
        int jet_index;
        int normal_j1_index;
        int normal_j2_index;
        int normal_j3_index;
        int normal_e1_index;
        int normal_e2_index;
        int normal_e3_index;
        int normal_mu1_index;
        int normal_mu2_index;
        int normal_mu3_index;
        
        
        //------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //*******************************************************Reconstruction of top quark**********************************************************************
        //------------------------------------------------------------------------------------------------------------------------------------------------------------
        vec_Mu.clear();
        vec_Ele.clear();
        int Ele = 0;
        int Mu = 0;

        for(unsigned int j=0; j<Electron_size; j++){
            if(Electron_PT[j] < LEP_PT_CUT) continue;
            if(abs(Electron_Eta[j]) > EL_ETA_CUT) continue;

            TLorentzVector elec(0,0,0,0);
            elec.SetPtEtaPhiM(Electron_PT[j],Electron_Eta[j],Electron_Phi[j],ELE_MASS);

            Ele++;
            vec_Ele.push_back(elec);
        }

        for(unsigned int j=0; j<Muon_size; j++){
            if(Muon_PT[j] < LEP_PT_CUT) continue;
            if(abs(Muon_Eta[j]) > MU_ETA_CUT) continue;

            TLorentzVector muon(0,0,0,0);
            muon.SetPtEtaPhiM(Muon_PT[j],Muon_Eta[j],Muon_Phi[j],MUON_MASS);

            Mu++;
            vec_Mu.push_back(muon);
        }
    
        if (Ele + Mu < 3) continue;

        vec_Jet.clear();

        for(unsigned int j=0; j<Jet_size; j++){
            if(Jet_PT[j] < JET_PT_CUT) continue;
           // if(abs(Jet_Eta[j]) > JET_ETA_CUT) continue;

            bool isClean=true;

            //lepton cleaning

            for ( std::size_t k=0; k<vec_Ele.size(); k++)
                {
                    if (deltaR(vec_Ele.at(k).Eta(), vec_Ele.at(k).Phi(),
                         Jet_Eta[j], Jet_Phi[j]) < JET_DELTA_R_CUT)
                    isClean = false;
                }
                for ( std::size_t k=0; k<vec_Mu.size(); k++)
                {
                    if (deltaR(vec_Mu.at(k).Eta(), vec_Mu.at(k).Phi(),
                         Jet_Eta[j], Jet_Phi[j]) < JET_DELTA_R_CUT)
                    isClean = false;
                }

                if ( isClean == false ) continue;

                vec_Jet.push_back(j);
        
        }
        //cout << "no of isolated jet" << vec_Jet.size() << "\n";

        for (int j = 0; j < vec_Jet.size(); j++)
        {

           // bool Jet_bTag_flag = true;

            if (Jet_BTag[j] == 1) //Jet_bTag_flag = true;

            {
                b_Jet.push_back({j,Jet_PT[j]});
            }

        }
//----------------------------------------------------------------------------------------------------------------------------------------------------
        
        std::sort(b_Jet.begin(), b_Jet.end(), [](const JetInfo &a, const JetInfo &b)
				  { return a.pt > b.pt; });
        
//---------------------------------------------------------------------------------------------------------------------------------------------------

        
        if(b_Jet.empty()) continue;
        
       // cout << "No of events" << nentries << "\n";
        TLorentzVector bTag;
        bTag.SetPtEtaPhiM(Jet_PT[b_Jet[0].index], Jet_Eta[b_Jet[0].index], Jet_Phi[b_Jet[0].index], Jet_Mass[b_Jet[0].index]);

        for (int j = 0; j < vec_Jet.size(); j++)
        {

            if (j == b_Jet[0].index) continue;

            
                Jets.push_back({j,Jet_PT[j]});
            
        }
       
        std::sort(Jets.begin(), Jets.end(), [](const JetInfo &a, const JetInfo &b)
				  { return a.pt > b.pt; });

        TLorentzVector forwJet;
        if(!Jets.empty()){
        forwJet.SetPtEtaPhiM(Jet_PT[Jets[0].index], Jet_Eta[Jets[0].index], Jet_Phi[Jets[0].index], Jet_Mass[Jets[0].index]);
        }
        else{
            cout << "no forw jet" << "\n";
        }
        
        TLorentzVector W_j1;
        if(Jets.size() > 1){
        W_j1.SetPtEtaPhiM(Jet_PT[Jets[1].index], Jet_Eta[Jets[1].index], Jet_Phi[Jets[1].index], Jet_Mass[Jets[1].index]);
        }
        else{
            cout << "no jet 1" << "\n";
        }
        
        TLorentzVector W_j2;
        if(Jets.size() > 2){
        W_j2.SetPtEtaPhiM(Jet_PT[Jets[2].index], Jet_Eta[Jets[2].index], Jet_Phi[Jets[2].index], Jet_Mass[Jets[2].index]);
        }
        else{
            cout << "no jet 2" << "\n";
        }

        TLorentzVector W_boson_top_reco;
        W_boson_top_reco = W_j1 + W_j2;

        TLorentzVector top_reco;
        top_reco = bTag + W_boson_top_reco;

        //------------------------------------------------------------------------------------------------------------------------------------------------------------------
        //*******************************************************Reconstruction of Z boson**********************************************************************
        //------------------------------------------------------------------------------------------------------------------------------------------------------------
        
        double Temp_mass = 999.0;
        double Zmass = 90.0;
        double Temp_mass_2;
        unsigned int L1;
        unsigned int L2;
        bool findZ1 = false;
        unsigned int N = Electron_size;

        for(std::size_t i=0; i<vec_Ele.size(); i++){
        for(std::size_t j=i+1; j<=vec_Ele.size(); j++){

            //cout << "electron charge " << Electron_Charge[i] << " , "<< Electron_Charge[j] << "\n";

           // if((Electron_Charge[i]+Electron_Charge[j]) != 0) continue;
            if((Electron_Charge[i])*(Electron_Charge[j]) > 0) continue;

            
            
            TLorentzVector ei, ej;
          
            ei.SetPtEtaPhiM(Electron_PT[i],Electron_Eta[i],Electron_Phi[i],ELE_MASS);
            ej.SetPtEtaPhiM(Electron_PT[j],Electron_Eta[j],Electron_Phi[j],ELE_MASS);

            TLorentzVector m_ee = ei+ej;

           
            if(abs(m_ee.M()-Zmass)<Temp_mass){
                double mZ1 = m_ee.M();
                L1 = i; L2 = j;  findZ1 = true; Temp_mass = abs(mZ1-Zmass);
                //cout <<"L1  "<< L1 <<"L2        "<< L2 << "Temp_mass_a  =  " << Temp_mass << "\n";
                
            }
            //}
               
         }
        }
        
       



        TLorentzVector e1, e2;
       
        e1.SetPtEtaPhiM(Electron_PT[L1],Electron_Eta[L1],Electron_Phi[L1],ELE_MASS);
        e2.SetPtEtaPhiM(Electron_PT[L2],Electron_Eta[L2],Electron_Phi[L2],ELE_MASS);
        TLorentzVector me1e2 = e1+e2;

        bool passZ1 = false;
        if(me1e2.M()>40 && me1e2.M()<120 && findZ1) passZ1 = true;

        //--------------------------------------------------------------------------------------------------------------------------------------------------------
        //*********************************************Reconstruction of W boson *********************************************************
        //--------------------------------------------------------------------------------------------------------------------------------------------
        const float ELE_MASS_1  = 0.000511;
        for(int k=0; k<vec_Ele.size(); k++){
           if(k==L1 || k==L2) continue; // can not be the lep from Z1
          
            ek.push_back({k,Electron_PT[k]});
        
        }
        //cout << "W_electron_size =" <<ek.size() << "\n";
        
        std::sort(ek.begin(), ek.end(), [](const JetInfo &a, const JetInfo &b)
				  { return a.pt > b.pt; });
        
        TLorentzVector W_e1;
        if(!ek.empty()){
         W_e1.SetPtEtaPhiM(Electron_PT[ek[0].index],Electron_Eta[ek[0].index],Electron_Phi[ek[0].index],ELE_MASS_1);
        }
       


        for(int i=0; i<MissingET_size; i++){

            ve.push_back({i,MissingET_MET[i]});
        }

        std::sort(ve.begin(), ve.end(), [](const JetInfo &a, const JetInfo &b)
				  { return a.pt > b.pt; });

        TLorentzVector Met;
        if(!ve.empty()){
             Met.SetPtEtaPhiM(MissingET_MET[ve[0].index], 0.0, MissingET_Phi[ve[0].index], 0.0);
        }
       

        //------------------------------------------------------------------------------------------------------------------------------------------------
        
        
        //------------------------------------------------------------------------------------------------------------------------------------------------
            TLorentzVector W_boson;
            W_boson = W_e1 + Met;

        //---------------------------------------------------------------------------------------------------------------------------------------------
        

  
  //-------------------------------------------------------------------------------------------------------------------------------------------------
       if ( e1.Pt() > 20 && abs(e1.Eta()) < 2.5 && e2.Pt() > 20 && abs(e2.Eta()) < 2.5)
        {

        Z_e1_Pt->Fill(e1.Pt());
        Z_e1_Eta->Fill(e1.Eta());
        Z_e1_Phi->Fill(e1.Phi());
        Z_e2_Pt->Fill(e2.Pt());
        Z_e2_Eta->Fill(e2.Eta());
        Z_e2_Phi->Fill(e2.Phi());
        Z_mass->Fill(me1e2.M());


        }

        if (W_e1.Pt() > 20 && abs(W_e1.Eta()) < 2.5){
        W_e1_Pt->Fill(W_e1.Pt());
        W_e1_Eta->Fill(W_e1.Eta());
        W_e1_Phi->Fill(W_e1.Phi());
        W_boson_transverse_mass->Fill(W_boson.Mt());
        }

        btag_Pt->Fill(bTag.Pt());
        btag_Eta->Fill(bTag.Eta());
        btag_Phi->Fill(bTag.Phi());

        if(abs(forwJet.Eta()) > 2.5 && forwJet.Pt() > 30.0 && forwJet.E() > 300.0){
        
        forwJet_Pt->Fill(forwJet.Pt());
        forwJet_Eta->Fill(forwJet.Eta());
        forwJet_Phi->Fill(forwJet.Phi());

        }

        
    
        if(W_j1.Pt() > 25 && abs(W_j1.Eta()) < 2.5 && W_j2.Pt() > 25 && abs(W_j2.Eta()) < 2.5){
            
            top_reco_mass->Fill(top_reco.M());
            W_jet1_Pt->Fill(W_j1.Pt());
            W_jet1_Eta->Fill(W_j1.Eta());
            W_jet1_Phi->Fill(W_j1.Phi());
            W_jet2_Pt->Fill(W_j2.Pt());
            W_jet2_Eta->Fill(W_j2.Eta());
            W_jet2_Phi->Fill(W_j2.Phi());
           // W_boson_reco_mass->Fill(W_boson_top_reco.M());
           // W_top_mass->Fill(W_boson_top.M());
        }
        
        

       // No_of_Jet->Fill(Jet_size);
        No_of_electron->Fill(Electron_size);
        No_of_muon->Fill(Muon_size);
        No_of_electron_plus_muon->Fill(Electron_size + Muon_size);
        
        //if(Met.Pt() > 80 && abs(Met.Eta()) < 5){

        Met_met->Fill(Met.Pt());
       // Met_Eta->Fill(Met.Eta());
        Met_Phi->Fill(Met.Phi());

        //}
        
        
        
        if(W_j1.Pt() > 25 && abs(W_j1.Eta()) < 2.5 && abs(forwJet.Eta()) > 2.5 && forwJet.Pt() > 30.0 && forwJet.E() > 300.0){

          deltaEta_W_jet1_forw->Fill(W_j1.Eta() - forwJet.Eta());
          deltaPhi_W_jet1_forw->Fill(W_j1.DeltaPhi(forwJet));
          deltaR_W_jet1_forw->Fill(W_j1.DeltaR(forwJet));
        }
        
        if(W_j2.Pt() > 25 && abs(W_j2.Eta()) < 2.5 && abs(forwJet.Eta()) > 2.5 && forwJet.Pt() > 30.0 && forwJet.E() > 300.0){

          deltaEta_W_jet2_forw->Fill(W_j2.Eta() - forwJet.Eta());
          deltaPhi_W_jet2_forw->Fill(W_j2.DeltaPhi(forwJet));
          deltaR_W_jet2_forw->Fill(W_j2.DeltaR(forwJet));
        }

        if(abs(forwJet.Eta()) > 2.5 && forwJet.Pt() > 30.0 && forwJet.E() > 300.0){

          deltaEta_b_quark_forw->Fill(bTag.Eta() - forwJet.Eta());
          deltaPhi_b_quark_forw->Fill(bTag.DeltaPhi(forwJet));
          deltaR_b_quark_forw->Fill(bTag.DeltaR(forwJet));
        }        
        

        if(abs(forwJet.Eta()) > 2.5 && forwJet.Pt() > 30.0 && forwJet.E() > 300.0 && W_j1.Pt() > 25 && abs(W_j1.Eta()) < 2.5 && W_j2.Pt() > 25 && abs(W_j2.Eta()) < 2.5){

          deltaEta_W_top_forw->Fill(W_boson_top_reco.Eta() - forwJet.Eta());   

        }
    }

    //------------------------------------------------------------------------------------------------------------------------------------------------------------------

    TFile outputFile1("outputFile_scale_1lakh_with_cut.root", "recreate");
    // if (Jet_size == 3 && Electron_size == 3 && MissingET_size == 1 && b_Jets.size() == 1)
    //{

    /*top_reco_mass->Scale(1.0 / top_reco_mass->Integral());
    //  top_pt->Scale(1.0/top_pt->Integral());
    W_boson_lep_reco_mass->Scale(1.0 / W_boson_lep_reco_mass->Integral());
    Z_mass->Scale(1.0 / Z_mass->Integral());
    btag_Pt->Scale(1.0 / btag_Pt->Integral());
    btag_Eta->Scale(1.0 / btag_Eta->Integral());
    btag_Phi->Scale(1.0 / btag_Phi->Integral());
    forwJet_Pt->Scale(1.0 / forwJet_Pt->Integral());
    forwJet_Eta->Scale(1.0 / forwJet_Eta->Integral());
    forwJet_Phi->Scale(1.0 / forwJet_Phi->Integral());*/
    /*jet2_Pt->Scale(1.0 / jet2_Pt->Integral());
    jet2_Eta->Scale(1.0 / jet2_Eta->Integral());
    jet2_Phi->Scale(1.0 / jet2_Phi->Integral());
    jet3_Pt->Scale(1.0 / jet3_Pt->Integral());
    jet3_Eta->Scale(1.0 / jet3_Eta->Integral());
    jet3_Phi->Scale(1.0 / jet3_Phi->Integral());*/
    /*W_jet1_Pt->Scale(1.0 / W_jet1_Pt->Integral());
    W_jet1_Eta->Scale(1.0 / W_jet1_Eta->Integral());
    W_jet1_Phi->Scale(1.0 / W_jet1_Phi->Integral());
    W_jet2_Pt->Scale(1.0 / W_jet2_Pt->Integral());
    W_jet2_Eta->Scale(1.0 / W_jet2_Eta->Integral());
    W_jet2_Phi->Scale(1.0 / W_jet2_Phi->Integral());
    W_e1_Pt->Scale(1.0 / W_e1_Pt->Integral());
    W_e1_Eta->Scale(1.0 / W_e1_Eta->Integral());
    W_e1_Phi->Scale(1.0 / W_e1_Phi->Integral());
    Z_e1_Pt->Scale(1.0 / Z_e1_Pt->Integral());
    Z_e1_Eta->Scale(1.0 / Z_e1_Eta->Integral());
    Z_e1_Phi->Scale(1.0 / Z_e1_Phi->Integral());
    Z_e2_Pt->Scale(1.0 / Z_e2_Pt->Integral());
    Z_e2_Eta->Scale(1.0 / Z_e2_Eta->Integral());
    Z_e2_Phi->Scale(1.0 / Z_e2_Phi->Integral());
    Met_met->Scale(1.0 / Met_met->Integral());
    Met_Eta->Scale(1.0 / Met_Eta->Integral());
    Met_Phi->Scale(1.0 / Met_Phi->Integral());
    W_top_mass->Scale(1.0 / W_top_mass->Integral());
    W_boson_reco_mass->Scale(1.0 / W_boson_reco_mass->Integral());
    Z_boson_reco_mass->Scale(1.0 / Z_boson_reco_mass->Integral());
    deltaEta_W_jet1_forw->Scale(1.0 / deltaEta_W_jet1_forw->Integral());
    deltaEta_W_jet2_forw->Scale(1.0 / deltaEta_W_jet2_forw->Integral());
    deltaEta_b_quark_forw->Scale(1.0 / deltaEta_b_quark_forw->Integral());
    deltaPhi_W_jet1_forw->Scale(1.0 / deltaPhi_W_jet1_forw->Integral());
    deltaPhi_W_jet2_forw->Scale(1.0 / deltaPhi_W_jet2_forw->Integral());
    deltaPhi_b_quark_forw->Scale(1.0 / deltaPhi_b_quark_forw->Integral());
    deltaR_W_jet1_forw->Scale(1.0 / deltaR_W_jet1_forw->Integral());
    deltaR_W_jet2_forw->Scale(1.0 / deltaR_W_jet2_forw->Integral());
    deltaR_b_quark_forw->Scale(1.0 / deltaR_b_quark_forw->Integral());
    deltaEta_W_top_forw->Scale(1.0 / deltaEta_W_top_forw->Integral());*/

    //*******************************************************************************************************************************************************************

    // double norm = (7.933E-05 * 1000 * 100) / 100000; // Integrated luminosity = 100 fb-1
    // double norm = (7.933E-05 * 1000 * 10)/100000 ; //Integrated luminosity = 10 fb-1

    /*top_mass->Scale(norm * (top_mass->GetEntries()));
    btag_Pt->Scale(norm * (btag_Pt->GetEntries()));
    btag_Eta->Scale(norm * (btag_Eta->GetEntries()));
    btag_Phi->Scale(norm * (btag_Phi->GetEntries()));
    jet1_Pt->Scale(norm * (jet1_Pt->GetEntries()));
    jet1_Eta->Scale(norm * (jet1_Eta->GetEntries()));
    jet1_Phi->Scale(norm * (jet1_Phi->GetEntries()));
    jet2_Pt->Scale(norm * (jet2_Pt->GetEntries()));
    jet2_Eta->Scale(norm * (jet2_Eta->GetEntries()));
    jet2_Phi->Scale(norm * (jet2_Phi->GetEntries()));
    jet3_Pt->Scale(norm * (jet3_Pt->GetEntries()));
    jet3_Eta->Scale(norm * (jet3_Eta->GetEntries()));
    jet3_Phi->Scale(norm * (jet3_Phi->GetEntries()));
    electron1_Pt->Scale(norm * (electron1_Pt->GetEntries()));
    electron1_Eta->Scale(norm * (electron1_Eta->GetEntries()));
    electron1_Phi->Scale(norm * (electron1_Phi->GetEntries()));
    electron2_Pt->Scale(norm * (electron2_Pt->GetEntries()));
    electron2_Eta->Scale(norm * (electron2_Eta->GetEntries()));
    electron2_Phi->Scale(norm * (electron2_Phi->GetEntries()));
    electron3_Pt->Scale(norm * (electron3_Pt->GetEntries()));
    electron3_Eta->Scale(norm * (electron3_Eta->GetEntries()));
    electron3_Phi->Scale(norm * (electron3_Phi->GetEntries()));
    Met_met->Scale(norm * (Met_met->GetEntries()));
    Met_Eta->Scale(norm * (Met_Eta->GetEntries()));
    Met_Phi->Scale(norm * (Met_Phi->GetEntries()));*/

    //  top_mass->Write();
    top_reco_mass->Write();
    W_boson_transverse_mass->Write();
    Z_mass->Write();
    btag_Pt->Write();
    btag_Eta->Write();
    btag_Phi->Write();
    W_e1_Pt->Write();
    W_e1_Eta->Write();
    W_e1_Phi->Write();
    Z_e1_Pt->Write();
    Z_e1_Eta->Write();
    Z_e1_Phi->Write();
    Z_e2_Pt->Write();
    Z_e2_Eta->Write();
    Z_e2_Phi->Write();
    forwJet_Pt->Write();
    forwJet_Eta->Write();
    forwJet_Phi->Write();
    Met_met->Write();
   // Met_Eta->Write();
    Met_Phi->Write();
    No_of_Jet->Write();
   // No_of_b_Jet->Write();
    No_of_electron->Write();
    No_of_muon->Write();
    No_of_electron_plus_muon->Write();
    W_jet1_Pt->Write();
     W_jet1_Eta->Write();
     W_jet1_Phi->Write();
     W_jet2_Pt->Write();
     W_jet2_Eta->Write();
     W_jet2_Phi->Write();
   // W_top_mass->Write();
   // W_boson_reco_mass->Write();
   // Z_boson_reco_mass->Write();
    deltaEta_W_jet1_forw->Write();
    deltaEta_W_jet2_forw->Write();
    deltaEta_b_quark_forw->Write();
    deltaPhi_W_jet1_forw->Write();
    deltaPhi_W_jet2_forw->Write();
    deltaPhi_b_quark_forw->Write();
    deltaR_W_jet1_forw->Write();
    deltaR_W_jet2_forw->Write();
    deltaR_b_quark_forw->Write();
    deltaEta_W_top_forw->Write();
    //    double norm = (0.003741E-06*1000*200);   //Integrated luminosity = 200 fb-1 ;

   // cout << "Integral............" << btag_Pt->Integral() <<"\n";

    outputFile1.Close();
    //}

    //}

    TCanvas *c1 = new TCanvas();
    //gStyle -> SetOptStat(0);
    top_reco_mass->Draw();
    c1->SaveAs("top_reco_mass.png");

    TCanvas *c2 = new TCanvas();

    W_boson_transverse_mass->Draw();
    c2->SaveAs("W_boson_transverse_mass.png");

    TCanvas *c3 = new TCanvas();

    Z_mass->Draw();
    c3->SaveAs("Z_mass.png");

    TCanvas *c4 = new TCanvas();

    W_e1_Pt->Draw();
    c4->SaveAs("W_e1_Pt.png");

    TCanvas *c5 = new TCanvas();

    W_e1_Eta->Draw();
    c5->SaveAs("W_e1_Eta.png");

    TCanvas *c6 = new TCanvas();

    W_e1_Phi->Draw();
    c6->SaveAs("W_e1_Phi.png");

    TCanvas *c7 = new TCanvas();

    Met_met->Draw();
    c7->SaveAs("Met_met.png");

    TCanvas *c8 = new TCanvas();

    btag_Pt->Draw();
    c8->SaveAs("btag_Pt.png");

    TCanvas *c9 = new TCanvas();

    btag_Eta->Draw();
    c9->SaveAs("btag_Eta.png");

    TCanvas *c10 = new TCanvas();

    btag_Phi->Draw();
    c10->SaveAs("btag_Phi.png");

    TCanvas *c11 = new TCanvas();

    No_of_electron_plus_muon->Draw();
    c11->SaveAs("No_of_electron_plus_muon.png");

   /* TCanvas *c12 = new TCanvas();

    jet2_Eta->Draw();
    c12->SaveAs("jet2_Eta.png");

    TCanvas *c13 = new TCanvas();

    jet2_Phi->Draw();
    c13->SaveAs("jet2_Phi.png");*/

    TCanvas *c14 = new TCanvas();

    W_jet1_Pt->Draw();
    c14->SaveAs("W_jet1_Pt.png");

    TCanvas *c15 = new TCanvas();

    W_jet1_Eta->Draw();
    c15->SaveAs("W_jet1_Eta.png");

    TCanvas *c16 = new TCanvas();

    W_jet1_Phi->Draw();
    c16->SaveAs("W_jet1_Phi.png");

    TCanvas *c17 = new TCanvas();

    W_jet2_Pt->Draw();
    c17->SaveAs("W_jet2_Pt.png");

    TCanvas *c18 = new TCanvas();

    W_jet2_Eta->Draw();
    c18->SaveAs("W_jet2_Eta.png");

    TCanvas *c19 = new TCanvas();

    W_jet2_Phi->Draw();
    c19->SaveAs("W_jet2_Phi.png");

    TCanvas *c20 = new TCanvas();

    Z_e1_Pt->Draw();
    c20->SaveAs("Z_e1_Pt.png");

    TCanvas *c21 = new TCanvas();

    Z_e1_Eta->Draw();
    c21->SaveAs("Z_e1_Eta.png");

    TCanvas *c22 = new TCanvas();

    Z_e1_Phi->Draw();
    c22->SaveAs("Z_e1_Phi.png");

    TCanvas *c23 = new TCanvas();

    Z_e2_Pt->Draw();
    c20->SaveAs("Z_e2_Pt.png");

    TCanvas *c24 = new TCanvas();

    Z_e2_Eta->Draw();
    c24->SaveAs("Z_e2_Eta.png");

    TCanvas *c25 = new TCanvas();

    Z_e2_Phi->Draw();
    c25->SaveAs("Z_e2_Phi.png");

    TCanvas *c26 = new TCanvas();

    Met_Eta->Draw();
    c26->SaveAs("Met_Eta.png");

    TCanvas *c27 = new TCanvas();

    Met_Phi->Draw();
    c27->SaveAs("Met_Phi.png");

    TCanvas *c28 = new TCanvas();

    W_top_mass->Draw();
    c28->SaveAs("W_top_mass.png");

    TCanvas *c29 = new TCanvas();

    forwJet_Pt->Draw();
    c29->SaveAs("forwJet_Pt.png");

    TCanvas *c30 = new TCanvas();

    forwJet_Eta->Draw();
    c30->SaveAs("forwJet_Eta.png");

    TCanvas *c31 = new TCanvas();

    forwJet_Phi->Draw();
    c31->SaveAs("forwJet_Phi.png");

    TCanvas *c32 = new TCanvas();

    W_boson_reco_mass->Draw();
    c32->SaveAs("W_boson_reco_mass.png");

    TCanvas *c33 = new TCanvas();

    No_of_Jet->Draw();
    c33->SaveAs("No_of_Jet.png");

    TCanvas *c34 = new TCanvas();

    No_of_electron->Draw();
    c34->SaveAs("No_of_electron.png");

    TCanvas *c35 = new TCanvas();

    No_of_muon->Draw();
    c35->SaveAs("No_of_muon.png");

    TCanvas *c36 = new TCanvas();

    Z_boson_reco_mass->Draw();
    c36->SaveAs("Z_boson_reco_mass.png");

    TCanvas *c37 = new TCanvas();

    deltaEta_W_jet1_forw->Draw();
    c37->SaveAs("deltaEta_W_jet1_forw.png");

    TCanvas *c38 = new TCanvas();

    deltaEta_W_jet2_forw->Draw();
    c38->SaveAs("deltaEta_W_jet2_forw.png");

    TCanvas *c39 = new TCanvas();

    deltaEta_b_quark_forw->Draw();
    c39->SaveAs("deltaEta_b_quark_forw.png");

    TCanvas *c40 = new TCanvas();

    deltaPhi_W_jet1_forw->Draw();
    c40->SaveAs("deltaPhi_W_jet1_forw.png");

    TCanvas *c41 = new TCanvas();

    deltaPhi_W_jet2_forw->Draw();
    c41->SaveAs("deltaPhi_W_jet2_forw.png");

    TCanvas *c42 = new TCanvas();

    deltaPhi_b_quark_forw->Draw();
    c42->SaveAs("deltaPhi_b_quark_forw.png");

    TCanvas *c43 = new TCanvas();

    deltaR_W_jet1_forw->Draw();
    c43->SaveAs("deltaR_W_jet1_forw.png");

    TCanvas *c44 = new TCanvas();

    deltaR_W_jet2_forw->Draw();
    c44->SaveAs("deltaR_W_jet2_forw.png");

    TCanvas *c45 = new TCanvas();

    deltaR_b_quark_forw->Draw();
    c45->SaveAs("deltaR_b_quark_forw.png");

    TCanvas *c46 = new TCanvas();

    deltaEta_W_top_forw->Draw();
    c46->SaveAs("deltaEta_W_top_forw.png");

    TCanvas *c47 = new TCanvas();

    No_of_b_Jet->Draw();
    c47->SaveAs("No_of_b_Jet.png");

    f->Close();
}
