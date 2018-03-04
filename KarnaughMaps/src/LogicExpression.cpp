/*
 * LogicExpression.cpp
 */

#include "LogicExpression.h"


LogicExpression* initLogicExpression(){
	LogicExpression* logic = new LogicExpression;
	vector<Implicant> minterms;
	vector<Implicant> dontCares;
	vector<Implicant> primeImplicants;
	vector<Implicant> essentialImplicants;

	logic->firstLevel = nullptr;
	logic->minterms = minterms;
	logic->dontCares = dontCares;
	logic->primeImplicants = primeImplicants;
	logic->essentialImplicants = essentialImplicants;

	return logic;
}

void LogicExpression::createQMc( vector<int> minterms, vector<int> dontCares ) {
	Level* temp = initLevel();
	findNumVariables( minterms, dontCares );
	initMinterm( minterms );
	initDontCares( dontCares );

	vector<Implicant> tempVector = this->minterms;
	tempVector.insert( tempVector.end(), this->dontCares.begin(), this->dontCares.end() );

	firstLevel = temp;
	firstLevel->level = tempVector;

	while ( temp->level.size() > 0 ) {
		temp->createNextLevel();
		temp = temp->next;
	}
	temp = nullptr;
}

void LogicExpression::findNumVariables( vector<int> minterms, vector<int> dontCares ) {
	int maxElement = 0;
	if( dontCares.size() > 0 )
		maxElement = max( *max_element( minterms.begin(), minterms.end() ), *max_element( dontCares.begin(), dontCares.end() ) );
	else
		maxElement = *max_element( minterms.begin(), minterms.end() );
	numVariables = log2( maxElement ) + 1;
}

void LogicExpression::initMinterm( vector<int> minterms ) {
	for( int i = 0; i < minterms.size(); i++ ) {
		int numOnes = 0;
		string bitRep = bitset<16>( minterms.at(i) ).to_string().substr( 16-numVariables );
		string key = to_string( minterms.at(i) );
		for( int k = 0; k < numVariables; k++ ) if( bitRep.at(k) == '1' ) numOnes++;

		Implicant minterm;
		minterm.initImplicant( numVariables, numOnes, bitRep, key );

		if( !isDupe( minterm.bitRep, this->minterms ) ) this->minterms.push_back(minterm);
	}
}

void LogicExpression::initDontCares( vector<int> dontCares ) {
	for( int i = 0; i < dontCares.size(); i++ ) {
		int numOnes = 0;
		string bitRep = bitset<16>( dontCares.at(i) ).to_string().substr( 16-numVariables );
		string key = to_string( dontCares.at(i) );
		for( int k = 0; k < numVariables; k++ ) if( bitRep.at(k) == '1' ) numOnes++;

		Implicant dontCares;
		dontCares.initImplicant( numVariables, numOnes, bitRep, key );

		if( !isDupe( dontCares.bitRep, this->dontCares ) && !isDupe( dontCares.bitRep, this->minterms ) ) this->dontCares.push_back(dontCares);
	}
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

void LogicExpression::printImplicants() {
	Level *b = firstLevel;
	while( b != nullptr ) {
		for ( int i = 0; i < b->level.size(); i++ ) {
			cout << b->level.at(i).key << endl;
			//cout << b->level.at(i).bitRep << endl;
		}
		cout << endl;
		b = b->next;
	}
}

void LogicExpression::printMinterms() {
	cout << "Minterms" << endl;
	for ( int i = 0; i < minterms.size(); i++ ) {
		cout << minterms.at(i).key << endl;
		//cout << primeImplicants.at(i).bitRep << endl;
	}
	cout << endl;
}

void LogicExpression::printPrimeImplicants() {
	cout << "Prime Implicants" << endl;
	for ( int i = 0; i < primeImplicants.size(); i++ ) {
		cout << primeImplicants.at(i).key << endl;
		//cout << primeImplicants.at(i).bitRep << endl;
	}
	cout << endl;
}

void LogicExpression::printEssentialImplicants() {
	cout << "Essential Implicants" << endl;
		for ( int i = 0; i < essentialImplicants.size(); i++ ) {
			cout << essentialImplicants.at(i).key << endl;
			//cout << essentialImplicants.at(i).bitRep << endl;
		}
	cout << endl;
}

void LogicExpression::produceMintermSOP() {

}

void LogicExpression::produceMaxtermPOS() {

}

void LogicExpression::produceMinimumSOP() {
	vector<bool> mintermsNeeded;
	string curExpression = buildInitialExpression();

	initMintermsNeeded( *mintermsNeeded );

	for( int i = 0; i < essentialImplicants.size(); i++ ) {
		findCoveredMinterms( essentialImplicants.at(i).key, *mintermsNeeded );
	}

	recursiveFindPossibleExpression( curExpression, mintermsNeeded );
}

void LogicExpression::produceMinimumPOS() {

}


