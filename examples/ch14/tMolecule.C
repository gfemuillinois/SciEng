/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include "SciEng/String.h"
#include "SciEng/CloneableObjPtr.h"
#include "Array/ConcreteFormedArray1d.h"

#include "tMolecule.h"


void duplicate(  ConcreteFormedArray1d<Atom*>& lhs,
		 const ConcreteFormedArray1d<Atom*>& rhs) { 


  ConcreteFormedArray1d<Atom*>::IteratorType lhs_i(lhs);
  ConcreteFormedArray1d<Atom*>::BrowserType rhs_i(rhs);
  for(; lhs_i.more(); lhs_i.advance(), rhs_i.advance()) { 
    lhs_i.current() = rhs_i.current()->clone();
  }
}

class Molecule {
public:
    Molecule(Subscript num_atoms) : atoms(num_atoms) {}
    Subscript numAtoms() const { return atoms.numElts(); }

    const CloneableObjPtr<Atom>& operator()(Subscript i) const { return atoms(i); }
          CloneableObjPtr<Atom>& operator()(Subscript i)       { return atoms(i); }

    void readAtoms();

private:
    ConcreteFormedArray1d< CloneableObjPtr<Atom> > atoms;
};


class BadMoleculeInput :
  public SciEngErr {
public:
  virtual String message() const { return "Bad Molecule Input"; }
};


class Hydrogen :
  public virtual Atom { 
public:

    virtual String       name()         const { return "Hydrogen"; }
    virtual unsigned int atomicNumber() const { return 1; }
  //    virtual Hydrogen*    clone()        const { return new Hydrogen(*this); }
    virtual Atom*    clone()        const { return new Hydrogen(*this); }

};


class Oxygen :
  public virtual Atom {
public:
   virtual String name() const { return "Oxygen"; }
   virtual unsigned int atomicNumber() const { return 16; }
  //   virtual Oxygen* clone() const { return new Oxygen(*this); }
   virtual Atom* clone() const { return new Oxygen(*this); }
};


void Molecule::readAtoms() { 
    Molecule& m = *this;
    for(Subscript i = 0; i < m.numAtoms(); i++) { 
        cout << "Enter H for hydrogen, O for oxygen:";
        String c;
        if (cin >> c) { 

	  //            if      (c == "Hydrogen") m(i) = new Hydrogen;
	  //           else if (c =="Oxygen")    m(i) = new Oxygen;

            if      (c == "H") m(i) = new Hydrogen;
            else if (c =="O")    m(i) = new Oxygen;


        }
        else throw BadMoleculeInput();
    }
}


ostream& operator<<(ostream& os, const Molecule& m) {
  os << '[';
  for (Subscript i = 0; i < m.numAtoms()-1; i++) os << m(i)->name() << ", ";
  return os << m(m.numAtoms()-1)->name() << ']';
}


int main() {
  {
    Molecule water(3);
    water(0) = new Hydrogen;
    water(1) = new Hydrogen;
    water(2) = new Oxygen;

    Molecule rain(water);
    cout << rain << endl;
  }
  {
    Molecule water(3);
    water.readAtoms();

    Molecule rain(water);
    cout << rain << endl;
  }
  return 0;
}

