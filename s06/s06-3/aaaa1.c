#include <stdio.h>
#include <math.h>

int main(void) {
    FILE *fp;
    fp = fopen("data1.dat", "r");
    if (fp == NULL) {
        printf("ファイルを開けませんでした\n");
        return 1;
    }

    FILE *fp2;
    fp2 = fopen("anime_data1_xy.dat", "w");

    // data1.datの中身を表示
    double t, θ1, θ2;
    double x0, y0, x1, y1, x2, y2;
    double r = 1; // ひもの長さ
    while (fscanf(fp, "%lf %lf %lf", &t, &θ1, &θ2) != EOF) {
        x0 = 0;
        y0 = 0;
        x1 = r * sin(θ1);
        y1 = -r * cos(θ1);
        x2 = x1 + r * sin(θ2);
        y2 = y1 - r * cos(θ2);
        fprintf(fp2, "%f %f %f %f %f %f\n", x0, y0, x1, y1, x2, y2);
    }

    fclose(fp);
    fclose(fp2);

    // 新しいファイルポインタを開く
    FILE *fp3;
    fp3 = fopen("anime_data1_xy.dat", "r");

    FILE *gp;
    gp = popen("gnuplot -persist", "w");

    fprintf(gp, "set terminal gif animate delay 5 optimize size 480,640\n");
    fprintf(gp, "set output 'anime_data1_xy.gif'\n");

    // ファイルからデータを読み込んでプロット
    while (fscanf(fp3, "%lf %lf %lf %lf %lf %lf", &x0, &y0, &x1, &y1, &x2, &y2) != EOF) {
        fprintf(gp, "plot [-1:1][-3:1] %lf, %lf, %lf, %lf w p pt 7 ps 2\n", x0, y0, x1, y1);
    }

    fprintf(gp, "unset output\n");

    fclose(fp3);
    pclose(gp);
    return 0;
}
