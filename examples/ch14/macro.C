/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

#define copyNew(class_instantiation) copyWrap( newed( new class_instantiation ) )
#define shareNew(class_instantiation) shareWrap (newed( new class_instantiation ) )

class Acme130 {
public:
  Acme130(int, int);
};

static int gpib_main = 0;
extern int newed(Acme130*);
extern void copyWrap(int);

void f() {

copyWrap( newed( new Acme130(gpib_main, 12) ) )

;

copyNew( Acme130(gpib_main, 12) )

;
}
