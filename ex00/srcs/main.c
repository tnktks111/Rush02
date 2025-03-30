#include "rush02.h"
int main(int argc, char *argv[])
{
	int i;
	i = is_valid_input(argc, argv, DICT_PATH);
	if (i == 0)
		return (error());
	else if (i == -1)
		return (dict_error());
	if (argc == 2)
		init(DICT_PATH, argv[1]);
	else if (argc == 3)
		init(argv[1], argv[2]);
	return (0);
}