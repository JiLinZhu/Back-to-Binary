
#ifndef LEVEL_H_
#define LEVEL_H_

#include <vector>
#include "Implicant.h"

class Level
{
	public:
		vector<Implicant> level;
		Level* next;
		Level* initLevel( void );
		void createNextLevel( Level* );
		bool canCombine( Implicant, Implicant );
		string combineBitRep( string, string );
		string orderTerms( string, string );
		bool isDupe( string, vector<Implicant> );
};

Level* initLevel( void );

void createNextLevel( Level* prevLevel );

bool canCombine( Implicant num1, Implicant num2 );

string combineBitRep( string key1, string key2 );

string orderTerms( string key1, string key2 );

bool isDupe( string key, vector<Implicant> curLevel );

#endif /* LEVEL_H_ */
