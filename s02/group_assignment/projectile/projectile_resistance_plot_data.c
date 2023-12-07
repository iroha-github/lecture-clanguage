#include <stdio.h>
#include <math.h>
#define Gravity -9.8

#ifndef M_PI
#define M_PI 3.141592
#endif

int main(void) {
    double x, z, vx0, vz0, vx, vz, theta;
    double z_min = 0.0;
    double z_max = 10.0; // 30.0
    double delta_z = 1.0;
    double z0;

    double theta_min = 0.0;
    double theta_max = 50.0;
    double delta_theta = 0.1; 

    double delta_t = 0.01; //0.01

    double v0 = 10.0;
    double b = 2.5;
    double m = 3.0;

    FILE *fp;
    fp = fopen("d2.dat", "r");
    if (fp == NULL) {
        printf("ファイルを開けませんでした．\n");
        return 1;
    }

    double z0_value, theta_value;
    int count = 1;

    while (fscanf(fp, "%lf %lf", &z0_value, &theta_value) != EOF) {
        printf("z=%fの時，theta=%f\n", z0_value, theta_value);
        double theta_flag = 0.0;
        double x_max = 0;
        x = 0;
        z = z0_value;
        vx0 = v0 * cos(theta_value / 180.0 * M_PI);
        vz0 = v0 * sin(theta_value / 180.0 * M_PI);
        vx = vx0;
        vz = vz0;
        
        char filename[20];
        sprintf(filename, "data2_%d.dat", count);
        FILE *fp2 = fopen(filename, "w");
        
        if (fp2 == NULL) {
            printf("%sファイルを開けませんでした．\n", filename);
            return 1;
        }

        int inner_count = 0;

        while (z >= 0.0) {
            printf("     %d %.3f %.3f\n", inner_count, x, z);
            fprintf(fp2, "%f %f\n", x, z);
            vx = vx + delta_t * (0 - b * vx / m);
            x += vx * delta_t;
            vz = vz + delta_t * (Gravity - b * vz / m);
            z += vz * delta_t;
            inner_count += 1;
        }

        fclose(fp2); // ファイルを閉じる
        count += 1;  // カウントを更新
    }

    fclose(fp); // ファイルを閉じる

    return 0;
}
