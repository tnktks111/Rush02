#include "rush02.h"
int init(char *dict_path, char *input)
{
	t_dict	dict;
	t_n_buf	*buffer;
	t_dict_max dict_max;
	char	*str;
	int		check;

	str = file_read(dict_path);
	if (!str)
		return (dict_error());
	dict_max = find_dict_max(str);
	if (dict_max.words_count == -1)
		return (dict_error());
	dict = init_dict(dict_max);
	if (dict.index == -1)
		return (dict_error());
	check = parser(&dict, str, dict_max);
	if (check == -1)
	{
		free_dict(&dict);
		return (dict_error());
	}
	buffer = n_buf_init();
	if (!buffer)
	{
		free_dict(&dict);
		return (dict_error());
	}
	check = n_convert(buffer, &dict, input);
	if (check == -1)
	{
		free_n_buf(buffer);
		free_dict(&dict);
		return (dict_error());
	}
	n_buf_print(buffer);
	free_n_buf(buffer);
	free_dict(&dict);
	return (0);
}
