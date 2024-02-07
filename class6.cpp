/*
Identity_id: cd1c47d7-d691-479c-ae84-65f8c3ad8f8b
Author: Steven Li
Time: 2024/02/07
TIME: 1707337999
Briefly: This a class 6 cpp program
Purpose: Class 6 classnote
Usage: run directly
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
    public:
        Person(const string& name): name(name){}

        friend ostream& operator<<(ostream& os, const Person& p);

        bool marries(Person& other){
            // spouse = other; // function (declared implicitly), cannot be referred -- it is a deleted function
            return true;
        }
    private:
        string name;
        // Person& spouse;

};

// function prototypes
void crossSpouse();
void pointerTest();
void pointerSwap();

// main function
int main() {
    pointerSwap();
}

// function implementations
ostream& operator<<(ostream& os, const Person& p){
    os << p.name;
    return os;
}

void crossSpouse(){
    Person p1("John");
    Person p2("Lisa");
    p1.marries(p2);
    cout << p1 << endl;
    cout << p2 << endl;
}

void pointerTest(){
    int first, second;
    int *p;

    p = &first;
    *p = 10;
    p = &second;
    *p = 20;

    cout << "first: " << first << endl;
    cout << "second: " << second << endl;
}

void pointerSwap(){
    int first = 1, second = 20;
    int *p1, *p2;

    p1 = &first;
    p2 = &second;  

    *p1 = 10; 
    *p2 = *p1;

    *p1 = 11;
    *p2 = 12;

    cout << "first: " << first << endl;
    cout << "second: " << second << endl;

    p1 = p2;
    *p1 = 30;

    cout << "first: " << first << endl;
    cout << "second: " << second << endl;
}

