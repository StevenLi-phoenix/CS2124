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
        os << p.name << " is " << (p.spouse ? "married to " + p.spouse->name : "not married.");
        return os;
    };
public:
    Person(const string& name): name(name), spouse(nullptr){}
    bool marries(Person& other){
        if (this == &other) return false; // assert not the same person
        if (this->spouse || other.spouse) return false; // this pointer is for readability
        spouse = &other; other.spouse = this; return true;}
    bool divorces(Person& other){
        spouse = nullptr; other.spouse = nullptr; return true;};
private:
    string name;
    Person* spouse;
};
// function prototypes

// main function
int main() {
    cout << "Tome and Sue:" << endl; // initial state
    Person tom = Person("Tom");
    Person sue = Person("Sue");
    cout << tom << endl;
    cout << sue << endl;
    cout << "============" << endl;

    cout << "Tom marries Sue:" << endl; // allowed, not married
    tom.marries(sue);
    cout << tom << endl;
    cout << sue << endl;
    cout << "============" << endl;

    cout << "Tom divorces Sue:" << endl; // allowed, they are married
    tom.divorces(sue);
    cout << tom << endl;
    cout << sue << endl;
    cout << "============" << endl;

    cout << "Tom marries himself:" << endl; // not allowed, same person
    tom.marries(tom);
    cout << tom << endl;
    cout << "============" << endl;

    cout << "Tom marries Sue:" << endl; // not allowed, already married
    Person mary = Person("Mary");
    tom.divorces(sue);
    mary.marries(tom);
    cout << mary << endl;
    cout << "============" << endl;

}
// function definitions
