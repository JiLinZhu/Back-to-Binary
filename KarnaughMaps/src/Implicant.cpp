
#include "Implicant.h"

void Implicant::initImplicant( string bitRep, string key, int numOnes ) {
	this->isPrimeImplicant = true;
	this->bitRep = bitRep;
	this->key = key;
	this->numOnes = numOnes;
}

bool Implicant::canCombine( Implicant other ) {
	int numDifferences = 0;

	if( abs( numOnes - other.numOnes ) != 1 ) return false;
    else {
		for( int i = 0; i < 8 ; i++ ) {
			if( bitRep.at(i) != other.bitRep.at(i) ) {
				if ( bitRep.at(i) == '_' || other.bitRep.at(i) == '_' ) return false;
				else numDifferences++;
			}
		}
    }
    return numDifferences == 1;
}

string Implicant::combineBitRep( Implicant other ) {
    int bit;
	for( int i = 0 ; i < 8; i++ ) {
		if( bitRep.at(i) != other.bitRep.at(i) )
			bit = i;
	}
	other.bitRep.at(bit) = '_';

	return other.bitRep;
}

