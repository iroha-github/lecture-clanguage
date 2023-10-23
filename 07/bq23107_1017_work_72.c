/*
・課題7-2：以下の機能を満たすプログラムを作成せよ。
　・ある円の半径を渡すと、円の周長と面積を計算し、表示する。
　・ただし、以下の仕様の関数”calc”、”calcCircumference”、”calcArea”を必ず作成し、
　　使用すること。
　　・関数calc
　　　ー引数として、double型で円の半径を渡すと、直径と面積を表示する関数
　　　ー戻り値はなし。内部で”calcCircumference”、”calcArea”を呼び出す。
　　・ calcCircumference
　　　ー引数として、double型で円の半径を渡すと、直径を計算する関数
　　　ーdouble型で周長を返す。
　　・ calcArea
　　　ー引数として、double型で円の半径を渡すと、面積を計算する関数
　　　ーdouble型で面積を返す。
*/

/*
＊円周率の使い方：math.hをインクルードして、M_PIを呼び出す。
　　　#include <math.h> 
void main(void) {
    printf("%f\n", M_PI); // M_PIは円周率として扱われる
}
*/


#include <stdio.h>

double calcCircumference(double radius){
  return 2 * 3.141592 * radius;
}

double calcArea(double radius){
  return 3.141592 * radius * radius;
}

void calc(double radius){
  double a, b;
  printf("半径rを%lfとしたときの周長は%lfです\n", radius, calcCircumference(radius));
  printf("半径rを%lfとしたときの面積は%lfです\n", radius, calcArea(radius));
}


int main(void){
  double radius;
  printf("半径を入力してください");
  printf("円の周長と面積を計算します");
  scanf("%lf",&radius);
  calc(radius);
}
