#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double determinant(double *m,int n)
{

  int i=0;
  double det=1;
/*Calculates the determinant of the upper triangular matrix by multiplying the diagonals together
 * where n is the dimension of the matrix.*/
  for(i=n-1; i>=0; i--)
  {
    det = m[n *i+i]*det;
  }

return(det);
}
