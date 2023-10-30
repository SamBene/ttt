// Fish.cpp
#include "Fish.h"

Fish::Fish() {
    cout << "Fish constructor called" << endl;
}

Fish::Fish(const string& breed, const string& color, const string& diet)
    : Base(breed, color), diet(diet) {
    cout << "Fish parameterized constructor called" << endl;
}

Fish::~Fish() {
    cout << "Fish destructor called" << endl;
}

void Fish::ShowInfo() const {
    cout << "\nFish Info:" << endl;
    Base::ShowInfo();
    cout << "Diet: " << diet << "\n" << endl;
}

string Fish::GetDiet() const {
    return diet;
}

void Fish::SetDiet(const string& diet) {
    this->diet = diet;
}

void Fish::SaveToFile(ofstream& file) const {
    file << "Fish ";
    Base::SaveToFile(file); // —начала сохран€ем атрибуты из базового класса
    file << GetDiet() << endl;
}

void Fish::LoadFromFile(ifstream& file) {
    if (file.is_open()) {
        string breed, color, diet;

        file >> breed >> color >> diet;

        SetBreed(breed);
        SetColor(color);
        SetDiet(diet);
    }
}

