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


#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.141592
#endif
/*
#ifndef は「if not defined」の略で、特定のマクロが定義されていない場合にのみコードを実行するためのプリプロセッサディレクティブです。このコードでは、M_PI がまだ定義されていない場合にのみ、M_PI を 3.14159265 に定義します。

このようにする理由は、M_PI がすでに別の場所で定義されている可能性があるからです。たとえば、<math.h> などの一部のライブラリでは、M_PI がすでに定義されていることがあります。このコードは、M_PI がまだ定義されていない場合にのみ新たに定義することで、二重定義を防ぎます。
*/

struct Data{
    double in;
    double out;
};

struct Data data[5] = {
    {0, 0},
    {M_PI/2, 0},
    {M_PI, 0},
    {3*M_PI/2, 0},
    {2*M_PI,0}
};

//C言語で構造体のメンバ変数にアクセスするには、ドット演算子.を使用します
//構造体へのポインタを通じてメンバ変数にアクセスする場合は、アロー演算子->を使用します
void Update(struct Data* data){
        data->out = sin(data->in);
}

int main(void){
    for(int i = 0; i < 5; i++){
        Update(&data[i]);
        printf("inは%.4lf,outは%.4lf\n",data[i].in, data[i].out);
    }
    return 0;
}