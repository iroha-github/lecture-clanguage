#include <stdio.h>

void main()
{
  int i =0;

  do{
    printf("i = %d\n", i);
    i ++;
  }while(i < 10);

  printf("Out of the do-while loop i = %d\n",i);
}