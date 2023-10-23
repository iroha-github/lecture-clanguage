#include <stdio.h>

void main()
{
  double x;

  scanf("%lf", &x);

  if (x > 0){
    printf("x is positive.\n");
  } else if ( x == 0 ){
    printf("x is zero.\n");
  } else {
    printf("x is negative.\n");
  }
}
