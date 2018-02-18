/*
 * QuineMcCluskey.h
 *
 *  Created on: Feb 17, 2018
 *      Author: jilin
 */

#ifndef QUINEMCCLUSKEY_H_
#define QUINEMCCLUSKEY_H_


using namespace std;
#include <vector>
#include "Implicant.h"

class QuineMcCluskey {
	public:
		struct Node;
		class Implicant;

		Node* createQMc( vector<int> );
		vector<Implicant> initMinterms(  vector<int> );
		void createNextLevel( Node* );
};

struct Node {
	vector<Implicant> level;
	Node* next;
};

Node* initNode();

Node* createQMc( vector<int> minterms );

vector<Implicant> initMinterms(  vector<int> minterms  );

void createNextLevel( Node* prevLevel );


#endif /* QUINEMCCLUSKEY_H_ */
