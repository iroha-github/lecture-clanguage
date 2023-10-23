/*
*キーボードで入力した文字を使って自分の氏名を入力、表示するプログラムを作成せよ
*/
#include <stdio.h>
int main(void)
{
    char name[40];
    printf("氏名を入力してください\n");
    scanf("%s",name);
    printf("あなたの氏名は%sですね\n",name);
    return 0;
}
