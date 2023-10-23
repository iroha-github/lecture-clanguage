#include <stdio.h>

int main(void){
    int i;
    int array[5]={4, 2, 3, 1, 7};

    for(i=0; i<5; i++){
        printf("array[%d]=%d\n", i, *(array+i));
    }
    return 0;
}