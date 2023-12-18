#define MAXLIMIT 30
#include "Keeper.h"


void Keeper::add(Price* productPtr, int position)
{
	Price** tmp = Keeper::product;
	Keeper::size++;
	product = new Price * [Keeper::size];
	product[position] = productPtr;	//adding new product to the end of the array
	for (int i = 0,j=0; i < size; i++) {
		if (i != position) {
			product[i] = tmp[j];
			j++;
		}
		else
			continue;
	}
}

void Keeper::remove(Price* productPtr)
{
	Price** tmp = Keeper::product;
	Keeper::size--;
	product = new Price * [Keeper::size];
	for (int i = 0; i <= size; i++) {	//"i <= size" because i have to check all elements of the initial array
		if (tmp[i] != productPtr) {
			product[i] = tmp[i];
		}
		else {
			i++;
			for (int j = i - 1; i <= size; j++, i++)
				product[j] = tmp[i];
			break;
		}
	}
	delete productPtr;
	cout << endl << "The element has been removed" << endl << endl;
}

void Keeper::showAllInfo() {
	if (size == 0)		//array is empty
		cout << endl << "The array is empty. Nothing to show for now..." << endl << endl;
	else
		for (int i = 0; i < size; i++) {
			cout << endl << "~~~~~~~~~~~~~~~~~~" << endl;
			cout << i + 1 << "." << endl;
			getProduct()[i]->showInfo();
			cout << "~~~~~~~~~~~~~~~~~~" << endl << endl;
		}
}

bool Keeper::isEmpty()
{
	if (Keeper::size > 0)
		return false;
	else
		return true;
}


Price& Keeper::operator<<(Price* productPtr)
{
	cout << "Enter a position you want to add a product to (min is 1, max is "
		<< Keeper::getSize() + 1 << "):";
	int position = getIntValue(1, Keeper::getSize() + 1) - 1;
	Price** tmp = Keeper::product;
	Keeper::size++;
	product = new Price * [Keeper::size];
	product[position] = productPtr;	//adding new product to the end of the array
	for (int i = 0, j = 0; i < size; i++) {
		if (i != position) {
			product[i] = tmp[j];
			j++;
		}
		else
			continue;
	}
	return **product;
}

Price& Keeper::operator>>(Price* productPtr)
{
	Price** tmp = Keeper::product;
	Keeper::size--;
	product = new Price * [Keeper::size];
	for (int i = 0; i <= size; i++) {	//"i <= size" because i have to check all elements of the initial array
		if (tmp[i] != productPtr) {
			product[i] = tmp[i];
		}
		else {
			i++;
			for (int j = i - 1; i <= size; j++, i++)
				product[j] = tmp[i];
			break;
		}
	}
	delete productPtr;
	cout << endl << "The element has been removed" << endl << endl;
	return **product;
}

void Keeper::alphabeticSort(){	//TODO:complete the function - when two shops have slightly same names
	for (int i = 0; i < Keeper::getSize(); i++){
		for (int j = 0; j < Keeper::getSize() - i - 1; j++) {
			char firstCharLine1 = getProduct()[j]->getShopName()[0];	//first character of the string
			int k = 0;
			while (true) {
				if (firstCharLine1 == ' ' || firstCharLine1 == '.' || firstCharLine1 == ',' || firstCharLine1 == '-') {
					firstCharLine1 = getProduct()[j]->getShopName()[k];
					k++;
				}
				else
					break;
			}
			char firstCharLine2 = getProduct()[j+1]->getShopName()[0];	//first character of the string
			k = 0;
			while (true) {
				if (firstCharLine2 == ' ') {
					firstCharLine2 = getProduct()[j + 1]->getShopName()[k];
					k++;
				}
				else
					break;
			}
			if (firstCharLine1 == firstCharLine2) {
				int q = 0;
				for (; product[j]->getShopName()[q] == product[j + 1]->getShopName()[q]; q++) {
					firstCharLine1 = product[j]->getShopName()[q];
					firstCharLine2 = product[j + 1]->getShopName()[q];
				}
				firstCharLine1 = product[j]->getShopName()[q];
				firstCharLine2 = product[j + 1]->getShopName()[q];
			}

			if (firstCharLine1 > firstCharLine2) {
				Price* tmp = *(getProduct()+j);
				*(getProduct()+j) = *(getProduct() + j + 1);
				*(getProduct()+j + 1) = tmp;
			}
		}
	}
}

void Keeper::showShopProducts(string shopName)
{
	bool flag = false;	//flag is 1 if a match has been found; otherwise - it's 0
	if (isEmpty())
		cout << endl << "The array is empty. Nothing to show for now..." << endl << endl;
	else
		for (int i = 0; i < Keeper::getSize(); i++) {
			if (product[i]->getShopName() == shopName) {
				flag = true;
				cout << endl << "~~~~~~~~~~~~~~~~~~" << endl;
				cout << i + 1 << "." << endl;
				product[i]->showInfo();
				cout << "~~~~~~~~~~~~~~~~~~" << endl << endl;
			}
		}
	if (!flag)
		cout << endl << "Entered shop not found." << endl << endl;
}

void Keeper::minBasket()
{
	typedef struct foodItem {
		string foodName, foodCategory;
		int foodPrice;
	} food;

	food foodList[MAXLIMIT];
	int foodNumber,i, f, searchedamount, foundamount, min, minPrice;

	fstream file;
	file.exceptions(ofstream::badbit);
	try {
		file.open("FoodDatabase.txt", std::fstream::in);
	}
	catch (const ofstream::failure& ex) {
		cout << endl << "Error occured while opening the file." << endl;
		cout << endl << ex.what() << endl << ex.code() << endl;
	}
	file >> foodNumber;
	for (int i = 0; i < foodNumber; i++) {
		file >> foodList[i].foodName;
		file >> foodList[i].foodCategory;
		file >> foodList[i].foodPrice;
	}

	typedef struct {
		string searchedCategory;
		int thereis;
	} basket;

	basket minBasket[20];
	for (i = 0; i < 20; i++)
		minBasket[i].thereis = 0;
	searchedamount = 0;
	foundamount = 0;
	min = -1;
	string line;
	i = 0;
	
	printf("\nEnter a NUMBER of desired product categories to create a minimum basket:\n");
	int searchedCatNum;	//Number of searhed categories
	searchedCatNum = getIntValue(1, 10);
	for (int j = 0; j < searchedCatNum; j++) {
		cout << endl << "Enter the " << j + 1 << " category:";
		minBasket[i].searchedCategory = getStringValue();
		i++;
		searchedamount++;
	}
	printf("\nProgram has added these products to the minimum basket:\n");
	for (i = 0; i < searchedamount; i++) {
		minPrice = INT_MAX;
		for (f = 0; f < foodNumber; f++) {
			if (minBasket[i].searchedCategory.compare(foodList[f].foodCategory) == 0) {
				minBasket[i].thereis++;
				if (minPrice == INT_MAX)
					foundamount++;
				if (foodList[f].foodPrice < minPrice) {
					minPrice = foodList[f].foodPrice;
					min = f;
				}
			}
			if ((f == foodNumber - 1) && (min >= 0) && (minBasket[i].thereis > 0))
				cout << endl << foodList[min].foodName << " for " << foodList[min].foodPrice << " rub." << endl;
		}
	}
	if (searchedamount > foundamount) {
		printf("\nNo matches found for the following categories:\n");
		for (i = 0; i < searchedamount; i++)
			if (minBasket[i].thereis == 0)
				cout << endl << minBasket[i].searchedCategory << endl << endl;
	}
	file.close();
}




void Keeper::setProduct(Price* product)
{
	this->product = &product;
}


Price** Keeper::getProduct()
{
	return product;
}

int Keeper::getSize()
{
	return Keeper::size;
}

Keeper::Keeper() {
	cout << "Keeper's constructor " << this << " is called" << endl;
	size = 0;
	product = new Price * [size];
}

Keeper::~Keeper()
{
	cout << "Keeper's destructor " << this << " is called" << endl;
	for (int i = 0; i < size; i++) {

		delete product[i];
	}
	product = nullptr;
	size = 0;
}
