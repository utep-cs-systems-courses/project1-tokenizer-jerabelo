#include <stdio.h>
#include <stdlib.h>
#include <tokenizer.h>
#include <tokenizer.c>

int main()
{

}
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
  if(!space_char(c))
    {
      return 0;
    }
  return 1;
}

char *word_start(char *word)
{
  int pos = 0;
  while(*(word+pos))
    {
      if(non_space_char(*(word+pos))
	{
	  return word + pos;
	}
	pos++;
    }
      return word + pos;
}

char *word_terminator(char *str)
{
  int pos = 0;
  while(*(word+pos))
    {
      if(space_char(*(word+pos)))
	{
	  return word + pos;
	}
      pos++;
    }
  return word + pos;
}

int count_words(char *str)
{
  char *tmp = str;
  int counter = 0;
  int pos = 0;
  tmp = word_start(tmp);
  while(*tmp)
    {
      if(non_space_char(tmp))
	{
	  count++;
	}
      tmp = word_terminator(tmp);
      tmp = word_start(tmp);
    }
  return count;
}

 char *copy_str(char *inStr, short len)
 {
   char *copyStr = malloc((len + 1) * sizeof(char));
   int i = 0;
   for(i = 0; i < len; i++)
     {
       copyStr[i] = inStr[i];
     }
   copyStr[i] ='\0';
   return copyStr;
 }

 void print_tokens(char **tokens)
 {
   while(**tokens != '\0')
     {
       prinf("%s\n",*tokens);
       tokens++;
     }
 }

 void free_tokens(char **tokens)
 {
   char **tmp = tokens;
   while(**tmp != '\0')
     {
       free(*tmp);
       tmp++;
     }
   free(*tmp);
   free(tokens);
 }
