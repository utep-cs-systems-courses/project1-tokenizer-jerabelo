#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#include <string.h>
#include <ctype.h>

int main()
{
  char userIn[100];
  while(1)
    {
      putchar('>');
      fgets(userIn, 100, stdin);
      printf("%s\n", userIn);
  //calling methods from tokenizer.h
  printf("%d\n",space_char(' '));
  printf("%d\n",non_space_char('d'));
  printf("%c\n",*word_start("questions"));
  // printf("%c\n",*word_terminator("hello say"));
  printf("%d\n",count_words("Hello world!"));

    }
  return 0;
}


