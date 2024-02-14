/*
Identity_id: 4d3f1c84-e972-43ee-8436-00d984caf724
Author: Steven Li
Time: 2024/02/14
TIME: 1707947252
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
class Thing{
    friend ostream& operator<<(ostream& os, const Thing& t){
        os << "Thing:" << *t.x << " @ " << t.x;
        return os;
    }
    public:
        Thing(int x = 0): x(new int(x)){} // new keyword is used to allocate memory on the heap
        ~Thing(){
            cout << "Thing destroyed" << endl;
            delete x;
        }
    private:
        int* x;
};
// function prototypes
void printThing(){
    Thing t(5);
    cout << t << endl;
}
// main function
int main() {
    printThing();
    return 0;
}

// function definitions

