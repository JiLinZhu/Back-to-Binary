
#include "Level.h"

Level* initLevel() {
	vector<Implicant> terms;
	Level *nextLevel = new Level;
 	nextLevel->level = terms;
 	nextLevel->next = nullptr;
 	return nextLevel;
}

void createNextLevel( Level* prevLevel ) {
	int numTerms = prevLevel->level.size();

	Level* curLevel = initLevel();
	prevLevel->next = curLevel;

	for( int i = 0; i < numTerms-1; i++ ) {
  		for( int j = i+1; j < numTerms; j++ ) {
			if( canCombine( prevLevel->level.at(i) , prevLevel->level.at(j) ) ) {
				prevLevel->level.at(i).isPrimeImplicant = false;
				prevLevel->level.at(i).isPrimeImplicant = false;

				Implicant term;
				term.isPrimeImplicant = true;
				term.bitRep = combineBitRep( prevLevel->level.at(i).bitRep , prevLevel->level.at(j).bitRep );
				term.key = orderTerms( prevLevel->level.at(i).key, prevLevel->level.at(j).key );
				term.numOnes = min( prevLevel->level.at(i).numOnes, prevLevel->level.at(j).numOnes );

				if ( !isDupe( term.key, curLevel->level ) ) curLevel->level.push_back(term);
			}
    		}
  	}
}

bool canCombine( Implicant num1, Implicant num2 ) {
	int numDifferences = 0;

	if( abs(num1.numOnes - num2.numOnes) != 1 ) {
    		return false;
    } else {
		for( int i = 0; i < 8 ; i++ ) {
			if( num1.bitRep.at(i) != num2.bitRep.at(i) ) {
				if ( num1.bitRep.at(i) == '_' || num2.bitRep.at(i) == '_' ) return false;
				else numDifferences++;
			}
		}
    }

    return numDifferences == 1;
}

string combineBitRep( string num1, string num2 ) {
    int bit;
	for( int i = 0 ; i < 8; i++ ) {
		if( num1.at(i) != num2.at(i) )
			bit = i;
	}
	num1.at(bit) = '_';

	return num1;
}

string orderTerms( string num1, string num2 ) {

    int parsedNumber1 = 0, parsedNumber2 = 0;
    string orderedTerms = "";

    int index1 = 0, index2 = 0, comma1 = 0, comma2 = 0;

    while( comma1 != -1 || comma2 != -1 ){
        comma1 = num1.find( ',', index1 );
        comma2 = num2.find( ',', index2 );
        parsedNumber1 = stoi( num1.substr( index1, comma1 ) );
        parsedNumber2 = stoi( num2.substr( index2, comma2 ) );

        if( parsedNumber1 > parsedNumber2 ){
            orderedTerms += parsedNumber1 + ',';
            index1 = comma1 + 1;
        } else {
            orderedTerms += parsedNumber2 + ',';
            index2 = comma2 + 1;
        }
    }

    if( -1 == comma1 ) orderedTerms += num2.substr( index2 + 1, num2.length() );
    else orderedTerms += num1.substr( index1 + 1, num1.length() );

    return orderedTerms;
}

bool isDupe( string key, vector<Implicant> curLevel ) {
	for( int i = 0; i < curLevel.size(); i++ ) {
		if ( curLevel.at(i).key == key ) return true;
	}
	return false;
}
