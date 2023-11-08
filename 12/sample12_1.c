#include <stdio.h>

int main(void){
    FILE *fp;   /* ファイルポインタfpの宣言 */

    fp = fopen("text.tex", "r"); /* ファイルtext.txtを読み込みモードでオープン*/
    if (fp == NULL) {
        printf("指定されたファイルが開けませんので，プログラムを終了します\n");
        return(-1);
    } else {
        printf("指定されたファイルをオープンしました．\n");
    }

    fclose(fp);
    printf("ファイルをクローズしました．\n");
        return 0;

}