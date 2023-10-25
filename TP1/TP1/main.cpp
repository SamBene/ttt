// main.cpp
#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

int main() {
    Keeper keeper;

    // Создаем объекты животных и добавляем их в хранилище
    Fish fish1("Goldfish", "Gold", "Carnivorous");
    Fish fish2("Clownfish", "Orange", "Omnivorous");
    Bird bird1("Eagle", "Brown", "Mountain", "Carnivorous");
    Bird bird2("Parrot", "Green", "Jungle", "Herbivorous");
    Cat cat1("Siamese", "SealPoint", "JohnSmith", "Fluffy");
    Cat cat2("MaineCoon", "Tabby", "AliceJohnson", "Whiskers");

    keeper.AddAnimal(&fish1);
    keeper.AddAnimal(&fish2);
    keeper.AddAnimal(&bird1);
    keeper.AddAnimal(&bird2);
    keeper.AddAnimal(&cat1);
    keeper.AddAnimal(&cat2);

    keeper.ShowAllAnimals();
    keeper.SaveToFile("animals.txt");

    keeper.LoadFromFile("animals.txt");
    keeper.ShowAllAnimals();

    keeper.RemoveAnimal(2);
    keeper.ShowAllAnimals();

    return 0;
}
