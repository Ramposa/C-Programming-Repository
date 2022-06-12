#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
typedef struct node {
  int Index; 
  char Name[20];
  int DOBDay;
  int DOBMonth;
  int DOBYear;
  struct node *left;
  struct node *right;
} node;

int CreateIndex(int day, int month, int year);
node* CreateNode(char Name[20], int day, int month, int year);
void InsertNode(node **root, node *new_node);
void DisplayBirthday(node *anode);
void BirthdaysInOrder(node *anode);
void BirthdaysBetween(node *anode, int index1, int index2);
int main(void) {
  
  node *root = NULL;

  InsertNode(&root,CreateNode("Bill",1,5,2000));
  InsertNode(&root,CreateNode("Jane",5,2,2001));
  InsertNode(&root,CreateNode("Dave",12,2,1999));
  InsertNode(&root,CreateNode("Kate",23,7,2000));



  printf("Birthdays in order\n");
  BirthdaysInOrder(root);

  printf("\n\n");

  printf("Birthdays in order between 1/1/2000 and 31/12/2000\n");
  BirthdaysBetween(root,CreateIndex(1,1,2000),CreateIndex(31,12,2000));



  return 0;
}



int CreateIndex(int day, int month, int year)
{
  return ((year*10000) + (month * 100) + day);
}

node* CreateNode(char Name[20], int day, int month, int year)
{
    node *temp = (node*)malloc(sizeof(node));
    strcpy(temp->Name,Name);
    temp->DOBDay = day;
    temp->DOBMonth = month;
    temp->DOBYear = year;
    temp->Index = CreateIndex(day,month,year);
    temp->left = temp->right = NULL;
  
    return temp;
}

void InsertNode(node **root, node *new_node)
{
  if (*root==NULL)
  {
      (*root) = new_node;
      return;
  }

  node *temp = (*root);
  bool added = false;
  while (!added)
  {
      if (new_node->Index < temp->Index)
      {
          if (temp->left == NULL)
          {
              temp->left = new_node;
              added = true;
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
              temp->right = new_node;
              added = true;
          }
          else
          {
              temp = temp->right;
          }
      }
  }
}

void DisplayBirthday(node *anode)
{
  printf("%s : %02d/%02d/%04d\n", anode->Name, anode->DOBDay,anode->DOBMonth,anode->DOBYear);
}


void BirthdaysInOrder(node *anode)
{
    // Test only needed for the first call when anode == root
    if (anode!=NULL)
    {
        // if the current node has a left call TraverseTree(anode->left)
        if (anode->left!=NULL)
        {
            BirthdaysInOrder(anode->left);
        }

        DisplayBirthday(anode);

        // if the current node has a right call TraverseTree(anode->right)
        if (anode->right!=NULL)
        {
            BirthdaysInOrder(anode->right);
        }
    }
    else
    {
        // should only come here if TraverseTree(&root) is called when root == NULL
        printf("node is null\n");
    }  
}


void BirthdaysBetween(node *anode, int index1, int index2)
{
  // Test only needed for the first call when anode == root
  if (anode!=NULL)
  { 
    // if the current node has a left call TraverseTree(anode->left)
    if (anode->left!=NULL)
    {
        BirthdaysBetween(anode->left,index1,index2);
    }

    if ((anode->Index>=index1)&&(anode->Index<=index2))
    {
      DisplayBirthday(anode);
    }

    // if the current node has a right call TraverseTree(anode->right)
    if (anode->right!=NULL)
    {
      BirthdaysBetween(anode->right,index1,index2);
    }
  }
  else
  {
    // should only come here if TraverseTree(&root) is called when root == NULL
    printf("node is null\n");
  }  
}
