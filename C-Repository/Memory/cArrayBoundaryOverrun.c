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

// Task Exercises
// 1 Resize the a[] array to store six integers and set them all to 1. Change the loops printing out a[] to match. Run the code - what is the effect?
// 2 Resize the b[] array to store six integers and set them all to 2. Change the loops printing out b[] to match. Run the code - what is the effect? Why is a[] now unaffected by overrunning b[]?
// 3 Change the loop that sets b[] to 3 from i<8 to i<10. Run the code. Does a[] change at all now?
// 4 Create a new array c[] immeadiately after creating b[]. Make it four long and set each value in it to 4. Print out all of c[] after printing out b[] each time. Run the code. Does c[] change?
// 5  Change the loop that sets b[] to 3 from int i=0 to int i=-2. Run the code. Does c[] change at all now? Why?