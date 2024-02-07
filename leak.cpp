#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int* p = &a;
    for (int i = 0; i < 64; i++) {
        p++;
        cout << *p << endl;
    }
}