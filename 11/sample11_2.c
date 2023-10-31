#include <stdio.h>

//構造体を定義
struct student{
    int id;
    char name[128];
    double gpa;
};

void print_student_id(struct student s){
    printf("Id: %d\n", s.id);
}

void change_id(int id, struct student* s){
    s->id = id;
}

int main(void) {
    //構造体型の変数を作成
    struct student A = {23123, "T.S.", 3.5};

    print_student_id(A);

    change_id(23999, &A);

    print_student_id(A);

    return 0;
}