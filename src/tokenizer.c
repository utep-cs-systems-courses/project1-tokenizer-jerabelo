#include <stdio.h>
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

char *word_terminator(char *str)
{
  while(non_space_char(str))
    {
      str++;
      if(str == NULL)
	{
	  return str;
	}
      return "0";
    }
}

int count_words(char *str)
{
  int pos = 0;
  int counter = 0;
  while(s[i] != '\0')
    {
      if(non_space_char(s[i]) && space_char(s[i+1]))
	{
	  counter++;
	  pos++;
	}
    }
  counter+= 1;
  if(space_char(s[i-2]))
    {
      counter--;
    }
  return counter;
}


