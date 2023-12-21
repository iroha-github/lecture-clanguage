set terminal gif animate delay 5 optimize size 640,480
set output 'CoupledVibrationMid.gif'

do for [i=0:100] {
  plot [-3:3][-3:3] "CoupledVibrationMid.dat" every ::i::i using 2:4 w p pt 7 ps 1, \
                     "CoupledVibrationMid.dat" every ::i::i using 3:4 w p pt 7 ps 2
}

unset output
