// Airline Reservation System

#include<iostream>
#include"FlightDataBase.h"
#include"Flight.h"
#include"Luggage.h"
#include"Passenger.h"
#include"FlightSeats.h"
#include"Booking.h"
#include"Payment.h"
#include"Ticket.h"
using namespace std;
void menu();


int main()
{
	Booking b;
	Ticket t;
	Passenger p("123456", "Usama", "3530288673533", "Male", 21);

	// My DataBase for scheduled flights //
	int numberOfFlights = 5;
	FlightDataBase flights(numberOfFlights);
	flights[0].insert("THA127", "TG961", "Thailand", "05:00 am", "25/11/2018", 40, 40);
	flights[1].insert("PAK009", "PK755", "Pakistan", "07:00 am", "25/11/2018", 40, 40);
	flights[2].insert("IND112", "IN211", "India", "12:00 pm", "25/11/2018", 40, 40);
	flights[3].insert("USA100", "US123", "US America", "03:00 pm", "25/11/2018", 60, 60);
	flights[4].insert("UAE741", "UA963", "Sharjah", "05:00 pm", "25/11/2018", 50, 50);
	//--------------------------------------------------------------------------------------//



	int choice;
	menu();
	cout << "Enter your choice: ";
	cin >> choice;
	while (choice != 10)
	{
		if (choice == 1)
		{
			string a, b, c, d, e;
			int f;
			cout << "Enter Airplane No: ";
			cin >> a;
			cout << "Enter Flight ID: ";
			cin >> b;
			cout << "Enter Destination: ";
			cin >> c;
			cout << "Enter Departure Time: ";
			cin >> d;
			cout << "Enter Departure Date (dd/mm/yyyy): ";
			cin >> e;
			cout << "Enter Total seats in Flight";
			cin >> f;

			//flights.insert("JAP753", "BO015", "Japan", "08:00", "25/11/2018", 50, 50);
			flights.insert(a, b, c, d, e, f, f);
			cout << "\nFlight Added successfully\n";
		}
		else if (choice == 2)
		{

			cout << "\nAlready Scheduled Flights\n";
			for (int i = 0; i < flights.getNumberOfFlights(); i++)
			{
				flights[i].showAllflights();
				cout << endl;
			}
			string f;
			cout << "\n\nEnter Flight ID to Remove: ";
			cin >> f;
			if (flights.remove(f) == true)
			{
				flights.remove(f);
				cout << "\n\nFlight is Successfully Removed\n";
			}
			else
			{
				cout << "\n\nInvalid Flight ID\n";
			}
		}
		else if (choice == 3)
		{
			cout << "Schedule Flights:-\n";
			for (int i = 0; i < flights.getNumberOfFlights(); i++)
			{
				flights[i].showAllflights();
				cout << endl;
			}
			cout << endl;

			string fid;
			int bok;
			cout << "Enter Flight ID: ";
			cin >> fid;
			cout << "How many seats do you want to book?: ";
			cin >> bok;
			b.makeBooking(flights, p, fid, bok);
			//b.makeBooking(flights,p, "UA963", 2);
		}
		else if (choice == 4)
		{
			cout << "Schedule Flights:-\n";
			for (int i = 0; i < flights.getNumberOfFlights(); i++)
			{
				flights[i].showAllflights();
				cout << endl;
			}
			cout << endl;

			string fid;
			cout << "Enter Flight ID: ";
			cin >> fid;
			cout << endl;
			b.showBookedSeatsOfFlight(flights, fid);
		}
		else if (choice == 5)
		{
			int ids;
			cout << "Enter Booking ID: ";
			cin >> ids;
			if (b.CancelBooking(flights, ids) == true)
			{
				cout << "\nbooking Canceled Successfully\n";
			}
			else
			{
				cout << "\nInValid Booking ID\n";
			}
		}
		else if (choice == 6)
		{
			cout << "Scheduled Flights:\n";
			for (int i = 0; i < flights.getNumberOfFlights(); i++)
			{
				flights[i].showAllflights();
				cout << endl;
			}
		}
		else if (choice == 7)
		{
			double w;
			cout << "Enter luggage weight (kg): ";
			cin >> w;
			p.calculateLuggageCharges(w);
		}
		else if (choice == 8)
		{
			if (t.Payment(12345, "MasterCard"))
			{
				if (t.GenerateTicket(flights, p))
				{
					cout << "\nTicket Successfully Generated\n";
				}
				else
				{
					cout << "\nThe Passenger has not booked any seat\n";
				}
			}
			else
			{
				cout << "\nInvalid Input\n";
			}
		}
		else if (choice == 9)
		{
			if (p.getP_bookingID() > 0)
			{
				cout << "\nBooking ID: " << p.getP_bookingID() << endl;
			}
			else
			{
				cout << "\nNo Booking ID record for this passenger\n";
			}
		}
		else if (choice > 10 && choice < 1)
		{
			cout << "Invalid Functionality Selection. Please Selete Again." << endl;
		}
		system("pause");
		system("cls");
		menu();
		cout << "Enter your choice: ";
		cin >> choice;
	}
	system("pause");
	return 0;
}
void menu()
{
	cout << "\t Functionality Menu\t" << endl;
	cout << "1: Add a New Flight " << endl;
	cout << "2: Remove Existing Flight " << endl;
	cout << "3: Book a passenger's Seat in Flight" << endl;
	cout << "4: Show Booked Seats in Flight" << endl;
	cout << "5: Cancel Booking" << endl;
	cout << "6: Show Flight Schedule" << endl;
	cout << "7: Luggage Charges of a passenger" << endl;
	cout << "8: Print Passenger's Ticket" << endl;
	cout << "9: Find Booking ID of a Passenger" << endl;
	cout << "10: Quit" << endl;
}