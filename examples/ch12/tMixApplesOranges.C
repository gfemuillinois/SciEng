/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include "SciEng/EquivalentCategory.h"

class Apple : 
    public EquivalentCategory<Apple> {
public:
    Apple(int n) : a(n) {}

  virtual ~Apple() {}

    virtual Boolean equivalentTo(const Apple& an_apple) const { return a == an_apple.a; }
private:
    int a; 
};

class Orange : 
    public EquivalentCategory<Orange> {
public:
    Orange(int n) : o(n) {}

  virtual ~Orange() {}

    virtual Boolean equivalentTo(const Orange& an_orange) const { return o == an_orange.o; }
private:
    int o; 
};

int main(){   
    Apple an_apple(1);
    Orange an_orange(1);
    if (an_apple == an_apple && an_orange == an_orange) return 0;
    return 1; 
}

