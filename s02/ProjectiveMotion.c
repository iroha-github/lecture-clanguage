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

    g=9.8;

    t0=0;
    t1=3.0;

    x0=0;
    z0=0;
    vx0=2.0;
    vz0=3.0;

    dt=0.1;
    numi=(t1-t0)/dt;

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
        x=x+dt*vx;
        z=z+dt*vz;
        vx=vx+dt*0;
        vz=vz+dt*(-g);
    }

    fclose(fp);

    fprintf(gp, "plot \"projective_motion.dat\" w p pt 7 ps 0.5 title \"Euler dt=0.1\" ");
    fprintf(gp, "replot \n");
    fflush(gp);

    pclose(gp);
    return 0;
}