// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
} node_t;

typedef struct list
{
  struct node *head;
} List;

/*-----creating the nodes----------*/
node_t *newNode(int num)
{
  node_t *temp = (node_t *)malloc(sizeof(node_t));
  temp->data = num;
  temp->next = NULL;
  return temp;
}
/*---creating linked list----*/
List *init_LL()
{
  List *l = (List *)malloc(sizeof(List));
  l->head = NULL;
  return l;
}

/*---Insert the nodes at the begining of the list---*/
void insertFirst(List *l, int data)
{
  node_t *temp = newNode(data);
  temp->next = l->head;
  l->head = temp;
}

/*----display the output--------*/
void display(List *l)
{
  node_t *temp;
  temp = l->head;
  while (temp != NULL)
  {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

/*-------reversing the linked list using recursion------*/
void reverse(List *l, node_t *ptr)
{
  // insert your code here

  // Base case: if the next node is NULL, set the head of the linked list to the current node
  if (ptr->next == NULL)
  {
    l->head = ptr;
    return;
  }

  // Recursively call the function to reverse the linked list
  reverse(l, ptr->next);

  node_t *temp = ptr->next; // Store the next node in a temporary variable
  temp->next = ptr;         // Set the next node to the current node
  ptr->next = NULL;         // Set the current node to NULL

  return;
}

/*----Free the nodes-----*/
void freenode(List *l)
{
  node_t *temp;
  while (l->head)
  {
    temp = l->head->next;
    free(l->head);
    l->head = temp;
  }
}
/*-----Main program--------------*/
int main()
{
  List *list = init_LL();

  insertFirst(list, 44);
  insertFirst(list, 33);
  insertFirst(list, 22);
  insertFirst(list, 11);
  display(list);
  reverse(list, list->head);
  display(list);

  freenode(list);
  free(list);
  return 0;
}
