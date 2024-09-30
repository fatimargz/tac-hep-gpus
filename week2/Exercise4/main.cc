#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "t1.h"

#include <TMath.h>
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h> 
#include <TLorentzVector.h>



//------------------------------------------------------------------------------
// Particle Class
//
class Particle{

	public:
	Particle(){
	// FIXME : Create an additional constructor that takes 4 arguments --> the 4-momentum
	double   pt, eta, phi, E, m, p[4];
	void     p4(double, double, double, double);
	void     print();
	void     setMass(double);
	double   sintheta();
	}

	Particle(double particle_E, double particle_pt, double particle_eta, double particle_phi){
	double pt = particle_pt;
	double eta = particle_eta;
	double phi = particle_phi;
	double E = particle_E;
	void     p4(double, double, double, double);
        void     print();
        void     setMass(double);
        float   sintheta();
	}
};

//------------------------------------------------------------------------------

//*****************************************************************************
//                                                                             *
//    MEMBERS functions of the Particle Class                                  *
//                                                                             *
//*****************************************************************************

//
//*** Default constructor ------------------------------------------------------
//
Particle::Particle(){
	pt = eta = phi = E = m = 0.0;
	p[0] = p[1] = p[2] = p[3] = 0.0;
}

//*** Additional constructor ------------------------------------------------------
Particle::Particle(double particle_E, double particle_pt, double particle_eta, double particle_phi){
	p[0] = particle_E;
	p[1] = particle_pt;
	p[2] = particle_eta;
	p[3] = particle_phi;

}

//
//*** Members  ------------------------------------------------------
//
double Particle::sintheta(){
	double pz = pt * sinh(eta);
	double p_mag = sqrt(pow(pt,2) + pow(pz,2));
	double sine_theta = pt/p_mag;
			
}

void Particle::p4(double pT, double eta, double phi, double energy){
	vector<double> = {pt,eta,phi,energy}

}

void Particle::setMass(double mass)
{
	m = mass; // not sure what this should be
}

//
class Lepton : public Particle {
	public:
		Lepton(double charge) {
			double q = charge;
		}
		void print_q();
}


void print_q(){
	cout << " Lepton charge:\n" << q << endl;
}



class Jets : public Particle {
	public:
		Jet(int flavor){
			int f = flavor;
		}
		void print_f();
}

void print_f(){
	if (f == 5){
		cout << " Jet originates from b-hadrons" ;
	} else if (f ==4) {
		cout << "Jet originates from c-hadron";
	} else if (f == 0) {
		cout << "Jet originates from u,d,s hadrons or gluons" << endl;

//*** Prints 4-vector ----------------------------------------------------------
//
void Particle::print(){
	std::cout << std::endl;
	std::cout << "(" << p[0] <<",\t" << p[1] <<",\t"<< p[2] <<",\t"<< p[3] << ")" << "  " <<  sintheta() << std::endl;
}

int main() {
	
	/* ************* */
	/* Input Tree   */
	/* ************* */

	TFile *f      = new TFile("input.root","READ");
	TTree *t1 = (TTree*)(f->Get("t1"));

	// Read the variables from the ROOT tree branches
	t1->SetBranchAddress("lepPt",&lepPt);
	t1->SetBranchAddress("lepEta",&lepEta);
	t1->SetBranchAddress("lepPhi",&lepPhi);
	t1->SetBranchAddress("lepE",&lepE);
	t1->SetBranchAddress("lepQ",&lepQ);
	
	t1->SetBranchAddress("njets",&njets);
	t1->SetBranchAddress("jetPt",&jetPt);
	t1->SetBranchAddress("jetEta",&jetEta);
	t1->SetBranchAddress("jetPhi",&jetPhi);
	t1->SetBranchAddress("jetE", &jetE);
	t1->SetBranchAddress("jetHadronFlavour",&jetHadronFlavour);

	// Total number of events in ROOT tree
	Long64_t nentries = t1->GetEntries();

	for (Long64_t jentry=0; jentry<100;jentry++)
 	{
		t1->GetEntry(jentry);
		std::cout<<" Event "<< jentry <<std::endl;	

		


	} // Loop over all events

  	return 0;
}
