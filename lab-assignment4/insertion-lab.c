// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

// To perform insertion sort of integers stored in a file and display the output and store it in another file.
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 10 // Maximum digits for a number

int main()
{
  FILE *fp;
  int arr[10], temp;
  int count, i, j;
  /*count will have the total number of elements in the array*/

  /*read the file*/
  fp = fopen("Input1.txt", "r");
  if (fp == NULL)
  {
    // if file returns NULL then can't open the file
    printf("\n Cannot open the file \n");
    exit(0);
  }

  count = sizeof(arr) / sizeof(arr[0]); // set count to number of elements in the array
  char strNum[MAX_LINE_LENGTH]; // char array to hold numbers from input file
  
  i = 0;
  // reads lines from the file and converts to integers
  while (fgets(strNum, MAX_LINE_LENGTH, fp) && i < count)
  {
    arr[i++] = atoi(strNum);
  }

  // insertion sort
  for (i = 0; i < count; i++)
  {
    temp = arr[i];
    for (j = i - 1; j >= 0 && arr[j] > temp; j--)
    {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = temp;
  }

  fclose(fp); // close input file

  // write the sorted array to the file
  fp = fopen("output.txt", "w");

  for (i = 0; i < count; i++)
  {
    fprintf(fp, "%d\n", arr[i]);
  }

  fclose(fp); // close output file

  return 0;
}