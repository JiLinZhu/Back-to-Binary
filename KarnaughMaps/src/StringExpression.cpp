/*
 * StringExpression.cpp
 */

#include "StringExpression.h"

void StringExpression::initStringExpression( string expression ) {
	vector<int> minterms;
	vector<int> dontCares;

	this->numVariables = 0;
	this->expression = expression;
	findNumVariables();
	this->minterms = minterms;
	this->dontCares = dontCares;
}

void StringExpression::evaluateExpression( string expression ) {
	vector<bool> variableValues;

	initStringExpression( expression );
	for( int i = 0; i < pow( 2, numVariables ); i++ ) {
		vector<bool> variableValues = findVariableCombination( i );
		evaluateCombination( variableValues, i );
	}
}

void StringExpression::evaluateCombination( vector<bool> variableValues, int minterm ) {
	string temp = expression;
	string result;

	string result = solveRecursive( temp, variableValues, 0, temp.length() );

	int ORindex = temp.find( '|' );
	while( ORindex != -1 ) {
		char pre = temp.at(ORindex - 1);
		char post = temp.at(ORindex + 1);
		if ( !isVariable( pre ) && !isVariable( post ) ){
			result = performOR( pre, post ) ? "1" : "0";
		} else if ( !isVariable( pre ) ) {
			result = performOR( pre, variableValues.at( post - 'a' ) ) ? "1" : "0";
		} else if( !isVariable( post ) ) {
			result = performOR( variableValues.at( pre - 'a' ), post ) ? "1" : "0";
		} else {
			result = performOR( variableValues.at( pre - 'a' ), variableValues.at( post - 'a' ) ) ? "1" : "0";
		}
		temp.replace( ORindex - 1, 3, result);
		ORindex = temp.find( '|' );
	}
	if ( '1' == temp ) this->minterms.push_back( minterm );
}

string solveRecursive( string curExpression, int variableValues, int prevStartIndex, int prevEndIndex ) {
	int curStartIndex = curExpression.find( '(', prevStartIndex + 1 );
	int curEndIndex = curExpression.rfind( ')', prevEndIndex - 1);
	if (  )
}

vector<bool> StringExpression::findVariableCombination( int minterm ) {
	vector<bool> variableValues;
	for( int i = 0; i < numVariables; i++ ) {
		variableValues.push_back( getBit( minterm, i ) );
	}
	return variableValues;
}


void StringExpression::findNumVariables() {
	string variables = "";
	for( int i = 0; i < expression.length(); i++ ) {
		if( expression.at(i) >= 97 && expression.at(i) <= 122 && variables.find( expression.at(i) ) == string::npos ) { //could simplify to !?
			variables += expression.at(i);
			numVariables++;
		}
	}
}

bool getBit( int num, int position ) {
	return num & ( 1 << position );
}

bool isVariable( char a ) {
	return (a >= 97 && a <= 122);
}

bool performOR( bool a, bool b ) {
	return a || b;
}

bool performAND( bool a, bool b ) {
	return a && b;
}

bool performXOR( bool a, bool b ) {
	return a ^ b;
}

bool performNOT( bool a ) {
	return !a;
}



