/*
 * Implicant.cpp
 *
 *  Created on: Feb 17, 2018
 *      Author: jilin
 */

#include "Implicant.h"

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
