#include <iostream>
#include "ManagerControls.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ConcessionItem.h"
#include "StarLightEvent.h"
#include "inventoryManager.h"

using namespace std;

// Display manager control options
void managerGreeting() {


	cout << "\nStarlight Entertainment manager controls.\n";
	cout << "Enter 1 to manage inventory\n";
	cout << "Enter 9 to go back to the main menu\n";

	//validate input
	int input;
	if (cin >> input) {

		if (input == 1) {

			manageInventory();
		}
		if (input == 9) {

			return;
		}
		else {

			cin.clear();
			return;
		}
	}
	else {

		cin.clear();
		cin.ignore();
		cin.ignore();
		managerGreeting();
	}
}

//In the future will be able to add/remove events and items from the master inventory
void manageInventory() {

	cout << "\nInventory Manager\n";
	cout << "If you would like to add inventory from a file please enter  1\n";
	cout << "Enter 9 to go back to the manager menu\n";

	int input;

	//validate input
	if (cin >> input) {

		if (input == 1) {

			fileInput();
		}
		if (input == 9) {

			return;
		}
		else {

			return;
		}
	}
	else {

		cin.clear();
		cin.ignore();
		cin.ignore();
		managerGreeting();
	}	
}

//file input method that checks for comments and reads only the appropriate data
//for some reason, and I for the life of me cannot figure out why, but this function will only read in
// every other line starting with the second line. Thus, the 'dummy lines' in the input file
void fileInput() {

	//operating variables
	fstream file("input.txt");
	string line;

	//item variables
	string type;
	string name;

	if (file.is_open()) {

		while (getline(file, line)) {
			//cout << line;
			//check for comments
			if (line[0] != '#') {
				
				getline(file, line);
				
				if (line[0] == 'e') {
					
					parseEvent(line);
				}

				if (line[0] == 'c') {

					parseConcessionItem(line);
				}				
			}			
		}

		file.close();
		cout << "File input successful!\n";
		return;
	}

	else {

		cout << "Error opening file";
		return;
	}
}

void parseEvent(string line){

	string prop[10];
	int i = 0;
	stringstream in(line);

	while (getline(in, prop[i], ',')) {

		++i;
	}

	string type = prop[0];
	string name = prop[1];
	string desc = prop[2];
	string _price = prop[3];
	string beginTime = prop[4];
	string _eventLength = prop[5];
	string _seatsOpen = prop[6]; 

	//stoi(string to integer)is a part of the standard library and is pretty awesome
	int eventLength = stoi(_eventLength);
	int seatsOpen = stoi(_seatsOpen);

	//stod(string to double) is a part of the standard library and is pretty awesome
	double price = stod(_price);

	//create item class objects and add them to their container
	starLightEvent item(name, desc, price, beginTime, eventLength, seatsOpen);
	eventContainer.push_back(item);

	return;

}

// this method takes in the string line from the input file that has already been determined to be a concessionItem.
// it then parses out each property, sets it to a different type if need be and then creates the item
void parseConcessionItem(string line) {	
	
	//an item should never be more than 8 properties long. Made the array of length 10 to be certain
	string prop[10];
	int i = 0;
	stringstream in(line);

	while (getline(in, prop[i], ',')) {

		++i;
	}

	string type = prop[0];
	string name = prop[1];
	string desc = prop[2];
	string size = prop[3];
	string FordOrDrink = prop[4];
	string _inventory = prop[5];

	//stoi(string to integer)is a part of the standard library and is pretty awesome
	int inventory = stoi(_inventory);

	//create sizeTypes from string
	concessionItem::sizeType _size;
	if (size == "small") {

		_size = concessionItem::SMALL;
	}

	if (size == "medium") {

		_size = concessionItem::MEDIUM;
	}

	if (size == "large") {

		_size = concessionItem::LARGE;
	}

	//create concessionItem types from string
	//create sizeTypes from string
	concessionItem::itemType _itemType;
	if (size == "food") {

		_itemType = concessionItem::FOOD;
	}

	if (size == "drink") {

		_itemType = concessionItem::DRINK;
	}

	if (size == "candy") {

		_itemType = concessionItem::CANDY;
	}

	//create item class objects and add them to their container
	concessionItem item(name, desc, _size, _itemType, inventory);
	itemContainer.push_back(item);

	return;
}