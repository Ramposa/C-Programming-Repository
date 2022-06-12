#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;
 
// function to create a new note & return a pointer to it
node *NewNode(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// Append the new data to the start of the stack
void push(node *new_node, node** stack){
    // Point the new node's next at the current top of the stack
    new_node->next = *stack;  
    
    // Make new node the top of the stack
    (*stack) = new_node;  
}

// Remove data from the top of the stack and return it
node* pop(node** stack){
    if(*stack != NULL)
    {
        node* tempPtr = *stack;
        *stack = (*stack) -> next;
        return tempPtr;
    }
    else
    {
        printf("The stack is empty.\n");
        return NULL;
    }
}

// Display the element at the top of the stack
// should always test for isEmpty()  first
node* peek(node* stack){
    if(stack != NULL){
        return stack;
    }
    else
    {
        printf("The stack is empty.\n");
        return NULL;
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



int main()
{
    node *Stack = NULL;

    push(NewNode(1),&Stack);
    push(NewNode(2),&Stack);

    printf("%d\n",pop(&Stack)->data);
    printf("%d\n",pop(&Stack)->data);

}
