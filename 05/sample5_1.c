#include <stdio.h>

void main()
{
  int i = 0;

  while (i < 10){
    printf("i = %d\n",i);
    i = i + 1;
  }

  printf("Out of the while loop. i = %d\n",i);
}