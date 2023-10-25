#include "Base.h"
#include <iostream>

using namespace std;

Base::Base(const string& breed, const string& color)
    : breed(breed), color(color) {
    cout << "Base constructor called" << endl;
}

Base::~Base() {
    cout << "Base destructor called" << endl;
}

void Base::ShowInfo() const {
    cout << "Breed: " << breed << endl;
    cout << "Color: " << color << endl;
}

void Base::SaveToFile(ofstream& file) const {
    file << GetBreed() << " " << GetColor() << " ";
}

void Base::LoadFromFile(ifstream& file) {
    file >> breed >> color;
}

string Base::GetBreed() const {
    return breed;
}

void Base::SetBreed(const string& breed) {
    this->breed = breed;
}

string Base::GetColor() const {
    return color;
}

void Base::SetColor(const string& color) {
    this->color = color;
}