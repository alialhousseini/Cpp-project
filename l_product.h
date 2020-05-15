#ifndef LIQUID_H
#define LIQUID_H

#include <iostream>
#include <string>
#include "location.h"
using namespace std;

class l_product
{
private:
	int id;
	string name;
	int quantity;
	float price;
	bool F;

public:
	location loc;
	bool isFlammable();
	float Total_Price();
	void setid(int);
	void setname(string);
	void setquantity(int);
	void setlocation(location);
	void setprice(float);
	int getid();
	string getname();
	location getlocation();
	int getquantity();
	float getprice();
	l_product(int, string, int,location , float, bool);
	~l_product();
};

#endif
