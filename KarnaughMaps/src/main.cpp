/*
//Consider finding the largest minterm and making a sufficient number of bits to represent this
//Also consider don't cares
//Change 8 to be number bits dynamic in the future

//Gotta Code an Order Function so that say 24 + 35 -> 2 3 4 5
//Get rid of dupes

*/
using namespace std;
#include <bitset>
#include <iostream>
#include <vector>

#include "QuineMcCluskey.h"

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

Node* initNode() {
	vector<Implicant> terms;
	Node *nextNode = new Node;
 	nextNode->level = terms;
 	nextNode->next = nullptr;
 	return nextNode;
}

bool canCombine( Implicant num1, Implicant num2 ) {
	int numDifferences = 0;

	if( abs(num1.numOnes - num2.numOnes) != 1 ) {
    		return false;
    } else {
    	//Change 8 to be number bits dynamic in the future
		for( int i = 0; i < 8 ; i++ ) {
			if( num1.bitRep.at(i) != num2.bitRep.at(i) )
				numDifferences++;
		}
    }
    return numDifferences == 1;
}


string combineBitRep( string num1, string num2 ) {
    int bit;
	for( int i = 0 ; i < 8; i++ ) {
		if( num1.at(i) != num2.at(i) )
			bit = i;
	}

	num1.at(bit) = '_';

	return num1;
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


Node* createQMc( vector<int> minterms ) {
	Node* quineMc = initNode();
	quineMc->level = initMinterms( minterms );
	createNextLevel( quineMc );

	return quineMc;
}


int main( void ) {
 	vector<int> minterms;
 	minterms.push_back(0);
	minterms.push_back(1);
 	minterms.push_back(3);
 	minterms.push_back(7);
 	minterms.push_back(15);
	Node *a = createQMc( minterms );

	for ( int i = 0; i < a->level.size(); i++ ) {
		cout << a->level.at(i).bitRep << endl;
	}
	for ( int i = 0; i < a->next->level.size(); i++ ) {
		cout << a->next->level.at(i).bitRep << endl;
	}
}




















