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

string solveRecursive( string curExpression, vector<bool> variableValues );

string evaluate( string expression, vector<bool> variableValues );
string evaluateNOT( string expression, vector<bool> variableValues );
string evaluateXOR( string expression, vector<bool> variableValues );
string evaluateAND( string expression, vector<bool> variableValues );
string evaluateOR( string expression, vector<bool> variableValues );

bool getBit( int num, int position );
bool isBalanced( string expression );
bool isVariable( char a );

#endif /* STRINGEXPRESSION_H_ */
