#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const double k = 1;  // バネ定数
const double m = 2;  // 質量 kg
const double l = 3;  // バネ自然長

double fu1(double u1, double u2, double u3) {
    return -2*k*u1+k*u2;
}

double fu2(double u1, double u2, double u3) {
    return k*u1-2*k*u2+k*u3;
}

double fu3(double u1, double u2, double u3) {
    return -2*k*u3+k*u2;
}

int main() {

    srand((unsigned)time(NULL));

    double w0, w1, w2, w3;
    double t0, t1, dt, ddt, t;
    double u1, u2, u3, vu1, vu2, vu3, u1_0, u2_0, u3_0, vu1_0, vu2_0, vu3_0;
    double ku1, kvu1, ku2, kvu2, ku3, kvu3;
    int numi, nump, i;

    double A1, A2, A3, B1, B2, B3, C1, C2, C3, phi1, phi2, phi3;

    w0 = sqrt(k/m);
    w1 = sqrt(2-sqrt(2))*w0;
    w2 = sqrt(2)*w0;
    w3 = sqrt(2+sqrt(2))*w0;
    
    int j;
    for(j = 1; j<4; j++){

    if(j==1){
        A1 = 1;
        A2 = 0;
        A3 = 0;
        B1 = sqrt(2);
        B2 = 0;
        B3 = 0;
        C1 = 1;
        C2 = 0;
        C3 = 0;
        phi1 = 0;
        phi2 = 0;
        phi3 = 0;
    } else if(j==2){
        A1 = 0;
        A2 = 1;
        A3 = 0;
        B1 = 0;
        B2 = 0;
        B3 = 0;
        C1 = 0;
        C2 = -1;
        C3 = 0;
        phi1 = 0;
        phi2 = 0;
        phi3 = 0;
    } else {
        A1 = 0;
        A2 = 0;
        A3 = 1;
        B1 = 0;
        B2 = 0;
        B3 = -sqrt(2);
        C1 = 0;
        C2 = 0;
        C3 = 1;
        phi1 = 0;
        phi2 = 0;
        phi3 = 0;
    }

    u1_0 = A1 * cos (w1 * t + phi1) + A2 * cos (w2 * t + phi2) + A3 * cos (w3 * t + phi3);
    u2_0 = B1 * cos (w1 * t + phi1) + B2 * cos (w2 * t + phi2) + B3 * cos (w3 * t + phi3);
    u3_0 = C1 * cos (w1 * t + phi1) + C2 * cos (w2 * t + phi2) + C3 * cos (w3 * t + phi3);
    vu1_0 = -w1 * A1 * sin (w1 * t + phi1) - w2 * A2 * sin (w2 * t + phi2) - w3 * A3 * sin (w3 * t + phi3);
    vu2_0 = -w1 * B1 * sin (w1 * t + phi1) - w2 * B2 * sin (w2 * t + phi2) - w3 * B3 * sin (w3 * t + phi3);
    vu3_0 = -w1 * C1 * sin (w1 * t + phi1) - w2 * C2 * sin (w2 * t + phi2) - w3 * C3 * sin (w3 * t + phi3);
    printf("【u1_0=%.3f u2_0=%.3f u3_0=%.3f vu1_0=%.3f vu2_0=%.3f vu3_0=%.3f】\n\n", u1_0, u2_0, u3_0, vu1_0, vu2_0, vu3_0);

    t0 = 0;
    t1 = 10.0;

    dt = 0.001;
    numi = (t1 - t0) / dt;

    t = t0;
    u1 = u1_0;
    u2 = u2_0;
    u3 = u3_0;
    vu1 = vu1_0;
    vu2 = vu2_0;
    vu3 = vu3_0;
    
    FILE *fp;
    char filename[100];
    sprintf(filename, "CoupledVibrationMid_anime_3_mode%d.dat",j);
    fp = fopen(filename, "w");

    ddt = 0.1;
    nump = ddt / dt;

    for (i = 0; i < numi; i++) {
        if (i % nump == 0) {
            // fprintf(fp, "%f %f %f %f 0\n", t, u1, u2, u3);
            fprintf(fp, "%f %f %f %f %d\n", t, u1+l, u2+2*l, u3+3*l, 0);
        }

        ku1=u1+(dt/2)*vu1;
        ku2=u2+(dt/2)*vu2;
        ku3=u3+(dt/2)*vu3;
        kvu1=vu1+(dt/2)*fu1(u1,u2,u3)/m;
        kvu2=vu2+(dt/2)*fu2(u1,u2,u3)/m;
        kvu3=vu3+(dt/2)*fu3(u1,u2,u3)/m;
        u1=u1+dt*kvu1;
        u2=u2+dt*kvu2;
        u3=u3+dt*kvu3;
        vu1=vu1+dt*fu1(ku1,ku2,ku3)/m;
        vu2=vu2+dt*fu2(ku1,ku2,ku3)/m;
        vu3=vu3+dt*fu3(ku1,ku2,ku3)/m;
        t=t+dt;
    }

    fflush(fp);
    fclose(fp);

    FILE *gp;
    gp = popen("gnuplot -persist", "w");
    // Gnuplotのコマンドを送る
    const char *gnuplotScript2 =\
        "set terminal gif animate delay 5 optimize size 640,480\n"
        "set output 'CoupledVibrationMid_anime_3_mode%d.gif'\n"
        "do for [i=0:99] {\n"
        "  plot [0:12][-1:1] \"CoupledVibrationMid_anime_3_mode%d.dat\" every ::i::i using 2:5 w p pt 7 ps 1 lc rgb \"#ff0000\" title \"mass point 1\", \\\n"
        "                    \"CoupledVibrationMid_anime_3_mode%d.dat\" every ::i::i using 3:5 w p pt 7 ps 1 lc rgb \"#00ff00\" title \"mass point 2\", \\\n"
        "                    \"CoupledVibrationMid_anime_3_mode%d.dat\" every ::i::i using 4:5 w p pt 7 ps 1 lc rgb \"#0000ff\" title \"mass point 3\"\n"
        "}\n"
        "unset output\n";

    // Gnuplotのプロセスにコマンドを送る
    fprintf(gp, gnuplotScript2, j, j, j, j);
    
    // プロセスを閉じる
    pclose(gp);

    }

    return 0;
}
