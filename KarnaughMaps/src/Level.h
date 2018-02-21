
#ifndef LEVEL_H_
#define LEVEL_H_

#include <vector>
#include "Implicant.h"

class Level
{
	public:
		vector<Implicant> level;
		Level* next;

		void initLevel();
		void createNextLevel();
};

void initLevel( void );

void createNextLevel( void );

bool isDupe( string bitrep, vector<Implicant> curLevel );

#endif /* LEVEL_H_ */



//
//string orderTerms( string key1, string key2 ) {
//
//    string parsedNumber1 = "", parsedNumber2 = "", orderedTerms = "";
//
//    int index1 = 0, index2 = 0, comma1 = 0, comma2 = 0;
//    comma1 = key1.find( ',', index1 );
//    comma2 = key2.find( ',', index2 );
//
//    while ( comma1 != -1 || comma2 != -1 ) {
//    		if ( comma1 != -1 )
//    			parsedNumber1 = key1.substr( index1, comma1 - index1 );
//    		else
//    			parsedNumber1 = key1.substr( key1.rfind( ',' ) + 1 );
//    		if ( comma2 != -1 )
//    			parsedNumber2 = key2.substr( index2, comma2 - index2 );
//    		else
//    			parsedNumber2 = key2.substr( key2.rfind( ',' ) + 1 );
//
//        if( stoi(parsedNumber1) < stoi(parsedNumber2) ) {
//            orderedTerms += parsedNumber1 + ',';
//            if ( comma1 == -1 ) {
//            		orderedTerms += key2.substr( index2, key2.length() - index2 );
//            		break;
//            } else {
//            		index1 = comma1 + 1;
//            		comma1 = key1.find( ',', index1 );
//            }
//        } else {
//            orderedTerms += parsedNumber2 + ',';
//            if ( comma2 == -1 ) {
//            		orderedTerms += key1.substr( index1, key1.length() - index1 );
//            		break;
//            } else {
//				index2 = comma2 + 1;
//				comma2 = key2.find( ',', index2 );
//            }
//        }
//    }
//
//    if ( -1 == comma1 && -1 == comma2 ) {
//    		parsedNumber1 = key1.substr( key1.rfind( ',' ) + 1 );
//    		parsedNumber2 = key2.substr( key2.rfind( ',' ) + 1 );
//    		if ( stoi(parsedNumber1) < stoi(parsedNumber2) ) orderedTerms = orderedTerms + parsedNumber1 + "," + parsedNumber2;
//    		else orderedTerms = orderedTerms + parsedNumber2 + "," + parsedNumber1;
//    }
//    return orderedTerms;
//}
