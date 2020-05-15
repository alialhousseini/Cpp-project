#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <string>
using namespace std;

class location
{
private:
	string block;
	string shelf;
public:
	location(string bn="default1", string sn="default2");
	string getblock();
	string getshelf();
	void setshelf(string);
	void setblock(string);
};

#endif
