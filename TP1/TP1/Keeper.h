#pragma once
#include <vector>
#include "Base.h"
using namespace std;

class Keeper {
public:
    Keeper();
    ~Keeper();

    void AddAnimal(Base* animal);
    void RemoveAnimal(int index);
    void ShowAllAnimals() const;

    void SaveToFile(const string& filename) const;
    void LoadFromFile(const string& filename);

private:
    vector<Base*> animals;
};
