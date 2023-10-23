#include <stdio.h>

// main()
int main(void)
{
  int i;
  int array[5] = {10, 20, 30, 40, 50};

  for (i = 0; i<5; i++) {
    printf("%d番目の要素変数の値は%dです。\n", i+1, array[i]);
  }
}