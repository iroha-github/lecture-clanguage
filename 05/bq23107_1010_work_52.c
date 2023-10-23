/*
・お小遣い3000円を全て使って、１個110円のりんごをいくつ買えるか計算する。
・ただし、割り算(/,%)は使用せず、引き算のみを使用して良い。
・while文を使うこと。
・最大購入可能数と余りの金額をひょうじすること。「27個、余り30円」
*/
#include <stdio.h>

int main(void){
  int money = 3000;
  int count = 0;

  while(money >= 110){
    count++;
    money -= 110;
  }

  printf("%d個、あまり%d円", count, money);
}