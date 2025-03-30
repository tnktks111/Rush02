#include "rush02.h"

//新しいbufferを作る
t_n_buf	*n_buf_init(void)
{
	t_n_buf	*buffer;

	buffer = (t_n_buf *)malloc(sizeof(t_n_buf));
	buffer->words = (char **)malloc(sizeof(char *));
	buffer->words[0] = 0;
	buffer->size = 0;
	return (buffer);
}

// bufferにwordをぶち込む、mallocで再確保するか、クソデカbufferを作るか、それともt_n_bufの実装をlinkedlistでやりなおすか
int	n_buf_add(t_n_buf *buffer, char *word)
{
	char	**words;
	int		i;

	words = (char **)malloc(sizeof(char *) * (buffer->size + 1));
	if (!words)
		return (0);
	i = 0;
	while (i < buffer->size)
	{
		words[i] = buffer->words[i];
		i++;
	}
	words[i] = word;
	free(buffer->words);
	buffer->words = words;
	buffer->size += 1;
	return (1);
}

//バッファが完成したら出力
void	n_buf_print(t_n_buf *buffer)
{
	int	i;

	i = 0;
	while (i < buffer->size)
	{
		ft_putstr(buffer->words[i]);
		if (i < buffer->size - 1)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

// free
void	free_n_buf(t_n_buf *buffer)
{
	int i;
	i = 0;
	while (i < buffer->size)
		free(buffer->words[i++]);
	free(buffer);
}