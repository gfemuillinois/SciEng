/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

//namespace SciEngLib{

template<class T>
CloneableObjPtr<T>::CloneableObjPtr(const CloneableObjPtr<T>& aCP) : 
    the_p(aCP.isNull() ?  0 : aCP.the_p->clone()) {
}



template<class T>
CloneableObjPtr<T>& CloneableObjPtr<T>::operator=(T* just_newed) {

    delete the_p;         // Discard lhs object.
    the_p = just_newed;   // Point to rhs object.
    return *this;

}



template<class T>
CloneableObjPtr<T>& CloneableObjPtr<T>::operator=(const CloneableObjPtr<T>& rhs) {
    if (the_p != rhs.the_p) {
        delete the_p;
        the_p = rhs.isNull() ? 0 : rhs.the_p->clone();
    }
    return *this;
}



template<class T>
T* CloneableObjPtr<T>::releaseControl() {
    T* save_p = the_p;
    the_p = 0;
    return save_p;
}

//}
