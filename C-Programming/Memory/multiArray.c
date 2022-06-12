#include <stdio.h>

int main(void) {
  int a[10][15];
  int *ptr = &a[0][0];

for (int i=0;i<(10*15);i++)
{
  *(ptr + i)=i;
}

for (int i=0;i<10;i++)
{
  for (int j=0;j<15;j++)
  {
    printf("%d, ",a[i][j]);
  }
  printf("\n");
}
