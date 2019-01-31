#include "Payment.h"


// Constructors
Payment::Payment()
{
	paymentType = "";
}
Payment::Payment(string s)
{
	paymentType = s;
}
Payment::Payment(const Payment & obj)
{
	paymentType = obj.paymentType;
}

// Member Functions
void Payment::cash(string s)
{
	paymentType = s;
}
void Payment::VisaCard(string s)
{
	paymentType = s;
}
void Payment::MasterCard(string s)
{
	paymentType = s;
}

// Destructor
Payment::~Payment()
{
}
