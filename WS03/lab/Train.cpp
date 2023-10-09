#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Train.h"
#define MIN_TIME 700
#define MAX_TIME 2300
#define MAX_NO_OF_PASSENGERS 1000

using namespace std;

namespace sdds {

	void Train::initialize() {

		trainName = nullptr;
		noOfpeople = -1;
		departureTime = -1;
	}
	bool Train::validTime(int value) const
	{
		bool ok = false;
		if (value > MIN_TIME && value < MAX_TIME )
		{
			int minutes = value % 100;
			if (minutes <= 59)
			{
				ok = true;
			}

		}
		
		return ok;
	}
	bool Train::validNoOfPassengers(int value) const 
	{
		bool ok = false;

		if (value > 0 && value < MAX_NO_OF_PASSENGERS)
		{
			ok = true;
		}

		return ok;
	}
	void Train::set(const char* name)
	{
		if (name != nullptr && strlen(name) != 0)
		{

			delete[] this->trainName;
			trainName = nullptr;

			trainName = new char[strlen(name) + 1];
			strcpy(trainName, name);
		}

	}
	void Train::set(int noOfPassengers, int departure)
	{
		if (Train::validNoOfPassengers(noOfPassengers) && Train::validTime(departure) )
		{
			noOfpeople = noOfPassengers;
			departureTime = departure;
		}
		else
		{
			noOfpeople = -1;
			departureTime = -1;
		}
	}
	void Train::set(const char* name, int noOfPassengers, int departure)
	{
		Train::set(name);
		Train::set(noOfPassengers, departure);
	}
	void Train::finalize()
	{
		delete[] trainName;
	}
	bool Train::isInvalid() const
	{
		bool ok = false;

		if (trainName == nullptr || noOfpeople == -1 || departureTime == -1)
		{
			ok = true;
		}

		return ok;
	}
	int Train::noOfPassengers() const
	{
		return noOfpeople;
	}
	const char* Train::getName() const
	{
		return trainName;
	}
	int Train::getDepartureTime() const
	{
		return departureTime;
	}
	void Train::display() const
	{
		if (!(Train::isInvalid()))
		{
			cout << "NAME OF THE TRAIN:    " << trainName << endl;
			cout << "NUMBER OF PASSENGERS: " << noOfpeople << endl;
			cout << "DEPARTURE TIME:       " << departureTime << endl;
		}
		else
		{
			cout << "Train in an invalid State!" << endl;
		}
	}
}