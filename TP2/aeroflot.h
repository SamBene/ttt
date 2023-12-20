#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Aeroflot {
private:
	string dest;
	int flightNumber;
	string aircraftType;
	friend istream& operator>>(istream& os, Aeroflot& pt);
	friend ostream& operator<<(ostream& os, Aeroflot& pt);
public:
	Aeroflot() {
		cout << "constructor called Aeroflot\n";
		dest = "";
		flightNumber = 0;
		aircraftType = "";
	}
	~Aeroflot() { cout << "destructor called Aeroflot\n"; }
	void setdest(string a) {
		dest = a;
	}

	void setflightNumber(int a) {
		flightNumber = a;
	}

	void setaircraftType(string a) {
		aircraftType = a;
	}

	string getdest() {
		return dest;
	}
	int getflightNumber() {
		return flightNumber;
	}
	string getaircraftType() {
		return aircraftType;
	}
	void info() {
		cout << "destanation: " << dest << "; flight: " << flightNumber << "; aircraft: " << aircraftType<<endl;
	}
};

istream& operator>>(istream& os, Aeroflot& pt) {
	cout << "¬ведите пункт назначени€ рейса: ";
	os >> pt.dest;
	system("cls");
	cout << "¬ведите номер рейса: ";
	os >> pt.flightNumber;
	system("cls");
	cout << "¬ведите тип самолета: ";
	os >> pt.aircraftType;
	system("cls");
	return os;
}
ostream& operator<<(ostream& os, Aeroflot& pt) {
	os << "destanation: " << pt.dest << "; flight: " << pt.flightNumber << "; aircraft: " << pt.aircraftType << endl;
	return os;
}
