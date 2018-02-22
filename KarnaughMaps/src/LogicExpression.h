
#ifndef LOGICEXPRESSION_H_
#define LOGICEXPRESSION_H_

#include <bitset>
#include "Level.h"

class LogicExpression
{
	public:
		Level* firstLevel;
		vector<Implicant> minterms;
		vector<Implicant> primeImplicants;
		vector<Implicant> essentialImplicants;

		void initLogicExpression();
		void createQMc( vector<int> );
		vector<Implicant> initMintermLevel( vector<int> );
		void findPrimeImplicants();
		void findEssentialImplicants();
};

void initLogicExpression( void );

void createQMc( vector<int> minterms );

vector<Implicant> initMintermLevel( vector<int> minterms  );

void findPrimeImplicants( void );

void findEssentialImplicants( void );

#endif /* LOGICEXPRESSION_H_ */
