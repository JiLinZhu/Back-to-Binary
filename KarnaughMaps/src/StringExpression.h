/*
 * StringExpression.h
 */

#ifndef STRINGEXPRESSION_H_
#define STRINGEXPRESSION_H_


#include "Libraries.h"

class StringExpression {
	public:
		string expression;
		int numVariables;
		vector<int> minterms;
		vector<int> dontCares;

		void initStringExpression( string );
		void evaluateExpression( string );
		void evaluateCombination( vector<bool>, int );
		vector<bool> findVariableCombination( int );
		void findNumVariables();
};

void initStringExpression( string expression );
void evaluateExpression( string expression );
void evaluateCombination( vector<bool> variableValues, int minterm );
vector<bool> findVariableCombination( int minterm );
void findNumVariables( void );

bool getBit( int num, int position );
bool isVariable( char a );

bool performOR( bool a, bool b );
bool performAND( bool a, bool b );
bool performXOR( bool a, bool b );
bool performNOT( bool a );

#endif /* STRINGEXPRESSION_H_ */
