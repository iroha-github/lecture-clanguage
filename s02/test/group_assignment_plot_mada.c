#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.141592
#endif

int main(void){
    double g,dt,x0,z0,v0,theta0,theta,dtheta,vx0,vz0,vz,x,z;

    g=-9.8; //重力加速度
    dt=0.01; //時間刻み
    x0=0.0; //x座標初期位置
    z0=0.0; //z座標初期位置

    v0=1.0;  //v0を初期速さとする

    theta0=0;
    dtheta=1.0;
    theta=theta0; //角度をdegreeで指定

    for(z=z0; z<10.0; z+=1.0){
        int count=0;
        int count_max=0;
        double z_temp=z;
        for(theta=0; theta<90; theta+=1){
            vx0=v0*cos(M_PI*theta/180);
            vz0=v0*sin(M_PI*theta/180);
            
            vz=vz0;
            count=1;
            do{
                vz=vz+(g*dt);
                z_temp=z_temp+vz*dt;
                count+=1;
            }while(z_temp>=0);

            count_max = count_max<count ? count : count_max;

        }
        x = x0 + vx0 * dt * count;  // xの値を計算
        printf("高さ%.2fの時，%.3f°で最大飛距離x=%f\n",z,theta,x);
    }

    return 0;
}