/*課題3-1 粘性抵抗中振動*/
/*
ｂの粘性抵抗係数を変えて
ｂ＝３ 減衰振動
ｂ＝２０ 臨界減衰
ｂ＝６０ 過減衰
*/

#include <stdio.h>
#include <math.h>

int main(){
    double m, k, b, t, x, xx, vx, t0, t1, x0, vx0, dt, ddt;
    int num_i, num_p;

    m=2; //質量
    k=50; //ばね定数
    b=60; //粘性抵抗係数

    t0=0; //初期時間
    t1=10; //この時間まで測定する

    x0 = 3;
    vx = 0;
    vx0 = 0;

    dt=0.001; //時間の刻み幅
    num_i=(t1-t0)/dt; //繰り返し回数の指定

    ddt = 0.1; //plotする時間間隔
    num_p = ddt/dt; //num_p毎にplotする

    t=t0;   //tの初期条件
    x=x0;   //x
    vx=vx0; //vx

    // FILE *gp;
    // gp = popen("gnuplot --persist");
    // FILE *fp;
    // fp = fopen("SpringViscosity.dat", "w")
    

    for(int i=1;i<=num_i+0.01;i++){
        if(i%num_p==0){  //iがnum_pで割り切れるとき
            printf("%f %f\n", t, x); //横軸にt,縦軸にx
        }

        xx = x; //xxは仮変数
        x = x + dt*vx;                 //xの更新
        vx = vx +dt*(-k*xx - b*vx)/m;  //vxの更新
        t = t+dt;                     //tの更新
    }
}

//plotする時間間隔