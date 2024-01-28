/*
情報処理演習Ⅱ グループ課題5-2
連星シミュレーション
*/

#include<stdio.h>
#include<math.h>

const double m1 = 1.0; // 質点1の質量
const double m2 = 2.0; // 質点2の質量
const double G = 10.0; // 描画しやすいような値にする

double r(double x1, double y1, double x2, double y2) { //質点1と質点2の距離
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

double grax(double x1, double y1, double x2, double y2) { //質点1と質点2のx方向の引力
    return G*m1*m2*(x2-x1) / (pow(r(x1, y1, x2, y2), -2)); 
}

double gray(double x1, double y1, double x2, double y2) { //質点1と質点2のy方向の引力
    return G*m1*m2*(y2-y1) / (pow(r(x1, y1, x2, y2), -2));
}

double cgx(double x1, double y1, double x2, double y2){ //重心点を表すx方向の関数
    return (m1*x1+m2*x2)/(m1+m2);
}

double cgy(double x1, double y1, double x2, double y2){ //重心点を表すy方向の関数
    return (m1*y1+m2*y2)/(m1+m2);
}

int main(){

    double t0,t1,x10,x20,vx10,vx20,y10,y20,vy10,vy20,x1,x2,vx1,vx2,y1,y2,vy1,vy2,vmax,dt;
    double k1x,k1y,k1vx,k1vy,k2x,k2y,k2vx,k2vy;
    int i,nint;

    t0 = 0.0; //初期時刻
    t1 = 30.0; //終了時刻
    
    x10 = 2.0;
    y10 = 0.0;
    vx10 = 1.0;
    vy10 = -2.0;

    x20 = -1.0;
    y20 = -1.0;
    vx20 = -1.0;
    vy20 = 1.0;

    x1 = x10;
    x2 = x20;
    y1 = y10;
    y2 = y20;

    vx1 = vx10;
    vx2 = vx20;
    vy1 = vy10;
    vy2 = vy20;

    dt = 0.0001; //中点法の時間の刻み幅
    nint = (t1-t0)/dt;

    FILE *fp;
    fp = fopen("binary_star_simulation_-3.dat", "w");

    for(i=1; i<=nint; i++){
        if(i%300 == 0){
            fprintf(fp,"%f %f %f %f %f %f\n", x1, y1, x2, y2, cgx(x1, y1, x2, y2), cgy(x1, y1, x2, y2));
        }
        k1x = x1 + dt/2*vx1;
        k1y = y1 + dt/2*vy1;
        k1vx = vx1 + dt/2*(grax(x1, y1, x2, y2))/m1;
        k1vy = vy1 + dt/2*(gray(x1, y1, x2, y2))/m1;

        k2x = x2 + dt/2*vx2;
        k2y = y2 + dt/2*vy2;
        k2vx = vx2 + dt/2*(grax(x2, y2, x1, y1))/m2;
        k2vy = vy2 + dt/2*(gray(x2, y2, x1, y1))/m2;
        
        x1 = x1 + dt*k1vx;
        y1 = y1 + dt*k1vy;
        vx1 = vx1 + dt*(grax(k1x, k1y, k2x, k2y))/m1;
        vy1 = vy1 + dt*(gray(k1x, k1y, k2x, k2y))/m1;

        x2 = x2 + dt*k2vx;
        y2 = y2 + dt*k2vy;
        vx2 = vx2 + dt*(grax(k2x, k2y, k1x, k1y))/m2;
        vy2 = vy2 + dt*(gray(k2x, k2y, k1x, k1y))/m2;
    }

    fflush(fp);
    fclose(fp);

    // 新たにgnuplotのプロセスを立ち上げるポインタを定義
    FILE *gp;
    gp = popen("gnuplot -persist", "w");

    // Gnuplotに送るコマンドを定義
    char *gnuplotscript =\
        "set terminal gif animate delay 5 optimize size 640,480\n"
        "set output \"binary_star_simulation_-3.gif\"\n"
        "set title \"binary star simulation\"\n"
        "do for [i=0:999] {\n"
        "plot [-12:2][-4:4]\"binary_star_simulation_-3.dat\" every ::i::i using 1:2 w p pt 7 ps 1 title \"Point mass 1\",\\\n"
        "                  \"binary_star_simulation_-3.dat\" every ::i::i using 3:4 w p pt 7 ps 1 title \"Point mass 2\",\\\n"
        "                  \"binary_star_simulation_-3.dat\" every ::i::i using 5:6 w p pt 7 ps 1 title \"The center of gravity\", \\\n"
        "                  \"binary_star_simulation_-3.dat\" using 1:2 w l title \"Point mass 1 with line\", \\\n"
        "                  \"binary_star_simulation_-3.dat\" using 3:4 w l title \"Point mass 2 with line\", \\\n"
        "                  \"binary_star_simulation_-3.dat\" using 5:6 w l title \"The center of gravity with line\"\n"
        "}\n"
        "unset output\n";  //明示的に終了

    // Gnuplotのプロセスにコマンドを送る
    fprintf(gp, "%s", gnuplotscript);

    // プロセスを閉じる
    pclose(gp);

    return 0;
}
