/*
・課題11-2：以下の機能を満たすプログラムを作成せよ。

    ・小数型の入力inと出力outをメンバ変数とする構造体Dataを定義する。

    ・t=0秒から0.01秒ごとインクリメントさせｔ=1.0秒まで繰り返し処理を行う。

    ・Data型配列data[101]を定義する。全てのメンバ変数を0で初期化する。
        *なぜ要素数を「101」にしたかは各自考えてください。

    ・tをdata[i]のメンバ変数inに代入し、出力outを計算する関数Updateを作成する。
        Updateの引数：t, data[i]
        処理：tを入力とし、振幅１、周期１秒のsin波の値を計算する。
        data[i]のinにtを代入、outに計算値を代入する。

    ・main関数でfor文を使い、関数Updateを呼び出し、更新しされたdata[i]の入力と出力を表示する。

    ＊#include <math.h>を使ってsin(theta)を計算する。ただし、 thetaはラジアン単位。
*/

#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265
#endif

struct Data {
    double in;
    double out;
};

//0が含まれるので要素数を101にする
struct Data data[101] = {0};

void Update(double t, struct Data* data){
    data->out = sin(t*2*M_PI);
}

int main(void){
    for(int i=0; i<101; i++){
        data[i].in = i/100.0;
    }
    /*
    i/100.0 の部分で、100.0 を使用する理由は、浮動小数点数の除算を行うためです。

    C言語では、整数同士の除算は整数除算となり、結果も整数になります。つまり、i/100 とすると、i が100未満の場合、結果は常に0になります。

    一方、少なくとも一方が浮動小数点数の場合、除算は浮動小数点数の除算となり、結果も浮動小数点数になります。つまり、i/100.0 とすると、i が100未満でも結果は0より大きな適切な小数になります。

    このプログラムでは、i を0.00から1.00までの小数に変換したいので、i/100.0 を使用しています。
    */


    for(int i=0; i<101; i++){
        double t;
        t = data[i].in;
        Update(t, &data[i]);
        printf("in:%lf, out:%lf\n",t,data[i].out);
    }
    return 0;
}

