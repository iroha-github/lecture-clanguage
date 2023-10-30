#include <stdio.h>

int main(void) {
    FILE *fp;
    double x, y, z;

    fp = fopen("data.dat", "r");
    if (fp == NULL) {
        printf("指定されたファイルが開けませんので，プログラムを終了します．\n");
        return -1;
    } else {
        printf("指定されたファイルをオープンしました．\n");
    }

    fscanf(fp, "%lf, %lf, %lf", &x, &y, &z);
    fclose(fp);

    printf("ファイルをクローズしました。\n");
    printf("読み込んだデータの総和は %f です．\n", x + y + z);

    return 0;
}