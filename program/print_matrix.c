#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_matrix(double *m, int *n)
{
  double buffer;
  int i=0, k=0;
  FILE *matrix;
/*Prints the matrix by cycling through the columns (k) and the rows (c) and printing one element at a time
 * where *n is the dimenion of the matrix.*/
  matrix = fopen("gauss_mat.out","w");

  for(i=0; i<*n; i++)
  {
    for(k=0; k<*n; k++)
    {
      buffer = m[*n *i+k];
      fprintf(matrix,"%f\t",buffer);
    }
    fprintf(matrix,"\n");
  }

  fclose (matrix);

return;
}
