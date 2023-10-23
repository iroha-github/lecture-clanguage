/*
 *  サンプルプログラム10
 */
#include <stdio.h>

void outputString()
{
    printf("Hello, world!\n"); // 1行目
    printf("\\ Hello, world! \\ Hello, world!\n");   // 空白
    printf("\t Hello, world! \t Hello, world!\n"); // TABインデント
}

void outputInteger()
{
    printf("1を整数表示:"); // 2行目
    printf("%d\n", 1); // 3行目
}

void outputDecimal()
{
    printf("3.14159を小数表示:"); // 4行目
    printf("%f\n", 3.14159); // 5行目

    printf("3.14159を小数点以下第2位まで表示:"); // 6行目
    printf("%.2f\n", 3.14159); // 7行目
}

void outputVariables()
{
    int number_of_students = 3; // 8行目
    printf("number_of_students=%d\n", number_of_students); // 9行目

    char greeting[] = "Hello, world!"; // 10行目
    printf("greeting=%s\n", greeting); // 11行目
}

int main()
{
    outputString();
    outputInteger();
    outputDecimal();
    outputVariables();

    return 0; // 12行目
}