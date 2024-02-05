#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Person{
public:
    class Date{
    public:
        Date(int day, int month, int year):day(day), month(month), year(year){
            this->day = day;
            this->month = month;
            this->year = year;
        };
        friend ostream& operator<<(ostream& os, const Date& date){
            os << date.day << "/" << date.month << "/" << date.year;
            return os;
        };
    private:
        int day, month, year;
    };

    Person(const string& name, int day, int month, int year): name(name), date_of_brith(day, month, year){};
    friend ostream& operator<<(ostream& os, const Person& person) {
        os << person.name << " " << person.date_of_brith;
        return os;
    }
private:
    string name;
    Date date_of_brith;
};

// ostream& operator<<(ostream& os, const Person::Date& date){
//     os << date.day << "/" << date.month << "/" << date.year;
//     return os;
// }

// ostream& operator<<(ostream& os, const Person& person){
//     os << person.name << " " << person.date_of_brith;
//     return os;
// }

int main(){
    Person person = Person("Ahmed", 1, 1, 2020);
    cout << person << endl;
    return 0;
}
