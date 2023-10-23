/*課題8-1：以下の機能を満たすプログラムを作成せよ。
　・10個の小数値をキーボードから入力すると、その平均値・分散・最大値・最小値を表示する。
　・ただし、配列を使用すること。
　・キーボードからのデータ読取りには while文あるいはfor文を利用すると便利です。　
　・分散は平均値と個々のデータの差の２乗の平均です。
*/

#include<stdio.h>
int main()
{
    int i;
    int u;
    int t;
    int e;
    double n;
    double sum;
    double scatter1;
    double scatter2;
    double scatter;
    
    //array[11]だと11個目の値が空白/すなわち0になってしまうので，最小値がバグる

    /*
    for(i=1;i<11;i++){
    }
    これをするとarray[0]とarray[11]の数値を管理するのが面倒になるので，
    */
   
    /*
    for(i=0;i<10;i++){
    }
    にする
    */

    double array[10];
    printf("10個小数入力して\n");
    for(e=0;e<10;e++){
      scanf("%lf\n",&array[e]);
    }
     /*average*/
     //インデントは2つぐらいが良いと思う

    for(i=0; i<10; i++){
      sum += array[i]; 
    }

    printf("ここで出力平均値%lf\n",sum/10);

     /*ぶんさん*/
    for(u=0; u<10; u++){
      scatter1 = sum/10-array[u]; 
      scatter2 += scatter1*scatter1;
    }
    scatter=scatter2/10;
    printf("ここらで出力分散値%lf\n",scatter);

    double max = array[0];
    double min = array[0];
    
    for(t=0; t<10; t++){
      if(max < array[t]){
        max = array[t];
      }

      if(min > array[t]){
        min = array[t];
      }
    }

    /* 現在の最大値より大きければ、その値を新たな最大値に設定 */
    printf("同時に出力最大値%.9lf\n",max);

    /* 現在の最小値より小さければ、その値を新たな最小値に設定 */
    printf("同時に出力最小値%.9lf\n",min);
    
}