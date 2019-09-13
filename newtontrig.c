//This program is used to find the roots of the given equation using newton method.
//This method is based on the approximation of a curve as a secant in the close 
//neighbourhood of the root.
//Then we find out the iterations using the expression 
//x(k+1) = x(k) - (f(k) / f`(k)).
//Where x(k) is the approximation in the near neighbourhood
//of the root and f(k) is the function value at x(k).
//The we use the same formula to find next iteration.
//Given equation is 3x - cos(x) - 1.
//Use -lm option of gcc while compiling the code and -o option to give a
//meaningfull objectcode filename.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float f(float );
float f1(float );

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    fprintf(stderr,"Usage:- ./newtontrig <guess1>\n");
    exit(1);
  }
//Variables x0, x1 for the iterations
  float x0, x1;
  int i = 0;
  
  x0 = atof(argv[1]); 
//While to calculate iterations
  while (i != 10)
  {
    i++;
    x1 = x0 - (f(x0) / f1(x0));
    x0 = x1;
    printf("Iteration %d :- %.10f\n", i, x1);
  }
  printf("Root of the equation is %.10f\n", x1);
  printf("Iterations :- %d\n", i);

  return(0);
}

//Function value
float f(float x)
{
  return ((3 * x) - cos(x) - 1);
}

//Value of derivative of the function
float f1(float x)
{
  return (3 + sin(x));
}
