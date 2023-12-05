#include <stdio.h>
#include <math.h>
#define Gravity -9.8

#ifndef M_PI
#define M_PI 3.141592
#endif

int main(void) {
    double g, dt, x0, z0, theta, dtheta, vx0, vz0, vx, vz, x, z;

    double z_min = 0.0;   // z座標初期位置
    double z_max = 100.0; // z座標最終位置
    double delta_z = 1.0; // z座標刻み幅

    double theta_min = 0.0; // theta初期角度
    double theta_max = 50.0; // theta最終座標
    double delta_theta = 1.0; // theta刻み幅

    double delta_t = 0.1; // t刻み幅

    double v0 = 10.0; // 初期速度


    FILE *fp;
    fp = fopen("data.dat", "w");

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
            do {
                vx += 0 * delta_t;
                x += vx * delta_t;
                vz += Gravity * delta_t;
                z += vz * delta_t;
                count += 1;
                //printf("     %d %.3f %.3f\n",count ,x, z);
            } while (z >= 0.0);

            if (x_max < x) {
                x_max = x;
                theta_flag = theta;
            }
            
        }

        printf("z=%fの時，theta=%fで最大飛距離x=%fである．\n", z0, theta_flag, x_max);
        fprintf(fp, "%f %f\n", z0, theta_flag);
    }

    return 0;
}
