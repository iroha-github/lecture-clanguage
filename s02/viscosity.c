#include <stdio.h>
#include <math.h>

//粘性抵抗中の自由落下の厳密解
// vz(t) = mg/g (1-exp(-bt/m))
// 厳密解verion

int main(){

    int nump;
    double vz,m,g,b,t,t0,t1,dt,vf;

    g=9.8; //重力加速度 9.8 m/s^2
    m=3.0; //質量 kg
    b=2.5; //粘性抵抗係数 kg/s ←b*(m/s) = N kg m/s^2 

    // 時刻 t0からt1までのプロット
    t0=0;
    t1=10.0;

    nump=100;
    dt=(t1-t0)/nump; //dt=(10.0-0)/100=0.1
    vf=m*g/b;        //終端速度を設定

    t=t0; //初期時刻t=t0=0代入
    vz=0; //初期速度代入

    //------------------------------------
    FILE *gp; //gnuplot用のFILEポインタ
    gp = popen("gnuplot -persist", "w");
    FILE *fp;  // データ出力用のFILEポイン
    fp = fopen("viscosity.dat", "w");
    
    //------------------------------------
    for(int i=1; i<=nump+1; i++){
        fprintf(fp, "%f %f %f\n", t, vz, vf);
        t =t+dt;
        vz = (m*g/b)*(1-exp(-b*t/m)); //時刻tにおける速度
    }

    fclose(fp);

    //------------------------------------
    fprintf(gp, "plot \"viscosity.dat\" using 1:2 w l title \"Ringorous Sol.\" ,\
                      \"viscosity.dat\" using 1:3 w l title \"Terminal Velocity\"\n");
    fprintf(gp, "set yrange[0:14] \n");
    fprintf(gp, "replot \n");
    fflush(gp);
    //------------------------------------

    pclose(gp);
    return 0;
    
}