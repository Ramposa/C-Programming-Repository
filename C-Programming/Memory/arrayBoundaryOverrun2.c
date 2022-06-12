#include <stdio.h>

int main(void) {

int a[] = {1,1,1,1,1,1};
int b[] = {2,2,2,2,2,2};
int c[] = {4,4,4,4};

for (int i=0;i<6;i++)
{
  printf("array a[%d] %d at address %p\n",i,a[i], &a[i]);
}
printf("\n");

for (int i=0;i<6;i++)
{
  printf("array b[%d] %d at address %p\n",i,b[i], &b[i]);
}
printf("\n");

for (int i=0;i<4;i++)
{
  printf("array c[%d] %d at address %p\n",i,c[i], &c[i]);
}
printf("\n");


for (int i=-2; i<10; i++)
{
  b[i]=3;
  printf("setting array b[%d] to %d at address %p\n",i,b[i], &b[i]);
}
printf("\n");

for (int i=0;i<6;i++)
{
  printf("array a[%d] %d at address %p\n",i,a[i], &a[i]);
}
printf("\n");

for (int i=0;i<6;i++)
{
  printf("array b[%d] %d at address %p\n",i,b[i], &b[i]);
}
printf("\n");

for (int i=0;i<4;i++)
{
  printf("array c[%d] %d at address %p\n",i,c[i], &c[i]);
}
printf("\n");

return 0;
}
