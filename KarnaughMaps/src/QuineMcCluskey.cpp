/*
 * QuineMcCluskey.c
 *
 *  Created on: Feb 17, 2018
 *      Author: jilin
 */

#include "QuineMcCluskey.h"


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


string orderTerms(string num1, string num2){
	vector<int> termValue;
	string parsedNumber = "";
	string parsedNumber2 = "";
	string orderedTerms = "";
	
	int index = 0;
	int index2 = 0;
	int comma1 = 0;
	int comma2 = 0;
	
	while(comma1 != -1 || comma2 != -1){
		comma1 = num1.find(',', index);
		comma2 = num2.find(',' , index2);
		
		parsedNumber = num1.substr(index,comma1);
		parsedNumber2 = num2. substr(index2, comma2);
		
		if(stoi(parsedNumber) > stoi(parsedNumber2)){
			orderedTerms += parsedNumber + ',';
			index = comma1 +1;
		}
		
		else if(stoi(parsedNumber) < stoi(parsedNumber2)){
			orderedTerms += parsedNumber2 + ',';
			index2 = comma2 +2;
		}
		
		else{
			orderedTerms += parsedNumber + ',' + parsedNumber2 + ',';
			index = comma1 + 1;
			index2 = comma2 + 1;
		}
	}
	
	if(comma1 = -1){
		orderedTerms += num2.substr(index2, num2.length());
	}
	else{
		orderedTerms += num1.substr(index,num1.length());
	}
	
	return orderedTerms;
}


