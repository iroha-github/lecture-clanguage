/*
課題9-1
・３個の小数値をキーボードから入力すると，その平均値・最大値・最小値を求めて表示する
・ただし，以下の仕様を満たす関数staticsを作成し使用すること．
    ・引数：3個の小数値、3個のポインタ変数（平均値・最大値・最小値）
    ・処理：与えられた小数値からその平均値・最大値・最小値を計算し、ポインタ変数に値をコピーする。
*/



#include <stdio.h>

void calc_ave(double a, double b, double c, double *ave){
    *ave = ( a + b + c )/3 ;
}

void calc_max(double a, double b, double c, double *max){
    *max = a;
    *max = (*max < b) ? b : *max;
    *max = (*max < c) ? c : *max;
}

void calc_min(double a, double b, double c, double *min){
    *min = a;
    if (*min > b) *min = b;
    if (*min > c) *min = b;
}

int main(void){
    double a, b, c, ave, max, min;
    printf("小数値を３つ入力してください\n");
    scanf("%lf %lf %lf",&a,&b,&c);

    calc_ave(a, b, c, &ave);
    printf("平均値は%lf\n",ave);

    calc_max(a, b, c, &max);
    printf("最大値は%lf\n",max);

    calc_max(a, b, c, &min);
    printf("最小値は%lf\n",min);

    return 0;
}



// #include <stdio.h>

// void statics(double x, double y, double z, double *ave, double *max, double *min){
//     *ave = (x + y + z) / 3;
//     *max = x;
//     *min = x;
//     if (*max < y) *max = y;
//     if (*max < z) *max = z;
//     if (*min > y) *min = y;
//     if (*min > z) *min = z;
// }

// int main(void){
//     double x, y, z, ave, max, min;
//     printf("Input 3 numbers: ");
//     scanf("%lf %lf %lf", &x, &y, &z);
//     statics(x, y, z, &ave, &max, &min);
//     printf("Average: %lf\n", ave);
//     printf("Max: %lf\n", max);
//     printf("Min: %lf\n", min);
//     return 0;
// }

