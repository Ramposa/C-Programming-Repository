#include <stdio.h>

int main () {

  int var = 20;       
  int *ip1 = &var;    
  int *ip2 = NULL;

  if (ip1!=NULL)
  {
    printf("Address stored in ip1 variable: %p\n", ip1 );
    printf("Value stored in ip1 location: %d\n", *ip1 );
  }
  else
  {
    printf("ip2 invalid pointer\n");
  }

  if (ip2!=NULL)
  {
    printf("Address stored in ip2 variable: %p\n", ip2 );
    printf("Value stored in ip2 location: %d\n", *ip2 );
  }
  else
  {
    printf("ip2 invalid pointer\n");
  }

  return 0;
}