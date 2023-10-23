#include <stdio.h>

main()
{
  int i, j;
  i = 0;
  j = 1;

  printf("式の値は %d,\n", i==j);
  printf("式の値は %d,\n", i!=j);
  printf("式の値は %d,\n", i>=j);

  printf("式の値は %d,\n", i>0 && j >0);
  printf("式の値は %d,\n", i>0 || j >0);
}