#include "FlightDataBase.h"
#include<iostream>
// Constructors
FlightDataBase::FlightDataBase()
{
	flights = nullptr;
	numberOfFlights = 0;
}
FlightDataBase::FlightDataBase(int n)
{
	numberOfFlights = n;
	flights = new Flight[numberOfFlights];
	for (int i = 0; i < numberOfFlights; i++)
	{
		flights[i] = Flight();
	}
}
FlightDataBase::FlightDataBase(const FlightDataBase & obj)
{
	numberOfFlights = obj.numberOfFlights;
	flights = new Flight[numberOfFlights];
	for (int i = 0; i < numberOfFlights; i++)
	{
		flights[i] = obj.flights[i];
	}
}

// member Fuctions
int FlightDataBase::getNumberOfFlights()
{
	return numberOfFlights;
}
void FlightDataBase:: insert(string AirplaneNo, string FlightID, string Destination, string DepartureTime, string DepartureDate, int AvailableSeats, int TotalSeats)
{
	numberOfFlights++;
	Flight *temp = new Flight[numberOfFlights];
	int i = 0;
	for (; i < numberOfFlights-1; i++)
	{
		temp[i] = flights[i];
	}
	temp[i].insert(AirplaneNo, FlightID, Destination, DepartureTime, DepartureDate, AvailableSeats, TotalSeats);
	delete[] flights;
	flights = new Flight[numberOfFlights];
	for (int i = 0; i < numberOfFlights; i++)
	{
		flights[i] = temp[i];
	}
	delete[] temp;
}
bool FlightDataBase::remove(string FlightID)
{
	for (int i = 0; i < numberOfFlights; i++)
	{
		if (flights[i].getFlightID() == FlightID)
		{

			Flight *temp = new Flight[numberOfFlights-1];
		
			int j = 0;
			int l = 0;

			for (; l < numberOfFlights; l++)
			{
				if (flights[l].getFlightID() == FlightID)
				{
					l++;
				}
				temp[j] = flights[l];
				j++;
			}
			numberOfFlights--;
			delete[] flights;

			flights = new Flight[numberOfFlights];
			for (int i = 0; i < numberOfFlights; i++)
			{
				flights[i] = temp[i];
			}
			delete[] temp;
			return true;
		}
		
	}
		return false;
}
Flight& FlightDataBase::getFlightDetails(int i)
{
	return flights[i];
}

// Subscript operator is overloaded here
Flight& FlightDataBase::operator [](int i)
{
	return flights[i];
}

// Destructor
FlightDataBase::~FlightDataBase()
{
	delete[]flights;
}
