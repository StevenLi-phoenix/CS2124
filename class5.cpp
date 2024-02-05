#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// class overloading 2
class Rectangle{
    int width, height;
};

void operatorpriority();
void non_member_function_overloading();
void operator_overloading();
void member_function_overloading();
void overloading_a_operater_function_as_an_member();
void overloading_function_examples();
 
int main(){
    overloading_function_examples();
    return 0;
}

void operatorpriority(){
    // see this link for more details
    // https://en.cppreference.com/w/cpp/language/operator_precedence

    // ASRL: order of precedence
    // A: Associativity
    // S: Shift 
    // R: Relational
    // L: Logic

    int x;
    x = 5 + 7 % 2;
    cout << x << endl; // 6

    x = (5+7) % 2;
    cout << x << endl; // 0
}

void non_member_function_overloading(){
    // non-member function overloading
    // complier choose the correct overload based on the decalred types
    // same exact name but having different parameters
    // like a() and a(int x) and a(int x, int y)
    // - this is resolved in complie time

    // if ambiguous, complier will throw an error
    class Student{
        string name = "Not know";
        int age = 18;

    public:
        void printStudent(){
            cout << name << " " << age << endl;
        }
        void addAge(int i){
            age += i;
        }
        void addAge(){
            age += 1;
        }
    };

    Student s;
    s.printStudent();
    s.addAge();
    s.printStudent();
    s.addAge(5);
    s.printStudent();

}

void operator_overloading(){
    // operator overloading
    // operator overloading is a way to define the way an operator works for user defined types
    // like int operator+(int a, int b){return a*b;} // LOL :D

    // operator overloading - chaining
    // return type the same as the left operand support chaining
    // cout << a << b << c;
    // ostream& operator<<(ostream& os, sth.){
    // ^^^^^^^^            ^^^^^^^^^^^
    // return type          left operand
    // it's the same as the left operand, so we can chain it
}

void member_function_overloading(){
    class Student {
        string name = "Not know";
        int age = 18;
        public:
        Student():name("default"){};
        Student(const string& iname):name(iname){};
        Student(int iage):name("default"), age(iage){};
        Student(const string& iname, int iage):name(iname), age(iage){};
    };
}

void overloading_a_operater_function_as_an_member(){
    // void operator=(consr SomeType& rhs){...
    // like when tried to overload << operator
    // cout << a << b << c;
    // you can overload << operator as a member function
    // or as a non-member function (free function)
    // This is not recommended to overload << operator as a member function,
    // because this will overload cout(ostream) object, which is a std lib
    // so, it's better to overload << operator as a non-member function (free function)

    // change the meaning of the function 
    // cannot change the return type

    // The following operator is expected to not be overload
    // ?: . :: sizeof
}

void overloading_function_examples(){
    // #include <iostream>
    // #include <string>
    // #include <vector>
    // #include <fstream>
    // using namespace std;

    // class Date{
    // public:
    //     Date(int day, int month, int year):day(day), month(month), year(year){
    //         this->day = day;
    //         this->month = month;
    //         this->year = year;
    //     };

    //     // ostream& operator<<(ostream& os){
    //     //     os << day << "/" << month << "/" << year;
    //     //     return os;
    //     // }
    //     friend ostream& operator<<(ostream& os, const Date& date);
    // private:
    //     int day, month, year;
    // };

    // class Person{
    //     public:
    //     Person(const string& name, int day, int month, int year): name(name), date_of_brith(day, month, year){};
    //     // ostream& operator<<(ostream& os){
    //     //     os << name << " " << date_of_brith;
    //     //     return os;
    //     // } //becase it's evaluated left to right, so it's not possible to overload << operator as a member function
    //     //   // it have to be modify the std lib to operate on the left operand
    //     friend ostream& operator<<(ostream& os, const Person& person);
    //     private:
    //     string name;
    //     Date date_of_brith;
    // };

    // ostream& operator<<(ostream& os, const Date& date){
    //     os << date.day << "/" << date.month << "/" << date.year;
    //     return os;
    // }

    // ostream& operator<<(ostream& os, const Person& person){
    //     os << person.name << " " << person.date_of_brith;
    //     return os;
    // }

    // int main(){
    //     Person person = Person("Ahmed", 1, 1, 2020);
    //     cout << person << endl;
    //     return 0;
    // }
}

void nested_class(){
    // #include <iostream>
    // #include <string>
    // #include <vector>
    // #include <fstream>
    // using namespace std;

    // class Person{
    // public:
    //     class Date{
    //     public:
    //         Date(int day, int month, int year):day(day), month(month), year(year){
    //             this->day = day;
    //             this->month = month;
    //             this->year = year;
    //         };
    //         friend ostream& operator<<(ostream& os, const Date& date);
    //     private:
    //         int day, month, year;
    //     };

    //     Person(const string& name, int day, int month, int year): name(name), date_of_brith(day, month, year){};
    //     friend ostream& operator<<(ostream& os, const Person& person);
    // private:
    //     string name;
    //     Date date_of_brith;
    // };

    // ostream& operator<<(ostream& os, const Person::Date& date){
    //     os << date.day << "/" << date.month << "/" << date.year;
    //     return os;
    // }

    // ostream& operator<<(ostream& os, const Person& person){
    //     os << person.name << " " << person.date_of_brith;
    //     return os;
    // }

    // int main(){
    //     Person person = Person("Ahmed", 1, 1, 2020);
    //     cout << person << endl;
    //     return 0;
    // }
}