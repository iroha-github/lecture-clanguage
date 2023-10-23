#include <stdio.h>
#define N 5        /* difineにより，コンパイル前に文字列Nを5に置換 */

int sum(int *array)    /* 整数型関数sumは，配列変数を引数として総和を返す */
{
    int i, sum=0;

    for(i = 0; i<N; i++){
        sum = sum + array[i];
    }     /*↑ただし，arrayはあくまでポインタ変数である点に注意*/
    return (sum);
}

int main(void)
{
    int i, total;
    int array[N];

    printf("%d個の整数を入力して下さい．\n",N);
    for(i = 0; i<N; i++){
        scanf("%d",&array[i]);
    }

    total = sum(array);
    printf("合計は%dです．\n",total);

    return 0;
}