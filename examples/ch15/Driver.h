#ifndef DRIVERH
#define DRIVERH 

template<class LapackMatrix, class EltT>
LapackUnfactored< RectLURep<EltT> >
xForAxEqb(LapackMatrix& matrixA, ConcreteFortranArray2d<EltT>& b) {
    return matrixA.factor().solve(b);
}

#endif
