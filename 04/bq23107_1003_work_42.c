/*
100点満点の成績を５段階で(S,A,B,C,D)に変換するプログラムを作成せよ。
90以上でS
90未満80以上でA
80未満70以上でB
70未満60以上でC
60未満でD
とする。
*/

#include <stdio.h>

int main(void){

  int score;

  printf("score :");
  scanf("%d", &score);

  if (score >= 90){
    printf("S\n");
  } else if (score >= 80){
    printf("A\n");
  } else if (score >= 70){
    printf("B\n");
  } else if (score >= 60){
    printf("C\n");
  } else if (score >= 0){
    printf("D\n");
  } else {
    printf("invalid score\n");
  }

  return 0;
}
