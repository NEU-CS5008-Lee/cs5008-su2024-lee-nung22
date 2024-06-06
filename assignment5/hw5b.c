// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 200
#define RAND_RANGE 95  // 95 printing characters x20-x7E

// return random character
char randChar() {
  // 0 -> x20 -> ' '
  // 1 -> x21 -> '!'
  // ,,,
  // 94 -> x7E -> '~'
  // see https://ascii.cl
  return ((char)((rand() % RAND_RANGE)+0x20));
}

// return the value of a char unless it is lower case
// in which case return the upper case of the character
char upperChar(char c){
  if ((c<'a') || (c>'z')){
    return(c);
  } else {
    // if you forget the displacement of lower to upper case
    // just let the computer figure it out for you!
    return(c-('a'-'A'));
  }
}



// pick pivot and then sort small and big parts 
void quicky(char* data, int left, int right) {

  // ADD YOUR CODE HERE

  // Base case: if the left index is greater than or equal to the right index, return
  if (left >= right) {
    return;
  }

  // Initialize variables to keep track of the left and right indices
  int leftIdx = left;
  int rightIdx = right;

  // Pick the pivot as the middle element
  char pivot = data[(left + right) / 2];

  // Loop until the left index is greater than the right index
  while (leftIdx <= rightIdx) {
    // Increment the left index until the element at the left index is greater than the pivot
    while (data[leftIdx] < pivot) {
      leftIdx++;
    }

    // Decrement the right index until the element at the right index is less than the pivot
    while (data[rightIdx] > pivot) {
      rightIdx--;
    }

    // If the left index is less than or equal to the right index
    if (leftIdx <= rightIdx) {
      // Swap the elements at the left and right indices
      char temp = data[leftIdx];
      data[leftIdx] = data[rightIdx];
      data[rightIdx] = temp;

      // Increment the left index and decrement the right index
      leftIdx++;
      rightIdx--;
    }
  }

  // Recursively sort the left and right subarrays
  quicky(data, left, rightIdx);
  quicky(data, leftIdx, right);

  return;
}



int main(){

  char source[LIMIT]; // array to hold input data values

  int i;             // loop variable
  int j;             // loop variable


  //seed random numbers
  srand((unsigned)time(NULL));

  //initialize source array with random character
  for (i=0; i<LIMIT; i++) {
    source[i] = randChar();
  }

  //print out source array in rows of 20 elments
  printf("Source array:\n");
  for (i=0; i < ((LIMIT/20)+1); i++) {
    for (j=0; j<20; j++) {
      if (i*20+j < LIMIT) {
	printf("%c ",source[i*20+j]);
      }
    }
    printf("\n");
  }
  printf("\n");

  // do the sorting
  quicky(source, 0, LIMIT-1);

  
  //print out sorted array in rows of 10
  printf("Destination array:\n");
  for (i=0; i < ((LIMIT/10)+1); i++) {
    for (j=0; j<10; j++) {
      if (i*10+j < LIMIT) {
	printf("%c ",source[i*10+j]);
      }
    }
    printf("\n");
  }
  printf("\n");
  
  return 0;
}
