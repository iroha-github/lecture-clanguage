#include <stdio.h>
#include <math.h>

//粘性抵抗中の自由落下の厳密解
// vz(t) = mg/g (1-exp(-bt/m))

int main(){

    int nump;
    double vz,m,g,b,t,t0,t1,dt;

    g=9.8; //重力加速度 9.8 m/s^2
    m=3.0; //質量 kg
    b=2.5; //粘性抵抗係数 kg/s ←b*(m/s) = N kg m/s^2 

    // 時刻 t0からt1までのプロット
    t0=0;
    t1=10.0;

    nump=100;
    dt=(t1-t0)/nump;

    t=t0; //初期時刻代入
    vz=0; //初期速度代入

    for(int i=1; i<nump+1; i++){
        printf("%f %f\n",t, vz);
        t =t+dt;
        vz = (m*g/b)*(1-exp(-b*t/m)); //時刻tにおける速度
    }

}