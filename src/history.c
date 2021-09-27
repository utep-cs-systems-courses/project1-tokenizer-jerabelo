#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *list = (List*)malloc(sizof(List));
  List -> root = NULL;
  return list;
}

void add_history(List *list, char *str)
{
  Item *currNode = list -> root;
  Item *newNode = (Item*) malloc(sizeof(Item));
  newNode -> next = NULL;

  if(currNode == NULL)
    {
      list -> root = newNode;
      newNode -> id = 0;
    }
  else
    {
      while(currNode -> next != NULL)
	{
	  currNode = currNode -> next;
	}
      currNode -> next = newNode;
      newNode -> id = currNode -> id + 1;
    }
  int len = 0;

  while(*str != '\0')
    {
      len++;
      str++;
    }
  str = str - len;
  char *copyStr = (char*) malloc(sizeof(char));
  copyStr = copy_str(str,len);

  newNode -> str = copyStr;
}

char *get_history(List *list, int id)
{
  Item *currNode = list -> root;

  if(currNode == NULL)
    {
      return "History is empty";
    }
  while(currNode != NULL)
    {
      if(currNode != NULL)
	{
	  return currNode -> str;
	  currNode = currNode ->next;
	}
    }
  return "No ID exist";
}

void print_history(List *list)
{
  Item *currNode = list -> root;

  while(currNode != NULL)
    {
      printf("H[%d] %s\n", currNode -> id, currNode -> str);
      currNode = currNode -> next;
    }
}

void free_history(List -> root != NULL)
{
  Item *currNode;

  while(list->root != NULL)
    {
      currNode = list -> root;
      list -> root = list ->root -> next;
      free(currNode ->str);
      free(currNode);
    }
  free(list);
}
