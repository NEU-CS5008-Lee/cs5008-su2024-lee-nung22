// name: Nicholas Ung
// email: ung.n@northeastern.edu

#include <stdio.h>   // standard input/output library
#include <stdbool.h> // standard boolean library: bool, true, false

#define MAXSIZE 100

// Check if the stack is empty
bool isEmpty (int* s, int t) {
  // returns true if t = -1
  return t == -1;
}

// Check if the stack is full
bool isFull (int* s, int t) {
  // returns true if no more room in the stack
  return t == MAXSIZE - 1;
}

// Push an element onto the stack
void push(int v, int* s, int* tp) {
  // put v onto the top of the stack s unless it is already full
  if(isFull(s, *tp)) {
    printf("Stack is full. Cannot push %d\n", v);
  } else {
    (*tp)++;
    s[*tp] = v;
  }
    return;
}

// Pop an element from the stack
int pop (int* s, int* tp) {
  // return the top entry in the stack unless stack is empty
  // update s and *tp -- requires top to be passed by reference!
  if(isEmpty(s, *tp)) {
    printf("Stack is empty. Cannot pop\n");
    return -1;
  } else {
    int poppedVal = s[*tp];
    (*tp)--;
    return poppedVal;
  }
  
}

int main () {

  int stack1[MAXSIZE]; // array in which stack will live
  int top1 = -1;       // top valid location in stack, -1 == empty
  int stack2[MAXSIZE]; // array in which stack will live
  int top2 = -1;       // top valid location in stack, -1 == empty
  
  printf("pushing: 1, 2, 3, 4, 5 onto first stack\n");
  printf("pushing: 100, 200, 300, 400, 500 onto second stack\n\n");
  push(1, stack1, &top1);
  push(2, stack1, &top1);
  push(3, stack1, &top1);
  push(4, stack1, &top1);
  push(5, stack1, &top1);
  push(100, stack2, &top2);
  push(200, stack2, &top2);
  push(300, stack2, &top2);
  push(400, stack2, &top2);
  push(500, stack2, &top2);

  printf("popping alternating stacks:\n");
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  printf("1> %d\n",pop(stack1, &top1));
  printf("2> %d\n",pop(stack2, &top2));
  return 0;
}
