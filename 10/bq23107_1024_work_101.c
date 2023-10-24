/*
・課題10-1：以下の機能を満たすプログラムを作成せよ。
・5個の小数値をキーボードから入力すると、その平均値・最大値・最小値を表示する。
・入力値を格納する配列in[5]、関数staticsからの出力を格納する配列out[3]を使用すること。
・main関数で関数staticsを呼び出し、配列outの値を表示する。・関数staticsの仕様は下記とする。
    ・引数：配列in[5]、out[3]
    ・処理：配列inから平均値・最大値・最小値を計算し、配列outに代入・戻り値：なし
*/

#include <stdio.h>

#define N 5

void statics(double *in, double *out){
    double sum =0;
    double max, min;
    max=in[0];
    min=in[0];

    for(int i=0; i<N; i++){
        sum += in[i];
        max = (max < in[i]) ? in[i] : max;
        min = (min > in[i]) ? in[i] : min;
    }

    out[0] = sum/N;
    out[1] = max;
    out[2] = min;
}

int main(void){
    double in[N];
    double out[3];
    printf("N(5)個の小数値を入力して下さい\n");
    for(int i=0; i<N; i++){
        scanf("%lf",&in[i]);
    }

    statics(in,out);

    printf("平均値・最大値・最小値\n");
    for(int i=0; i<3; i++){
        printf("%lf\n",out[i]);

    }
    
}