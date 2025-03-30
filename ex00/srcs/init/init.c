#include "rush02.h"
int init(char *dict_path, char *input)
{
	t_dict	dict;
	t_n_buf	*buffer;
	char	*str;
	int		parser_check;
	int		num_check;

	str = file_read(dict_path);
	if (!str)
		return (dict_error());

	t_dict_max dict_max = find_dict_max(str);
	if (dict_max.words_count == -1)
		return (dict_error());

	dict = init_dict();
	// TODO ↓のようなmallocエラーの処理入れる
	// if (!dict)
	//   return (dict_error());
	parser_check = parser(&dict, str);
	if (parser_check == -1)
		return (dict_error());
	buffer = n_buf_init();
	num_check = n_convert(buffer, &dict, input);
	if (num_check == -1)
		return (dict_error());
	n_buf_print(buffer);
	return (0);
}
