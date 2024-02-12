/*
    Identity_id: 8fe16470-6982-4c95-8ea5-80af6222f004
    Author: Steven Li
    Time: 2024/02/12
    TIME: 1707770558
    Briefly: class 7 cpp program
    Purpose: notes for class 7
    Usage: ./r class7.cpp
    Licence: CC BY-NC-SA 4.0
    */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// global variables

// class definitions
class Person{
    friend ostream& operator<<(ostream& os, const Person& p){
        if (!p.spouse) {
            os << p.name << " is not married";
        } else {
            os << p.name << " is married to " << p.spouse->name;
        }
        return os;
    };
public:
    Person(const string& name): name(name), spouse(nullptr){}
    bool marries(Person& other){spouse = &other; other.spouse = this; return true;}
    bool divorces(Person& other){spouse = nullptr; other.spouse = nullptr; return true;};
private:
    string name;
    Person *spouse;
};
// function prototypes

// main function
int main() {
    Person tom = Person("Tom");
    Person sue = Person("Sue");
    cout << tom << endl;
    cout << sue << endl;
    tom.marries(sue);
    cout << tom << endl;
    cout << sue << endl;
    tom.divorces(sue);
    cout << tom << endl;
    cout << sue << endl;
}
// function definitions
