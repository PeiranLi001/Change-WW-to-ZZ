#include "TH1F.h"
#include "TH2F.h"
#include <vector>
#include "TLorentzVector.h"


void WWnewselection(){

  TFile *f1 = TFile::Open("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/GF_HH_SM_slc6_LHEBqrk.root");


  TTree *t1 = (TTree*)f1->Get("otree");
 
  //create histograms
  TH1F *AK4njet = new TH1F("AK4njet","AK4njet;number",30,0,30);
  TH1F *AK8njet = new TH1F("AK8njet","AK8njet;number",30,0,30);
  TH1F *AK8_HiggsJet_minDMass_M_WW = new TH1F("AK8_HiggsJet_minDMass_M_WW","AK8_HiggsJet_minDMass_M_WW;JetMass",100,0,400);
  TH1F *OneAK8TwoAK4_minMass_ReconsH_M_WW_1 = new TH1F("OneAK8TwoAK4_minMass_ReconsH_M_WW_1","OneAK8TwoAK4_minMass_ReconsH_M_WW_1;ReconHMass",100,-50,400);
  TH1F *OneAK8TwoAK4_minMass_ReconsH_M_WW_2 = new TH1F("OneAK8TwoAK4_minMass_ReconsH_M_WW_2","OneAK8TwoAK4_minMass_ReconsH_M_WW_2;ReconHMass",100,-50,400);
  TH1F *AK4_AllResolved_Higgs_M = new TH1F("AK4_AllResolved_Higgs_M","AK4_AllResolved_Higgs_M",100,0,400);
  
  //vector<int> *pdgID;
  
  double gen_HiggsGG_Pt;
  double gen_leading_photon_Pt;

  double gen_HiggsWW_Pt;
  double gen_HiggsWW_Eta;
  double gen_HiggsWW_Phi;
  double gen_deltaR_Wp_Wm;
  double gen_leading_WpJets_Pt;
  double gen_leading_WmJets_Pt;
  double gen_Subleading_WpJets_Pt;
  double gen_Subleading_WmJets_Pt;
  double gen_leading_WBoson_Pt;
  double gen_Subleading_WBoson_Pt;
  double gen_leading_WBoson_M;
  double gen_Subleading_WBoson_M;
  double gen_deltaR_WpJ0_WmJ0;
  double gen_deltaR_WpJ0_WmJ1;
  double gen_deltaR_WpJ1_WmJ0;
  double gen_deltaR_WpJ1_WmJ1;

  double gen_HiggsZZ_Pt;
  double gen_HiggsZZ_Eta;
  double gen_HiggsZZ_Phi;
  double gen_deltaR_Z1_Z2;
  double gen_leading_ZBoson_Pt;
  double gen_Subleading_ZBoson_Pt;
  double gen_leading_ZBoson_M;
  double gen_Subleading_ZBoson_M;
  double gen_deltaR_Z1J0_Z2J0;
  double gen_deltaR_Z1J0_Z2J1;
  double gen_deltaR_Z1J1_Z2J0;
  double gen_deltaR_Z1J1_Z2J1;
  

  double AK4GEN_AllResolved_dR_J1_onShell_q;
  double AK4GEN_AllResolved_dR_J2_onShell_q;
  double AK4GEN_AllResolved_dR_J3_offShell_q;
  double AK4GEN_AllResolved_dR_J4_offShell_q;
  double genJetAK4_njets;
  double genJetAK8_njets;
  double AK4GEN_AllResolved_onShellWboson_Pt;
  double AK4GEN_AllResolved_offShellWboson_Pt;
  double AK4GEN_AllResolved_onShellWboson_M;
  double AK4GEN_AllResolved_offShellWboson_M;
  double AK4GEN_AllResolved_Higgs_M;
  double AK4GEN_AllResolved_Higgs_Pt;
  double AK8Gen_MergedWjets_dR_MaxPt_Leading_W;
  double AK8Gen_MergedWjets_dR_MaxPt_SubLeading_W;
  double AK8Gen_MergedWjets_dR_minDMass_Leading_W;
  double AK8Gen_MergedWjets_dR_minDMass_SubLeading_W;
  double AK8Gen_MergedWjets_dR_minWminHmass_Leading_W;
  double AK8Gen_MergedWjets_dR_minWminHmass_SubLeading_W;
  double OneAK8TwoAK4_minMass_dR_ReconsW_AK4_W;
  double OneAK8TwoAK4_minMass_dR_AK8_W;
  double AK8Gen_HiggsJet_minDMass_deltaR_HWW;
  double AK8Gen_HiggsJet_minDMass_M;
  double AK8Gen_HiggsJet_minDMass_Pt;
  double AK8Gen_HiggsJet_minDMass_Eta;
  double AK8Gen_HiggsJet_minDMass_Phi;
  double AK8Gen_MergedWjets_minWminHmass_Leading_Pt;
  double AK8Gen_MergedWjets_minWminHmass_SubLeading_Pt;
  double AK8Gen_MergedWjets_minWminHmass_Higgs_Pt;
  double OneAK8TwoAK4_pTMax_leadingAK4_dR_q;
  double OneAK8TwoAK4_pTMax_subleadingAK4_dR_q;
  double OneAK8TwoAK4_minMass_ReconsH_M;
  double OneAK8TwoAK4_minMass_ReconsW_AK4_Pt;
  double OneAK8TwoAK4_minMass_ReconsW_AK4_M;
  double OneAK8TwoAK4_minMass_AK8_M;
  double OneAK8TwoAK4_minMass_AK8_Pt;

  double AK4GEN_AllResolved_onShellZboson_Pt;
  double AK4GEN_AllResolved_offShellZboson_Pt;
  double AK4GEN_AllResolved_onShellZboson_M;
  double AK4GEN_AllResolved_offShellZboson_M;
  double AK8Gen_MergedZjets_minZminHmass_Leading_Pt;
  double AK8Gen_MergedZjets_minZminHmass_SubLeading_Pt;
  double AK8Gen_MergedZjets_minZminHmass_Higgs_Pt;
  double OneAK8TwoAK4_minMass_ReconsZ_AK4_Pt;


  
  //t1->SetBranchAddress("pdgID", &pdgID);
  t1->SetBranchAddress("gen_HiggsGG_Pt",&gen_HiggsGG_Pt);
  t1->SetBranchAddress("gen_leading_photon_Pt",&gen_leading_photon_Pt);

  t1->SetBranchAddress("gen_HiggsWW_Pt",&gen_HiggsWW_Pt);
  t1->SetBranchAddress("gen_HiggsWW_Eta",&gen_HiggsWW_Eta);
  t1->SetBranchAddress("gen_HiggsWW_Phi",&gen_HiggsWW_Phi);
  t1->SetBranchAddress("gen_deltaR_Wp_Wm",&gen_deltaR_Wp_Wm);
  t1->SetBranchAddress("gen_leading_WpJets_Pt",&gen_leading_WpJets_Pt);
  t1->SetBranchAddress("gen_leading_WmJets_Pt",&gen_leading_WmJets_Pt);
  t1->SetBranchAddress("gen_Subleading_WpJets_Pt",&gen_Subleading_WpJets_Pt);
  t1->SetBranchAddress("gen_Subleading_WmJets_Pt",&gen_Subleading_WmJets_Pt);
  t1->SetBranchAddress("gen_leading_WBoson_Pt",&gen_leading_WBoson_Pt);
  t1->SetBranchAddress("gen_Subleading_WBoson_Pt",&gen_Subleading_WBoson_Pt);
  t1->SetBranchAddress("gen_leading_WBoson_M",&gen_leading_WBoson_M);
  t1->SetBranchAddress("gen_Subleading_WBoson_M",&gen_Subleading_WBoson_M);
  t1->SetBranchAddress("gen_deltaR_WpJ0_WmJ0",&gen_deltaR_WpJ0_WmJ0);
  t1->SetBranchAddress("gen_deltaR_WpJ0_WmJ1",&gen_deltaR_WpJ0_WmJ1);
  t1->SetBranchAddress("gen_deltaR_WpJ1_WmJ0",&gen_deltaR_WpJ1_WmJ0);
  t1->SetBranchAddress("gen_deltaR_WpJ1_WmJ1",&gen_deltaR_WpJ1_WmJ1);

  t1->SetBranchAddress("AK4GEN_AllResolved_dR_J1_onShell_q",&AK4GEN_AllResolved_dR_J1_onShell_q);
  t1->SetBranchAddress("AK4GEN_AllResolved_dR_J2_onShell_q",&AK4GEN_AllResolved_dR_J2_onShell_q);
  t1->SetBranchAddress("AK4GEN_AllResolved_dR_J3_offShell_q",&AK4GEN_AllResolved_dR_J3_offShell_q);
  t1->SetBranchAddress("AK4GEN_AllResolved_dR_J4_offShell_q",&AK4GEN_AllResolved_dR_J4_offShell_q);
  
  t1->SetBranchAddress("genJetAK4_njets",&genJetAK4_njets);
  t1->SetBranchAddress("genJetAK8_njets",&genJetAK8_njets);
  t1->SetBranchAddress("AK4GEN_AllResolved_onShellWboson_Pt",&AK4GEN_AllResolved_onShellWboson_Pt);
  t1->SetBranchAddress("AK4GEN_AllResolved_offShellWboson_Pt",&AK4GEN_AllResolved_offShellWboson_Pt);
  t1->SetBranchAddress("AK4GEN_AllResolved_onShellWboson_M",&AK4GEN_AllResolved_onShellWboson_M);
  t1->SetBranchAddress("AK4GEN_AllResolved_offShellWboson_M",&AK4GEN_AllResolved_offShellWboson_M);
  t1->SetBranchAddress("AK4GEN_AllResolved_Higgs_M",&AK4GEN_AllResolved_Higgs_M);
  t1->SetBranchAddress("AK4GEN_AllResolved_Higgs_Pt",&AK4GEN_AllResolved_Higgs_Pt);

  t1->SetBranchAddress("AK8Gen_HiggsJet_minDMass_deltaR_HWW",&AK8Gen_HiggsJet_minDMass_deltaR_HWW);
  t1->SetBranchAddress("AK8Gen_HiggsJet_minDMass_M",&AK8Gen_HiggsJet_minDMass_M);
  t1->SetBranchAddress("AK8Gen_HiggsJet_minDMass_Pt",&AK8Gen_HiggsJet_minDMass_Pt);
  t1->SetBranchAddress("AK8Gen_HiggsJet_minDMass_Eta",&AK8Gen_HiggsJet_minDMass_Eta);
  t1->SetBranchAddress("AK8Gen_HiggsJet_minDMass_Phi",&AK8Gen_HiggsJet_minDMass_Phi);
  t1->SetBranchAddress("AK8Gen_MergedWjets_dR_MaxPt_Leading_W",&AK8Gen_MergedWjets_dR_MaxPt_Leading_W);
  t1->SetBranchAddress("AK8Gen_MergedWjets_dR_MaxPt_SubLeading_W",&AK8Gen_MergedWjets_dR_MaxPt_SubLeading_W);
  t1->SetBranchAddress("AK8Gen_MergedWjets_dR_minDMass_Leading_W",&AK8Gen_MergedWjets_dR_minDMass_Leading_W);
  t1->SetBranchAddress("AK8Gen_MergedWjets_dR_minDMass_SubLeading_W",&AK8Gen_MergedWjets_dR_minDMass_SubLeading_W);
  t1->SetBranchAddress("AK8Gen_MergedWjets_dR_minWminHmass_Leading_W",&AK8Gen_MergedWjets_dR_minWminHmass_Leading_W);
  t1->SetBranchAddress("AK8Gen_MergedWjets_dR_minWminHmass_SubLeading_W",&AK8Gen_MergedWjets_dR_minWminHmass_SubLeading_W);
  t1->SetBranchAddress("AK8Gen_MergedWjets_minWminHmass_Leading_Pt",&AK8Gen_MergedWjets_minWminHmass_Leading_Pt);
  t1->SetBranchAddress("AK8Gen_MergedWjets_minWminHmass_SubLeading_Pt",&AK8Gen_MergedWjets_minWminHmass_SubLeading_Pt);
  t1->SetBranchAddress("AK8Gen_MergedWjets_minWminHmass_Higgs_Pt",&AK8Gen_MergedWjets_minWminHmass_Higgs_Pt);
  t1->SetBranchAddress("OneAK8TwoAK4_minMass_dR_ReconsW_AK4_W",&OneAK8TwoAK4_minMass_dR_ReconsW_AK4_W);
  t1->SetBranchAddress("OneAK8TwoAK4_minMass_dR_AK8_W",&OneAK8TwoAK4_minMass_dR_AK8_W);
  t1->SetBranchAddress("OneAK8TwoAK4_pTMax_leadingAK4_dR_q",&OneAK8TwoAK4_pTMax_leadingAK4_dR_q);
  t1->SetBranchAddress("OneAK8TwoAK4_pTMax_subleadingAK4_dR_q",&OneAK8TwoAK4_pTMax_subleadingAK4_dR_q);
  t1->SetBranchAddress("OneAK8TwoAK4_minMass_ReconsH_M",&OneAK8TwoAK4_minMass_ReconsH_M);
  t1->SetBranchAddress("OneAK8TwoAK4_minMass_ReconsW_AK4_Pt",&OneAK8TwoAK4_minMass_ReconsW_AK4_Pt);
  t1->SetBranchAddress("OneAK8TwoAK4_minMass_ReconsW_AK4_M",&OneAK8TwoAK4_minMass_ReconsW_AK4_M);
  t1->SetBranchAddress("OneAK8TwoAK4_minMass_AK8_M",&OneAK8TwoAK4_minMass_AK8_M);
  t1->SetBranchAddress("OneAK8TwoAK4_minMass_AK8_Pt",&OneAK8TwoAK4_minMass_AK8_Pt);

  vector<double> countnumber1(20,0);
  int entries1=t1->GetEntries();
  for (int i=0; i<entries1; ++i){
    t1->GetEntry(i);
    double gen_onShell_WBoson_M;
    double gen_offShell_WBoson_M;
    if (abs(gen_leading_WBoson_M-80) < abs(gen_Subleading_WBoson_M-80)){
      gen_onShell_WBoson_M = gen_leading_WBoson_M;
      gen_offShell_WBoson_M = gen_Subleading_WBoson_M;
    }
    if (abs(gen_leading_WBoson_M-80) > abs(gen_Subleading_WBoson_M-80)){
      gen_onShell_WBoson_M = gen_Subleading_WBoson_M;
      gen_offShell_WBoson_M = gen_leading_WBoson_M;
    }
    countnumber1[0]=countnumber1[0]+1;
    AK4njet->Fill(genJetAK4_njets);
    AK8njet->Fill(genJetAK8_njets);
    //Jqqqq
    if (AK8Gen_HiggsJet_minDMass_Pt > 400) {
      countnumber1[1]=countnumber1[1]+1;
      if (AK8Gen_HiggsJet_minDMass_M < 160 && AK8Gen_HiggsJet_minDMass_M > 100) {
	AK8_HiggsJet_minDMass_M_WW->Fill(AK8Gen_HiggsJet_minDMass_M);
	countnumber1[2]=countnumber1[2]+1;
	continue;
      }
    }
    //JJJJqqqq
    if (AK4GEN_AllResolved_onShellWboson_M > 60 && AK4GEN_AllResolved_onShellWboson_M < 105){
      AK4_AllResolved_Higgs_M->Fill(AK4GEN_AllResolved_Higgs_M);
      countnumber1[3]=countnumber1[3]+1;
      continue;
    }
    //JJJqqqq
    if (OneAK8TwoAK4_minMass_AK8_Pt > 200 && OneAK8TwoAK4_minMass_ReconsW_AK4_Pt < 200){
     countnumber1[4]=countnumber1[4]+1;
     
     if ((OneAK8TwoAK4_minMass_AK8_M > 60 && OneAK8TwoAK4_minMass_AK8_M < 105) || (OneAK8TwoAK4_minMass_ReconsW_AK4_M > 60 && OneAK8TwoAK4_minMass_ReconsW_AK4_M < 105)){
       OneAK8TwoAK4_minMass_ReconsH_M_WW_1->Fill(OneAK8TwoAK4_minMass_ReconsH_M);
       countnumber1[5]=countnumber1[5]+1;
       continue;
     }
    } 
    countnumber1[6]=countnumber1[6]+1;
    OneAK8TwoAK4_minMass_ReconsH_M_WW_2->Fill(OneAK8TwoAK4_minMass_ReconsH_M);
  }
  
  std::cout <<"TotalWW:"<<countnumber1[0]<<"->"<<countnumber1[0]/countnumber1[0]<<std::endl;
  std::cout <<"HiggsJet_Pt_WW>400:"<<countnumber1[1]<<"->"<<countnumber1[1]/countnumber1[0]<<std::endl;
  std::cout <<"1-jet:"<<countnumber1[2]<<"->"<<countnumber1[2]/countnumber1[0]<<std::endl;
  std::cout <<"4-jet:"<<countnumber1[3]<<"->"<<countnumber1[3]/countnumber1[0]<<std::endl;
  std::cout <<"3-jetPtcut:"<<countnumber1[4]<<"->"<<countnumber1[4]/countnumber1[0]<<std::endl;
  std::cout <<"3-jetcase1:"<<countnumber1[5]<<"->"<<countnumber1[5]/countnumber1[0]<<std::endl;
  std::cout <<"3-jetcase2:"<<countnumber1[6]<<"->"<<countnumber1[6]/countnumber1[0]<<std::endl;



  TCanvas *c1 = new TCanvas();
  //OneAK8TwoAK4_minMass_ReconsH_M_WW_1->SetLineColor(1);
  //OneAK8TwoAK4_minMass_ReconsH_M_ZZ_1->SetLineColor(2);
  
  OneAK8TwoAK4_minMass_ReconsH_M_WW_1->DrawNormalized();
  //OneAK8TwoAK4_minMass_ReconsH_M_ZZ_1->DrawNormalized("same");
 
  c1->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/WWnewselection/OneAK8TwoAK4_minMass_ReconsH_M_1.png");

  TCanvas *c2 = new TCanvas();
  //OneAK8TwoAK4_minMass_ReconsH_M_WW_1->SetLineColor(1);
  //OneAK8TwoAK4_minMass_ReconsH_M_ZZ_1->SetLineColor(2);
  
  OneAK8TwoAK4_minMass_ReconsH_M_WW_2->DrawNormalized();
  //OneAK8TwoAK4_minMass_ReconsH_M_ZZ_1->DrawNormalized("same");
 
  c2->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/WWnewselection/OneAK8TwoAK4_minMass_ReconsH_M_2.png");

  TCanvas *c3 = new TCanvas();

  AK4_AllResolved_Higgs_M->DrawNormalized();
 
 
  c3->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/WWnewselection/AK4_AllResolved_Higgs_M.png");

  TCanvas *c4 = new TCanvas();
  
  
  AK8_HiggsJet_minDMass_M_WW->DrawNormalized();
  
 
  c4->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/WWnewselection/AK8_HiggsJet_minDMass_M.png");

  TCanvas *c24 = new TCanvas();
  AK4njet->SetLineColor(1);
  AK8njet->SetLineColor(2);
  
  AK4njet->DrawNormalized();
  AK8njet->DrawNormalized("same");
 
  c24->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/WWnewselection/AK48njet.png");

 

}
