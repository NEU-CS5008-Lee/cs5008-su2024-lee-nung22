// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

#include <stdio.h>
#include <string.h>

int compression(char arr[], int n, char res[])
{
  int i, j = 0, count;

  for (i = 0; i < n; i++)
  {
    // Count occurrences of the current character
    count = 1;
    while (i < n - 1 && arr[i] == arr[i + 1])
    {
      count++;
      i++;
    }

    // Append the character to the result
    res[j++] = arr[i];

    // Append the count if greater than 1
    if (count > 1)
    {
      char count_str[10];
      sprintf(count_str, "%d", count);
      for (int k = 0; count_str[k] != '\0'; k++)
      {
        res[j++] = count_str[k];
      }
    }
  }

  // Null-terminate the result string
  res[j] = '\0';

  return j; // Length of the compressed string
}

int main()
{
  char a[] = "aaaaaaaaaaaaaabbbbcccd";
  char res[50];
  int r, n = strlen(a); // n is the size of input array
  r = compression(a, n, res);
  printf("length of the compressed string:%d\n", r);
  printf("compressed string:%s\n", res);
  return 0;
}
