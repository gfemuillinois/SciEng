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
CountedBuiltInPtr<T>& CountedBuiltInPtr<T>::operator=(const CountedBuiltInPtr<T>& rhs) {
    if (the_p != rhs.the_p) {
        if (unique()) delete the_p;
        the_p = rhs.the_p;
        refCount = rhs.refCount;
    }
    return *this;
}

template<class T>
CountedBuiltInPtr<T>& CountedBuiltInPtr<T>::operator=(T* just_newed) { 
    if (unique()) delete the_p;
    the_p = just_newed;
    refCount = ReferenceCount();
    return *this;
}


template<class T>
CountedBuiltInPtr<T>::~CountedBuiltInPtr() { 
    if (refCount.unique()) delete the_p;
}

template<class T>
Boolean CountedBuiltInPtr<T>::unique() const { 
    return refCount.unique();
}

//}
