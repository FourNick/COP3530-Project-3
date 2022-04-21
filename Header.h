#pragma once
#include "HashMap.h"

HashMap::HashMap() {
	table = new vector<NGO>[10];
}

void HashMap::insert(NGO toBeInserted) {
	int x = hash(toBeInserted.getIncome());
	table[x].push_back(toBeInserted);
	elements++;
	double loadFactor = (double)elements / tableSize;
	if (loadFactor > maxLoadFactor)
		rehash();
}

int HashMap::hash(long unsigned int income) {
	return income % tableSize;
}

void HashMap::rehash() {
	vector<NGO>* tempTable = new vector<NGO>[tableSize * 2];
	for (int i = 0; i < tableSize; i++) {
		for (NGO ngo : table[i]) {
			int x = hash(ngo.getIncome());
			tempTable[x].push_back(ngo);
		}
	}
	delete[] table;
	table = tempTable;
	tableSize = tableSize * 2;
}

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

vector<NGO> HashMap::getExact(long unsigned int income) {
	int x = hash(income);
	return table[x];
}