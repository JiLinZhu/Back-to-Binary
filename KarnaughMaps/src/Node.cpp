/*
 * Node.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: jilin
 */


#include "Node.h"

Node* initNode() {
	vector<Implicant> terms;
	Node *nextNode = new Node;
 	nextNode->level = terms;
 	nextNode->next = nullptr;
 	return nextNode;
}
