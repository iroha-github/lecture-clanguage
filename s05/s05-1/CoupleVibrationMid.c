/*
個人課題5-1（必須） 二自由度連成振動のシミュレーション

＊１） 時間刻み幅 ⊿tを様々に変え，厳密解，オイラー法，中点法と比較せよ
＊２） *1)で十分小さいと判断される⊿tを用いて，中点法でモード１，モード２の運動を再現すること，
また，乱数を用いた様々な初期条件でシミュレーションをすること
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

    srand((unsigned)time(NULL));

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
    x0=2*(rand()/(double)RAND_MAX)-0.5;
    y0=2*(rand()/(double)RAND_MAX)-0.5;
    vx0=2*(rand()/(double)RAND_MAX)-0.5;
    vy0=2*(rand()/(double)RAND_MAX)-0.5;

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

    ddt = 0.1;
    nump = ddt/dt;

    for(i=0; i<numi; i++){
        if(i%nump==0){
            fprintf(fp,"%f %f %f\n",t,x,y);
            printf("%f %f %f\n",t,x,y);
        }
        kx=x+(dt/2)*vx;
        ky=y+(dt/2)*vy;
        kvx=vx+(dt/2)*fx(x,y)/m;
        kvy=vy+(dt/2)*fy(x,y)/m;
        x=x+dt*kvx;
        y=y+dt*kvy;
        vx=vx+dt*fx(kx,ky)/m;
        vy=vy+dt*fy(kx,ky)/m;
        t=t+dt;
    }
    fflush(fp);
    fclose(fp);

    fprintf(gp,"plot \"CoupledVibrationMid.dat\" u 1:2 w l title \"x(t)\", \"CoupledVibrationMid.dat\" u 1:3 w l title \"y(t)\"\n");
    fprintf(gp,"replot\n");
    pclose(gp);
}