/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#ifndef ListH
#define ListH

#include <iostream.h>
#include <float.h>
#include "SciEng/Boolean.h"


template<class T>
class List {
public:
    List() : first(0), last(0) {}

    ~List() {
        while (first != 0) {
            Node* p = first->link;
            delete first;
            first = p;
        }
    }

    void add(T x) {
        if (first == 0) first = last = new Node(x);
        else last = last->link = new Node(x);
    }

    void remove(T x);
    // ...

    friend class ListIterator<T>;
private:
    class Node {
    public:
        Node(T x) : link(0), datum(x) {}
        Node* link;
        T     datum;
    };

    Node* first;
    Node* last;
    List(const List<T>&);  // Prohibit, since not implemented 
    List<T>& operator=(const List<T>&);  // Prohibit, since not implemented 
};



template<class T>
class ListIterator {
public:
    ListIterator(const List<T>& list) : cur(list.first) {}

    Boolean more()    const { return cur != 0;   }
    T       current() const { return cur->datum; }
    void    advance()       { cur = cur->link;   }

private:
    List<T>::Node* cur;
};


template<class T>
inline void List<T>::remove(T x) {
  Node* prev = 0;
  Node* cur = first;
  while (cur != 0) {
    if (cur->datum == x) {
      if (prev == 0) {
        first = cur->link;
        delete cur;
        cur = first;
      } else {
        prev->link = cur->link;
        delete cur;
        cur = prev->link;
      }
    } else {
      prev = cur;
      cur = cur->link;
    }
  }
}
#endif
