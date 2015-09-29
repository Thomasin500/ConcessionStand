#ifndef CONCESSION_ITEM_H
#define CONCESSION_ITEM_H

//This class is used for any concession items
//It includes both food and drink
//Make sure that stock and numInCart align so that the total number(stock and in cart) is equal to the sum of each
//Prices are set by size

#include <string>

using namespace std;

class concessionItem {
	
	//class variables
	public:
		string name;
		string description;
		double price;

		static enum sizeType{SMALL, MEDIUM, LARGE};
		sizeType size;

		static enum itemType{DRINK, FOOD, CANDY};
		itemType type;

	private:
		//number of items in inventory
		int stock;	
		//number of items in cart
		int numInCart;


	//class methods
	public:
		concessionItem();
		concessionItem(string name, string description, sizeType size, itemType type, int stock); // specific constructor
		~concessionItem(); //default destructor

		//setters and getters for each property
		string getName();
		void setName(string name);
		string getDescription();
		void setDescription(string description);
		double getPrice();
		void setPrice(int price);
		sizeType getSize();
		void setSize(sizeType size);
		int getStock();
		void setStock(int numItems);
		int getNumInCart();
		void setNumInCart(int numInCart);

		//utils
		string displaySize();

	private:
		string convertSizeToString(sizeType size);



};

#endif