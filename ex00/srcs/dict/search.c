#include "rush02.h"
//receive the key and return the val if key is in the dict, otherwise return null;
char *dict_get(t_dict *dict, char *key){
	int i;
	i = 0;
	while (i < dict->size)
	{
		if (ft_strcmp(key, dict->keys[i]) == 0)
			return (dict->vals[i]);
		i++;
	}
	return (0);
}