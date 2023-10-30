// Fish.h
#pragma once
#include "Base.h"
#include <iostream>
using namespace std;

class Fish : public Base {
public:
    Fish();
    Fish(const string& breed, const string& color, const string& diet);
    ~Fish() override;

    void ShowInfo() const override;

    string GetDiet() const;
    void SetDiet(const string& diet);

    void SaveToFile(ofstream& file) const override;
    void LoadFromFile(ifstream& file) override;

private:
    string diet;
};
