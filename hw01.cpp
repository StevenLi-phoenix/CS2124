/*
Identity_id: 78f5a96f-6cc4-4106-89c6-12b102e34ac3
Author: Steven Li
Time: 2024/02/01
TIME: 1706841142
Briefly: This program is to decode the encrypted.txt file.
Purpose: This program is part of HW01.cpp for NYU Tandon 2024 spring CS2124
Usage: Put the encrypted.txt file in the same directory as this program, and run it.
Licence: CC BY-NC-SA 4.0
*/

/*
hw01: Caesar Cypher
---------------------------------------------------------------------------------------------------------
Focus:
---------------------------------------------------------------------------------------------------------
vectors
strings
functions
Standard I/O
Clean code!
---------------------------------------------------------------------------------------------------------
Task:
---------------------------------------------------------------------------------------------------------
We are given a file of text that has been encrypted. For simplicity, we will assume the name is "encrypted.txt".  
    That will save you having to ask the user.

-[x] Do not ask the user for the file name.

Luckily we know what algorithm was used, the classic Caesar cypher. 
    Each UPPERcase alphabetic character has been modified by “rotating” it through the alphabet some number of steps.
    For example, if the number of steps was 3 and the original letter was 'B' 
    then the encrypted file would instead have a 'E' in the same place, since 'E' is three letters past 'B' in the alphabet. 
    On the other hand, if the rotation distance was -3 and the letter was 'E' in the encrypted file, then the unencrypted character would be 'B'.
    Clearly we have to address the problem of what to do when the letter to be encrypted is too close to the end of the alphabet. 
    For example, what should we do if we had to encrypt the letter 'Y', again with the number of steps specified as three. 
    The first step takes us to 'Z'. What about the second step? We wrap around, 
    back to 'A'. The third and final step then is easy, it will take us on to 'B'.
    Of course, we are decrypting, so the task for our program is to realize that if we see a 'B', then it was originally a 'Y'.

Your program will read an encrypted file. You are to decrypt it.
    The first item in the file will be an int, the number of steps that was used in the rotation. Yes, it could be negative.
    The following lines will contain the text that you are to decode. Only UPPERcase alphabetic characters have been encrypted. 
    The rest, e.g. lowercase, digits and punctuation all appear in the encrypted file the same way they did in the original.

Oh, one other thing. To make the encoded file just a little more difficult, they thought it would be clever to reverse the lines in the file. 
    So what should be the first line shows up last, etc.

You will be reading the lines from the file into a vector of strings, in the order that you read them. 
    Of course the number of items in your vector, i.e. its size, will be the same as the number of text lines in the input file.

Do not reorder the lines in the vector!
    When you are displaying the decoded lines, you will just loop through the vector backwards. (An example of doing this will have been covered in class.)
    An example. Suppose this is the contents of the file you were asked to decrypt:

5
FSI YMJ RTRJWFYMJX TZYLWFGJ.
FQQ RNRXD BJWJ YMJ GTWTLWTAJX
INI LDWJ FSI LDRGQJ NS YMJ BFGJ.
YBFX GWNQQNL FSI YMJ XQNYMJD YTAJX

That says that the original file was encoded with a Caesar cypher using a rotation of five. 
    Remember that the lines have also been reversed meaning that the first line of text we see is the encoded version of 
    what was the last line of code in the original file, etc. When we decrypt it, we should get:

TWAS BRILLIG AND THE SLITHEY TOVES
DID GYRE AND GYMBLE IN THE WABE.
ALL MIMSY WERE THE BOROGROVES
AND THE MOMERATHES OUTGRABE.

---------------------------------------------------------------------------------------------------------
Further Constraints
---------------------------------------------------------------------------------------------------------
Only use what we have covered
Specifically, do not use additional library features that we have not covered. Most such "abuses" will come from students 
    who cannot think how to solve the problem with what they have learned, so they do a "search" for a solution. 
    At this point, we are trying to get you to exercise your basic programming skills, not your web search skills.
    This includes not calling a library function to test if a character is uppercase. 
    Why? If you can't write a test that determines if a character is uppercase then you haven't learned enough about the basics of programming, 
    in C++ or other languages.
    Everything you need should be available in the online lecture notes. If you think what you need is not there, then talk to us.
---------------------------------------------------------------------------------------------------------
Functions
---------------------------------------------------------------------------------------------------------
A good program will have the task nicely broken up into functions. Certainly the solution to this assignment could be written with all of the code in main and
    take up barely 20 lines. But our goal throughout the semester is to make a practice of good programming style and that means, among other things, 
    of making good use of functions.

For this assignment we will actually tell you a couple of functions to provide. Usually we would leave it up to you to come up with them. 
    After all, programming is supposed to be fun and it is less fun when someone is telling you what to do every step of the way.
    First, write a function that takes an encrypted character and the rotation distance, and returns the corresponding decrypted character. 
    Note that only UPPERcase characters will result in a change. For all other characters, 
    this function will return the input value. (Note that the function's return type will need to be char.)

Second, write a function that takes a string and the rotation distance. It will modify the string that is passed in, using the above function, 
    changing the character in the string into its unencrypted form. Note that unlike in some languages strings in C++ are mutable, 
    meaning that we can directly change their contents. 
    This function is passed the string to be modified along with the rotation distance and changes the string in place. 
    It does not return anything, i.e. it has a void return type.
    Neither of the above functions prints anything. That will be the task of main, 
    or another function if you see some merit in further breaking up the program.

If you have not covered functions and parameter passing in your lecture(s) so far when this assignment is posted, 
    you can still take a first pass at solving the problem, putting everything in main, and then when functions are covered, 
    add it to your solution.  Once you know how, the changes shouldn't take long to add to a correctly working program. 
    You can read up on functions and parameter passing in the lecture notes.
---------------------------------------------------------------------------------------------------------
Submit
---------------------------------------------------------------------------------------------------------
- [x] Submit a single source file, hw01.cpp.

Things that might help

In C++ and related languages, a character has the type char. 
    A character literal is represented by the character between single quotes , 
    e.g. 'm', as opposed to a string literal which is the string surrounded by double quotes,                                                               // note: interesting, in python, the single quote and double quote are the same
    e.g. "this is a string literal".

We can compare characters with the usual operators <, >, ==, etc. 
    Worthy of note is that all of the lowercase characters are in order, 
    so that 'a' is less than 'b', etc., and similarly the UPPERcase characters are also in order.

Characters are actually represented as a kind of integer, so we can also do arithmetic with them. 
    We can add an integer to a character and get another character. 
    For example, the expression 'm' + 3 has the same value as the character 'p'.
    Unlike Python, there is no need to "convert" a character to its ascii value.  

The spec says to read the input from a file. 
    If you haven't covered files yet, you can still get started by reading the input from standard input, 
    i.e. from cin. 
    Note that the lecture notes on how to open / close a file and read from it can be found at 
    [http://cis.poly.edu/jsterling/cs2124/LectureNotes/01.Intro.html#fileio.](http://cis.poly.edu/jsterling/cs2124/LectureNotes/01.Intro.html#fileio.)

Note that the file starts with an integer (possibly negative). 
    Naturally you will read that into a variable of type int. 
    Remember that C++'s I/O system makes it easy to read each item just as you would want. 
    (Unlike with a language like Python, where you had to first read things as strings and then had to convert them. Happily we don't have to do that.)

For the message, you were told to process each line as a whole, 
    so you will want to read the rest of the file line by line. 
    The function getline is ideal for that.  
    You can find it discussed in the lecture notes for file I/O, mentioned above.

One thing that may trip you up a little is that when you have read the integer at the beginning of the file 
    (which represents the rotation distance), 
    your "read pointer" will be sitting immediately after the number and just before the newline character at the end of the line.                          // note: what? I did not notice that. And did not encounter this problem
    Before you can move on to read the next line, you need to gobble up that newline character.                                                             // todo: monitor this and try to catch this hint
    One way to get rid of it is just to call getline an "extra" time, right after you read the integer and before you read the rest of the lines.           // FIXED
---------------------------------------------------------------------------------------------------------
Good Code
---------------------------------------------------------------------------------------------------------
Reminder that this is really about writing good code. That means, your program needs:
- [x] Good comments.
    - [x] Every program file should have a comment at the top to identify the file, the author and, briefly, the purpose of the code in the file.
    - [x] Every function definition should have a comment identifying its purpose, the purpose of its parameters and that of its return value. Unlike Python docstrings, this comment comes just before the function.
    - [x] Any block of code, e.g. loop, should have a comment to explain enough of what it does so that the reader could skip reading the code in that block altogether without missing anything.
    - [x] Good functions. Well, we addressed that above in the requirements. Normally, thinking of good functions is a key part of your task. You are welcome to add any functions you think would be helpful here!

- [x] Function prototypes 
    - [x] Function prototypes come before main.
    - [x] Function definitions should come after main. 
If you haven't covered function prototypes, don't worry, it will only take you a few minutes to add them to your program.

- [x] Good naming. Both variables and functions should have good names.
    - [x] A function's name should say clearly what it does.
    - [x] A variable's name should say clearly what it holds. No, not its type but what its purpose is in the application.
Calling a vector of strings something like "stringVec" would be silly at best. If the vector is holding the lines from a file, perhaps it might be called "lines".
    In general, single letter names are unacceptable.
    Yes, we do often use the letters i and j as loop index variables, at least if the loop is reasonably short and their scope is limited by the loop itself. Even then, a more meaningful name helps clarify at a glance the intent of the code. 
    An index variable called row might work better in some cases.
    Similarly, variables with names like temp don't help the reader and should (almost) never be used.

- [x] Good format.
    It should be easy to see the structure of your program even if it was held far enough away that you could not read the code itself. 
    Unlike Python, C++ does not require indentation. But good indentation makes code easier to read.  
    And writing code that is easy to read is one of the most important principles of good programming
    - [x] Line length. Long lines have two problems. 
        First, unless you are reading the code on a device with a wide enough window, there is going to be annoying line wrap (aargh!). 
        And secondly, it just makes it harder to see the logic that must be embedded in there. 
        A good rule of thumb is to assume your program will eventually get printed and due to whatever limitations, 
        anything over 80 characters in a line will result in line wrap.
    - [x] Function length. Years ago, the recommended length limit was about 24 lines. 
        That was how much we could fit on our terminal screens! :-). It is still a common recommendation to keep functions short for readability, 
        but we will be a little more tolerant and allow functions to be as long as 40 lines.
    - [x] Whitespace. 
        It usually makes code more readable if you put whitespace around your operators. 
        Especially when there is a lot going on on the line. 
        A simple example would be that cin >> word, is definitely more readable than cin>>word
        Some people will insist that where you place the opening curly brace for a block is extremely important. { Wars have been waged over such! } 
        I have my preferences, but I won't force you to share them. Just be consistent.
    - [x] Global variables. 
        Don't. No program that you will write for this course will need global variables. Do not use them.
    - [x] Global constants, 
        on the other hand are highly recommended. (Remember that GLOBAL_CONSTANTS are written with all caps.)
        
Please, refer back to these guidelines throughout the semester. If you violate any of them, you may be penalized. And we much rather give out perfect scores! (Honest)                              // Note: I am checking it item by item.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const string FILENAME = "encrypted.txt";

// Global Constants
const int LOWERLIMIT = 65; // 0x0041;
const int UPPERLIMIT = 90; // 0x005A;
const int ROTATERANGE = 26; // 0x0041 -> 0x005A

// Function Prototype
char decode_char(const char& c, const int& shift);
void decode_line(string& line, const int& shift);
// Fact: the reference symbol '&' could be 'int& var' or 'int &var.'

// Main
int main(){
    int shift;
    vector<string> content;
    string line;
    
    // read file
    ifstream infs(FILENAME);
    if (!infs){cout << "Read File: " << FILENAME << " failed." << endl;}

    // get int and assert in range
    infs >> shift;
    if (shift > ROTATERANGE || shift < -ROTATERANGE){
        cout << "Invalid shift number: " << shift << endl;
        return 1;
    }

    // read empty line
    getline(infs, line);
    // read the file line by line, and decode it, then push it into the vector
    while (getline(infs, line)){
        decode_line(line, shift);
        content.push_back(line);
    }
    infs.close();

    // print the decoded content
    for (size_t i = content.size(); i > 0; --i){
        if (content[i-1].size() == 0) {continue;}
        for (const char& c: content[i-1]){
            cout << c;
        }
        cout << endl;
    }
    return 0;
}

// Defination of Functions
/*
decode_char:
    Decode the char with the shift number
    note: only char between LOWERLIMIT and UPPERLIMIT will be decoded
    char c: the char to be decoded
    int shift: the shift number, range from -ROTATERANGE to ROTATERANGE
*/
char decode_char(const char& ch, const int& shift){
    if (ch > UPPERLIMIT || ch < LOWERLIMIT){
       return ch;
    }else if (ch - shift > UPPERLIMIT){
        return ch - shift - ROTATERANGE;
    } else if ( ch - shift < LOWERLIMIT ){
        return ch - shift + ROTATERANGE;
    } else {
        return ch - shift; // since 0x0020 is space, so we don't need to worry about it
    }
}

/*
decode_line:
    Decode the line with the shift number
    note: only char between LOWERLIMIT and UPPERLIMIT will be decoded
    string line: the line to be decoded
    int shift: the shift number, range from -ROTATERANGE to ROTATERANGE
    note: ROTATERANGE, 0, -ROTATERANGE will not change the line
*/
void decode_line(string& line, const int& shift){
    for(char& ch: line){
        ch = decode_char(ch, shift);
    }
}
