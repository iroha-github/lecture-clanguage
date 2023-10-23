#include <stdio.h>

void hello(void) /*関数helloの定義(引数，戻り値ともになし)*/
{
  printf("こんにちは\n");
}

int max(int x, int y)
{
  int max=x;

  if(max<y) max=y; /*最大値の入れ替え*/
    return(max);
}

void print_num(int x, int y) /*入力値を表示する関数*/
{
  printf("入力された整数はx=%dとy=%dですね．\n", x, y);
}

void main() /*main関数*/
{
  int a,b,c;

  hello(); /*関数helloの呼び出し(引数,戻り値ともなし)*/

  printf("一つ目の整数を入力してください．\n");
  scanf("%d", &a);

  printf("二つ目の整数を入力してください．\n");
  scanf("%d", &b);

  print_num(a,b); /*関数print_numの呼び出し(引数あり，戻り値なし)*/

  c=max(a,b); /*関数maxえお呼び出し，結果を変数cに格納(引数あり,戻り値なし)*/
  printf("%dと%dの最大値は%dです．\n", a, b, c);
}