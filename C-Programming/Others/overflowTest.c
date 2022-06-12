#include <stdio.h>

int main(void) {
  unsigned short int aNumber=65535;

  printf("the number is %hu\n", aNumber);
  aNumber = aNumber + 1;
  printf("the number is now %hu\n", aNumber);

  aNumber=0;
  printf("the number is %hu\n", aNumber);
  aNumber = aNumber - 1;
  printf("the number is now %hu\n", aNumber);

  return 0;
}
