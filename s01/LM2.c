/*
情報処理演習Ⅱ課題／ロジスティクス写像２

ロジスティクス写像のパラメータを設定した上で，datファイルへの出力とgnuplotでのプロットを一括で行うプログラム
*/

#include <stdio.h>

double LM(double x, double a){
    return a*x*(1-x);
}

int main(){
    int n,i;
    double a,x0,x,y0,y,e;
    a=4;  //ロジスティクス写像のパラメータ a ∈ [0,4] 
    x0=0.3;  //初期値条件 x0 ∈ [0,1]
    e=0.0001; //初期条件の差
    y0=x0+e;//もう一つの初期条件

    //--------------------------------------------------------------
    FILE *gp;
    gp = popen("gnuplot -persist","w");
    FILE *fp;
    fp = fopen("LM2.dat", "w");  // ファイルを書き込みモードで開く
    //---------------------------------------------------------------

    fprintf(fp, "0 %f %f\n", x0, y0); //初期値の出力(0回目, 初期値)

    n=100; //回数を設定

    x=x0; 
    y=y0;

    for(i=1;i<=n;i++){
        x=LM(x,a);
        y=LM(y,a);
        fprintf(fp, "%d %f %f\n",i,x,y);
    }

    fclose(fp);  // ファイルを閉じる

    //---------------------------------------------------------------
    // gnuplotでデータをプロット
    fprintf(gp, "plot 'LM2.dat' using 1:2 with lines, 'LM2.dat' using 1:3 with lines\n");
    fprintf(gp, "replot \n");        // gnuplotにコマンドを送る
    fflush(gp);  // バッファをクリア
    //---------------------------------------------------------------

    pclose(gp);  // gnuplotを閉じる
    return 0;

}