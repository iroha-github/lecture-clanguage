//キーボード入力で商品Aのの価格を設定する
//商品Aの価格が3000円以上の場合は、2割引き、5000円以上の場合は3割引きとして価格を表示する。
//ただし、商品の価格が0円未満の場合「invalid price」と出力する

#include <stdio.h>

int main(void){

  int price;

  printf("price :");
  scanf("%d", &price);

  if (price >= 5000){
    printf("price is %.0f\n", price * 0.7);
  } else if (price >= 3000){
    printf("price is %.0f\n", price * 0.8);
  } else if (price > 0){
    printf("price is %d\n", price);
  } else {
    printf("invalid price\n");
  }
  return 0;
}


