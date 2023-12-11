# plot_script_inline.plt

# 軸の範囲を設定
set xrange [0:10]
set yrange [-2:3]

# ラベルの設定
set xlabel "t"
set ylabel "x(t)"

# プロットする関数の定義
x1(t) = exp(-2*t) * (3*cos(sqrt(24)*t) + 3/(2*sqrt(6))*sin(sqrt(24)*t))
x2(t) = 3*exp(-5*t) + 15*t*exp(-5*t)
x3(t) = (2/3) * exp(-25/6*t) + (2/3) * exp(-25/6*t)



# グラフをターミナルに表示
plot '+' using 1:(x1($1)) with lines title "x1(t)", \
     '+' using 1:(x2($1)) with lines title "x2(t)", \
     '+' using 1:(x3($1)) with lines title "x3(t)"
