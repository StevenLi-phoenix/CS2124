#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// global variables

// class definitions
class Person{
    friend ostream& operator<<(ostream& os, const Person& p){
            os << p.name << " " << p.age;
            return os;
    }
    public:
        Person(string name = "unnamed", int age = -1): name(name), age(age){}
    private:
        string name;
        int age;
};
// function prototypes


// main function
int main(){
    vector<Person*> group1;
    vector<Person*> group2;

    ifstream file("people.txt");
    string name;
    int age;
    while (file >> name >> age){
        group1.push_back(new Person(name, age));
    }
    

    int x = 1;
    cout << &x << endl;

    return 0;
}

// function definitions
int getNum(int num1, int num2){
    return num1 + num2;
}
