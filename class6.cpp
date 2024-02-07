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
void crossReference();
void pointerTest();

// main function
int main() {
    pointerTest();
}

// function implementations
ostream& operator<<(ostream& os, const Person& p){
    os << p.name;
    return os;
}

void crossReference(){
    Person p1("John");
    Person p2("Lisa");
    p1.marries(p2);
    cout << p1 << endl;
    cout << p2 << endl;
}

void pointerTest(){
    vector<int> v;
    cout << sizeof(v) << endl;
    char x = 'a';
    char *p;
    p = &x;
    cout << sizeof(p) << endl;
}

