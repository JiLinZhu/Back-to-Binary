
/*
//Could do 8 input if we use a cube + 4 buttons

//SOP, POS, NAND, NOR, take in boolean expression, recognize XOR
//Min cost

//Perhaps consider doing maxterms?

//Consider using Boost Library

//SortLevel function?
 * TO DO:
 *
 *Currently, the string expression requires you to use variables starting at the start of the alphabet without skipping any. Perhaps think of a way to allow for any
 *Choice of variable
 *
 *
 *Level::sortLevel() function, it might be better to simply sort the minterms before you creating any levels. Think about this.
 *
 * findPossibleExpression() -- The essential implicants and prime implicants are passed.
 * This will be the most complicated, the result will entirely depend on what the user wants. This
 * will likely have a ton of sub functions. ie SOP, POS and all different possible expressions using the essential primes (and a combination of the primes)
 *
*/

#include "LogicExpression.h"
#include "StringExpression.h"

int main( void ) {
	StringExpression* s = new StringExpression;
	s->evaluateExpression( "a  ^((b*  (a*  c)*(d+c)+(a*b))*b)" );


 	vector<int> minterms;
 	vector<int> dontCares;

// 	minterms.push_back(0);
 	minterms.push_back(1);
//	minterms.push_back(2);
	minterms.push_back(3);
	minterms.push_back(4);
	minterms.push_back(5);
//	minterms.push_back(6);
//	minterms.push_back(7);
//	minterms.push_back(8);
// 	minterms.push_back(9);
// 	minterms.push_back(10);
 	minterms.push_back(11);
 	minterms.push_back(12);
 	minterms.push_back(13);
 	minterms.push_back(14);
 	minterms.push_back(15);
// 	minterms.push_back(16);

//    dontCares.push_back(0);
// 	dontCares.push_back(1);
//	dontCares.push_back(2);
// 	dontCares.push_back(3);
// 	dontCares.push_back(4);
// 	dontCares.push_back(5);
//	dontCares.push_back(6);
//	dontCares.push_back(7);
//  dontCares.push_back(8);
// 	dontCares.push_back(9);
// 	dontCares.push_back(10);
// 	dontCares.push_back(11);
// 	dontCares.push_back(12);
// 	dontCares.push_back(13);
// 	dontCares.push_back(14);
// 	dontCares.push_back(15);
// 	dontCares.push_back(16);

 	LogicExpression* a = initLogicExpression();

 	a->createQMc( s->minterms, dontCares );
 	a->findEssentialImplicants();

 	a->printImplicants();
 	a->printMinterms();
 	a->printPrimeImplicants();
 	a->printEssentialImplicants();

}


