#include <stdio.h>

int main(void) {

int a[] = {1,1,1,1,1};
int b[] = {2,2,2,2,2};
int c[] = {3,3,3,3,3};

for (int i=0;i<5;i++)
{
  printf("array a[%d] %d at address £%p\n",i,a[i], &a[i]);
}
printf("\n");

for (int i=0;i<5;i++)
{
  printf("array b[%d] %d at address £%p\n",i,b[i], &b[i]);
}
printf("\n");

for (int i=0;i<5;i++)
{
  printf("array c[%d] %d at address £%p\n",i,c[i], &c[i]);
}
printf("\n");

printf("\n");
printf("array a[%d] %d at address £%p\n",0,a[0], &a[0]);
printf("array b[%d] %d at address £%p\n",0,b[0], &b[0]);
printf("array c[%d] %d at address £%p\n",0,c[0], &c[0]);

return 0;
}
