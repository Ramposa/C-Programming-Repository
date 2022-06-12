#include <stdio.h>
#include <string.h>

typedef struct Book {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
   float price;
} Book;

void printBook( Book *book );

int main(void) {
  
  Book book1;
  strcpy(book1.title, "Lovecraft Country");
  strcpy(book1.author, "Matt Ruff");
  strcpy(book1.subject, "Horror");
  book1.book_id = 19334;
  book1.price = 5.99;


  printBook(&book1);


  return 0;
}

void printBook(Book *book)
{
  printf("Title : %s\n", book->title);
  printf("Author : %s\n", book->author);
  printf("Subject : %s\n", book->subject);
  printf("Book ID : %d\n", book->book_id);
  printf("Price : %.2f\n", book->price);
}
