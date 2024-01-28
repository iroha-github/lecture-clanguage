set terminal gif animate delay 5 optimize size 480,640
set output 'anime_data1_xy.gif'
do for [i=0: 499] {
  plot [-1:1][-3:1] "anime_data1_xy.dat" every ::i::i using 1:2 w lp pt 7 ps 2,\
                    "anime_data1_xy.dat" every ::i::i using 3:4 w lp pt 7 ps 2,\
                    "anime_data1_xy.dat" every ::i::i using 5:6 w lp pt 7 ps 2,\
                    

}
unset output