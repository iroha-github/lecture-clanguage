#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.141592
#endif

#define GRAVITY -9.8
#define DT 1.0/10

int main(void) {
    double g, dt, x0, z0, v0, theta0, dTheta, thetaMax, vx0, vz0, vz, x, xMax, z, zSet;

    printf("初期高さ（z_set）をメートルで入力してください：\n");
    scanf("%lf", &zSet);

    g = GRAVITY;
    dt = DT;
    x0 = 0.0;
    v0 = 10.0;
    theta0 = 0;
    dTheta = 1.0 / 1.0;
    z0 = 0.0;

    while (z0 < zSet) {
        z0 += 1.0;
        int count = 0;
        char filename[20];
        sprintf(filename, "data%.2lf.dat", z0);

        FILE *fp = fopen(filename, "w");
        if (fp == NULL) {
            printf("ファイル %s のオープンに失敗しました\n", filename);
            return 1;
        }

        xMax = 0;

        for (double theta = theta0; theta < 90; theta += dTheta) {
            printf("角度 %f: ", theta);
            vx0 = v0 * cos(M_PI * theta / 180);
            vz0 = v0 * sin(M_PI * theta / 180);

            vz = vz0;
            z = z0;

            do {
                vz += (g * dt);
                z += vz * dt;
                count += 1;
            } while (z >= 0);

            x = x0 + vx0 * dt * count;
            printf("%d 回のイテレーション, x = %f\n", count, x);

            if (xMax < x) {
                thetaMax = theta;
                xMax = x;
            }
        }

        printf("高さ %.2f で、", z0);
        printf("最大射程 %.2f は角度 %.2f 度で達成されました\n", xMax, thetaMax);

        x = x0;
        z = z0;
        vz = vz0;

        for (int j = 0; j < count; j++) {
            x = x0 + vx0 * dt;
            vz += vz * dt;
            z += vz * dt;
            printf("j = %d, カウント = %d\n", j, count);
            printf("%.5f %.5f\n", x, z);
            fprintf(fp, "%.5f %.5f\n", x, z);
        }

        fclose(fp);
    }

    return 0;
}
