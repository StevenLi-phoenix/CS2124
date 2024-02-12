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
    string getName() const {return name;}
private:
    string name;
};

// function prototypes
// main function
int main(){
    vector<Person> group;
    group.emplace_back("Tom");
    group.emplace_back("Sue");
    group.emplace_back("Bob");

    for (const auto& p : group){
        cout << p.getName() << endl;
    }
    

}
// function definitions