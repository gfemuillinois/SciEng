/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
template<class T> class Vector;



extern float  sdot(const Vector<float>&, const Vector<float>&);   // Float accumulation
extern double ddot(const Vector<float>&, const Vector<float>&);   // Double accumulation


#ifdef BAD_COMPILE

template<class AccumType>  // WRONG: template argument not used in formal arguments
extern AccumType dot(const Vector<float>&, const Vector<float>&);

#endif
