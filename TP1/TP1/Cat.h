// Cat.h
#pragma once
#include "Base.h"
#include <iostream>


class Cat : public Base {
public:
    Cat();
    Cat(const string& breed, const string& color, const string& ownerName, const string& name);
    ~Cat() override;

    void ShowInfo() const override;

    string GetOwnerName() const;
    void SetOwnerName(const string& ownerName);

    string GetName() const;
    void SetName(const string& name);

    void SaveToFile(ofstream& file) const override;
    void LoadFromFile(ifstream& file) override;

private:
    string ownerName;
    string name;
};
