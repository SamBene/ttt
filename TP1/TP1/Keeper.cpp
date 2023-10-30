// Keeper.cpp
#include "Keeper.h"
#include <fstream>
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

Keeper::Keeper() {
    cout << "Keeper constructor called" << endl;
}

Keeper::~Keeper() {
    cout << "Keeper destructor called" << endl;
   /* for (Base* animal : animals) {
        delete animal;
    }*/
}

void Keeper::AddAnimal(Base* animal) {
    animals.push_back(animal);
}

void Keeper::RemoveAnimal(int index) {
    if (index >= 0 && index < animals.size()) {
        delete animals[index];
        animals.erase(animals.begin() + index);
    }
}

void Keeper::ShowAllAnimals() const {
    for (const Base* animal : animals) {
        animal->ShowInfo();
    }
}

void Keeper::SaveToFile(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        for (const Base* animal : animals) {
            animal->SaveToFile(file);
        }
        file.close();
    }
    else {
        cerr << "Error: Unable to open file for writing." << endl;
    }
}

void Keeper::LoadFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        animals.clear(); // Очищаем текущий список животных

        while (!file.eof()) {
            string type;
            file >> type;

            Base* animal = nullptr;

            if (type == "Fish") {
                animal = new Fish();
            }
            else if (type == "Bird") {
                animal = new Bird();
            }
            else if (type == "Cat") {
                animal = new Cat();
            }

            if (animal) {
                animal->LoadFromFile(file);
                animals.push_back(animal);
            }
        }

        file.close();
    }
    else {
        cerr << "Error: Unable to open file for reading." << endl;
    }
}
