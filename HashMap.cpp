#pragma once
#include "HashMap.h"

HashMap::HashMap() {
	table = new vector<NGO*>[100];
}

void HashMap::insert(NGO* toBeInserted) {
	int x = hash(toBeInserted->getIncome());
	table[x].push_back(toBeInserted);
	elements++;
	double loadFactor = (double)elements / tableSize;
	if (loadFactor >= maxLoadFactor)
		rehash();
}

int HashMap::hash(long unsigned int income) {
	return income % tableSize;
}

void HashMap::rehash() {
	vector<NGO*>* tempTable = new vector<NGO*>[tableSize * 2];
	for (int i = 0; i < tableSize; i++) {
		for (NGO* ngo : table[i]) {
			int x = hash(ngo->getIncome());
			tempTable[x].push_back(ngo);
		}
	}
	delete[] table;
	table = tempTable;
	tableSize = tableSize * 2;
}

vector<NGO*> HashMap::returnSorted(unsigned long int min, unsigned long int max) {
	vector<NGO*> v;
	for (int i = 0; i < tableSize; i++) {
		for (int j = 0; j < table[i].size(); j++) {
			if (table[i][j]->getIncome() >= min && table[i][j]->getIncome() <= max)
			{
				v.push_back(table[i][j]);

			}
		}
	}
	
	/*vector<NGO*> v2;
	for (int x : v) {
		auto z = getExact(x);
		for (int i = 0; i < z.size(); i++) {
			if (x >= min && x <= max)
				v2.push_back(z[i]);
		}
	}*/
	return v;
}

vector<NGO*> HashMap::getExact(long unsigned int income) {
	int x = hash(income);
	return table[x];
}

vector<NGO*> HashMap::searchName(string name) {
	vector<NGO*> v;
	for (int i = 0; i < tableSize; i++) {
		for (int j = 0; j < table[i].size(); j++) {
			if (table[i][j]->getName().find(name) != std::string::npos)
				v.push_back(table[i][j]);
		}
	}
	return v;

}