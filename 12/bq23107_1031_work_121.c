/*
- 課題12-1：以下の機能を満たすプログラムを作成せよ。
  - データの出力ファイル名を“data.dat”とする。
  - t=0秒から0.01秒ごとインクリメントさせｔ=2秒まで繰り返し処理を行う。
  - main関数でfor文を使い、以下の処理を実行する。
    - tを入力する。
    - 小数型変数out1に振幅1、周期1秒のsin波の値を代入する。
    - 小数型変数out2に振幅2、周期1秒のcos波の値を代入する。
    - 出力ファイルに時刻t, out1, out2を出力する。
  - 出力ファイルを閉じる。
- #include <math.h>を使ってsin(theta)を計算する。ただし、 thetaはラジアン単位。
*/

#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.141592
#endif

struct DATA {
    double t;
    double out1;
    double out2;
};

struct DATA DATA[201] = {0};  //DATA[201]は、0から200までの201個の要素を持つ配列を宣言します。


int main(void){
    
    //tを０~2まで0.01ずつインクリメント
    for(int i = 0; i<=200; i++){
        DATA[i].t = i/100.0;
        /*
        C言語では、整数同士の除算は整数除算となり、結果も整数になります。つまり、i/100 とすると、i が100未満の場合、結果は常に0になります。
        一方、少なくとも一方が浮動小数点数の場合、除算は浮動小数点数の除算となり、結果も浮動小数点数になります。つまり、i/100.0 とすると、i が100未満でも結果は0より大きな適切な小数になります。
        */

    }

    //out1,out2に周期1秒のsin波cos波を代入
    for(int i = 0; i<=200; i++){
        DATA[i].out1 = sin(DATA[i].t*2*M_PI);
        DATA[i].out2 = 2*cos(DATA[i].t*2*M_PI);  //振幅2
    }

    FILE *fp;
    
    fp = fopen("data.dat","w");
    if (fp == NULL){
        printf("error!");
        return(-1);
    } else {
        printf("open OK!");
    }

    for(int i = 0; i<=200; i++){
        fprintf(fp, "%lf %lf %lf\r\n",DATA[i].t, DATA[i].out1, DATA[i].out2 );
    }


    fclose(fp);
    printf("close OK!");
    return 0;
    
}