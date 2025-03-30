#include "rush02.h"
//receive a key-val set and dict, and push the set to the end of the dict
void items_setter(t_dict *dict, char *key, char *val)
{
	ft_strcpy(dict->keys[dict->size], key);
	ft_strcpy(dict->vals[dict->size], val);
	dict->size += 1;
}