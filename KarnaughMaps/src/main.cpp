
/*
//Consider finding the largest minterm and making a sufficient number of bits to represent this
//Also consider don't cares
//Change 8 to be number bits dynamic in the future

//Gotta Code an Order Function so that say 24 + 35 -> 2 3 4 5
//Get rid of dupes

*/
using namespace std;
#include <bitset>
#include <iostream>


#include "QuineMcCluskey.h"

int main( void ) {
 	vector<int> minterms;
 	minterms.push_back(0);
	minterms.push_back(1);
 	minterms.push_back(3);
 	minterms.push_back(7);
 	minterms.push_back(15);
	Node *a = createQMc( minterms );

	for ( int i = 0; i < a->level.size(); i++ ) {
		cout << a->level.at(i).bitRep << endl;
	}
	for ( int i = 0; i < a->next->level.size(); i++ ) {
		cout << a->next->level.at(i).bitRep << endl;
	}
	delete(a);
}

