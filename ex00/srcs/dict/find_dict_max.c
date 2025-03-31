#include "rush02.h"

// OK: "  +123abc\t   :..."
// NG: "+abc123:..."
// NG: "++1:..."
// NG: "123\n" (newline comes before colon)
int validate_key(char *str)
{
  int i = 0;
  while (str[i] == ' ')
    i++;
  if (str[i] == '-' || str[i] == '+')
    i++;
  if (str[i] < '0' && str[i] > '9')
    return (-1);
  while (str[i] != ':')
  {
    if (str[i] == '\n')
      return (-1);
    i++;
  }
  return (i);
}

int validate_value(char *str)
{
  // TODO 非表示文字のバリデーション
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
  dict_max.max_word_len = -1;
  return dict_max;
}

char str6[] = "42: two\n";
void calc_dict_max(char *str, t_dict_max *dict_max)
{
  int i;
  int j;
  i = 0;
  j = 0;
  dict_max->words_count = 0;
  dict_max->max_word_len = 0;
  while (str[i])
  {
    j = 0;
    if (str[i] == '\n'){
      i++;
      dict_max->words_count++;
    }
    while (str[i + j] != '\n' && str[i + j] != 0)
    {
      if (dict_max->max_word_len < j)
        dict_max->max_word_len = j;
      j++;
    }
    i += j;
  }
}

t_dict_max find_dict_max(char *str)
{
  t_dict_max dict_max;
  int i;
  int j;
  i = 0;
  j = 0;
  calc_dict_max(str, &dict_max);
  while (str[i])
  {
    if (str[i++] == '\n')
      continue;
    if ((j = validate_key(&str[i])) == -1)
      return (invalid_dict_max());
    i += j;
    if (str[i++] != ':') // ++ skips ':'
      return (invalid_dict_max());
    while (str[i] == ' ')
      i++;
    if ((j = validate_value(&str[i])) == -1)
      return (invalid_dict_max());
    i += j;
    if (str[i++] != '\n' && str[i] != 0) // ++ skips '\n'
      return (invalid_dict_max());
  }
  if (str[i - 1] != '\n')
    return (invalid_dict_max());
  return (dict_max);
}

// testはmainをコメント戻して以下を実行
// cc -I ./includes/ ./srcs/dict/find_dict_max.c

// int main (){
//   printf("--OK: key後半に数字以外入ってる------\n");
//   char str1[] = "4:four\n   8aaaaa: eight\n";
//   t_dict_max dict_max1 = find_dict_max(str1);
//   printf("%s\n",str1);
//   printf("words_count = %d\n", dict_max1.words_count);
//   printf("max_word_len = %d\n", dict_max1.max_word_len);

//   printf("--OK: key前半に数字以外入ってる-----\n");
//   char str2[] = "4:four\n   a80000: eight\n";
//   t_dict_max dict_max2 = find_dict_max(str2);
//   printf("%s\n",str2);
//   printf("words_count = %d\n", dict_max2.words_count);
//   printf("max_word_len = %d\n", dict_max2.max_word_len);

//   printf("--NG: key:valueになっていない行がある-----\n");
//   char str3[] = "4:four\n\naiueo\n\n80000: eight\n";
//   t_dict_max dict_max3 = find_dict_max(str3);
//   printf("%s\n",str3);
//   printf("words_count = %d\n", dict_max3.words_count);
//   printf("max_word_len = %d\n", dict_max3.max_word_len);

//   printf("--OK: 10,11の間が改行入ってないが、:以降はすべての表示文字が入れられるので、:も対象と考えられる-------\n");
//   char str4[] = "\n\n4:four\n\n\n\n  10:::aaa:ten\n\n\n";
//   t_dict_max dict_max4 = find_dict_max(str4);
//   printf("%s\n",str4);
//   printf("words_count = %d\n", dict_max4.words_count);
//   printf("max_word_len = %d\n", dict_max4.max_word_len);

//   printf("--OK------\n");
//   char str5[] = "\n\n4:four\n\n\n\n     10    :    ten\n80000   : eight\n\n";
//   t_dict_max dict_max5 = find_dict_max(str5);
//   printf("%s\n",str5);
//   printf("words_count = %d\n", dict_max5.words_count);
//   printf("max_word_len = %d\n", dict_max5.max_word_len);

//   printf("--OK-----\n");
//   char str6[] = "42: two\n";
//   // char str6[] = "  ++-7: seven\n8: eight\n42: forty    two ";
//   t_dict_max dict_max6 = find_dict_max(str6);
//   printf("%s\n",str6);
//   printf("words_count = %d\n", dict_max6.words_count);
//   printf("max_word_len = %d\n", dict_max6.max_word_len);

//   printf("--OK-----\n");
//   char str7[] = "           11110:                zero     \n1: one\n2: two\n3: threeggggg\n4: four\n5: five\n6: six\n7: seven\n8: eight\n";
//   t_dict_max dict_max7 = find_dict_max(str7);
//   printf("%s\n",str7);
//   printf("words_count = %d\n", dict_max7.words_count);
//   printf("max_word_len = %d\n", dict_max7.max_word_len);

//   printf("--NG: 最後の\nがない（他のエントリーについては、なかったとしても次の項目も含めて大きな１つのエントリーとして扱うべき）-----\n");
//   char str8[] = "           11110:                zero     \n1: one\n2: two\n3: threeggggg\n4: four\n5: five\n6: six\n7: seven\n8: eight";
//   t_dict_max dict_max8 = find_dict_max(str8);
//   printf("%s\n",str8);
//   printf("words_count = %d\n", dict_max8.words_count);
//   printf("max_word_len = %d\n", dict_max8.max_word_len);
// }
