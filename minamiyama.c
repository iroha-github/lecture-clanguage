#include <stdio.h>

int main(void){

    double m,k,b,t,x,vx,t0,t1,x0,vx0,dt,xx,ddt;
    int numi,i,nump;

    m=2;    //質量
    k=50;    //ばね定数
    b=0;    //粘性抵抗係数

    t0=0;   //0からスタート
    t1=5;

    x0=3;   //初期条件3から
    vx0=0;

    dt=0.0001; //刻み幅　
    numi=(t1-t0)/dt;

    ddt=0.01;    //plotする時間間隔
    nump=ddt/dt;    //nump毎にplot

    //初期の値
    t=t0;
    x=x0;
    vx=vx0;

    for(i=1;i<=numi;i++){
        if(i%nump==0){
        printf("%f %f\n",t,x);
        }
        xx=x;
        x=x+dt*vx;
        vx=vx+dt*(-k*xx-b*vx)/m;
        t=t+dt;
    }

    return 0;

}