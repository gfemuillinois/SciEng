/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
// compile test only

int hasVal(int val, int n, int values[]) {
    // Return true if the n-element array "values" contains an element
    // with value "val"; otherwise, return false.
    for (int i = 0; i < n; i++) {
        if (values[i] = val) return 1;
    }
    return 0;
}

