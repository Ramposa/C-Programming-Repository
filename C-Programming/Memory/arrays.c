#include <stdio.h>
#include <stdalign.h>

int main(void) {
  int f=99;
int e=-7;
int a[] = {1,1,1,1,1};
int Numbers[] = {8,8,8,8,8,8,8,8,8};
int b[] = {2,2};
int i=1;

for (i=-15;i<18;i++)
{
  printf("[%d] [%d] %p\n",i,Numbers[i], Numbers+i);
}
i=33;
printf("%zu %lu\n", alignof(int[]),sizeof(int));

printf("[%d] %p\n",i,&i);

return 0;
}
