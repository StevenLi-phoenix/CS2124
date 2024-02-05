#include <iostream>
#include <string>
#include <ostream>

using namespace std;

/*
Object Oriented Programming
- Class
    attributes
    methods
    * user defined data type
    * abstraction over objects - collection of attributes and methods

- Object
    instance of a class

Difference between class and struct
- class: var private by default (like java)
- struct: var public by default (like python)

- Encapsulation
    - data encapsulation
    - data hiding
*/

class Rectangle{
public:
    void setname(const string& iname){name = iname;}
    void setwidth(int iwidth){width = iwidth;}
    void setheight(int iheight){height = iheight;}

    const string& getname() const {return name;}
    int getwidth() const {return width;}
    int getheight() const {return height;}

    // not recommended, because it initializes the object with default values and then assigns the values
    // Rectangle(const string& iname, int iwidth, int iheight){name=iname; width=iwidth; height=iheight;}

    // using initializer list
    Rectangle(const string& iname, int iwidth, int iheight): name(iname), width(iwidth), height(iheight){}
    Rectangle(): name("default"), width(0), height(0){}


    void printRectangle() const {  // inline 
        cout << name << " " << width << " " << height << endl; // {name},{width},{height} available in local scope
    }
    const string& getName() const; 
    // the first const means that the return value of this method is a const string
    // this const means that this method will not modify any of the attributes of the class

    friend ostream& operator<<(ostream& os, const Rectangle& r);

private:
    string name;
    int width;
    int height;
    string description = "password";
};

// define method outside the class
// note: require prototype
const string& Rectangle::getName() const{
    return description;
}

// output operator
ostream& operator<<(ostream& os, const Rectangle& r){
    // os << r.getname() << " " << r.getwidth() << " " << r.getheight();
    os << r.name << " " << r.getwidth() << " " << r.getheight();
    return os;
}

void test(){
    Rectangle r1("r1", 10, 20);
    r1.printRectangle();
    cout << r1.getName() << endl;
    cout << r1 << endl;
}


int main(){
    test();
}
