#include <stdio.h>

void main()
{
  int i;
  int array[100];

  /*配列要素に値を代入*/
  for(i=0; i<100; i++){
    array[i] = 10*(i+1);
  }

  for (i=0; i<100; i++){
    printf("%d番目の要素変数の値は%dです。\n", i+1, array[i]);
  }
}