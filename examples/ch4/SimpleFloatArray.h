/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

class SimpleFloatArray {
public:

    SimpleFloatArray(int n);                                // Create array of n elements
    SimpleFloatArray();                                     // Create array of 0 elements
    SimpleFloatArray(const SimpleFloatArray&);              // Copy array
    ~SimpleFloatArray();                                    // Destroy array
    float& operator[](int i);                               // Subscripting
    int numElts();                                          // Number of elements
    SimpleFloatArray& operator=(const SimpleFloatArray&);   // Array assignment
    SimpleFloatArray& operator=(float);                     // Scalar assignment 
    void setSize(int n);                                    // Change size
private:
    int num_elts;                                           // Number of elements
    float* ptr_to_data;                                     // Pointer to built-in array of elements

    void copy(const SimpleFloatArray& a);                   // Copy in elements of a

};

