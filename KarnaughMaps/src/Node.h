/*
 * Node.h
 *
 *  Created on: Feb 19, 2018
 *      Author: jilin
 */

#ifndef NODE_H_
#define NODE_H_

#include <vector>
#include "Implicant.h"

class Node
{
	public:
		vector<Implicant> level;
		Node* next;
		Node* initNode( void );
};

Node* initNode( void );

#endif /* NODE_H_ */
