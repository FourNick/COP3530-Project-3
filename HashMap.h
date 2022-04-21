#include <iostream>
#include <vector>
#include <algorithm>
#include "NGO.h"
using namespace std;

class HashMap {

private:
	unsigned int tableSize = 100;
	float maxLoadFactor = 0.75;
	float elements = 0;
	vector<NGO*>* table;

public:
	HashMap();
	void insert(NGO* toBeInserted);
	int hash(long unsigned int income);
	void rehash();
	vector<NGO*> returnSorted(unsigned long int min, unsigned long int max);
	vector<NGO*> getExact(long unsigned int income);
	vector<NGO*> searchName(string name);
};