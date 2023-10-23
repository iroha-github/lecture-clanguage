/*
 *  課題2-1
 */
#include <stdio.h>

int main()
{
  int A;
  int B;

  printf("商品Aの価格：\n");
  scanf("%d", &A);

  printf("商品Bの価格：\n");
  scanf("%d", &B);
  
  printf("商品Aの価格は %d円 で商品Bの価格は %d円 ですね\n", A,B);

  printf("商品Aのみを購入したときの代金は %d円 です\n", A);
  printf("商品Aと商品Bを購入したときの代金は %d円です\n", A+B);
  printf("用品Aを３割引きで購入したときの代金は%f円です\n", A*0.7);

  return 0;
}