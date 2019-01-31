#include "Luggage.h"


// Constructor
Luggage::Luggage():allowedWeight(0)
{
	weight = 0;
	charges = 0;
}
Luggage::Luggage(double Weight, double Charges, double AllowedWeight):allowedWeight(AllowedWeight)
{
	weight = Weight;
	charges = Charges;
}
Luggage::Luggage(const Luggage & obj):allowedWeight(obj.allowedWeight)
{
	weight = obj.weight;
	charges = obj.charges;
}

// Member Fuctions
void Luggage::setLuggage(double l)
{
	weight = l;
}
double Luggage::getLuggageWeight()
{
	return weight;
}
void Luggage::setLuggageCharges()
{
	if (weight > allowedWeight)
	{
		charges = (weight - allowedWeight) * 250;
	}
}
double Luggage::getLuggageCharges()
{
	return charges;
}

// Destructor
Luggage::~Luggage()
{
}
