/*
 * QuineMcCluskey.h
 *
 *  Created on: Feb 17, 2018
 *      Author: jilin
 */

#ifndef QUINEMCCLUSKEY_H_
#define QUINEMCCLUSKEY_H_


#include <bitset>

#include <algorithm>

#include "Node.h"

class QuineMcCluskey
{
	public:
		Node* createQMc( vector<int> );
		vector<Implicant> initMinterms(  vector<int> );
		void createNextLevel( Node* );
		bool canCombine( Implicant, Implicant );
		string combineBitRep( string, string );
		bool isDupe( string, vector<Implicant> );
};


Node* createQMc( vector<int> minterms );

vector<Implicant> initMinterms(  vector<int> minterms  );

void createNextLevel( Node* prevLevel );

bool canCombine( Implicant num1, Implicant num2 );

string combineBitRep( string num1, string num2 );

bool isDupe( string key, vector<Implicant> curLevel );
#endif /* QUINEMCCLUSKEY_H_ */
