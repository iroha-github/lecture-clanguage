#include<stdio.h>
#include<math.h>

const double g=9.8;// 重力加速度
const double m=10;// 質量 kg
const double l=1;// ひもの自然長

//　θ1,θ2という質点について考える
double fθ1(double m,double l,double θ1,double θ2,double w1,double w2){
    return (m*l*l*sin(θ1-θ2)*cos(θ1-θ2)*w1*w1-m*l*l*sin(θ1-θ2)*w2*w2+(m*sin(θ2)*cos(θ1-θ2)-2*m*sin(θ1))*l*g)/(l*l*(2*m-m*cos(θ1-θ2)*cos(θ1-θ2)));  //θ1に働く力
}
double fθ2(double m,double l,double θ1,double θ2,double w1,double w2){
    return (2*m*l*l*sin(θ1-θ2)*w1*w1+m*l*l*sin(θ1-θ2)*cos(θ1-θ2)*w2*w2+2*m*(sin(θ1)*cos(θ1-θ2)-sin(θ2))*l*g)/(l*l*(2*m-m*cos(θ1-θ2)*cos(θ1-θ2)));  //θ2に働く力
}

int main(){

    int numi,nump,i;
    double t0,t1,dt,ddt,t;
    double θ1,θ2,w1,w2,θ10,θ20,w10,w20;
    double w0,wm,wp;
    double kθ1,kw1,kθ2,kw2;

    // 時刻 t0からt1までplot
    t0=0;  //それぞれの初期条件を代入
    t1=20.0;
    //初期条件の変更
    θ10=0.03;
    θ20=-sqrt(2)*θ10;

    w10=0;
    w20=0;

    dt=0.001;  //中点法の時間刻み幅
    numi=(t1-t0)/dt;  //中点法の試行回数

    ddt=0.5;  //plotの時間刻み幅
    nump=(t1-t0)/ddt;  //plotの試行回数

    t=t0;  //それぞれの初期条件を定義
    θ1=θ10;
    θ2=θ20;
    w1=w10;
    w2=w20;

    FILE *fp;
    fp=fopen("data1.dat","w");

    for(i=1; i<=numi; i++){
        if (i % nump ==0){  //plotの時間刻み幅でplot
            printf("%f %f %f\n",t,θ1,θ2);  //時刻と質点1,2の変位
            fprintf(fp,"%f %f %f\n",t,θ1,θ2);  //ファイルに出力
        }
        kθ1=θ1+(dt/2)*w1;  //中点法の時間刻み幅の半分でθ1の位置をオイラー法を用いて計算
        kθ2=θ2+(dt/2)*w2;  //θ2の位置

        kw1=w1+(dt/2)*fθ1(m,l,θ1,θ2,w1,w2);  //中点法の時間刻み幅の半分でθ1の速度をオイラー法を用いて計算
        kw2=w2+(dt/2)*fθ2(m,l,θ1,θ2,w1,w2);  //θ2の速度

        θ1=θ1+dt*kw1;  //θ1の位置を更新
        θ2=θ2+dt*kw2;  //θ2の位置を更新

        w1=w1+dt*fθ1(m,l,kθ1,kθ2,kw1,kw2);  //θ1の速度を更新
        w2=w2+dt*fθ2(m,l,kθ1,kθ2,kw1,kw2);  //θ2の速度を更新

        t=t+dt;  //時間を更新
    }

    fflush(fp);
    fclose(fp);

    FILE *gp;
    gp=popen("gnuplot -persist -slow","w");

    fprintf(gp,"set xlabel \"t\"\n");
    fprintf(gp,"set ylabel \"θ1,θ2\"\n");
    fprintf(gp,"plot \"data1.dat\" using 1:2 with lines title \"θ1\",\"data1.dat\" using 1:3 with lines title \"θ2\"\n");
    pclose(gp);

}