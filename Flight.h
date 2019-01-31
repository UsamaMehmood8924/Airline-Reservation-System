#ifndef _FLIGHT_H_
#define _FLIGHT_H_
#include<string>
#include"FlightSeats.h"
using namespace std;
class Flight
{
	string airplaneNo;
	string flightID;
	string destination;
	string departureTime;
	string departureDate;
	int availableSeats;
	int totalSeats;
	FlightSeats noOfSeats;
public:
	//Constructrors
	Flight();
	Flight(string AirplaneNo, string FlightID, string Destination, string DepartureTime, string DepartureDate, int AvailableSeats, int TotalSeats);
	Flight(const Flight & obj);

	// Member Functions
	string getAirplaneNo()const;
	string getFlightID()const;
	string getDestination()const;
	string getDeparturetime()const;
	string getDepartureDate()const;
	int getAvailableSeats()const;
	int getTotalSeats()const;
	void setAvailablSeats();
	void setFlightID(string f);
	void showAllflights();
	void setnoOSeats(int seats);
	bool bookASeat(int seatNumber,int seatid);
	void ShowSittingPlan();
	void SetSeat(int i, int id);
	int getSeatsID(int i);
	void insert(string AirplaneNo, string FlightID, string Destination, string DepartureTime, string DepartureDate, int AvailableSeats, int TotalSeats);

	// Assignment Operator is overloaded here
	Flight operator =(Flight & obj);

	// Destructor
	~Flight();
};
#endif

