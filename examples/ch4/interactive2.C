/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <string.h>

extern void command_a();
extern void command_b();
extern void command_c();


int main() {
    char command[100];
    while (cin >> command) {
        try {

            if      (strcmp(command, "a") == 0) command_a();
            else if (strcmp(command, "b") == 0) command_b();
            else if (strcmp(command, "c") == 0) command_c();
            // ...
            else    cout << "Unknown command: " << command << endl;

        }
        catch (char* message) {
            cout << message << endl;
        }
    }
    return 0;
}


void command_a() {
    cout << "Doing a" << endl; 
    float x; 
    cin >> x;
    if (x < 0) {
        throw "Nonnegative input expected in command a";
    }
    // ... process the command with valid input ...
}

void command_b() { cout << "Doing b" << endl; }
void command_c() { cout << "Doing c" << endl; }
