#include <iostream>
#include <cstring>

class Person {
private:
    char* name;

public:
    Person(const char* name = "Dasha") {
        this->name = new char[std::strlen(name) + 1];
        strcpy_s(this->name, std::strlen(name) + 1, name);
    }

    Person(const Person& other) {
        name = new char[std::strlen(other.name) + 1];
        strcpy_s(name, std::strlen(other.name) + 1, other.name);
    }

    ~Person() {
        delete[] name;
    }

    void display() const {
        std::cout << "Name: " << name << std::endl;
    }
};

class Apartment {
private:
    Person* people;
    int num_people;

public:
    Apartment(int num_people = 1) : num_people(num_people) {
        people = new Person[num_people];
    }

    Apartment(const Apartment& other) : num_people(other.num_people) {
        people = new Person[num_people];
        for (int i = 0; i < num_people; ++i) {
            people[i] = other.people[i];
        }
    }

    ~Apartment() {
        delete[] people;
    }

    void display() const {
        std::cout << "Apartment with " << num_people << " people:" << std::endl;
        for (int i = 0; i < num_people; ++i) {
            people[i].display();
        }
    }
};

class House {
private:
    Apartment* apartments;
    int num_apartments;

public:
    House(int num_apartments = 1) : num_apartments(num_apartments) {
        apartments = new Apartment[num_apartments];
    }

    House(const House& other) : num_apartments(other.num_apartments) {
        apartments = new Apartment[num_apartments];
        for (int i = 0; i < num_apartments; ++i) {
            apartments[i] = other.apartments[i];
        }
    }

    ~House() {
        delete[] apartments;
    }

    void display() const {
        std::cout << "House with " << num_apartments << " apartments:" << std::endl;
        for (int i = 0; i < num_apartments; ++i) {
            apartments[i].display();
        }
    }
};

int main() {
    House house(2);
    house.display();

    return 0;
}
