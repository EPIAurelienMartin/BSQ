/*
** EPITECH PROJECT, 2017
** fill
** File description:
** struct
*/

#include "my.h"
#include "bsq.h"

void    init_struct(struct s_bsq *bsq, char *buffer)
{
	bsq->tab = my_str_to_word_array(buffer, "\n");
	bsq->map_size = my_getnb(bsq->tab[0]) - 1;
	bsq->large = my_strlen(bsq->tab[1]) - 1;
	bsq->tab++;
	bsq->max_size = 0;
	bsq->y = 0;
	bsq->x = 0;
	bsq->mod = malloc(sizeof(int*) * bsq->map_size + 1);
	for (int i = 0; i < bsq->map_size + 1; i++)
		bsq->mod[i] = malloc(sizeof(int) * bsq->large);
}
