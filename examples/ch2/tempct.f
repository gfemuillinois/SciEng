/*
Example programs from the book Scientific and Engineering Programming
in C++: An Introduction with Advanced Techniques and Examples,
Addison-Wesley, 1994.
 
                 (c) COPYRIGHT INTERNATIONAL BUSINESS MACHINES
                 CORPORATION 1994.  ALL RIGHTS RESERVED.

See README file for further details.
*/

          SUBROUTINE TCTRL



      IF (TEMP .GT. MAXSAF) THEN 
          PRINT *, 'EMERGENCY: Too hot--flushing'
          CALL FLUSH
      END IF



          END

