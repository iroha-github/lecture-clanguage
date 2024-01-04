/*
個人課題5-1
厳密解
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const double k=1;// バネ定数
const double m=2;// 質量 kg
const double l=3;// バネ自然長

double fx(double x, double y){
    return -2*k*x+k*y;
}

double fy(double x, double y){
    return k*x-2*k*y;
}



int main(){

    double w0,w1,w2;
    double t0,t1,dt,ddt,t;
    double x,y,vx,vy,x0,y0,vx0,vy0;

    int numi,nump,i;

    w0=sqrt(k/m);
    w1=w0;
    w2=sqrt(3)*w0;

    t0=0;
    t1=20.0;
    x0=1;
    y0=1.5;
    vx0=1;
    vy0=0;

    dt=0.001;
    numi=(t1-t0)/dt;

    t=t0;
    x=x0;
    y=y0;
    vx=vx0;
    vy=vy0;

    FILE *gp;
    gp=popen("gnuplot -persist -slow","w");
    FILE *fp;
    fp=fopen("CoupledVibrationEuler.dat","w");

    ddt = 0.1; // 0.1秒ごとに結果をプロットする
    nump = ddt/dt; //プロット回数を制限するための変数

    for(i=0; i<numi; i++){
        if(i%nump == 0){
            printf("%f %f %f\n",t,x,y);
            fprintf(fp,"%f %f %f\n",t,x,y);
        }
        x=x+dt*vx;
        y=y+dt*vy;
        vx=vx+dt*fx(x,y)/m;
        vy=vy+dt*fy(x,y)/m;
        t=t+dt;
    }
    fflush(fp);
    fclose(fp);

    fprintf(gp,"set xlabel \"t\"\n");
    fprintf(gp,"set ylabel \"x,y\"\n");
    fprintf(gp,"plot \
    \"CoupledVibrationEuler.dat\" u 1:2 w l title \"x(t)\", \
    \"CoupledVibrationEuler.dat\" u 1:3 w l title \"y(t)\"\n");
    pclose(gp);
}