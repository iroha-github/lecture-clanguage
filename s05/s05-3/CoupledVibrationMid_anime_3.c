#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const double k = 1;  // バネ定数
const double m = 2;  // 質量 kg
const double l = 3;  // バネ自然長

/*
f_1=kx
f_2=k(y-x)
f_3=k(z-y)
f_4=k(-z)

mx''=-2kx+ky
my''=kx-2ky+kz
mz''=-2kz+ky
*/

double fx(double x, double y, double z) {
    return -2*k*x+k*y;
}

double fy(double x, double y, double z) {
    return k*x-2*k*y+k*x;
}

double fz(double x, double y, double z) {
    return -2*k*z+k*y;
}


int main() {

    srand((unsigned)time(NULL));

    double w0, w1, w2;
    double t0, t1, dt, ddt, t;
    double x, y, z, vx, vy, vz, x0, y0, z0, vx0, vy0, vz0;
    double kx, kvx, ky, kvy, kz, kvz;
    int numi, nump, i;


    t0 = 0;
    t1 = 10.0;
    x0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
    y0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
    z0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
    vx0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
    vy0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
    vz0 = 2 * (rand() / (double)RAND_MAX) - 0.5;

    dt = 0.001;
    numi = (t1 - t0) / dt;

    t = t0;
    x = x0;
    y = y0;
    z = z0;
    vx = vx0;
    vy = vy0;
    vz = vz0;

    FILE *fp;
    fp = fopen("CoupledVibrationMid_anime_3.dat", "w");

    ddt = 0.1;
    nump = ddt / dt;

    for (i = 0; i < numi; i++) {
        if (i % nump == 0) {
            fprintf(fp, "%f %f %f %f 0\n", t, x+l, y+2*l, z+3*l);
            printf("%f %f %f %f 0\n", t, x+l, y+2*l, z+3*l);
        }
		kx=x+(dt/2)*vx;
		ky=y+(dt/2)*vy;
        kz=z+(dt/2)*vz;
		kvx=vx+(dt/2)*fx(x,y,z)/m;
		kvy=vy+(dt/2)*fy(x,y,z)/m;
		kvz=vz+(dt/2)*fz(x,y,z)/m;
		x=x+dt*kvx;
		y=y+dt*kvy;
		z=z+dt*kvz;
		vx=vx+dt*fx(kx,ky,kz)/m;
		vy=vy+dt*fy(kx,ky,kz)/m;
		vz=vz+dt*fz(kx,ky,kz)/m;
		t=t+dt;
    }

    fflush(fp);
    fclose(fp);

	// 新たにgnuplotのプロセスを立ち上げるポインタを定義
    FILE *gp;
    gp = popen("gnuplot -persist", "w");

    // Gnuplotのコマンドを送る
    const char *gnuplotScript =\
		"set terminal gif animate delay 5 optimize size 640,480\n"
		"set output 'CoupledVibrationMid_anime_3.gif'\n"
		"do for [i=0:99] {\n"
		"  plot [0:13][-1:1] \"CoupledVibrationMid_anime_3.dat\" every ::i::i using 2:5 w p pt 7 ps 1, \\\n"
		"                    \"CoupledVibrationMid_anime_3.dat\" every ::i::i using 3:5 w p pt 7 ps 2, \\\n"
		"                    \"CoupledVibrationMid_anime_3.dat\" every ::i::i using 4:5 w p pt 7 ps 3\n"
		"}\n"
		"unset output\n";

    // Gnuplotのプロセスにコマンドを送る
    fprintf(gp, "%s", gnuplotScript);

    // プロセスを閉じる
    pclose(gp);
}
