/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/


       double precision function fronrm(array, m, n)
       integer m, n
       double precision array(m, n), scale, sumsq, absx

C      The sum of the squares is scale**2 * sumsq:
       sumsq = 0.0
       scale = 1.0


       do 100 j = 1, n

          do 200 i = 1, m
             absx = abs(array(i, j))

             if (absx .gt. scale) then
                 sumsq = (scale / absx)**2 * sumsq + 1
                 scale = absx
             else
                 sumsq = sumsq + (absx / scale)**2
             end if

200       continue

100    continue
       fronrm = scale * sqrt(sumsq)
       end





       program tfrob
       double precision m(2,3)
       data m/1,2,3,4,5,6/
       print *, fronrm(m, 2, 3)
       end

