
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
vector<Implicant> initializeMinterms(  vector<int> minterms  ) {
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


Node* initializeQMc( vector<int> minterms ) {
	Node *quineMc = new Node;
	quineMc->level = initializeMinterms(  minterms  );
	quineMc->next = nullptr;

	return quineMc;
}


int main( void ) {
	vector<int> minterms;
	minterms.push_back(2);
	minterms.push_back(4);
	minterms.push_back(9);
	Node *a = initializeQMc( minterms );

	cout << a->level.at(0).bitRep << endl;
}




















