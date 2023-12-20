#include <iostream>
#include <clocale>
#include "filework.h"
#include "baseContainer.h"
#include "aeroflot.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    while (true) {
        cout << "�������� �������:\n";
        cout << "1 - Aeroflot\n";
        cout << "2 - ������ � ������\n";
        cout << "3 - �����\n";
        cout << "������� ����� ���������� ��������: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            system("cls");
            Container* con = new Container;
            while (true) {
                cout << "�������� ��������:\n";
                cout << "1 - �������� ����\n";
                cout << "2 - ������� ����\n";
                cout << "3 - ���������� � ���� �������\n";
                cout << "4 - ���������� � ���� ������ � ���������� ����� ����������\n";
                cout << "5 - ������������ >> � << ��� Aircraft\n";
                cout << "6 - Back\n";
                cout << "�������� ��������: ";
                int choice2;
                cin >> choice2;
                if (choice2 == 1) {
                    Aeroflot* aeroflot;
                    system("cls");
                    aeroflot = new Aeroflot;
                    cout << "������� ����� ���������� �����: ";
                    string name;
                    cin >> name;
                    system("cls");
                    aeroflot->setdest(name);
                    cout << "������� ��� ��������: ";
                    cin >> name;
                    aeroflot->setaircraftType(name);
                    system("cls");
                    cout << "������� ����� �����: ";
                    int nu;
                    cin >> nu;
                    system("cls");
                    aeroflot->setflightNumber(nu);
                    con->addElement(aeroflot);
                    con->sort();
                }
                else if (choice2 == 2) {
                    system("cls");
                    if (con->getCount() > 0) {
                        con->displayContainer();
                        cout << "������� ������ ������ ��� ��������: ";
                        int index;
                        cin >> index;
                        if (index > 0 and index <= (con->getCount())) {
                            system("cls");
                            con->deleteElement(index);
                        }
                        else {
                            system("cls");
                            cout << "������� ������ ������\n" << endl;
                        }
                    }
                    else {
                        cout << "EMPTY\n\n";
                    }
                }
                else if (choice2 == 3) {
                    system("cls");
                    con->displayContainer();
                }
                else if (choice2 == 4) {
                    system("cls");
                    if (con->getCount() == 0) {
                        cout << "EMPTY\n\n";
                    }
                    else {
                        cout << "������� �������� ����� ���������� ��� ������ ���� ������ � ���� �����: ";
                        string isk;
                        cin >> isk;
                        system("cls");
                        con->displayAbout(isk);
                    }
                }
                else if (choice2 == 6) {
                    system("cls");
                    if (con->getCount() > 0) {
                        int tem = con->getCount();
                        for (int k = 1; k <= tem; k++) {
                            con->deleteElement(1);
                        }
                    }
                    delete con;
                    break;
                }
                else if (choice2 == 5) {
                    system("cls");
                    Aeroflot* ba = new Aeroflot;
                    cin >> *ba;
                    cout << *ba;
                    delete ba;
                }
                else {
                    system("cls");
                    cout << "�������� �����\n";
                }
            }
        }
        else if (choice == 2) {
            ifstream file1("text.txt");
            system("cls");
            Flight task2;
            task2.doTask(file1);
            task2.print();
        }
        else if (choice == 3) {
            break;
        }
        else {
            system("cls");
            cout << "�������� �����." << endl;
        }
    }
    return 0;
}
