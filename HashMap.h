#include <iostream>
#include <vector>
#include <algorithm>
#include "NGO.h"
using namespace std;

class HashMap {

private:
	unsigned int tableSize = 10;
	float maxLoadFactor = 0.75;
	float elements = 0;
	vector<NGO>* table;

public:
	HashMap();
	void insert(NGO toBeInserted);
	int hash(long unsigned int income);
	void rehash();
	vector<NGO> returnSorted();
	vector<NGO> getExact(long unsigned int income);
};
