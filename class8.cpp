#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// global variables

// class definitions

// function prototypes
int getNum(int num1, int num2 = 0);

// main function
int main(){
    cout << getNum(5) << endl;
    cout << getNum(5, 6) << endl;
    return 0;
}

// function definitions
int getNum(int num1, int num2){
    return num1 + num2;
}