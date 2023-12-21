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

double v(double vx0, double vy0, double vz0){
    return sqrt(vx0*vx0+vy0*vy0+vz0*vz0);

}

int main(void){
    double k,M,m,x,y,z,vx,vy,vz,x0,y0,z0,vx0,vy0,vz0,t0,t1,t,ax,ay,az,xx,yy,zz,dt,ddt,KE;
    int i,nump,numpp;
    
    k = 1.0; //係数を1.0とする(万有引力定数)
    M = 1.0; //中心物体の質量を1.0とする
    m = 1.0; //回転物体の質量を1.0とする

    //---------------------------------//
    x0 = 1.0; //初期位置x0を1.0とする
    y0 = 0.0; //初期位置y0を0.0とする
    z0 = 0.0; //初期位置z0を0.1とする

    vx0 = 0.0; //初速度vx0を0.0とする
    vy0 = 1.0; //初速度vy0を1.0とする
    vz0 = 0.0; //初速度vz0を0.0とする

    x = x0; //初期位置xをx0とする
    y = y0; //初期位置yをy0とする
    z = z0; //初期位置zをz0とする

    vx = vx0; //初速度vxをvx0とする
    vy = vy0; //初速度vyをvy0とする
    vz = vz0; //初速度vzをvz0とする
    //---------------------------------//


    for(int i=100; i<200; i++){
        vy0 = i*0.01;
        KE = m*pow(v(vx0, vy0, vz0), 2)/2-k/r(x0, y0, z0);

        if(KE<0){
            printf("vy0 = %f ", vy0);
            printf("楕円軌道\n");
        } else if(KE=0){
            printf("vy0 = %f ", vy0);
            printf("放物軌道\n");
        } else {
            printf("vy0 = %f ", vy0);
            printf("双曲軌道\n");
        }
    }
}
