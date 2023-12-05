#include <stdio.h>
/* 斜方投射のオイラー法

dx/dt = vx ⇔ x(d+dt) = x(t) + dt*vx
dz/dt = vz
m dvx/dt = 0 ⇔ vx(d+dt) = vx(t) + dt*0
m dvz/dt = -g ⇔ vx(d+dt) = vx(t) + dt*(-g)

*/

int main(){

    double g,x0,z0,vx0,vz0,t1,t0,dt,x,z,vx,vz;
    int numi;

    g=9.8; //重力加速度

    t0=0;  //初めの時刻
    t1=3.0;  //終わりの時刻

    x0=0;  //x方向初期位置
    z0=0;  //z方向初期位置
    vx0=2.0;  //x方向初期速度
    vz0=3.0;  //z方向初期速度

    dt=0.1;  //刻み幅を0.1とする
    numi=(t1-t0)/dt;  // (3.0-0.0)/0.1=30

    x=x0;
    z=z0;
    vx=vx0;
    vz=vz0;

    //------------------------------------
    FILE *gp;
    gp = popen("gnuplot -persist", "w");
    FILE *fp;
    fp = fopen("projective_motion.dat", "w");
    //------------------------------------

    for(int i=1; i<=numi; i++){
        fprintf(fp, "%f %f\n",x ,z);
        //放物運動の計算を実行
        x=x+dt*vx;
        z=z+dt*vz;
        vx=vx+dt*0;
        vz=vz+dt*(-g);
    }

    fclose(fp);

    fprintf(gp, "plot \"projective_motion.dat\" w l pt 7 ps 0.5 title \"Euler dt=0.1\" \n"); //\nを忘れないように注意する
    fprintf(gp, "replot \n");
    fflush(gp);

    pclose(gp);
    return 0;
}