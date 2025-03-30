#include "rush02.h"
char **create_strarr(void)
{
	char **res;
	int i;
	i = 0;
	res = (char **)malloc(sizeof(char *) * 200);
	while (i < 200)
	{
		res[i] = (char *)malloc(sizeof(char) * 200);
		i++;
	}
	return (res);
}

t_dict *init_dict(void)
{
	t_dict *dict;
	dict = (t_dict *)malloc(sizeof(t_dict));
	if (!dict)
		return (NULL);
	dict->keys = create_strarr();
	dict->vals = create_strarr();
	dict->size = 0;
	return (dict);
}