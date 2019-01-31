#include "Ticket.h"
#include<iostream>

// Constructor
Ticket::Ticket()
{
	ticketCharges = 0;
}
Ticket::Ticket(int ticketCharge)
{
	ticketCharges = ticketCharge;
}
Ticket::Ticket(const Ticket & obj)
{
	ticketCharges = obj.ticketCharges;
}

// Member Variable
void Ticket::setTicketCharges(int charges)
{
	ticketCharges = charges;
}
int Ticket::getTicketCharges()const
{
	return ticketCharges;
}
bool Ticket::GenerateTicket(FlightDataBase obj, Passenger & p)
{
	//cout << p.getP_bookingID() << endl;
	if (p.getP_bookingID() > 0)
	{
		int c =0;
		int charg;
		int fc = -1;
		int count = 0;
		for (int i = 0; i < obj.getNumberOfFlights(); i++)
		{
			for (int j = 0; j < obj.getFlightDetails(i).getTotalSeats(); j++)
			{
				if (p.getP_bookingID() == obj.getFlightDetails(i).getSeatsID(j))
				{
					if (c == 0)
					{
						cout << "Enter Charges for 1 seat in Flight " << obj.getFlightDetails(i).getFlightID()<<" :";
						fc = i;
						cin >> charg;
						c++;
					}
					count++;
				}
			}
		}
		p.setFlightCharges(count*charg);
		if (fc >= 0)
		{
			cout << " _________________________________________________________________________________________________________________________" << endl;
			cout << "| "; obj.getFlightDetails(fc).showAllflights();cout<< "         " << endl;
			cout << "| " << endl;
			cout << "| Flight Charges: Rs." << p.getFlightCharges() << "/-           " << endl;
			//cout << "| Extra luggage weight Charges Rs.: " << p.getLuggageWeightCharges() << "/-           " << endl;
			cout << "| Total Charges: Rs." << p.getFlightCharges() /*+ p.getLuggageWeightCharges()*/ << "/-" << endl;
			cout << "| Have a Safe Journey " << endl;
			cout << "|_________________________________________________________________________________________________________________________" << endl;
			return true;
		}
	}
	return false;
}
bool Ticket::Payment(int BookingID, string PaymentType)
{
	if (PaymentType == "Cash")
	{
		cash(PaymentType);
		return true;
	}
	else if (PaymentType == "VisaCard")
	{
		VisaCard(PaymentType);
		return true;
	}
	else if (PaymentType == "MasterCard")
	{
		MasterCard(PaymentType);
		return true;
	}
	return false;
}

// Destructor
Ticket::~Ticket()
{
}
