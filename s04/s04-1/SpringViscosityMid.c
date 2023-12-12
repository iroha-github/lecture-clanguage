#include <stdio.h>

const double m=3.0;// 質量 kg
const double k=50; // ばね定数 N/m
const double b=1; // 粘性抵抗係数 b  = kg/s 
//const double g=9.8;// 重力加速度 9.8 m/s^2

double f(double x, double vx){
    return -k*x - b*vx;
}

int main(){

    double t,x,vx,t0,t1,x0,vx0,dt,xx,ddt,k1,k2;
    int i,numi,nump;

    t0=0; //初期時刻
    t1=5; //終了時刻

    x0=3; //初期位置
    vx0=0; //初期速度

    dt=0.1;
    numi=(t1-t0)/dt;

    t=t0;
    x=x0;
    vx=vx0;

    FILE *gp;
    gp=popen("gnuplot --persist -slow","w"); //gnuplotの呼び出し
    FILE *fp;
    fp=fopen("SpringViscosityMid.dat","w"); //datファイルの作成


    for(i=1; i<=numi; i++){
        printf("%f %f\n",t,x);
        fprintf(fp, "%f %f\n",t,x); //datファイルに書き込み

        k1=x+(dt/2)*vx;   // 現在のxにdt/2だけ進んだときの位置
        k2=vx+(dt/2)*f(x,vx)/m;  // 現在のvxにdt/2だけ進んだときの速度
                                 // 与えられた位置と速度に対する加速度を計算する関数fを用いる
        x=x+dt*k2;          //新しい位置xを計算する
                            //傾きk2にステップサイズdtをかけてxに足す
        vx=vx+dt*f(k1,k2)/m;//新しい速度vxを計算する
                            //位置k1と速度k2から加速度を計算
                            //ステップサイズdtをかけてvxに足す
        t=t+dt;
    }

    fclose(fp);
    fprintf(gp, "plot \"SpringViscosityMid.dat\" with lines\n"); //gnuplotでdatファイルをプロット
    fflush(gp);
    pclose(gp);

}