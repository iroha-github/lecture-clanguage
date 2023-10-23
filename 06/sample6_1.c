#include <stdio.h>

void main()
{
  int i;

  for (i=0; i<10; i++){
    printf("i = %d\n",i);
  }

  printf("Out of the for loop. i=%d\n",i);
}