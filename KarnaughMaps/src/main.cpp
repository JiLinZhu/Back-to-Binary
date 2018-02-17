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


class Implicant{

    bool isPrimeImplicant;

    string bitRep;
    string key;

    int numOnes;

};

struct Node {
	vector<Implicant> level;
  Node* next;
};


//Consider finding the largest minterm and making a sufficient number of bits to represent this
vector<Implicant> initializeMinterms(  vector<int> minterms  ) {
	vector<Implicant> firstLevel;

  	//Adding first level
	for ( int i = 0; i < minterms.size(); i++ ) {
		Implicant num = new Implicant();
		int numOnes = 0;

		num.isPrimeImplicant = true;
		num.bitRep = bitset<8>( minterms.at(i) ).to_string();

		//Counting how many ones are in the bit representation
		for(int k = 0; k < 8; k++) if(num.bitRep.at(k) == "1") numOnes++;

		num.numOnes = numOnes;

		firstLevel.push_back(num);
	}
  return firstLevel;
}


Node* initializeQuineMccluskey( vector<int> minterms ) {
	Node *quineMc = new Node;
	quineMc->level = initializeMinterms(  minterms  );
	quineMc->next = nullptr;
}
























