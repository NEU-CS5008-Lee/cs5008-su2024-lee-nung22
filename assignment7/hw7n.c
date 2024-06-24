// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

// Hash table with doubly linked list for chaning/
#include <stdio.h>
#include <stdlib.h>

struct bucket *hashTable = NULL;
int BUCKET_SIZE = 10;

// node struct
struct node
{
  // node struct
  struct node *next; // pointer to the next node in the linked list
  struct node *prev; // pointer to the previous node in the linked list
  int key; // key value of the node
  int value; // value stored in the node
};

// bucket struct
struct bucket
{
  struct node *head; // pointer to the head of the linked list
  struct node *tail; // pointer to the tail of the linked list
};

// create a new node
struct node *createNode(int key, int value)
{
  // Allocate memory for the new node
  struct node *newNode = (struct node *)malloc(sizeof(struct node));

  // Set the key and value of the new node
  newNode->key = key;
  newNode->value = value;

  // Set the next and previous pointers of the new node to NULL
  newNode->next = NULL;
  newNode->prev = NULL;

  // Return the newly created node
  return newNode;
}

//  hash function with %
int hashFunction(int key)
{
  return key % BUCKET_SIZE;
}

//  insert a new key
void add(int key, int value)
{
  int hashIndex = hashFunction(key);
  struct node *newNode = createNode(key, value);

  // If the bucket is empty, set the head and tail of the bucket to the new node, 
  // else add the new node to the end of the linked list
  if (hashTable[hashIndex].head == NULL)
  {
    hashTable[hashIndex].head = newNode;
    hashTable[hashIndex].tail = newNode;
  }
  else
  {
    hashTable[hashIndex].tail->next = newNode;
    newNode->prev = hashTable[hashIndex].tail;
    hashTable[hashIndex].tail = newNode;
  }
}

// remove a key
void remove_key(int key)
{
  // Calculate the hash index for the given key
  int hashIndex = hashFunction(key);
  // Get the head node of the linked list at the hash index
  struct node *iterator = hashTable[hashIndex].head;
  struct node *temp;

  // If the key is found in the linked list, remove the node
  while (iterator != NULL)
  {
    // Check if the current node's key matches the given key
    if (iterator->key == key)
    {
      // If the current node is the head of the linked list
      if (iterator->prev == NULL)
      {
        // Update the head of the linked list to the next node
        hashTable[hashIndex].head = iterator->next;
      }
      else
      {
        // Update the previous node's next pointer to skip the current node
        iterator->prev->next = iterator->next;
      }

      // If the current node is the tail of the linked list
      if (iterator->next == NULL)
      {
        // Update the tail of the linked list to the previous node
        hashTable[hashIndex].tail = iterator->prev;
      }
      else
      {
        // Update the next node's previous pointer to skip the current node
        iterator->next->prev = iterator->prev;
      }

      // Free the memory allocated for the current node
      temp = iterator;
      iterator = iterator->next;
      free(temp);
    }
    else
    {
      // Move to the next node in the linked list
      iterator = iterator->next;
    }
  }
}

// search a value using a key
void search(int key)
{
  // Calculate the hash index for the given key
  int hashIndex = hashFunction(key);
  // Get the head node of the linked list at the hash index
  struct node *node = hashTable[hashIndex].head;

  // Traverse the linked list to find the node with the matching key
  while (node != NULL)
  {
    // Check if the current node's key matches the given key
    if (node->key == key)
    {
      // Print the key and value of the node
      printf("Key: %d, Value: %d\n", node->key, node->value);
      return;
    }
    // Move to the next node in the linked list
    node = node->next;
  }

  // If the key is not found in the linked list
  printf("Key not found\n");
}

void display()
{
  struct node *iterator;

  printf("\n========= display start ========= \n");
  for (int i = 0; i < BUCKET_SIZE; i++)
  {
    iterator = hashTable[i].head;
    printf("Bucket[%d] : ", i);
    while (iterator != NULL)
    {
      printf("(key: %d, val: %d)  <-> ", iterator->key, iterator->value);
      iterator = iterator->next;
    }
    printf("\n");
  }
  printf("\n========= display complete ========= \n");
}

int main()
{
  hashTable = (struct bucket *)malloc(BUCKET_SIZE * sizeof(struct bucket));

  add(0, 1);
  add(1, 10);
  add(11, 12);
  add(21, 14);
  add(31, 16);
  add(5, 18);
  add(7, 19);

  display();

  remove_key(31);
  remove_key(11);

  display();

  search(11);
  search(1);
}
