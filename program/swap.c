#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_matrix(double *m, int *n);

int swap(double *m, int *n, int c, double *b)
{
  int l,f,sign=0,swaprow;
  double change1,change2;
  change1=change2=f=0;
  swaprow=*n*c;
/*cycles through the matrix where l and c are the row counters, l is the column counter,
 * and n is the dimension of the matrix*/
  for(l=c; l<*n; l++)
  {
//Search all elements in the same column as the diagonal of the current row.
//Find the row with the largest leading term and switch that row with the
//current row.
     if(fabs(m[swaprow+c]) < fabs(m[*n *l+c]))
     {
      swaprow=*n*l;
     }
  }

  if(swaprow != *n*c)
  {
    sign++;
/*swaps two rows of the matrix*/
    for(f=0;f<*n;f++)	
    {
      change1 = m[*n *c+f];
      change2 = m[swaprow+f];
      m[*n *c+f] = change2;
      m[swaprow+f] = change1;
    }
//keeps track of the row swaps to change the sign of the determinant as necessary.
/*swaps two elements of the vector b in the equation Mx=b*/
    change1 = b[swaprow/l];
    change2 = b[c];
    b[c] = change1;
    b[swaprow/l] = change2;
  }
return(sign);
}
