/*
個人課題5-1
中点法
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
    double kx,kvx,ky,kvy;
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
    fp=fopen("CoupledVibrationMid.dat","w");

    ddt = 0.1; // 0.1秒ごとの結果をプロットする
    nump = ddt/dt; //プロット回数を制限するための変数

    for(i=0; i<numi; i++){
        if(i%nump == 0){
            fprintf(fp,"%f %f %f\n",t,x,y);
            printf("%f %f %f\n",t,x,y);
        }

        kx=x+(dt/2)*vx; //中点法を行うためにdt/2だけ進めた値でkxを仮置きする
        ky=y+(dt/2)*vy; //中点法を行うためにdt/2だけ進めた値でkyを仮置きする
        kvx=vx+(dt/2)*fx(x,y)/m; //中点法を行うために値をkvx仮置きする
        kvy=vy+(dt/2)*fy(x,y)/m; //中点法を行うために値をkvy仮置きする
        x=x+dt*kvx; //仮置きされた値を用いてxを更新する
        y=y+dt*kvy; //仮置きされた値を用いてxを更新する
        vx=vx+dt*fx(kx,ky)/m; //仮置きされた値を用いてvxを更新する
        vy=vy+dt*fy(kx,ky)/m; //仮置きされた値を用いてvyを更新する
        t=t+dt;
    }
    fflush(fp);
    fclose(fp);

    fprintf(gp,"set xlabel \"t\"\n");
    fprintf(gp,"set ylabel \"x,y\"\n");
    fprintf(gp,"plot \
    \"CoupledVibrationMid.dat\" u 1:2 w l title \"x(t)\", \
    \"CoupledVibrationMid.dat\" u 1:3 w l title \"y(t)\"\n");
    pclose(gp);
}