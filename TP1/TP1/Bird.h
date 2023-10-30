// Bird.h
#pragma once
#include "Base.h"
#include <iostream>
using namespace std;

class Bird : public Base {
public:
    Bird();
    Bird(const string& breed, const string& color, const string& habitat, const string& diet);
    ~Bird() override;

    void ShowInfo() const override;

    string GetHabitat() const;
    void SetHabitat(const string& habitat);

    string GetDiet() const;
    void SetDiet(const string& diet);

    void SaveToFile(ofstream& file) const override;
    void LoadFromFile(ifstream& file) override;

private:
    string habitat;
    string diet;
};
