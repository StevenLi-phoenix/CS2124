#include <iostream>
#include <string>
#include <fstream>

using namespace std;



struct Student {
    int StudentID;
    string name;
    short yearInSchool;
    double gpa;

    // double gpa = 4.0; // in C++ 17 you can provide default values for struct fields
    // It seems like the default assign statement is make the assignment of the new object messed up

    
};


void instantiate_struct_object(){
    // Student jack;
    // Student John; // Allocate memory here
    
    // alter way
    // struct Student {
    // int StudentID;
    // string name;
    // short yearInSchool;
    // double gpa = 4.0; // in C++ 11 you can provide default values for struct fields
    // } john, jack; // not common but you can

    // use dot to access the instant obj
    // cout << "Student ID: " << jack.StudentID << endl;
    // cout << "Student name: " << jack.name << endl;
    // cout << "Student year in school: " << jack.yearInSchool << endl;
    // cout << "Student GPA: " << jack.gpa << endl;

    //inital object individually

    Student jack1 = {1234, "John", 3, 3.5}; // somehow failed to compile due to the constructor do not have constructor
    //class3.cpp:36:13: error: no matching constructor for initialization of 'Student'
    //class3.cpp:8:8: note: candidate constructor (the implicit copy constructor) not viable: requires 1 argument, but 4 were provided

    cout << "Student ID: " << jack1.StudentID << endl;
    cout << "Student name: " << jack1.name << endl;
    cout << "Student year in school: " << jack1.yearInSchool << endl;
    cout << "Student GPA: " << jack1.gpa << endl;
}

struct motercycle {
    string brand;
    string model;
    string color;
    int cc;
};

void printInformationOfMyBike(const motercycle& myBike){
    // why reference? 1. efficiency 2. const correctness
    // const correctness with efficiency -> const reference
    // const correctness without efficiency -> just copy the value (motercycle myBike)
    cout << "Brand: " << myBike.brand << " " << "Model: " << myBike.model << " " << "Color: " << myBike.color << " " << "CC: " << myBike.cc << endl;
}

void instantiate_motercycle(){
    motercycle honda;
    printInformationOfMyBike(honda);
    // local variable that are primitive type are not initialized
    // local variable that are class type(not primitive) are initialized

    honda.brand = "Honda";
    honda.model = "CBR";
    honda.color = "Red";
    honda.cc = 250;
    printInformationOfMyBike(honda);

    // create another motercycle
    motercycle my_bike{"Suzuki", "CBR", "Blue", 0};
    printInformationOfMyBike(my_bike);

    // copy constructor
    printInformationOfMyBike(honda);
    honda = my_bike;
    printInformationOfMyBike(honda);

    // cerate and init bike3 from bike2
    motercycle bike3(my_bike);
    printInformationOfMyBike(bike3);
    cout << endl;
}

void modify_vector_of_motorcycle(motercycle& bike){
    bike.cc = 1000;
}

void sep(const int counts = 20){
    for (int i = 0; i < counts; ++i){
        cout << "=";
    }
    cout << endl;
}

void fstream_motercycle(){
    vector<motercycle> bikes;
    motercycle temp;
    string brand, model, color;
    int cc;
    ifstream fin("motercycle_lst.txt");
    if (!fin){cout << "File not found" << endl;exit(1);}

    // while (fin >> brand >> model >> color >> cc){
    //     // init field by field
    //     // motercycle temp;
    //     // temp.brand = brand, temp.model = model, temp.color = color, temp.cc = cc;
    //     // bikes.push_back(temp);

    //     //init by constructor
    //     motercycle temp{brand, model, color, cc};
    //     bikes.push_back(temp);

    //     // motercycle temp{brand, model, color, cc};
    //     // modify_vector_of_motorcycle(temp);
    // }
    while (fin >> temp.brand >> temp.model >> temp.color >> temp.cc){
        bikes.push_back(temp);
    }
    fin.close();
    
    for (motercycle bike: bikes){
        printInformationOfMyBike(bike);
    }
    sep();
    for (size_t i = 0; i < bikes.size(); ++i){
        cout << "Bike " << i << endl;
        printInformationOfMyBike(bikes[i]);
    }

    cout << endl;
}

void crorupted_fstream_motocycle(){
    vector<motercycle> bikes;
    string brand, model, color;
    int cc;
    ifstream fin("motercycle_lst_cop.txt");
    if (!fin){cout << "File not found" << endl;exit(1);}

    while (fin >> brand >> model >> color >> cc){ 
        // if the file is crop, that means fstream will return False, and the loop will exit
        bikes.push_back(motercycle{brand, model, color, cc});
    }

    for (motercycle bike: bikes){
        printInformationOfMyBike(bike);
    }
}

struct wordsInLine{
    string word;
    vector<string> words;
};

void textin2dvector(){
    vector<wordsInLine> lines;
    string line, word;
    ifstream fin("jabberwocky");


}

int main(){
    instantiate_struct_object();
    instantiate_motercycle();
    fstream_motercycle();
    crorupted_fstream_motocycle();
    textin2dvector();
}