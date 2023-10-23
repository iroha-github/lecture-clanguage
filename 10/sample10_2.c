#include <stdio.h>
int main(void)
{
    int i, array[5];

    for (i=0; i<5; i++){
        printf("配列要素array[%d]のポインタは%p．\n", i, &array[i]);
    }
    printf("配列名arrayはポインタ%pを表します．\n", array);
    return 0;
}