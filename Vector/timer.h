/*
 *
  Class to implement a timer for the different portions of the simulation.
  The timer is running on multiple processors if necessary.
  
 */

#if !defined(MY_TIMER_H)
#define MY_TIMER_H
/*
              Copyright (c) 1994 by Jurgen K. Singer, Houston
                         jsinger@na-net.ornl.gov
 
           -------------------------------------------------------
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
 
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
 
      ---------------------------------------------------------------
 

*/
#include <iostream>
#include <stdio.h>
//#include "COMM/comm_serv.h"

#if defined(__ksr__)
#include <ksr/ksr_timers.h>

typedef double seconds;

#define getres(r) ((r) = (8.0/20e06))
#define gettime(t) ((t) = user_seconds())
#define align(n) (((n)+15)&(-16))

#else

#include <time.h>
#include <sys/times.h>
#include <sys/resource.h>
//extern "C" int getrusage (int Who, struct rusage *RUsage);

typedef double seconds;
#define getres(r) ((r) = CLOCKS_PER_SEC) 
#define gettime(t) {  \
	struct rusage buffer;\
	getrusage( RUSAGE_SELF, &buffer );\
	(t) = buffer.ru_utime.tv_sec + buffer.ru_stime.tv_sec +\
	    1.e-6*(buffer.ru_utime.tv_usec + buffer.ru_stime.tv_usec) ;\
		   }
#define align(n) (n)

#endif

#define TOTAL_TIMER 0
#define P2M_TIMER 1
#define M2M_TIMER 2
#define M2L_TIMER 3
#define L2L_TIMER 4
#define FARFIELD_TIMER 5
#define DIRECT_TIMER 6
#define INIT_TIMER 7
#define NUMBER_OF_TIMERS 8

class Timer
{
  private:
    static int num_timers;
   static double *t; 
    static seconds *dt;

#if defined(__ksr__)
#define Seconds(s) s
#define diff(s1,s2) s1-s2

#else

#define Seconds(s) s
    // static const double Seconds(const seconds s) 
    // { 
    //   return s/((double) CLOCKS_PER_SEC);
    // } 
    
    static double diff(const seconds s1, const seconds s2) 
    {
      return Seconds(s1-s2);
    } 
#endif

  public:
    //
    // Construction & Demolition crews
    //
    ~Timer(void) { delete [] t ; delete [] dt ; }
    Timer(void) { }
    Timer(int n) 
    { 
        num_timers = n; 
        t  = new double[num_timers];
        dt = new seconds[num_timers]; 
 	if ( !t ) 
	std::cerr << " No ticks created. num_timers = " << n << std::endl ;
 	if ( !dt )
	std::cerr << " No timers created. num_timers = " << n << std::endl ;
    }

    //
    // Information 
    //
    static void   set  (int n = 0) 	// initialize tick
         { t[n] = 0.0;     }
    static const double& read (int n = 0) // return tick
         { return t[n];    }     
    static double get(int n = 0)
				   {
				     seconds s;
				     gettime(s);
				     return diff(s,dt[n]); 
				   }

    static void start(int n = 0)   // read value for timer
         { gettime(dt[n]);  }
    static void stop(int n = 0)   // incremet tick using previous value
				  // read in the timer
         { t[n] += get(n); }

    static void banner() ;

    static void print(int n = 0);
};

extern Timer the_timer;	// global object to be used by everybody

#endif
