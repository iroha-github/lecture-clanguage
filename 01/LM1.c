#include <stdio.h>

int main(){
    int n,i;
    double a,x0,x;
    a=1.5;  //ロジスティクス写像のパラメータ a　∈　[0,4] 
    x0=0.5;  //初期値条件 x0　∈　[0,1]

    printf("0 %f\n",x0);

    n=100;

    x=x0;

    for(i=1;i<=n;i++){
        x=a*x*(1-x);
        printf("%d %f\n",i,x);
    }
}