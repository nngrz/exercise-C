#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::ostream;

class Animal {
public:
    Animal(string name) : name(name) {}

    virtual string voice() const = 0;
    virtual int legs() const = 0;

    string getSpecies() const {
        return species;
    };

    string getName() const {
        return name;
    };

protected:
    string species;
    string name;

    friend ostream& operator<<(ostream& os, const Animal& a) {
        os << a.species << " " << a.name
           << ", " << a.legs() << " legs, voice: \""
           << a.voice() << "\"";
        return os;
    }

    friend ostream& operator<<(ostream& os, const Animal* p) {
        if (p) os << *p;
        return os;
    }
};

// Cat
class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {
        species = "Cat";
    }

    string voice() const override {
        return "Meow";
    }

    int legs() const override {
        return 4;
    }
};

// Snake
class Snake : public Animal {
public:
    Snake(string n) : Animal(n) {
        species = "Snake";
    }

    string voice() const override {
        return "Ssss";
    }

    int legs() const override {
        return 0;
    }
};

int main() {
    Cat cat1("Oliver"), cat2("Sophie");
    Snake snake("Wire");

    Animal* arr[] = {&cat1, &cat2, &snake};

    for (const auto& a : arr) cout << *a << endl;
    cout << endl;

    for (const auto& a : arr) cout << a << endl;
}
