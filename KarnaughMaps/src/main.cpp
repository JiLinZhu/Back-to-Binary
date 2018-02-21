
/*
//Consider finding the largest minterm and making a sufficient number of bits to represent this
//Also consider don't cares
//Change 8 to be number bits dynamic in the future


//SOP, POS, NAND, NOR, take in boolean expression, recognize or?
//Min cost?
*/

#include <iostream>
#include "QuineMcCluskey.h"

int main( void ) {
 	vector<int> minterms;

 	minterms.push_back(0);
 	minterms.push_back(1);
	minterms.push_back(2);
	minterms.push_back(3);
	minterms.push_back(4);
	minterms.push_back(5);
	minterms.push_back(6);
	minterms.push_back(7);
	minterms.push_back(8);
 	minterms.push_back(9);
 	minterms.push_back(10);
 	minterms.push_back(11);
 	minterms.push_back(12);
 	minterms.push_back(13);
 	minterms.push_back(14);
 	minterms.push_back(15);

	Level *a = createKMap( minterms );

	while( a != nullptr ) {
		for ( int i = 0; i < a->level.size(); i++ ) {
			//cout << a->level.at(i).key << " " << a->level.at(i).isPrimeImplicant << endl;
			cout << a->level.at(i).bitRep << endl;
		}
		cout << endl;
		a = a->next;
	}
}


