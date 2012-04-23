#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_b(double *b, int *n);
void print_matrix(double *m, int *n);

void add(double *m, int *n, int c, double *b)
{
  int i=0;
//if the diagonal element of a given row is zero, add to
//that row the elements of the row below it.
       if(m[*n *c+c] == 0)
       {  
          if(fabs(m[*n *(c+1)+c]) != 0)
          {
 	    for(i=0; i<*n;i++)
	    {
	      m[*n *c+i]+=m[*n *(c+1)+i];
            }
	      b[c]+=b[c+1];
          }
       }
return;
}
