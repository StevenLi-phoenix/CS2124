#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// global variables

// class definitions
class Person{
    public:
        string name;
        int age;
        Person(string name, int age){
            this->name = name;
            this->age = age;
        }
        Person(string name, int age = -1){
            this->name = name;
            this->age = age;
        }
        Person(int age, string name = "Unknown"){
            this->name = name;
            this->age = age;
        }
        Person(){
            this->name = "Unknown";
            this->age = -1;
        }
};

// function prototypes


// main function
int main(){
    vector<Person> people;
    people.push_back(Person("Mike", 40));
    people.push_back(Person(30));
    people.push_back(Person("Vicky"));
    people.push_back(Person());

    for (const Person& p: people){
        cout << p.name << " " << p.age << endl;
    }
    return 0;
}

// function definitions
int getNum(int num1, int num2){
    return num1 + num2;
}