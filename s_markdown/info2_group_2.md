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


| 役職           | 学籍番号 | 名前 |  備考  |
|---------------|--------|-----|-------|
| リーダー        | BQ23107 | 窪田 大輝 |      |
| プログラムリーダー | BQ23008 | 脇家 優太 |     |
| 企画係          | BQ23071 | 平川 奨  |      |
| 連絡係          | BQ23060 | 塚田 水月 |      |
| 書記１          | BQ23110 | 信賀 晃  |      |
| 書記２          | BQ23103 | 山田 泰我 | 欠席  |

> [TOC]

<div style="page-break-before:always"></div>

## 仮説(運動学として解く)←信賀

### 高さhを増加させる場合

#### 高さ$0$の時

$z$座標$0.0$，初速$v_0=10$，角度$\theta$で斜方投射した時に最大飛距離になる$\theta$を求める．
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
$0 \degree  <\theta<90 \degree$の範囲で最大値を求める．
$sin(90 \degree) = 1$で最大値なので，$\theta = 45 \degree$の時に最大飛距離になる．

#### 高さが$h$の時

水平方向の初期速度：$v_x(0) = v0 \cos(\theta)$
鉛直方向の初期速度：$v_z(0) = v0 \sin(\theta)$

水平方向の初期位置：$x(0)=0$
鉛直方向の初期位置：$z(0)=h$

水平方向の運動方程式：$a_x(t) = 0$
鉛直方向の運動方程式：$ma_z(t) = -mg$

水平方向の速度：$v_x(t) = v0 \cos(\theta)$
鉛直方向の速度：$v_z(t) = v0 \sin(\theta) - gt$

水平方向の位置：$x(t) = v0 \cos(\theta)t$
鉛直方向の位置：$z(t) = v0 \sin(\theta)t - \frac{1}{2}gt^2 + h$

高さが$0$になる時間$t$を求める．
$$
\begin{align*}
z(t) &= 0 \\
v_0 \sin(\theta)t - \frac{1}{2}gt^2 + h &= 0 \\
t &= \frac{v_0 \sin(\theta) \pm \sqrt{v_0^2 \sin^2(\theta) - gh}}{g}
\end{align*}
$$
この$t$を$x(t)$に代入すると，最大飛距離$x$が求まる．
$$
\begin{align*}
x(t) &= v_0 \cos(\theta)t \\
&= v_0 \cos(\theta) \frac{v_0 \sin(\theta) \pm \sqrt{v_0^2 \sin^2(\theta) - gh}}{g} \\
&= \frac{v_0^2 \sin(\theta) \cos(\theta) \pm v_0 \cos(\theta) \sqrt{v_0^2 \sin^2(\theta) - gh}}{g} \\
&= \frac{v_0^2 \sin(2\theta) \pm v_0 \cos(\theta) \sqrt{v_0^2 \sin^2(\theta) - gh}}{g}
\end{align*}
$$
この式に$h$を実数を代入する．その後$x(t)$が最大となるように$\theta$を求めれば良い．

### 粘性抵抗を考慮して高さhを増加させる場合

水平方向の初期速度：$v_x(0) = v_0 \cos(\theta)$
鉛直方向の初期速度：$v_z(0) = v_0 \sin(\theta)$

水平方向の初期位置：$x(0)=0$
鉛直方向の初期位置：$z(0)=h$

粘性抵抗係数$b=2.5$

水平方向の運動方程式：$ma_x(t) =m\frac{dv_x}{dt}= -bv_x(t)$
鉛直方向の運動方程式：$ma_z(t) =m\frac{dv_z}{dt} = -mg-bv_z(t)$

水平方向の速度：
$$
\begin{align*}
\frac{dv_x}{dt} &= -\frac{b}{m}v_x(t) \\
\int \frac{1}{v_x(t)} \, dv_x &= -\int \frac{b}{m} \, dt \\
\ln|v_x(t)| &= -\frac{b}{m}t + C \\
v_x(t) &= e^{-\frac{b}{m}t + C} \\
v_x(t) &= Ae^{-\frac{b}{m}t}
\end{align*}
$$
初速度が$v_x(0)$なので$A=v_x(0)=v_0\cos(\theta)$より
$$
\begin{align*}
v_x(t) &= v_0\cos(\theta)e^{-\frac{b}{m}t}
\end{align*}
$$

鉛直方向の速度：

$$
\begin{align*}
\frac{dv_z}{dt} &= -g - \frac{b}{m}v_z(t) \\
\int \frac{1}{g+\frac{b}{m}v_z(t)} \, dv_z &= -\int \, dt \\
\int \left(1 - \frac{\frac{b}{m}}{g}v_z(t)\right) \, dv_z &= -\int \, dt \\
v_z(t) - \frac{\frac{b}{m}}{g}v_z^2(t) &= -t + C
\end{align*}
$$

初速度が$v_z(0)$なので$C=v_z(0)=v_0\sin(\theta)$より…
と解きたいが，解けないので数値計算や近似法を用いることが一般的である．

## 結果(C言語で球値)

### 高さhを増加させる場合

#### 最大飛距離を計算

図1は，高さをz軸座標を0から刻み幅1.0ごとに10.0まで増加させた時に，θを変化させて，何度で投げると飛距離を最大にできるかを計算するプログラムである．
図2はその結果である．

@import "../s02/group_assignment/projectile/projectile_calculate.c"
<center>Fig.1 Z座標と角度をパラメータとした時の，最大飛距離を求めるC言語プログラム</center><br>

@import "../s02/group_assignment/projectile/d1.dat"
<center>Fig.2 Z座標と角度をパラメータとした時の，最大飛距離を求めるC言語プログラムの実行結果</center><br>

#### 最大飛距離をgnuplotでプロット

図3は図1のプログラムで球値した最大飛距離になるまでの軌跡をdatファイルに格納するプログラムである．datファイルは複数に出力されるので，その結果を統合してGnupplotで描画したプログラムが図4である．

@import "../s02/group_assignment/projectile/projectile_resistance_plot_data.c"
<center>Fig.3 最大飛距離になる時の軌跡をdatファイルに格納するプログラム</center><br>

@import "../s02/group_assignment/projectile/projectile_plot_figure.c"
<center>Fig.4 複数datファイルから軌跡を描くプログラム</center><br>

図5は図4で示したプログラムにより生成されたグラフである．
@import "../s02/group_assignment/projectile/pp1.png"
<center>Fig.5 図4によって生成されたグラフ</center><br>

### 粘性抵抗を考慮して高さhを増加させる場合

#### 最大飛距離を計算

図6は，高さをz軸座標を0から刻み幅1.0ごとに10.0まで増加させた時に，θを変化させて，何度で投げると飛距離を最大にできるかを計算するプログラムである．
図7はその結果である．
@import "../s02/group_assignment/projectile/projectile_resistance_calculate.c"

<center><Fig.6 Z座標と角度をパラメータとした時の，最大飛距離を求めるC言語プログラム</center><br>

@import "../s02/group_assignment/projectile/d2.dat"

<center>Fig.7 Z座標と角度をパラメータとした時の，最大飛距離を求めるC言語プログラムの実行結果</center><br>

#### 最大飛距離をgnuplotでプロット
図8は図6のプログラムで球値した最大飛距離になるまでの軌跡をdatファイルに格納するプログラムである．datファイルは複数に出力されるので，その結果を統合してGnupplotで描画したプログラムが図4である．

@import "../s02/group_assignment/projectile/projectile_resistance_plot_data.c"

<center>Fig.8 最大飛距離になる時の軌跡をdatファイルに格納するプログラム</center><br>

@import "../s02/group_assignment/projectile/projectile_resistance_plot_figure.c"
<center>Fig.9 複数datファイルから軌跡を描くプログラム</center><br>

図10は図9で示したプログラムにより生成されたグラフである．

@import "../s02/group_assignment/projectile/pp2.png"
<center>Fig.10 図4によって生成されたグラフ</center>


|仮説で論じた通り，計算が難しいものも，オイラー法により計算できた．
|:--|
