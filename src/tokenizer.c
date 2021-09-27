#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == ' ' || c == '\t')
    {
      return 1;
    }
  return 0;
}

int non_space_char(char c)
{
  if(c != ' ' || c != '\t' || c == '\0')
    {
      return 1;
    }
  return 0;
}

char *word_start(char *str)
{
  if(*str == '\0')
    {
      return '\0';
    }
  while(space_char(*str))
    {
      str++;
    }
  return str;
}

char *word_terminator(char *word)
{
  while(non_space_char(*word))
  {
    word++;
  }
  return word;
}

int count_words(char *str)
{
  int count = 0;
  while(*str != '\0')
    {
      str = word_start(str);
      str = word_terminator(str);
      count++;
    }
  return count;
}

char *copy_str(char *inStr, short len)
{
   char *copyStr = (char*)malloc((len + 1) * sizeof(char));

   for(int i = 0; i < len; i++)
     {
       *copyStr++ = *inStr++;
     }
   *copyStr = 0;
   copyStr = copyStr - len;
   return copyStr;
}

char **tokenize(char *str)
{
  int wordCount = count_words(str);

  char **tokens = (char**) malloc((wordCount+1)*sizeof(char*));

  char *end;
  str = word_start(str);

  for(int i = 0; i < wordCount; i++)
    {
      int wordLen = word_terminator(str) - str;

      char *copyStr = (char*) malloc((wordLen+1)*sizeof(char));

      copyStr = copy_str(str,wordLen);
      *tokens = copyStr;

      end = word_terminator(str);
      str = word_start(end);
      tokens++;
    }
  *tokens = 0;
  return tokens - wordCount;
}

void print_tokens(char **tokens)
{
   printf("tokens printed!");

   int counter = 0;
   while(*tokens != 0)
     {
       printf("[%d] %s\n", counter, *tokens);
       counter++;
       tokens++;
     }
 }

void free_tokens(char **tokens)
{
   while(*tokens != 0)
     {
       free(*tokens);
       tokens++;
     }
 }
