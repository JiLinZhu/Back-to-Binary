using namespace std;
#include <bitset>
#include <iostream>
#include <vector>


class Implicant {
	public:
		bool isPrimeImplicant;

		string bitRep;
		string key;

		int numOnes;

};

struct Node {
	vector<Implicant> level;
	Node* next;
};


//Consider finding the largest minterm and making a sufficient number of bits to represent this
vector<Implicant> initMinterms(  vector<int> minterms  ) {
	vector<Implicant> firstLevel;

  	//Adding first level
	for( int i = 0; i < minterms.size(); i++ ) {
		Implicant minterm;
		int numOnes = 0;

		minterm.isPrimeImplicant = true;
		minterm.bitRep = bitset<8>( minterms.at(i) ).to_string();
		minterm.key = minterms.at(i);

		//Counting how many ones are in the bit representation
<<<<<<< HEAD
		for( int k = 0; k < 8; k++ )
			if( minterm.bitRep.at(k) == 1 )
				numOnes++;

=======
		for(int k = 0; k < 8; k++){
			if( minterm.bitRep.at(k) == 1 ) 
				numOnes++;
		}
>>>>>>> 8a697a18ad46d916d07e513f2cd70f8867863da1
		minterm.numOnes = numOnes;

		firstLevel.push_back(minterm);
	}
	return firstLevel;
}



Node* initNode() {
	vector<Implicant> terms;
	Node *nextNode = new Node;
 	nextNode->level = terms;
 	nextNode->next = nullptr;
 	return nextNode;
}


Node* createQMc( vector<int> minterms ) {
	Node *quineMc = initNode();
	quineMc->level = initMinterms( minterms );

	return quineMc;
}


bool canCombine( Implicant num1, Implicant num2 ) {
	int numDifferences = 0;

<<<<<<< HEAD
	if( abs(num1.numOnes - num2.numOnes) != 1 ) {
    		return false;
    } else {
    	//Change 8 to be number bits dynamic in the future
		for( int i = 0; i < 8 ; i++ ) {
			if( num1.bitRep.at(i) != num2.bitRep.at(i) )
				numDifferences++;
		}
    }
=======
	if( abs(num1.numOnes - num2.numOnes) != 1 ){
    	return false;
    } 
	
	else {
    	//Change 8 to be number bits dynamic in the future
    	for(int i = 0; i < 8 ; i++){
			if( num1.bitRep.at(i) != num2.bitRep.at(i) )
				numDifferences++;
		}
	}
>>>>>>> 8a697a18ad46d916d07e513f2cd70f8867863da1

    return numDifferences == 1;
}


<<<<<<< HEAD
string combineBitRep(Implicant num1, Implicant num2) {
	int bit;
	for( int i = 0 ; i < 8; i++ ) {
		if( num1.bitRep.at(i) != num2.bitRep.at(i) )
			bit = i;
	}

	string newBitRep = num1.bitRep;
	newBitRep.at(bit) = '_';

	return newBitRep;
}


void createNextLevel( Node* prevLevel ) {
	int numTerms = prevLevel->level.size();

	Node* nextLevel = initNode();
	prevLevel->next = nextLevel;

	for( int i = 0; i < numTerms-1; i++ ) {
  		for( int j = i+1; j < numTerms; j++ ) {
			if( canCombine( prevLevel->level.at(i) , prevLevel->level.at(j) ) ) {
				Implicant term;
				term.isPrimeImplicant = true;
				term.bitRep = combineBitRep( prevLevel->level.at(i) , prevLevel->level.at(j) );

				//Gotta Code an Order Function so that say 24 + 35 -> 2 3 4 5
				term.key = prevLevel->level.at(i).key + prevLevel->level.at(j).key);
				term.numOnes = min( prevLevel->level.at(i).numOnes, prevLevel->level.at(j).numOnes );
				nextLevel->level.push_back(term);
			}
    		}
  	}
}
=======
string combineBitRep(Implicant num1, Implicant num2){
	int bit;
	for(int i = 0 ; i < 8; i ++){
		if(num1.bitRep.at(i) != num2.bitRep.at(i))
			bit = i;
	}
	
	string newBitRep = num1.bitRep;
	newBitRep.at(bit) = '_';
	
	return newBitRep;
	
	
}

// void createNextLevel( Node* prevLevel ) {
	// int numTerms = prevNode->level.size();

  // Node* nextLevel = initNode();
  // prevLevel->next = nextLevel;

	// for ( int i = 0; i < numTerms-1; i++ ) {
  		// for ( int j = i+1; j < numTerms; j++ ) {
    		// if( canCombine( quineMc->level.at(i) , quineMc->level.at(j) ) ){
				// nextLevel->level.isPrimeImplicant = true;
				// nextLevel->level.bitRep
			// }
    	// }	
  	// }

// }
>>>>>>> 8a697a18ad46d916d07e513f2cd70f8867863da1



int main( void ) {
<<<<<<< HEAD
 	vector<int> minterms;
 	minterms.push_back(2);
	minterms.push_back(3);
 	minterms.push_back(4);
 	minterms.push_back(9);
	Node *a = createQMc( minterms );


	string s = combineBitRep(a->level.at(0), a->level.at(1));

 	cout << a->level.at(0).bitRep << endl;
=======
	vector<int> minterms;
	minterms.push_back(2);
	minterms.push_back(3);
	minterms.push_back(4);
	minterms.push_back(9);
	Node *a = createQMc( minterms );
	
	
	string s = combineBitRep(a->level.at(0), a->level.at(1));

	cout << a->level.at(0).bitRep << endl;
>>>>>>> 8a697a18ad46d916d07e513f2cd70f8867863da1
	cout << a->level.at(1).bitRep << endl;
	cout << s << endl;
}




////////











