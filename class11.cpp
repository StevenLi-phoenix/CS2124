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
        for(int i = 0; i < v.size(); i++){
            os << v.elem[i] << " ";
        }
        return os;
    };

    public:
        Vector(int s) : elem(new double[s]), sz(s) {}
        Vector& operator=(const Vector& a){
            double* p = new double[a.sz];
            for(int i = 0; i < a.sz; i++){
                p[i] = a.elem[i];
            }
            delete[] elem;
            elem = p;
            sz = a.sz;
            return *this;
        };
        // Vector& operator=(int i){
        //     for(int j = 0; j < sz; j++){
        //         elem[j] = i;
        //     }
        //     return *this;
        // };
        double& operator[](int i) { return elem[i]; }
        int size() const { return sz; }
    private:
        double* elem;
        int sz;
};
// function prototypes

// main function
int main() {
    Vector v1(5);
    v1 = 3;
    cout << v1 << endl;
    return 0;
}

// function definitions

