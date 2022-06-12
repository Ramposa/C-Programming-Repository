#include <stdio.h>
#include<stdlib.h> 

typedef struct node {
  int val;

  struct node *next;
} node;




node* newNode(int value)
{
node *new_node = NULL;
new_node =malloc(sizeof(node));

if (new_node != NULL)
{
  new_node->val = value;
  new_node->next = NULL;
}
return new_node;
}

void insertNode(node **head_ptr, int value)
{ 
  if(*head_ptr==NULL){
    *head_ptr = newNode(value);
  }
  else
  { node *head = *head_ptr;
    while(head->next!=NULL){
        head = head->next;
    }
    head->next = newNode(value);
  }
}


int main(void) {
node *head = NULL;
insertNode(&head, 32);
insertNode(&head, 35);
insertNode(&head, 12);
insertNode(&head, 57);
node *temp = head;
if (temp!=NULL)
{
  while (temp->next != NULL)
  {
    printf("%d\n",temp->val);
    temp = temp->next;
  }
} 
}
