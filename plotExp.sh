#!/usr/bin/env gnuplot

set terminal pdf
set output 'navigation.pdf'

set xtics rotate # crucial line

set key vert
set key left 

  

set title "Problem vs Time"
set grid y
set grid x
#set logscale y 100

set ylabel "Time (seconds)"


plot "Navigation.dat" using 2:xtic(1) t "VI" with linespoints pt 4 ps 0.6




set terminal pdf
set output 'triangle.pdf'

set xtics rotate # crucial line

set key vert
set key left 

  

set title "Problem vs Time"
set grid y
set grid x



set ylabel "Time (seconds)"


plot "Triangle.dat" using 2:xtic(1) t "VI" with linespoints pt 4 ps 0.6


