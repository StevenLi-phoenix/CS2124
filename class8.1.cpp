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

class Group{
    friend ostream& operator<<(ostream& os, const Group& g){
        os << g.name << ": " << endl;
        for (const Person& p: g.people){
            os << "\t" << p << endl;
        }
        return os;
    }
    public:
        Group(string name = "unnamed"): name(name){}
        void addPerson(string name, int age){
            people.push_back(Person(name, age));
        }
    private:
        string name;
        vector<Person> people;
};
// function prototypes


// main function
int main(){
    vector<Group> groups;
    Group group1("Group1");
    group1.addPerson("Mike", 40);
    group1.addPerson("Vicky", 30);
    groups.push_back(group1);
    for (const Group& g: groups){
        cout << g << endl;
    }

    int x = 1;
    cout << &x << endl;
    int y = copy(x);
    cout << &y << endl;

    return 0;
}

// function definitions
int getNum(int num1, int num2){
    return num1 + num2;
}

template <typename T>
T copy(T a){
    T b = a;
    return b;
}
