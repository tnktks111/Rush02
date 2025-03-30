#ifndef RUSH02_H
#define RUSH02_H

typedef struct s_dict
{
	char **keys;
	char **vals;
	int size;
} t_dict;

typedef struct s_n_buf
{
	char **words;
	int size;
} t_n_buf;

#define DICT_PATH "dicts/numbers.dict"
#define BUF_SIZE 4096
#include <unistd.h> //read, write, close
#include <fcntl.h> //open,
#include <sys/types.h> //open, 
#include <sys/stat.h> //open,
#include <stdlib.h> //malloc, free
#include <stdio.h> 

//dict
char **create_strarr(void);
t_dict init_dict(void);
void free_dict(t_dict *dict);
void items_setter(t_dict *dict, char *key, char *val);
int parser(t_dict *dict, char *raw);
char *dict_get(t_dict *dict, char *key);
int skip_to_numeric(char *str);
int skip_to_word(char *str);
int skip_to_next_entry(char *str);
int dict_get_num(char *dest, char *str);
int dict_get_word(char *dest, char *str);
//error
int error(void);
int dict_error(void);
//file
int file_size(char *file);
char *file_read(char *file);
//init
int init(char *dict_path, char *input);
//nums
t_n_buf *n_buf_init(void);
void n_buf_add(t_n_buf *buffer, char *word);
void n_buf_print(t_n_buf *buffer);
void free_n_buf(t_n_buf *buffer);
int n_store(t_n_buf *buffer, t_dict *dict, char *str);
int n_tens(t_n_buf *buffer, t_dict *dict, char *str);
int n_hundreds(t_n_buf *buffer, t_dict *dict, char *str);
int n_convert(t_n_buf *buffer, t_dict *dict, char *str);
char *zero_padding(char c, int size);
char *get_sub(char *str, int left, int right);
//utils
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar(char c);
//validation
int ft_is_numeric(char *str);
int is_valid_dictfile(char *dict);
int is_valid_input(int argc, char *argv[], char *dict);
#endif