#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_b(double *b, int *n)
{
  int i=0;
  FILE *Pfile;

  Pfile = fopen("gauss_solution.out","w");
/*Prints the vector b in the equation Mx=b. n here is the dimension of the matrix*/
  for(i=0; i<*n; i++)
  {
    fprintf(Pfile,"%f\t",b[i]);
  }

  fclose(Pfile);

return;
}
