/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

class B : 
    public TraceLifetime {
public:
    B(int a) : b(a), TraceLifetime("B") {}
    B(const B& aB) : b(aB.b), TraceLifetime("B-from-B") {}
    int val() const { return b; }
private:
    int b;
};

class A {
public:
    A(B* p):pb(p) {}
    A& operator=(B* rhs) { pb = rhs; return *this; }
    int val() const { return pb->val(); }
private:
    CopiedObjPtr<B> pb;
};

int main() {
    B* b1 = new B(1);
    A a1(b1);
    A a2(a1);
    cout << a1.val() << " " << a2.val() << endl;
    a1 = new B(2);
    cout << a1.val() << endl;
    a2 = a1;
    cout << a2.val() << endl;
    a2 = a2;
    cout << a2.val() << endl;
    return 0;
}

