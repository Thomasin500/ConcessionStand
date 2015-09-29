#ifndef CART_MANAGER_H
#define CART_MANAGER_H

#include "inventoryManager.h"

#include <string>

using namespace std;

class CartManager {

	public:
		//These 2 carts each hold the information of the object(s) that the customer may wish to purchase
		//2 seperate carts are used as vectors cannot hold objects of different classes or at least I have been unable to find a way to do so
		//I at first attempted to make the carts pointers to the objects within the containers, however this approached created many bugs.
		//When vector.push_back() is called, it creates a copy of that object to be put into the vector. As such any changes made to the 
		//cart objects should also be made to the corresponding container object.
		//Will look into a better way of referencing the container object in the future
		vector<starLightEvent> eventCart;
		vector<concessionItem> concessionItemCart;
		double totalPrice = 0.0;

		void removeFromCartPrompt();
		void removeEventFromCart();
		void removeItemFromCart();
		void displayCart();
		void addToCart(starLightEvent& _event, int numTickets);
		void addToCart(concessionItem& _item, int numItems);
		void emptyCart();
		void checkout();
};

#endif