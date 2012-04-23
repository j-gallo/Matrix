#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void add(double *m, int *n, int c, double *b);
double determinant(double *m,int n);
void print_matrix(double *m, int *n);
void print_b(double *b, int *n);

void no_pivot(double *m, double *b, int *n)
{

  int i,k,c;
  double factor,det;
  c=i=k=factor=det=1;

  for(c=0; c<*n-1; c++)	//cycle for columns
  {
    for(k=*n-1; k>c; k--)//cycle for rows
    { 
/* If the diagonal element of the current row is zero, run the add function.
 * Then divide it by the element just below it in the same column and use the negative 
 * of that fraction as a scaling factor. then add the current row times the scaling 
 * factor to the row just beneath*/
       if((m[*n *c+c] == 0)) (add(m,n,c,b));

       if((m[*n *c+c] == 0))
       {
         printf("The determinant of this matrix is zero!\n\n");
         exit(EXIT_FAILURE);
       }

       factor = (m[*n *k+c])/(m[*n *c+c]);
       for(i=c; i<*n; i++)			 
       {  
         m[*n *k+i] = -factor * m[c* *n+i]+m[*n *k+i];
       }
       b[k]= -factor * b[c]+b[k];
    } 
  }

/*calls the determinant function. If the determinant is zero, exit*/
  if((det=determinant(m,*n)) == 0)
  {
    printf("The determinant of this matrix is zero!\n\n");
    exit(EXIT_FAILURE);
  }

/*  printf("\nYour reduced matrix without pivoting is:\n");
  print_matrix(m,n);*/
  printf("The Determinant calculated without pivoting is\n \t %.10lf\n\n",det);  

return;
}
