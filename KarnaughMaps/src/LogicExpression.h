/*
LogicExpression.h
*/

#ifndef LOGICEXPRESSION_H_
#define LOGICEXPRESSION_H_

#include "Level.h"

class LogicExpression
{
	public:
		int numVariables;

		Level* firstLevel;
		vector<Implicant> minterms;
		vector<Implicant> dontCares;
		vector<Implicant> primeImplicants;
		vector<Implicant> essentialImplicants;

		void initLogicExpression();
		void createQMc( vector<int>, vector<int> );
		void findNumVariables( vector<int>, vector<int> );
		void initMintermLevel( vector<int> );
		void initDontCares( vector<int> );
		void findPrimeImplicants();
		void findEssentialImplicants();
		void printMinterms();
		void printImplicants();
		void printPrimeImplicants();
		void printEssentialImplicants();
};

void initLogicExpression( void );

void createQMc( vector<int> minterms, vector<int> dontCares );

void findNumVariables( vector<int> minterms, vector<int> dontCares );

void initMintermLevel( vector<int> minterms );

void initDontCares( vector<int> dontCares );

void findPrimeImplicants( void );

void findEssentialImplicants( void );

void printImplicants( void );

void printMinterms( void );

void printPrimeImplicants( void );

void printEssentialImplicants( void );

#endif /* LOGICEXPRESSION_H_ */
