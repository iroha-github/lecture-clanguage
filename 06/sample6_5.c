#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
  int x, y;

  // 時間データを基に乱数の種を生成し、srand関数に渡して乱数生成を準備
  srand(time(0));

  /*
  「rand()」を実行すると、乱数を１回発生させる。これと剰余演算子により。
  0～9までの数をランダムに発生させ、整数型変数x,yに代入
  */

 x = rand() % 10;
 y = rand() % 10;
  
  printf("スタート座標です。今、あなたは(x,y)=(%d %d)にいます。\n", x, y);
}