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
	initStringExpression( expression );
	removeSpace();
	for( int i = 0; i < pow( 2, numVariables ); i++ ) {
		vector<bool> variableValues = findVariableCombination( i );
		evaluateCombination( variableValues, i );
	}
}

void StringExpression::evaluateCombination( vector<bool> variableValues, int minterm ) {
	string result = solveRecursive( "(" + expression + ")", variableValues );
	if ( "1" == result ) this->minterms.push_back( minterm );
}

vector<bool> StringExpression::findVariableCombination( int minterm ) {
	vector<bool> variableValues;
	for( int i = numVariables - 1; i >= 0; i-- ) {
		variableValues.push_back( getBit( minterm, i ) );
	}
	return variableValues;
}

void StringExpression::findNumVariables() {
	string variables = "";
	for( int i = 0; i < expression.length(); i++ ) {
		if( expression.at(i) >= 97 && expression.at(i) <= 122 && variables.find( expression.at(i) ) == -1) {
			variables += expression.at(i);
			numVariables++;
		}
	}
}

void StringExpression::removeSpace() {
	int spaceIndex = expression.find( " " );
	while( spaceIndex != -1 ) {
		expression.erase( spaceIndex, 1 );
		spaceIndex = expression.find( " " );
	}
}

string solveRecursive( string curExpression, vector<bool> variableValues  ) {
	int curStartIndex = curExpression.find( '(', 1 );
	int curEndIndex = curExpression.find( ')', 1 );
	if ( -1 == curStartIndex ) {
		return evaluate( curExpression.substr( 1, curExpression.length() - 2 ), variableValues );
	} else {
		string substring = "";
		while( curEndIndex != curExpression.length() - 1 ) {
			substring = curExpression.substr( curStartIndex, curEndIndex - curStartIndex + 1 );
			if ( isBalanced( substring ) ) {
				curExpression.replace( curStartIndex, curEndIndex - curStartIndex + 1 , solveRecursive( substring, variableValues ) );
				curStartIndex = curExpression.find( '(', 1 );
				curEndIndex = curExpression.find( ')', 1 );
			} else curEndIndex = curExpression.find( ')', curEndIndex + 1 );
		}
		return evaluate( curExpression.substr( 1, curExpression.length() - 2 ), variableValues );
	}
}

string evaluate( string expression, vector<bool> variableValues ) {
	expression = evaluateNOT( expression, variableValues );
	expression = evaluateAND( expression, variableValues );
	expression = evaluateXOR( expression, variableValues );
	expression = evaluateOR( expression, variableValues );
	return expression;
}

string evaluateNOT( string expression, vector<bool> variableValues ) {
	bool post;
	int NOTindex = expression.find( '!' );
	while( NOTindex != -1 ) {
		if ( isVariable( expression.at(NOTindex + 1) ) ) post = variableValues.at( expression.at(NOTindex + 1) - 'a' );
		else if ( '0' == expression.at(NOTindex + 1) ) post = false;
		else post = true;

		string result = !post ? "1" : "0";
		expression.replace( NOTindex, 2, result );
		NOTindex = expression.find( '!' );
	}
	return expression;
}

string evaluateXOR( string expression, vector<bool> variableValues ) {
	bool pre, post;
	int XORindex = expression.find( '^' );
	while( XORindex != -1 ) {
		if ( isVariable( expression.at(XORindex - 1) ) ) pre = variableValues.at( expression.at(XORindex - 1) - 'a' );
		else if ( '0' == expression.at(XORindex - 1) ) pre = false;
		else pre = true;

		if ( isVariable( expression.at(XORindex + 1) ) ) post = variableValues.at( expression.at(XORindex + 1) - 'a' );
		else if ( '0' == expression.at(XORindex + 1) ) post = false;
		else post = true;

		string result = pre != post ? "1" : "0";
		expression.replace( XORindex - 1, 3, result );
		XORindex = expression.find( '^' );
	}
	return expression;
}

string evaluateAND( string expression, vector<bool> variableValues ) {
	bool pre, post;
	int ANDindex = expression.find( '*' );
	while( ANDindex != -1 ) {
		if ( isVariable( expression.at(ANDindex - 1) ) ) pre = variableValues.at( expression.at(ANDindex - 1) - 'a' );
		else if ( '0' == expression.at(ANDindex - 1) ) pre = false;
		else pre = true;

		if ( isVariable( expression.at(ANDindex + 1) ) ) post = variableValues.at( expression.at(ANDindex + 1) - 'a' );
		else if ( '0' == expression.at(ANDindex + 1) ) post = false;
		else post = true;

		string result = pre && post ? "1" : "0";
		expression.replace( ANDindex - 1, 3, result );
		ANDindex = expression.find( '*' );
	}
	return expression;
}

string evaluateOR( string expression, vector<bool> variableValues ) {
	bool pre, post;
	int ORindex = expression.find( '+' );
	while( ORindex != -1 ) {
		if ( isVariable( expression.at(ORindex - 1) ) ) pre = variableValues.at( expression.at(ORindex - 1) - 'a' );
		else if ( '0' == expression.at(ORindex - 1) ) pre = false;
		else pre = true;

		if ( isVariable( expression.at(ORindex + 1) ) ) post = variableValues.at( expression.at(ORindex + 1) - 'a' );
		else if ( '0' == expression.at(ORindex + 1) ) post = false;
		else post = true;

		string result = pre || post ? "1" : "0";
		expression.replace( ORindex - 1, 3, result );
		ORindex = expression.find( '+' );
	}
	return expression;
}

bool getBit( int num, int position ) {
	return num & ( 1 << position );
}

bool isBalanced( string expression ) {
	int balance = 0;
	for( int i = 0; i < expression.length(); i++ ) {
		if ( expression.at(i) == '(' ) balance++;
		else if ( expression.at(i) == ')' ) balance--;
		if ( balance < 0 ) return false;
	}
	return balance == 0;
}

bool isVariable( char a ) {
	return (a >= 97 && a <= 122);
}


