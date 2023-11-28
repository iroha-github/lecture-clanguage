#include <stdio.h>

int main() {
    FILE *gp;                            // gnuplot用のFILEポインタ
    gp = popen("gnuplot -persist", "w"); // -persistオプションでウィンドウを閉じない
    fprintf(gp, "plot [-20:20] sin(x)\n");        // gnuplotにコマンドを送る
    fprintf(gp, "replot \n");        // gnuplotにコマンドを送る
    pclose(gp);                          // FILEポインタを閉じる
    return 0;
}