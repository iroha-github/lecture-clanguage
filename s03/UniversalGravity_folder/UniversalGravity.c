/*
課題3-2
*/
#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double r(double x, double y, double z){
    return sqrt(x*x+y*y+z*z);
}

double a(double){

}

int main(void){
    double k,m,x,y,z,vx,vy,x0,y0,vx0,vy0,t0,t1,t,ax,ay,xx,yy,dt,KE;
    int i,nump,numpp;
    
    k = 1.0; //係数を1.0とする(万有引力定数)
    m = 1.0; //質量を1.0とする
    x0 = 1.0; //初期位置x0を1.0とする
    y0 = 0.0; //初期位置y0を0.0とする

    vx0 = 0.0; //初速度vx0を0.0とする
    vy0 = 1.0; //初速度vy0を1.0とする

    x = x0; //初期位置xをx0とする
    y = y0; //初期位置yをy0とする

    vx = vx0; //初速度vxをvx0とする
    vy = vy0; //初速度vyをvy0とする
    vz = vz0; //初速度vzをvz0とする


    t0 = 0.0; //初期時刻t0を0.0とする
    t1 = 2.0*M_PI; //終了時刻t1を2πとする

    nump = 10000; //分割数を10000とする
    dt = (t1-t0)/nump; //時間刻み幅dtを計算する

    numpp = 100; //分割数100とする
    ddt = (t1-t0)/numpp;

    for(double t=t0; t<t1; t+=dt){
        vx=vx+ax*dt;
        vy=vy+ay*dt;
        vz=vz+az*dt;
        x=x+vx*dt;
        y=y+vy*dt;
        z=z+vz*dt;
        ax=-k*m*x/r(x,y,z)/r(x,y,z)/r(x,y,z);
        ay=-k*m*y/r(x,y,z)/r(x,y,z)/r(x,y,z);
        az=-k*m*z/r(x,y,z)/r(x,y,z)/r(x,y,z);
        KE=0.5*m*(vx*vx+vy*vy+vz*vz);
        printf("%f %f %f %f %f %f %f %f %f %f %f\n",t,x,y,z,vx,vy,vz,ax,ay,az,KE);
        

    }

}
