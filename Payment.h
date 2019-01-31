#ifndef _PAYMENT_H_
#define _PAYMENT_H_
#include<string>
using namespace std;
class Payment
{
	string paymentType;
public:
	//Constructor
	Payment();
	Payment(string s);
	Payment(const Payment & obj);
	virtual void cash(string s);
	virtual void VisaCard(string s);
	virtual void MasterCard(string s);
	~Payment();
};
#endif

