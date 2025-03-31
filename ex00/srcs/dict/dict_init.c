#include "rush02.h"
char **create_strarr(int arr_len, int word_cap)
{
	char **res;
	int i;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (!res)
	{
		return (NULL);
	}
	while (i < arr_len)
	{
		res[i] = (char *)malloc(sizeof(char) * (word_cap + 1));
		if (!res[i])
		{
			while(--i >= 0)
				free(res[i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}

t_dict init_dict(t_dict_max dict_max)
{
	t_dict dict;
	int i;
	
	dict.keys = create_strarr(dict_max.words_count, dict_max.max_word_len);
	dict.vals = create_strarr(dict_max.words_count, dict_max.max_word_len);
	i = 0;
	if (!dict.keys || !dict.vals)
	{
		if (dict.keys)
		{
			while(i < dict_max.words_count)
				free(dict.keys[i]);
			free(dict.vals);
		}
		if (dict.vals)
		{
			while(i < dict_max.words_count)
				free(dict.keys[i]);
			free(dict.vals);
		}
		dict.index = -1;
		return (dict);
	}
	dict.index = 0;
	dict.size = dict_max.words_count + 1;
	return (dict);
}