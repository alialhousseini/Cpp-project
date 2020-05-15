#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <malloc.h>
using namespace std;

#include "s_product.h"
#include "l_product.h"
#include "inventory.h"
#include "location.h"

// Before we begin , some notes about this program.
// There exist two classes called l_product, and s_products that represents " solid product " & " liquid product ".
// Using a input of user and bool functions we detect if any product is solid or liquid.
// Noting that the quantity of a product and the number of piece or amount, is the same. So we have included only a quantity variable.
// According to the givens of the project , we need to declare a list of products, so i have declared two lists.
// One of them for solid products and the other for liquid products.
// Every class has its own constructor.
// The location class contains the block & shelf and every product has the same location of its inventory.
// Wish you a happy tour in this program , you can use it easly because everything is arranged.
// If you have any problem, don't care , eveything you click will display with an explanation.
// Dear user, i wish to send me your notes about this program after using it and reading the code too.
// My email  a_h9@bk.ru , and thank you !
// !~ Let's Start ~!

//location class implementation
location::location(string N, string M)
{
	setblock(N);
	setshelf(M);
}

string location::getblock()
{
	return block;
}

string location::getshelf()
{
	return shelf;
}

void location::setblock(string X)
{
	block = X;
}

void location::setshelf(string Y)
{
	shelf = Y;
}

//l_product implementation
l_product::l_product(int A, string B, int C, location D, float E, bool G)
{
	setid(A);
	setname(B);
	setquantity(C);
	setlocation(D);
	setprice(E);
	F = G;
}

l_product::~l_product()
{
	delete &id;
	delete &name;
	delete &loc;
	delete &price;
	delete &F;
}

void l_product::setid(int A)
{
	id = A;
}

void l_product::setname(string B)
{
	name = B;
}

void l_product::setquantity(int C)
{
	quantity = C;
}

void l_product::setlocation(location D)
{
	loc.setblock(D.getblock());
	loc.setshelf(D.getshelf());
}

void l_product::setprice(float E)
{
	price = E;
}

int l_product::getid()
{
	return id;
}

string l_product::getname()
{
	return name;
}

int l_product::getquantity()
{
	return quantity;
}

location l_product::getlocation()
{
	return loc;
}

float l_product::getprice()
{
	return price;
}

bool l_product::isFlammable()
{
	if (F == 0)
		return 0;
	else
		return 1;
}

float l_product::Total_Price()
{
	float S = price * quantity;
	return S;
}

//s_product implementation
s_product::s_product(int A, string B, int C, location D, float E, bool G)
{
	setid(A);
	setname(B);
	setquantity(C);
	setlocation(D);
	setprice(E);
	F = G;
}

s_product::~s_product()
{
	delete& id;
	delete& name;
	delete& loc;
	delete& price;
	delete& F;
}

void s_product::setid(int A)
{
	id = A;
}

void s_product::setname(string B)
{
	name = B;
}

void s_product::setquantity(int C)
{
	quantity = C;
}

void s_product::setlocation(location D)
{
	loc.setblock(D.getblock());
	loc.setblock(D.getblock());
}

void s_product::setprice(float E)
{
	price = E;
}

int s_product::getid()
{
	return id;
}

string s_product::getname()
{
	return name;
}

int s_product::getquantity()
{
	return quantity;
}

location s_product::getlocation()
{
	return loc;
}

float s_product::getprice()
{
	return price;
}

bool s_product::isFragile()
{
	if (F == 0)
		return 0;
	else
		return 1;
}

float s_product::Total_Price()
{
	float S = price * quantity;
	return S;
}

//inventory class implementation
inventory::inventory(int X,int Y,location D)
{
	size_s = X;
	size_l = Y;
	for (int i = 0; i < size_s; i++)
		list_s[i] = new s_product(1,"default", 1, D, 1.0, 0);

	for (int i = 0; i < size_l; i++)
		list_l[i] = new l_product(1 ,"default", 1, D, 1.0, 0);

	setlocation(D);
}

location inventory::getlocation()
{
	return locX;
}

int inventory::getSize_s()
{
	return size_s;
}

int inventory::getSize_l()
{
	return size_l;
}

void inventory::setlocation(location D)
{
	locX = D;
}

void inventory::setSize_s(int X)
{
	size_s = X;
}

void inventory::setSize_l(int Y)
{
	size_l = Y;
}

void inventory::load(ifstream& inp)
{
	string S, P;
	int a = 0, b, c;
	float d;
	bool e;
	int counter = 1;
	int i1 = getSize_l();
	int i2 = getSize_s();


	char X;

	cout << "What this file contains ? \n 1- Only Solid Products. \n 2- Only Liquid Products. \n 3- Solid & Liquid Products. \n";
	cout << "Please select one of these 3 options (1/2/3)" << endl;
	cin >> a;
	while (a != 1 && a != 2 && a != 3)
	{
		cout << "Please select ONLY ONE OF these 3 options (1/2/3)\n" << endl;
		cin >> a;
	}

	if (a == 1 && a!= 2 && a != 3) {
		cout << "Now we want to take the products and put it in an array of SOLID products\n";
	}
	if (a == 2 && a != 1 && a != 3) {
        cout << "Now we want to take the products and put it in an array of LIQUID products\n";
	}
	if (a == 3 && a!= 1 && a != 2 ) {
		cout << "Now we want to take the products, but before putting every product we want to know if it is solid or liquid \n";
	}

	while (!inp.eof())
	{
		if (a == 1)
		{
            inp >>b>>P>>c>>d>>e;
			list_s[i2] = new s_product(b,P,c,getlocation(),d,e);
			i2++;
		}

		if (a == 2)
		{

			inp >> b>>P>>c>>d>>e;
            list_l[i1] = new l_product(b, P, c, getlocation(), d, e);
            i1++;
		}

		if(a == 3)
		{
			cout << "The product number " << counter << " is Liquid or Solid ? (L/S)\n";
			cin >> X;
			while ((X != 'l') && (X != 'L') && (X != 'S') && (X != 's'))
			{
				cout << "Try Again! Choose 'L' for liquid and 'S' for solid\n";
				cin >> X;
			}

			if (X == 'L' || X == 'l')
			{
				inp >> b >> P >> c >> d >> e;
				list_l[i1] = new l_product(b, P, c, getlocation(), d, e);
				i1++;
			}
			if (X == 'S' || X == 's')
			{
				inp >> b >> P >> c >> d >> e;
				list_s[i2] = new s_product(b, P, c, getlocation(), d, e);
				i2++;
			}
		}
		counter++;

	}
	setSize_l(i1);
	setSize_s(i2);
	cout<<"Loading is DONE!\n";
	inp.close();

}

void inventory::save(ofstream& out)
{

	int S1 = getSize_s();
	int S2 = getSize_l();
	int i=0;
	cout<<"You have "<< S1 <<" Solid Products.\n";
	cout<<"And " << S2 << " Liquid Product.\n";
	out << "Inventory Location\t" << getlocation().getblock() << "\t" << getlocation().getshelf() << endl;
	cout << "Printing of solid products then liquid products.\n";

        out << "Solid Products\n";
		out << "ID\t Name\t Quantity(Pieces)\t Price(Of once in $)\t Fragile(0 if FALSE / 1 if TRUE)\n";
		while(i<size_s)
		{
			out << list_s[i]->getid() << "\t" << list_s[i]->getname() << "\t" << list_s[i]->getquantity() << "\t" << list_s[i]->getprice() << "\t" << list_s[i]->isFragile();
			out << "\n";
			i++;
		}

		i=0;
		out << "Liquid Products\n";
		out << "ID\t Name\t Quantity(Amount)\t Price(per liter in $)\t Flammable(0 if FALSE / 1 if TRUE)\n";
		while(i<size_l)
		{
			out << list_l[i]->getid() << "\t" << list_l[i]->getname() << "\t" << list_l[i]->getquantity() << "\t" << list_l[i]->getprice() << "\t" << list_l[i]->isFlammable();
			out << "\n";
			i++;
		}

	cout << "Writing is DONE! Check it on your File !\n";
	out.close();


}

void inventory::removeProduct_s(int X)
{
	int count = 0;
	int j;
	for (int i = 0; i < getSize_s(); i++)
	{
		if (X == list_s[i]->getid())
		{
			list_s[i]->~s_product();

			j=i;
			while(j<size_s)
                {list_s[j]=list_s[j+1];
                    j++;}

			count++;
		}

	}
	size_s-=1;
	if (count == 0)
		{cout << "This ID doesn't exists in the list of Solid Products!\n";
		return;}

    cout<<"Removing is DONE.\n";
}

void inventory::removeProduct_l(int X)
{
	int count = 0;
	int j;
	for (int i = 0; i < getSize_l(); i++)
	{
		if (X == list_l[i]->getid())
		{
			list_l[i]->~l_product();

			j=i;
			while(j<size_l)
                {list_l[j]=list_l[j+1];
                    j++;}

			count++;
		}

	}
	size_l-=1;
	if (count == 0)
		{cout << "This ID doesn't exists in the list of Solid Products!\n";
		return;}

    cout<<"Removing is DONE.\n";
}

void inventory::add_l()
{
	int a; string b; int c; float d; bool e;
	char X;
	cout << "Do You want to give the new liquid product an ID or randomly generates it ?\n ";
	cout << "Choose 'M' to give the product an id or 'R' to randomly generating it.\n";
	cin >> X;

    while(X!='m' && X!='M' && X!='R' && X!='r')
    {
        cout<<"You must choose M or R ONLY>\n";
        cin>>X;
    }

	if (X == 'R' || X == 'r')
	{
		int i = 0;
		a= rand() % 100 + 1;
		while(i!=getSize_l())
		{
			if (a == list_l[i]->getid())
			{
				a = rand() % 100 + 1;
				i = 0;
			}
			i++;
		}

		cout << "DONE! the product has take a new id =" << a << endl;

		cout << "Give this product a name\n";
		cin >> b;

		cout << "Give this product a POSITIVE quantity.\n";
		cin >> c;
		while (c <= 0)
		{
			cout << "The quantity must be POSITIVE! Try Again.\n";
			cin >> c;
		}

		cout << "Give this product a POSITIVE price (per liter).\n";
		cin >> d;
		while (d <= 0)
		{
			cout << "The price must be POSITIVE! Try Again.\n";
			cin >> d;
		}

		cout << "It is FLAMMABLE !? ( Yes is 1 / No is 0 )\n";
		cin >> e;
		while (e != 0 && e!= 1)
		{
			cout << "The answer must be 0 or 1 ! Try Again.\n";
			cin >> e;
		}
	}

	if (X == 'm' || X == 'M')
	{
		int i = 0;
		cout << "Give this product a POSITIVE ID.\n";
		cin >> a;
		while (a <= 0)
		{
			cout << "The ID must be POSITIVE! Try Again.\n";
			cin >> a;
		}

		while (i != getSize_s())
		{
			if (a == list_s[i]->getid())
			{
				cout << "This ID is already taken, please give us a new POSITIVE ID.\n";
				cin >> a;
				while (a <= 0)
				{
					cout << "The ID must be POSITIVE! Try Again.\n";
					cin >> a;
				}
				i = 0;
			}
			i++;
		}

		cout << "Give this product a name\n";
		cin >> b;

		cout << "Give this product a POSITIVE quantity.\n";
		cin >> c;
		while (c <= 0)
		{
			cout << "The quantity must be POSITIVE! Try Again.\n";
			cin >> c;
		}

		cout << "Give this product a POSITIVE price(per liter).\n";
		cin >> d;
		while (d <= 0)
		{
			cout << "The price must be POSITIVE! Try Again.\n";
			cin >> d;
		}

		cout << "It is FRAGILE !? ( Yes is 1 / No is 0 )\n";
		cin >> e;
		while (e != 0 && e != 1)
		{
			cout << "The answer must be 0 or 1 ! Try Again.\n";
			cin >> e;
		}
	}

	list_l[getSize_l()] = new l_product(a, b, c, getlocation(), d, e);
	size_l++;

}

void inventory::add_s()
{
	int a; string b; int c; float d; bool e;
	char X;
	cout << "Do You want to give the new solid product an ID or randomly generates it ?\n ";
	cout << "Choose 'M' to give the product an id or 'R' to randomly generating it\n ";
	cin >> X;
	while(X!='m' && X!='M' && X!='R' && X!='r')
    {
        cout<<"You must choose M or R ONLY>\n";
        cin>>X;
    }

	if (X == 'R' || X == 'r')
	{
		int i = 0;
		a = rand() % 100 + 1;
		while (i != getSize_s())
		{
			if (a == list_s[i]->getid())
			{
				a = rand() % 100 + 1;
				i = 0;
			}
			i++;
		}

		cout << "DONE! the product has take a new id =" << a << endl;

		cout << "Give this product a name\n";
		cin >> b;

		cout << "Give this product a POSITIVE quantity.\n";
		cin >> c;
		while (c <= 0)
		{
			cout << "The quantity must be POSITIVE! Try Again.\n";
			cin >> c;
		}

		cout << "Give this product a POSITIVE price.\n";
		cin >> d;
		while (d <= 0)
		{
			cout << "The price must be POSITIVE! Try Again.\n";
			cin >> d;
		}

		cout << "It is FRAGILE !? ( Yes is 1 / No is 0 )\n";
		cin >> e;
		while (e != 0 && e != 1)
		{
			cout << "The answer must be 0 or 1 ! Try Again.\n";
			cin >> e;
		}
	}

	if (X == 'm' || X == 'M')
	{
		int i = 0;
		cout << "Give this product a POSITIVE ID.\n";
		cin >> a;
		while (a <= 0)
		{
			cout << "The ID must be POSITIVE! Try Again.\n";
			cin >> a;
		}

		while (i != getSize_s())
		{
			if (a == list_s[i]->getid())
			{
				cout << "This ID is already taken, please give us a new POSITIVE ID.\n";
				cin >> a;
				while (a <= 0)
				{
					cout << "The ID must be POSITIVE! Try Again.\n";
					cin >> a;
				}
				i = 0;
			}
			i++;
		}

		cout << "Give this product a name\n";
		cin >> b;

		cout << "Give this product a POSITIVE quantity.\n";
		cin >> c;
		while (c <= 0)
		{
			cout << "The quantity must be POSITIVE! Try Again.\n";
			cin >> c;
		}

		cout << "Give this product a POSITIVE price.\n";
		cin >> d;
		while (d <= 0)
		{
			cout << "The price must be POSITIVE! Try Again.\n";
			cin >> d;
		}

		cout << "It is FRAGILE !? ( Yes is 1 / No is 0 )\n";
		cin >> e;
		while (e != 0 && e != 1)
		{
			cout << "The answer must be 0 or 1 ! Try Again.\n";
			cin >> e;
		}
	}

	list_s[getSize_s()] = new s_product(a, b, c, getlocation(), d, e);
	size_s++;

}

void inventory::getnewid(int X)
{
	int a;
	int i = 0;
	int count1 = 0;
	int count2 = 0;

	while (i < getSize_l())
	{
		if (X == list_l[i]->getid())
		{
			count1++;
		}
		i++;
	}

	i = 0;

	while (i < getSize_s())
	{
		if (X == list_s[i]->getid())
		{
			count2++;
		}
		i++;
	}

	if (count1 == 0 && count2 == 0)
	{
		cout << "This ID is not an id of any of solid & liquid products!\n";
		cout << "ERROR! Try Again Later.\n";
		return;
	}

	i = 0;
	cout << "Give us the NEW ID please.\n";
	cin >> a;
	while (a <= 0)
	{
		cout << "The ID must be POSITIVE! Try Again.\n";
		cin >> a;
	}

	while (i < getSize_l())
	{
		if (a == list_l[i]->getid())
		{
			cout << "This ID is already taken, please give us a new POSITIVE ID.\n";
			cin >> a;
			while (a <= 0)
			{
				cout << "The ID must be POSITIVE! Try Again.\n";
				cin >> a;
			}
			i = 0;
		}
		i++;
	}

	if (count1 != 0 && count2 == 0)
	{
		for (int i = 0; i < size_l; i++)
			if (X == list_l[i]->getid())
			{
				list_l[i]->setid(a);
				cout<<"Changing ID is DONE.\n";
				return;
			}
	}


	while (i != getSize_s())
	{
		if (a == list_s[i]->getid())
		{
			cout << "This ID is already taken, please give us a new POSITIVE ID.\n";
			cin >> a;
			while (a <= 0)
			{
				cout << "The ID must be POSITIVE! Try Again.\n";
				cin >> a;
			}
			i = 0;
		}
		i++;
	}

	if (count1 == 0 && count2 != 0)
	{
		for (int i = 0; i < size_s; i++)
			if (X == list_s[i]->getid())
			{
				list_s[i]->setid(a);
				cout<<"Changing ID is DONE.\n";
				return;
			}
	}

}

void inventory::getProductCount_s(int X)
{
	int count = 0;
	int i = 0;
    for(i=0;i<size_s;i++)
    {
        if(X == list_s[i]->getid())
            {count++;
            break;}
    }

	if (count == 0)
	{
		cout << "The ID doesn't exists in the solid products, try again later\n";
		return;
	}

	cout << "The product of name \b" << list_s[i]->getname() << " \b you have \b " << list_s[i]->getquantity() << " \b pieces of it.\n";

}

void inventory::getProductCount_l(int X)
{
	int count = 0;
	int i = 0;
    for(i=0;i<size_l;i++)
    {
        if(X == list_l[i]->getid())
            {count++;
            break;}
    }

	if (count == 0)
	{
		cout << "The ID doesn't exists in the liquid products, try again later\n";
		return;
	}

	cout << "The product of name \b" << list_l[i]->getname() << " \b you have \b " << list_l[i]->getquantity() << " \b litre(s) of it.\n";

}

void inventory::getInventoryValue()
{
	int i = 0;
	float S = 0;
	int i1=getSize_l();
	int i2=getSize_s();

	for (i = 0 ; i < i1 ; i++)
	{
		S += (list_l[i]->getprice() * static_cast<float>(list_l[i]->getquantity()));
	}

	for (i = 0; i < i2 ; i++)
	{
		S += (list_s[i]->getprice() * static_cast<float>(list_s[i]->getquantity()));
	}

	cout << "THE TOTAL VALUE OF THIS INVENTORY IS " << S << " $ .\n";
}

void inventory::getUnitCount()
{
	int S1 = getSize_s();
	int S2 = getSize_l();
	int Sum1=0, Sum2=0;

	for (int i = 0; i < S1; i++)
		Sum1+=list_s[i]->getquantity();

	for (int i = 0; i < S2; i++)
		Sum2 += list_l[i]->getquantity();

	cout << "You have in this inventory...\n";
	cout << Sum1 << "\t pieces of solid products.\n";
	cout << Sum2 << "\t litres of liquid products.\n";
	cout << Sum1 + Sum2 << "\t unit of quantity of products.\n";

}

inventory::~inventory()
{
    int i;
    for(i=0;i<size_s;i++)
        delete list_s[i];

    for(i=0;i<size_l;i++)
        delete list_l[i];

}

void inventory::getTotalPrice_s()
{
            int X;
		    cout<<"Select the ID of the SOLID Product.\n";
		    cin>>X;
		    int i=0;
		    while(i!=getSize_s())
            {
                if(list_s[i]->getid() == X)
                {
                    cout<<"The total price is"<< list_s[i]->Total_Price() << endl;
                    break;
                }
                i++;
            }

}

void inventory::getTotalPrice_l()
{
    int X;
		    cout<<"Select the ID of the SOLID Product.\n";
		    cin>>X;
		    int i=0;
		    while(i!=getSize_l())
            {
                if(list_l[i]->getid() == X)
                {
                    cout<<"The total price is"<< list_l[i]->Total_Price() << endl;
                    break;
                }
                i++;
            }

}


//the main function
int main()
{

	cout << "Welcome to our program for managing inventories , products , and using many functions on it.\n";
	cout << "Before we start we need to tell you that you can send your review about this program to our email.\n";
	cout << "The email is : a_h9@bk.ru \n";
	cout << "To exit the program please write the number 0 \n";
	cout << "Let's Start!\n";

	cout << "1- Create an inventory to load the informations from a file.\n";
	cout << "2- Save the inventory into a file.\n";
	cout << "3- Remove a SOLID PRODUCT.\n";
	cout << "4- Remove a LIQUID PRODUCT.\n";
	cout << "5- Add a SOLID PRODUCT.\n";
	cout << "6- Add a LIQUID PRODUCT.\n";
	cout << "7- Change the ID of a product selected by its ID.\n";
	cout << "8- Get the count of a SOLID PRODUCT.\n";
	cout << "9- Get the count of a LIQUID PRODUCT.\n";
	cout << "10- Get the inventory value.\n";
	cout << "11- Get the total quantities of products\n";
	cout << "12- Clear the inventory from the memory.\n";
	cout << "13- Get the total price of a selected SOLID PRODUCT.\n";
	cout << "14- Get the total price of a selected LIQUID PRODUCT.\n";
	cout << "0- Exit the program!\n";

	int z;
	location D("default1","default2");
	inventory I(0,0,D);
	cin >> z;
	while (z != 0)
	{
		if (z == 1)
		{
			string S1, S2,S;
			cout << "The block of the location.\n";
			cin >> S1;
			cout << "The shelf of the location.\n";
			cin >> S2;
			location loc;
			loc.setblock(S1);
			loc.setshelf(S2);
			I.setlocation(loc);
			cout << "please give me the name of the file to get the products\n";
			cin >> S;
			ifstream inp;
			inp.open(S);
			while (!inp.is_open())
			{
				cout << "The file is not found.Try Again.\n";
				cin >> S;
				inp.open(S);
			}
			I.load(inp);

			cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }

		}

		if (z == 2)
		{
		    string S;
            cout<< "Please give me the name of the file to write the informations of the products\n";
            cin >> S;
            ofstream out;
			out.open(S,ofstream::trunc);
			while (!out.is_open())
			{
				cout << "The file is not found.Try Again.\n";
				cin >> S;
				out.open(S);
			}
			I.save(out);

			cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }
		}

		if (z == 3)
		{
		    int X;
		    if(I.getSize_s()==0)
            {
                cout<<"There are not solid products in this inventory, you have returned to the page of main options.\n";
                cout<<"(HINT: load solid products into the inventory)\n";
                cout<<"Select another option.\n";
                cin>>z;
            }

            while(z<0 && z>15)
            {
                cout<<"Select another option.\n";
                cin >> z;
            }

            cout<<"select the id of the SOLID PRODUCTS you want to remove it.\n";
            cin>>X;
            I.removeProduct_s(X);

            cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }

		}

		if (z == 4)
		{
		    int X;
		    if(I.getSize_l()==0)
            {
                cout<<"There are not liquid products in this inventory, you have returned to the page of main options.\n";
                cout<<"(HINT: load liquid products into the inventory)\n";
                cout<<"Select another option.\n";
                cin>>z;
            }

            while(z<0 && z>15)
            {
                cout<<"Select another option.\n";
                cin >> z;
            }

            cout<<"select the id of the LIQUID PRODUCTS you want to remove it.\n";
            cin>>X;
            I.removeProduct_l(X);


            cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }
		}

		if (z == 5)
		{
            I.add_s();
            cout<<"Adding is DONE.\n";

            cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }
		}

		if (z == 6)
		{
            I.add_l();
            cout<<"Adding is DONE.\n";

            cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }
		}

		if (z == 7)
		{
		    int X;
		    if(I.getSize_s()==0 && I.getSize_l()==0)
            {
                cout<<"There are no solid or liquid products in this inventory, you have returned to the page of main options.\n";
                cout<<"(HINT: load products into the inventory)\n";
                cout<<"Select another option.\n";
                cin>>z;
            }
            while(z<0 && z>15)
            {
                cout<<"Select another option.\n";
                cin >> z;
            }
            if(I.getSize_s()!=0 || I.getSize_l()!=0)
             {
                cout<<"Select an ID.\n";
                cin>>X;
                I.getnewid(X);
             }

             cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }
		}

		if (z == 8)
		{
		    int O;
		    cout<<"Give me the ID of the SOLID product.\n";
		    cin>>O;
            I.getProductCount_s(O);

            cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }
		}

		if (z == 9)
		{
		    int X;
		    cout<<"Give me the ID of the LIQUID product\n";
		    cin>>X;
            I.getProductCount_l(X);

            cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }

		}

		if (z == 10)
		{
		    I.getInventoryValue();
		    cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }

		}

		if (z == 11)
		{
		    I.getUnitCount();
		    cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }

		}

		if (z == 12)
		{
		    I.~inventory();
		    cout<<"DONE.\n";
		    cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }

		}

		if (z == 13)
		{
		    I.getTotalPrice_s();

		    cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }

		}

		if (z == 14)
		{
		    I.getTotalPrice_l();

		    cout<<"Select another option\n";
			cin>>z;

            while(z<0 && z>15)
            {
                cout<<"Select another option\n";
                cin >> z;
            }

		}

		if(z<0 || z>15)
		{
			cout << "This value is not found in the options, please TRY AGAIN.\n";
			cin >> z;
		}

	}

	cout << "Thank you for using our program , GoodBye!\n";

	return 0;
}
