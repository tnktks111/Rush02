#include "rush02.h"
int ft_strlen(char *str)
{
	char *tail;

	tail = str;
	while(*tail)
		tail++;
	return (tail - str);
}
