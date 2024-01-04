/*
個人課題5-1
厳密解
*/

#include<stdio.h>
#include<math.h>

const double k=1;// バネ定数
const double m=2;// 質量 kg
const double l=3;// バネ自然長
	
int main(){

	int nump,i;
	double t0,t1,dt,t;
	double x,y,vx,vy,x0,y0,vx0,vy0;
	double C1,C2,D1,D2,phi1,phi2,w0,w1,w2;

	w0=sqrt(k/m);
	w1=w0;
	w2=sqrt(3)*w0;

	// 時刻 t0からt1までplot
	t0=0;
	t1=20.0;
	x0=1;
	y0=1.5;
	vx0=1;
	vy0=0;

	C1=(x0+y0)/2;
	C2=(x0-y0)/2;
	D1=(vx0+vy0)/(2*w1);
	D2=(vx0-vy0)/(2*w2);
	// 初期条件との関係は下記動画参照
	//https://web.microsoftstream.com/video/60564ed9-a0e2-4862-85ce-d6fcab56bfbe


	nump=100;
	dt=(t1-t0)/nump;
	t=t0;
	x=C1*cos(w1*t)+D1*sin(w1*t)+C2*cos(w2*t)+D2*sin(w2*t);
	y=C1*cos(w1*t)+D1*sin(w1*t)-C2*cos(w2*t)-D2*sin(w2*t);

	FILE *gp;
	gp=popen("gnuplot -persist -slow","w");
	FILE *fp;
	fp=fopen("CoupledVibrationRig_dist.dat","w");
	
	
	for(i=1;i<=nump;i++){
		printf("%f %f %f\n",t,x,y);
		fprintf(fp,"%f %f %f\n",t,x,y);
		t=t+dt;
		x=C1*cos(w1*t)+D1*sin(w1*t)+C2*cos(w2*t)+D2*sin(w2*t);
	 	y=C1*cos(w1*t)+D1*sin(w1*t)-C2*cos(w2*t)-D2*sin(w2*t);
	}
	fclose(fp);
	fprintf(gp,"set xlabel \"t\"\n");
	fprintf(gp,"set ylabel \"x,y\"\n");
	fprintf(gp,"plot \
    \"CoupledVibrationRig_dist.dat\" u 1:2 w l,\
    \"CoupledVibrationRig_dist.dat\" u 1:3 w l\n");
	pclose(gp);
	return 0;
	
}
