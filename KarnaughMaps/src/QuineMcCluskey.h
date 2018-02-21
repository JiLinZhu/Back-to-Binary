
#ifndef QUINEMCCLUSKEY_H_
#define QUINEMCCLUSKEY_H_

#include <bitset>
#include "Level.h"

class QuineMcCluskey
{
	public:
		Level* createKMap( vector<int> );
		vector<Implicant> initMinterms( vector<int> );
};


Level* createKMap( vector<int> minterms );

vector<Implicant> initMinterms( vector<int> minterms  );


#endif /* QUINEMCCLUSKEY_H_ */
