#include "rush02.h"

int validate_key(char *str)
{
  int i = 0;
  while (str[i] == ' ')
    i++;
  if (str[i] == '-' || str[i] == '+')
    i++;
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
  int count = 0;
  while (*str != '\n' && *str != 0)
  {
    str++;
    count++;
  }
  return count;
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
  int i;
  int j;
  i = 0;
  j = 0;
  dict_max.words_count = 0;
  while (str[i])
  {
    if (str[i] == '\n')
    {
      i++;
      continue;
    }
    dict_max.words_count++;
    if ((j = validate_key(&str[i])) == -1)
      return (invalid_dict_max());
    i += j;
    while (str[i] == ' ')
      i++;
    if (str[i++] != ':') // ++ skips ':'
      return (invalid_dict_max());
    while (str[i] == ' ')
      i++;
    if ((j = validate_value(&str[i])) > dict_max.max_value_len)
      dict_max.max_value_len = j;
    if (j == -1)
      return (invalid_dict_max());
    i += j;
    if (str[i++] != '\n' && str[i] != 0) // ++ skips '\n'
      return (invalid_dict_max());
  }
  return (dict_max);
}

// testはmainをコメント戻して以下を実行
// cc -I ./includes/ ./srcs/dict/find_dict_max.c

// int main (){
//   printf("-----key後半に数字以外入ってるから☓------\n");
//   char str1[] = "4:four\n   8aaaaa: eight\n";
//   t_dict_max dict_max1 = find_dict_max(str1);
//   printf("%s\n",str1);
//   printf("words_count = %d\n", dict_max1.words_count);
//   printf("max_value_len = %d\n", dict_max1.max_value_len);

//   printf("------key前半に数字以外入ってるから☓-----\n");
//   char str2[] = "4:four\n   a80000: eight\n";
//   t_dict_max dict_max2 = find_dict_max(str2);
//   printf("%s\n",str2);
//   printf("words_count = %d\n", dict_max2.words_count);
//   printf("max_value_len = %d\n", dict_max2.max_value_len);

//   printf("------key:valueになっていない行があるから☓-----\n");
//   char str3[] = "4:four\n\naiueo\n\n80000: eight\n";
//   t_dict_max dict_max3 = find_dict_max(str3);
//   printf("%s\n",str3);
//   printf("words_count = %d\n", dict_max3.words_count);
//   printf("max_value_len = %d\n", dict_max3.max_value_len);
 
//   printf("----10,11の間が改行入ってないから☓-------\n");
//   char str4[] = "\n\n4:four\n\n\n\n  10: ten  11: eleven\n\n\n";
//   t_dict_max dict_max4 = find_dict_max(str4);
//   printf("%s\n",str4);
//   printf("words_count = %d\n", dict_max4.words_count);
//   printf("max_value_len = %d\n", dict_max4.max_value_len);

//   printf("-----◯------\n");
//   char str5[] = "\n\n4:four\n\n\n\n     10    :    ten\n80000   : eight\n\n";
//   t_dict_max dict_max5 = find_dict_max(str5);
//   printf("%s\n",str5);
//   printf("words_count = %d\n", dict_max5.words_count);
//   printf("max_value_len = %d\n", dict_max5.max_value_len);

//   printf("------◯-----\n");
//   char str6[] = "7: seven\n8: eight\n42: forty    two ";
//   t_dict_max dict_max6 = find_dict_max(str6);
//   printf("%s\n",str6);
//   printf("words_count = %d\n", dict_max6.words_count);
//   printf("max_value_len = %d\n", dict_max6.max_value_len);

//   printf("------◯-----\n");
//   char str7[] = "           11110:                zero     \n1: one\n2: two\n3: threeggggg\n4: four\n5: five\n6: six\n7: seven\n8: eight\n";
//   t_dict_max dict_max7 = find_dict_max(str7);
//   printf("%s\n",str7);
//   printf("words_count = %d\n", dict_max7.words_count);
//   printf("max_value_len = %d\n", dict_max7.max_value_len);
// }
