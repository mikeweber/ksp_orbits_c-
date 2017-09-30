#include <stdio.h>
#include <math.h>

#define TAU 6.283185307

int main ()
{
  double param, result;
  param = 30.0;
  result = sin(param * TAU / 360);
  printf("The sine of %f degrees is %f.\n", param, result);
  return 0;
}
