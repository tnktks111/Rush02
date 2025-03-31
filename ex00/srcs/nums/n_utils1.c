#include "rush02.h"

int n_store(t_n_buf *buffer, t_dict *dict, char *str)
{
	if (str == NULL)
		return (-1);
	char *word;
	word = dict_get(dict, str);
	if (!word)
		return (-1);
	if (!n_buf_add(buffer, word))
		return (-1);
	
	return (0);
}

int n_tens(t_n_buf *buffer, t_dict *dict, char *str)
{
	int len;

	char *pad;
	len = 2;
	while (*str == '0')
	{
		str++;
		len--;
	}
	if (len == 0)
		return (0);
	if (len == 1)
		return (n_store(buffer, dict, str));
	if (str[0] == '1')
		return (n_store(buffer, dict, str));
	pad = zero_padding(str[0], 1);
	if (n_store(buffer, dict, pad) == -1)
		return (-1);
	free(pad);
	if (str[1] != '0')
	{
		if (!n_buf_add(buffer, "-"))
			return (-1);
		return (n_store(buffer, dict, &str[1]));
	}
	return (0);
}

int n_hundreds(t_n_buf *buffer, t_dict *dict, char *str)
{
	int len;
	char *sub;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '0')
		return (n_store(buffer, dict, "0"));
	while (*str == '0')
	{
		str++;
		len--;
	}
	if (len == 0)
		return (0);
	if (len == 1)
		return (n_store(buffer, dict, str));
	if (len == 2)
		return (n_tens(buffer, dict, str));
	sub = get_sub(str, 0, 0);
	if (n_store(buffer, dict, sub) == -1)
		return (-1);
	if (n_store(buffer, dict, "100") == -1)
		return (-1);
	if (str[1] != '0' || str[2] != '0')
		if (!n_buf_add(buffer, "and"))
			return (-1);
	free(sub);
	sub = get_sub(str, 1, 2);
	if (n_tens(buffer, dict, sub) == -1)
		return (-1);
	free(sub);
	return (0);
}

int n_convert(t_n_buf *buffer, t_dict *dict, char *str)
{
	int i;
	int n;
	int remain;
	char *digits;
	char *pad;

	i = 0;
	remain = ft_strlen(str);
	while(i < ft_strlen(str)){
		n = remain % 3;
		if (n == 0)
			n = 3;
		digits = get_sub(str, i, i + n - 1);
		if (n_hundreds(buffer, dict, digits) == -1)
		{
			free(digits);
			return (0);
		}
		if (remain - n >= 3 && !(digits[0] == '0' && digits[1] == '0' && digits[2] == '0'))
		{
			pad = zero_padding('1', remain - n);
			if (n_store(buffer, dict, pad) == -1 || n_buf_add(buffer, ",") == -1)
			{
				free(pad);
				return(-1);
			}
			free(pad);
		}
		free(digits);
		i += n;
		remain -= n;
	}
	return (0);
}