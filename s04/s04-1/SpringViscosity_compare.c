/*
課題4-1
オイラー法と中点法の比較
dt=0.1
*/
#include <stdio.h>

const double m=3.0;// 質量 kg
const double k=50; // ばね定数 N/m
const double b=1; // 粘性抵抗係数 b  = kg/s 
//const double g=9.8;// 重力加速度 9.8 m/s^2

double f(double x, double vx){
    return -k*x - b*vx;
}

int main(){

    double t,x,vx,t0,t1,x0,vx0,dt,xx,ddt,k1,k2;
    int i,numi,nump;

    t0=0;
    t1=5;

    x0=3;
    vx0=0;

    dt=0.0001;
    numi=(t1-t0)/dt;

    t=t0;
    x=x0;
    vx=vx0;

    FILE *gp;
    gp = popen("gnuplot --persist -slow","w");
    FILE *fp1;
    fp1 = fopen("SpringViscosity_euler.dat","w");
    FILE *fp2;
    fp2 = fopen("SpringViscosity_midpoint.dat","w");



    for(i=1; i<=numi; i++){
        printf("%f %f\n",t,x);
        fprintf(fp1, "%f %f\n",t,x);

        k1=x+(dt/2)*vx;
        k2=vx+(dt/2)*f(x,vx)/m;
        x=x+dt*k2;
        vx=vx+dt*f(k1,k2)/m;

        t=t+dt;
    }

    t=t0;
    x=x0;
    vx=vx0;

    for(i=1; i<=numi; i++){
        printf("%f %f\n",t,x);
        fprintf(fp2, "%f %f\n",t,x);
        xx=x;
        x=x+dt*vx;
        vx=vx+dt*f(xx,vx)/m;
        t=t+dt;
    }


    fclose(fp1);
    fclose(fp2);
    fprintf(gp, "plot \"SpringViscosity_euler.dat\" with lines, \
                      \"SpringViscosity_midpoint.dat\" with lines\n");
    fprintf(gp, "set xlabel \"t\"\n");
    fprintf(gp, "set ylabel \"x\"\n");
    fprintf(gp, "set title \"Euler method and Midpoint method dt=%.4f\"\n", dt);
    fprintf(gp, "replot\n");
    fflush(gp);
    pclose(gp);

}