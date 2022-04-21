#include "HashMap.h"

// initializes the hash map with a size of 10.
HashMap::HashMap() {
	table = new vector<NGO>[10];
}

// function to insert objects from the NGO file into the hashmap
void HashMap::insert(NGO toBeInserted) {
	// call the hash function to get the index where the key is the income.
	int x = hash(toBeInserted.getIncome());
	table[x].push_back(toBeInserted);
	// increase the element size in order to account for the loadFactor.
	elements++;
	double loadFactor = (double)elements / tableSize;
	// call rehash functions if the max load factor is met by the current load factor.
	if (loadFactor >= maxLoadFactor)
		rehash();
}

// hash function to create the index for the item in the map by using the actual amount of the key divided by the table size
// and then getting that remainder.
int HashMap::hash(long unsigned int income) {
	return income % tableSize;
}

// rehash function in case the max load factor is met so the hash table
// is double in size and the keys get their their new index by rehashing. 
void HashMap::rehash() {
	vector<NGO>* tempTable = new vector<NGO>[tableSize * 2];
	for (int i = 0; i < tableSize; i++) {
		for (NGO ngo : table[i]) {
			int x = hash(ngo.getIncome());
			tempTable[x].push_back(ngo);
		}
	}
	// delete the old table's information
	delete[] table;
	table = tempTable;
	tableSize = tableSize * 2;
}

// function to return the items sorted by key. 
vector<NGO> HashMap::returnSorted() {
	vector<int> v;
	for (int i = 0; i < tableSize; i++) {
		for (NGO ngo : table[i]) {
			v.push_back(ngo.getIncome());
		}
	}
	sort(v.begin(), v.end());
	vector<NGO> v2;
	for (int x : v) {
		for (NGO ngo : getExact(x)) {
			if (ngo.getIncome() == x)
			v2.push_back(ngo);
		}
	}
	return v2;
}
// getExact functions takes in the income(key) and returns all of the values in that key.
vector<NGO> HashMap::getExact(long unsigned int income) {
	int x = hash(income);
	return table[x];
}
