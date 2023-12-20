#pragma once
#include <iostream>
#include "aeroflot.h"
#include <cstring>
using namespace std;
class Container {
private:
    class Element {
    public:
        Aeroflot* value;
        Element* prev;
        Element(Aeroflot* data, Element* prev = nullptr) {
            std::cout << "CONSTRUCTOR ELEMENT\n";
            this->value = data;
            this->prev = prev;
        }
        ~Element() {
            std::cout << "DESTRUCTOR ELEMENT\n";
            delete this->value;
        }
    };
    int count;
    Element* head;
    Element* end;

public:
    Container() {
        std::cout << "CONSTRUCTOR CONTAINER\n";
        count = 0;
        head = nullptr;
        end = nullptr;
    }

    ~Container() {
        std::cout << "DESTRUCTOR CONTAINER\n";
        while (head != nullptr && count != 0) {
            end = head;
            head = head->prev;
            delete end;
            count--;
        }
        delete head;
    }

    int getCount() { return count; }

    Aeroflot& operator[] (const int index) {
        int cnt = getCount();
        Element* cur;
        cur = this->head;
        while (cur != nullptr) {
            if (cnt == index) {
                return  *(cur->value);
            }
            cur = cur->prev;
            cnt--;
        }
    }

    void addElement(Aeroflot* x) {
        if (head == nullptr) {
            head = new Element(x);
            head->value = x;
        }
        else {
            end = new Element(x);
            end->prev = head;
            head = end;
            head->value = x;
        }
        count++;
    }

    void deleteElement(const int index) {
        if (getCount() == 1) {
            delete this->head;
            head = nullptr;
            count--;
        }
        else if (index == getCount()) {
            Element* cur = this->head;
            head = head->prev;
            delete cur;
            count--;
        }
        else {
            Element* cur = this->head;
            Element* current1 = this->head;
            int c = getCount();
            bool flag = 0;
            while (flag != 1) {
                if (c == index) {
                    int r = getCount();
                    while (r != (c + 1)) {
                        current1 = current1->prev;
                        r--;
                    }
                    Element* temp = cur;
                    cur = cur->prev;
                    current1->prev = cur;
                    delete temp;
                    flag = 1;
                    count--;
                }
                else {
                    cur = cur->prev;
                    c--;
                }
            }
        }
    }
    void displayContainer() {
        try {
            for (int i = 1; i < getCount() + 1; i++) {                        
                cout << "#"<<i<<" ";
                (*this)[i].info();
            }
        }
        catch (const exception& ex) {
            cout << ex.what();
        }
    }
    void displayAbout(string name) {
        try {
            int flag = 0;
            if (getCount() == 0) throw std::exception("EMPTY\n");

            for (int i = 1; i < getCount() + 1; i++) {
                if (((*this)[i]).getdest() == name) {
                    cout << "#"<<i<<" ";
                    (*this)[i].info();
                    flag = 1;
                }
            }
            if (flag==0) throw std::exception("NOT FOUND\n");
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << '\n';
        }
    }
    void sort() {
        /*cout << "Flight numbers before sorting:" << endl;
        for (int i = 1; i <= getCount(); ++i) {
            cout << (*this)[i].getflightNumber() << " ";
        }
        cout << endl;*/

        for (int i = 1; i < getCount(); ++i) {
            for (int j = i + 1; j <= getCount(); ++j) {
                if ((*this)[i].getflightNumber() > (*this)[j].getflightNumber()) {
                    swap((*this)[i], (*this)[j]);
                }
            }
        }

      /*  cout << "Flight numbers after sorting in order:" << endl;
        for (int i = 1; i <= getCount(); ++i) {
            cout << (*this)[i].getflightNumber() << " ";
        }
        cout << endl;*/
    }


    Aeroflot getAeroflot() {
        return (*(this->head->value));
    }
    
};