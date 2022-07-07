#include <stdio.h>
#include <stdlib.h>

typedef struct page {
  int p;
  
} page;


typedef struct book {
  int i;
  int j;  
  page k;
} book;



void doSomething(book *Book, int *number);
int bookSum(book abook);


int main(void) {
  int num = 5;
  int *num_p = &num;

  book myBook;
  myBook.i = 1;
  myBook.j = 1;
  myBook.k.p = 1;

  doSomething(&myBook, num_p);

  printf("%d\n", myBook.k.p);

  return 0;
}


void doSomething(book *Book, int *number)
{

  (*number) = 7;  

  (*Book).i =5;
  (*Book).j =5;

  Book->i=5;  
  Book->j=5;  
  
  Book->k.p = 5;

}


int bookSum(book abook)
{
    return abook.i + abook.j;
}


book bookFunc(book aBook)
{
    aBook.i=7;
 // do whatever
 return  aBook;
}

