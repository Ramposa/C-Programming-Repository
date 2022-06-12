#include <stdio.h>
#include <string.h>

typedef struct Book {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Book;

void printBook( Book *book );

int main(void) {
  
  Book book1;
  strcpy(book1.title, "Lovecraft Country");
  strcpy(book1.author, "Matt Ruff");
  strcpy(book1.subject, "Horror");
  book1.book_id = 19334;

  printBook(&book1);


  return 0;
}

void printBook(Book *book)
{
  printf("Title : %s\n", book->title);
  printf("Author : %s\n", book->author);
  printf("Subject : %s\n", book->subject);
  printf("Book ID : %d\n", book->book_id);
}

// Exercise 1 Tasks
// 1. Add a float to the Book structure called `price`
// 2. Add a line of code setting the price
// 3. Modify printBook to also output the price of the book in pounds. It must show exactly two numbers after the decimal place (to represent the pence i.e. £5.99 or £3.00)