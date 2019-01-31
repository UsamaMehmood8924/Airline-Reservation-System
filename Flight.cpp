#include "Flight.h"
#include<iostream>

// Constructors
Flight::Flight():noOfSeats(0)
{
	airplaneNo = "";
	flightID = "";
	destination = "";
	departureTime = "";
	departureDate = "";
	availableSeats = 0;
	totalSeats = 0;
	
}
Flight::Flight(string A, string F, string D, string DT, string DD, int ASeats, int TSeats):noOfSeats(TSeats)
{
	airplaneNo = A;
	flightID = F;
	destination = D;
	departureTime = DT;
	departureDate = DD;
	availableSeats = ASeats;
	totalSeats = TSeats;
}
Flight::Flight(const Flight & obj)
{
	airplaneNo = obj.airplaneNo;
	flightID = obj.flightID;
	destination = obj.destination;
	departureTime = obj.departureTime;
	departureDate = obj.departureDate;
	availableSeats = obj.availableSeats;
	totalSeats = obj.totalSeats;
	noOfSeats = obj.noOfSeats;
}

// Member Fuctions
string Flight::getAirplaneNo()const
{
	return airplaneNo;
}
string Flight::getFlightID()const
{
	return flightID;
}
string Flight::getDestination()const
{
	return destination;
}
string Flight::getDeparturetime()const
{
	return departureTime;
}
string Flight::getDepartureDate()const
{
	return departureDate;
}
int Flight::getAvailableSeats()const
{
	return availableSeats;
}
int Flight::getTotalSeats()const
{
	return totalSeats;
}
void Flight::insert(string A, string F, string D, string DT, string DD, int ASeats, int TSeats)
{
	airplaneNo = A;
	flightID = F;
	destination = D;
	departureTime = DT;
	departureDate = DD;
	availableSeats = ASeats;
	totalSeats = TSeats;
	noOfSeats.setSeats(TSeats);
}
void Flight::showAllflights()
{
	cout << "Airplane No: " << airplaneNo << " | " << "Flight ID: " << flightID << " | " << "Destination: " << destination << " | "
		<< "Departure Time: " << departureTime << " | " << "Departure Date: " << departureDate << endl;
}
void Flight::ShowSittingPlan()
{
	noOfSeats.showSeats();
}
void Flight::setnoOSeats(int seats)
{
	noOfSeats.setSeats(totalSeats);
}
bool Flight::bookASeat(int seatNumber,int id)
{
	if (noOfSeats.bookSeat(seatNumber,id) == true)
	{
		noOfSeats.bookSeat(seatNumber,id);
		return true;
	}
	return false;
}
void Flight::SetSeat(int i, int id)
{
	noOfSeats.seatsID(i, id);
}
int Flight::getSeatsID(int i)
{
	return noOfSeats.getSeatid(i);
}
void Flight::setAvailablSeats()
{
	availableSeats--;
}
void Flight::setFlightID(string f)
{
	flightID = f;
}

// Assignment Operator is overloaded here
Flight Flight::operator =(Flight & obj)
{
	airplaneNo = obj.airplaneNo;
	flightID = obj.flightID;
	destination = obj.destination;
	departureTime = obj.departureTime;
	departureDate = obj.departureDate;
	availableSeats = obj.availableSeats;
	totalSeats = obj.totalSeats;
	noOfSeats = obj.noOfSeats;
	return *this;
}


// Destructor
Flight::~Flight()
{
}
