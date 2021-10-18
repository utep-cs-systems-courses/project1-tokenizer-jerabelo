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
  if(c != ' ' && c != '\t')
    {
      return 1;
    }
  return 0;
}

char *word_start(char *str)
{
  if(*str == '\0')
    {
      return 0;
    }
  while(space_char(*str))
    {
      str++;
      if(*str == '\0') return 0;
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
  char *wordStart, *wordEnd;
  int totalWords = 0, count = 0;
  while(*str != '\0') {
    wordStart = word_start(str);
    wordEnd = word_terminator(wordStart);
    str = wordEnd;
    str++;
    totalWords++;
  }
  return totalWords;
}

char *copy_str(char *inStr, short len)
{
   char *copyStr = (char*)malloc((len + 1) * sizeof(char));
   int i;
   for(i = 0; i < len; i++)
     {
       copyStr[i] = inStr[i];
     }
   copyStr[i] = '\0';
   return copyStr;
}

char **tokenize(char *str)
{
  short size = 0, i = 0;
  int totalWords = count_words(str);
  char *wordStart, *wordEnd;
  char **tokens = (char**)malloc(sizeof(char*)*(totalWords+1));

  for(i = 0; i < totalWords; i++) {
    wordStart = word_start(str);
    wordEnd = word_terminator(wordStart);
    size = wordEnd - wordStart;
    tokens[i] = copy_str(wordStart, size);
    str = word_start(wordEnd);
  }
  tokens[i] = '\0';
  return tokens;
}

void print_tokens(char **tokens)
{
   printf("tokens printed!\n");
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
