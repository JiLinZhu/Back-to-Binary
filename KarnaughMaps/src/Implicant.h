/*
 * Implicant.h
 *
 *  Created on: Feb 17, 2018
 *      Author: jilin
 */

#ifndef IMPLICANT_H_
#define IMPLICANT_H_

using namespace std;
#include <string>

class Implicant
{
	public:
		bool isPrimeImplicant;
		string bitRep;
		string key;
		int numOnes;

		bool canCombine( Implicant, Implicant );
		string combineBitRep( Implicant, Implicant );
};

bool canCombine( Implicant num1, Implicant num2 );

string combineBitRep( string num1, string num2 );

#endif /* IMPLICANT_H_ */
