#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


class Base {
public:
    Base(const string& breed = "", const string& color = "");
    virtual ~Base();

    virtual void ShowInfo() const;
    
    virtual void SaveToFile(ofstream& file) const;
    virtual void LoadFromFile(ifstream& file);

    string GetBreed() const;
    void SetBreed(const string& breed);

    string GetColor() const;
    void SetColor(const string& color);

private:
    string breed;
    string color;
};