#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const double k = 1; // バネ定数
const double m = 2; // 質量 kg
const double l = 3; // バネ自然長

double fx(double x, double y) {
    return -2 * k * x + k * y;
}

double fy(double x, double y) {
    return k * x - 2 * k * y;
}

int main() {
    double w0, w1, w2;
    double t0, t1, dt, ddt, t;
    double x, y, vx, vy, x0, y0, vx0, vy0;
    double C1, C2, D1, D2, phi1, phi2;
    double kx, kvx, ky, kvy;
    int numi, nump, i;

    // 乱数ジェネレータの初期化
    srand(time(NULL));

    w0 = sqrt(k / m);
    w1 = w0;
    w2 = sqrt(3) * w0;

    t0 = 0;
    t1 = 20.0;
    // 乱数を使用して初期値を設定
    x0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
    y0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
    vx0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
    vy0 = 2 * (rand() / (double)RAND_MAX) - 0.5;

    dt = 0.001;
    numi = (t1 - t0) / dt;

    ddt = 0.1; // 0.1秒ごとの結果をプロットする
    nump = ddt / dt; //プロット回数を制限するための変数

    t = t0;
    x = x0;
    y = y0;
    vx = vx0;
    vy = vy0;

    //---ここから厳密解-------------------------------
    FILE *fp;
    fp = fopen("CoupledVibrationRig_dist.dat", "w");

    C1 = (x0 + y0) / 2;
    C2 = (x0 - y0) / 2;
    D1 = (vx0 + vy0) / (2 * w1);
    D2 = (vx0 - vy0) / (2 * w2);

    x = C1 * cos(w1 * t) + D1 * sin(w1 * t) + C2 * cos(w2 * t) + D2 * sin(w2 * t);
    y = C1 * cos(w1 * t) + D1 * sin(w1 * t) - C2 * cos(w2 * t) - D2 * sin(w2 * t);

    for (i = 0; i <= numi; i++) {
        if (i % nump == 0) {
            printf("%f %f %f\n", t, x, y);
            fprintf(fp, "%f %f %f\n", t, x, y);
        }
        t = t + dt;
        x = C1 * cos(w1 * t) + D1 * sin(w1 * t) + C2 * cos(w2 * t) + D2 * sin(w2 * t);
        y = C1 * cos(w1 * t) + D1 * sin(w1 * t) - C2 * cos(w2 * t) - D2 * sin(w2 * t);
    }
    fflush(fp);
    fclose(fp);
    //---ここまで厳密解-------------------------------

    t = t0; // tを初期値に戻す
    x = x0; // xを初期値に戻す
    y = y0; // yを初期値に戻す
    vx = vx0; // vxを初期値に戻す
    vy = vy0; // vyを初期値に戻す

    //---ここからオイラー法----------------------------
    FILE *fp1;
    fp1 = fopen("CoupledVibrationEuler.dat", "w");

    for (i = 0; i < numi; i++) {
        if (i % nump == 0) {
            printf("%f %f %f\n", t, x, y);
            fprintf(fp1, "%f %f %f\n", t, x, y);
        }
        x = x + dt * vx;
        y = y + dt * vy;
        vx = vx + dt * fx(x, y) / m;
        vy = vy + dt * fy(x, y) / m;
        t = t + dt;
    }
    fflush(fp1);
    fclose(fp1);
    //---ここまでオイラー法----------------------------

    t = t0; // tを初期値に戻す
    x = x0; // xを初期値に戻す
    y = y0; // yを初期値に戻す
    vx = vx0; // vxを初期値に戻す
    vy = vy0; // vyを初期値に戻す

    //---ここから中点法-------------------------------
    FILE *fp2;
    fp2 = fopen("CoupledVibrationMid.dat", "w");

    for (i = 0; i < numi; i++) {
        if (i % nump == 0) {
            fprintf(fp2, "%f %f %f\n", t, x, y);
            printf("%f %f %f\n", t, x, y);
        }

        kx = x + (dt / 2) * vx; //中点法を行うためにdt/2だけ進めた値でkxを仮置きする
        ky = y + (dt / 2) * vy; //中点法を行うためにdt/2だけ進めた値でkyを仮置きする
        kvx = vx + (dt / 2) * fx(x, y) / m; //中点法を行うために値をkvx仮置きする
        kvy = vy + (dt / 2) * fy(x, y) / m; //中点法を行うために値をkvy仮置きする
        x = x + dt * kvx; //仮置きされた値を用いてxを更新する
        y = y + dt * kvy; //仮置きされた値を用いてxを更新する
        vx = vx + dt * fx(kx, ky) / m; //仮置きされた値を用いてvxを更新する
        vy = vy + dt * fy(kx, ky) / m; //仮置きされた値を用いてvyを更新する
        t = t + dt;
    }

    fflush(fp2);
    fclose(fp2);
    //---ここまで中点法-------------------------------

    FILE *gp;
    gp = popen("gnuplot -persist -slow", "w");

    // Gnuplotに送るコマンドを定義
    char *gnuplotscript =
        "set xlabel \"t\"\n"
        "set ylabel \"x,y\"\n"
        "plot "
        "\"CoupledVibrationRig_dist.dat\" u 1:2 w l title \"Rig dist_x\", "
        "\"CoupledVibrationRig_dist.dat\" u 1:3 w l title \"Rig dist_y\", "
        "\"CoupledVibrationEuler.dat\" u 1:2 w l title \"Euler_x\", "
        "\"CoupledVibrationEuler.dat\" u 1:3 w l title \"Euler_y\", "
        "\"CoupledVibrationMid.dat\" u 1:2 w l title \"Mid_x\", "
        "\"CoupledVibrationMid.dat\" u 1:3 w l title \"Mid_y\"\n";

    // Gnuplotにコマンドを送る
    fprintf(gp, "%s", gnuplotscript);

    pclose(gp);

    return 0;
}
