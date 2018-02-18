/*
 * QuineMcCluskey.c
 *
 *  Created on: Feb 17, 2018
 *      Author: jilin
 */


using namespace std;

#include "QuineMcCluskey.h"

Node* initNode() {
	vector<Implicant> terms;
	Node *nextNode = new Node;
 	nextNode->level = terms;
 	nextNode->next = nullptr;
 	return nextNode;
}

Node* createQMc( vector<int> minterms ) {
	Node* quineMc = initNode();
	quineMc->level = initMinterms( minterms );
	createNextLevel( quineMc );

	return quineMc;
}


vector<Implicant> initMinterms(  vector<int> minterms  ) {
	vector<Implicant> firstLevel;

  	//Adding first level
	for( int i = 0; i < minterms.size(); i++ ) {
		Implicant minterm;
		int numOnes = 0;

		minterm.isPrimeImplicant = true;
		minterm.bitRep = bitset<8>( minterms.at(i) ).to_string();
		minterm.key = minterms.at(i);

		//Counting how many ones are in the bit representation
		for( int k = 0; k < 8; k++ ) {
			if( minterm.bitRep.at(k) == '1' )
				numOnes++;
		}
		minterm.numOnes = numOnes;

		firstLevel.push_back(minterm);
	}
	return firstLevel;
}



void createNextLevel( Node* prevLevel ) {
	int numTerms = prevLevel->level.size();

	Node* nextLevel = initNode();
	prevLevel->next = nextLevel;

	for( int i = 0; i < numTerms-1; i++ ) {
  		for( int j = i+1; j < numTerms; j++ ) {
			if( canCombine( prevLevel->level.at(i) , prevLevel->level.at(j) ) ) {
				Implicant term;
				term.isPrimeImplicant = true;
				term.bitRep = combineBitRep( prevLevel->level.at(i).bitRep , prevLevel->level.at(j).bitRep );

				//Gotta Code an Order Function so that say 24 + 35 -> 2 3 4 5
				term.key = prevLevel->level.at(i).key + prevLevel->level.at(j).key;
				term.numOnes = min( prevLevel->level.at(i).numOnes, prevLevel->level.at(j).numOnes );
				//Get rid of dupes
				nextLevel->level.push_back(term);
			}
    		}
  	}
}




