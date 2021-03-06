#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fun(float x);
/**********Main function begins*********/
int main(int argc,char *argv[])
{
  float a,b,N,h,f[32],x,ans,n = 0;    /* a,b are the limits where N is the number of intervals and x is the interval,f[] maintains function values at each interval,h is interval length */
  int i = 0,j = 1;    /* These are used to maintain count */
  if (argc != 4) {
    printf("Syntax: ./trapezoid1 a b n\n");    /* prints error message for wrong syntax */
    exit(1);    /* exits from the program */
  }
  a = atof(argv[1]);    /* Takes lower bound */
  b = atof(argv[2]);    /* Takes upper bound */
  N = atof(argv[3]);    /* Takes number of intervals */
  h = (b - a) / (N);    /* interval length */
  while (i != (N + 1)){
    x = a + (i*h);    /* calculates x value at each interval */
    f[i] = fun(x);    /* store f(x) */
    printf ("x[%d] = %f, f[%d] = %f\n",i,x,i,f[i]);    /* prints x and f(x) at each interval */
    i++;    /* increments count */
  }
  i = i - 1;    /* here i = N */
  ans = ((h*(f[0] + f[i]))/2);    /* adds h/2(f(0) + f(N)) to the answer */
  for(j = 1;j < i;j++) {
    n = n + f[j];
  }
  ans = ans + (n*h);    /* adds h(f(x_1) + f(x_2)+.......+f(x_N-1)) to the answer */
  printf("Ans = %f\n",ans);    /* prints the answer */
}
/************Main function ends************/
float fun(float x)
{
  return(sqrt(1 + pow(x,2)));    /* returns f(x) */
}

