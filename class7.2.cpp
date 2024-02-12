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
        os << p.name << " is " << p.age << " years old.";
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
    group1.push_back(Person("Tom", 35));
    group1.push_back(Person("Sue", 30));
    group1.push_back(Person("Bob", 25));
    vector<Person> group2;
    group2.push_back(Person("Alice", 40));
    group2.push_back(Person("Eve", 45));
    vector<Person> group3;
    group3.push_back(Person("Jane", 50));
    group3.push_back(Person("Joe", 55));
    group3.push_back(Person("Jill", 60));
    group3.push_back(Person("Jack", 65));
    group3.push_back(Person("Jen", 70));
    
    cout << "Group 1:" << endl; for (const Person& p : group1)cout << p.getName() << endl;
    cout << "Group 2:" << endl; for (const Person& p : group2)cout << p.getName() << endl;
    cout << "Group 3:" << endl; for (const Person& p : group3)cout << p.getName() << endl;
}
// function definitions