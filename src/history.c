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
  Item *currNode = (*list).root;
  Item *newNode = (Item*) malloc(sizeof(Item));
  (*newNode).next = NULL;
}

void free_history(*list).root != NULL)
{
  Item *currNode;

  while(*list).root != NULL)
    {
      currNode = (*list).root;
      (*list).root = (*list).next;
      free(currNode ->str);
      free(currNode);
    }
  free(list);
}
