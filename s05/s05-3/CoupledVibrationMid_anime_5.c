/*
情報処理演習Ⅱ 個人課題5-3オプション
（多自由度連成振動のシミュレーション）
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

const double k = 1;  // バネ定数
const double m = 2;  // 質量 kg
const double l = 3;  // バネ自然長



double fx(double x, double y, double z, double w, double v) {
	return -2*k*x+k*y;
}

double fy(double x, double y, double z, double w, double v) {
	return k*x-2*k*y+k*x;
}

double fz(double x, double y, double z, double w, double v) {
	return -2*k*z+k*y+k*w;
}

double fw(double x, double y, double z, double w, double v) {
	return  -2*k*w+k*z+k*v;
}

double fv(double x, double y, double z, double w, double v) {
	return -2*k*v+k*w;
}


int main() {

	srand((unsigned)time(NULL));

	// double w0, w1, w2;
	double t0, t1, dt, ddt, t;
	double x, y, z, w, v, vx, vy, vz, vw, vv, x0, y0, z0, w0, v0, vx0, vy0, vz0, vw0, vv0;
	double kx, kvx, ky, kvy, kz, kvz, kw, kvw, kv, kvv;
	int numi, nump, i;


	t0 = 0;
	t1 = 10.0;

	x0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
	y0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
	z0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
	w0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
	v0 = 2 * (rand() / (double)RAND_MAX) - 0.5;

	vx0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
	vy0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
	vz0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
	vw0 = 2 * (rand() / (double)RAND_MAX) - 0.5;
	vv0 = 2 * (rand() / (double)RAND_MAX) - 0.5;

	dt = 0.001;
	numi = (t1 - t0) / dt;

	t = t0;
	x = x0;
	y = y0;
	z = z0;
	w = w0;
	v = v0;

	vx = vx0;
	vy = vy0;
	vz = vz0;
	vw = vw0;
	vv = vv0;

	FILE *fp;
	fp = fopen("CoupledVibrationMid_anime_5.dat", "w");

	ddt = 0.1;
	nump = ddt / dt;

	for (i = 0; i < numi; i++) {
		if (i % nump == 0) {
			fprintf(fp, "%f %f %f %f %f %f 0\n", t, x+l, y+2*l, z+3*l, w+4*l, v+5*l);
			printf("%f %f %f %f %f %f 0\n", t, x+l, y+2*l, z+3*l, w+4*l, v+5*l);
		}
		kx=x+(dt/2)*vx;
		ky=y+(dt/2)*vy;
		kz=z+(dt/2)*vz;
		kw=w+(dt/2)*vw;
		kv=v+(dt/2)*vv;

		kvx=vx+(dt/2)*fx(x,y,z,v,w)/m;
		kvy=vy+(dt/2)*fy(x,y,z,v,w)/m;
		kvz=vz+(dt/2)*fz(x,y,z,v,w)/m;
		kvw=vw+(dt/2)*fw(x,y,z,v,w)/m;
		kvv=vv+(dt/2)*fv(x,y,z,v,w)/m;

		x=x+dt*kvx;
		y=y+dt*kvy;
		z=z+dt*kvz;
		w=w+dt*kvw;
		v=v+dt*kvv;

		vx=vx+dt*fx(kx,ky,kz,kw,kv)/m;
		vy=vy+dt*fy(kx,ky,kz,kw,kv)/m;
		vz=vz+dt*fz(kx,ky,kz,kw,kv)/m;
		vw=vw+dt*fw(kx,ky,kz,kw,kv)/m;
		vv=vv+dt*fv(kx,ky,kz,kw,kv)/m;

		t=t+dt;
	}

	fflush(fp);
	fclose(fp);

	// 新たにgnuplotのプロセスを立ち上げるポインタを定義
	FILE *gp;
	gp = popen("gnuplot -persist", "w");

	// Gnuplot script
	// const char *gnuplotScript =でgpポインタに渡す文字列を定義
	// この文字列はgnuplotのコマンドと同じ
	// ここでは、
	// 1. gifアニメーションを作成するための設定
	// 2. データファイルをプロットするための設定
	// 3. データファイルをプロットするためのコマンド
	// 4. gifを作成するためのコマンド

	/*
	逐一ポインタから渡すのは面倒であるし，コードが読みにくくなる．
	1. datファイルに必要なデータを書き出す
		この時，1次元上で描画するために，x軸方向のみのデータを入れる．
		そのため，y軸は0としたいので，datファイルの時点で0を入れる．
	2. gnuplotのコマンドを文字列として定義しておく．
		この時，datファイルのデータをプロットするために，datファイルの名前を指定する．
	3. gnuplotのコマンドをポインタに渡す．
	この流れでアニメーションを作成する．
	*/


	const char *gnuplotscript =\
        "set terminal gif animate delay 5 optimize size 640,480\n"
		"set output 'CoupledVibrationMid_anime_5.gif'\n"
		"set title 'CoupledVibrationMid gif animation 5 degrees of freedom'\n"
		"do for [i=0:99] {\n"
		"  plot [0:18][-1:1] \"CoupledVibrationMid_anime_5.dat\" every ::i::i using 2:7 w p pt 7 ps 1 lc rgb \"#ff0000\", \\\n"
		"                    \"CoupledVibrationMid_anime_5.dat\" every ::i::i using 3:7 w p pt 7 ps 1 lc rgb \"#ff6600\", \\\n"
		"                    \"CoupledVibrationMid_anime_5.dat\" every ::i::i using 4:7 w p pt 7 ps 1 lc rgb \"#008000\", \\\n"
		"                    \"CoupledVibrationMid_anime_5.dat\" every ::i::i using 5:7 w p pt 7 ps 1 lc rgb \"#3366ff\", \\\n"
		"                    \"CoupledVibrationMid_anime_5.dat\" every ::i::i using 6:7 w p pt 7 ps 1 lc rgb \"#000000\",\n"
		"}\n"
		"unset output\n";

	// Send Gnuplot script to the Gnuplot process
	fprintf(gp, "%s", gnuplotscript);

	// Close Gnuplot process
	pclose(gp);
}
