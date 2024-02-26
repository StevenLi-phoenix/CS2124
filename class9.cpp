/*
Identity_id: 99c6f6bd-d9ea-4b78-8dd5-f2f643884772
Author: Steven Li
Time: 2024/02/21
TIME: 1708552698
Briefly: deallocate from heap
Purpose: class 9 classnote
Usage: ./r class9.cpp
Licence: CC BY-NC-SA 4.0
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// global variables

// class definitions
class Thing{
    friend ostream& operator<<(ostream& os, const Thing& t){
        os << "I am a thing";
        return os;
    }
    public:
        Thing(){
            cout << "Thing constructor" << endl;
        }
        ~Thing(){
            cout << "Thing destructor" << endl;
            delete xp;
        }
        Thing& operator=(const Thing& t){
        if(this != &t){
            delete xp;
            xp = new int(*t.xp);
        }
        return *this;
        }
    private:
        int* xp;
};
// function prototypes

// main function
int main() {
    return 0;
}

// function definitions

