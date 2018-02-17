/*
 * main.c
 *
 *  Created on: Feb 17, 2018
 *      Author: jilin
 */

using namespace std;
#include <bitset>
#include <iostream>
#include <vector>


<<<<<<< HEAD
class Implicant{
	public:
=======
 class Implicant{
	public:
	
>>>>>>> 0a88676bb82d56dcc2d4bf27e142614c7299fc94
		bool isPrimeImplicant;

		string bitRep;
		string key;

		int numOnes;

};

struct Node {
<<<<<<< HEAD
	vector<Implicant> level;
=======
	vector<Implicant*> level;
>>>>>>> 0a88676bb82d56dcc2d4bf27e142614c7299fc94
	Node* next;
};


//Consider finding the largest minterm and making a sufficient number of bits to represent this
vector <Implicant*> initializeMinterms(  vector<int> minterms  ) {
	vector<Implicant*> firstLevel;

  	//Adding first level
	for ( int i = 0; i < minterms.size(); i++ ) {
<<<<<<< HEAD
		Implicant minterm;
		int numOnes = 0;

		minterm.isPrimeImplicant = true;
		minterm.bitRep = bitset<8>( minterms.at(i) ).to_string();

		//Counting how many ones are in the bit representation
		for(int k = 0; k < 8; k++) if( minterm.bitRep.at(k) == 1 ) numOnes++;

		minterm.numOnes = numOnes;
=======
		Implicant *minterm = new Implicant();
		int numOnes = 0;

		minterm->isPrimeImplicant = true;
		minterm->bitRep = bitset<8>( minterms.at(i) ).to_string();

		//Counting how many ones are in the bit representation
		for(int k = 0; k < 8; k++) if(minterm->bitRep.at(k) == 1) numOnes++;

		minterm->numOnes = numOnes;
>>>>>>> 0a88676bb82d56dcc2d4bf27e142614c7299fc94

		firstLevel.push_back(minterm);
	}
  return firstLevel;
}


Node* initializeQMc( vector<int> minterms ) {
	Node *quineMc = new Node;
	quineMc->level = initializeMinterms(  minterms  );
	quineMc->next = nullptr;

	return quineMc;
}


int main( void ) {
	vector<int> minterms;
	minterms.push_back(2);
	minterms.push_back(4);
	minterms.push_back(9);
	Node *a = initializeQMc( minterms );

	cout << a->level.at(0).bitRep << endl;
}




















