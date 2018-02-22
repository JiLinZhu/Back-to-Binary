
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

	firstLevel = temp;
	firstLevel->level = initMintermLevel( minterms );

	while ( temp->level.size() > 0 ) {
		temp->createNextLevel();
		temp = temp->next;
	}
	temp = nullptr;
}

vector<Implicant> LogicExpression::initMintermLevel( vector<int> minterms ) {
	for( int i = 0; i < minterms.size(); i++ ) {
		int numOnes = 0;
		string bitRep = bitset<8>( minterms.at(i) ).to_string();
		string key = to_string( minterms.at(i) );
		for( int k = 0; k < 8; k++ ) if( bitRep.at(k) == '1' ) numOnes++;

		Implicant minterm;
		minterm.initImplicant( bitRep, key, numOnes );

		if( !isDupe( minterm.bitRep, this->minterms ) ) this->minterms.push_back(minterm);
	}
	return this->minterms;
}

void LogicExpression::findPrimeImplicants() {
	Level* temp = firstLevel;
	while( temp != nullptr ) {
		for( int i = 0; i < temp->level.size(); i++ ) {
			if ( temp->level.at(i).isPrimeImplicant ) primeImplicants.push_back( temp->level.at(i) );
		}
		temp = temp->next;
	}
}


void LogicExpression::findEssentialImplicants() {
	if ( primeImplicants.size() <= 0 ) findPrimeImplicants();

	//Code this
}
