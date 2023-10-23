
/*
・課題8-1：以下の機能を満たすプログラムを作成せよ。
・10個の小数値をキーボードから入力すると、その平均値・分散・最大値・最小値を表示する。
・ただし、配列を使用すること。
・キーボードからのデータ読取りには while文あるいはfor文を利用すると便利です。　
・分散は平均値と個々のデータの差の２乗の平均です。
*/

#include <stdio.h>
#include <math.h>

double input_array(double array[]){
  int i;
  double num;
  for(i=0; i<10; i++){
    printf("配列の%d番目の数値(小数可)を入力してください\n",i+1);
    scanf("%lf",&num);
    array[i]=num;
  }
}

double calc_sum(double array[]){
  int i;
  double sum = 0;
  for(i=0; i<10; i++){
    sum+=array[i];
  }
  return (sum);
}

double calc_ave(double sum){
  double ave = 0;
  ave = sum/10;
  return (ave);
}

double calc_var(double array[], double ave){
  int i;
  double var = 0;
  for(i=0; i<10; i++){
    var+=(array[i]-ave)*(array[i]-ave)/10;
  }
  return (var);
}

double calc_max(double array[]){
  int i;
  double max=array[0]; // 最初の要素で初期化
  for(i=0; i<10; i++){
    if(max < array[i]){
      max = array[i];
    }
  }
  return (max);
}

double calc_min(double array[]){
  int i;
  double min=array[0]; // 最初の要素で初期化
  for(i=0; i<10; i++){
    if(min > array[i]){
    }
      min = array[i];
  }
  return (min);
}

int main(void){
  double array[10];
  input_array(array);

  double sum = calc_sum(array);
  printf("合計値は%lfのようです\n",sum);

  double ave = calc_ave(sum);
  printf("平均値は%lfのようです\n",ave);

  double var = calc_var(array, ave);
  printf("分散は%lfのようです\n",var);

  double max = calc_max(array);
  printf("最大値は%lfのようです\n",max);

  double min = calc_min(array);
  printf("最小値は%lfのようです\n",min);

  return 0;
}
