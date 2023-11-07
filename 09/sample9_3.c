#include <stdio.h>
void swap(int *xxx, int *yyy){
    int tmp;
    tmp = *xxx;
    *xxx = *yyy;
    *yyy = tmp;
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