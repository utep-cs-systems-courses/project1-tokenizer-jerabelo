#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *list = malloc(sizof(List));
  List -> root = malloc(sizeof(Item));
  return list;
}
