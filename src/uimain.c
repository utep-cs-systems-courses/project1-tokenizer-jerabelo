#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#include <string.h>
#include <ctype.h>

int main()
{
  int count = 0;
  
  while(1)
    {
      char userInput[100];
      int historyNum;
      char* historyList;
      List *history = init_history();

      printf("\nEnter a String. Enter 'h' to see history. Enter 'x' to exit\nEnter \ !<number>\ to       see selected history\n");

      while(userInput[0] != 'x')
	{
	  printf(">");
	  fgets(userInput,100,stdin);
	  if(userInput[0] == 'x')
	    {
	      break;
	    } else if (userInput[0] == '?')
	    {
	      break;
	    } else if(userInput[0] == '!')
	    {
	      historyNum = atoi(userInput+1);
	      if(historyNum > 0)
		{
		  historyTotal = get_history(history,historyNum);
		}
	    }


