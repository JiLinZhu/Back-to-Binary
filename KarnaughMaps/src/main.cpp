
using namespace std;
#include <bitset>
#include <iostream>
#include <vector>


class Implicant{
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
	for ( int i = 0; i < minterms.size(); i++ ) {
		Implicant minterm;
		int numOnes = 0;

		minterm.isPrimeImplicant = true;
		minterm.bitRep = bitset<8>( minterms.at(i) ).to_string();

		//Counting how many ones are in the bit representation
		for(int k = 0; k < 8; k++) if( minterm.bitRep.at(k) == 1 ) numOnes++;

		minterm.numOnes = numOnes;

		firstLevel.push_back(minterm);
	}
  return firstLevel;
}


Node* createQMc( vector<int> minterms ) {
	Node *quineMc = initNode();
	quineMc->level = initMinterms(  minterms  );
	
	return quineMc;
}


Node* initNode() {
	vector<Implicant> terms;
	Node *nextNode = new Node;
  nextNode->level = terms;
  nextNode->next = nullptr;
}


bool canCombine( Implicant* num1, Implicant* num2 ) {
		int numDifferences = 0;
    
		if( abs(num1->numOnes - num2->numOnes) != 1 ){
    	return false;
    } else {
    	//Change 8 to be number bits dynamic in the future
    	for(int i = 0; i < 8 ; i++){
      	if( num1->bitRep.at(i) != num2->bitRep.at(i) )
        	numDifferences++;
      }
    
    	if( numDifferences == 1 )
      	return true;
        
      else
      	return false;
    }
}

void createNextLevel( Node* prevNode ) {
	int numTerms = prevNode->level.size();

  Node* nextLevel = initNode();
  prevNode->next = nextLevel;
  
	for ( int i = 0; i < numTerms-1; i++ ) {
  	for ( int j = i+1; j < numTerms; j++ ) {
    	if( canCombine( quineMc->level.at(i) , quineMc->level.at(j) ){
      	
      }
    }
  }
	
}
	


int main( void ) {
	vector<int> minterms;
	minterms.push_back(2);
	minterms.push_back(4);
	minterms.push_back(9);
	Node *a = createQMc( minterms );

	cout << a->level.at(0).bitRep << endl;
	cout << a->level.at(2).bitRep << endl;
}




















