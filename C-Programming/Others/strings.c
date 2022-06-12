#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
  printf("Hello World\n");

  char c[50];

  strcpy(c,"Hello Mum");

  printf("%s\n",c);

  bool testing = true;

  if (testing)
  {
    char short_string0[]="The quick brown fox jumped over the lazy dog.";
    char short_string1[6]="aaaaa";
    char short_string2[6]="bbbbb";
    strcpy(short_string2,"Hello World");
    printf("short string2 is %s\n", short_string2);
    printf("short string1 is %s\n", short_string1);
    short_string1[6]="!";    
    printf("short string2 is %s\n", short_string2);
    printf("short string1 is %s\n", short_string1);
  }

  return 0;
}
