#include "FlightSeats.h"
#include<iostream>
using namespace std;

//Constructors
FlightSeats::FlightSeats() :noOfSeats(0) {
	board = nullptr;
}
FlightSeats::FlightSeats(int n) :noOfSeats(n) {
	board = new int[noOfSeats];
	for (int i = 0; i < noOfSeats; i++)
	{
		board[i] = 0;
	}
}
FlightSeats::FlightSeats(const FlightSeats & obj) :noOfSeats(obj.noOfSeats) {
	board = new int[noOfSeats];
	for (int i = 0; i < noOfSeats; i++)
	{
		board[i] = obj.board[i];
	}
}


// Member Functions
void FlightSeats::showSeats()
{
	for (int i = 0; i < noOfSeats; i++)
	{
		if (i % 5 == 0)
		{
			cout << endl;
		}
		if (board[i] == 0)
		{
			if (i + 1 < 10)
			{
				cout << "0";
			}
			cout << i + 1 << " ";
		}
		else
		{
			cout << " *" << " ";
		}

	}
}
void FlightSeats::setSeats(int s)
{
	noOfSeats = s;
	board = new int[noOfSeats];
	for (int i = 0; i < noOfSeats; i++)
	{
		board[i] = 0;
	}
}
bool FlightSeats::bookSeat(int seatNumber, int iD)
{
	if (board[seatNumber] == 0)
	{
		board[seatNumber] = iD;
		return true;
	}
	else
	{
		return false;
	}
}
int FlightSeats::getSeatid(int i)
{
	return board[i];
}
void FlightSeats::seatsID(int i, int id)
{
	board[i] = id;
}

// Destructor
FlightSeats::~FlightSeats()
{
}
