#include "Price.h"

string Price::getName()
{
	return this->name;
}

string Price::getShopName()
{
	return this->shopName;
}

void Price::showInfo()
{
	cout << "Name of the product is: " << Price::name << endl;
	cout << "Price of the product is: " <<Price::price << endl;
	cout << "Shop name of the product is: " << Price::shopName << endl;
}

void Price::edit()
{
	cout << "Name of the product is: " << Price::name << endl;
	cout << "Enter a new name of the product: ";
	this->name = getStringValue();
	cout << "Price of the product is: " << Price::price << endl;
	cout << "Enter a new price of the product: ";
	this->price = getDoubleValue(0,DBL_MAX);	
	cout << "Shop name of the product is: " << Price::shopName << endl;
	cout << "Enter a new name of the shop: ";
	this->shopName = getStringValue();
}

Price::Price()
{
	cout << "Price's constructor " << this << " is called" << endl;
	cout << endl << "Please enter a name of the product: ";
	Price::name = getStringValue();
	cout << endl << "Please enter a price of the product: ";
	Price::price = getDoubleValue(0, DBL_MAX);
	cout << endl << "Please enter a shop name of the product: ";
	Price::shopName = getStringValue();
}

Price::Price(string name, double price, string shopName)
{
	cout << "Price's constructor with parameters " << this << " is called" << endl;
	this->name = name;
	this->shopName = shopName;
	this->price = price;
}

Price::~Price()
{
	cout << "Price's destructor " << this << " is called" << endl;

}
