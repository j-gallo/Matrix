#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double determinant(double *m,int n);
void print_matrix(double *m, int *n);
int swap(double *m, int *n, int c, double*b);

void pivoting(double *m, double *b, int *n)
{
 
  int c,k,i,j,l,f;
  double factor,change1,change2,det;
  int sign=0;

  change1 = det = change2 = f = j = l = c = k = i = 0;
/*cycles through the matrix elements with c as the rows, k as the columns, and n the 
 * dimension of the matrix.*/
  for(c=0; c<*n-1; c++)
  {
/*calls the swap function to perform any necessary pivoting*/
    sign+=swap(m,n,c,b);	
    for(k=*n-1; k>0+c; k--)
    {
/*if the diagonal element on the current row is not zero, divide it by the element just 
 * below it in the same column and use the negative of that fraction as the scaling factor
 * and add the current row times the scaling factor to the row just beneath*/
      if(m[*n *c+c] != 0)
      {
        factor = (m[*n *k+c])/(m[*n *c+c]);
        for(i=c; i<*n; i++)
        {
	  m[*n *k+i] = -factor * m[c* *n+i]+m[*n *k+i];
        }
	b[k]= -factor*b[c]+b[k];
      }
    }
  }
//keeps track of the row swaps to change the determinant as necessary.
  sign+=swap(m,n,c,b);
/*calls the determinant function. If the determinant is zero, exit*/
  if((det = determinant(m,*n)) == 0)
  {
    printf("the determinant of the matrix is zero\n");
    exit(EXIT_FAILURE);
  }

//calculates the value of the determinant and changes the sign as dictated by the number
//of row swaps (if there were an odd number of row swaps, the determinant will come out
//negative of the correct answer so i must multiply by -1).
  if(sign % 2 == 0) det = determinant(m,*n);
  else det = determinant(m,*n) * -1;
/*  printf("Your reduced, pivoted, matrix is:\n");
  print_matrix(m,n);*/
  printf("The Determinant calculated with pivoting is\n \t %.10lf\n\n",det);  

return;
}
