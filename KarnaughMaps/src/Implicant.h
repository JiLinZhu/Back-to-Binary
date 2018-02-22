/*
Implicant.h
*/

#ifndef IMPLICANT_H_
#define IMPLICANT_H_

#include "Libraries.h"

class Implicant
{
	public:
		int numBits;
		int numOnes;
		string bitRep;
		string key;
		bool isPrimeImplicant;

		void initImplicant( int, int, string, string );
		bool canCombine( Implicant );
		string combineBitRep( Implicant );
		bool containsMinterm( string );
};

void initImplicant( int numBits, int numOnes, string bitRep, string key );

bool canCombine( Implicant other );

string combineBitRep( Implicant other );

bool containsMinterm( string minterm );

#endif /* IMPLICANT_H_ */
