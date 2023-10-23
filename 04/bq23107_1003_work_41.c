/*
・キーボードから整数X,Yを入力する。（Xは演算対象、Yはコマンド）
・演算対象Xは１～９のみ受け付け、それ以外の入力があった場合は、「Invalid number」と表示し、プログラムを終了する。
・コマンドYは、１～４とする。次のメニューに従ってXを演算し、その結果を表示する
１：二乗、２：絶対値、３：偶奇の判断、４：演算しない。
それ以外の入力は「Invalid commannd」と表示し、プログラムを終了する。
*/

//switch文を使う場合

#include <stdio.h>

int main(void){

  int X, Y;

  printf("X,Y :");
  scanf("%d %d", &X, &Y);

  if (X < 1 || X > 9){
    printf("Invalid number\n");
    return 0;
  }

  switch (Y){
    case 1:
      printf("X^2 = %d\n", X * X);

      break;
    case 2:
      printf("|X| = %d\n", X > 0 ? X : -X);
      //?の使い方
      //条件式 ? 式1 : 式2
      //条件式が真の場合は式1を、偽の場合は式2を評価する
      break;
    case 3:
      printf("X is %s\n", X % 2 == 0 ? "even" : "odd");
      //Xを2で割った余りが0ならeven、それ以外ならodd
      break;
    case 4:
      printf("X is %d\n", X);
      break;
    default:
      printf("Invalid command\n");
      break;
  }

  return 0;
}

//if文を使う場合

// #include <stdio.h>

// int main(void){

//   int X, Y;

//   printf("X,Y :");
//   scanf("%d %d", &X, &Y);

//   if (X < 1 || X > 9){
//     printf("Invalid number\n");
//     return 0;
//   }

//   if (Y == 1){
//     printf("X^2 = %d\n", X * X);
//   } else if (Y == 2){
//     printf("|X| = %d\n", X > 0 ? X : -X);
//   } else if (Y == 3){
//     printf("X is %s\n", X % 2 == 0 ? "even" : "odd");
//   } else if (Y == 4){
//     printf("X is %d\n", X);
//   } else {
//     printf("Invalid command\n");
//   }

//   return 0;
// }
