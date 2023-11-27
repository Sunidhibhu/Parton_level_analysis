#include <TLegend.h>

void ComparePlots()


{

 // TH1D *jet1_Pt_compare = new TH1D("jet1_Pt_compare ", "jet1_Pt_compare ", 50, 1, 800);
  TFile *f1 = new TFile("outputFile_scale_44lakh_cut.root");
  
  TH1D *jet1_Pt_Detector_level = dynamic_cast<TH1D*>(f1->Get("jet1_Pt"));
  TH1D *jet1_Eta_Detector_level = dynamic_cast<TH1D*>(f1->Get("jet1_Eta"));
  TH1D *jet1_Phi_Detector_level = dynamic_cast<TH1D*>(f1->Get("jet1_Phi"));
  TH1D *jet2_Pt_Detector_level = dynamic_cast<TH1D*>(f1->Get("jet2_Pt"));
  TH1D *jet2_Eta_Detector_level = dynamic_cast<TH1D*>(f1->Get("jet2_Eta"));
  TH1D *jet2_Phi_Detector_level = dynamic_cast<TH1D*>(f1->Get("jet2_Phi"));
  TH1D *jet3_Pt_Detector_level = dynamic_cast<TH1D*>(f1->Get("jet3_Pt"));
  TH1D *jet3_Eta_Detector_level = dynamic_cast<TH1D*>(f1->Get("jet3_Eta"));
  TH1D *jet3_Phi_Detector_level = dynamic_cast<TH1D*>(f1->Get("jet3_Phi"));
  TH1D *bTag_Pt_Detector_level = dynamic_cast<TH1D*>(f1->Get("btag_Pt"));
  TH1D *bTag_Eta_Detector_level = dynamic_cast<TH1D*>(f1->Get("btag_Eta"));
  TH1D *bTag_Phi_Detector_level = dynamic_cast<TH1D*>(f1->Get("btag_Phi"));
  TH1D *electron1_Pt_Detector_level = dynamic_cast<TH1D*>(f1->Get("electron1_Pt"));
  TH1D *electron1_Eta_Detector_level = dynamic_cast<TH1D*>(f1->Get("electron1_Eta"));
  TH1D *electron1_Phi_Detector_level = dynamic_cast<TH1D*>(f1->Get("electron1_Phi"));
  TH1D *electron2_Pt_Detector_level = dynamic_cast<TH1D*>(f1->Get("electron2_Pt"));
  TH1D *electron2_Eta_Detector_level = dynamic_cast<TH1D*>(f1->Get("electron2_Eta"));
  TH1D *electron2_Phi_Detector_level = dynamic_cast<TH1D*>(f1->Get("electron2_Phi"));
  TH1D *electron3_Pt_Detector_level = dynamic_cast<TH1D*>(f1->Get("electron3_Pt"));
  TH1D *electron3_Eta_Detector_level = dynamic_cast<TH1D*>(f1->Get("electron3_Eta"));
  TH1D *electron3_Phi_Detector_level = dynamic_cast<TH1D*>(f1->Get("electron3_Phi"));
  TH1D *Met_met_Detector_level = dynamic_cast<TH1D*>(f1->Get("Met_met"));
  TH1D *Met_Eta_Detector_level = dynamic_cast<TH1D*>(f1->Get("Met_Eta"));
  TH1D *Met_Phi_Detector_level = dynamic_cast<TH1D*>(f1->Get("Met_Phi"));
 // jet1_Pt_compare->Write();
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------  
  
 TFile *f2 = new TFile("file2_scale_44lakh_cut.root");

TH1D *h_quarks1_Pt_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_quarks1_Pt"));
TH1D *h_quarks1_Eta_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_quarks1_Eta"));
TH1D *h_quarks1_Phi_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_quarks1_Phi"));
TH1D *h_quarks2_Pt_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_quarks2_Pt"));
TH1D *h_quarks2_Phi_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_quarks2_Phi"));
TH1D *h_quarks2_Eta_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_quarks2_Eta"));
TH1D *h_b_quark_Pt_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_b_quark_Pt"));
TH1D *h_b_quark_Eta_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_b_quark_Eta"));
TH1D *h_b_quark_Phi_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_b_quark_Phi"));
TH1D *h_MET_Pt_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_MET_Pt"));
TH1D *h_MET_Eta_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_MET_Eta"));
TH1D *h_MET_Phi_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_MET_Phi"));
TH1D *h_forw_jet_Pt_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_forw_jet_Pt"));
TH1D *h_forw_jet_Eta_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_forw_jet_Eta"));
TH1D *h_forw_jet_Phi_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_forw_jet_Phi"));
TH1D *h_lepton1_Pt_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_lepton1_Pt"));
TH1D *h_lepton1_Eta_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_lepton1_Eta"));
TH1D *h_lepton1_Phi_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_lepton1_Phi"));
TH1D *h_lepton2_Pt_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_lepton2_Pt"));
TH1D *h_lepton2_Eta_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_lepton2_Eta"));
TH1D *h_lepton2_Phi_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_lepton2_Phi"));
TH1D *h_lepton3_Pt_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_lepton3_Pt"));
TH1D *h_lepton3_Eta_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_lepton3_Eta"));
TH1D *h_lepton3_Phi_Parton_level = dynamic_cast<TH1D*>(f2->Get("h_lepton3_Phi")); 
  
//----------------------------------------------------------------------------------------------------------------------------------------------------------------- 
  
TCanvas *c1 = new TCanvas();

//jet1_Pt_Detector_level->Scale(1.0/jet1_Pt_Detector_level->Integral());
//h_forw_jet_Pt_Parton_level->Scale(1.0/h_forw_jet_Pt_Parton_level->Integral());
jet1_Pt_Detector_level->Draw("hist");
h_forw_jet_Pt_Parton_level->Draw("same:hist"); 
jet1_Pt_Detector_level->SetLineColor(kBlue);
h_forw_jet_Pt_Parton_level->SetLineColor(kRed); 

TLegend *legend1 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend1->AddEntry(jet1_Pt_Detector_level, "jet1_Pt_Detector_level", "l");
    legend1->AddEntry(h_forw_jet_Pt_Parton_level, "h_forw_jet_Pt_Parton_level", "l");
    legend1->Draw();

c1->Update();    
c1->SaveAs("jet1_Pt_compare.png");

//------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c2 = new TCanvas();

jet1_Eta_Detector_level->Draw("hist");
h_forw_jet_Eta_Parton_level->Draw("same:hist"); 
jet1_Eta_Detector_level->SetLineColor(kBlue);
h_forw_jet_Eta_Parton_level->SetLineColor(kRed);

TLegend *legend2 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend2->AddEntry(jet1_Eta_Detector_level, "jet1_Eta_Detector_level", "l");
    legend2->AddEntry(h_forw_jet_Eta_Parton_level, "h_forw_jet_Eta_Parton_level", "l");
    legend2->Draw();

c2->Update();    
c2->SaveAs("jet1_Eta_compare.png");

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c3 = new TCanvas();

jet1_Phi_Detector_level->Draw("hist");
h_forw_jet_Phi_Parton_level->Draw("same:hist");
jet1_Phi_Detector_level->SetLineColor(kBlue);
h_forw_jet_Phi_Parton_level->SetLineColor(kRed);


TLegend *legend3 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend3->AddEntry(jet1_Phi_Detector_level, "jet1_Phi_Detector_level", "l");
    legend3->AddEntry(h_forw_jet_Phi_Parton_level, "h_forw_jet_Phi_Parton_level", "l");
    legend3->Draw();

c3->Update();    
c3->SaveAs("jet1_Phi_compare.png");

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c4 = new TCanvas();


h_quarks1_Pt_Parton_level->Draw("hist"); 
jet2_Pt_Detector_level->Draw("same:hist");
jet2_Pt_Detector_level->SetLineColor(kBlue);
h_quarks1_Pt_Parton_level->SetLineColor(kRed);



TLegend *legend4 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend4->AddEntry(jet2_Pt_Detector_level, "jet2_Pt_Detector_level", "l");
    legend4->AddEntry(h_quarks1_Pt_Parton_level, "h_quarks1_Pt_Parton_level", "l");
    legend4->Draw();

c4->Update();    
c4->SaveAs("jet2_Pt_compare.png");

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c5 = new TCanvas();

jet2_Eta_Detector_level->Draw("hist");
h_quarks1_Eta_Parton_level->Draw("same:hist");
jet2_Eta_Detector_level->SetLineColor(kBlue);
h_quarks1_Eta_Parton_level->SetLineColor(kRed);

TLegend *legend5 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend5->AddEntry(jet2_Eta_Detector_level, "jet2_Eta_Detector_level", "l");
    legend5->AddEntry(h_quarks1_Eta_Parton_level, "h_quarks1_Eta_Parton_level", "l");
    legend5->Draw();

c5->Update();    
c5->SaveAs("jet2_Eta_compare.png");

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c6 = new TCanvas();

jet2_Phi_Detector_level->Draw("hist");
h_quarks1_Phi_Parton_level->Draw("same:hist"); 
jet2_Phi_Detector_level->SetLineColor(kBlue);
h_quarks1_Phi_Parton_level->SetLineColor(kRed);


TLegend *legend6 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend6->AddEntry(jet2_Phi_Detector_level, "jet2_Phi_Detector_level", "l");
    legend6->AddEntry(h_quarks1_Phi_Parton_level, "h_quarks1_Phi_Parton_level", "l");
    legend6->Draw();

c6->Update();    
c6->SaveAs("jet2_Phi_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c7 = new TCanvas();

jet3_Pt_Detector_level->Draw("hist");
h_quarks2_Pt_Parton_level->Draw("same:hist");
jet3_Pt_Detector_level->SetLineColor(kBlue);
h_quarks2_Pt_Parton_level->SetLineColor(kRed);


TLegend *legend7 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend7->AddEntry(jet3_Pt_Detector_level, "jet3_Pt_Detector_level", "l");
    legend7->AddEntry(h_quarks2_Pt_Parton_level, "h_quarks2_Pt_Parton_level", "l");
    legend7->Draw();

c7->Update();    
c7->SaveAs("jet3_Pt_compare.png");

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c8 = new TCanvas();

jet3_Eta_Detector_level->Draw("hist");
h_quarks2_Eta_Parton_level->Draw("same:hist"); 
jet3_Eta_Detector_level->SetLineColor(kBlue);
h_quarks2_Eta_Parton_level->SetLineColor(kRed);


TLegend *legend8 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend8->AddEntry(jet3_Eta_Detector_level, "jet3_Eta_Detector_level", "l");
    legend8->AddEntry(h_quarks2_Eta_Parton_level, "h_quarks2_Eta_Parton_level", "l");
    legend8->Draw();

c8->Update();    
c8->SaveAs("jet3_Eta_compare.png");

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c9 = new TCanvas();

jet3_Phi_Detector_level->Draw("hist");
h_quarks2_Phi_Parton_level->Draw("same:hist"); 
jet3_Phi_Detector_level->SetLineColor(kBlue);
h_quarks2_Phi_Parton_level->SetLineColor(kRed);

TLegend *legend9 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend9->AddEntry(jet3_Phi_Detector_level, "jet3_Phi_Detector_level", "l");
    legend9->AddEntry(h_quarks2_Phi_Parton_level, "h_quarks2_Phi_Parton_level", "l");
    legend9->Draw();

c9->Update();    
c9->SaveAs("jet3_Phi_compare.png");

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c10 = new TCanvas();

bTag_Pt_Detector_level->Draw("hist"); 
h_b_quark_Pt_Parton_level->Draw("same:hist");

bTag_Pt_Detector_level->SetLineColor(kBlue);
h_b_quark_Pt_Parton_level->SetLineColor(kRed); 

TLegend *legend10 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend10->AddEntry(bTag_Pt_Detector_level, "bTag_Pt_Detector_level", "l");
    legend10->AddEntry(h_b_quark_Pt_Parton_level, "h_b_quark_Pt_Parton_level", "l");
    legend10->Draw();

c10->Update();    
c10->SaveAs("bTag_Pt_compare.png");

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c11 = new TCanvas();


h_b_quark_Eta_Parton_level->Draw("hist");
bTag_Eta_Detector_level->Draw("same:hist");
bTag_Eta_Detector_level->SetLineColor(kBlue);
h_b_quark_Eta_Parton_level->SetLineColor(kRed); 

TLegend *legend11 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend11->AddEntry(bTag_Eta_Detector_level, "bTag_Eta_Detector_level", "l");
    legend11->AddEntry(h_b_quark_Eta_Parton_level, "h_b_quark_Eta_Parton_level", "l");
    legend11->Draw();

c11->Update();    
c11->SaveAs("bTag_Eta_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c12 = new TCanvas();


h_b_quark_Phi_Parton_level->Draw("hist");
bTag_Phi_Detector_level->Draw("same:hist");
bTag_Phi_Detector_level->SetLineColor(kBlue);
h_b_quark_Phi_Parton_level->SetLineColor(kRed);

TLegend *legend12 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend12->AddEntry(bTag_Phi_Detector_level, "bTag_Phi_Detector_level", "l");
    legend12->AddEntry(h_b_quark_Phi_Parton_level, "h_b_quark_Phi_Parton_level", "l");
    legend12->Draw();

c12->Update();    
c12->SaveAs("bTag_Phi_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c13 = new TCanvas();


h_lepton1_Pt_Parton_level->Draw("hist");
electron1_Pt_Detector_level->Draw("same:hist"); 
electron1_Pt_Detector_level->SetLineColor(kBlue);
h_lepton1_Pt_Parton_level->SetLineColor(kRed); 

TLegend *legend13 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend13->AddEntry(electron1_Pt_Detector_level, "electron1_Pt_Detector_level", "l");
    legend13->AddEntry(h_lepton1_Pt_Parton_level, "h_lepton1_Pt_Parton_level", "l");
    legend13->Draw();

c13->Update();    
c13->SaveAs("electron1_Pt_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c14 = new TCanvas();


h_lepton1_Eta_Parton_level->Draw("hist");
electron1_Eta_Detector_level->Draw("same:hist"); 
electron1_Eta_Detector_level->SetLineColor(kBlue);
h_lepton1_Eta_Parton_level->SetLineColor(kRed);

TLegend *legend14 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend14->AddEntry(electron1_Eta_Detector_level, "electron1_Eta_Detector_level", "l");
    legend14->AddEntry(h_lepton1_Eta_Parton_level, "h_lepton1_Eta_Parton_level", "l");
    legend14->Draw();

c14->Update();    
c14->SaveAs("electron1_Eta_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c15 = new TCanvas();

electron1_Phi_Detector_level->Draw("hist");
h_lepton1_Phi_Parton_level->Draw("same:hist"); 
electron1_Phi_Detector_level->SetLineColor(kBlue);
h_lepton1_Phi_Parton_level->SetLineColor(kRed);

TLegend *legend15 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend15->AddEntry(electron1_Phi_Detector_level, "electron1_Phi_Detector_level", "l");
    legend15->AddEntry(h_lepton1_Phi_Parton_level, "h_lepton1_Phi_Parton_level", "l");
    legend15->Draw();

c15->Update();    
c15->SaveAs("electron1_Phi_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c16 = new TCanvas();


h_lepton2_Pt_Parton_level->Draw("hist");
electron2_Pt_Detector_level->Draw("same:hist"); 
electron2_Pt_Detector_level->SetLineColor(kBlue);
h_lepton2_Pt_Parton_level->SetLineColor(kRed); 

TLegend *legend16 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend16->AddEntry(electron2_Pt_Detector_level, "electron2_Pt_Detector_level", "l");
    legend16->AddEntry(h_lepton2_Pt_Parton_level, "h_lepton2_Pt_Parton_level", "l");
    legend16->Draw();

c16->Update();    
c16->SaveAs("electron2_Pt_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c17 = new TCanvas();

electron2_Eta_Detector_level->Draw("hist");
h_lepton2_Eta_Parton_level->Draw("same:hist"); 
electron2_Eta_Detector_level->SetLineColor(kBlue);
h_lepton2_Eta_Parton_level->SetLineColor(kRed);

TLegend *legend17 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend17->AddEntry(electron2_Eta_Detector_level, "electron2_Eta_Detector_level", "l");
    legend17->AddEntry(h_lepton2_Eta_Parton_level, "h_lepton2_Eta_Parton_level", "l");
    legend17->Draw();

c17->Update();    
c17->SaveAs("electron2_Eta_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c18 = new TCanvas();

electron2_Phi_Detector_level->Draw("hist");
h_lepton2_Phi_Parton_level->Draw("same:hist"); 
electron2_Phi_Detector_level->SetLineColor(kBlue);
h_lepton2_Phi_Parton_level->SetLineColor(kRed);

TLegend *legend18 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend18->AddEntry(electron2_Phi_Detector_level, "electron2_Phi_Detector_level", "l");
    legend18->AddEntry(h_lepton2_Phi_Parton_level, "h_lepton2_Phi_Parton_level", "l");
    legend18->Draw();

c18->Update();    
c18->SaveAs("electron2_Phi_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c19 = new TCanvas();

electron3_Pt_Detector_level->Draw("hist");
h_lepton3_Pt_Parton_level->Draw("same:hist"); 
electron3_Pt_Detector_level->SetLineColor(kBlue);
h_lepton3_Pt_Parton_level->SetLineColor(kRed); 

TLegend *legend19 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend19->AddEntry(electron3_Pt_Detector_level, "electron3_Pt_Detector_level", "l");
    legend19->AddEntry(h_lepton3_Pt_Parton_level, "h_lepton3_Pt_Parton_level", "l");
    legend19->Draw();

c19->Update();    
c19->SaveAs("electron3_Pt_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c20 = new TCanvas();

electron3_Eta_Detector_level->Draw("hist");
h_lepton3_Eta_Parton_level->Draw("same:hist"); 
electron3_Eta_Detector_level->SetLineColor(kBlue);
h_lepton3_Eta_Parton_level->SetLineColor(kRed);

TLegend *legend20 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend20->AddEntry(electron3_Eta_Detector_level, "electron3_Eta_Detector_level", "l");
    legend20->AddEntry(h_lepton3_Eta_Parton_level, "h_lepton3_Eta_Parton_level", "l");
    legend20->Draw();

c20->Update();    
c20->SaveAs("electron3_Eta_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c21 = new TCanvas();

electron3_Phi_Detector_level->Draw("hist");
h_lepton3_Phi_Parton_level->Draw("same:hist"); 
electron3_Phi_Detector_level->SetLineColor(kBlue);
h_lepton3_Phi_Parton_level->SetLineColor(kRed);

TLegend *legend21 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend21->AddEntry(electron3_Phi_Detector_level, "electron3_Phi_Detector_level", "l");
    legend21->AddEntry(h_lepton3_Phi_Parton_level, "h_lepton3_Phi_Parton_level", "l");
    legend21->Draw();

c21->Update();    
c21->SaveAs("electron3_Phi_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c22 = new TCanvas();


h_MET_Pt_Parton_level->Draw("hist"); 
Met_met_Detector_level->Draw("same:hist");
Met_met_Detector_level->SetLineColor(kBlue);
h_MET_Pt_Parton_level->SetLineColor(kRed); 

TLegend *legend22 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend22->AddEntry(Met_met_Detector_level, "Met_met_Detector_level", "l");
    legend22->AddEntry(h_MET_Pt_Parton_level, "h_MET_Pt_Parton_level", "l");
    legend22->Draw();

c22->Update();    
c22->SaveAs("Met_met_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c23 = new TCanvas();


h_MET_Eta_Parton_level->Draw("hist");
Met_Eta_Detector_level->Draw("same:hist"); 
Met_Eta_Detector_level->SetLineColor(kBlue);
h_MET_Eta_Parton_level->SetLineColor(kRed); 

TLegend *legend23 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend23->AddEntry(Met_Eta_Detector_level, "Met_Eta_Detector_level", "l");
    legend23->AddEntry(h_MET_Eta_Parton_level, "h_MET_Eta_Parton_level", "l");
    legend23->Draw();

c23->Update();    
c23->SaveAs("Met_Eta_compare.png");

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

TCanvas *c24 = new TCanvas();

Met_Phi_Detector_level->Draw("hist");
h_MET_Phi_Parton_level->Draw("same:hist"); 
Met_Phi_Detector_level->SetLineColor(kBlue);
h_MET_Phi_Parton_level->SetLineColor(kRed); 

TLegend *legend24 = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend24->AddEntry(Met_Phi_Detector_level, "Met_Phi_Detector_level", "l");
    legend24->AddEntry(h_MET_Phi_Parton_level, "h_MET_Phi_Parton_level", "l");
    legend24->Draw();

c24->Update();    
c24->SaveAs("Met_Phi_compare.png");

 
f1->Close();  
f2->Close();
  
}

