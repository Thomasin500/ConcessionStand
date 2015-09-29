#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

//The inventory manager is used as a central place to display, purchase, and add items to the inventory 
//Also houses all cart features and purchasing

#include <vector>
#include "ConcessionItem.h"
#include "StarLightEvent.h"


//The vector arrays declared below were chosen because 1) They can dynamically grow and shrink without having to manually reallocated memory
// and 2) they clean up their used memory very well. Declared below, their memory should be on the stack and as a vector, will call its own
// destructor automatically, thus removing the possibility of any memory leaks

//This global variable will hold all the concessionItem objects within the inventory at any given time
//declared as extern so that other files can access it as a global variable
extern vector<concessionItem> itemContainer;

//This global variable will hold all the event objects within the inventory at any given time
extern vector<starLightEvent> eventContainer;

void displayInventory();
void displayEvents();
void createDefaultInventory();
int endProgram();

#endif