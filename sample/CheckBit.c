#include <stdio.h>
#include <string.h>

void printBin1(unsigned char bin);

int main()
{
    int i;
    int a=-934281216;
    unsigned char c[sizeof(a)];

    memcpy(c,&a,sizeof(a));
    for(i=sizeof(a)-1;i>=0;i--)
    {
        printBin1(c[i]);
    }
}

void printBin1(unsigned char bin)
{
    int i;
    unsigned char binTemp;
    for(i=0;i<7;i++)
    {
        binTemp=bin;
        binTemp=binTemp>>i;
        printf("%d", binTemp%2);
    }
    printf("b\n");
}
