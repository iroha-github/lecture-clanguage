/*
情報処理演習Ⅱ課題／ロジスティクス写像3

ロジスティクス写像のパラメータを設定した上で，datファイルへの出力とgnuplotでのプロットを一括で行うプログラム
*/

#include <stdio.h>

double LM(double x, double a){
    return a*x*(1-x);
}

int main(){
    int i, numa, j, numi, numd;
    double a0,a,da,x0,x;

    //--------------------------------------------------------------
    FILE *gp;   // gnuplot用のFILEポインタ
    gp = popen("gnuplot -persist","w");  // -persistオプションでウィンドウを閉じない
    FILE *fp;  // データ出力用のFILEポインタ
    fp = fopen("LM3.dat", "w");  // ファイルを書き込みモードで開く
    //---------------------------------------------------------------

    numa = 500; //aの刻みを0~4の中で何回刻むか
    da = 4.0/500; //daが実数型にするために4.0とする
    a0 = 0; //aの初期条件
    x0 = 0.2; //xの初期条件
    numd = 500; //500回未満は
    numi = 1000; //xの更新回数
    for(int i=1; i<=numa; i++){
        x = x0; //xの初期化
        for(int j=1; j<=numd; j++){
            x =LM(x,a); //numdの間は更新のみ
        }
        for(int j=1; j<=numi; j++){
            x = LM(x,a);
            fprintf(fp, "%f %f\n",a,x);
        }
        a = a+da; 
    }

    fclose(fp);  // ファイルを閉じる

    //---------------------------------------------------------------
    // gnuplotでデータをプロット
    fprintf(gp, "plot \"LM3.dat\" with points pt 7 ps 0.01 \n");  // 1行目
    /*
    点(マーカ)の種類→pointtype(pt)
        1: +
        2: ×
        3: *
        4: □
        5: ■
        6: ○
        7: ●

    点(マーカ)の大きさ→pointsize(ps)

    */

    fprintf(gp, "replot \n");        // gnuplotにコマンドを送る
    fflush(gp);  // バッファをクリア
    //---------------------------------------------------------------

    pclose(gp);  // gnuplotを閉じる
    return 0;
    
}