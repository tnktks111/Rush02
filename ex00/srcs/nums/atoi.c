#include "rush02.h"

char	*ft_atoi(char *str)
{
	while (*str && *str == ' ')
		str++;
	if (!*str)
		return (str);
	if (*str == '-')
	{
		if (!*(str + 1))
			*str = '0';
		else
			return (NULL);
	}
	if (*str == '+')
	{
		if (!*(str + 1))
			*str = '0';
		else
			str++;
	}
	return (str);
}