// Linkage names between C, C++, and Fortran (platform dependent)

#ifndef _CLARCH_H_
#define _CLARCH_H_

// not found at toucan, tsunami
// #include <generic.h>

#ifdef __GNUC__

// Copied this from generic.h at SGI
#ifndef name2
#define name2(a,b) gEnErIc2(a,b)
#define gEnErIc2(a,b) a ## b
#endif

#define FTNAME(x) name2(x,_)   

 // SGIs using gcc, g++ and f77
 // Linux using gcc, g++ and g77
 // SGI Altix using Intel compilers. Intel compilers also define __GNUC__

#else

 // ibm r6k using  xlC and xcf compilers

#define FTNAME(x) x

#endif


#endif // _CLARCH_H_

