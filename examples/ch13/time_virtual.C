//
//  Measuring the time spent on virtual function calls
//

#include <iostream>
#include <assert.h>

#include "timer.h"
#include "pou.h"

static const int n_int_pt = 50000;
static const int nshape = 1000;

Timer  the_timer(10);	// 10 clocks

static void calc_stiff_using_virtual_fn(const POU& pou);

typedef void (*pt_shape)(double phi[], const int nphi);

static void calc_stiff_using_ptr_to_function(pt_shape shape);

static void calc_stiff();

static void user_shape(double phi[], const int nphi);

main() {

    MLSPOU mls_pou;

    the_timer.set(0);
    the_timer.start(0);

    // This one uses virtual function  (one level of derivation)

    calc_stiff_using_virtual_fn(mls_pou);

    the_timer.stop(0);
    cout << "\n Time spent at calc_stiff_using_virtual_fn"
	    " (MLSPOU) (s) = "
	 << the_timer.read(0) << endl;

    MLSPOUellipse mls_pou_ellipse;

    the_timer.set(3);
    the_timer.start(3);

    // This one uses virtual function (2 levels of derivation)

    calc_stiff_using_virtual_fn(mls_pou_ellipse);

    the_timer.stop(3);
    cout << "\n Time spent at calc_stiff_using_virtual_fn"
	    " (MLSPOUellipse) (s) = "
	 << the_timer.read(3) << endl;

    MLSPOUcircle mls_pou_circle;

    the_timer.set(4);
    the_timer.start(4);

    // This one uses virtual function (3 levels of derivation)

    calc_stiff_using_virtual_fn(mls_pou_circle);

    the_timer.stop(4);
    cout << "\n Time spent at calc_stiff_using_virtual_fn"
	    " (MLSPOUcircle) (s) = "
	 << the_timer.read(4) << endl;


    the_timer.set(1);
    the_timer.start(1);

    // This one uses pointer to function

    calc_stiff_using_ptr_to_function(user_shape);

    the_timer.stop(1);
    cout << "\n Time spent at calc_stiff_using_ptr_to_function (s) = "
	 << the_timer.read(1) << endl;


    the_timer.set(2);
    the_timer.start(2);

    // This one has the call to shape hardwired

    calc_stiff();

    the_timer.stop(2);
    cout << "\n Time spent at calc_stiff (s) = "
	 << the_timer.read(2) << endl;


     
    return 0;
}
// ***************************************************
// ***************************************************

void calc_stiff_using_virtual_fn(const POU& pou){

    double* phi = new double[nshape];
    assert(phi);

    for(int ipt=0; ipt<n_int_pt; ipt++){
	pou.Shape(phi,nshape);
    }

    cout << "\n calc_stiff_using_virtual_fn, phi[0] = " 
	 << phi[0] << endl;

    if(phi) delete [] phi;

    return;
}
// ***************************************************
// ***************************************************

void calc_stiff_using_ptr_to_function(pt_shape shape){

    double* phi = new double[nshape];
    assert(phi);

    for(int ipt=0; ipt<n_int_pt; ipt++){
	shape(phi,nshape);
    }

    cout << "\n calc_stiff_using_ptr_to_function, phi[0] = " 
	 << phi[0] << endl;

    if(phi) delete [] phi;

    return;
}
// ***************************************************
// ***************************************************

void calc_stiff(){

    double* phi = new double[nshape];
    assert(phi);

    for(int ipt=0; ipt<n_int_pt; ipt++){
	user_shape(phi,nshape);
    }

    cout << "\n calc_stiff, phi[0] = " 
	 << phi[0] << endl;

    if(phi) delete [] phi;

    return;
}
// ***************************************************
// ***************************************************

void user_shape(double phi[], const int nphi){

    double *phi0 = phi;
    double *phi1 = &phi[nphi];
    while(phi0 < phi1){
	*phi0++ = 9.0;
    }
}
// ***************************************************
// ***************************************************
