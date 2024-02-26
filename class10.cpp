/*
Identity_id: 75ef2cd7-67b2-479c-8aca-988b25527998
Author: Steven Li
Time: 2024/02/26
TIME: 1708979709
Briefly: Class 10 class note
Purpose: note
Usage: ./r class10.cpp
Licence: CC BY-NC-SA 4.0
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// global variables

// class definitions
class Vector{
    friend ostream& operator<<(ostream& os, const Vector& v){
        os << "capacity: " << v.capacity << " size: " << v.sizeValue << " data: ";
        for (size_t ii = 0; ii < v.sizeValue; ii++) {
            os << v.data[ii] << " ";
        }
        return os;
    };
    public:
        Vector() : capacity(0), sizeValue(0), data(nullptr) {}
        Vector(size_t s, int val = 0) : capacity(s), sizeValue(s) {
            data = new int[s];
            for (size_t ii = 0; ii < s; ii++) {
                data[ii] = val;
            }
        }
        ~Vector() { delete[] data; }
        size_t size() const { return sizeValue; }
        bool push_back(int val) {
            if (sizeValue == capacity) {
                if (!resize(2 * capacity)) return false; // possible OOM
            }
            data[sizeValue] = val;
            sizeValue++;
            return true;
        }
        void clear() {
            sizeValue = 0;
        }
        int pop_back() {
            if (sizeValue == 0) return -1;
            sizeValue--;
            return data[sizeValue];
        }
        int operator[](size_t index) {
            // return *(data+index);
            if (index >= sizeValue) return -1;
            if (index > 0) return data[index];
            if (index > -sizeValue) return data[sizeValue + index];
            if (index < -sizeValue) return -1;
        }
    private:
        bool resize(size_t newsize) {
            if (newsize > capacity) {
                int* temp = new int[newsize];
                for (size_t ii = 0; ii < sizeValue; ii++) {
                    temp[ii] = data[ii];
                }
                delete[] data;
                data = temp;
                capacity = newsize;
                return true;
            } else {
                return false;
            }
        }
        size_t capacity;
        size_t sizeValue;
        int* data;


};
// function prototypes

// main function
int main() {
    Vector v;
    Vector v1(10);
    Vector v2(10, 5);
    cout << v << endl;
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v2.size() << endl;
    cout << v2.push_back(10) << endl;
    cout << v2.push_back(20) << endl;
    cout << v2[0] << endl;
    cout << v2[11] << endl;
    cout << v2 << endl;
    return 0;
}

// function definitions

