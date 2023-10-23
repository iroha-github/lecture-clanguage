#include <stdio.h>

void main(){
    int x = 1, size;

    printf("変数xの値は %dです．\n",x);
    printf("変数xのポインタは %pです．\n",&x);

    size =sizeof(x)*8; /* 変数xのメモリ上の領域をビットで計算 */
    printf("変数xが使用するビットの数は %dです．\n",size);
}