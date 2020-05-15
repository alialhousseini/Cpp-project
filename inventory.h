#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <fstream>
#include <string>
#include "location.h"
using namespace std;
#include "s_product.h"
#include "l_product.h"


class inventory
{
private:
	s_product* list_s[100];
	l_product* list_l[100];
	int size_s;
	int size_l;
public:
    void getInventoryValue();
	void getUnitCount();
	void getProductCount_s(int);
	void getProductCount_l(int);
    void getnewid(int);
    void removeProduct_s(int);
    void removeProduct_l(int);
    void add_s();
	void add_l();
	location locX;
	void load(ifstream&);
	void save(ofstream&);
	void setSize_s(int);
	void setSize_l(int);
	void setlocation(location);
	int getSize_s();
	int getSize_l();
	location getlocation();
	void getTotalPrice_l();
	void getTotalPrice_s();
	inventory(int,int,location);
	~inventory();

};
#endif
