#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#include <string.h>
#include <ctype.h>

#define LENGTH 101
int main()
{
  char userIn[LENGTH];
  userIn[100] = '\0';
  List* history = init_history();

  printf("\nEnter string. (h) to see history. (!<num>) to access specific history. (q) to quit.");

  char** tokens;
  while(1) {
      printf("%s", "> ");
      fgets(userIn,100,stdin);
      if(userIn[0] == '/' && userIn[1] == 'q' && userIn[2] == 'u' && userIn[3] == 'i' && userIn[4] == 't'){
	return 0;
      } else if(userIn[0] == '/') {
	if(userIn[1] == '\n') {
	  printf("%s\n", get_history(history,userIn[1] - '0'));
	} else {
	  print_history(history);
	}
      } else {
	add_history(history, userIn);
	tokens = tokenize(userIn);
	printf("Number of words: %d\n", count_words(userIn));
	print_tokens(tokens);
      }
  }
}
