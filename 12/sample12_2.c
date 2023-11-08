#include <stdio.h>

int main(void){
    FILE *fp;
    double x,y,z;
    fp = fopen("test.txt", "r");

    if(fp == NULL){
        printf("error\n");
        return -1;
    } else {
        printf("read OK!\n");
    }

    fscanf(fp, "%lf, %lf, %lf", &x, &y, &z);
    fclose(fp);
    printf("close OK!\n");

    printf("読み込んだデータの総和は %f です．¥n", x + y + z);

    return 0;

}