/*
・時間に応じて乱数を発生させる。
・100以下の値であれば、計算により素数かどうかを判断し、表示する。
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int is_prime(int num){
  int i, j;

  for(i=2; i<100; i++){
      for(j=2; j<100; j++){
        if(i % j == 0){
          if(i == j){
            return 0;
            break;
          }else{
            break;
          }
      }
    }
  }
  return 1;
}

int main(void){
  int a;
  while(1){
    srand(time(0));
    a = rand() % 100;
    printf("%d", a);

    int prime = is_prime(a);
    if (prime == 0){
      printf("素数です");
    }
  }
}

