/*
・課題11-1：以下の機能を満たすプログラムを作成せよ。
    ・小数型の入力inと出力outをメンバ変数とする構造体Dataを定義する。
    ・Data型変数による配列data[5]を定義する。
      dataの各要素のメンバ変数inを右表1列目θ、outを0で初期化する。
    ・data[i](i=0~4)を入力とし、メンバ変数inから出力outを計算する関数Updateを作成する。
      Updateの引数：data[i]
      処理：data[i]のinから、out(sin出力)を求める。
    ・main関数でfor文を使い、関数Updateを呼び出し、data[i]の入力と出力を表示する。
    ＊#include <math.h>を使ってsin(theta)を計算する。ただし、 thetaはラジアン単位。
*/

/*
入力in    出力out
  0 
 1/2π
  π
 3/2π
  2π

*/
#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.141592
#endif

struct Data{
    double in;
    double out;
};

struct Data data[5] = {{0, 0}, {M_PI/2, 0}, {M_PI, 0}, {3*M_PI/2, 0}, {2*M_PI, 0}};

void Update(struct Data* d){
    d->out = sin(d->in);
    printf("in: %f, out: %f\n", d->in, d->out);
}

int main(void){
    for(int i=0; i<5; i++){
        Update(&data[i]);
    }
}