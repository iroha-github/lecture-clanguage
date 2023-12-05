# plot.gp
set terminal pngcairo
set output 'output.png'
set key outside
set xlabel 'X'
set ylabel 'Y'
do for [i=1:5] {
    plot sprintf('data_%d.dat', i) using 1:2 with lines title sprintf('Data %d', i)
}