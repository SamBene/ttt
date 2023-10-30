// Bird.cpp
#include "Bird.h"

Bird::Bird() {
    cout << "Bird constructor called" << endl;
}

Bird::Bird(const string& breed, const string& color, const string& habitat, const string& diet)
    : Base(breed, color), habitat(habitat), diet(diet) {
    cout << "Bird parameterized constructor called" << endl;
}

Bird::~Bird() {
    cout << "Bird destructor called" << endl;
}

void Bird::ShowInfo() const {
    cout << "\nBird Info:" << endl;
    Base::ShowInfo();
    cout << "Habitat: " << habitat << endl;
    cout << "Diet: " << diet << "\n" << endl;
}

string Bird::GetHabitat() const {
    return habitat;
}

void Bird::SetHabitat(const string& habitat) {
    this->habitat = habitat;
}

string Bird::GetDiet() const {
    return diet;
}

void Bird::SetDiet(const string& diet) {
    this->diet = diet;
}

void Bird::SaveToFile(ofstream& file) const {
    file << "Bird ";
    Base::SaveToFile(file); // —начала сохран€ем атрибуты из базового класса
    file << GetHabitat() << " " << GetDiet() << endl;
}

void Bird::LoadFromFile(ifstream& file) {
    if (file.is_open()) {
        string habitat, diet, breed, color;

        file >> breed >> color >> habitat >> diet;

        SetBreed(breed);
        SetColor(color);
        SetHabitat(habitat);
        SetDiet(diet);
    }
}
