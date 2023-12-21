/*
課題3-2
*/
#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double r(double x, double y, double z){
    return sqrt(x*x+y*y+z*z);
}


int main(void){
    double k,M,m,x,y,z,vx,vy,vz,x0,y0,z0,vx0,vy0,vz0,t0,t1,t,ax,ay,az,xx,yy,zz,dt,ddt,KE;
    int i,nump,numpp;
    
    k = 1.0; //係数を1.0とする(万有引力定数)
    M = 1.0; //中心物体の質量を1.0とする
    m = 1.0; //回転物体の質量を1.0とする

    //---------------------------------//
    x0 = 1.0; //初期位置x0を1.0とする
    y0 = 0.0; //初期位置y0を0.0とする
    z0 = 0.0; //初期位置z0を0.1とする

    vx0 = 0.0; //初速度vx0を0.0とする
    vy0 = 1.0; //初速度vy0を1.0とする
    vz0 = 0.0; //初速度vz0を0.0とする

    x = x0; //初期位置xをx0とする
    y = y0; //初期位置yをy0とする
    z = z0; //初期位置zをz0とする

    vx = vx0; //初速度vxをvx0とする
    vy = vy0; //初速度vyをvy0とする
    vz = vz0; //初速度vzをvz0とする
    //---------------------------------//

    //---------------------------------//
    FILE *gp;
    gp = popen("gnuplot --persist -slow", "w"); 
    //popen は "process open" の略で、子プロセスを開くことを目的
    //FILE *popen(const char *command, const char *mode);

    FILE *fp;
    fp = fopen("UniversalGravity.dat", "w");
    //---------------------------------//


    t0 = 0.0; //初期時刻t0を0.0とする
    t1 = 10; //終了時刻t1とする

    nump = 10000; //分割数を10000とする
    dt = (t1-t0)/nump; //時間刻み幅dtを計算する

    numpp = 100; //分割数100とする(dataファイルへの出力用)
    ddt = (t1-t0)/numpp; //時間刻み幅ddtを計算する

    for(int i=0; i<nump; i++){
        if(i%numpp==0){
            printf("%f %f %f\n",x,y,z);
            fprintf(fp, "%f %f %f\n", x,y,z);
        }
        xx=x; 
        yy=y; 
        zz=z; 
        x=x+vx*dt; //x座標を設定
        y=y+vy*dt; //y座標を設定
        z=z+vz*dt; //z座標を設定
        vx=vx+dt*m*M*(-k*xx/pow(r(xx,yy,zz),3))/m; //質量にmとMを設定
        vy=vy+dt*m*M*(-k*yy/pow(r(xx,yy,zz),3))/m;
        vz=vz+dt*m*M*(-k*zz/pow(r(xx,yy,zz),3))/m;
    }
    fclose(fp);

    fprintf(gp, "splot 'UniversalGravity.dat' w l \n");
    fprintf(gp, "set title \"UniversalGravity Simulation vx0=%.2f vy0=%.2f vz0=%.2f\"\n", vx0, vy0, vz0);
    fprintf(gp, "set size square\n");
    fprintf(gp, "replot \n");
    fflush(gp);
    pclose(gp);

    return 0;

}
