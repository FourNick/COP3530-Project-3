#include "iostream"
#include "fstream"
#include "string"
#include "NGO.h"
#include "vector"

using namespace std;

int main() {
	vector<NGO*> nonprofits;
	string inLine;
	std::fstream name ("eo1.csv", ios::in);
	if (name.is_open()) {
		getline(name, inLine);
		while (getline(name, inLine))
		{
			NGO* temp = new NGO(inLine);
			nonprofits.push_back(temp);
		}
		for (int i = 0; i < 100; i++)
		{
			nonprofits[i]->printName();
		}
		cout << endl;
		cout << "done" << endl;
		name.close();
	}
	else
	{
		cout << "error" << endl;
	}



	return 0;
}