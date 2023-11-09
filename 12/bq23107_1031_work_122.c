/*
- 課題12-2：以下の機能を満たすプログラムを作成せよ。
    - 新しく出力用ファイルを生成する。”data2.dat”
    - 課題12-1で生成したdata.datから時刻t, 出力out1, out2を読み込む。
        - EOFまで読み込むとデータ数が把握できる。
    - for文で時刻tのデータ数分だけ以下を繰り返す
        - 読み込んだ時刻tを2倍し、時刻t2に代入する。
        - 時刻t2を入力とし、小数型変数out3に振幅1、周期1秒のsin波の値を計算し代入する。
        - 出力ファイルに時刻t2, out3を出力する。
    - 出力ファイル(”data2.dat”)を閉じる。
- #include <math.h>を使ってsin(theta)を計算する。ただし、 thetaはラジアン単位。
*/

#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(void){
        FILE *fp1, *fp2;
        fp1 = fopen("data.dat", "r");
        fp2 = fopen("data2.dat", "w");

        if (fp1 == NULL || fp2 == NULL){
                printf("ファイルが正常に開けませんでした\n");
                return -1;
        } else {
                printf("ファイルが正常に開けました\n");
        }
        
        int i = 0;
        double t, t2, out1, out2, out3;

        while(1){
            if(fscanf(fp1, "%lf %lf %lf", &t, &out1, &out2) != EOF){

                t2 = t*2;
                out3 = sin(t2*M_PI*2);

                fprintf(fp2, "%lf %lf\r\n", t2, out3);
                i++;
            } else {
                    break;
            }
        }
        
        printf("data2.datへの書き込み完了\n");
        fclose(fp1);
        fclose(fp2);
        printf("ファイルを閉じました\n");
}
