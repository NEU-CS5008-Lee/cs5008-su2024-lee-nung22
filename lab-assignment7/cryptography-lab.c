// Name: Nicholas Ung
// Email: ung.n@northeastern.edu

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*function to decrypt the data*/

/**
 * Encrypts the given text using a Caesar cipher with the specified key.
 *
 * @param text The text to be encrypted.
 * @param key The key to be used for encryption.
 */
void encrypt(char text[], int key)
{
  // Iterate through each character in the text
  for (int i = 0; text[i] != '\0'; i++)
  {
    // Check if the character is an alphabet
    if (isalpha(text[i]))
    {
      // Encrypt lowercase characters
      if (islower(text[i]))
      {
        text[i] = ((text[i] - 'a') + key) % 26 + 'a';
      }
      // Encrypt uppercase characters
      else
      {
        text[i] = ((text[i] - 'A') + key) % 26 + 'A';
      }
    }
  }
}

/**
 * Decrypts the given text using a specified key.
 *
 * @param text The text to be decrypted.
 * @param key The key used for decryption.
 */
void decrypt(char text[], int key)
{
  int i;
  for (i = 0; text[i] != '\0'; i++)
  {
    if (isalpha(text[i])) // Check if the character is an alphabet
    {
      if (islower(text[i])) // Check if the character is lowercase
      {
        text[i] = ((text[i] - 'a') - key + 26) % 26 + 'a'; // Decrypt lowercase character
      }
      else
      {
        text[i] = ((text[i] - 'A') - key + 26) % 26 + 'A'; // Decrypt uppercase character
      }
    }
  }
}

/*----------- Main program---------------*/
int main()
{
  char text[20];
  int keyvalue = 3;
  /*Input string */
  printf("Enter the message:  ");
  scanf("%s", text);
  printf("text input   = %s\n", text);

  /*call function to encrypt the data*/
  encrypt(text, keyvalue);
  printf("Encrypted value = %s\n", text);

  /*call function to decrypt the data*/
  decrypt(text, keyvalue);
  printf("Decrypted value = %s\n", text);

  return 0;
}
