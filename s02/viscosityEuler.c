#include <stdio.h>
#include <math.h>

//粘性抵抗中の自由落下のオイラー法による近似
// m dvz(t)\dt = mg - b vz
// vz(t) = mg/g (1-exp(-bt/m))

int main(){

    int i, numi;
    double vz,m,g,b,t,t0,t1,dt;

    g=9.8; //重力加速度 9.8 m/s^2
    m=3.0; //質量 kg
    b=2.5; //粘性抵抗係数 kg/s ←b*(m/s) = N kg m/s^2 

    // 時刻 t0からt1までのプロット
    t0=0;
    t1=10.0;

    dt=0.1; //オイラー法の時間刻み幅
    numi=(int)(t1-t0)/dt; //オイラー法の繰り返し回数

    t=t0; //初期時刻代入
    vz=0; //初期速度代入

    //------------------------------------
    FILE *gp; //gnuplot用のFILEポインタ
    gp = popen("gnuplot -persist", "w");
    FILE *fp;  // データ出力用のFILEポイン
    fp = fopen("viscosityEuler.dat", "w");
    
    //------------------------------------
    for(int i=1; i<=numi+1; i++){
        fprintf(fp, "%f %f\n", t, vz); 
        vz = vz+dt*(g - b*vz/m); //オイラー法で近似した次の時刻のvz
        t = t + dt; //時刻の更新
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