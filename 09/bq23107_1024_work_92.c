/*
・課題9‐2：以下の機能を満たすプログラムを作成せよ。
・4個の整数値をキーボードから入力すると、小さい順に並び変えたものを表示する。
・ただし、以下の仕様を満たす関数sortを作成し使用すること。
    ・引数：4個の整数値、4個のポインタ変数
    ・処理：与えられた整数値を並び替えてポインタ変数に値をコピーする。
*/

#include <stdio.h>

void sort(int *a, int *b, int *c, int *d){
    int tmp;
    if(*a > *b){
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
    if(*b > *c){
        tmp = *b;
        *b = *c;
        *c = tmp;
    }
    if(*c > *d){
        tmp = *c;
        *c = *d;
        *d = tmp;
    }
    if(*a > *b){
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
    if(*b > *c){
        tmp = *b;
        *b = *c;
        *c = tmp;
    }
    if(*a > *b){
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

int main(void){
    int a, b, c, d;
    printf("4つの整数を入力してください。\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    sort(&a, &b, &c, &d);
    printf("小さい順に並び替えた結果は %d %d %d %d です。\n", a, b, c, d);
    return 0;
}