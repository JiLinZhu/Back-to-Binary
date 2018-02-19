
#include "Level.h"
#include <iostream>

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

string combineBitRep( string key1, string key2 ) {
    int bit;
	for( int i = 0 ; i < 8; i++ ) {
		if( key1.at(i) != key2.at(i) )
			bit = i;
	}
	key1.at(bit) = '_';

	return key1;
}

string orderTerms( string key1, string key2 ) {

    string parsedNumber1 = "", parsedNumber2 = "", orderedTerms = "";

    int index1 = 0, index2 = 0, comma1 = 0, comma2 = 0;
    comma1 = key1.find( ',', index1 );
    comma2 = key2.find( ',', index2 );

    while ( comma1 != -1 || comma2 != -1 ) {
    		if ( comma1 != -1 )
    			parsedNumber1 = key1.substr( index1, comma1 - index1 );
    		else
    			parsedNumber1 = key1.substr( key1.rfind( ',' ) + 1 );
    		if ( comma2 != -1 )
    			parsedNumber2 = key2.substr( index2, comma2 - index2 );
    		else
    			parsedNumber2 = key2.substr( key2.rfind( ',' ) + 1 );

        if( stoi(parsedNumber1) < stoi(parsedNumber2) ) {
            orderedTerms += parsedNumber1 + ',';
            if ( comma1 == -1 ) {
            		orderedTerms += key2.substr( index2, key2.length() - index2 );
            		break;
            } else {
            		index1 = comma1 + 1;
            		comma1 = key1.find( ',', index1 );
            }
        } else {
            orderedTerms += parsedNumber2 + ',';
            if ( comma2 == -1 ) {
            		orderedTerms += key1.substr( index1, key1.length() - index1 );
            		break;
            } else {
				index2 = comma2 + 1;
				comma2 = key2.find( ',', index2 );
            }
        }
    }

    if ( -1 == comma1 && -1 == comma2 ) {
    		parsedNumber1 = key1.substr( key1.rfind( ',' ) + 1 );
    		parsedNumber2 = key2.substr( key2.rfind( ',' ) + 1 );
    		if ( stoi(parsedNumber1) < stoi(parsedNumber2) ) orderedTerms = orderedTerms + parsedNumber1 + "," + parsedNumber2;
    		else orderedTerms = orderedTerms + parsedNumber2 + "," + parsedNumber1;
    }

    return orderedTerms;
}

bool isDupe( string key, vector<Implicant> curLevel ) {
	for( int i = 0; i < curLevel.size(); i++ ) {
		if ( curLevel.at(i).key == key ) return true;
	}
	return false;
}
