#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;
// Append the new data to the start of the stack
void push(int data, node** stack){
    // Create a new node
    node* new_node = (struct node*)malloc(sizeof(node)); 

    // Store the data in the new node
    new_node->data = data; 
    
    // Point the new node's next at the current top of the stack
    new_node->next = *stack;  
    
    // Make new node the top of the stack
    (*stack) = new_node;  
}

// Remove data from the top of the stack and return it
int pop(node** stack){
    if(*stack != NULL)
    {
        int popped = (*stack) -> data;
        node* tempPtr = *stack;
        *stack = (*stack) -> next;
        free(tempPtr);
        return popped;
    }
    else
    {
        printf("The stack is empty.\n");
        return -1;
    }
}

// Display the element at the top of the stack
// should always test for isEmpty()  first
int peek(node* stack){
    if(stack != NULL){
        return stack -> data;
    }
    else
    {
        printf("The stack is empty.\n");
        return -1;
    }
}

bool isEmpty(node* stack){
    if(stack != NULL){
        return true;
    }
    else
    {
        return false;
    }
}

void displayStack(node* stack){
  while(stack!=NULL)
  {
    printf("%d, ",stack->data);
    stack = stack ->next;
  }
  printf("\n");
}

int main()
{
    node *Stack = NULL;

    push(1,&Stack);
    push(2,&Stack);
    push(7,&Stack);
    push(2,&Stack);

    displayStack(Stack);

    printf("pop() returns %d\n", pop(&Stack));
    displayStack(Stack);

    printf("peek() returns %d\n", peek(Stack));
    displayStack(Stack);

    return 0;
}
