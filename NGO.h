#include "string"
#include "vector"
#include "sstream"
#include "iostream"

#pragma once

using namespace std;
class NGO
{
	int EIN;
	string name;
	int incomeCode;
	unsigned long int income;
	string zip;
	string address;	
	string state;
	string city;
	vector<string> types;
	//string setType(string code);
	//map<string, string> typeMap;
public: 
	NGO(); // NGO base case
	NGO(string inLine); // constructor for import from csv
	NGO(string name_, string zip_, long int income_); // constructor for user added NGO 
	void printName(); // prints the name of the nonprofit formatted with a comma and space afterwards 
	string getZip(); // returns zip code as a string
	unsigned long int getIncome(); // returns income as a long int
	string getName(); // returns name as a string (in all caps)
	string getAddress();
	string getState();
	vector<string> getType();
	string getCity();
};

