/*
グループ課題2

高さh から同じ初期速さv0で斜方投射するとき，角度何度に投げると飛距離を最大にできるか？

注意： h = 0 mのときは，角度45度だが，h > 0の場合は必ずしも45度とは限らない！
注意： 粘性抵抗を入れるとどうなるか？

粘性抵抗なし
グラフ描画なし

*/

#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.141592
#endif

int main(void){
    double g,dt,x0,z0,v0,θ0,θ,dθ,θ_max,vx0,vz0,vz,x,x_max,z;

    printf("高さh[m]を入力してください\n");
    scanf("%lf",&z0);

    g=-9.8;//重力加速度

    dt=1.0/100;

    x0=0.0;  //x軸方向初期位置


    v0=5.0;  //v0を初期速さとする

    θ0=0;
    dθ=1.0/1.0;
    θ=θ0;  //角度をdegreeで指定


    while(θ < 90){
        int count=0;
        θ=θ+dθ;
        printf("角度%fの時 ",θ);
        vx0=5.0*cos(M_PI*θ/180);
        vz0=5.0*sin(M_PI*θ/180);
        printf("vx0=%f vz0=%f ",vx0,vz0);

        vz=vz0;
        z=z0;
        do {
            vz=vz+(g*dt);
            z=z+vz*dt;
            count += 1;
        } while (z >= 0);

    x=x0+vx0*dt*count;
    printf("%d回でx=%f\n",count,x);

    while(x_max < x){
        θ_max=θ;
        x_max=x;
    }
    
    }

    printf("高さが%.2fの時，",z0);
    printf("角度%.1f°の時に最大飛距離%fを記録しました\n",θ_max,x_max);
    

    return 0;
}