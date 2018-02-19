
#include "Level.h"
#include <iostream>

Level* initLevel() {
	vector<Implicant> terms;
	Level *nextLevel = new Level;
 	nextLevel->level = terms;
 	nextLevel->next = nullptr;
 	return nextLevel;
}

void createNextLevel( Level* prevLevel ) {
	int numTerms = prevLevel->level.size();

	Level* curLevel = initLevel();
	prevLevel->next = curLevel;

	for( int i = 0; i < numTerms-1; i++ ) {
  		for( int j = i+1; j < numTerms; j++ ) {
			if( canCombine( prevLevel->level.at(i) , prevLevel->level.at(j) ) ) {
				prevLevel->level.at(i).isPrimeImplicant = false;
				prevLevel->level.at(j).isPrimeImplicant = false;

				Implicant term;
				term.isPrimeImplicant = true;
				term.bitRep = combineBitRep( prevLevel->level.at(i).bitRep , prevLevel->level.at(j).bitRep );
				term.key = prevLevel->level.at(i).key + "," + prevLevel->level.at(j).key;
				term.numOnes = min( prevLevel->level.at(i).numOnes, prevLevel->level.at(j).numOnes );

				if ( !isDupe( term.bitRep, curLevel->level ) ) curLevel->level.push_back(term);
			}
    		}
  	}
}

bool canCombine( Implicant num1, Implicant num2 ) {
	int numDifferences = 0;

	if( abs(num1.numOnes - num2.numOnes) != 1 ) {
    		return false;
    } else {
		for( int i = 0; i < 8 ; i++ ) {
			if( num1.bitRep.at(i) != num2.bitRep.at(i) ) {
				if ( num1.bitRep.at(i) == '_' || num2.bitRep.at(i) == '_' ) return false;
				else numDifferences++;
			}
		}
    }

    return numDifferences == 1;
}

string combineBitRep( string key1, string key2 ) {
    int bit;
	for( int i = 0 ; i < 8; i++ ) {
		if( key1.at(i) != key2.at(i) )
			bit = i;
	}
	key1.at(bit) = '_';

	return key1;
}

bool isDupe( string bitrep, vector<Implicant> curLevel ) {
	for( int i = 0; i < curLevel.size(); i++ ) {
		if ( curLevel.at(i).bitRep == bitrep ) return true;
	}
	return false;
}
