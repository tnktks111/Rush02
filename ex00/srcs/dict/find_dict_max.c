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
  if (str[i] < '0' || str[i] > '9')
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
  int count = 0;
  while (*str != '\n' && *str != 0)
  {
    if (*str < 32 || *str > 126)
      return (-1);
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
    if (i != 0 && (str[i] == '\n' && str[i - 1] != '\n'))
    {
      i++;
      dict_max->words_count++;
    }
    if (str[i] == '\n')
      i++;
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
    if (str[i] == '\n')
    {
      i++;
      continue;
    }
    if ((j = validate_key(&str[i])) == -1)
      return (invalid_dict_max());
    i += j;
    if (str[i++] != ':') // ++ skips ':'
      return (invalid_dict_max());
    if ((j = validate_value(&str[i])) == -1)
      return (invalid_dict_max());
    i += j;
    if (str[i++] != '\n' && str[i - 1] != 0) // ++ skips '\n'
      return (invalid_dict_max());
  }
  if (str[i - 1] != '\n')
    return (invalid_dict_max());
  return (dict_max);
}

// for unit test
// cc -I ./includes/ ./srcs/dict/find_dict_max.c

// int main (){
//   printf("--OK: key後半に数字以外(非表示文字も含む)が入ってる\n");
//   char str1[] = "4:four\n   8aaaa\ta: eight\n";
//   t_dict_max dict_max1 = find_dict_max(str1);
//   printf("words_count = %d\n", dict_max1.words_count);
//   printf("max_word_len = %d\n", dict_max1.max_word_len);

//   printf("--OK: 改行を複数含む\n");
//   char str5[] = "\n\n4:four\n\n\n\n     10    :    ten\n80000   : eight\n\n";
//   t_dict_max dict_max5 = find_dict_max(str5);
//   printf("words_count = %d\n", dict_max5.words_count);
//   printf("max_word_len = %d\n", dict_max5.max_word_len);

//   printf("--OK: 10,11の間が改行なし（:以降はすべての表示文字が入れられるので、:も表示対象と考えられる）\n");
//   char str4[] = "\n\n4:four\n\n\n\n  10:::ten11:eleven\n\n\n";
//   t_dict_max dict_max4 = find_dict_max(str4);
//   printf("words_count = %d\n", dict_max4.words_count);
//   printf("max_word_len = %d\n", dict_max4.max_word_len);

//   printf("--OK: ひたすらいろんな場所にスペース\n");
//   char str7[] = "           +111   10a:                zero     \n1: one\n2: two\n3: threeggggg\n4: four\n5: five\n6: six\n7: seven\n8: eight\n";
//   t_dict_max dict_max7 = find_dict_max(str7);
//   printf("words_count = %d\n", dict_max7.words_count);
//   printf("max_word_len = %d\n", dict_max7.max_word_len);

//   printf("--OK: 符号１つ含む\n");
//   char str6[] = "  +7: seven\n-8: eight\n42: forty    two \n";
//   t_dict_max dict_max6 = find_dict_max(str6);
//   printf("words_count = %d\n", dict_max6.words_count);
//   printf("max_word_len = %d\n", dict_max6.max_word_len);

//   printf("--NG: key前半に数字以外入ってる\n");
//   char str2[] = "4:four\n   a80000: eight\n";
//   t_dict_max dict_max2 = find_dict_max(str2);
//   printf("words_count = %d\n", dict_max2.words_count);
//   printf("max_word_len = %d\n", dict_max2.max_word_len);

//   printf("--NG: key:valueになっていない行がある\n");
//   char str3[] = "4:four\n\naiueo\n\n80000: eight\n";
//   t_dict_max dict_max3 = find_dict_max(str3);
//   printf("words_count = %d\n", dict_max3.words_count);
//   printf("max_word_len = %d\n", dict_max3.max_word_len);

//   printf("--NG: valueに非表示文字を含む\n");
//   char str9[] = "7: s\teven\n8: eight\n";
//   t_dict_max dict_max9 = find_dict_max(str9);
//   printf("words_count = %d\n", dict_max9.words_count);
//   printf("max_word_len = %d\n", dict_max9.max_word_len);

//   printf("--NG: 最後の改行がない（他のエントリーについては、なかったとしても次の項目も含めて大きな１つのエントリーとして扱うべき）\n");
//   char str8[] = "7: seven\n8: eight";
//   t_dict_max dict_max8 = find_dict_max(str8);
//   printf("words_count = %d\n", dict_max8.words_count);
//   printf("max_word_len = %d\n", dict_max8.max_word_len);

//   printf("--NG: 符号が重なっている\n");
//   char str10[] = "++7: seven\n: eight\n";
//   t_dict_max dict_max10 = find_dict_max(str10);
//   printf("words_count = %d\n", dict_max10.words_count);
//   printf("max_word_len = %d\n", dict_max10.max_word_len);
// }