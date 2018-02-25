/*
 * Implicant.cpp
 */

#include "Implicant.h"

void Implicant::initImplicant( int numBits, int numOnes, string bitRep, string key ) {
	this->numBits = numBits;
	this->numOnes = numOnes;
	this->bitRep = bitRep;
	this->key = key;
	this->isPrimeImplicant = true;
}

bool Implicant::canCombine( Implicant other ) {
	int numDifferences = 0;

	if( abs( numOnes - other.numOnes ) != 1 ) return false;
    else {
		for( int i = 0; i < numBits ; i++ ) {
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
	for( int i = 0 ; i < numBits; i++ ) {
		if( bitRep.at(i) != other.bitRep.at(i) )
			bit = i;
	}
	other.bitRep.at(bit) = '_';

	return other.bitRep;
}

bool Implicant::containsMinterm( string minterm ) {
	int index = 0, commaIndex = key.find( "," );
	while( commaIndex != -1 ) {
		if( minterm == key.substr(index, commaIndex-index) ) return true;
		index = commaIndex + 1;
		commaIndex = key.find( ",", index + 1 );
	}
	return minterm == key.substr( key.rfind( "," ) + 1 );
}
