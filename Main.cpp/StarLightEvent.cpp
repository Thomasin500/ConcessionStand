#ifndef STAR_LIGHT_EVENT_CPP
#define STAR_LIGHT_EVENT_CPP

#include "StarLightEvent.h"
#include <string>

using namespace std;

//default constructor and destructor
starLightEvent::starLightEvent(){}
starLightEvent::~starLightEvent(){}

//specific constructor
starLightEvent::starLightEvent(string name, string description, double price, string eventTime, int eventLength, int seatsOpen) {

	//set object parameters 
	this->name = name;
	this->description = description;
	this->price = price;
	this->eventTime = eventTime;
	this->eventLength = eventLength;
	this->seatsOpen = seatsOpen;
	this->seatsTaken = 0;
}

//getters
string starLightEvent::getName() {

	return this->name;
}
string starLightEvent::getDescription() {

	return this->description;
}
double starLightEvent::getPrice() {

	return this->price;
}
string starLightEvent::getEventTime() {

	return this->eventTime;
}
int starLightEvent::getEventLength() {

	return this->eventLength;
}
int starLightEvent::getSeatsOpen() {

	return this->seatsOpen;
}
int starLightEvent::getSeatsTaken() {

	return this->seatsTaken;
}

//setters

void starLightEvent::setName(string _name) {

	this->name = name;
}
void starLightEvent::setDescription(string _description) {

	this->description = _description;
}
void starLightEvent::setPrice(double _price) {

	this->price = _price;
}
void starLightEvent::setEventTime(string _eventTime) {

	this->eventTime = _eventTime;
}
void starLightEvent::setEventLength(int _eventLength) {

	this->eventLength = _eventLength;
}
void starLightEvent::setSeatsOpen(int _seatsOpen) {

	this->seatsOpen = _seatsOpen;
}
void starLightEvent::setSeatsTaken(int _seatsTaken) {

	this->seatsTaken = _seatsTaken;
}













#endif