/*
・100以下の値に対し、計算により素数かどうかを判断し、素数を全て表示する。
・for文を利用すること
・break文による繰り返しの強制終了も有効。
・for文を入れ子構造にした多重ループも使ってよい。
*/


#include <stdio.h>

int main(void){
  int i, j;

  for(i=2; i<100; i++){
      for(j=2; j<100; j++){
        if(i % j == 0){
          if(i == j){
            printf("%d\n",i);
            break;
          }else{
            break;
          }
      }
    }
  }
}