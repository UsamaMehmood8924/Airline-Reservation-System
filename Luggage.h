#ifndef _LUGGAGE_H_
#define _LUGGAGE_H_
class Luggage
{
	double weight;
	double charges;
	const double allowedWeight;
public:
	//Constructor
	Luggage();
	Luggage(double Weight, double Charges, double AllowedWeight);
	Luggage(double AllowedWeight):allowedWeight(AllowedWeight){}
	Luggage(const Luggage & obj);

	// Member Functions
	void setLuggage(double l);
	double getLuggageWeight();
	void setLuggageCharges();
	double getLuggageCharges();

	// Destructor
	~Luggage();
};
#endif

