#include "rush02.h"
char **create_strarr(int arr_len, int word_cap)
{
	char **res;
	int i;
	i = 0;
	res = (char **)malloc(sizeof(char *) * (arr_len + 1));
	while (i < 200)
	{
		res[i] = (char *)malloc(sizeof(char) * (word_cap + 1));
		i++;
	}
	return (res);
}

t_dict init_dict(t_dict_max dict_max)
{
	t_dict dict;

	dict.keys = create_strarr(dict_max.words_count, dict_max.max_word_len);
	dict.vals = create_strarr(dict_max.words_count, dict_max.max_word_len);
	dict.index = 0;
	dict.size = dict_max.words_count + 1;
	return (dict);
}