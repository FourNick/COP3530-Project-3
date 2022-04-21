#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <unordered_map>
#include <chrono>
#include "NGO.h"
#include "RedBlackTree.h"
#include "HashMap.h"

using namespace std;


void searchIncome(unsigned long int min, unsigned long int max, string state, string city, RedBlackTree& nonprofits);
void searchIncome(unsigned long int min, unsigned long int max, string state,  string city,HashMap& nonprofits);

void searchName(string name, HashMap& nonprofits);
void searchName(string name, RedBlackTree& nonprofits);

void display(NGO* nonprofit);


int main() {
	vector<NGO*> nonprofits;
	string inLine;
	
	std::fstream name ("eo3.csv", ios::in);
	if (name.is_open()) {
		getline(name, inLine);
		while (getline(name, inLine))
		{
			NGO* temp = new NGO(inLine);
			nonprofits.push_back(temp);
		}
		cout << endl;
		// cout << "done" << endl;
		name.close();
	}
	else
	{
		cout << "error" << endl;
	}

	RedBlackTree testMap;
	HashMap testUnMap;
	for (int i = 0; i < nonprofits.size(); i++)
	{
		testMap.insert(nonprofits[i]);
		testUnMap.insert(nonprofits[i]);
	}

	int option = 0;
	while (option != 7)
	{
		cout << "\nwhat would you like to do?" << endl 
			<< "1. search for nonprofits - red/black tree" << endl 
			<< "2. search for nonprofits - hash map" << endl 
			<< "3. search for nonprofits - head to head" << endl 
			<< "4. search by name - red/black tree" << endl 
			<< "5. search by name - hash map" << endl
			<< "6. search by name - head to head" << endl
			<< "7. quit" << endl;
		string optionString;
		cin >> optionString;
	
		if (optionString == "1")
		{
			option = 1;
			//cout << "which type of nonprofit would you like to search for?" << endl << "1. Religious\n2. Education\n3. Cultural or Historical\n4. Instructional or Informational\n5. Health Services\n6. Scientific Research\n7. Business or Professional\n8. Farming\n9. Mutual Organization\n10. Membership Organizaton\n11. Sports and Recreation\n12. Youth Activities\n13. Environmental and Conservation\n14. Housing\n15. Inner City and Community\n16. Civil Rights\n17. Litigation and Legal Aid\n18. Legislation and Political Activities\n19. Advocacy\n20. Other Individual Activities\n21. Activity Group\n22. Other";

			cout << "which state would you like to search in?" << endl << "AK, AL, AR, AZ, CA, CO, FL, GA, HI, ID, KS, LA, MO, MS, MT, NM, NV, OK, OR, TN, TX, UT, WA, WY" << endl;
			
			string state;
			cin >> state;

			cout << "which city would you like to search in?" << endl;
			string city;
			cin >> city;
			transform(city.begin(), city.end(), city.begin(), ::toupper);

			cout << "what minimum income would you like to search for?" << endl;
			string incomeMinString;
			cin >> incomeMinString;
			cout << "what maximum income would you like to search for?" << endl;
			string incomeMaxString;
			cin >> incomeMaxString;
			unsigned long int incomeMin = stoll(incomeMinString);
			unsigned long int incomeMax = stoll(incomeMaxString);

			searchIncome(incomeMin, incomeMax, state, city, testMap);

		}
		else if (optionString == "2")
		{
			option = 2;
			cout << "which state would you like to search in?" << endl << "AK, AL, AR, AZ, CA, CO, FL, GA, HI, ID, KS, LA, MO, MS, MT, NM, NV, OK, OR, TN, TX, UT, WA, WY" << endl;
			string state;
			cin >> state;

			cout << "which city would you like to search in?" << endl;
			string city;
			cin >> city;
			transform(city.begin(), city.end(), city.begin(), ::toupper);

			cout << "what minimum income would you like to search for?" << endl;
			string incomeMinString;
			cin >> incomeMinString;
			cout << "what maximum income would you like to search for?" << endl;
			string incomeMaxString;
			cin >> incomeMaxString;
			unsigned long int incomeMin = stoll(incomeMinString);
			unsigned long int incomeMax = stoll(incomeMaxString);

			searchIncome(incomeMin, incomeMax, state, city, testUnMap);

		}
		else if (optionString == "3")
		{
			option = 3;
			cout << "which state would you like to search in?" << endl << "AK, AL, AR, AZ, CA, CO, FL, GA, HI, ID, KS, LA, MO, MS, MT, NM, NV, OK, OR, TN, TX, UT, WA, WY" << endl;
			string state;
			cin >> state;

			cout << "which city would you like to search in?" << endl;
			string city; 
			cin >> city;
			transform(city.begin(), city.end(), city.begin(), ::toupper);

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
			cout << "what maximum income would you like to search for" << endl;
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


			chrono::system_clock::time_point start = chrono::system_clock::now(); // timer start
			searchIncome(incomeMin, incomeMax, state, city, testMap);
			chrono::system_clock::time_point end = chrono::system_clock::now(); // timer stop

			cout << "\n--------------------------------------------------------------------------------\n\n";

			auto elapsed1 = chrono::duration_cast<std::chrono::milliseconds>(end - start); // timer calculation

			start = chrono::system_clock::now();  // timer start
			searchIncome(incomeMin, incomeMax, state, city, testUnMap);
			end = chrono::system_clock::now(); // timer stop

			auto elapsed2 = chrono::duration_cast<std::chrono::milliseconds>(end - start); // timer calculation

			cout << "\n--------------------------------------------------------------------------------\n\nResults:\nRed-Black Tree: "  << elapsed1.count() << "ms\nHash Table: " << elapsed2.count()  << "ms\n";
		}
		else if (optionString == "4")
		{
			option = 4;
			cout << "please enter a name to search for: ";
			string name; 
			cin >> name;
			cout << endl;

			searchName(name, testMap);
		}
		else if (optionString == "5")
		{
			option = 5;
			cout << "please enter a name to search for: ";
			string name;
			cin >> name;
			cout << endl;

			searchName(name, testUnMap);
		}
		else if (optionString == "6")
		{
			option = 6;
			cout << "please enter a name to search for: ";
			string name;
			cin >> name;
			cout << endl;

			chrono::system_clock::time_point start = chrono::system_clock::now(); // timer start
			searchName(name, testMap);
			chrono::system_clock::time_point end = chrono::system_clock::now(); // timer stop
			cout << "\n--------------------------------------------------------------------------------\n\n";
			auto elapsed1 = chrono::duration_cast<std::chrono::milliseconds>(end - start); // timer calculation


			start = chrono::system_clock::now();  // timer start
			searchName(name, testUnMap);
			end = chrono::system_clock::now(); // timer stop
			auto elapsed2 = chrono::duration_cast<std::chrono::milliseconds>(end - start); // timer calculation

			cout << "\n--------------------------------------------------------------------------------\n\nResults:\nRed-Black Tree: " << elapsed1.count() << "ms\nHash Table: " << elapsed2.count() << "ms\n";

		}
		else if (optionString == "7")
		{
			option = 7;
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

void searchIncome(unsigned long int min, unsigned long int max, string state, string city, RedBlackTree& nonprofits)
{
	NGO* temp = new NGO("", "", max);
	nonprofits.insert(temp);
	Node* maxNode = nonprofits.searchNode(max);
	vector<NGO*> nonprofitVector = nonprofits.flatten(maxNode, min, max);
	bool displayed = false;
	for (int i = 0; i < nonprofitVector.size(); i++)
	{
		

		if (nonprofitVector[i]->getName() != "" && nonprofitVector[i]->getState() == state && nonprofitVector[i]->getIncome() > min && nonprofitVector[i]->getIncome() < max && city == nonprofitVector[i]->getCity()) {
			display(nonprofitVector[i]);
			displayed = true;

		}
	}
	if(displayed)
		cout << "\n========================================\n\n";
	else
		cout << "\n no matches found, please try again\n\n";
}

void searchIncome(unsigned long int min, unsigned long int max, string state, string city, HashMap& nonprofits)
{
	bool displayed = false;
	vector<NGO*> nodes = nonprofits.returnSorted(min, max);
	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i]->getName() != "" && nodes[i]->getState() == state && nodes[i]->getIncome() > min && nodes[i]->getIncome() < max && city == nodes[i]->getCity())
		{
			display(nodes[i]);
			displayed = true;
		}
	}

	if (displayed)
		cout << "\n========================================\n\n";
	else
		cout << "\n no matches found, please try again\n\n";
}

void searchName(string name, RedBlackTree& nonprofits)
{
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	auto output = nonprofits.search(name);
	if (output.size() == 0)
	{
		cout << "\n no matches found, please try again\n\n";
	}
	else
	{
		for (int i = 0; i < output.size(); i++)
		{
			display(output[i]);
		}
	}
}
void searchName(string name, HashMap& nonprofits)
{
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	auto output = nonprofits.searchName(name);
	if (output.size() == 0)
	{
		cout << "\n no matches found, please try again\n\n";
	}
	else
	{
		for (int i = 0; i < output.size(); i++)
		{
			display(output[i]);
		}
	}
}

void display(NGO* nonprofit)
{
	cout << "\n========================================\n\n" << 
		nonprofit->getName() << 
		"\nIncome: $" << nonprofit->getIncome() << 
		"\nAddress: " << nonprofit->getAddress() << endl;
}