#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
  int val;

  struct node *next;
} node;

node* NewNode(int value);
void AddNodeToStartOfList(node **ptr_to_start, int value);
void AddNodeToEndOfList(node **ptr_to_start, int value);
void PrintLinkedList(node *start);

int main(void) {
  node *head = NULL; 
  AddNodeToStartOfList(&head,5);

  AddNodeToEndOfList(&head,7);
  AddNodeToEndOfList(&head,2);

  PrintLinkedList(head);
  
  return 0;
}

node* NewNode(int value)
{
  node *new_node = NULL;                // Create a pointer to a node structure, set it to NULL for safety
  new_node =malloc(sizeof(node));       // Set aside space in memory for a node structure. If this fails new_node will be set to NULL
  if (new_node != NULL)                 // Always ensure the node exists before accessing it.
  {
    new_node->val = value;              // Set data values as required
    new_node->next = NULL;              // Set next (and any other pointers to NULL)
  } 
  return new_node;
}

void AddNodeToStartOfList(node **ptr_to_start, int value)
{
  /*

  **ptr_to_start is a variable that stores a pointer to a pointer. 
  It is the address of the variable which stores the address of the first item in the list.
  **ptr_to_start is the address of head
  *ptr_to_start is the contents of the variable head, which is the address of the start of the list.
  If we change *ptr_to_start (note only one * here) we are changing the contents of head. 
  We are changing which node is the first node in the list.
  */

   node *temp = NewNode(value);   // Create a new node
   temp->next = *ptr_to_start;    // Set the new nodes next pointer to point to the start of the list
   *ptr_to_start = temp;          // Change head to point to the new node
}


void PrintLinkedList(node *start)
{
  // Prints the Linked list from *start
  // Note if you pass in the address of a node half way through the list it will print the
  // list from that point

//  node *temp = start;             //
  while (start!=NULL)
  {
    printf("%d\n",start->val);
    start = start->next;
  }
}

void AddNodeToEndOfList(node **ptr_to_start, int value)
{   
  node *new_node = NewNode(value);
  node *temp = *ptr_to_start;

  // if list is empty
  if (*ptr_to_start==NULL)
  {
    *ptr_to_start = new_node;
    return;
  }

  // If next is NULL we are on the last entry in the list (or we've broken our list!)
  while (temp->next != NULL)   
  {    
    temp = temp->next;         // Change our temp pointer from the current one to temp->next - "moving" us on to the next node
  } 
  temp->next = new_node;
  return;
}


/* Exercise Tasks
1. Write a function int ListLength(*start) which traverses the list, counts the number of nodes and returns that count.
2. Write a function AddNode(**ptr_to_start, int value)
    This function should insert a node in to a place in the list so that the list is stored 
    in ascending order of value. e.g. 3,7,9,122 etc
    If the list is empty it should add a new node at the start of the list
    If the list is not empty it should
      - traverse the list until it finds a value greater than value and insert a new node       before the node with the greater value
      - if it reaches the end of the list without finding a greater value,
          it should add a new node to the end of the list
3. Test the function from 1 with these values added in this order 5,6,2,7,4 and make sure you 
    get the correct output with PrintLinkedList
4. Write a function SortList(*start) which takes an unsorted list and rearranges it   
    in to a sorted list
   The function should implement a bubble sort and swap the values within the nodes around

Bubble Sort

  In a bubble sort we travese our way through a list from the start and test each node with the one after it. If the node value is greater than the one after it we swap the two nodes in the list.
  Once we've made it to the end of the list we return to the start and repeat the process.
  When he have done this a number of times equal to the length of the list minus 1 we can be sure we have sorted our list.

Use the following function calls to set up the list for testing

AddNodeToStartOfList(&head,5);
AddNodeToEndOfList(&head,7);
AddNodeToEndOfList(&head,2);
AddNodeToEndOfList(&head,1);
AddNodeToEndOfList(&head,4);
AddNodeToEndOfList(&head,3);



*/
