#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/deltaPhi.h"
#include <vector>
#include <iostream>
#include "TH1F.h"
#include "TLorentzVector.h"
void matchWW(){

  TFile *f1 = TFile::Open("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/GF_HH_SM_slc6_LHEBqrk.root");
  //TFile *f2 = TFile::Open("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/GF_HH_SM_slc6_LHEBqrk_ZZ.root");
 
  TTree *t1 = (TTree*)f1->Get("otree");
  //TTree *t2 = (TTree*)f2->Get("otree");

  //create histograms
  
  TH1F *AllResolved_onShellWboson_Pt = new TH1F("AllResolved_onShellWboson_Pt","AllResolved_onShellWboson_Pt",25,0,100);
  TH1F *AllResolved_offShellWboson_Pt = new TH1F("AllResolved_offShellWboson_Pt","AllResolved_offShellWboson_Pt",25,0,100);
  TH1F *AllResolved_onShellZboson_Pt = new TH1F("AllResolved_onShellZboson_Pt","AllResolved_onShellZboson_Pt",25,0,100);
  TH1F *AllResolved_offShellZboson_Pt = new TH1F("AllResolved_offShellZboson_Pt","AllResolved_offShellZboson_Pt",25,0,100);
  TH1F *onShell_WBoson_Pt = new TH1F("onShell_WBoson_Pt","onShell_Wboson_Pt",25,0,100);
  TH1F *offShell_WBoson_Pt = new TH1F("offShell_WBoson_Pt","offShell_Wboson_Pt",25,0,100);
  TH1F *onShell_ZBoson_Pt = new TH1F("onShell_ZBoson_Pt","onShell_Zboson_Pt",25,0,100);
  TH1F *offShell_ZBoson_Pt = new TH1F("offShell_ZBoson_Pt","offShell_Zboson_Pt",25,0,100);
  TH1F *AK4_AllResolved_onShellWboson_M = new TH1F("AK4_AllResolved_onShellWboson_M","AK4_AllResolved_onShellWboson_M",40,0,160);
  TH1F *AK4_AllResolved_offShellWboson_M = new TH1F("AK4_AllResolved_offShellWboson_M","AK4_AllResolved_offShellWboson_M",40,0,160);
  TH1F *AK4_AllResolved_Higgs_M = new TH1F("AK4_AllResolved_Higgs_M","AK4_AllResolved_Higgs_M",40,0,160);
  TH1F *AK4_AllResolved_dR_J1_onShell_q = new TH1F("AK4_AllResolved_dR_J1_onShell_q","AK4_AllResolved_dR_J1_onShell_q",25,0,4.5);
  TH1F *AK4_AllResolved_dR_J2_onShell_q = new TH1F("AK4_AllResolved_dR_J2_onShell_q","AK4_AllResolved_dR_J2_onShell_q",25,0,4.5);
  TH1F *AK4_AllResolved_dR_J3_offShell_q = new TH1F("AK4_AllResolved_dR_J3_offShell_q","AK4_AllResolved_dR_J3_offShell_q",25,0,4.5);
  TH1F *AK4_AllResolved_dR_J4_offShell_q = new TH1F("AK4_AllResolved_dR_J4_offShell_q","AK4_AllResolved_dR_J4_offShell_q",25,0,4.5);
  TH1F *AK8_HiggsJet_minDMass_deltaR_HWW = new TH1F("AK8_HiggsJet_minDMass_deltaR_HWW","AK8_HiggsJet_minDMass_deltaR_HWW",25,0,4.5);
  TH1F *AK8_HiggsJet_minDMass_deltaR_H_q1 = new TH1F("AK8_HiggsJet_minDMass_deltaR_H_q1","AK8_HiggsJet_minDMass_deltaR_H_q1",25,0,4.5);
  TH1F *AK8_HiggsJet_minDMass_deltaR_H_q2 = new TH1F("AK8_HiggsJet_minDMass_deltaR_H_q2","AK8_HiggsJet_minDMass_deltaR_H_q2",25,0,4.5);
  TH1F *AK8_HiggsJet_minDMass_deltaR_H_q3 = new TH1F("AK8_HiggsJet_minDMass_deltaR_H_q3","AK8_HiggsJet_minDMass_deltaR_H_q3",25,0,4.5);
  TH1F *AK8_HiggsJet_minDMass_deltaR_H_q4 = new TH1F("AK8_HiggsJet_minDMass_deltaR_H_q4","AK8_HiggsJet_minDMass_deltaR_H_q4",25,0,4.5);
  TH1F *AK8_HiggsJet_MaxPt_deltaR_H_q1 = new TH1F("AK8_HiggsJet_MaxPt_deltaR_H_q1","AK8_HiggsJet_MaxPt_deltaR_H_q1",25,0,4.5);
  TH1F *AK8_HiggsJet_MaxPt_deltaR_H_q2 = new TH1F("AK8_HiggsJet_MaxPt_deltaR_H_q2","AK8_HiggsJet_MaxPt_deltaR_H_q2",25,0,4.5);
  TH1F *AK8_HiggsJet_MaxPt_deltaR_H_q3 = new TH1F("AK8_HiggsJet_MaxPt_deltaR_H_q3","AK8_HiggsJet_MaxPt_deltaR_H_q3",25,0,4.5);
  TH1F *AK8_HiggsJet_MaxPt_deltaR_H_q4 = new TH1F("AK8_HiggsJet_MaxPt_deltaR_H_q4","AK8_HiggsJet_MaxPt_deltaR_H_q4",25,0,4.5);
  
  TH1F *AK8_MergedWjets_dR_MaxPt_Leading_W = new TH1F("AK8_MergedWjets_dR_MaxPt_Leading_W","AK8_MergedWjets_dR_MaxPt_Leading_W",25,0,4.5);
  TH1F *AK8_MergedWjets_dR_MaxPt_SubLeading_W = new TH1F("AK8_MergedWjets_dR_MaxPt_SubLeading_W","AK8_MergedWjets_dR_MaxPt_SubLeading_W",25,0,4.5);
  TH1F *AK8_MergedWjets_dR_minDMass_Leading_W = new TH1F("AK8_MergedWjets_dR_minDMass_Leading_W","AK8_MergedWjets_dR_minDMass_Leading_W",25,0,4.5);
  TH1F *AK8_MergedWjets_dR_minDMass_SubLeading_W = new TH1F("AK8_MergedWjets_dR_minDMass_SubLeading_W","AK8_MergedWjets_dR_minDMass_SubLeading_W",25,0,4.5);
  TH1F *AK8_MergedWjets_dR_minWminHmass_Leading_W = new TH1F("AK8_MergedWjets_dR_minWminHmass_Leading_W","AK8_MergedWjets_dR_minWminHmass_Leading_W",25,0,4.5);
  TH1F *AK8_MergedWjets_dR_minWminHmass_SubLeading_W = new TH1F("AK8_MergedWjets_dR_minWminHmass_SubLeading_W","AK8_MergedWjets_dR_minWminHmass_SubLeading_W",25,0,4.5);
  TH1F *HOneAK8TwoAK4_minMass_dR_ReconsW_AK4_W = new TH1F("HOneAK8TwoAK4_minMass_dR_ReconsW_AK4_W","HOneAK8TwoAK4_minMass_dR_ReconsW_AK4_W",25,0,4.5);
  TH1F *HOneAK8TwoAK4_minMass_dR_AK8_W = new TH1F("HOneAK8TwoAK4_minMass_dR_AK8_W","HOneAK8TwoAK4_minMass_dR_AK8_W",25,0,4.5);
  TH1F *HOneAK8TwoAK4_pTMax_leadingAK4_dR_q = new TH1F("HOneAK8TwoAK4_pTMax_leadingAK4_dR_q","HOneAK8TwoAK4_pTMax_leadingAK4_dR_q",25,0,4.5);
  TH1F *HOneAK8TwoAK4_pTMax_subleadingAK4_dR_q = new TH1F("HOneAK8TwoAK4_pTMax_subleadingAK4_dR_q","HOneAK8TwoAK4_pTMax_subleadingAK4_dR_q",25,0,4.5);
  
  TH1F *AK4_AllResolved_dR_J1_q = new TH1F("AK4_AllResolved_dR_J1_q","AK4_AllResolved_dR_J1_q;dR(J1,q);Normalized Events",25,0,4.5);
  TH1F *AK4_AllResolved_dR_J2_q = new TH1F("AK4_AllResolved_dR_J2_q","AK4_AllResolved_dR_J2_q;dR(J2,q);Normalized Events",25,0,4.5);
  TH1F *AK4_AllResolved_dR_J3_q = new TH1F("AK4_AllResolved_dR_J3_q","AK4_AllResolved_dR_J3_q;dR(J3,q);Normalized Events",25,0,4.5);
  TH1F *AK4_AllResolved_dR_J4_q = new TH1F("AK4_AllResolved_dR_J4_q","AK4_AllResolved_dR_J4_q;dR(J4,q);Normalized Events",25,0,4.5);
	
  TH1F *testdR = new TH1F("testdR","testdR;dR(J1,q);Normalized Events",25,0,4.5);
	
  


  vector<double> countnumber(20,0);
	
  
  double gen_leading_photon_Pt;
  double gen_leading_WpJets_Pt;
  double gen_leading_WpJets_Eta;
  double gen_leading_WpJets_Phi;
  double gen_leading_WmJets_Pt;
  double gen_leading_WmJets_Eta;
  double gen_leading_WmJets_Phi;
  double gen_Subleading_WpJets_Pt;
  double gen_Subleading_WpJets_Eta;
  double gen_Subleading_WpJets_Phi;
  double gen_Subleading_WmJets_Pt;
  double gen_Subleading_WmJets_Eta;
  double gen_Subleading_WmJets_Phi;
  double gen_leading_WBoson_Pt;
  double gen_Subleading_WBoson_Pt;
  double gen_leading_WBoson_M;
  double gen_Subleading_WBoson_M;
  double gen_onShell_WBoson_Pt;
  double gen_offShell_WBoson_Pt;
  double gen_HiggsWW_Pt;
  double gen_HiggsWW_Eta;
  double gen_HiggsWW_Phi;

  double gen_leading_ZBoson_Pt;
  double gen_Subleading_ZBoson_Pt;
  double gen_leading_ZBoson_M;
  double gen_Subleading_ZBoson_M;
  double gen_onShell_ZBoson_Pt;
  double gen_offShell_ZBoson_Pt;

  double AK4GEN_AllResolved_onShellJet1_Eta;
  double AK4GEN_AllResolved_onShellJet1_Phi;
  double AK4GEN_AllResolved_onShellJet2_Eta;
  double AK4GEN_AllResolved_onShellJet2_Phi;
  double AK4GEN_AllResolved_offShellJet1_Eta;
  double AK4GEN_AllResolved_offShellJet1_Phi;
  double AK4GEN_AllResolved_offShellJet2_Eta;
  double AK4GEN_AllResolved_offShellJet2_Phi;
  double AK4GEN_AllResolved_dR_J1_onShell_q;
  double AK4GEN_AllResolved_dR_J2_onShell_q;
  double AK4GEN_AllResolved_dR_J3_offShell_q;
  double AK4GEN_AllResolved_dR_J4_offShell_q;
  double genJetAK4_njets;
  double AK4GEN_AllResolved_onShellWboson_Pt;
  double AK4GEN_AllResolved_offShellWboson_Pt;
  double AK4GEN_AllResolved_onShellWboson_M;
  double AK4GEN_AllResolved_offShellWboson_M;
  double AK4GEN_AllResolved_Higgs_M;
  double AK4GEN_AllResolved_onShellZboson_Pt;
  double AK4GEN_AllResolved_offShellZboson_Pt;
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
  double AK8Gen_HiggsJet_MaxPt_M;
  double AK8Gen_HiggsJet_MaxPt_Pt;
  double AK8Gen_HiggsJet_MaxPt_Eta;
  double AK8Gen_HiggsJet_MaxPt_Phi;
  double OneAK8TwoAK4_pTMax_leadingAK4_dR_q;
  double OneAK8TwoAK4_pTMax_subleadingAK4_dR_q;


  t1->SetBranchAddress("gen_leading_photon_Pt",&gen_leading_photon_Pt);
  t1->SetBranchAddress("gen_leading_WpJets_Pt",&gen_leading_WpJets_Pt);
  t1->SetBranchAddress("gen_leading_WpJets_Eta",&gen_leading_WpJets_Eta);
  t1->SetBranchAddress("gen_leading_WpJets_Phi",&gen_leading_WpJets_Phi);
  t1->SetBranchAddress("gen_leading_WmJets_Pt",&gen_leading_WmJets_Pt);
  t1->SetBranchAddress("gen_leading_WmJets_Eta",&gen_leading_WmJets_Eta);
  t1->SetBranchAddress("gen_leading_WmJets_Phi",&gen_leading_WmJets_Phi);
  t1->SetBranchAddress("gen_Subleading_WpJets_Pt",&gen_Subleading_WpJets_Pt);
  t1->SetBranchAddress("gen_Subleading_WpJets_Eta",&gen_Subleading_WpJets_Eta);
  t1->SetBranchAddress("gen_Subleading_WpJets_Phi",&gen_Subleading_WpJets_Phi);
  t1->SetBranchAddress("gen_Subleading_WmJets_Pt",&gen_Subleading_WmJets_Pt);
  t1->SetBranchAddress("gen_Subleading_WmJets_Eta",&gen_Subleading_WmJets_Eta);
  t1->SetBranchAddress("gen_Subleading_WmJets_Phi",&gen_Subleading_WmJets_Phi);
  t1->SetBranchAddress("gen_leading_WBoson_Pt",&gen_leading_WBoson_Pt);
  t1->SetBranchAddress("gen_Subleading_WBoson_Pt",&gen_Subleading_WBoson_Pt);
  t1->SetBranchAddress("gen_leading_WBoson_M",&gen_leading_WBoson_M);
  t1->SetBranchAddress("gen_Subleading_WBoson_M",&gen_Subleading_WBoson_M);
  t1->SetBranchAddress("gen_HiggsWW_Pt",&gen_HiggsWW_Pt);
  t1->SetBranchAddress("gen_HiggsWW_Eta",&gen_HiggsWW_Eta);
  t1->SetBranchAddress("gen_HiggsWW_Phi",&gen_HiggsWW_Phi);

  t1->SetBranchAddress("AK4GEN_AllResolved_dR_J1_onShell_q",&AK4GEN_AllResolved_dR_J1_onShell_q);
  t1->SetBranchAddress("AK4GEN_AllResolved_dR_J2_onShell_q",&AK4GEN_AllResolved_dR_J2_onShell_q);
  t1->SetBranchAddress("AK4GEN_AllResolved_dR_J3_offShell_q",&AK4GEN_AllResolved_dR_J3_offShell_q);
  t1->SetBranchAddress("AK4GEN_AllResolved_dR_J4_offShell_q",&AK4GEN_AllResolved_dR_J4_offShell_q);
  
  t1->SetBranchAddress("genJetAK4_njets",&genJetAK4_njets);

  t1->SetBranchAddress("AK4GEN_AllResolved_onShellJet1_Eta",&AK4GEN_AllResolved_onShellJet1_Eta);
  t1->SetBranchAddress("AK4GEN_AllResolved_onShellJet2_Eta",&AK4GEN_AllResolved_onShellJet2_Eta);
  t1->SetBranchAddress("AK4GEN_AllResolved_offShellJet1_Eta",&AK4GEN_AllResolved_offShellJet1_Eta);
  t1->SetBranchAddress("AK4GEN_AllResolved_offShellJet2_Eta",&AK4GEN_AllResolved_offShellJet2_Eta);
  t1->SetBranchAddress("AK4GEN_AllResolved_onShellJet1_Phi",&AK4GEN_AllResolved_onShellJet1_Phi);
  t1->SetBranchAddress("AK4GEN_AllResolved_onShellJet2_Phi",&AK4GEN_AllResolved_onShellJet2_Phi);
  t1->SetBranchAddress("AK4GEN_AllResolved_offShellJet1_Phi",&AK4GEN_AllResolved_offShellJet1_Phi);
  t1->SetBranchAddress("AK4GEN_AllResolved_offShellJet2_Phi",&AK4GEN_AllResolved_offShellJet2_Phi);
  t1->SetBranchAddress("AK4GEN_AllResolved_onShellWboson_Pt",&AK4GEN_AllResolved_onShellWboson_Pt);
  t1->SetBranchAddress("AK4GEN_AllResolved_offShellWboson_Pt",&AK4GEN_AllResolved_offShellWboson_Pt);
  t1->SetBranchAddress("AK4GEN_AllResolved_onShellWboson_M",&AK4GEN_AllResolved_onShellWboson_M);
  t1->SetBranchAddress("AK4GEN_AllResolved_offShellWboson_M",&AK4GEN_AllResolved_offShellWboson_M);
  t1->SetBranchAddress("AK4GEN_AllResolved_Higgs_M",&AK4GEN_AllResolved_Higgs_M);

  t1->SetBranchAddress("AK8Gen_HiggsJet_minDMass_deltaR_HWW",&AK8Gen_HiggsJet_minDMass_deltaR_HWW);
  t1->SetBranchAddress("AK8Gen_HiggsJet_minDMass_M",&AK8Gen_HiggsJet_minDMass_M);
  t1->SetBranchAddress("AK8Gen_HiggsJet_minDMass_Pt",&AK8Gen_HiggsJet_minDMass_Pt);
  t1->SetBranchAddress("AK8Gen_HiggsJet_minDMass_Eta",&AK8Gen_HiggsJet_minDMass_Eta);
  t1->SetBranchAddress("AK8Gen_HiggsJet_minDMass_Phi",&AK8Gen_HiggsJet_minDMass_Phi);
  t1->SetBranchAddress("AK8Gen_HiggsJet_MaxPt_M",&AK8Gen_HiggsJet_MaxPt_M);
  t1->SetBranchAddress("AK8Gen_HiggsJet_MaxPt_Pt",&AK8Gen_HiggsJet_MaxPt_Pt);
  t1->SetBranchAddress("AK8Gen_HiggsJet_MaxPt_Eta",&AK8Gen_HiggsJet_MaxPt_Eta);
  t1->SetBranchAddress("AK8Gen_HiggsJet_MaxPt_Phi",&AK8Gen_HiggsJet_MaxPt_Phi);
  
  t1->SetBranchAddress("AK8Gen_MergedWjets_dR_MaxPt_Leading_W",&AK8Gen_MergedWjets_dR_MaxPt_Leading_W);
  t1->SetBranchAddress("AK8Gen_MergedWjets_dR_MaxPt_SubLeading_W",&AK8Gen_MergedWjets_dR_MaxPt_SubLeading_W);
  t1->SetBranchAddress("AK8Gen_MergedWjets_dR_minDMass_Leading_W",&AK8Gen_MergedWjets_dR_minDMass_Leading_W);
  t1->SetBranchAddress("AK8Gen_MergedWjets_dR_minDMass_SubLeading_W",&AK8Gen_MergedWjets_dR_minDMass_SubLeading_W);
  t1->SetBranchAddress("AK8Gen_MergedWjets_dR_minWminHmass_Leading_W",&AK8Gen_MergedWjets_dR_minWminHmass_Leading_W);
  t1->SetBranchAddress("AK8Gen_MergedWjets_dR_minWminHmass_SubLeading_W",&AK8Gen_MergedWjets_dR_minWminHmass_SubLeading_W);
  t1->SetBranchAddress("OneAK8TwoAK4_minMass_dR_ReconsW_AK4_W",&OneAK8TwoAK4_minMass_dR_ReconsW_AK4_W);
  t1->SetBranchAddress("OneAK8TwoAK4_minMass_dR_AK8_W",&OneAK8TwoAK4_minMass_dR_AK8_W);
  t1->SetBranchAddress("OneAK8TwoAK4_pTMax_leadingAK4_dR_q",&OneAK8TwoAK4_pTMax_leadingAK4_dR_q);
  t1->SetBranchAddress("OneAK8TwoAK4_pTMax_subleadingAK4_dR_q",&OneAK8TwoAK4_pTMax_subleadingAK4_dR_q);


  //t2->SetBranchAddress("gen_leading_ZBoson_Pt",&gen_leading_ZBoson_Pt);
  //t2->SetBranchAddress("gen_Subleading_ZBoson_Pt",&gen_Subleading_ZBoson_Pt);
  //t2->SetBranchAddress("gen_leading_ZBoson_M",&gen_leading_ZBoson_M);
  //t2->SetBranchAddress("gen_Subleading_ZBoson_M",&gen_Subleading_ZBoson_M);
  //t2->SetBranchAddress("AK4GEN_AllResolved_onShellZboson_Pt",&AK4GEN_AllResolved_onShellZboson_Pt);
  //t2->SetBranchAddress("AK4GEN_AllResolved_offShellZboson_Pt",&AK4GEN_AllResolved_offShellZboson_Pt);
  


  
  //define new variable for plot
  double tempdR = 999.0;


  int entries1=t1->GetEntries();
  //int entries2=t2->GetEntries();
  std::cout <<"entries:"<<entries1<<std::endl;
  //std::cout <<"entries:"<<entries2<<std::endl;
  
  for (int i=0; i<entries1; ++i){
    t1->GetEntry(i);
    vector<double> AK4GEN_AllResolved_dR_J_q(4);
    vector<int> indexJq(4,-1);
    vector<double> Eta_q(4);
    vector<double> Phi_q(4);
    vector<double> Eta_AK4jet(4);
    vector<double> Phi_AK4jet(4);
    Eta_q[0]=(gen_leading_WpJets_Eta);
    Eta_q[1]=(gen_Subleading_WpJets_Eta);
    Eta_q[2]=(gen_leading_WmJets_Eta);
    Eta_q[3]=(gen_Subleading_WmJets_Eta);
    Eta_AK4jet[0]=(AK4GEN_AllResolved_onShellJet1_Eta);
    Eta_AK4jet[1]=(AK4GEN_AllResolved_onShellJet2_Eta);
    Eta_AK4jet[2]=(AK4GEN_AllResolved_offShellJet1_Eta);
    Eta_AK4jet[3]=(AK4GEN_AllResolved_offShellJet2_Eta);
  
    Phi_q[0]=(gen_leading_WpJets_Eta);
    Phi_q[1]=(gen_Subleading_WpJets_Eta);
    Phi_q[2]=(gen_leading_WmJets_Eta);
    Phi_q[3]=(gen_Subleading_WmJets_Eta);
    Phi_AK4jet[0]=(AK4GEN_AllResolved_onShellJet1_Phi);
    Phi_AK4jet[1]=(AK4GEN_AllResolved_onShellJet2_Phi);
    Phi_AK4jet[2]=(AK4GEN_AllResolved_offShellJet1_Phi);
    Phi_AK4jet[3]=(AK4GEN_AllResolved_offShellJet2_Phi);
    
    for (int indexAK4jet=0; indexAK4jet<4; ++indexAK4jet){
	tempdR = 999.0;
	for(int indexq=0; indexq<4; ++indexq){
		if(tempdR > deltaR(Eta_AK4jet[indexAK4jet],Phi_AK4jet[indexAK4jet],Eta_q[indexq],Phi_q[indexq]) && indexq != indexJq[0] && indexq != indexJq[1] && indexq != indexJq[2]){
			tempdR=	deltaR(Eta_AK4jet[indexAK4jet],Phi_AK4jet[indexAK4jet],Eta_q[indexq],Phi_q[indexq]);
			indexJq[indexAK4jet]=indexq;
		}
	}
	AK4GEN_AllResolved_dR_J_q[indexAK4jet]=(tempdR);
    }

	  
    countnumber[0]=countnumber[0]+1;
    // Apply cut

    // if (gen_leading_WpJets_Pt>15)
    if (abs(gen_leading_WBoson_M-80) <= abs(gen_Subleading_WBoson_M-80)){
      gen_onShell_WBoson_Pt=gen_leading_WBoson_Pt;
      gen_offShell_WBoson_Pt=gen_Subleading_WBoson_Pt;
    }
    if (abs(gen_leading_WBoson_M-80) > abs(gen_Subleading_WBoson_M-80)){
      gen_onShell_WBoson_Pt=gen_Subleading_WBoson_Pt;
      gen_offShell_WBoson_Pt=gen_leading_WBoson_Pt;
    }
    // Apply cut flow
    if (AK4GEN_AllResolved_Higgs_M > 100 && AK4GEN_AllResolved_Higgs_M < 160 && AK4GEN_AllResolved_onShellWboson_M > 60 && AK4GEN_AllResolved_onShellWboson_M < 105){
      countnumber[1]=countnumber[1]+1;
      if (AK4GEN_AllResolved_onShellWboson_Pt < 200 && AK4GEN_AllResolved_offShellWboson_Pt < 200){
	countnumber[2]=countnumber[2]+1;
      }
    }
    //cut: JJJJqqqq
    if (AK4GEN_AllResolved_dR_J_q[0] < 0.4 && AK4GEN_AllResolved_dR_J_q[1] < 0.4 && AK4GEN_AllResolved_dR_J_q[2] < 0.4 && AK4GEN_AllResolved_dR_J_q[3] < 0.4) {
      countnumber[3]=countnumber[3]+1;
    }
    //cut:Jqqqq
    if (AK8Gen_HiggsJet_minDMass_deltaR_HWW < 0.4) {
      countnumber[4]=countnumber[4]+1;
    }
    //cut:JJqqqq in MaxPt of JJ
    if (AK8Gen_MergedWjets_dR_MaxPt_Leading_W < 0.4 && AK8Gen_MergedWjets_dR_MaxPt_SubLeading_W < 0.4) {
      countnumber[5]=countnumber[5]+1;
    }
    if (AK8Gen_MergedWjets_dR_minDMass_Leading_W < 0.4 && AK8Gen_MergedWjets_dR_minDMass_SubLeading_W < 0.4) {
      countnumber[6]=countnumber[6]+1;
    }
    if (AK8Gen_MergedWjets_dR_minWminHmass_Leading_W < 0.4 && AK8Gen_MergedWjets_dR_minWminHmass_SubLeading_W < 0.4) {
      countnumber[7]=countnumber[7]+1;
    }
    //cut:JJJqqqq minMass qq->J
    if (OneAK8TwoAK4_minMass_dR_ReconsW_AK4_W < 0.4 && OneAK8TwoAK4_minMass_dR_AK8_W < 0.4) {
      countnumber[8]=countnumber[8]+1;
    }
    if (OneAK8TwoAK4_pTMax_leadingAK4_dR_q < 0.4 && OneAK8TwoAK4_pTMax_subleadingAK4_dR_q < 0.4) {
      countnumber[9]=countnumber[9]+1;
    }
    if (AK8Gen_HiggsJet_minDMass_M > 100 && AK8Gen_HiggsJet_minDMass_M < 160) {
      countnumber[10]=countnumber[10]+1;
      if (AK8Gen_HiggsJet_minDMass_Pt > 400) {
	countnumber[11]=countnumber[11]+1;
	AK8_HiggsJet_minDMass_deltaR_H_q1->Fill(deltaR(Eta_q[0],Phi_q[0],AK8Gen_HiggsJet_minDMass_Eta,AK8Gen_HiggsJet_minDMass_Phi));
	AK8_HiggsJet_minDMass_deltaR_H_q2->Fill(deltaR(Eta_q[1],Phi_q[1],AK8Gen_HiggsJet_minDMass_Eta,AK8Gen_HiggsJet_minDMass_Phi));
	AK8_HiggsJet_minDMass_deltaR_H_q3->Fill(deltaR(Eta_q[2],Phi_q[2],AK8Gen_HiggsJet_minDMass_Eta,AK8Gen_HiggsJet_minDMass_Phi));
	AK8_HiggsJet_minDMass_deltaR_H_q4->Fill(deltaR(Eta_q[3],Phi_q[3],AK8Gen_HiggsJet_minDMass_Eta,AK8Gen_HiggsJet_minDMass_Phi));
	if (AK8Gen_HiggsJet_minDMass_deltaR_HWW < 0.8) {
	  countnumber[12]=countnumber[12]+1;
	}
	if (deltaR(Eta_q[0],Phi_q[0],AK8Gen_HiggsJet_minDMass_Eta,AK8Gen_HiggsJet_minDMass_Phi) < 0.8 && deltaR(Eta_q[1],Phi_q[1],AK8Gen_HiggsJet_minDMass_Eta,AK8Gen_HiggsJet_minDMass_Phi) < 0.8 &&deltaR(Eta_q[2],Phi_q[2],AK8Gen_HiggsJet_minDMass_Eta,AK8Gen_HiggsJet_minDMass_Phi) < 0.8 &&deltaR(Eta_q[3],Phi_q[3],AK8Gen_HiggsJet_minDMass_Eta,AK8Gen_HiggsJet_minDMass_Phi) < 0.8) {
     	  countnumber[13]=countnumber[13]+1;
    	}
      }
    }
    if (AK8Gen_HiggsJet_MaxPt_M > 100 && AK8Gen_HiggsJet_MaxPt_M < 160) {
      countnumber[14]=countnumber[14]+1;
      if (AK8Gen_HiggsJet_MaxPt_Pt > 400) {
	countnumber[15]=countnumber[15]+1;
	AK8_HiggsJet_MaxPt_deltaR_H_q1->Fill(deltaR(Eta_q[0],Phi_q[0],AK8Gen_HiggsJet_MaxPt_Eta,AK8Gen_HiggsJet_MaxPt_Phi));
	AK8_HiggsJet_MaxPt_deltaR_H_q2->Fill(deltaR(Eta_q[1],Phi_q[1],AK8Gen_HiggsJet_MaxPt_Eta,AK8Gen_HiggsJet_MaxPt_Phi));
	AK8_HiggsJet_MaxPt_deltaR_H_q3->Fill(deltaR(Eta_q[2],Phi_q[2],AK8Gen_HiggsJet_MaxPt_Eta,AK8Gen_HiggsJet_MaxPt_Phi));
	AK8_HiggsJet_MaxPt_deltaR_H_q4->Fill(deltaR(Eta_q[3],Phi_q[3],AK8Gen_HiggsJet_MaxPt_Eta,AK8Gen_HiggsJet_MaxPt_Phi));

	if (deltaR(gen_HiggsWW_Eta,gen_HiggsWW_Phi,AK8Gen_HiggsJet_MaxPt_Eta,AK8Gen_HiggsJet_MaxPt_Phi) < 0.8) {
	  countnumber[16]=countnumber[16]+1;
	}
	if (deltaR(Eta_q[0],Phi_q[0],AK8Gen_HiggsJet_MaxPt_Eta,AK8Gen_HiggsJet_MaxPt_Phi) < 0.8 && deltaR(Eta_q[1],Phi_q[1],AK8Gen_HiggsJet_MaxPt_Eta,AK8Gen_HiggsJet_MaxPt_Phi) < 0.8 &&deltaR(Eta_q[2],Phi_q[2],AK8Gen_HiggsJet_MaxPt_Eta,AK8Gen_HiggsJet_MaxPt_Phi) < 0.8 &&deltaR(Eta_q[3],Phi_q[3],AK8Gen_HiggsJet_MaxPt_Eta,AK8Gen_HiggsJet_MaxPt_Phi) < 0.8) {
     	  countnumber[17]=countnumber[17]+1;
    	}
      }
    }


    // Fill histogram

    AllResolved_onShellWboson_Pt->Fill(AK4GEN_AllResolved_onShellWboson_Pt);
    AllResolved_offShellWboson_Pt->Fill(AK4GEN_AllResolved_offShellWboson_Pt);
    AK4_AllResolved_onShellWboson_M->Fill(AK4GEN_AllResolved_onShellWboson_M);
    AK4_AllResolved_offShellWboson_M->Fill(AK4GEN_AllResolved_offShellWboson_M);
    AK4_AllResolved_Higgs_M->Fill(AK4GEN_AllResolved_Higgs_M);
    AK4_AllResolved_dR_J1_onShell_q->Fill(AK4GEN_AllResolved_dR_J1_onShell_q);
    AK4_AllResolved_dR_J2_onShell_q->Fill(AK4GEN_AllResolved_dR_J2_onShell_q);
    AK4_AllResolved_dR_J3_offShell_q->Fill(AK4GEN_AllResolved_dR_J3_offShell_q);
    AK4_AllResolved_dR_J4_offShell_q->Fill(AK4GEN_AllResolved_dR_J4_offShell_q);
    AK8_HiggsJet_minDMass_deltaR_HWW->Fill(AK8Gen_HiggsJet_minDMass_deltaR_HWW);
    AK8_MergedWjets_dR_MaxPt_Leading_W->Fill(AK8Gen_MergedWjets_dR_MaxPt_Leading_W);
    AK8_MergedWjets_dR_MaxPt_SubLeading_W->Fill(AK8Gen_MergedWjets_dR_MaxPt_SubLeading_W);
    AK8_MergedWjets_dR_minDMass_Leading_W->Fill(AK8Gen_MergedWjets_dR_minDMass_Leading_W);
    AK8_MergedWjets_dR_minDMass_SubLeading_W->Fill(AK8Gen_MergedWjets_dR_minDMass_SubLeading_W);
    AK8_MergedWjets_dR_minWminHmass_Leading_W->Fill(AK8Gen_MergedWjets_dR_minWminHmass_Leading_W);
    AK8_MergedWjets_dR_minWminHmass_SubLeading_W->Fill(AK8Gen_MergedWjets_dR_minWminHmass_SubLeading_W);
    HOneAK8TwoAK4_minMass_dR_ReconsW_AK4_W->Fill(OneAK8TwoAK4_minMass_dR_ReconsW_AK4_W);
    HOneAK8TwoAK4_minMass_dR_AK8_W->Fill(OneAK8TwoAK4_minMass_dR_AK8_W);
    HOneAK8TwoAK4_pTMax_leadingAK4_dR_q->Fill(OneAK8TwoAK4_pTMax_leadingAK4_dR_q);
    HOneAK8TwoAK4_pTMax_subleadingAK4_dR_q->Fill(OneAK8TwoAK4_pTMax_subleadingAK4_dR_q);
	  
    AK4_AllResolved_dR_J1_q->Fill(AK4GEN_AllResolved_dR_J_q[0]);
    AK4_AllResolved_dR_J2_q->Fill(AK4GEN_AllResolved_dR_J_q[1]);
    AK4_AllResolved_dR_J3_q->Fill(AK4GEN_AllResolved_dR_J_q[2]);
    AK4_AllResolved_dR_J4_q->Fill(AK4GEN_AllResolved_dR_J_q[3]);
    
    testdR->Fill(deltaR(Eta_q[0],Phi_q[0],AK8Gen_HiggsJet_minDMass_Eta,AK8Gen_HiggsJet_minDMass_Phi));

	  
    onShell_WBoson_Pt->Fill(gen_onShell_WBoson_Pt);
    offShell_WBoson_Pt->Fill(gen_offShell_WBoson_Pt);

    
  }
  // cutflow
  std::cout <<"Total:"<<countnumber[0]<<"->"<<countnumber[0]/countnumber[0]<<std::endl;
  std::cout <<"Cut1:"<<countnumber[1]<<"->"<<countnumber[1]/countnumber[0]<<std::endl;
  std::cout <<"Cut2:"<<countnumber[2]<<"->"<<countnumber[2]/countnumber[0]<<std::endl;
  std::cout <<"JJJJqqqq:"<<countnumber[3]<<"->"<<countnumber[3]/countnumber[0]<<std::endl;
  std::cout <<"Jqqqq:"<<countnumber[4]<<"->"<<countnumber[4]/countnumber[0]<<std::endl;
  std::cout <<"JJqqqq_MaxPt:"<<countnumber[5]<<"->"<<countnumber[5]/countnumber[0]<<std::endl;
  std::cout <<"JJqqqq_minDMass:"<<countnumber[6]<<"->"<<countnumber[6]/countnumber[0]<<std::endl;
  std::cout <<"JJqqqq_minWminHmass:"<<countnumber[7]<<"->"<<countnumber[7]/countnumber[0]<<std::endl;
  std::cout <<"JJJqqqq_minDMass:"<<countnumber[8]<<"->"<<countnumber[8]/countnumber[0]<<std::endl;
  std::cout <<"JJJqqqq_pTMax:"<<countnumber[9]<<"->"<<countnumber[9]/countnumber[0]<<std::endl;
  std::cout <<"HiggsJetmHcut:"<<countnumber[10]<<"->"<<countnumber[10]/countnumber[0]<<std::endl;
  std::cout <<"HiggsJetPtcut:"<<countnumber[11]<<"->"<<countnumber[11]/countnumber[0]<<std::endl;
  std::cout <<"Jqqqqaftermasspt:"<<countnumber[12]<<"->"<<countnumber[12]/countnumber[0]<<std::endl;
  std::cout <<"Jqqqqaftermasspt0.8:"<<countnumber[13]<<"->"<<countnumber[13]/countnumber[0]<<std::endl;
  std::cout <<"HiggsmaxJetmHcut:"<<countnumber[14]<<"->"<<countnumber[14]/countnumber[0]<<std::endl;
  std::cout <<"HiggsmaxJetPtcut:"<<countnumber[15]<<"->"<<countnumber[15]/countnumber[0]<<std::endl;
  std::cout <<"maxJqqqqaftermasspt:"<<countnumber[16]<<"->"<<countnumber[16]/countnumber[0]<<std::endl;
  std::cout <<"maxJqqqqaftermasspt0.8:"<<countnumber[17]<<"->"<<countnumber[17]/countnumber[0]<<std::endl;
  
  
  //TCanvas *c1 = new TCanvas();
  //AllResolved_onShellWboson_Pt->DrawNormalized();
  //AllResolved_onShellZboson_Pt->DrawNormalized("same");
  //c1->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/node1/AK4onShellWboson_Pt.png");
  //TCanvas *c2 = new TCanvas();
  //AllResolved_offShellWboson_Pt->DrawNormalized();
  //AllResolved_offShellZboson_Pt->DrawNormalized("same");
  //c2->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/node1/AK4offShellWboson_Pt.png");
  //TCanvas *c3 = new TCanvas();
  //onShell_WBoson_Pt->DrawNormalized();
  //onShell_ZBoson_Pt->DrawNormalized("same");
  //c3->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/node1/gen_onShell_Wboson_Pt.png");
  //TCanvas *c4 = new TCanvas();
  //offShell_WBoson_Pt->DrawNormalized();
  //offShell_ZBoson_Pt->DrawNormalized("same");
  //c4->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/node1/gen_offShell_Wboson_Pt.png");
  //TCanvas *c5 = new TCanvas();
  //AK4_AllResolved_onShellWboson_M->SetLineColor(1);
  //AK4_AllResolved_offShellWboson_M->SetLineColor(2);
  //AK4_AllResolved_Higgs_M->SetLineColor(3);
  //AK4_AllResolved_onShellWboson_M->DrawNormalized();
  //AK4_AllResolved_offShellWboson_M->DrawNormalized("same");
  //AK4_AllResolved_Higgs_M->DrawNormalized("same");
  //c5->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/node1/AK4_WWH_mass.png");
  TCanvas *c6 = new TCanvas();
  AK4_AllResolved_dR_J1_q->SetLineColor(1);
  AK4_AllResolved_dR_J2_q->SetLineColor(2);
  AK4_AllResolved_dR_J3_q->SetLineColor(3);
  AK4_AllResolved_dR_J4_q->SetLineColor(4);
  AK4_AllResolved_dR_J1_q->DrawNormalized();
  AK4_AllResolved_dR_J2_q->DrawNormalized("same");
  AK4_AllResolved_dR_J3_q->DrawNormalized("same");
  AK4_AllResolved_dR_J4_q->DrawNormalized("same");
  c6->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/SM/AK4_JJJJqqqq_dR.png");
  TCanvas *c7 = new TCanvas();
  AK8_HiggsJet_minDMass_deltaR_HWW->DrawNormalized();
  
  c7->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/SM/AK8_Higgsjets_minDMass_dR.png");
  TCanvas *c8 = new TCanvas();
  AK8_MergedWjets_dR_MaxPt_Leading_W->SetLineColor(1);
  AK8_MergedWjets_dR_MaxPt_SubLeading_W->SetLineColor(2);
  
  AK8_MergedWjets_dR_MaxPt_Leading_W->DrawNormalized();
  AK8_MergedWjets_dR_MaxPt_SubLeading_W->DrawNormalized("same");
 
  c8->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/SM/AK8_MergedWjets_MaxPt_dR.png");
  TCanvas *c9 = new TCanvas();
  AK8_MergedWjets_dR_minDMass_Leading_W->SetLineColor(1);
  AK8_MergedWjets_dR_minDMass_SubLeading_W->SetLineColor(2);
  
  AK8_MergedWjets_dR_minDMass_Leading_W->DrawNormalized();
  AK8_MergedWjets_dR_minDMass_SubLeading_W->DrawNormalized("same");
 
  c9->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/SM/AK8_MergedWjets_minDMass_dR.png");
  TCanvas *c10 = new TCanvas();
  AK8_MergedWjets_dR_minWminHmass_Leading_W->SetLineColor(1);
  AK8_MergedWjets_dR_minWminHmass_SubLeading_W->SetLineColor(2);
  
  AK8_MergedWjets_dR_minWminHmass_Leading_W->DrawNormalized();
  AK8_MergedWjets_dR_minWminHmass_SubLeading_W->DrawNormalized("same");
 
  c10->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/SM/AK8_MergedWjets_minWminHmass_dR.png");
  TCanvas *c11 = new TCanvas();
  HOneAK8TwoAK4_minMass_dR_ReconsW_AK4_W->SetLineColor(1);
  HOneAK8TwoAK4_minMass_dR_AK8_W->SetLineColor(2);
  
  HOneAK8TwoAK4_minMass_dR_ReconsW_AK4_W->DrawNormalized();
  HOneAK8TwoAK4_minMass_dR_AK8_W->DrawNormalized("same");
 
  c11->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/SM/OneAK8TwoAK4_minMass_dR.png");
  TCanvas *c12 = new TCanvas();
  HOneAK8TwoAK4_pTMax_leadingAK4_dR_q->SetLineColor(1);
  HOneAK8TwoAK4_pTMax_subleadingAK4_dR_q->SetLineColor(2);
  
  HOneAK8TwoAK4_pTMax_leadingAK4_dR_q->DrawNormalized();
  HOneAK8TwoAK4_pTMax_subleadingAK4_dR_q->DrawNormalized("same");
 
  c12->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/SM/OneAK8TwoAK4_pTMax_dR.png");
  TCanvas *c13 = new TCanvas();
  AK8_HiggsJet_minDMass_deltaR_H_q1->SetLineColor(1);
  AK8_HiggsJet_minDMass_deltaR_H_q2->SetLineColor(2);
  AK8_HiggsJet_minDMass_deltaR_H_q3->SetLineColor(3);
  AK8_HiggsJet_minDMass_deltaR_H_q4->SetLineColor(4);
  AK8_HiggsJet_minDMass_deltaR_H_q1->DrawNormalized();
  AK8_HiggsJet_minDMass_deltaR_H_q2->DrawNormalized("same");
  AK8_HiggsJet_minDMass_deltaR_H_q3->DrawNormalized("same");
  AK8_HiggsJet_minDMass_deltaR_H_q4->DrawNormalized("same");
  c13->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/SM/AK8_Higgsjets_minDMass_Jqqqq_dR.png");
  c12->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/SM/OneAK8TwoAK4_pTMax_dR.png");
  TCanvas *c14 = new TCanvas();
  AK8_HiggsJet_MaxPt_deltaR_H_q1->SetLineColor(1);
  AK8_HiggsJet_MaxPt_deltaR_H_q2->SetLineColor(2);
  AK8_HiggsJet_MaxPt_deltaR_H_q3->SetLineColor(3);
  AK8_HiggsJet_MaxPt_deltaR_H_q4->SetLineColor(4);
  AK8_HiggsJet_MaxPt_deltaR_H_q1->DrawNormalized();
  AK8_HiggsJet_MaxPt_deltaR_H_q2->DrawNormalized("same");
  AK8_HiggsJet_MaxPt_deltaR_H_q3->DrawNormalized("same");
  AK8_HiggsJet_MaxPt_deltaR_H_q4->DrawNormalized("same");
  c14->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/SM/AK8_Higgsjets_MaxPt_Jqqqq_dR.png");
  //TCanvas *c14 = new TCanvas();
  //testdR->DrawNormalized();
 
  //c14->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/makeplot/SM/test_dR.png");

}
