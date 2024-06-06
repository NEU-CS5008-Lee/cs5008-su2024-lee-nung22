// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LIMIT 200
#define RAND_RANGE 95 // 95 printing characters x20-x7E

// return random character
char randChar()
{
  // 0 -> x20 -> ' '
  // 1 -> x21 -> '!'
  // ,,,
  // 94 -> x7E -> '~'
  // see https://ascii.cl
  return ((char)((rand() % RAND_RANGE) + 0x20));
}

// return location mid way between left and right
int midPoint(int left, int right)
{
  // note integer division always returns an integer
  return (left + (right - left) / 2);
}

// min of two integers
int findMin(int a, int b)
{
  if (a <= b)
  {
    return a;
  }
  else
  {
    return b;
  }
}

// merge two sorted sub arrays
void mergeIt(
    char *data,
    int leftStart,
    int leftStop,
    int rightStart,
    int rightStop)
{

  // ADD YOUR CODE HERE

  // Create temporary array to store merged data
  char temp[LIMIT];

  // Initialize variables to keep track of current index in each subarray
  int leftIdx = leftStart;
  int rightIdx = rightStart;
  int tempIdx = 0;

  // Merge the two subarrays
  while (leftIdx <= leftStop && rightIdx <= rightStop)
  {
    if (data[leftIdx] < data[rightIdx])
    {
      temp[tempIdx] = data[leftIdx];
      leftIdx++;
    }
    else
    {
      temp[tempIdx] = data[rightIdx];
      rightIdx++;
    }
    tempIdx++;
  }

  // Copy any remaining elements from the left subarray
  while (leftIdx <= leftStop)
  {
    temp[tempIdx] = data[leftIdx];
    leftIdx++;
    tempIdx++;
  }

  // Copy any remaining elements from the right subarray

  while (rightIdx <= rightStop)
  {
    temp[tempIdx] = data[rightIdx];
    rightIdx++;
    tempIdx++;
  }

  // Copy the merged data back into the original array
  for (int i = 0; i < tempIdx; i++)
  {
    data[leftStart + i] = temp[i];
  }

  return;
}

// break data array up into halves until down to single elements
// then merge them
void msort(char *data, int left, int right)
{

  if (left >= right)
  {
    // base case of 1 element
    return;
  }
  else
  {
    // Sort left half
    msort(data, left, midPoint(left, right));

    // Sort right half
    msort(data, midPoint(left, right) + 1, right);

    // Merge left and right halves
    mergeIt(
        data,
        left, midPoint(left, right),
        midPoint(left, right) + 1, right);
  }
  return;
}

int main()
{

  char source[LIMIT]; // Array to hold input data values

  int i;        // Loop variable
  int j;        // Loop variable
  int smallest; // Current smallest element

  // Seed random numbers
  srand((unsigned)time(NULL));

  // Initialize source array with random character
  for (i = 0; i < LIMIT; i++)
  {
    source[i] = randChar();
  }

  // Print out source array in rows of 20 elments
  printf("Source array:\n");
  for (i = 0; i < ((LIMIT / 20) + 1); i++)
  {
    for (j = 0; j < 20; j++)
    {
      if (i * 20 + j < LIMIT)
      {
        printf("%c ", source[i * 20 + j]);
      }
    }
    printf("\n");
  }
  printf("\n");

  // Do the sorting
  msort(source, 0, LIMIT - 1);

  // Print out sorted array in rows of 10
  printf("Destination array:\n");
  for (i = 0; i < ((LIMIT / 10) + 1); i++)
  {
    for (j = 0; j < 10; j++)
    {
      if (i * 10 + j < LIMIT)
      {
        printf("%c ", source[i * 10 + j]);
      }
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}
