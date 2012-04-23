#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

void readin(char *file, double **m, int *size)
{
  int i,c;
  double read;
  FILE *matrix;
 // double temp;
    i = 0;
/* Opens the input file. If the file doesn't exist, the program exits*/
  if ( NULL == (matrix = fopen(file,"r")))
  {
    printf("Could not open file\n");
    exit(EXIT_FAILURE) ;	
  }

/*Reads the file, counts the number of elements in the matrix (i), and reallocates memory with each new readin.
 * If a the next thing to be read is not a double, stop the loop.*/
if(*m==NULL)
{
  while(1 == (c=fscanf(matrix,"%lf",&read)))
  {
    i++;
    if(0 == (*m = realloc(*m, i * sizeof(double)))) 
    {  
      printf("Memory allocation has failed\n");
      exit(EXIT_FAILURE);
    }
    (*m)[i-1] = read;
  }

//If the last thing read was a double, not the end of file, exit.
  if(EOF !=c)
  {
    printf("Your matrix is populated by things other than numbers.\n");
    exit(EXIT_FAILURE);
  }
}

else
{
  while(1 == (c=fscanf(matrix,"%lf",&read)))
  {
    i++;
    (*m)[i-1] = read;
  }
}
/*n is the dimension of the square matrix*/
  *size = i;
  fclose(matrix);

return;
}
