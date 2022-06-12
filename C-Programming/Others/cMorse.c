#include <stdio.h>
#include <string.h>

void Morse(char c);

#define MAX_STRING_SIZE 50  // Use a #define to avoid a magic number
                            // use UPPER_CASE to make it stand out

int main(void) {

  char aWord[MAX_STRING_SIZE];  // Create a character array to hold the string

  printf("Enter text to translate to Morse Code\n");
  
  // scanf("%s",aWord);  // will stop at a space

  fgets(aWord,sizeof(aWord),stdin); // Reads a string in from stdin (typically the keyboard)
                                    // Note we tell it the size of the char array to stop it 
                                    // overflowing

  for (int i=0; i<strlen(aWord);i++) // Loop for each character in array
  {
    Morse(aWord[i]); // Access each character as you would access values in any array.
  }
  return 0;
}

void Morse(char c)
{
  // Use a switch statement to identify the character and print out the appropriate morse
  // NB note all morse here
  switch (c)
  {
    case    'a':
        printf(".-\n");
        break;
    case    'b':
        printf("-...\n");
        break;
    case    'c':
        printf("-.-.\n");
        break;
    case    'd':
        printf("-..\n");
        break;
    case    'e':
        printf(".\n");
        break;
    case    'f':
        printf("-..-.\n");
        break;
    case    'g':
        printf("--.\n");
        break;
    case    'h':
        printf("....\n");
        break;
    case    ' ':
        printf("\n");
        break;
    default:
        break;
  }
}