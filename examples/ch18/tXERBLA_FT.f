
      external snrm2

      real x(10), norm, snrm2
      integer i

      do i=1,10
         x(i) = i-1 
      enddo
      
      norm = snrm2( 10, x, 1)

      write(*,*) ' norm = ', norm

c      return
      end
