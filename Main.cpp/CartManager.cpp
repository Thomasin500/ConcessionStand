#ifndef CART_MANAGER_CPP
#define CART_MANAGER_CPP

#include <iostream>
#include <string>

#include "CartManager.h"
#include "InventoryManager.h"
#include "CustomerOptions.h"

using namespace std;

//similar to endProgram() in inventory manager with the exception that it does not end the program nor empty the contains of the containers
void CartManager::emptyCart(){

	//create a temporary, empty vector that can be swapped with the actual vector
	vector<concessionItem> temp1;
	vector<starLightEvent> temp2;

	concessionItemCart.swap(temp1);
	eventCart.swap(temp2);

	customerGreeting();
}

//This prompt is needed as there are 2 different carts and no way to merge them 
//See comments in inventoryManager.h regarding the declaration of these vectors
void CartManager::removeFromCartPrompt() {

	cout << "\nIf you would like to remove an event from your cart please enter 1\n";
	cout << "If you would like to remove an item from your cart please enter 2\n";
	cout << "If you would like to go back to the main menu please enter 9\n";

	int input;
	if (cin >> input) {

		if (input == 1){

			removeEventFromCart();
		}
		if (input == 2){

			removeItemFromCart();
		}
		if (input == 9){

			customerGreeting();
		}
	}
}

//currently, since the cart and eventContainer are seperate, the cart item count can differ from the container item count
//can simply duplicate code to correct this, but the object in the container should be the same thats in the cart, pass by reference not working??

//I have later found out that the .push_back() method on vectors creates a copy of that object. I am sure there is a way to pass a pointer to the correct object,
//but for now the duplicate solution should work, will come back to this later
void CartManager::removeEventFromCart() {

	cout << "\nPlease enter the event number of the Star Light event you would like to remove\n";

	int input;
	if (cin >> input) {

		for (size_t i = 0; i < eventCart.size(); ++i) {

			if (input == i) {

				cout << "\nYou have selected " << eventCart[i].getName() << endl;
				cout << "How many event tickets would you like to remove?\n";

				//underscored to differ from the original input
				int _input;
				if (cin >> _input) {

					//verify the customer is not trying to remove more items than they have in their cart
					if (_input > eventCart[i].getSeatsTaken()) {

						cout << "\nInvalid number, you only have " << eventCart[i].getSeatsTaken() << " tickets in your cart\n";
						removeFromCartPrompt();
					}

					//change in cart
					eventCart[i].setSeatsTaken(eventCart[i].getSeatsTaken() - _input);
					eventCart[i].setSeatsOpen(eventCart[i].getSeatsOpen() + _input);

					//change in container
					eventContainer[i].setSeatsTaken(eventContainer[i].getSeatsTaken() - _input);
					eventContainer[i].setSeatsOpen(eventContainer[i].getSeatsOpen() + _input);

					//change total price
					totalPrice -= eventCart[i].getPrice() * _input;

					cout << "Item(s) removed successfully\n";
				}
			}
		}
		customerGreeting();
	}
}

//see comments on removeEventFromCart()
void CartManager::removeItemFromCart() {

	cout << "\nPlease enter the item number of the concession item you would like to remove\n";

	int input;
	if (cin >> input) {

		for (size_t i = 0; i < concessionItemCart.size(); ++i) {

			if (input == i) {

				cout << "\nYou have selected " << concessionItemCart[i].getName() << endl;
				cout << "How many concession items would you like to remove?\n";

				//underscored to differ from the original input
				int _input;
				if (cin >> _input) {

					//verify the customer is not trying to remove more items than they have in their cart
					if (_input > concessionItemCart[i].getNumInCart()) {

						cout << "\nInvalid number, you only have " << concessionItemCart[i].getNumInCart() << " items in your cart\n";
						removeFromCartPrompt();
					}

					//change in cart
					concessionItemCart[i].setNumInCart(concessionItemCart[i].getNumInCart() - _input);
					concessionItemCart[i].setStock(concessionItemCart[i].getStock() + _input);

					//change in container
					itemContainer[i].setNumInCart(itemContainer[i].getNumInCart() - _input);
					itemContainer[i].setStock(itemContainer[i].getStock() + _input);

					//change total price
					totalPrice -= concessionItemCart[i].getPrice() * _input;

					cout << "Item(s) removed successfully\n";
				}
			}
		}

		customerGreeting();
	}
}

//metallica event is not aligned properly
//A simple way to display cart and handle cart operations, can be called from any file that includes the header
//In the future I would like to seperate any I/O from this function so that it is a true 'display' function
void CartManager::displayCart() {

	if (concessionItemCart.size() == 0 && eventCart.size() == 0) {

		cout << "\nYour cart is currently empty\n";
		customerGreeting();
	}

	else {
		cout << "\nHere is your current shopping cart:\n";

		//display events in cart
		cout << endl;
		cout << "Events: \n";
		for (size_t i = 0; i < eventCart.size(); ++i){

			cout << i << "  ";
			cout << eventCart[i].getName() << "	";
			cout << "$" << eventCart[i].getPrice();

			cout << " Number of Tickets: " << eventCart[i].getSeatsTaken() << endl;

		}

		//display concession items in cart
		cout << endl;
		cout << "Concession Items: \n";
		for (size_t i = 0; i < concessionItemCart.size(); ++i){

			cout << i << "  ";
			cout << concessionItemCart[i].getName() << "	";
			cout << "$" << concessionItemCart[i].getPrice();
			cout << " Number of Items: " << concessionItemCart[i].getNumInCart() << endl;
		}

		cout << "\n\nYour total price is: $" << totalPrice << "\n\n";

		cout << "If you would like to check out and complete your order, please enter 1\n";
		cout << "If you would like to remove items from your cart, please enter 2\n";
		cout << "If you would like to go back to the main menu, please enter 9\n";

		int input;
		if (cin >> input) {

			if (input == 1) {

				checkout();
			}
			if (input == 2) {

				removeFromCartPrompt();
			}
			if (input == 9) {

				customerGreeting();
			}
			else {

				cout << "\nInvalid input4\n";
				displayCart();
			}
		}
	}
}

//pass by reference so that the actual event is being modified and not copied. 
//^^^****This is only partially true as the container event is passed by reference, but the event added to the cart is by copy
//Cart is still a copy of the corresponding container object. See comments in vector declaration in inventoryManager.h 
void CartManager::addToCart(starLightEvent& _event, int numTickets) {

	totalPrice += _event.getPrice() * numTickets;

	//value that sets if the event is a match to a current cart event or if it is new
	//could probably find a better way of doing this, works for now
	bool match = false;

	//check if cart already has the item in it, if it does just add the number of tickets to the existing order
	for (size_t i = 0; i < eventCart.size(); ++i) {

		if (_event.getName() == eventCart[i].getName()) {

			match = true;
			//change in cart
			eventCart[i].setSeatsOpen(eventCart[i].getSeatsOpen() - numTickets);
			eventCart[i].setSeatsTaken(eventCart[i].getSeatsTaken() + numTickets);

			//change in container
			eventContainer[i].setSeatsOpen(eventContainer[i].getSeatsOpen() - numTickets);
			eventContainer[i].setSeatsTaken(eventContainer[i].getSeatsTaken() + numTickets);
		}
	}
	//if new item in cart, modify object parameters and add to cart
	if (match == false) {

		//no need to change in cart as the event is updated in the container and then added to the cart so the correct information is there
		_event.setSeatsOpen(_event.getSeatsOpen() - numTickets);
		_event.setSeatsTaken(_event.getSeatsTaken() + numTickets);
		eventCart.push_back(_event);
	}
}

//similar thing here, passed by reference 
void CartManager::addToCart(concessionItem& item, int numItems) {

	totalPrice += item.getPrice() * numItems;

	//value that sets if the item is a match to a current cart item or if it is new
	//could probably find a better way of doing this, works for now
	bool match = false;

	//check if cart already has the item in it, if it does just add the number of items to the existing order
	for (size_t i = 0; i < concessionItemCart.size(); ++i) {

		if (item.getName() == concessionItemCart[i].getName()) {

			match = true;
			//change in cart
			concessionItemCart[i].setStock(concessionItemCart[i].getStock() - numItems);
			concessionItemCart[i].setNumInCart(concessionItemCart[i].getNumInCart() + numItems);

			//change in container
			itemContainer[i].setStock(itemContainer[i].getStock() - numItems);
			itemContainer[i].setNumInCart(itemContainer[i].getNumInCart() + numItems);
		}
	}
	//if new item in cart, modify object parameters and add to cart
	if (match == false) {

		//no need to change in cart as the item is updated in the container and then added to the cart so the correct information is there
		item.setStock(item.getStock() - numItems);
		item.setNumInCart(item.getNumInCart() + numItems);
		concessionItemCart.push_back(item);
	}
}

//Simple confirmation allows the customer to complete his/her transaction
void CartManager::checkout() {

	cout << "\nThe total price of your order is: $" << totalPrice << endl;
	cout << "If you would like to confirm your purchase please enter 1\n";
	cout << "If you would like to go back to the main menu please enter 9\n";

	int input;
	if (cin >> input) {

		if (input == 1) {

			cout << "\nPurchase successful!" << endl;
			cout << "\nThank you for shopping at Star Light Entertainment\n\n\n" << endl;

			//empty cart so that they can purchase more items
			emptyCart();

			cout << "\nIf you would like to exit the program now, please enter 1";
			cout << "\nIf you would like to return to the main menu, please enter 9\n";

			int _input;
			if (cin >> _input) {

				if (_input == 1) {
					
					endProgram();
				}
				if (_input == 9) {

					customerGreeting();
				}
			}
		}

		if (input == 9) {

			customerGreeting();
		}
	}
}







#endif