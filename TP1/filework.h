#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Flight {
private:
    class Element1 {
    public:
        string value;
        int index;
        Element1* prev;

        Element1(string data, Element1* prev = nullptr) {
            this->value = data;
            this->prev = prev;
        }

        ~Element1() {}
    };

    int count;
    Element1* head;
    Element1* end;

    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    Flight() {
        count = 0;
        head = nullptr;
        end = nullptr;
    }

    ~Flight() {
        while (head != nullptr and count != 0) {
            end = head;
            head = head->prev;
            delete end;
            count--;
        }
        delete head;
    }

    int getCount() {
        return count;
    }

    void add(string et) {
        if (head == nullptr) {
            head = new Element1(et);
            end = head;  // Устанавливаем end на первый элемент при первом добавлении
        }
        else {
            end->prev = new Element1(et);
            end = end->prev;
        }
        count++;
    }

    void print() {
        try {
            int i = getCount();
            if (i == 0) throw exception("EMPTY\n");
            cout << endl;
            end = head;
            while (end != nullptr && i != 0) {
                cout << end->value << endl;
                end = end->prev;
                i--;
            }
            cout << endl;
        }
        catch (const exception& ex) {
            cout << ex.what();
        }
    }

    void doTask(ifstream& filik) {
        string line;
        while (getline(filik, line)) {
            istringstream iss(line);
            string word;
            while (iss >> word) {
                if (!word.empty() && isVowel(word[0])) {
                    this->add(word);
                }
            }
        }
        filik.close();
    }
};
