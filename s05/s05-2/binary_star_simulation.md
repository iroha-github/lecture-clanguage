# 情報処理演習Ⅱ Binary Star Simulation

![Alt text](image.png)

[動画url](https://shibaura3-my.sharepoint.com/personal/gen_sic_shibaura-it_ac_jp/_layouts/15/stream.aspx?id=%2Fpersonal%2Fgen%5Fsic%5Fshibaura%2Dit%5Fac%5Fjp%2FDocuments%2FStream%20Migrated%20Videos%2F%E6%83%85%E5%A0%B1%E5%87%A6%E7%90%86%E6%BC%94%E7%BF%92II%5F%E9%80%A3%E6%98%9F%E3%82%B7%E3%83%9F%E3%83%A5%E3%83%AC%E3%83%BC%E3%82%B7%E3%83%A7%E3%83%B3%E5%8F%82%E8%80%83%E5%8B%95%E7%94%BB%2D20210110%5F051740%2Emp4&referrer=StreamWebApp%2EWeb&referrerScenario=AddressBarCopied%2Eview)

## 概要

## 理論

### 連星とは

連星とは、2つの恒星が互いに万有引力により結びつき，それぞれ楕円軌道を描くものである．

### 連星の運動方程式

<center><img src=image-2.png width="700px"></center>


質点1,2をデカルト座標系で表す．
それぞれの質点1,2に対して，万有引力の法則より
質点1にかかる力は質点2から，質点2にかかる力は質点1からとなる．

$|\vec{F}_{1 \to 2}|=|\vec{F}_{2 \to 1}|=G\frac{m_1m_2}{r^2}$
$\vec{F}_{1 \to 2}=-\vec{F}_{2 \to 1}$

質点1の位置ベクトル$\vec{r_1}=(\vec{x_1},\vec{y_1})$，質点2の位置ベクトル$\vec{r_2}=(\vec{x_2},\vec{y_2})$とする．

運動方程式を立てると，

$$
\begin{align*}
    \begin{cases}
        m_1 \ddot{r}_1 &= \vec{F}_{1 \to 2} \\
        m_2 \ddot{r}_2 &= \vec{F}_{2 \to 1}
    \end{cases} \\
    \Leftrightarrow \quad
    \begin{aligned}
        &\begin{cases}
            m_1 \ddot{x}_1 &= (\vec{F}_{1 \to 2})_x \\
            m_1 \ddot{y}_1 &= (\vec{F}_{1 \to 2})_y
        \end{cases} \\
        &\begin{cases}
            m_2 \ddot{x}_2 &= (\vec{F}_{2 \to 1})_x \\
            m_2 \ddot{y}_2 &= (\vec{F}_{2 \to 1})_y
        \end{cases}
    \end{aligned}
\end{align*}
$$

ここで、質点1と質点2の位置ベクトルの差を
$$\vec{r_{12}}=\vec{r_2}-\vec{r_1}$$とすると，$\vec{F_{1 \to 2}} / \! / \vec{r_{12}}$となり，単位ベクトルを$\vec{e}$とすると
$$
\vec{F_{1 \to 2}}=|\vec{F_{1 \to 2}}|\vec{e}
$$
ベクトルの規格化$
\vec{e}=\frac{\vec{r_{12}}}{|\vec{r_{12}}|}$を行い，$|\vec{F}_{1 \to 2}|=|\vec{F}_{2 \to 1}|=G\frac{m_1m_2}{r^2}$とすると
$$
\begin{align*}
\vec{F_{1 \to 2}}
    &=|\vec{F_{1 \to 2}}|\frac{\vec{r_{12}}}{|\vec{r_{12}}|}\\
&=G\frac{m_1 m_2}{r^2}\frac{\vec{r_{12}}}{|\vec{r_{12}}|}\\
&=G\frac{m_1 m_2 }{r^3}(\vec{r_2}-\vec{r_1})
\end{align*}
$$
よって
$$
\begin{align*}
    \begin{cases}
        m_1 \ddot{x_1}=G\frac{m_1 m_2 }{r^3}(x_2-x_1) \\
        m_1 \ddot{y_1}=G\frac{m_1 m_2 }{r^3}(y_2-y_1) \\
    \end{cases}\\
\end{align*}
$$
また，質点2に働く力は質点1に働く力は逆向きであるから，
$$
\begin{align*}
    \begin{cases}
        m_2 \ddot{x_2}=-G\frac{m_1 m_2 }{r^3}(x_2-x_1) \\
        m_2 \ddot{y_2}=-G\frac{m_1 m_2 }{r^3}(y_2-y_1) \\
    \end{cases}\\
\end{align*}
$$
となる．

### 重心

重心は，質量の重み付き平均で表される．
質点1,2の重心を$\vec{r_g}$とすると(考え方：重心周りのモーメントは0になる)，
$$
\begin{align*}
    \vec{r_g}=\frac{m_1 \vec{r_1}+m_2 \vec{r_2}}{m_1+m_2}
\end{align*}
$$
この時x,y成分はそれぞれ
$$
\begin{cases}
    (\vec{r_g})_x=\frac{m_1 x_1+m_2 x_2}{m_1+m_2} \\
    (\vec{r_g})_y=\frac{m_1 y_1+m_2 y_2}{m_1+m_2}
\end{cases}
$$

## 検証
以下のプログラムが検証に用いたプログラムである．中点法を用いている．

```c
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
    return G*m1*m2*(x2-x1) / (pow(r(x1, y1, x2, y2), 3)); 
}

double gray(double x1, double y1, double x2, double y2) { //質点1と質点2のy方向の引力
    return G*m1*m2*(y2-y1) / (pow(r(x1, y1, x2, y2), 3));
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

    dt = 0.001; //中点法の時間の刻み幅
    nint = (t1-t0)/dt;

    FILE *fp;
    fp = fopen("binary_star_simulation.dat", "w");

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
        "set output \"binary_star_simulation.gif\"\n"
        "set title \"binary star simulation\"\n"
        "do for [i=0:99] {\n"
        "plot [-12:3][-6:5]\"binary_star_simulation.dat\" every ::i::i using 1:2 w p pt 7 ps 1 title \"Point mass 1\",\\\n"
        "                  \"binary_star_simulation.dat\" every ::i::i using 3:4 w p pt 7 ps 1 title \"Point mass 2\",\\\n"
        "                  \"binary_star_simulation.dat\" every ::i::i using 5:6 w p pt 7 ps 1 title \"The center of gravity\", \\\n"
        "                  \"binary_star_simulation.dat\" using 1:2 w l title \"Point mass 1 with line\", \\\n"
        "                  \"binary_star_simulation.dat\" using 3:4 w l title \"Point mass 2 with line\", \\\n"
        "                  \"binary_star_simulation.dat\" using 5:6 w l title \"The center of gravity with line\"\n"
        "}\n"
        "unset output\n";  //明示的に終了

    // Gnuplotのプロセスにコマンドを送る
    fprintf(gp, "%s", gnuplotscript);

    // プロセスを閉じる
    pclose(gp);

    return 0;
}

```

以下は上記のプログラムの内，アニメーションを作成するためのプログラムを抜粋したものである．逐一ポインタから渡すのは面倒であるし，コードが読みにくくなる．それを解消するために，ポインタgpに渡す文字列を定義している．この文字列はgnuplotのコマンドと同様である．
以下がそのプログラムの流れを説明したものである．

1. datファイルに必要なデータを書き出す

    ```c
    FILE *fp;
    fp = fopen("binary_star_simulation.dat", "w");
    ```

    と記述し，`fprintf(fp,~~~)`でポインタを介してbinary_star_simulation.datにデータを書き出す．
2. gnuplotのコマンドを文字列として定義しておく．

    ```c
    FILE *gp;
    gp = popen("gnuplot -persist", "w");
    ```

    と記述し，`fprintf(gp,~~~)`でポインタを介してgnuplotのコマンドを送る．

3. gnuplotのコマンドをポインタに渡す．
    渡した内容は以下の通りである．
    1. gifアニメーションを作成するための設定
    2. 繰り返しを用いてデータファイルをプロットするための設定

    これらを記述して実行し，gifアニメーションを作成する．

## 結果

<img src="binary_star_simulation.gif" width="500px">

## 考察
