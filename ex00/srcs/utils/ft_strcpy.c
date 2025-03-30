#include "rush02.h"
char *ft_strcpy(char *dest, char *src)
{
	while(*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}