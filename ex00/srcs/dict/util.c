#include "rush02.h"
//indexハンドラーと抽出

// 次の数字までインデックスを進める
int skip_to_numeric(char *str)
{
	int i;
	i = 0;
	while(str[i] && !(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		i++;
	return (i);
}

// 次のwordまでインデックスを進める
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

//次の行までインデックスを進める
int skip_to_next_entry(char *str)
{
	int i;
	i = 0;
	while (str[i] == '\n')
		i++;
	return (i);
}

//copy the string(expressesing num) to char *dest
int dict_get_num(char *dest, char *str)
{
	int i;

	i = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '+')
			str++;
		else
			dest[i++] = '-';
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

//copy the string(expressesing word, not integer) to char *dest
int dict_get_word(char *dest, char *str)
{
	int i;

	i = 0;
	while (str[i] >= 32 && str[i] < 127)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
