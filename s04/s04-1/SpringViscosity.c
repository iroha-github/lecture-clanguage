#include <stdio.h>

const double m=3.0;// 質量 kg
const double k=50; // ばね定数 N/m
const double b=1; // 粘性抵抗係数 b  = kg/s 
//const double g=9.8;// 重力加速度 9.8 m/s^2

double f(double x, double vx){
    return -k*x - b*vx;
}

int main(){

    double t,x,vx,t0,t1,x0,vx0,dt,xx,ddt;
    int i,numi,nump;

    t0=0;
    t1=5;

    x0=3;
    vx0=0;

    dt=0.1;
    numi=(t1-t0)/dt;

    t=t0;
    x=x0;
    vx=vx0;

    FILE *gp;
    gp=popen("gnuplot --persist -slow","w");
    FILE *fp;
    fp=fopen("SpringViscosityMid.dat","w");


    for(i=1; i<=numi; i++){
        printf("%f %f\n",t,x);
        fprintf(fp, "%f %f\n",t,x);
        xx=x;
        x=x+dt*vx;
        vx=vx+dt*f(xx,vx)/m;
        t=t+dt;
    }

    fclose(fp);
    fprintf(gp, "plot \"SpringViscosityMid.dat\" with lines\n");
    fflush(gp);
    pclose(gp);

}