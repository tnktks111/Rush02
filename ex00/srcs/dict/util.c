#include "rush02.h"
//indexハンドラーと抽出

// recieve strings and return the offset of the head of numeric char
int skip_to_numeric(char *str)
{
	int i;
	i = 0;
	while(str[i] && (str[i] < '0' || str[i] > '9'))
		i++;
	return (i);
}
// recieve strings and return the offset of the head of the word
int skip_to_word(char *str)
{
	int i;
	i = 0;
	while(str[i] && str[i] != ':' && str[i] != '\n')
		i++;
	if (str[i] == ':')
		i++;
	while(str[i] == ' ')
		i++;
	return (i);
}
int skip_to_next_entry(char *str)
{
	int i;
	i = 0;
	if (str[i] == '\n')
		i++;
	return (i);
}

//copy the string(expressesing num) to char *dest
int dict_get_num(char *dest, char *str)
{
	int i;
	char c[100];

	i = 0;
	while(str[i] >= '0' && str[i] <= '9')
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	ft_strcpy(dest, c);
	return (i);
}

//copy the string(expressesing word, not integer) to char *dest
int dict_get_word(char *dest, char *str)
{
	int i;
	char c[100];

	i = 0;
	while((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	ft_strcpy(dest, c);
	return (i);
}