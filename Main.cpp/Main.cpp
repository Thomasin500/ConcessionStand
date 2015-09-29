// Thomas Freeman

#include <iostream>
#include <vector>
#include <string>
#include "ConcessionItem.h"
#include "StarLightEvent.h"
#include "ManagerControls.h"
#include "CustomerOptions.h"
#include "inventoryManager.h"
#include "CartManager.h"

using namespace std;

//This function is used as a homepage when the user first enters the program. Can also be called to restart the system.
extern void mainGreeting() {

	cout << "\nWelcome to Starlight Entertainment! \n";
	cout << "If you would like to browse our available events and concessions please enter 1\n";
	cout << "If you are a manager and would like to add inventory from a file please enter 2\n";
	cout << "If you would like to end this program please enter 0\n";
	
	//Verify input was valid
	int input;
	if (cin >> input) {

		if (input == 1) {

			customerGreeting();
		}
		if (input == 2) {

			managerGreeting();
		}
		if (input == 0) {

			endProgram();
		}
		else {

			mainGreeting();
		}		
	}  else {

		cout << "\n\nInvalid input2\n";
		cin.clear();
		mainGreeting();
	} 
}



int main() {

	//Create a default inventory upon starting the system
	//createDefaultInventory();

	//go to first greeting menu prompt
	//from here, all other I/O is handled by either customerOptions or managerControls
	mainGreeting();

	return 0;
}