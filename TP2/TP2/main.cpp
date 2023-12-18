#define LOWLIMIT 0  //limits for the main menu
#define UPLIMIT 7

#define SHOW 1
#define ADD 2
#define REMOVE 3
#define EDIT 4
#define ALPHABETIC_SORT 5
#define SHOW_SHOP_PRODUCTS 6
#define MIN_BASKET 7


#define EXIT 0

#include <iostream>
#include <string>
#include "InputCheck.h"
#include "Keeper.h"

using namespace std;

void printMenu();

int main() {
    Keeper keeper;

    ///////////////Testing//////////////////////
    keeper.add(new Price("banana", 10.99, "wallmart"), 0);
    keeper.add(new Price("ogre", 200.33, "seven-eleven"), 1);
    keeper.add(new Price("apple", 20.11, "euroSpar"), 2);
    keeper.add(new Price("     cc", 3, "Wendy's"), 3);
    keeper.add(new Price("apple", 20.11, "euroSaa"), 4);


    //keeper.test();
    //cout << keeper.getProduct()[0]->getName()[0] << endl;
    ///////////////Testing//////////////////////






    int position;
    cout << endl << "Hey :)" << endl << endl;
    while (true) {
        printMenu();
        switch (getIntValue(LOWLIMIT, UPLIMIT)) {
            cout << endl;
        case SHOW:
            keeper.showAllInfo();
            break;
        case ADD:
            cout << "Enter a position you want to add a product to (min is 1, max is "
                << keeper.getSize() + 1 << "):";
            position = getIntValue(1, keeper.getSize() + 1) - 1;
            cout << endl;
            keeper.add(new Price, position);    //adding a new product
            //keeper << new Price;
            break;
        case REMOVE:
            if (keeper.isEmpty()) {
                cout << endl << "The array is empty. Nothing to remove..." << endl << endl;
                break;
            }
            else {
                cout << "Here are all products:" << endl;
                keeper.showAllInfo();
                cout << "What product you want to remove? Enter a number:";
                //keeper.remove(keeper.getProductPtr(getIntValue(1, keeper.getSize())));
                keeper >> keeper.getProduct()[getIntValue(1, keeper.getSize())-1];
                break;
            }
        case EDIT:
            cout << "Here are all products:" << endl;
            keeper.showAllInfo();
            cout << "What product you want to edit? Enter a number:";
            keeper.getProduct()[getIntValue(1, keeper.getSize())-1]->edit();
            break;
        case ALPHABETIC_SORT:
            if (keeper.isEmpty()) {
                cout << endl << "The array is empty. Nothing to sort..." << endl << endl;
                break;
            }
            else {
                keeper.alphabeticSort();
                cout << endl << "The array has been alphabetically sorted." << endl << endl;
            }
            break;
        case SHOW_SHOP_PRODUCTS:
            cout << endl << "Please enter a name of the shop: ";
            keeper.showShopProducts(getStringValue());
            break;
        case MIN_BASKET:
            keeper.minBasket();
            break;
        case EXIT:
            /*while (true) {
                cout << endl << "Confirm exiting. y/n:";
                _getch()
            }*/
            cout << endl << "Exiting the program. Bye-bye." << endl << endl;
            return 0;
        default:
            cout << endl << "Wrong number entered." << endl;
            break;
        }
    }
	return 0;
}

void printMenu() {
    cout << "What do you want to do:" << endl;
    cout << "1. Show every product" << endl <<
        "2. Add a product" << endl <<
        "3. Remove a product" << endl <<
        "4. Edit a product" << endl <<
        "5. Sort the array alphabetically by the names of shops" << endl <<
        "6. Show product info that are being sold in the shop" << endl <<
        "7. Create a minimum basket" << endl <<
        "0. Exit the program" << endl << endl <<
        "Enter a number:";
}