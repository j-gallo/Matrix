//$Id: gauss.c,v 1.5 2010/11/05 18:36:02 jgallo Exp jgallo $

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void readin(char *file, double **m, int *size);
void pivoting(double *m, double *b, int *n);
void no_pivot(double *m, double *b, int *n);
double determinant(double *m,int n);
void answer(double *m, double *b, int *n);
void print_b(double *b, int *n);
void print_matrix(double *m, int *n);


int main(int argc, char **argv)
{
/*This function simply initializes the pointers that will be passed throughout all of the subroutines
 * and calls each subroutine in order.*/
  int *n,*size, sizeb=0, sizem=0;
  double *m,*b;
  m = NULL;
  b = NULL;
  n = NULL;
  size = NULL;
  m=b=0;

//Checks to make sure that enough arguments have been supplied. If not, exit.
  if(argc<3)
  {
    printf("You have not supplied enough arguments.\nPlease input the name of the file containing the matrix and the name of the file containing the solution vector\n");
    exit(EXIT_FAILURE);
  }


    size = malloc(sizeof(int));
    n = malloc(sizeof(int));

if(argc == 4)
{
  if(0 == strcmp ("-np",argv[3]))
  {
//reads in the solution vector
    readin(argv[2],&b,size);

//records the size of the solution vector
    sizeb = *size;

//reads in the matrix
    readin(argv[1],&m,size);

//records the dimension of the matrix
    sizem = sqrt(*size);
    if(pow(sizem,2) != *size)
    {
      printf("This matrix is not square!\n");
      exit(EXIT_FAILURE);
    }

//checks that the matrix dimension and the size of the solution vector are the same
    if(sizem != sizeb)
    {
      printf("The matrix is not the same size as the solution vector!!\n");
      exit(EXIT_FAILURE);
    }

    *n = sizem;

    no_pivot(m,b,n);

    print_matrix(m,n);

    print_b(b,n);

    answer(m,b,n);
  }
  else printf("%s is not a valid flag\n",argv[4]);
}


//---------------------------------------------------------------------------------


//If there are only 3 arguments, default to pivoting
if(argc == 3)
{
    readin(argv[2],&b,size);

//records the size of the solution vector
    sizeb = *size;

    readin(argv[1],&m,size);

//records the dimension of the matrix
    sizem = sqrt(*size);
    if(pow(sizem,2) != *size)
    {
      printf("This matrix is not square!\n");
      exit(EXIT_FAILURE);
    }

//checks that the matrix dimension and the size of the solution vector are the same
    if(sizem != sizeb)
    {
      printf("The matrix is not the same size as the solution vector!!\n");
      exit(EXIT_FAILURE);
    }

    *n = sizem;

    pivoting(m,b,n);

    print_b(b,n);

    answer(m,b,n);

    print_matrix(m,n);
}

  free (m);
  free (b);
  free (n);
  free (size);
return (0);
}
