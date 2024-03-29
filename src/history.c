#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *list = (List*)malloc(sizeof(List));
  list -> root = NULL;
  return list;
}

void add_history(List *list, char *str)
{
  int id = 1;
  Item *tmpNode = (Item*) malloc(sizeof(Item));
  tmpNode -> str = str;
  Item* tmp = list -> root;

  //if empty
  if(!list->root)
    {
      tmpNode -> id = 0;
      list -> root = tmpNode;
      return;
    }
  while(tmp -> next)
    {
      tmp = tmp -> next;
      id++;
    }
  tmpNode -> id = id;
  tmpNode -> next = NULL;
  return;
}

char*get_history(List* list, int id)
{
  if(list->root == NULL)
    {
      return "List is empty";
    }
  Item* tmp = list->root;
  while(tmp != NULL)
    {
      if(tmp -> id == id)
	{
	  return tmp -> str;
	}
      tmp = tmp -> next;
    }
  return "Item not found";
}

void print_history(List * list)
{
  Item* tmp = list->root;
  while(tmp != NULL)
    {
      printf("History Item[%d]: %s \n", tmp->id, tmp->str);
      tmp = tmp->next;
    }
}

void free_history(List *list)
{
  Item *tmp;

  while((*list).root != NULL)
    {
      tmp = list->root;
      list->root = tmp->next;
      free(tmp->str);
      free(tmp);
    }
  free(list);
}

