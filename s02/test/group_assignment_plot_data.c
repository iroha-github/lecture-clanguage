#include <stdio.h>
#include <math.h>
#define Gravity -9.8

#ifndef M_PI
#define M_PI 3.141592
#endif

int main(void) {

    double x,z,vx0,vz0,vx,vz,theta;
    double z_min = 0.0;   // z座標初期位置
    double z_max = 100.0; // z座標最終位置
    double delta_z = 1; // z座標刻み幅
    double z0; //z座標の仮置き変数

    double theta_min = 0.0; // theta初期角度
    double theta_max = 50.0; // theta最終座標
    double delta_theta = 0.01; // theta刻み幅

    double delta_t = 0.01; // t刻み幅

    double v0 = 10.0; // 初期速度


    FILE *fp;
    fp = fopen("data.dat", "r");
    if (fp == NULL) {
        printf("ファイルを開けませんでした．\n");
        return 1;
    }
    

    double z0_value, theta_value;
    int count = 0;
    while (fscanf(fp, "%lf %lf", &z0_value, &theta_value) != EOF) {
        printf("z=%fの時，theta=%f\n", z0_value, theta_value);
        double theta_flag = 0.0;
        double x_max = 0; // 初期
        x = 0;

        z = z0_value;
        vx0 = v0 * cos(theta_value / 180.0 * M_PI);
        vz0 = v0 * sin(theta_value / 180.0 * M_PI);
        vx = vx0;
        vz = vz0;
        count += 1;
        //printf("%f %f %f\n",theta ,vx, vz);
        char filename[20];
        sprintf(filename, "data_%d.dat", count);

        FILE *fp2 = fopen(filename, "w");
        if (fp2 == NULL) {
            printf("%sファイルを開けませんでした．\n", filename);
            return 1;
        }
        while(z>=0.0){
            printf("     %d %.3f %.3f\n",count ,x, z);
            fprintf(fp2, "%f %f\n", x, z);
            
            vx += 0 * delta_t;
            x += vx * delta_t;
            vz += Gravity * delta_t;
            z += vz * delta_t;
            

        }
    }

    return 0;
}
