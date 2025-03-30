#include "rush02.h"

//if str is numeric, return 1, otherwise return 0
int ft_is_numeric(char *str)
{
	while(*str){
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

//if the dict exists, return 1, otherwise return 0
int is_valid_dictfile(char *dict)
{
	int fd;
	char buf[BUF_SIZE];
	int byte_num;
	
	fd = open(dict, O_RDONLY);
	if (fd == -1)
		return (0);
	byte_num = read(fd, buf, BUF_SIZE);
	if (byte_num <= 0)
	{
		close(fd);
		return(0);
	}
	close(fd);
	return (1);
}

//If the input are valid, return 1.
//Otherwise, return non-positive value depending on the kinds of error.
//(numeric error ... 0, file error ... -1)
int is_valid_input(int argc, char *argv[], char *dict){
	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 2)
	{
		if (!ft_is_numeric(argv[1]))
			return (0);
		if (!is_valid_dictfile(dict))
			return (-1);
	}
	if (argc == 3)
	{
		if (!ft_is_numeric(argv[2]))
			return (0);
		if (!is_valid_dictfile(argv[1]))
			return (-1);
	}
	return(1);
}