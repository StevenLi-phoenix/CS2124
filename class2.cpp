#include <iostream>
#include <vector>
#include <string>
#include <fstream> 
#include <typeinfo>
using namespace std;

void vector_sub() {
    vector<int> v;
    cout << "Size: " << v.size() << endl;

    v.push_back(10);
    v.push_back(20);

    cout << "Size: " << v.size() << endl;

    for(int i = 0; i < v.size(); i++){
        cout << "value of " << i << "is" << v[i] << endl;
    }
    cout << endl;

    v.clear();
    cout << "Size: " << v.size() << endl;
}

void vector_method_2(){
    vector<int> v1(5, 10);
    vector<int> v2 = {1,1,2,3,5,8,13,21,34,55}; // CPP 11 feature???
    for (int value: v1){
        cout << value << " ";
    }
    cout << endl;
    for (int value: v2){
        cout << value << " ";
    }
    cout << endl;
}

void complex_var_assignment(){
    int num, val = 12; // val is being assigned 12, num is not. And also not zero
    num = 12;
    cout << "num: " << num << endl;
    cout << "val: " << val << endl;

    cout << "num++" << num++ << endl;
    cout << "++val" << ++val << endl;

    cout << "num: " << num << endl;
    cout << "val: " << val << endl;
}


void char_data_type(){
    char c1 = 'a';
    cout << "c1: " << c1 << endl;

    char c2 = 78;
    cout << "c2: " << c2 << endl;

    int n = 90 + 256 * 10;
    c2 = n; // verified
    cout << "c2: " << c2 << endl;
}

void string_m(){
    string s = "Hello";
    cout << "s: " << s << endl;

    s.push_back('!');
    cout << "s: " << s << endl;

    s.pop_back();
    cout << "s: " << s << endl;

    s.append(" World"); //?
    cout << "s: " << s << endl;

    s.clear();
    cout << "s: " << s << endl;
}

void string_with_char_example(){
    string s = "Hello";
    cout << "s: " << s << endl;

    for (char s: s){
        cout << s << " ";
    }
    cout << endl;

    string s1 = "Hello";
    string s2 = "World";
    string s3 = s1 + " " + s2 + "!";
    cout << "s3: " << s3 << endl;
}

void string_with_int_ops()
{
    string s = "Bat";
    s[0]++;
    cout << "s: " << s << endl;
}

void read_file_operation(){
    ifstream file_operator("jabberwocky");
    if (!file_operator){
        cerr << "Error opening file" << endl;
        exit(1);
    }

    string something;
    // file_operator >> something; // Accept input from file (read one word of content)
    // getline(file_operator, something); // Accept input from file (read one line of content)
    while (file_operator >> something){
        cout << something << endl;
    }
    file_operator.close();

    // int x = 20;
    // while(--x){
    //     cout << x << endl;
    //     }
    // In a while loop zero is false and non-zero is true
    // So in here the file_operator >> something will return file_operator when it is not the end of file,
    // so the while loop will stop when it reaches the end of file
}

void read_file_operation_2(){
    ifstream file_operation("jabberwocky");
    if (!file_operation){
        cerr << "Error opening file" << endl;
        exit(1);
    }

    string line;
    vector<string> lines;
    while (getline(file_operation, line)){
        lines.push_back(line);
    }
    file_operation.close();

    // print the content of the vector
    for (string line: lines){
        cout << line << endl;
    }

    // print the content of the vector in reverse order
    for (size_t i = lines.size() - 1; i > 0; --i){
        for (size_t j = lines[i-1].size(); 0 < j; --j){
            cout << lines[i-1][j-1] << "";
        }
        cout << endl;
    }
}

void vector_2d(){
    const int ROWS = 10; // Const ALL CAP and CAN NOT be changed
    const int COLS = 10;
    vector<vector<int>> mat;

    for (int r=0; r < ROWS; ++r){
        mat.push_back(vector<int>(COLS));
        for (int c=0; c < COLS; ++c){
            mat[r][c] = r * COLS + c;
        }
    }

    for (int r=0; r < ROWS; ++r){
        for (int c=0; c < COLS; ++c){
            cout << mat[r][c] << " ";
        }
        cout << endl;
    }
}

void create_reference_variable(){
    int x = 10;
    int y = x; // y is a reference variable of x
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    y++;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
}

void modufy_vector_by_reference(){
    vector<int> v = {1,2,3,4,5};
    for (int value: v){
        cout << value << " ";
    }
    cout << endl;

    for (int value: v){
        value *= 2; // This will not change the value in the vector
    }

    for (int value: v){
        cout << value << " ";
    }
    cout << endl;

    for (int &value: v){
        value ++; // This will change the value in the vector
    }

    for (int value: v){
        cout << value << " ";
    }
    cout << endl;
}


void one_last_thing(){
    // use reference to pass into function
    // reference to the memory location not the variable it self
    // reading
    
}

 
int main(){
    complex_var_assignment();
}
