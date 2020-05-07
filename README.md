# pipe-and-filter-calculator

#La compilation: 

gcc -o calcul calcul.c

gcc -o trace trace.c

gcc `pkg-config --cflags gtk+-3.0` -o gui gui.c `pkg-config --libs gtk+3.0` 

#L'exécution:

./gui 
