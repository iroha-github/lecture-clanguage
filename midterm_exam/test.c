/* --- 中間試験(実技) 問 --- */
/*
BQ23107→XとYどちらも奇数なのでA=6 B=7 C=0

問題文を読み、作成したコードと生成したデータによるグラフを回答欄に記入せよ。

 “IntTest1.c”は、ある図形を描くためのデータをファイルに保存するプログラムである。

 ある図形とは、時間変化するx,y方向の単振動を合成する（x-yグラフを描く）ことで得られる。

 x,y方向の単振動は、以下の式で与える。

 ・x=sin(A * 2 * π * t / T + C)

 ・y=sin(B * 2 * π * t / T)

ただし、t:時間、A、B、C：定数、T：周期である。本問では、T=2秒とする。

また、サンプリング時間（ST、更新間隔）=0.01秒とする。

 
*/
#include <stdio.h>
#include <math.h>

#define ST 0.01 // seconds
#define PI 3.14159 
#define IS_EVEN_NUM 1
#define IS_ODD_NUM 2

// Define output data to the file as a structure.
struct OUTPUT_DATA{
	double x;
	double y;
};

/* 
 Name: "isEvenNum" 
 Function: determines whether a number is even or odd. 
 Arguments:
  in: integer value
 Return value:
  1: if the argument "in" is even
  2: if the argument "in" is odd
*/
int isEvenNum(int in){
	int ret = 0;
	/* Q1 START */
	if( in % 2 == 0 ){
        ret = IS_EVEN_NUM;
  	} else {
        ret = IS_ODD_NUM;
  	}
	/* Q1 END */

	return ret;
}

/* 
 Name: "SetParamsFromId" 
 Function: sets the values of constants A, B, and C based on a numerical 5-digit ID.
 Arguments:
  FiveDigitId: integer value (a 5-digit numerical ID)
  A, B, and C: the values of constants
 Return value: None
*/
void SetParamsFromId(int FiveDigitId, double* A, double* B, double* C){
	
	int X = FiveDigitId / 100; // Decimal points are truncated when converted to int type
	int Y = FiveDigitId - X * 100; 
    printf("The numeric part (5 digits) of the student ID is %d.\n", FiveDigitId);
    printf("X = %d, Y = %d\n", X, Y);

	int isEvenX = isEvenNum(X);
	int isEvenY = isEvenNum(Y);

	/* Q2 START */
	if ( isEvenX == IS_ODD_NUM) {
		if ( isEvenY == IS_ODD_NUM) {
    		printf("Both X and Y are odd.\n");
            *A = 6;
            *B = 7;
            *C = 0;
		}else{
    		printf("X is odd, and Y is even.\n");
            *A = 2;
            *B = 3;
            *C = PI / 6;
		}
	}else{
		if ( isEvenY == IS_ODD_NUM) {
    		printf("X is even, and Y is odd.\n");
            *A = 3;
            *B = 4;
            *C = PI / 6;
		}else{
    		printf("Both X and Y are even.\n");
            *A = 6;
            *B = 7;
            *C = PI / 6;
		}
	}
	/* Q2 END */

}

/* 
 Name: "CalcOutputData" 
 Function: calculates output data by time.
 Arguments:
  t: time
  A, B, and C: the values of constants
  data: output data
 Return value: None
*/
void CalcOutputData(double t, double A, double B, double C, struct OUTPUT_DATA* data){

	/* Q3 START */
    data->x =sin(A * 2 * PI * t / 2 + C);
    data->y=sin(B * 2 * PI * t / 2);
	/* Q3 END */
 
}

// main function.
int main(void)
{
	FILE   *fp;
	struct OUTPUT_DATA data[256];
	char DataFileName[256] = "IntTest.dat";
	double A = 0;
	double B = 0;
	double C = 0;
	int FiveDigitId = 0;

	// Input your ID (5-digits). 
	// ex. input 12345, if your ID is BQ12345.
	printf("Please input your ID (5-digits):");
	scanf("%d", &FiveDigitId);
	printf("\n");

	/* Q4 START */
	// Analyze your ID.
	SetParamsFromId(FiveDigitId, &A, &B, &C);
	/* Q4 END */

	// Open the file.
	fp = fopen(DataFileName, "w");
	if (fp == NULL) {
	    printf("The file cannot be opened.\n");
	      return(-1);
	} else {
	    printf("The file has been opened.\n");
	}

	int i=0;
	int num = sizeof(data) / sizeof(data[0]);
	double t = 0;

	// Calc. output & writing it to the file. 
	fprintf(fp, "t, x, y,\r\n");

	printf("Loop started.\n");
	for(i<0;i<num;i++){

		/* Q5 START */
		CalcOutputData(t, A, B, C, &data[i]);
		/* Q5 END */

		fprintf(fp, "%f, %f, %f,\r\n", t, data[i].x, data[i].y );

		/* Q6 START */
		if ( t > 2.00 ) {
            
		/* Q6 END */
			printf("Loop ended.\n");
			break;
		}
		

		t += ST;
	}

	// Close the file.
	fclose(fp);
	printf("The file has been closed.\n");
	
	return 0;
}