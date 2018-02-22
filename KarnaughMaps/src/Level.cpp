/*
Level.cpp
*/

#include "Level.h"

void Level::initLevel() {
	vector<Implicant> terms;
 	level = terms;
 	next = nullptr;
}

void Level::createNextLevel() {
	int numTerms = level.size();

	Level* curLevel = new Level;
	curLevel->initLevel();

	next = curLevel;

	for( int i = 0; i < numTerms-1; i++ ) {
  		for( int j = i+1; j < numTerms; j++ ) {
			if( level.at(i).canCombine( level.at(j) ) ) {
				level.at(i).isPrimeImplicant = false;
				level.at(j).isPrimeImplicant = false;
				string bitRep = level.at(i).combineBitRep( level.at(j) );
				string key = level.at(i).key + "," + level.at(j).key;
				int numOnes = min( level.at(i).numOnes, level.at(j).numOnes );

				Implicant term;
				term.initImplicant( level.at(i).numBits, numOnes, bitRep, key );

				if ( !isDupe( term.bitRep, next->level ) ) next->level.push_back(term);
			}
    		}
  	}
}

bool isDupe( string bitrep, vector<Implicant> curLevel ) {
	for( int i = 0; i < curLevel.size(); i++ ) {
		if ( curLevel.at(i).bitRep == bitrep ) return true;
	}
	return false;
}
