#include <stdio.h>
#include <math.h>
#define Gravity -9.8

#ifndef M_PI
#define M_PI 3.141592
#endif

int main(void) {;

    double x,z,vx0,vz0,vx,vz,theta;
    double z_min = 0.0;   // z座標初期位置 0.0
    double z_max = 10.0; // z座標最終位置 30.0
    double delta_z = 1.0; // z座標刻み幅
    double z0; //z座標の仮置き変数

    double theta_min = 0.0; // theta初期角度
    double theta_max = 50.0; // theta最終座標
    double delta_theta = 0.1; // theta刻み幅

    double delta_t = 0.01; // t刻み幅 0.01

    double v0 = 10.0; // 初期速度
    double b = 2.5; // 粘性抵抗係数
    double m = 3.0; // 質量


    FILE *fp;
    fp = fopen("d2.dat", "w");

    for (z0 = z_min; z0 < z_max; z0 += delta_z) {
        double theta_flag = 0.0;
        double x_max = 0; // 初期
        for (theta = theta_min; theta < theta_max; theta += delta_theta) {
            x = 0;
            z = z0;
            vx0 = v0 * cos(theta / 180.0 * M_PI);
            vz0 = v0 * sin(theta / 180.0 * M_PI);
            vx = vx0;
            vz = vz0;
            int count = 0;
            //printf("%f %f %f\n",theta ,vx, vz);
            while(z>=0.0){
                vx = vx + delta_t * (0 - b * vx/m);
                x += vx * delta_t;
                vz = vz + delta_t * (Gravity - b * vz/m);
                //vz+dt*(g - b*vz/m)
                z += vz * delta_t;
                count += 1;
                //printf("%f %d %.3f %.3f\n", theta,count, x, z);
            }

            if (x_max < x) {
                x_max = x;
                theta_flag = theta;
            }
            
        }

        printf("z=%.3fの時，theta=%.3fで最大飛距離x=%.3fである．\n", z0, theta_flag, x_max);
        fprintf(fp, "%f %f\n", z0, theta_flag);
    }

    return 0;
}
