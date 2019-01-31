#ifndef _FDATABASE_H_
#define _FDATABASE_H_
#include"Flight.h"
class FlightDataBase:public Flight
{
	Flight *flights;
	int numberOfFlights;
public:
	// Constructor
	FlightDataBase();
	FlightDataBase(int num);
	FlightDataBase(const FlightDataBase & obj);

	// Subscript operator overloaded
	Flight& operator [](int i);

	// Member Fuctions
	int getNumberOfFlights();

	Flight& getFlightDetails(int i);

	void insert(string AirplaneNo, string FlightID, string Destination, string DepartureTime, string DepartureDate, int AvailableSeats, int TotalSeats);
	bool remove(string FlightID);

	// Destrctor
	~FlightDataBase();
};
#endif

