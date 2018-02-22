
#include <math.h>
#include "LogicExpression.h"

void LogicExpression::initLogicExpression(){
	vector<Implicant> minterms;
	vector<Implicant> primeImplicants;
	vector<Implicant> essentialImplicants;

	this->firstLevel = nullptr;
	this->minterms = minterms;
	this->primeImplicants = primeImplicants;
	this->essentialImplicants = essentialImplicants;
}

void LogicExpression::createQMc( vector<int> minterms ) {
	Level* temp = new Level;
	temp->initLevel();

	findNumVariables( minterms );
	firstLevel = temp;
	firstLevel->level = initMintermLevel( minterms );

	while ( temp->level.size() > 0 ) {
		temp->createNextLevel();
		temp = temp->next;
	}
	temp = nullptr;
}

void LogicExpression::findNumVariables( vector<int> minterms ) {
	int maxElement = *max_element( minterms.begin(), minterms.end() );
	numVariables = log2( maxElement ) + 1;
}

vector<Implicant> LogicExpression::initMintermLevel( vector<int> minterms ) {
	for( int i = 0; i < minterms.size(); i++ ) {
		int numOnes = 0;
		string bitRep = bitset<16>( minterms.at(i) ).to_string().substr( 16-numVariables );
		string key = to_string( minterms.at(i) );
		for( int k = 0; k < numVariables; k++ ) if( bitRep.at(k) == '1' ) numOnes++;

		Implicant minterm;
		minterm.initImplicant( numVariables, numOnes, bitRep, key );

		if( !isDupe( minterm.bitRep, this->minterms ) ) this->minterms.push_back(minterm);
	}
	return this->minterms;
}

void LogicExpression::findPrimeImplicants() {
	Level* temp = firstLevel;
	while( temp != nullptr ) {
		for( int i = 0; i < temp->level.size(); i++ ) {
			if ( temp->level.at(i).isPrimeImplicant )
				primeImplicants.push_back( temp->level.at(i) );
		}
		temp = temp->next;
	}
}

void LogicExpression::findEssentialImplicants() {
	bool alreadyContain = false, remove = false;
	Implicant candidate;

	if( primeImplicants.size() <= 0 ) findPrimeImplicants();

	for( int i = 0; i < minterms.size(); i++ ) {
		for( int j = 0; j < primeImplicants.size(); j++ ) {
			if( primeImplicants.at(j).containsMinterm( minterms.at(i).key ) ) {
				if ( false == alreadyContain ) {
					alreadyContain = true;
					candidate = primeImplicants.at(j);
				} else {
					remove = true;
				}
			}
		}
		if ( false == remove && true == alreadyContain && !isDupe( candidate.bitRep, essentialImplicants ) )
			essentialImplicants.push_back( candidate );
		remove = false;
		alreadyContain = false;
	}

}

