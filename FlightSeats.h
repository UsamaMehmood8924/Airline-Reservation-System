#ifndef _FSEATS_H_
#define _FSEATS_H_
class FlightSeats
{
	int noOfSeats;
	int *board;
public:
	// Constructor
	FlightSeats();
	FlightSeats(int n);
	FlightSeats(const FlightSeats & obj);

	// Member Functions
	void setSeats(int s);
	bool bookSeat(int seatNumber, int iD);
	void showSeats();
	int  getSeatid(int i);
	void seatsID(int i, int id);

	// Destructor
	~FlightSeats();
};
#endif
