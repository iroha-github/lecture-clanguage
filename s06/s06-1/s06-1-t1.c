#include<stdio.h>
#include<math.h>

const double g=9.8;// 重力加速度
const double m=10;// 質量 kg
const double l=1;// ひもの自然長

//　θ1,θ2という質点について考える
double fθ1(double m,double l,double θ1,double θ2,double w1,double w2){
    return (m*l*l*sin(θ1-θ2)*cos(θ1-θ2)*w1*w1-m*l*l*sin(θ1-θ2)*w2*w2+(m*sin(θ2)*cos(θ1-θ2)-2*m*sin(θ1))*l*g)/(l*l*(2*m-m*cos(θ1-θ2)*cos(θ1-θ2)));  //θ1に働く力
}

int main(){

    int numi,nump,i;
    double t0,t1,dt,ddt,t;
    double θ10_a,θ10_b,θ1_a,θ1_b;
    double w0,wm,wp;
    double w10_a,w10_b,w1_a,w1_b;
    double kθ1_a,kθ1_b,kw1_a,kw1_b;
    double kθ2_a,kθ2_b,kw2_a,kw2_b;
    double θ1,θ2,w1,w2,kw1,kw2;

    // 時刻 t0からt1までplot
    t0=0;  //それぞれの初期条件を代入
    t1=20.0;

    //初期条件の変更
    θ10_a=0.0004;
    θ10_b=1.0;

    w10_a=2.0;
    w10_b=0.02;

    dt=0.001;  //中点法の時間刻み幅
    numi=(t1-t0)/dt;  //中点法の試行回数

    ddt=0.5;  //plotの時間刻み幅
    nump=(t1-t0)/ddt;  //plotの試行回数

    t=t0;  //それぞれの初期条件を定義
    θ1_a=θ10_a;
    θ1_b=θ10_b;
    w1_a=w10_a;
    w1_b=w10_b;

    FILE *fp;
    fp=fopen("data1.dat","w");

    for(i=1; i<=numi; i++){
        if (i % nump ==0){  //plotの時間刻み幅でplot
            printf("%f %f %f\n",t,θ1_a,θ1_b);  //時刻と質点1,2の変位
            fprintf(fp,"%f %f %f\n",t,θ1_a,θ1_b);  //ファイルに出力
        }

        kθ1_a=θ1_a+(dt/2)*w1_a;  //中点法の時間刻み幅の半分でθ1の位置をオイラー法を用いて計算
        kθ1_b=θ1_b+(dt/2)*w1_b;  //θ2の位置

        kw1_a=w1+(dt/2)*fθ1(m,l,θ1_a,θ1_b,w1_a,w1_b);  //中点法の時間刻み幅の半分でθ1の速度をオイラー法を用いて計算
        kw1_a=w2+(dt/2)*fθ1(m,l,θ1_a,θ1_b,w1_a,w1_b);  //θ2の速度

        θ1_a=θ1_a+dt*kw1;  //θ1の位置を更新
        θ1_b=θ1_b+dt*kw2;  //θ2の位置を更新

        w1_a=w1_a+dt*fθ1(m,l,kθ1_a,kθ1_b,kw1_a,kw1_b);  //θ1_aの速度を更新
        w1_b=w1_b+dt*fθ1(m,l,kθ1_a,kθ1_b,kw1_a,kw1_b);  //θ1_bの速度を更新

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