#ifndef SOLID_H
#define SOLID_H

#include <iostream>
#include <string>
#include "location.h"
using namespace std;

class s_product
{
private:
	int id;
	string name;
	int quantity;
	float price;
	bool F;

public:
	location loc;
	bool isFragile();
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
	s_product(int, string, int, location, float, bool);
	~s_product();
};

#endif
