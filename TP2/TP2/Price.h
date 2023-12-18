#pragma once
#include <iostream>
#include <string>
#include "InputCheck.h"

using namespace std;

class Price
{
private:
	string name;
	string shopName;
	double price;
public:
	string getName();
	string getShopName();
	void showInfo();
	void edit();

	Price();
	Price(string name, double price, string shopName);
	~Price();
};