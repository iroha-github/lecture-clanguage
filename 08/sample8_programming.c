/*
キーボードから5つの小数データを配列に読込み、入力後に表示するプログラムを作成せよ
*/




#include <stdio.h>

int main(void){
  float a[5];

  for (int i=0; i<5; i++){
    printf("%d番目の数字を入力してください．\n",i+1);
    double x;
    scanf("%lf",&x);
    a[i] = x;
  }

  for (int i=0; i<5; i++){
    printf("%f\n",a[i]);
  }
}