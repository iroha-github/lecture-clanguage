/*
・キーボードから１～９の値を入力し、素数かどうかを判定・表示する動作を５回繰り返すプログラムを作成せよ。
・while文を利用すること
*/

#include <stdio.h>

int main(void){
  int i = 0; 
  int n = 0;


  while(i<5){
    printf("１～９の数字を入力してください\n");
    printf("素数かどうかを判定します\n");
    scanf("%d",&n);

    if (n>0 && n< 10){
      if (n == 2 || n == 3 || n == 5 || n == 7 ){
        printf("素数です\n");
      }else{
        printf("素数ではありません\n");
      }

    }else{
      printf("１～９の数字を入力してください");
    }

    i++;
  }

}
