/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/
            SUBROUTINE SIMPLE


      PARAMETER (H=6.6256E-34) ! Planck's constant (mks units)




      INTEGER I
      REAL X
      DATA I/3/, X/10.0/




      I = 5
      X = 12.1



      END




      SUBROUTINE S(A, B)
      REAL A, B
      A = B
*     ...
      END



      SUBROUTINE SCALL



      CALL S(X, 4.2)


            END

            SUBROUTINE ARRAY

       DIMENSION X(100)

       END



      SUBROUTINE F(X, N)
      DIMENSION X(N)
*     ...
      END


