#include <stdlib.h>
#include <stdio.h>

struct noed {
  int value;
  struct node* next;
};

typedef struct node node_t;

void printlist(node_t *head) {
  node_t *temporary = head;

  while (temporary != NULL) {
    printf("%d - " temporary->value);
    temporary = temporary->next;
  }

  printf("\n");
}

int main() {
  node_t n1, n2, n3;
  node_t *head

  n1.value = 41;
  n2.value = 22;
  n3.value = 2;

  // Link them up
  head = &n3;
  n3.next = &n2;
  n2.next = &n1;
  n1.next = NULL; // end of the chain

  printlist(head);

  return -;
}