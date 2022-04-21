#include <iostream>
#include <vector>
#include <algorithm>
#include "NGO.h"
using namespace std;

class HashMap {

private:
	// Initialize tableSize to 10 of the hash map.
	unsigned int tableSize = 10;
	// maxLoadFactor of the table that if met, rehashing should take place.
	float maxLoadFactor = 0.75;
	float elements = 0;
	// Table declaration. 
	vector<NGO>* table;

public:
	// Where all the functions used are being declared.
	HashMap();
	void insert(NGO toBeInserted);
	int hash(long unsigned int income);
	void rehash();
	vector<NGO> returnSorted();
	vector<NGO> getExact(long unsigned int income);
};
