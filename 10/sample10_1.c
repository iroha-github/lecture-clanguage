//配列宣言時の個数には定数しか使えない
#include <stdio.h>

#define NUMBER 5 /* Nの定義 */

int main(void)
{
    int data[NUMBER];
    int k=0;

    int arrayNumber = sizeof data / sizeof data[0];

    printf("arrayNumber; %d\n", arrayNumber);
    return 0;
}