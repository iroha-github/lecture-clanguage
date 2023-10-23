#include <stdio.h>

int main()
{
    int i;
    int aa[3] = {1,3,5};
    int ab[5];

    /* 配列aaを配列abにコピー*/
    for(i=0; i<3; i++){
        ab[i] = aa[i];
    }

    for(i=0; i<3; i++){
        printf("配列abの%d番目の要素は%dです．\n",i+1,ab[i]);
    }
}