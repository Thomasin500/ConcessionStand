#ifndef INVENTORY_MANAGER_CPP
#define INVENTORY_MANAGER_CPP

#include <iostream>
#include <string>

#include "inventoryManager.h"	
#include "ConcessionItem.h"
#include "StarLightEvent.h"
#include "CustomerOptions.h"
#include "CartManager.h"

using namespace std;

//vectors are declared below as in inventoryManager.h that are stated to be external and thus, undecalred in that files
vector<concessionItem> itemContainer;
vector<starLightEvent> eventContainer;

//a method used to clean up any memory, may be unnecessary as vectors should deallocate its memory once it runs out of scope
//might be moved to a different location in the future
int endProgram() {
	
	//create a temporary, empty vector that can be swapped with the actual vector so to 'free' its memory
	vector<concessionItem> temp1;
	vector<starLightEvent> temp2;

	itemContainer.swap(temp1);
	eventContainer.swap(temp2);

	exit(0);
}


//display all concession items in inventory
void displayInventory() {

	//header for an inventory display
	cout << endl;
	
	cout << "Item #" << "	" << "Name" << "		" << "Description" << "			" << "Size" << "	" << "Price" << "	" << "Stock" << endl;

	for (size_t i = 0; i < itemContainer.size(); i++) {


		cout << i << "	" << itemContainer[i].getName() << "	" << itemContainer[i].getDescription() << "	" << itemContainer[i].displaySize() << "	" << itemContainer[i].getPrice() << "	" << itemContainer[i].getStock() << endl;
	}
	cout << endl;
}

//display all Star Light Entertainment events
void displayEvents() {

	//header for an event display
	cout << endl;
	cout << "Here are our events for today:\n";
	cout << "Event #" << "	" << "Name" << "		" << "Description" << "			" << "Price" << "	" << "Seats Open" << endl;

	//print parameters of the object
	for (size_t i = 0; i < eventContainer.size(); i++) {

		cout << i << "	" << eventContainer[i].getName() << "	" << eventContainer[i].getDescription() << "	" << eventContainer[i].getPrice() << "	" << eventContainer[i].getSeatsOpen() << endl;
	}
	cout << endl;
}

//Called upon starting the program for the first time, creates a default inventory of 5 concession items and 3 events
//In the future I would like to add some way of disabling this if the manager has already set an inventory
void createDefaultInventory() {
	
	//concession items
	concessionItem coke("Coca Cola", "A refreshing cola beverage", concessionItem::LARGE, concessionItem::DRINK, 25);
	concessionItem sprite("Sprite", "	A delicious lemon lime soda", concessionItem::MEDIUM, concessionItem::DRINK, 25);

	concessionItem cheesePizza("Cheese Pizza", "5 cheese pizza		", concessionItem::MEDIUM, concessionItem::FOOD, 10);
	concessionItem hotDog("Hot Dog", "	The all america favorite", concessionItem::SMALL, concessionItem::FOOD, 20);

	concessionItem snickers("Snickers", "Chocolate, caramel, and nugget", concessionItem::SMALL, concessionItem::CANDY, 15);

	//add items to container so that it can be accessed elsewhere
	itemContainer.push_back(coke);
	itemContainer.push_back(sprite);
	itemContainer.push_back(cheesePizza);
	itemContainer.push_back(hotDog);
	itemContainer.push_back(snickers);

	//events
	starLightEvent movie("Batman Begins", "The first Batman movie	", 9.99, "12:00", 120, 200);
	starLightEvent ballet("Florida Ballet", "State Sponsored Ballet	", 29.99, "15:30", 90, 150);
	starLightEvent concert("Metallica", "Everything but St. Anger", 59.99, "20:00", 180, 500);

	//add events to container
	eventContainer.push_back(movie);
	eventContainer.push_back(ballet);
	eventContainer.push_back(concert);	
}

#endif