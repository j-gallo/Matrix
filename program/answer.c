#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void answer(double *m, double *b, int *n)
{
  int c=0, k=0;
  double *x,temp;
  FILE *Pfile;

  x = malloc(*n *sizeof(double));
/*c is the counter for the rows and k the counter for the columns.
 * this loop cycles through each row, starting from the bottom,
 * solves for the corresponding x, and then uses the calculated
 * values for the elements of x to find the elements of x in the
 * rows above.*/
  for(c=*n-1; c>=0; c--)
  {
    temp = 0;		
    for(k=*n-1; k>c; k--)
    {
/* temp stores the sum all of the known values of x times the coefficients
 * from the current row of the matrix*/
      temp += m[*n *c+k]*x[k];
    }
      x[c]= (b[c]-temp)/(m[*n *c+c]);
  }

  Pfile = fopen("gauss_answer.out","w");
 
  for(c=0; c<*n; c++)
  {
    fprintf(Pfile,"%f\n",x[c]);
  }

  free (x);
  fclose (Pfile);

return;
}
