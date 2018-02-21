
#include "QuineMcCluskey.h"

Level* createKMap( vector<int> minterms ) {
	Level* quineMc = new Level;
	quineMc->initLevel();
	quineMc->level = initMinterms( minterms );

	Level* temp = quineMc;
	while ( temp->level.size() > 0 ) {
		temp->createNextLevel();
		temp = temp->next;
	}
	temp = nullptr;
	return quineMc;
}

vector<Implicant> initMinterms(  vector<int> minterms  ) {
	vector<Implicant> firstLevel;

	for( int i = 0; i < minterms.size(); i++ ) {
		Implicant minterm;
		int numOnes = 0;

		minterm.isPrimeImplicant = true;
		minterm.bitRep = bitset<8>( minterms.at(i) ).to_string();
		minterm.key = to_string( minterms.at(i) );

		//Counting how many ones are in the bit representation
		for( int k = 0; k < 8; k++ ) {
			if( minterm.bitRep.at(k) == '1' )
				numOnes++;
		}
		minterm.numOnes = numOnes;

		if ( !isDupe( minterm.bitRep, firstLevel ) ) firstLevel.push_back(minterm);
	}
	return firstLevel;
}

