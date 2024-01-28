#include <stdio.h>
#include <math.h>

int main (void){
    // data1.datを読み込む
    FILE *fp;
    fp = fopen("data1.dat","r");
    if(fp == NULL){
        printf("ファイルを開けませんでした\n");
        return 1;
    }

    FILE *fp2;
    fp2 = fopen("anime_data1_xy.dat","w");
    

    // data1.datの中身を表示
    double t,θ1,θ2;
    double x0,y0,x1,y1,x2,y2;
    double r=1; // ひもの長さ
    while(fscanf(fp,"%lf %lf %lf",&t,&θ1,&θ2) != EOF){
        x0 = 0;
        y0 = 0;
        x1 = r*sin(θ1);
        y1 = -r*cos(θ1);
        x2 = x1 + r*sin(θ2);
        y2 = y1 - r*cos(θ2);
        fprintf(fp2,"%f %f %f %f %f %f\n",x0, y0, x1,y1,x2,y2);
    }

    fclose(fp);
    fclose(fp2);


    FILE *gp;
    gp = popen("gnuplot -persist","w");
    fprintf(gp,"set terminal gif animate delay 5 optimize size 480,640\n");
    fprintf(gp,"set output 'anime_data1_xy.gif'\n");
    fprintf(gp,"do for [i=0: 499] {\n");
    fprintf(gp,"plot [-1:1][-3:1] \"anime_data1_xy.dat\" every ::i::i using 1:2 w lp pt 7 ps 2,\\\n");
    fprintf(gp,"                  \"anime_data1_xy.dat\" every ::i::i using 3:4 w lp pt 7 ps 2,\\\n");
    fprintf(gp,"                  \"anime_data1_xy.dat\" every ::i::i using 5:6 w lp pt 7 ps 2,\\\n");
    fprintf(gp,"}\n");
    fprintf(gp,"unset output\n");
    pclose(gp);
    return 0;
}