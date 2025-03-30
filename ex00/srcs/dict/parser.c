#include "rush02.h"
int parser(t_dict *dict, char *str){
	int i;
	char *num;
	char *word;

	i = 0;
	while (str[i]){
		num = (char *)malloc(sizeof(char) * 100);
		word = (char *)malloc(sizeof(char) * 100);
		if (!num || !word)
			return (-1);
		i += skip_to_word(str + i);
		i += dict_get_word(word, str + i);
		i += skip_to_next_entry(str + i);
		items_setter(dict, num, word);
		free(num);
		free(word);
	}
	return (0);
}