#ifndef CONCESSION_ITEM_CPP
#define CONCESSION_ITEM_CPP

#include <string>

#include "ConcessionItem.h"

using namespace std;

//default constructor and destructor
concessionItem::concessionItem(){}
concessionItem::~concessionItem(){}

//specific constructor
concessionItem::concessionItem(string name, string description, sizeType size, itemType type, int numItems) {
	
	//set object parameters 
	this->name = name;
	this->description = description;
	this->price = price;
	this->type = type;
	this->stock = numItems;
	this->numInCart = 0;

	//set price according to size
	switch (size) {

		case SMALL:
			this->price = 0.99;
			this->size = size;
			break;
	
		case MEDIUM:
			this->price = 2.99;
			this->size = size;
			break;

		case LARGE:
			this->price = 5.99;
			this->size = size;
			break;
	}
}

//getters
string concessionItem::getName() {

	return this->name;
}
string concessionItem::getDescription() {

	return this->description;
}
double concessionItem::getPrice() {

	return this->price;
}
int concessionItem::getStock() {

	return this->stock;
}
int concessionItem::getNumInCart() {

	return this->numInCart;
}
concessionItem::sizeType concessionItem::getSize() {

	return this->size;
}

//setters
void concessionItem::setName(string name){

	this->name = name;
}
void concessionItem::setDescription(string description) {

	this->description = description;
}
void concessionItem::setPrice(int price) {

	this->price = price;
}
void concessionItem::setStock(int numItems) {

	this->stock = numItems;
}
void concessionItem::setNumInCart(int numInCart) {

	this->numInCart = numInCart;
}

//utils

string concessionItem::displaySize() {

	return convertSizeToString(getSize());
}

string concessionItem::convertSizeToString(sizeType size) {

	switch (size) {
		case SMALL:
			return "Small";
			break;
		case MEDIUM:
			return "Medium";
			break;
		case LARGE:
			return "Large";
			break;
		default:
			break;
	}
}

#endif

