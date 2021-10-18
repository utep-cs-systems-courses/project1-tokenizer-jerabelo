#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#include <string.h>
#include <ctype.h>

int main()
{
  char user_in[101];
  user_in[100] = '\0';
  List *history = init_history();

  printf("\nEnter text. (!h) to see history, (!<num>) to see specific token, (!q) to quit.");

  char**tokens;
  while(1) {
    printf("%s", "\n> ");
    fgets(user_in, 100, stdin);
    if(user_in[0] == '!' && user_in[1] == 'h') {
      print_history(history);
    } else if (user_in[0] == '!' && isdigit(user_in[1])) {
      printf("%s\n", get_history(history, user_in[1]-'0'));
    } else if(user_in[0] == '!' && user_in[1] == 'q') {
      return 0;
    } else {
      add_history(history, user_in);
      tokens = tokenize(user_in);
      printf("Number of words: %d\n", count_words(user_in));
      print_tokens(tokens);
    }
  }
}
