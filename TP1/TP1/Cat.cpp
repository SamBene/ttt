// Cat.cpp
#include "Cat.h"

Cat::Cat() {
    cout << "Cat constructor called" << endl;
}

Cat::Cat(const string& breed, const string& color, const string& ownerName, const string& name)
    : Base(breed, color), ownerName(ownerName), name(name) {
    cout << "Cat parameterized constructor called" << endl;
}

Cat::~Cat() {
    cout << "Cat destructor called" << endl;
}

void Cat::ShowInfo() const {
    cout << "\nCat Info:" << endl;
    Base::ShowInfo();
    cout << "Owner Name: " << ownerName << endl;
    cout << "Name: " << name << "\n" << endl;
}

string Cat::GetOwnerName() const {
    return ownerName;
}

void Cat::SetOwnerName(const string& ownerName) {
    this->ownerName = ownerName;
}

string Cat::GetName() const {
    return name;
}

void Cat::SetName(const string& name) {
    this->name = name;
}

void Cat::SaveToFile(ofstream& file) const {
    file << "Cat ";
    Base::SaveToFile(file); // —начала сохран€ем атрибуты из базового класса
    file << GetOwnerName() << " " << GetName() << endl;
}

void Cat::LoadFromFile(ifstream& file) {
    if (file.is_open()) {
        string name, ownerName, breed, color;

        file >> breed >> color >> ownerName >> name;

        SetBreed(breed);
        SetColor(color);
        SetOwnerName(ownerName);
        SetName(name);
    }
}
