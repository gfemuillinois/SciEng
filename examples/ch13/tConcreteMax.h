
#ifndef TCONCRETEMAXH
#define TCONCRETEMAXH


template<class ArrayType>
typename ArrayType::EltT maxArray2dElement(const ArrayType& a) {
    typename ArrayType::EltT the_max = a(0, 0);
    for (Subscript i = 0; i < a.shape(0); i++) {
        for (Subscript j = 0; j < a.shape(1); j++) {
            the_max = sce::max( the_max, a(i, j) );
        }
    }
    return the_max;
}

/*
This version will call the copy constructor for ArrayType::ProjectionT
which is protected!

template<class ArrayType>
typename ArrayType::ProjectionT maxArray3dPlane(ArrayType& a) {
    // Returns plane of a that contains the maximum value
    Subscript plane_with_max = 0;
    typename ArrayType::EltT max_value = a(0, 0, 0);
    for (Subscript plane = 0; plane < a.shape(0); plane++) {
        typename ArrayType::EltT max_value_in_plane = maxArray2dElement(a[plane]);
        if (max_value_in_plane > max_value) {
            plane_with_max = plane;
            max_value = max_value_in_plane;
        }
    }
    return a[plane_with_max];
}
*/

template<class ArrayType>
Subscript maxArray3dPlane(ArrayType& a) {
    // Returns plane of a that contains the maximum value
    Subscript plane_with_max = 0;
    typename ArrayType::EltT max_value = a(0, 0, 0);
    for (Subscript plane = 0; plane < a.shape(0); plane++) {
        typename ArrayType::EltT max_value_in_plane = maxArray2dElement(a[plane]);
        if (max_value_in_plane > max_value) {
            plane_with_max = plane;
            max_value = max_value_in_plane;
        }
    }
    return plane_with_max;
}

#endif
