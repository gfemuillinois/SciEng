/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "examples/ch6/List.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    // Read list of values and find minimum.
    List<float> list;
    float val;
    float minval = FLT_MAX;  // Max float value, from float.h
    while ( cin >> val) {
        if (val < minval) minval = val;
        list.add(val);
    }

    // Normalize values and write out.
    for (ListIterator<float> i(list); i.more(); i.advance()) {
        cout << i.current() - minval << endl;
    }

    {// Test removal                                                
    for (ListIterator<float> i(list); i.more(); i.advance()) {        
        list.remove(i.current());                                  
    }                                                              
    }                                                                
    return 0;
}

