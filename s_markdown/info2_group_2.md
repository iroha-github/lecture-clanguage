 <script type="text/javascript" async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
 MathJax.Hub.Config({
 tex2jax: {
 inlineMath: [['$', '$'] ],
 displayMath: [ ['$$','$$'], ["\\[","\\]"] ]
 }
 });
</script>

# 情報処理演習グループ課題2


| 役職             | 学籍番号   | 名前     |備考      |
|------------------|------------|----------|---------|
| リーダー         | BQ23107    | 窪田大輝 |         |
| プログラムリーダー | BQ23008    | 脇家優太 |         |
| 企画係           | BQ23071    | 平川奨   |         |
| 連絡係           | BQ23060    | 塚田水月 |         |
| 書記１           | BQ23110    | 信賀晃   |         |
| 書記２           | BQ23103    | 山田泰我 | 欠席    |


> [TOC]


<div style="page-break-before:always"></div>


## 仮説(運動学として解く)←信賀
### 高さhを増加させる場合
z座標を0から刻み幅ごとに1.0まで増加させた時に，θを変化させて，何度で投げると飛距離を最大にできるかを計算するプログラムである．


### 粘性抵抗を考慮して高さhを増加させる場合
z座標$0.0$，初速$v0=10$，角度$$で斜方投射した時に最大飛距離になる$θ$を求める．
重力加速度を$g=9.8$とする．

水平方向の初期速度：$v_x(t) = v0 \cos(\theta)$
鉛直方向の初期速度：$v_z(t) = v0 \sin(\theta)$

水平方向の初期位置：$x(t)=0$
鉛直方向の初期位置：$z(t)=0$

水平方向の運動方程式：$a_x(t) = 0$
鉛直方向の運動方程式：$a_z(t) = -g$

水平方向の速度：$v_x(t) = v0 \cos(\theta)$
鉛直方向の速度：$v_z(t) = v0 \sin(\theta) - gt$

水平方向の位置：$x(t) = v0 \cos(\theta)t$
鉛直方向の位置：$z(t) = v0 \sin(\theta)t - \frac{1}{2}gt^2$

高さが$0$になる時間$t$を求める．
$$
\begin{align*}
z(t) &= 0 \\
v_0 \sin(\theta)t - \frac{1}{2}gt^2 &= 0 \\
t &= \frac{2v_0 \sin(\theta)}{g}
\end{align*}
$$
この$t$を$x(t)$に代入すると，最大飛距離$x$が求まる．
$$
\begin{align*}
x(t) &= v_0 \cos(\theta)t \\
&= v_0 \cos(\theta) \frac{2v_0 \sin(\theta)}{g} \\
&= \frac{2v_0^2 \sin(\theta) \cos(\theta)}{g} \\
&= \frac{v_0^2 \sin(2\theta)}{g}
\end{align*}
$$




## 結果(C言語で球値)
### 高さhを増加させる場合
#### 最大飛距離を計算
図1は，高さをz軸座標を0から刻み幅1.0ごとに10.0まで増加させた時に，θを変化させて，何度で投げると飛距離を最大にできるかを計算するプログラムである．
図2はその結果である．

```c
#include <stdio.h>
#include <math.h>
#define Gravity -9.8

#ifndef M_PI
#define M_PI 3.141592
#endif

int main(void) {;

    double x,z,vx0,vz0,vx,vz,theta;
    double z_min = 0.0;   // z座標初期位置
    double z_max = 10.0; // z座標最終位置
    double delta_z = 1.0; // z座標刻み幅
    double z0; //z座標の仮置き変数

    double theta_min = 0.0; // theta初期角度
    double theta_max = 50.0; // theta最終座標
    double delta_theta = 0.01; // theta刻み幅

    double delta_t = 0.01; // t刻み幅

    double v0 = 10.0; // 初期速度


    FILE *fp;
    fp = fopen("data.dat", "w");

    for (z0 = z_min; z0 < z_max; z0 += delta_z) {
        double theta_flag = 0.0;
        double x_max = 0; // 初期
        for (theta = theta_min; theta < theta_max; theta += delta_theta) {
            x = 0;
            z = z0;
            vx0 = v0 * cos(theta / 180.0 * M_PI);
            vz0 = v0 * sin(theta / 180.0 * M_PI);
            vx = vx0;
            vz = vz0;
            int count = 0;
            //printf("%f %f %f\n",theta ,vx, vz);
            while(z>=0.0){
                vx += 0 * delta_t;
                x += vx * delta_t;
                vz += Gravity * delta_t;
                z += vz * delta_t;
                count += 1;
            }

            if (x_max < x) {
                x_max = x;
                theta_flag = theta;
            }
            
        }

        printf("z=%.3fの時，theta=%.3fで最大飛距離x=%.3fである．\n", z0, theta_flag, x_max);
        fprintf(fp, "%f %f\n", z0, theta_flag);
    }

    return 0;
}

```

**Fig.1 Z座標と角度をパラメータとした時の，最大飛距離を求めるC言語プログラム**
![image](https://hackmd.io/_uploads/ryZwDb0Sp.png)

**Fig.2 Z座標と角度をパラメータとした時の，最大飛距離を求めるC言語プログラムの実行結果**

#### 最大飛距離をgnuplotでプロット
図3は図1のプログラムで球値した最大飛距離になるまでの軌跡をdatファイルに格納するプログラムである．datファイルは複数に出力されるので，その結果を統合してGnupplotで描画したプログラムが図4である．

```c
#include <stdio.h>
#include <math.h>
#define Gravity -9.8

#ifndef M_PI
#define M_PI 3.141592
#endif

int main(void) {

    double x,z,vx0,vz0,vx,vz,theta;
    double z_min = 0.0;   // z座標初期位置
    double z_max = 10.0; // z座標最終位置
    double delta_z = 1.0; // z座標刻み幅
    double z0; //z座標の仮置き変数

    double theta_min = 0.0; // theta初期角度
    double theta_max = 50.0; // theta最終座標
    double delta_theta = 0.01; // theta刻み幅

    double delta_t = 0.01; // t刻み幅

    double v0 = 10.0; // 初期速度

    FILE *fp;
    fp = fopen("data.dat", "r");
    if (fp == NULL) {
        printf("ファイルを開けませんでした．\n");
        return 1;
    }

    double z0_value, theta_value;
    int count = 0;
    while (fscanf(fp, "%lf %lf", &z0_value, &theta_value) != EOF) {
        printf("z=%fの時，theta=%f\n", z0_value, theta_value);
        double theta_flag = 0.0;
        double x_max = 0; // 初期
        x = 0;

        z = z0_value;
        vx0 = v0 * cos(theta_value / 180.0 * M_PI);
        vz0 = v0 * sin(theta_value / 180.0 * M_PI);
        vx = vx0;
        vz = vz0;
        count += 1;
        //printf("%f %f %f\n",theta ,vx, vz);
        char filename[20];
        sprintf(filename, "data_%d.dat", count);

        FILE *fp2 = fopen(filename, "w");
        if (fp2 == NULL) {
            printf("%sファイルを開けませんでした．\n", filename);
            return 1;
        }
        while(z>=0.0){
            printf("     %d %.3f %.3f\n",count ,x, z);
            fprintf(fp2, "%f %f\n", x, z);
            
            vx += 0 * delta_t;
            x += vx * delta_t;
            vz += Gravity * delta_t;
            z += vz * delta_t;
        }
    }

    return 0;
}


```
**Fig.3 最大飛距離になる時の軌跡をdatファイルに格納するプログラム**

```c
#include <stdio.h>

int main() {
    FILE *gnuplotPipe = popen ("gnuplot -persistent", "w");

    if (gnuplotPipe == NULL) {
        printf("Error opening pipe to GNU plot.\n");
        return 1;
    }

    fprintf(gnuplotPipe, "set title 'Graph'\n");

    for (int i = 1; i <= 10; i++) {
        if (i == 1) {
            fprintf(gnuplotPipe, "plot 'data_%d.dat' with lines\n", i);
        } else {
            fprintf(gnuplotPipe, "replot 'data_%d.dat' with lines\n", i);
        }
    }
    fprintf(gnuplotPipe, "replot\n");
    fflush(gnuplotPipe);
    fclose(gnuplotPipe);
    return 0;
}
```
**Fig.4 複数datファイルから軌跡を描くプログラム**

図5は図4で示したプログラムにより生成されたグラフである．
![image](https://hackmd.io/_uploads/rycnD-Cra.png)

**Fig.5 図4によって生成されたグラフ**

### 粘性抵抗を考慮して高さhを増加させる場合
#### 最大飛距離を計算
図6は，高さをz軸座標を0から刻み幅1.0ごとに10.0まで増加させた時に，θを変化させて，何度で投げると飛距離を最大にできるかを計算するプログラムである．
図7はその結果である．
```c
#include <stdio.h>
#include <math.h>
#define Gravity -9.8

#ifndef M_PI
#define M_PI 3.141592
#endif

int main(void) {;

    double x,z,vx0,vz0,vx,vz,theta;
    double z_min = 0.0;   // z座標初期位置
    double z_max = 30.0; // z座標最終位置
    double delta_z = 3.0; // z座標刻み幅
    double z0; //z座標の仮置き変数

    double theta_min = 0.0; // theta初期角度
    double theta_max = 50.0; // theta最終座標
    double delta_theta = 0.01; // theta刻み幅

    double delta_t = 0.01; // t刻み幅

    double v0 = 10.0; // 初期速度
    double b = 2.5; // 粘性抵抗係数
    double m = 3.0; // 質量


    FILE *fp;
    fp = fopen("data.dat", "w");

    for (z0 = z_min; z0 < z_max; z0 += delta_z) {
        double theta_flag = 0.0;
        double x_max = 0; // 初期
        for (theta = theta_min; theta < theta_max; theta += delta_theta) {
            x = 0;
            z = z0;
            vx0 = v0 * cos(theta / 180.0 * M_PI);
            vz0 = v0 * sin(theta / 180.0 * M_PI);
            vx = vx0;
            vz = vz0;
            int count = 0;
            //printf("%f %f %f\n",theta ,vx, vz);
            while(z>=0.0){
                vx += 0 * delta_t;
                x += vx * delta_t;
                vz = vz + delta_t* (Gravity - b * vz/m);
                //vz+dt*(g - b*vz/m)
                z += vz * delta_t;
                count += 1;
            }

            if (x_max < x) {
                x_max = x;
                theta_flag = theta;
            }
        }

        printf("z=%.3fの時，theta=%.3fで最大飛距離x=%.3fである．\n", z0, theta_flag, x_max);
        fprintf(fp, "%f %f\n", z0, theta_flag);
    }
    return 0;
}

```

**Fig.6 Z座標と角度をパラメータとした時の，最大飛距離を求めるC言語プログラム**
![ppf1](https://hackmd.io/_uploads/SJREDu0HT.png)


**Fig.7 Z座標と角度をパラメータとした時の，最大飛距離を求めるC言語プログラムの実行結果**

#### 最大飛距離をgnuplotでプロット
図8は図6のプログラムで球値した最大飛距離になるまでの軌跡をdatファイルに格納するプログラムである．datファイルは複数に出力されるので，その結果を統合してGnupplotで描画したプログラムが図4である．

```c
#include <stdio.h>
#include <math.h>
#define Gravity -9.8

#ifndef M_PI
#define M_PI 3.141592
#endif

int main(void) {;

    double x,z,vx0,vz0,vx,vz,theta;
    double z_min = 0.0;   // z座標初期位置
    double z_max = 30.0; // z座標最終位置
    double delta_z = 3.0; // z座標刻み幅
    double z0; //z座標の仮置き変数

    double theta_min = 0.0; // theta初期角度
    double theta_max = 50.0; // theta最終座標
    double delta_theta = 0.01; // theta刻み幅

    double delta_t = 0.01; // t刻み幅

    double v0 = 10.0; // 初期速度
    double b = 2.5; // 粘性抵抗係数
    double m = 3.0; // 質量

    FILE *fp;
    fp = fopen("data.dat", "r");
    if (fp == NULL) {
        printf("ファイルを開けませんでした．\n");
        return 1;
    }    

    double z0_value, theta_value;
    int count = 0;

    while (fscanf(fp, "%lf %lf", &z0_value, &theta_value) != EOF) {
        printf("z=%fの時，theta=%f\n", z0_value, theta_value);
        double theta_flag = 0.0;
        double x_max = 0; // 初期
        x = 0;

        z = z0_value;
        vx0 = v0 * cos(theta_value / 180.0 * M_PI);
        vz0 = v0 * sin(theta_value / 180.0 * M_PI);
        vx = vx0;
        vz = vz0;
        count += 1;
        //printf("%f %f %f\n",theta ,vx, vz);
        char filename[20];
        sprintf(filename, "data_%d.dat", count);

        FILE *fp2 = fopen(filename, "w");
        if (fp2 == NULL) {
            printf("%sファイルを開けませんでした．\n", filename);
            return 1;
        }
        while(z>=0.0){
            printf("     %d %.3f %.3f\n",count ,x, z);
            fprintf(fp2, "%f %f\n", x, z);
            
            vx += 0 * delta_t;
            x += vx * delta_t;
            vz = vz + delta_t* (Gravity - b * vz/m);
            vz += Gravity * delta_t;
            z += vz * delta_t;
        }
    }
    return 0;
}
```
**Fig.8 最大飛距離になる時の軌跡をdatファイルに格納するプログラム**

```c
#include <stdio.h>

int main() {
    FILE *gnuplotPipe = popen ("gnuplot -persistent", "w");

    if (gnuplotPipe == NULL) {
        printf("Error opening pipe to GNU plot.\n");
        return 1;
    }

    fprintf(gnuplotPipe, "set title 'Graph'\n");

    for (int i = 1; i <= 10; i++) {
        if (i == 1) {
            fprintf(gnuplotPipe, "plot 'data_%d.dat' with lines\n", i);
        } else {
            fprintf(gnuplotPipe, "replot 'data_%d.dat' with lines\n", i);
        }
    }
    fprintf(gnuplotPipe, "replot\n");
    fflush(gnuplotPipe);
    fclose(gnuplotPipe);
    return 0;
}
```
**Fig.9 複数datファイルから軌跡を描くプログラム**

図10は図9で示したプログラムにより生成されたグラフである．
![ppf2](https://hackmd.io/_uploads/SyxgPO0Bp.png)

**Fig.10 図4によって生成されたグラフ**


## 考察

