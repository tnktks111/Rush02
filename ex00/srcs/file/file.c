#include "rush02.h"
int file_size(char *file){
	int fd;
	char buffer[BUF_SIZE];
	int byte_num;
	int file_size;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	file_size = 0;
	while (1)
	{
		byte_num = read(fd, buffer, BUF_SIZE);
		if (byte_num == -1)
		{
			close(fd);
			return (-1);
		}
		if (byte_num == 0)
			break;
		file_size += byte_num;
	}
	close(fd);
	return (file_size);
}

char *file_read(char *file)
{
	int fd;
	char *buffer;
	int f_size;
	int rd;

	f_size = file_size(file);
	if (f_size == -1)
	{
		ft_putstr_error("Error\n");
		return (NULL);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_error("Error\n");
		return (NULL);
	}
	buffer = (char *)malloc(f_size + 1);
	rd = read(fd, buffer, f_size);
	if (rd == -1)
	{
		ft_putstr_error("Error\n");
		close(fd);
		return (NULL);
	}
	close(fd);
	buffer[f_size] = '\0';
	return (buffer);
}
