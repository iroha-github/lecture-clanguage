/*
課題3-2
*/
#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double r(double x, double y){
    return sqrt(x*x+y*y);
}

double a(double){

}

int main(void){
    double k,M,m,x,y,vx,vy,x0,y0,vx0,vy0,t0,t1,t,ax,ay,xx,yy,dt,ddt,KE;
    int i,nump,numpp;
    
    k = 1.0; //係数を1.0とする(万有引力定数)
    M = 1.0; //中心物体の質量を1.0とする
    m = 1.0; //回転物体の質量を1.0とする

    //---------------------------------//
    x0 = 1.0; //初期位置x0を1.0とする
    y0 = 0.0; //初期位置y0を0.0とする

    vx0 = 0.0; //初速度vx0を0.0とする
    vy0 = 1.0; //初速度vy0を1.0とする

    x = x0; //初期位置xをx0とする
    y = y0; //初期位置yをy0とする

    vx = vx0; //初速度vxをvx0とする
    vy = vy0; //初速度vyをvy0とする
    //---------------------------------//

    //---------------------------------//

    //---------------------------------//


    t0 = 0.0; //初期時刻t0を0.0とする
    t1 = 2.0*M_PI; //終了時刻t1を2πとする

    nump = 10000; //分割数を10000とする
    dt = (t1-t0)/nump; //時間刻み幅dtを計算する

    numpp = 100; //分割数100とする(dataファイルへの出力用)
    ddt = (t1-t0)/numpp; //時間刻み幅ddtを計算する

    for(int i=0; i<nump; i++){
        if(i%numpp==0){
            printf("%f %f\n",x,y);
        }
        xx=x;
        yy=y;
        x=x+vx*dt;
        y=y+vy*dt;
        vx=vx+dt*m*M*(-k*xx/pow(r(xx,yy),3))/m;
        vy=vy+dt*m*M*(-k*yy/pow(r(xx,yy),3))/m;
    }

}
