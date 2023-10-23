/*
課題8-2：以下の機能を満たすプログラムを作成せよ。
・２次元配列で２×２の異なる配列A,Bを表示する。２つの配列A,Bは埋め込みで良い。
・A＋B、A・Bを計算し、表示する。
・Aの逆行列を計算し、表示する。ただし、行列式＝０の場合は計算しないこと。
*/

#include <stdio.h>

//配列表示関数
void show_matrix(int matrix[2][2]){
  int i, j;
  for(i=0; i<2; i++){
    for(j=0; j<2; j++){
      printf("%d ",matrix[i][j]);
    }
    printf("\n");
  }
}

void show_matrix_double(double matrix[2][2]){
  int i, j;
  for(i=0; i<2; i++){
    for(j=0; j<2; j++){
      printf("%lf ",matrix[i][j]);
    }
    printf("\n");
  }
}

//配列A,Bの和
//戻り値の型はvoidにする必要があります。また、配列への代入には、=ではなく、要素ごとの代入が必要です。
//C言語では、関数の戻り値としては1つの型のデータしか返すことができないため、2次元配列を直接戻り値として返すことはできません。
//関数は引数で渡された配列に対して計算を行い、その結果を引数で渡された配列 result に格納しています。これは、C言語における関数の "副作用" の一例です。副作用は、関数が引数を変更することを指します。戻り値がないため、関数は何かしらの手段で結果を呼び出し元に伝える必要があります。その手段として、引数を通じて結果を伝えることがあります。

void sum_matrix(int matrixA[2][2], int matrixB[2][2], int result[2][2]){
  int i,j ;
  for(i=0; i<2; i++){
    for(j=0; j<2; j++){
      result[i][j] = matrixA[i][j]+ matrixB[i][j];
    }
  }
}

//配列A,Bの積
void product_matrix(int matrixA[2][2], int matrixB[2][2], int result[2][2]){
  int i,j,k;
  for(i=0; i<2; i++){
    for(j=0; j<2; j++){
      for(k=0; k<2; k++){
        result[i][j] += matrixA[i][k]*matrixB[k][j];
      }
    }
  }
}

//行列式＝０か判定＆Aの逆行列を計算
int inverse_matrix(int matrixA[2][2], double result[2][2]){
  double num = matrixA[0][0]*matrixA[1][1]-matrixA[0][1]*matrixA[1][0];
  if (num == 0){
    return 1;
  } else {
    result[0][0]=1/num*matrixA[1][1];
    result[0][1]=-1/num*matrixA[0][1];
    result[1][0]=-1/num*matrixA[1][0];
    result[1][1]=1/num*matrixA[0][0];
    return 0;
  }
}

int main(void){
  int matrixA[2][2] = {{1, 2}, {3, 4}};
  int matrixB[2][2] = {{5, 6}, {7, 8}};
  int result_sum[2][2];
  int result_product[2][2];
  double result_inverse[2][2];

  printf("配列Aを表示\n");
  show_matrix(matrixA);

  printf("\n配列Bを表示\n");
  show_matrix(matrixB);

  printf("\nA＋Bを表示\n");
  sum_matrix(matrixA, matrixB, result_sum);
  show_matrix(result_sum);

  printf("\nA・Bを表示\n");
  product_matrix(matrixA, matrixB, result_product);
  show_matrix(result_product);

  printf("\nAの逆行列を表示/行列式=0の場合は計算しない\n");
  if (inverse_matrix(matrixA, result_inverse)==0){
    printf("逆行列は存在します\n");
    show_matrix_double(result_inverse);
  }else{
    printf("逆行列は存在しません\n");
  }

  //以下動作確認用
  printf("\n\n動作確認用\n");
  printf("matrixC[2][2] = {{1, 2}, {3, 6}}を指定すると\n");
  int matrixC[2][2] = {{1, 2}, {3, 6}};
  printf("matrixCの逆行列を表示/行列式=0の場合は計算しない\n");
  if (inverse_matrix(matrixC, result_inverse)==0){
    printf("逆行列は存在します\n");
    show_matrix_double(result_inverse);
  }else{
    printf("逆行列は存在しません\n\n");
  }

}