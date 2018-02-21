
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

		void initImplicant( string, string, int );
		bool canCombine( Implicant );
		string combineBitRep( Implicant );
};

void initImplicant( string bitRep, string key, int numOnes );

bool canCombine( Implicant other );

string combineBitRep( Implicant other );

#endif /* IMPLICANT_H_ */
