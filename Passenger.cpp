#include "Passenger.h"
#include<iostream>

// Constructor
Passenger::Passenger():luggage(15)
{
	passportNo="";
	name = "";
	nic = "";
	gender = "";
	age = 0;
	chargesForFlight = 0;
	bookingid = 0;
}
Passenger::Passenger(string PassportNum, string Name, string NIC, string Gender, int Age):luggage(15)
{
	passportNo = PassportNum;
	name = Name;
	nic = NIC;
	gender = Gender;
	age = Age;
	bookingid = 0;
	chargesForFlight = 0;
}
Passenger::Passenger(string PassportNum, string Name, string NIC, string Gender, int Age,double lugWeight,double allowedLuggae):luggage(allowedLuggae)
{
	passportNo = PassportNum;
	name = Name;
	nic = NIC;
	gender = Gender;
	age = Age;
	luggage.setLuggage(lugWeight);
	luggage.setLuggageCharges();
	bookingid = 0;
	chargesForFlight = 0;
}
Passenger::Passenger(const Passenger & obj):luggage(obj.luggage)
{
	passportNo = obj.passportNo;
	name = obj.name;
	nic = obj.nic;
	gender = obj.gender;
	age = obj.age;
	bookingid = obj.bookingid;
	chargesForFlight = obj.chargesForFlight;
}

// Member Fuctions
string Passenger::getName()const
{
	return name;
}
string Passenger::getPassportNum()const
{
	return passportNo;
}
string Passenger::getNIC()const
{
	return nic;
}
string Passenger::getGender()const
{
	return gender;
}
int Passenger::getAge()const
{
	return age;
}
void Passenger::setName(string s)
{
	name = s;
}
void Passenger::setPassportNum(string s)
{
	passportNo = s;
}
void Passenger::setNIC(string s)
{
	nic = s;
}
void Passenger::setGender(string s)
{
	gender = s;
}
void Passenger::setAge(int a)
{
	age = a;
}
double Passenger::getLuggageWeightCharges()
{
	return luggage.getLuggageCharges();
}
void Passenger::showPassengerDetails()const
{
	cout << "Name: " << name << " | " << "Age: " << age << " | " << "Gender: " << gender << " | " << "NIC: " << nic << " | "
		<< "Passport No: " << passportNo << endl;
}
void Passenger::calculateLuggageCharges(double w)
{
	cout << "Your Luggage Charges : Rs ";
	luggage.setLuggage(w);
	luggage.setLuggageCharges();
	cout << luggage.getLuggageCharges() << "/-" << endl;
}
void Passenger::setPassengersDetails()
{
	string s;
	cout << "Enter passport No: ";
	cin >> s;
	passportNo = s;
	cout << "Enter Name: ";
	cin >> s;
	name = s;
	cout << "Enter NIC No: ";
	cin >> s;
	nic = s;
	cout << "Enter Gender: ";
	cin >> s;
	gender = s;
	int i;
	cout << "Enter age: ";
	cin >> i;
	age = i;
	double w;
	cout << "How much luggage do you have to board on flight? (weight in Kgs): ";
	cin >> w;
	luggage.setLuggage(w);
	luggage.setLuggageCharges();
}
void Passenger::setPassengersLuggage(Luggage & obj)
{
	luggage.setLuggage(obj.getLuggageWeight());
	luggage.setLuggageCharges();
}
void Passenger::setP_bookingID(int id)
{
	bookingid = id;
}
int Passenger::getP_bookingID()const
{
	return bookingid;
}
void Passenger::setFlightCharges(int c)
{
	chargesForFlight = c;
}
int Passenger::getFlightCharges()const
{
	return chargesForFlight;
}
// Assignment Operator is overloaded here
Passenger& Passenger::operator =(Passenger & obj)
{
	passportNo = obj.passportNo;
	name = obj.name;
	nic = obj.nic;
	gender = obj.gender;
	age = obj.age;
	return *this;
}

// Destructor
Passenger::~Passenger()
{
}
