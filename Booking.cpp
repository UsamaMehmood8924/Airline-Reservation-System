#include "Booking.h"
#include<iostream>
#include<time.h>
#include <stdlib.h> 

// Constructors
Booking::Booking()
{
	seats = 0;
}
Booking::Booking(int Seats)
{
	seats = Seats;
}
Booking::Booking(const Booking & obj)
{
	seats = obj.seats;
}

// Member Functions
void Booking::makeBooking(FlightDataBase obj,Passenger & p, string FlightID, int seat)
{
	for (int i = 0; i < obj.getNumberOfFlights(); i++)
	{
		if (FlightID == obj.getFlightDetails(i).getFlightID())
		{
			cout << "\n Seating Plan of "<<obj.getFlightDetails(i).getFlightID() <<" \n";
			obj.getFlightDetails(i).ShowSittingPlan();
			cout<<"\n Total Seats: "<< obj.getFlightDetails(i).getTotalSeats() << endl;
			cout << "\n Available Seats: " << obj.getFlightDetails(i).getAvailableSeats() << endl;
			cout << endl;

			p.setP_bookingID(booking_id());
			int s;
			for (int j = 0; j < seat; j++)
			{
				cout << "Enter seat number: ";
				cin >> s;
				if (obj.getFlightDetails(i).bookASeat(s, p.getP_bookingID()))
				{
					cout << "Seat Successfully Booked\n";
					obj.getFlightDetails(i).setAvailablSeats();
				}
				else
				{
					cout << " * * *Seat not Available* * *\n";
					seat++;
					cout << "* * *Kindly book a vacant seat* * *\n";
				}
				cout << "\n";
				obj.getFlightDetails(i).ShowSittingPlan();
				cout << "\n Total Seats: " << obj.getFlightDetails(i).getTotalSeats() << endl;
				cout << "\n Available Seats: " << obj.getFlightDetails(i).getAvailableSeats() << endl;
			}

			cout << "\nPassenger's Booking ID is: ";
			cout<<p.getP_bookingID()<<endl;
			cout << endl;

			cout << "\n\n Seating Plan of " << obj.getFlightDetails(i).getFlightID() << " \n";
			obj.getFlightDetails(i).ShowSittingPlan();
			cout << "Total Seats: " << obj.getFlightDetails(i).getTotalSeats() << endl;
			cout << "\n Available Seats: " << obj.getFlightDetails(i).getAvailableSeats() << endl;
			cout << endl;
		}
	}
}
void Booking::showBookedSeatsOfFlight(FlightDataBase obj, string FlightID)
{
	for (int i = 0; i < obj.getNumberOfFlights(); i++)
	{
		if (FlightID == obj.getFlightDetails(i).getFlightID())
		{
			cout << "\n Seating Plan of " << obj.getFlightDetails(i).getFlightID() << " \n";
			obj.getFlightDetails(i).ShowSittingPlan();
			cout << "\n Total Seats: " << obj.getFlightDetails(i).getTotalSeats() << endl;
			cout << "\n Available Seats: " << obj.getFlightDetails(i).getAvailableSeats() << endl;
			cout << endl;
		}
	}
}
int Booking::booking_id()
{
	srand(time(NULL));
	int r = 105202 + rand()%99999;
	return r;
}
bool Booking::CancelBooking(FlightDataBase obj,int BookingID)
{
	bool check = false;
	for (int i = 0; i < obj.getNumberOfFlights(); i++)
	{
		for (int j = 0; j < obj.getFlightDetails(i).getTotalSeats(); j++)
		{
			if (BookingID == obj.getFlightDetails(i).getSeatsID(j))
			{
				obj.getFlightDetails(i).SetSeat(j, 0);
				cout << "Seat Successfully removed from Flight " << obj.getFlightDetails(i).getFlightID() << endl;
				cout << "\n Seating Plan of " << obj.getFlightDetails(i).getFlightID() << " \n";
				obj.getFlightDetails(i).ShowSittingPlan();
				cout << "\n Total Seats: " << obj.getFlightDetails(i).getTotalSeats() << endl;
				cout << "\n Available Seats: " << obj.getFlightDetails(i).getAvailableSeats() << endl;
				cout << endl;
				check = true;
			}
		}
	}
	return check;
}

// Destructor
Booking::~Booking()
{
}
