#ifndef CUSTOMER_OPTIONS_CPP
#define CUSTOMER_OPTIONS_CPP

#include <iostream>
#include <vector>
#include "ConcessionItem.h"
#include "inventoryManager.h"
#include "CartManager.h"


using namespace std;;

//declared here so that it can be called from displayEventPrompt even though it is on top
void customerGreeting();

// instantiate cart
CartManager cart;

//usually called from customerGreeting(), acts as a main hub for all menu controls related to events
void displayEventPrompt() {

	displayEvents();
	
	cout << "\nTo add an event ticket to your cart please enter the event number or enter 9 to go back to the main page\n";
	 
	//verify input and match it to the event
	int input;
	if (cin >> input && input <= eventContainer.size()) {
		
		for (size_t i = 0; i < eventContainer.size(); ++i) {
			
			if (input == i) {
	
				//if matched, display the choice and prompt for ticket numbers
				cout << "\nYou have selected " << eventContainer[i].getName();
				cout << "\nHow many tickets would you like to purchase?\n";
			
				//verify input, verify the number of tickets are available, and add to cart
				int numTickets;
				if (cin >> numTickets) {

					if (numTickets > eventContainer[i].getSeatsOpen()) {

						cout << "\nSorry, there are only " << eventContainer[i].getSeatsOpen() << " tickets available\n";
						displayEventPrompt();
					}
					else {
						
						//add event to event cart
						cart.addToCart(eventContainer[i], numTickets);

						cout << "\nYou have added " << numTickets << " ticket(s) to see " + eventContainer[i].getName() << endl;

						cout << "Would you like to purchase more tickets? (y/n)\n";

						//verify input and redirect to the appropiate function
						string more;
						if (cin >> more) {

							if (more == "y") {

								displayEventPrompt();
							}
							if (more == "n") {

								cout << "\nIf you would like to review the items in your cart please enter 1" << endl;
								cout << "If you would like to go back to the main menu please enter 9" << endl;

								//this input is underscored because the original input is still being used as the id of the event
								int _input;
								if (cin >> _input) {

									if (_input == 1) {

										cart.displayCart();
									}
									if (_input == 9) {

										customerGreeting();
									}
								}								
							}
						}
					}
				}
				else {

					cout << "invalid ticket number";
					cin.clear();
					cin.ignore();
					cin.ignore();
				}

				cin.clear();
				cin.ignore();
				cin.ignore();
			}
		}	
	}

	if (input == 9) {

		customerGreeting();
	}
	else {

		cout << "\nPlease enter a valid event number\n";
		cin.clear();
		cin.ignore();
		cin.ignore();
		displayEventPrompt();
	}
}

//usually called from customerGreeting(), acts as a main hub for all menu controls related to concession items
void displayConcessionItemPrompt() {

	displayInventory();

	cout << "\nTo add a concession item to your cart please enter the item number or enter 9 to go back to the main page\n";

	//verify input and match it to the event
	int input;
	if (cin >> input && input <= itemContainer.size()) {

		for (size_t i = 0; i < itemContainer.size(); ++i) {

			if (input == i) {

				//if matched, display the choice and prompt for item numbers
				cout << "\nYou have selected " << itemContainer[i].getName();
				cout << "\nHow many items would you like to purchase?\n";

				//verify input, verify the number of items are available, and add to cart
				int numItems;
				if (cin >> numItems) {

					if (numItems > itemContainer[i].getStock()) {

						cout << "\nSorry, there are only " << itemContainer[i].getStock() << " items available\n";
						displayConcessionItemPrompt();
					}
					else {
						cout << "\nYou have added " << numItems << " item(s) of " + itemContainer[i].getName() << " to your cart" << endl;

						//add items to item cart
						cart.addToCart(itemContainer[i], numItems);

						cout << "Would you like to purchase more items? (y/n)\n";

						//verify input and redirect to the appropiate function
						string more;
						if (cin >> more) {

							if (more == "y") {

								displayConcessionItemPrompt();
							}

							if (more == "n") {

								cout << "\nIf you would like to review the items in your cart please enter 1" << endl;
								cout << "If you would like to go back to the main menu please enter 9" << endl;

								//this input is underscored because the original input is still being used as the id of the event
								int _input;
								if (cin >> _input) {

									if (_input == 1) {

										cart.displayCart();
									}
									if (_input == 9) {

										customerGreeting();
									}
								}
							}
						}
					}
				}

				else {

					cout << "invalid item";
					cin.clear();
					cin.ignore();
					cin.ignore();
				}

				cin.clear();
				cin.ignore();
				cin.ignore();
			}
		}
	}

	if (input == 9) {

		customerGreeting();
	}
	else {

		cout << "\nPlease enter a valid item number\n";
		cin.clear();
		cin.ignore();
		cin.ignore();
		displayConcessionItemPrompt();
	}
}

//This is the main menu control function which customers will first enter
//All additional future controls and features must be added here
void customerGreeting() {

	cout << "\nThank you for choosing Starlight Entertainment.\n";
	cout << "If you would like to view our current events please enter 1\n";
	cout << "If you would like to view all of our delicious food and drink at our concession stand, please enter 2\n";
	cout << "If you would like to view your cart please enter 3\n";
	cout << "If you would like to empty your cart please enter 4\n";
	cout << "To go back to the main menu please enter 9\n";	
	cout << "If you would like to end this program please enter 0\n";

	int input;

	//Verify input was valid
	if (cin >> input) {

		if (input == 1) {

			displayEventPrompt();
		}
		if (input == 2) {

			displayConcessionItemPrompt();
		}
		if (input == 3) {

			cart.displayCart();
		}
		if (input == 4) {

			cart.emptyCart();
		}
		if (input == 9){
			//return to mainGreeting function in Main.cpp
			return;
		}
		if (input == 0) {

			endProgram();
		}
		else {
			
			cin.clear();
			cin.ignore();
			cin.ignore();
			customerGreeting();
		}
	}	
}

#endif