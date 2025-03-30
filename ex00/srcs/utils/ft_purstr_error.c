#include "rush02.h"
void	ft_putstr_error(char *str)
{
	write(2, str, ft_strlen(str));
}