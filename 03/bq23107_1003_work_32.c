//キーボード入力で数字の1~9を入力する
//入力した数が素数(2,3,5,7)であれば「prime number」と出力する。
//入力した数が素数でなければ「not prime number」と出力する。
//入力した数が1~9以外の場合は「invalid number」と出力する。

#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);

  if (n == 2 || n == 3 || n == 5 || n == 7) {
    printf("prime number\n");
  } else if (n == 1 || n == 4 || n == 6 || n == 8 || n == 9) {
    printf("not prime number\n");
  } else {
    printf("invalid number\n");
  }
}