// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Get the number of consecutive occurrences of a character
int getrepeat(char *str, char ch)
{
  char *ptr = str;
  int repeat = 0;
  while (*ptr == ch)
  {
    ptr += 1;
    repeat++;
  }
  return repeat;
}

// Run-length encode the input string
char *runlengthencoding(char *str, char *rle)
{
  char *ptr = str;
  char *ptrend = &str[strlen(str)];
  char encoding[100];
  int repeat;
  strcpy(rle, "");

  while (ptr < ptrend)
  {
    repeat = getrepeat(ptr, *ptr);
    if (repeat > 1)
    {
      sprintf(encoding, "%c%d", *ptr, repeat);
      strcat(rle, encoding);
      ptr = ptr + repeat;
    }
    else
    {
      sprintf(encoding, "%c", *ptr);
      strcat(rle, encoding);
      ptr++;
    }
  }

  return rle;
}

// Get the count of repeated characters from the RLE string
int getcount(char *rle)
{
  int count = 0;
  //
  // Add your code here to return count for the current char
  //

  while (isdigit(*rle))
  {
    count = count * 10 + (*rle - '0');
    rle ++;
  }

  return count;
}

// Decode the RLE string back to the original string
char *decode_rle(char *rle, char *str)
{
  char *ptr = rle;
  char *ptrend = &rle[strlen(rle)];
  char decoding[100];
  int i = 0, j = 0, count = 0, digit = 0;
  strcpy(str, "");
  //
  // Add your code here to decode rle
  //

    // Decode the RLE string
    while (*ptr != '\0')
    {
        char ch = *ptr++;
        if (isdigit(*ptr))
        {
            char *count_ptr = ptr;
            count = getcount(count_ptr);
            while (isdigit(*ptr)) ptr++; // Move the original pointer past the digits
        }
        else
        {
            count = 1;
        }

        for (int j = 0; j < count; j++)
        {
            str[i++] = ch;
        }
    }

  str[i] = '\0';
  return str;
}

int main()
{
  char str_org[] = "WWWWWWWWWWWWWWWWWWWWWWWWWWWWbAAAABBCBBCBBCaaa";
  char rle[100];
  runlengthencoding(str_org, rle);
  printf("str_org:[%s] => rle:[%s]\n", str_org, rle);

  char str_dec[100];
  decode_rle(rle, str_dec);
  printf("rle:[%s] => str_dec:[%s]\n", rle, str_dec);
  return 0;
}
