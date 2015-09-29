#ifndef STAR_LIGHT_EVENT_H
#define STAR_LIGHT_EVENT_H

//This class is where all event objects are derived from. Events have no set type such as price or size, it is all manager defined
//It is important to keep in mind that setsOpen and seatsTaken should ALWAYS align so that the total seats are the sum of each

#include <string>

using namespace std;

class starLightEvent {

	//class variables
	public:
		string name;
		string description;
		double price;
		string eventTime;
		int eventLength;

	private:
		int seatsOpen;
		int seatsTaken;

	//class methods
	public:
		starLightEvent(); //default constructor
		starLightEvent(string name, string description, double price, string eventTime, int eventLength, int seatsOpen); // specific constructor
		~starLightEvent(); //default destructor

		//setters and getters for each property
		string getName();
		void setName(string _name);
		string getDescription();
		void setDescription(string _description);
		double getPrice();
		void setPrice(double _price);
		string getSize();
		
		string getEventTime();
		void setEventTime(string _eventTime);
		int getEventLength();
		void setEventLength(int _eventLength);

		void setSeatsOpen(int _seatsOpen);
		int getSeatsOpen();
		void setSeatsTaken(int _seatsTaken);
		int getSeatsTaken();

};

#endif