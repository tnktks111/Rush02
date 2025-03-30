#include "rush02.h"
//ex. c=5, size =3 -> "5000"を返す
char *zero_padding(char c, int size)
{
	char *str;
	int i;
	
	str = (char *)malloc(sizeof(char) * (size + 2));
	str[0] = c;
	i = 1;
	while(i < size + 1)
	{
		str[i++] = '0';
	}
	str[i] = '\0';
	return (str);
}

//str[left:right + 1]を獲得する
char *get_sub(char *str, int left, int right)
{
	char *sub;
	int len;
	int i;

	i = 0;
	len = right - left + 1;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		sub[i] =str[left + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}