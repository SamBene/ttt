#pragma once
#include "Price.h"
#include <fstream>
class Keeper	
{
private:
	int size;	//size of the dynamic array of pointers
	Price** product;
	void setProduct(Price* product);
public:	
	void add(Price* productPtr, int position);	
	void remove(Price* productPtr);
	Price** getProduct();
	int getSize();
	void showAllInfo();
	bool isEmpty();

	void alphabeticSort();
	void showShopProducts(string shopName);
	void minBasket();	//additional functionality

	Price& operator<<(Price* productPtr);
	Price& operator>>(Price* productPtr);


	Keeper();
	~Keeper();
};

