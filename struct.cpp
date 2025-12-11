#include <iostream>
#include <string>
#include <vector>

struct Car {
    std::string make;
    int price;
};

struct Address {
    std::string city;
    std::string street;
};

struct Person {
    std::string name;
    Car car;
    Address address;
};

void printNames(const std::vector<Person>& persons) {
    for (const auto& p : persons) {
        std::cout << p.name << ' ';
    }
    std::cout << std::endl;
}

void sortByName(std::vector<Person>& persons) {
    size_t n = persons.size();

    for (size_t i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (persons[j].name > persons[j + 1].name) {
                Person temp = persons[j];
                persons[j] = persons[j + 1];
                persons[j + 1] = temp;
            }
        }
    }
}

void sortByPrice(std::vector<Person>& persons) {
    size_t n = persons.size();

    for (size_t i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (persons[j].car.price > persons[j + 1].car.price) {
                Person temp = persons[j];
                persons[j] = persons[j + 1];
                persons[j + 1] = temp;
            }
        }
    }
}

auto riches(const std::vector<Person>& persons, int min_price) {
    std::vector<std::string> result;

    for (const auto& p : persons) {
        if (p.car.price >= min_price) {
            result.push_back(p.name + "(" + p.address.city + ")");
        }
    }

    return result;
}

int main() {
    std::vector<Person> persons = {
        {"John", {"Ford", 20000}, {"London", "Oxford St."}},
        {"Mary", {"Audi", 30000}, {"Oxford", "London St."}},
        {"Sara", {"Seat", 21000}, {"Bristol", "Long St."}},
        {"Bill", {"BMW", 32000}, {"Cardiff", "King St."}},
        {"Dora", {"Tesla", 18000}, {"Belfast", "Main St."}},
        {"Adam", {"Audi", 29000}, {"London", "Abbey Rd."}}
    };
    printNames(persons);
    sortByName(persons);
    printNames(persons);
    sortByPrice(persons);
    printNames(persons);
    auto richPeople = riches(persons, 30000);
    for (auto s : richPeople) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}
