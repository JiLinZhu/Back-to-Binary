
/*
//Consider finding the largest minterm and making a sufficient number of bits to represent this
//Also consider don't cares
//Change 8 to be number bits dynamic in the future


//SOP, POS, NAND, NOR, take in boolean expression, recognize or?
//Min cost?

//Perhaps it would be beneficial for a member of QMcC object to be a linked list of the Level object
//Consider how to code this

//Perhaps consider doing maxterms?

 *
 * TO DO:
 * findEssentialImplicant(), given the prime implicants find all the essential primes
 * Efficiency is key here
 *
 * calculateMaxBits(), given the minterms, find the max number of bits required to represent all of them
 *
 * calculateMinterms(), given a BOOLEAN EXPRESSION, find what the minterms -> make QuineMc Table
 * This may be quite complicated, dunno if we need to worry about this for now
 *
 * findPossibleExpression() -- The essential implicants and prime implicants are passed.
 * This will be the most complicated, the result will entirely depend on what the user wants. This
 * will likely have a ton of sub functions. ie SOP, POS and all different possible expressions using the essential primes (and a combination of the primes)
 *
*/

#include <iostream>
#include "LogicExpression.h"

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

 	LogicExpression* a = new LogicExpression;
 	a->createQMc( minterms );
 	a->findEssentialImplicants();

 	Level *b = a->firstLevel;
	while( b != nullptr ) {
		for ( int i = 0; i < b->level.size(); i++ ) {
			cout << b->level.at(i).key << endl;
			cout << b->level.at(i).bitRep << endl;
		}
		cout << endl;
		b = b->next;
	}

	cout << "Prime Implicants" << endl;
	for ( int i = 0; i < a->primeImplicants.size(); i++ ) {
		cout << a->primeImplicants.at(i).key << endl;
		cout << a->primeImplicants.at(i).bitRep << endl;
	}
	cout << endl;

	cout << "Essential Implicants" << endl;
		for ( int i = 0; i < a->primeImplicants.size(); i++ ) {
			cout << a->essentialImplicants.at(i).key << endl;
			cout << a->essentialImplicants.at(i).bitRep << endl;
		}
	cout << endl;


}


