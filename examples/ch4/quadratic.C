/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream.h>
#include <math.h>


class QuadraticPolynomial {
public:
    QuadraticPolynomial(double a, double b, double c);

    class RealRoots {
    public:
        RealRoots(double x1, double x2);
        double minRoot();
        double maxRoot();
    private:
        double min_root;
        double max_root;
    };

    class ComplexRoots {
        // ...
    };


    RealRoots    realRoots();             // Solve for real roots
    ComplexRoots complexRoots();          // Solve for complex roots
    double       evaluateAt(double x);    // Evaluate at x


    class NoRealRoots {
        // Exception: real roots requested but both roots are complex.
        // ...
    };
private:
    // Polynomial coefficients
    double a;
    double b;
    double c;
};

int main() {
   int a = 1, b = 2, c = -3;

   do {
   c *= -1;

   // ... Set a, b, c ...
   try {
    QuadraticPolynomial eqn(a, b, c);
    QuadraticPolynomial::RealRoots roots = eqn.realRoots();
    cout << "Real roots are: " << roots.minRoot() << ", " << roots.maxRoot() << endl;
    // ... computation using the real roots ...
}
   catch (QuadraticPolynomial::NoRealRoots) {
    cout << "No real roots." << endl;
}

   } while (c == 3);
   return 0;
}


QuadraticPolynomial::RealRoots QuadraticPolynomial::realRoots() {
    // Solve for real roots.
    // Formula from Section 5.6, Numerical Recipes in C, 2nd ed.,
    // by Press, Teukolsky, Vetterling, and Flannery,
    // Cambridge University Press, 1992.
    double sgn_b = (b >= 0.0 ? 1.0 : -1.0);
    double disc = b*b - 4*a*c;
    if (disc < 0.0) throw NoRealRoots();
    double q = -.5 * ( b + sgn_b * sqrt(disc) );
    return RealRoots( q/a, c/q ); 
}



QuadraticPolynomial::RealRoots::RealRoots(double x1, double x2) {
    if (x1 < x2) {
        min_root = x1;
        max_root = x2;
    }
    else {
        min_root = x2;
        max_root = x1;
    }
}
double QuadraticPolynomial::RealRoots::minRoot() { return min_root; }
double QuadraticPolynomial::RealRoots::maxRoot() { return max_root; }


QuadraticPolynomial::QuadraticPolynomial(double acoeff, double bcoeff, double ccoeff) :
  a(acoeff), b(bcoeff), c(ccoeff) {}

