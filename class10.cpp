/*
Identity_id: 75ef2cd7-67b2-479c-8aca-988b25527998
Author: Steven Li
Time: 2024/02/28
TIME: 1709152755
Briefly: Class 10 class note & Class 11 class note
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
    /**
     * Overloaded insertion operator for Vector class.
     * Prints the capacity, size, and data elements of the Vector object to the output stream.
     *
     * @param os The output stream to write to.
     * @param v The Vector object to be printed.
     * @return The output stream after printing the Vector object.
     */
    friend ostream& operator<<(ostream& os, const Vector& v){
        os << "capacity: " << v.capacity << " size: " << v.sizeValue << " data: ";
        for (size_t ii = 0; ii < v.sizeValue; ii++) {
            os << v.data[ii] << " ";
        }
        return os;
    };
    public:
        /**
         * Default constructor for the Vector class.
         * Initializes the capacity, size, and data pointer.
         */
        Vector() : capacity(0), sizeValue(0), data(nullptr) {}
        /**
         * @brief Constructs a Vector object with a specified size and initial value.
         * 
         * @param s The size of the Vector.
         * @param val The initial value for each element in the Vector. Default value is 0.
         */
        Vector(size_t s, int val = 0) : capacity(s), sizeValue(s) {
            data = new int[s];
            for (size_t ii = 0; ii < s; ii++) {
                data[ii] = val;
            }
        }
        /**
         * @brief Destructor for the Vector class.
         * 
         * This destructor is responsible for deallocating the memory
         * occupied by the dynamic array 'data'.
         */
        ~Vector() { delete[] data; }
        /**
         * Returns the size of the object.
         *
         * @return The size of the object.
         */
        size_t size() const { return sizeValue; }
        /**
         * Adds an element to the end of the container.
         *
         * @param val The value to be added.
         * @return True if the value was successfully added, false otherwise.
         */
        bool push_back(int val) {
            if (sizeValue == capacity) {
                if (capacity == 0) {
                    resize(1);
                    data = new int[1];
                }  else {
                    resize(2 * capacity);
                }
            }
            data[sizeValue] = val;
            sizeValue++;
            return true;
        }
        /**
         * Clears the contents of the object.
         */
        void clear() {
            sizeValue = 0;
        }
        /**
         * Removes and returns the last element of the container.
         *
         * @return The value of the last element that was removed.
         */
        int pop_back() {
            if (sizeValue == 0) {
                cerr << "pop_back: empty vector" << endl;
                return -1;
            };
            sizeValue--;
            if (sizeValue < capacity / 4) {
                if (!resize(capacity / 2)) {
                    cerr << "pop_back: cannot resize" << endl;
                    return -1;
                }
            }
            return data[sizeValue];
        }
        /**
         * @brief Overloaded subscript operator.
         * 
         * This function allows accessing elements of the object using the subscript operator [].
         * 
         * @param index The index of the element to access.
         * @return int& A reference to the element at the specified index.
         */
        int operator[](size_t index) {
            // return *(data+index);
            if (index >= sizeValue) return -1;
            if (index >= 0) return data[index];
            if (index > -sizeValue) return data[sizeValue + index];
            return -1;
        }
    private:
        /**
         * Resizes the array to the specified new size.
         * If the new size is greater than the current capacity, the array is reallocated with the new size.
         * If the new size is smaller than the current capacity, the array is reallocated only if the new size is greater than the current size.
         * If the new size is smaller than the current size, the array cannot be shrunk and the function returns false.
         * 
         * @param newsize The new size of the array.
         * @return true if the array was successfully resized, false otherwise.
         */
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
            } else if (newsize < capacity) {
                if (newsize > sizeValue) {
                    int* temp = new int[newsize];
                    for (size_t ii = 0; ii < newsize; ii++) {
                        temp[ii] = data[ii];
                    }
                    delete[] data;
                    data = temp;
                    capacity = newsize;
                    return true;
                } else {
                    return false; // cannot shrink to a smaller size
                }
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
    cout << v.size() << endl;
    cout << v.push_back(10) << endl;
    cout << v.push_back(20) << endl;
    cout << v[0] << endl;
    // cout << v[-1] << endl;
    cout << v << endl;
    return 0;
}

// function definitions

