#include <stdio.h>
#include <math.h>

int main(){
    double m, k, b, t, x, xx, vx, t0, t1, x0, vx0, dt, ddt;
    int num_i, num_p;

    m = 2; // 質量
    k = 50; // ばね定数
    b = 0; // 粘性抵抗係数を一旦ゼロ置いておく

    t0 = 0; // 初期時間
    t1 = 10; // この時間まで測定する

    x0 = 3;  // 初期位置
    vx = 0;  // 速度
    vx0 = 100;  // 初期速度

    dt = 0.001; // 時間の刻み幅
    num_i = (t1 - t0) / dt; // 繰り返し回数の指定

    ddt = 0.01; // plotする時間間隔
    num_p = ddt / dt; // num_p毎にplotする

    int b_resistance[3] = {3, 20, 100}; // 粘性抵抗の値を３つ指定

    FILE *gp;
    gp = popen("gnuplot --persist -slow", "w");

    for (int i = 0; i < 3; i++) {
        char filename[30];
        sprintf(filename, "SpringViscosity2_%d.dat", b_resistance[i]);
        FILE *fp;
        fp = fopen(filename, "w");

        t = t0;   // tの初期条件
        x = x0;   // x
        vx = vx0; // vx
        b = b_resistance[i]; // bの値を変更

        for (int j = 1; j <= num_i + 0.001; j++) {
            if (j % num_p == 0) {              // jがnum_pで割り切れるとき
                printf("%f %f\n", t, x); // 横軸にt,縦軸にx
                fprintf(fp, "%f %f\n", t, x);
            }
            xx = x; // xxは仮変数
            x = x + dt * vx;                 // xの更新
            vx = vx + dt * (-k * xx - b * vx) / m;  // vxの更新
            t = t + dt;                     // tの更新
        }
        fclose(fp);
    }

    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            fprintf(gp, "plot \"SpringViscosity2_%d.dat\" w l \n", b_resistance[i]);
        } else {
            fprintf(gp, "replot \"SpringViscosity2_%d.dat\" w l\n", b_resistance[i]);
        }
    }
    fflush(gp);
    pclose(gp);
    return 0;
}
