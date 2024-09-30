#include <iostream>
using namespace std;
#include <vector>


/// TAC HEP GPU Modeul Course: Homework 1 by Fatima Rodriguez
// Forked github can be found here: https://github.com/fatimargz/tac-hep-gpus



// EXERCISE 1 : FUNCTION THAT SWAPS TWO INT VALUES
void swap_int(int &a, int &b){
	int a_cp = a;
	a = b;
	b = a_cp;
};

// EXERCISE 2: structure with name, email, username, experiment, etc.
struct TAC_HEP {
	string name;
	string email;
	string experiment;
	string school;
};


// function that takes the struct and prints out the values 
void print_struct(const TAC_HEP& x){
	cout << "Name: " << x.name << " , Email: " << x.email << ", Experiment: " << x.experiment << " , School: " << x.school << "\n" << endl;
};

// EXERCISE 3: Rock, Paper, Scissors, Shoot!
void RockPaperScissors(){ 
	string PLAYER1;

	cout << " Player 1, what's your move? (type 'rock', 'paper', or 'scissors') " ;
	getline(cin, PLAYER1);

	string rock = "rock";
	string paper = "paper";
	string scissors = "scissors";

	if (PLAYER1 != rock && PLAYER1 != paper && PLAYER1 != scissors){
	       cout << "Error: please check your spelling. Type 'rock', 'paper', or 'scissors'" ;
	       return;
	} 
	
	string PLAYER2;
	cout << " Player 2, what's your move? (type 'rock', 'paper', 'scissors') " ;
	getline(cin, PLAYER2);

	if (PLAYER2 != rock && PLAYER2 != paper && PLAYER2 != scissors){
		cout << "Error: please check your spelling. Type 'rock', 'paper', or 'scissors'" ;
		return;
	} 

	cout << "Rock, Paper, Scissors, Shoot! \n Player 1: " << PLAYER1 << " vs. Player 2: " << PLAYER2 << "\n";

	if (PLAYER1 == PLAYER2){
		cout << "It's a tie! Play again.";
	} else if (PLAYER1 == rock & PLAYER2 == paper){
		cout << "Player 2 wins!!";
	} else if (PLAYER1 == rock & PLAYER2 == scissors){
		cout << "Player 1 wins!!";
	} else if (PLAYER1 == paper & PLAYER2 == rock){
		cout << "Player 1 wins!!";
	} else if (PLAYER1 == paper & PLAYER2 == scissors){
		cout << "Player 2 wins!!";
	} else if (PLAYER1 == scissors & PLAYER2 == rock){
		cout << "Player 2 wins!!";
	}else if (PLAYER1 == scissors & PLAYER2 == paper){
		cout << "Player 1 wins!!";
	}
}

int main(){
	// EXERCISE 1
	// testing swap function 
	int a_test = 34;
	int b_test = 26;
	swap_int(a_test, b_test);
	cout << "The value of 'a' (should now be 26): " << a_test << endl;
	cout << "The value of 'b' (should now be 34): " << b_test << endl;
	// yup, that checked out. 
	// Creating two arrays A and B, that hold 10 integer numbers each. 
	vector<int> A = {0,1,2,3,4,5,6,7,8,9};
	vector<int> B = {10,11,12,13,14,15,16,17,18,19};
	// applying swap_int function to arrays
	for (size_t i; i<10;i++){
		cout << "Old " << i << " element of A: " << A[i] << endl;
		cout << "Old " << i << " element of B: " << B[i] << endl;
		swap_int(A[i], B[i]);
		cout << "New " << i << " element of A: " << A[i] << endl;
		cout << "New " << i << " element of B: " << B[i] << endl;
		// yup, this checked out. 
	}

	// EXERCISE 2 
	TAC_HEP fatima;
	fatima.name = "Fatima Rodriguez";
	fatima.email = "fatima@niu.edu";
	fatima.experiment = "ATLAS";
	fatima.school = "NIU";

	TAC_HEP hayden;
	hayden.name = "Hayden Shaddix";
	hayden.email = "hshaddix@niu.edu";
	hayden.experiment = "ATLAS";
	hayden.school = "NIU";

	TAC_HEP miranda;
	miranda.name = "Miranda Gorsuch";
	miranda.email = "mrgorsuch@wisc.edu";
	miranda.experiment = "Rubin Project";
	miranda.school = "University of Wisconsin-Madison";

	TAC_HEP michael;
	michael.name = "Machael Martinez";
	michael.email = "mnmartinez@wisc.edu";
	michael.experiment = "NRAO";
	michael.school = "University of Wisconsin-Madison";

	TAC_HEP frank;
	frank.name = "Frank Strug";
	frank.email = "fstrug2@uic.edu";
	frank.experiment = "CMS";
	frank.school = "UIC";

	TAC_HEP elliott;
	elliott.name = "Elliott Kauffman";
	elliott.email = "ek8842@princeton.edu";
	elliott.experiment = "CMS";
	elliott.school = "Princeton University";

	TAC_HEP ameya;
	ameya.name = "Ameya Thete";
	ameya.email = "thete@wisc.edu";
	ameya.school = "University of Wisconsin-Madison";
	ameya.experiment = "CMS";

	TAC_HEP lael;
	lael.name = "Lael Verace";
	lael.email = "lverace@wisc.edu";
	lael.school = "University of Wisconsin-Madison";
	lael.experiment = "CMS";

	TAC_HEP andrew;
	andrew.name = "Andrew Toler";
	andrew.email = "atoler@umass.edu";
	andrew.school = "University of Massachusetts Amherst";
	andrew.experiment = "ATLAS";

	TAC_HEP ashley;
	ashley.name = "Ashley Quinn";
	ashley.email = "aq3942@princeton.edu";
	ashley.school = "Princeton University";
	ashley.experiment = "CMS";

	TAC_HEP rupesh;
	rupesh.name = "Rupesh Kannan";
	rupesh.school = "University of Wisconsin-Madison";
	rupesh.experiment = "McDermott Group";
	rupesh.email = "rupesh.kannan@wisc.edu";

	vector<TAC_HEP> students = {fatima, hayden, miranda, michael, frank, elliott, ameya, lael, andrew, ashley, rupesh};
	for (int j; j<students.size(); j++){
		print_struct(students[j]);
	}

	// EXERCISE 3 : ROCK PAPER SCISSORS SHOOT
	RockPaperScissors();

}
