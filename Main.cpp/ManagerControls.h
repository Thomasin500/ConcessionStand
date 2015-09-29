#ifndef MANAGER_CONTROLS_H
#define MANAGER_CONTROLS_H

#include <string>

using namespace std;

//Currently very barebones, this file will be a way to organize methods that are realted to what a manager should be able to do
//Future ideas include: adding/deleting from inventory, modifing events, adding additional features, etc..

void managerGreeting();
void manageInventory();
void fileInput();
void parseEvent(string line);
void parseConcessionItem(string line);





#endif