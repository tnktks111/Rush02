#include "rush02.h"
//dictからstrに対するvalを検索、あればbufにぶち込む
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

//2桁の数を処理
//上から順に00, 0*, 1*, 下2つでメイン処理
int n_tens(t_n_buf *buffer, t_dict *dict, char *str)
{
	int len;
	len = 2;
	while (*str == '0')
	{
		str++;
		len--;
	}
	if (len == 0)
		return (0);
	if (len == 1)
		return (n_store(buffer, dict, get_sub(str, 0, 0)));
	if (str[0] == '1')
		return (n_store(buffer, dict, str));
	if (n_store(buffer, dict, zero_padding(str[0], 1)) == -1)
		return (-1);
	if (str[1] != '0')
		return (n_store(buffer, dict, get_sub(str, 1, 1)));
	return (0);
}

//3桁の数を処理
//上から順に、000, 00*, 0**, 下3つが***の処理
int n_hundreds(t_n_buf *buffer, t_dict *dict, char *str)
{
	int len;

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
	if (n_store(buffer, dict, get_sub(str, 0, 0)) == -1)
		return (-1);
	if (n_store(buffer, dict, "100") == -1)
		return (-1);
	if (n_tens(buffer, dict, get_sub(str, 1, 2)) == -1)
		return (-1);
	return (0);
}

int n_convert(t_n_buf *buffer, t_dict *dict, char *str)
{
	int i;
	int n;
	int remain;
	char *digits;

	i = 0;
	remain = ft_strlen(str);
	while(i < ft_strlen(str)){
		n = remain % 3;
		if (n == 0)
			n = 3;
		digits = get_sub(str, i, i + n - 1);
		if (n_hundreds(buffer, dict, digits) == -1)
			return -1;
		if (remain - n >= 3 && !(digits[0] == '0' && digits[1] == '0' && digits[2] == '0'))
			if (n_store(buffer, dict, zero_padding('1', remain - n)) == -1)
				return (-1);
		i += n;
		remain -= n;
	}
	return (0);
}