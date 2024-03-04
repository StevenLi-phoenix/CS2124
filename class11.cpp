/*
Identity_id: bbc475ca-bb1f-449e-8ac1-1bbd6f60d2bf
Author: Steven Li
Time: 2024/03/04
TIME: 1709584361
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
class Vector{
    friend ostream& operator<<(ostream& os, const Vector& v){
        os << "Vector(" << v.size() << ")\n";
        for(size_t i = 0; i < v.size(); i++){
            os << v.elem[i] << " ";
        }
        return os;
    };

    public:
        Vector() : elem(nullptr), sz(0), cap(0) {}
        Vector(size_t s) : elem(new int[s]), sz(s), cap(s) {
            for(size_t i = 0; i < s; i++){
                elem[i] = 0;
            }
        }
        Vector& operator=(const Vector& a){
            int* p = new int[a.cap];
            for(size_t i = 0; i < a.sz; i++){
                p[i] = a.elem[i];
            }
            delete[] elem;
            elem = p;
            cap = a.cap;
            sz = a.sz;
            return *this;
        };
        int& operator[](size_t i) { return elem[i]; }
        size_t size() const { return sz; }

        void push_back(int d){
            if (sz == cap){
                if (cap == 0){
                    elem = new int[1];
                    elem[0] = d;
                    sz++;
                    cap++;
                    return;
                }
                int* p = new int[cap*2];
                for(size_t i = 0; i < sz; i++){
                    p[i] = elem[i];
                }
                delete[] elem;
                elem = p;
                cap *= 2;
            }
            elem[sz] = d;
            sz++;
        }
        int pop_back(){
            if (sz == 0){
                return 0;
            }
            return elem[--sz];
        }
    private:
        int* elem;
        size_t sz, cap;
};
// function prototypes

// main function
int main() {
    Vector v1(0);
    cout << v1 << endl;
    v1 = 3;
    cout << v1 << endl;
    v1.push_back(5);
    cout << v1 << endl;

    Vector v2;
    v2 = v1;
    cout << v2 << endl;
    v2.push_back(10);
    cout << v2 << endl;

    cout << v1.pop_back() << endl;
    cout << v1 << endl;
    cout << v2.pop_back() << endl;
    cout << v2 << endl;

    return 0;
}

// function definitions

