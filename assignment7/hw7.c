// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

// format of document is a bunch of data lines beginning with an integer (rank which we ignore)
// then a ',' followed by a double-quoted string (city name)
// then a ',' followed by a double-quoted string (population) - ignore commas and covert to int; or (X) - convert to 0
// then a lot of entries that are ignored

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXSTRING 200

// finite state machine states
#define STARTSTATE 0
#define S1 1
#define S2 2
#define S3 3
#define S4 4
#define S5 5
#define S6 6
#define ACCEPTSTATE 10
#define ERRORSTATE 11

// check if a character c is a digit
bool isDigit(char c)
{
  return '0' <= c && c <= '9';
}

// append character c to string s
void appendChar(char *s, char c)
{
  int len = strlen(s);
  s[len] = c;
  s[len + 1] = '\0';
}

// convert a population string to an integer
int convertPopulation(const char *popStr)
{
  int pop = 0;
  for (int i = 0; i < strlen(popStr); i++)
  {
    if (isDigit(popStr[i]))
    {
      pop = pop * 10 + (popStr[i] - '0');
    }
  }
  return pop;
}

int main()
{
  char inputLine[MAXSTRING]; // temporary string to hold input line
  char cityStr[MAXSTRING];   // city name
  char popStr[MAXSTRING];    // population string
  int state;                 // FSM state
  int nextChar;              // index of next character in input string
  char temp[MAXSTRING];      // temp string to build up extracted strings from input characters

  FILE *fp;
  fp = fopen("pop.csv", "r");

  if (fp != NULL)
  {
    while (fgets(inputLine, MAXSTRING, fp) != NULL)
    {
      nextChar = 0;
      state = STARTSTATE;
      strcpy(temp, "");    // temp = ""
      strcpy(cityStr, ""); // cityStr = ""
      strcpy(popStr, "");  // popStr = ""

      if (strlen(inputLine) == 0)
      {
        state = ERRORSTATE;
      }

      while ((state != ERRORSTATE) && (state != ACCEPTSTATE))
      {
        switch (state)
        {
        case STARTSTATE:
          if (isDigit(inputLine[nextChar]))
          {
            state = S1;
          }
          else
          {
            state = ERRORSTATE;
          }
          break;

        case S1:
          if (isDigit(inputLine[nextChar]))
          {
            state = S1;
          }
          else if (inputLine[nextChar] == ',')
          {
            state = S2;
          }
          else
          {
            state = ERRORSTATE;
          }
          break;

        case S2:
          if (inputLine[nextChar] == '"')
          {
            state = S3;
          }
          else
          {
            state = ERRORSTATE;
          }
          break;

        case S3:
          if (inputLine[nextChar] == '"')
          {
            state = S4;
          }
          else
          {
            appendChar(cityStr, inputLine[nextChar]);
          }
          break;

        case S4:
          if (inputLine[nextChar] == ',')
          {
            state = S5;
          }
          else
          {
            state = ERRORSTATE;
          }
          break;

        case S5:
          if (inputLine[nextChar] == '"')
          {
            state = S6;
          }
          else if (inputLine[nextChar] == '(')
          {
            state = ACCEPTSTATE;
            strcpy(popStr, "0");
          }
          else
          {
            state = ERRORSTATE;
          }
          break;

        case S6:
          if (isDigit(inputLine[nextChar]))
          {
            appendChar(popStr, inputLine[nextChar]);
          }
          else if (inputLine[nextChar] == ',')
          {
            // do nothing, stay in S6
          }
          else if (inputLine[nextChar] == '"')
          {
            state = ACCEPTSTATE;
          }
          else
          {
            state = ERRORSTATE;
          }
          break;

        case ACCEPTSTATE:
          break;

        default:
          state = ERRORSTATE;
          break;
        } // end switch

        nextChar++;
      } // end while state machine loop

      // only process valid lines
      if (state == ACCEPTSTATE)
      {
        int popInt = convertPopulation(popStr);
        printf("> %.60s\n", inputLine);
        printf("[%.30s]: %d\n", cityStr, popInt);
      }

    } // end while file input loop

    fclose(fp);
  }
  else
  {
    printf("File not found!\n");
  }

  return 0;
}
