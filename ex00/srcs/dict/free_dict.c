#include "rush02.h"
void free_dict(t_dict *dict)
{
	int i;
	i = 0;
	while (i < dict->size)
	{
		free(dict->keys[i]);
		free(dict->vals[i]);
		i++;
	}
	free(dict);
}