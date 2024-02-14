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
        Person(string name = "unnamed", int age = -1): name(name), age(age){}

};

// function prototypes


// main function
int main(){
    vector<Person> people;
    people.push_back(Person("Mike", 40));
    people.push_back(Person("Vicky"));

    for (const Person& p: people){
        cout << p.name << " " << p.age << endl;
    }
    return 0;
}

// function definitions
int getNum(int num1, int num2){
    return num1 + num2;
}