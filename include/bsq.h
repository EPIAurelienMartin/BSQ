/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** bsq
*/

#define ERROR 84
#define SUCESS 0

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

struct s_bsq
{
	char	*buffer;
	char	**tab;
	int	**mod;
	int	map_size;
	int	max_size;
	int	large;
	int	y;
	int	x;
};

char    *open_my_file(char *name);
int     file_exist(char *file);
void	fill_struct(struct s_bsq *bsq);
void	my_check_buffer(char *str);
void    init_struct(struct s_bsq *bsq, char *buffer);
