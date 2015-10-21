/* Simple dictionary search for a word. Dictionary file is located in /usr/share/dict. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char** argv) {
  char* word = malloc(sizeof(argv[1]+1));
  strcpy(word, argv[1]);
  word = strcat(word, "\n");
  printf("Word is: %s", word);
  int check = lookup(word);
  word[strlen(word)-1] = '\0';
  if (check != 0)
    printf("Sorry, %s is not in the dictionary.\n", word);
  else
    printf("%s is in the dictionary.\n", word);
  free(word);
}

int lookup(char* word) {
  int check = -1;
  char dictword[64];
  FILE* dict = fopen("/usr/share/dict/words", "r"); 
  while((check != 0) && (fgets(dictword, 64, dict) != NULL))
    check = strcmp(word, dictword);
  fclose(dict);
  return check;
}
