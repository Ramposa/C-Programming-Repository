#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int data; 

  struct node *left;
  struct node *right;
} node;

node* CreateNewNode(int data);
void InsertNode(node **root, int data);
void DisplayTree(node *anode);


int main(void) {

  node* root = NULL;

  InsertNode(&root, 10);
  InsertNode(&root, 5);
  InsertNode(&root, 11);
  InsertNode(&root, 7);

  DisplayTree(root);

  return 0;
}



node* CreateNewNode(int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}


void InsertNode(node **root, int data){
    node *newnode = CreateNewNode(data);

    if (*root==NULL)
    {
        (*root) = newnode;
        return;
    }

    node *temp = (*root);
    bool in = false;
    while (!in)
    {
        if (newnode->data < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = newnode;
                in = true;
            }
            else
            {
                temp = temp->left;
            }
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = newnode;
                in = true;
            }
            else
            {
                temp = temp->right;
            }
        }
    }
}
