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
CopiedBuiltInPtr<T>::CopiedBuiltInPtr(const CopiedBuiltInPtr<T>& aCP) : 
    the_p(aCP.isNull() ?  0 : new T(*aCP.the_p)) {
}



template<class T>
CopiedBuiltInPtr<T>& CopiedBuiltInPtr<T>::operator=(T* just_newed) {

    delete the_p;          // Discard lhs object.
    the_p = just_newed;    // Point to just_newed object.
    return *this;

}



template<class T>
CopiedBuiltInPtr<T>& CopiedBuiltInPtr<T>::operator=(const CopiedBuiltInPtr<T>& rhs) {
    if (the_p != rhs.the_p) {
        delete the_p;
        the_p = rhs.isNull() ? 0 : new T(*rhs.the_p);
    }
    return *this;
}



template<class T>
T* CopiedBuiltInPtr<T>::releaseControl() {
    T* save_p = the_p;
    the_p = 0;
    return save_p;
}

//}
