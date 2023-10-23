#include <stdio.h>

// main()
void main()
//↑何故main()なの？

{
  int i = 0;

  while(1){
    printf("i = %d\n", i);
    i++;
    if(i>10) break;
  }
  printf("Out of the while loop.\n");
}
