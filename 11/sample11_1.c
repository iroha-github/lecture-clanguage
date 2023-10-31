#include <stdio.h>
#include <string.h>

//構造体を定義
struct student{
    int id;
    char name[128];
    double gpa;
};

int main(void){
    // 構造体型の変数を作成
    struct student A;

    // 構造体に値をセット
    A.id = 23123;
    strcpy(A.name, "T.S.");
    A.gpa = 3.5;

    printf("No. \t Name \t GPA\n");
    printf("%d \t %s \t %.1f\n", A.id, A.name, A.gpa);

    return 0;
}
