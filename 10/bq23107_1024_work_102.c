/*
・課題10-2：以下の機能を満たすプログラムを作成せよ。
・3個の整数値をキーボードから入力すると、素数だけ取り出し、表示する。
・ただし、以下の仕様を満たす関数extractPrimeNumを作成し使用すること。
    ・引数：配列in[3]、out[3]・処理：配列inの各要素が素数であるかどうかをチェックし、素数の場合、
    配列outに代入する。素数でなければ、0を代入する。
    if（in[i] == 素数）
        out[i] = in[i]
    else 
        out[i] = in[i]
・main関数で関数extractPrimeNumを呼び出し、配列outに格納されたもののうち、素数を全て表示する。
*/

#include <stdio.h>

//プロトタイプ宣言というものをしてみる
/*
関数を呼び出す場合
「呼び出す関数は使用する前に記述しておく必要がある」
というルールがあります。
*/


void extractPrimeNum(int *, int *);


int main(void){
    int in[3], out[3];
    int i = 0;

    printf("素数か否かを判定します．\n");

    while (i < 3){
        printf("%d番目の数字を入力してください\n",i+1);
        scanf("%d",&in[i]);
        i++;
    }
    
    //配列は関数に渡される際に、暗黙的にその最初の要素へのポインタとして解釈され、関数内でそのポインタを使用して配列にアクセスできます。

    extractPrimeNum(in,out);
    
    printf("配列outに格納されたもののうち，素数だけを表示\n");
    for(int i=0; i<3; i++){
        if(out[i] != 0){
            printf("%d ",out[i]);
        }
    }
}


void extractPrimeNum(int in[], int out[]){
    for(int i=0; i<3; i++){
        int num = in[i];

        while(num == 2){
            out[i]=2;
            break;
        }

        for(int j=2; j<num; j++){
            if(num % j == 0 ){
                out[i]=0;
                break;
            }else{
                out[i]=in[i];
            }
        }
    }
}


/*
このことについてまとめると、まず、次の3つは同じ意味の仮引数宣言です。
ただし、この3つが同じ意味になるのは関数の仮引数宣言の場合のみです。

ソースコード
int getaverage(int data[10]);
int getaverage(int data[]);
int getaverage(int* data);

そして、関数の中では、dataはいずれもポインタ型の変数です。
そして、呼び出し先と呼び出し元ではまったく同じメモリ領域の配列を使うことになります。

どれにするか
この3つが同じ意味だと、どれを使って良いのか迷う人もいるかもしれませんが、
筆者としては、2番目のように要素数を省略した形を使うことを勧めます。
*/
