
#ifndef QUINEMCCLUSKEY_H_
#define QUINEMCCLUSKEY_H_

#include <bitset>

#include "Level.h"

class QuineMcCluskey
{
	public:
		Level* createQMc( vector<int> );
		vector<Implicant> initMinterms(  vector<int> );
};


Level* createQMc( vector<int> minterms );

vector<Implicant> initMinterms(  vector<int> minterms  );


#endif /* QUINEMCCLUSKEY_H_ */
