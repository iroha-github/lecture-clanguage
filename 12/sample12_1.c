#include <stdio.h>

int main(void) {
    FILE *fp;
    char str[256];

    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("指定されたファイルが開けませんので，プログラムを終了します．\n");
        return -1;
    } else {
        printf("指定されたファイルをオープンしました．\n");
    }

    while (fgets(str, 256, fp) != NULL) {
        printf("%s", str);
    }

    fclose(fp);
    printf("ファイルをクローズしました．\n");
    return 0;
}