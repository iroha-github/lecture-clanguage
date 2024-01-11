#include <stdio.h>
#include <math.h>

// シミュレーションパラメータ
const double l = 1.0;  // 振り子の長さ
const double g = 9.8;  // 重力加速度

// 微分方程式
double differential_equations(double theta1, double omega1, double theta2, double omega2,
                            double *dtheta1, double *domega1, double *dtheta2, double *domega2) {
    *dtheta1 = omega1;                          // theta1の計算
    *domega1 = ((theta2 - 2 * theta1) * g) / l; // omega1の計算
    *dtheta2 = omega2;                          // theta2の計算
    *domega2 = (2 * (theta1 - theta2) * g) / l; // omega2の計算
}

int main() {
    double w0, w_M, w_P;
    double theta1_0, theta2_0, omega1_0, omega2_0;
    double t0, t1, dt, ddt, t;
    double theta1, theta2, omega1, omega2;
    double k1_theta1, k1_omega1, k2_theta1, k2_omega1;
    double k1_theta2, k1_omega2, k2_theta2, k2_omega2;
    double dtheta1, domega1, dtheta2, domega2;
    int numi, nump, i;

    w0 = sqrt(l / g);
    w_M = sqrt(2 - sqrt(2)) * w0;
    w_P = sqrt(2 + sqrt(2)) * w0;

    theta1_0 = 0.03;
    theta2_0 = -sqrt(2) * theta1_0;
    omega1_0 = 0;
    omega2_0 = 0;

    t0 = 0;
    t1 = 20.0;
    theta1 = theta1_0;
    theta2 = theta2_0;
    omega1 = omega1_0;
    omega2 = omega2_0;

    dt = 0.001;
    numi = (t1 - t0) / dt;

    ddt = 0.5;
    nump = (t1 - t0) / ddt;

    FILE *fp;
    fp = fopen("data1.dat", "w");

    for (i = 1; i <= numi; i++) {
        if (i % nump == 0) {
            printf("%f %f %f %f %f\n", t, theta1, theta2, omega1, omega2);
            fprintf(fp, "%f %f %f %f %f\n", t, theta1, theta2, omega1, omega2);
        }

        // 中点法
        differential_equations(theta1, omega1, theta2, omega2, &dtheta1, &domega1, &dtheta2, &domega2);

        double k1_theta1 = dt * dtheta1;
        double k1_omega1 = dt * domega1;
        double k1_theta2 = dt * dtheta2;
        double k1_omega2 = dt * domega2;

        differential_equations(theta1 + k1_theta1/2.0, omega1 + k1_omega1/2.0, theta2 + k1_theta2/2.0, omega2 + k1_omega2/2.0, &dtheta1, &domega1, &dtheta2, &domega2);

        double k2_theta1 = dt * dtheta1;
        double k2_omega1 = dt * domega1;
        double k2_theta2 = dt * dtheta2;
        double k2_omega2 = dt * domega2;

        theta1 = theta1 + k2_theta1;
        omega1 = omega1 + k2_omega1;
        theta2 = theta2 + k2_theta2;
        omega2 = omega2 + k2_omega2;
        
        t = t + dt;
    }
    fflush(fp);
    fclose(fp);
    
    FILE *gp;
    gp = popen("gnuplot -persist", "w");
    fprintf(gp, "plot \"data1.dat\" u 1:2 w l title \"theta 1\", \"data1.dat\" u 1:3 w l title \"theta 2\"\n");
    fflush(gp);
    fclose(gp);

    return 0;
}
