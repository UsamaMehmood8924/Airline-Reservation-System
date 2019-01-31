#ifndef _BOOKING_H_
#define _BOOKING_H_
#include"FlightDataBase.h"
#include"Passenger.h"

class Booking:public FlightDataBase,public Passenger
{
	int seats;
public:
	// Constructor
	Booking();
	Booking(int Seats);
	Booking(const Booking & obj);

	// Member Fuctions
	int booking_id();
	void makeBooking(FlightDataBase obj,Passenger & p, string FlightID, int seat);
	void showBookedSeatsOfFlight(FlightDataBase obj,string FlightID);
	bool CancelBooking(FlightDataBase obj, int BookingID);

	// Destructor
	~Booking();
};
#endif

