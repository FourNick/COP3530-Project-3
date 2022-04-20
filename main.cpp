#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <unordered_map>
#include "chrono"
#include "NGO.h"
#include "RedBlackTree.h"

using namespace std;


void searchIncome(unsigned long int min, unsigned long int max, string state, RedBlackTree& nonprofits);
void searchIncome(unsigned long int min, unsigned long int max, string state, unordered_map<unsigned long int, vector<NGO*>>& nonprofits);

void display(NGO* nonprofit);


int main() {
	vector<NGO*> nonprofits;
	string inLine;
	
	std::fstream name ("eoT.csv", ios::in);
	if (name.is_open()) {
		getline(name, inLine);
		while (getline(name, inLine))
		{
			NGO* temp = new NGO(inLine);
			nonprofits.push_back(temp);
		}
		cout << endl;
		cout << "done" << endl;
		name.close();
	}
	else
	{
		cout << "error" << endl;
	}

	RedBlackTree testMap;
	unordered_map<unsigned long int, vector<NGO*>> testUnMap;
	for (int i = 0; i < nonprofits.size(); i++)
	{
		testMap.insert(nonprofits[i]);
		testUnMap[nonprofits[i]->getIncome()].push_back(nonprofits[i]);
	}

	int option = 0;
	while (option != 5)
	{
		cout << "\nwhat would you like to do?" << endl << "1. search for nonprofits - ordered map" << endl << "2. search for nonprofits - unordered map" << endl << "3. search for nonprofits - head to head" << endl << "4. extra option" << endl << "5. quit" << endl;
		string optionString;
		cin >> optionString;
	
		if (optionString == "1")
		{
			option = 1;
			//cout << "which type of nonprofit would you like to search for?" << endl << "1. Religious\n2. Education\n3. Cultural or Historical\n4. Instructional or Informational\n5. Health Services\n6. Scientific Research\n7. Business or Professional\n8. Farming\n9. Mutual Organization\n10. Membership Organizaton\n11. Sports and Recreation\n12. Youth Activities\n13. Environmental and Conservation\n14. Housing\n15. Inner City and Community\n16. Civil Rights\n17. Litigation and Legal Aid\n18. Legislation and Political Activities\n19. Advocacy\n20. Other Individual Activities\n21. Activity Group\n22. Other";

			cout << "which state would you like to search in?" << endl << "AK, AL, AR, AZ, CA, CO, FL, GA, HI, ID, KS, LA, MO, MS, MT, NM, NV, OK, OR, TN, TX, UT, WA, WY" << endl;
			
			string state;
			cin >> state;

			cout << "what minimum income would you like to search for?" << endl;
			string incomeMinString;
			cin >> incomeMinString;
			cout << "what maximum income would you like to search for?" << endl;
			string incomeMaxString;
			cin >> incomeMaxString;
			unsigned long int incomeMin = stoll(incomeMinString);
			unsigned long int incomeMax = stoll(incomeMaxString);

			searchIncome(incomeMin, incomeMax, state, testMap);

		}
		else if (optionString == "2")
		{
			option = 2;
			cout << "which state would you like to search in?" << endl << "AK, AL, AR, AZ, CA, CO, FL, GA, HI, ID, KS, LA, MO, MS, MT, NM, NV, OK, OR, TN, TX, UT, WA, WY" << endl;
			string state;
			cin >> state;

			cout << "what minimum income would you like to search for?" << endl;
			string incomeMinString;
			cin >> incomeMinString;
			cout << "what maximum income would you like to search for?" << endl;
			string incomeMaxString;
			cin >> incomeMaxString;
			unsigned long int incomeMin = stoll(incomeMinString);
			unsigned long int incomeMax = stoll(incomeMaxString);

			searchIncome(incomeMin, incomeMax, state, testUnMap);

		}
		else if (optionString == "3")
		{
			option = 3;
			cout << "which state would you like to search in?" << endl << "AK, AL, AR, AZ, CA, CO, FL, GA, HI, ID, KS, LA, MO, MS, MT, NM, NV, OK, OR, TN, TX, UT, WA, WY" << endl;
			string state;
			cin >> state;

			cout << "what minimum income would you like to search for?" << endl;
			string incomeMinString;
			cin >> incomeMinString;

			unsigned long int incomeMin;
			try {
				incomeMin = stoll(incomeMinString);
			}
			catch (exception)
			{
				cout << "please enter a valid input option" << endl;
				continue;
			}
			cout << "what maximum income would you like to search for, up to $4 billion?" << endl;
			string incomeMaxString;
			cin >> incomeMaxString;
			unsigned long int incomeMax;
			try {
				incomeMax = stoll(incomeMaxString);
			}
			catch (exception)
			{
				cout << "please enter a valid input option" << endl;
				continue;
			}


			chrono::system_clock::time_point start = chrono::system_clock::now();

			searchIncome(incomeMin, incomeMax, state, testMap);
			chrono::system_clock::time_point end = chrono::system_clock::now();
			chrono::high_resolution_clock;
			cout << "\n--------------------------------------------------------------------------------\n\n";
			auto elapsed1 = chrono::duration_cast<std::chrono::milliseconds>(end - start);

			start = chrono::system_clock::now(); 
			searchIncome(incomeMin, incomeMax, state, testUnMap);
			end = chrono::system_clock::now();

			auto elapsed2 = chrono::duration_cast<std::chrono::milliseconds>(end - start);




			cout << "\n--------------------------------------------------------------------------------\n\nResults:\nRed-Black Tree: "  << elapsed1.count() << "ms\nHash Table: " << elapsed2.count()  << "ms\n";
		}
		else if (optionString == "4")
		{
			option = 4;
		}
		else if (optionString == "5")
		{
			option = 5;
			break;
		}
		else
		{
			cout << "please enter a valid input option (1, 2, 3, 4, or 5)" << endl;
			continue;
		}




	}


	return 0;
}

void searchIncome(unsigned long int min, unsigned long int max, string state, RedBlackTree& nonprofits)
{
	NGO* temp = new NGO("", "", max);
	nonprofits.insert(temp);
	Node* maxNode = nonprofits.searchNode(max);
	vector<NGO*> nonprofitVector = nonprofits.flatten(maxNode, min, max);
	for (int i = 0; i < nonprofitVector.size(); i++)
	{
		

		if (nonprofitVector[i]->getState() == state && nonprofitVector[i]->getIncome() > min && nonprofitVector[i]->getIncome() < max) {
			display(nonprofitVector[i]);
		}
	}
	cout << "\n========================================\n\n";

}

void searchIncome(unsigned long int min, unsigned long int max, string state, unordered_map<unsigned long int, vector<NGO*>>& nonprofits)
{
	auto iter = nonprofits.begin();
	while (iter != nonprofits.end())
	{
		for (int i = 0; i < iter->second.size(); i++)
		{
			if (iter->second[i]->getName() != "" && iter->second[i]->getState() == state && iter->second[i]->getIncome() > min && iter->second[i]->getIncome() < max)
				display(iter->second[i]);
		}
		iter++;

	}
	cout << "\n========================================\n\n";
}


void display(NGO* nonprofit)
{
	cout << "\n========================================\n\n" << 
		nonprofit->getName() << 
		"\nIncome: $" << nonprofit->getIncome() << 
		"\nAddress: " << nonprofit->getAddress() << endl;
}