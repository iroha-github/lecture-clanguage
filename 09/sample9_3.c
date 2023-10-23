#include <stdio.h>
void swap(int *x, int *y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(void){
    int x = 1, y = 2;
    printf("Before: \n");
    printf("x = %d, y = %d\n",x, y);

    swap(&x, &y);

    printf("After: \n");
    printf("x = %d, y = %d\n", x, y);
    return 0;
}