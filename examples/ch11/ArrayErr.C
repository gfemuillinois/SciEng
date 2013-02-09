/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
#include <iostream>
#include "SciEng/ArrayErr.h"
#include "SciEng/Boolean.h"
#include "SciEng/SciEngString.h"


String ArrayErr::Shape::message() const {
    return "Array shapes not commensurate.";
}

String ArrayErr::Dimensionality::message() const {
    return "Array has wrong dimensionality.";
}

String ArrayErr::CreationSize::message() const {
    return "Creation size specified inconsistent with rigid array's shape.";
}

String ArrayErr::NegativeSize::message() const {
    return "Negative creation size specified.";
}

String ArrayErr::Symmetry::message() const {
    return "Asymmetric size specified for symmetric array.";
}

String ArrayErr::SubscriptRange::message() const {
    return "Subscript out of range.";
}

