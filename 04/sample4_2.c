#include <stdio.h>

int main()
/*
/サンプルプログラムはmain()から始まるが
/今回はmain()の前にintをつけることで
/main()の戻り値をint型にする
*/ 
{
  int n;

  printf("Menu\n");
  printf("1.spring \n");
  printf("2.summer \n");
  printf("3.fall \n");
  printf("4.winter \n");
  scanf("%d", &n);

  switch (n) {
  case 1:
    printf("March, April, May\n");
    break;
  case 2:
    printf("June, July, August\n");
    break;
  case 3:
    printf("September, October, November\n");
    break;
  case 4:
    printf("December, January, February\n");
    break;
  default:
    printf("error!\n");
  }
}
