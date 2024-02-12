/*
Identity_id: a5e46652-36cc-4d22-838f-720eb35d4344
Author: Steven Li
Time: 2024/02/12
TIME: 1707773973
Briefly: 
Purpose: 
Usage:
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
        os << p.name;
        return os;
    };
public:
    Person(const string& name): name(name), age(0){}
    Person(const string& name, int age): name(name), age(age){}
    string getName() const {return name;}
    int getAge() const {return age;}
    void setName(const string& name) {this->name = name;}
    void setAge(int age) {this->age = age;}
private:
    string name;
    int age;
};

// function prototypes
// main function
int main(){
    vector<Person> group1;
    group1.emplace_back("Tom");
    group1.emplace_back("Sue");
    group1.emplace_back("Bob");
    vector<Person> group2;
    group2.emplace_back("Alice");
    group2.emplace_back("Eve");
    vector<Person> group3;
    group3.emplace_back("John");
    group3.emplace_back("Jane");
    group3.emplace_back("Joe");
    group3.emplace_back("Jill");
    group3.emplace_back("Jack");

    for (const Person& p : group1)cout << p.getName() << endl;
    for (const Person& p : group2)cout << p.getName() << endl;
    for (const Person& p : group3)cout << p.getName() << endl;
}
// function definitions