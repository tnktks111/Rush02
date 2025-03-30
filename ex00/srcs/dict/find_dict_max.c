#include "rush02.h"

int count_word_length(char *str)
{
  int count = 0;
  while (*str != '\n' && *str != 0)
  {
    str++;
    count++;
  }
  return count;
}

int validate_key(char *str)
{
  int i = 0;
  while (str[i] != ':')
  {
    if (str[i] != ' ' && (str[i] < '0' || str[i] > '9'))
      return (-1);
    i++;
  }

  return (i);
}

int validate_value(char *str)
{
  int i = 0;
  int word_length = 0;
  while (str[i] == ' ')
    i++;
  return count_word_length(&str[i]);
}

t_dict_max invalid_dict_max(void)
{
  t_dict_max dict_max;
  dict_max.words_count = -1;
  dict_max.max_value_len = -1;
  return dict_max;
}

t_dict_max find_dict_max(char *str)
{
  t_dict_max dict_max;
  int i = 0;
  int j = 0;
  dict_max.words_count = 0;
  dict_max.max_value_len = 0;
  while (str[i])
  {
    dict_max.words_count++;
    if ((j = validate_key(&str[i])) == -1)
      return invalid_dict_max();
    i += j;
    while (str[i] == ' ')
      i++;
    if (str[i] != ':')
      return invalid_dict_max();
    if ((j = validate_value(&str[i])) > dict_max.max_value_len)
      dict_max.max_value_len = j;
    if (j == -1)
      return invalid_dict_max();
    i += j;
    if (str[i] != '\n' && str[i] != 0)
      return invalid_dict_max();
    i++;
  }
  return (dict_max);
}

// test
// cc -I ../../includes/ find_dict_max.c

int main (){
  char str[] = "           111110:           zero     \n1: one\n2: two\n3: threeggggg\n4: four\n5: five\n6: six\n7: seven\n8: eight\n";
  t_dict_max dict_max = find_dict_max(str);
  printf("words_count = %d\n", dict_max.words_count);
  printf("max_value_len = %d\n", dict_max.max_value_len);
}
