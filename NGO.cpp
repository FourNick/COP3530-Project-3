#include "NGO.h"


NGO::NGO(string inLine) {
	vector<string> row;
	stringstream rowString(inLine);
	string word;
	while (getline(rowString, word, ','))
	{
		row.push_back(word);
	}
	EIN = stoi(row[0]);
	name = row[1];
	zip = row[6];
	incomeCode = stoi(row[15]);
	if (incomeCode != 0 && row[25] != "") {
		income = stoll(row[25], nullptr, 10);
	}
	else
		income = 0;

}

NGO::NGO(string name_, string zip_, long int income_) {
	name = name_;
	zip = zip_;
	income = income_;
}

void NGO::printName() {
	cout << name << ", ";
}

string NGO::getZip() {
	return zip;
}

long int NGO::getIncome() {
	return income;
}

string NGO::getName() {
	return name;
}