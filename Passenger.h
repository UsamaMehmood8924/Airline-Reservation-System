#ifndef _PASSENGER_H_
#define _PASSENGER_H_
#include<string>
#include"Luggage.h"
using namespace std;
class Passenger
{
	string passportNo;
	string name;
	string nic;
	string gender;
	int age;
	Luggage luggage;
	int bookingid;
	int chargesForFlight;
public:
	// Constructor
	Passenger();
	Passenger(string PassportNum,string Name,string NIC,string Gender,int Age);
	Passenger(string PassportNum, string Name, string NIC, string Gender, int Age,double luggage,double allowedLugage);
	Passenger(const Passenger & obj);

	// Member Fuctions
	string getName()const;
	string getPassportNum()const;
	string getNIC()const;
	string getGender()const;
	int getAge()const;
	void setName(string s);
	void setPassportNum(string s);
	void setNIC(string s);
	void setGender(string s);
	void setAge(int i);
	void showPassengerDetails()const;
	void setPassengersLuggage(Luggage & obj);
	void calculateLuggageCharges(double w);
	double getLuggageWeightCharges();
	void setPassengersDetails();
	void setP_bookingID(int);
	int getP_bookingID()const;
	void setFlightCharges(int c);
	int getFlightCharges()const;

	// Assignment Operator overloaded
	Passenger& operator =(Passenger & obj);

	// Destructor
	~Passenger();
};
#endif

