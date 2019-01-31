#ifndef _TICKET_H_
#define _TICKET_H_
#include"Payment.h"
#include"FlightDataBase.h"
#include"Passenger.h"
class Ticket:public Payment
{
	int ticketCharges;
public:
	//Constructor
	Ticket();
	Ticket(int ticketCharge);
	Ticket(const Ticket & obj);

	// Member Functions
	void setTicketCharges(int charges);
	int getTicketCharges()const;
	bool GenerateTicket(FlightDataBase flight,Passenger & p);
	bool Payment(int BookingID, string PaymentType);

	// Destructor
	~Ticket();
};
#endif

