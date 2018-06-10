/*
** EPITECH PROJECT, 2017
** strgotoin
** File description:
** ...
*/

#include "my.h"
#include "bsq.h"

int     my_add(struct s_bsq *bsq, int y, int x)
{
	int	one = bsq->mod[y][x + 1];
	int	two = bsq->mod[y + 1][x];
	int	three = bsq->mod[y + 1][x + 1];
	int	res = one;

	if (bsq->tab[y][x] == 'o')
		return (0);
	if (one == 0 || two == 0 || three == 0)
		return (1);
	two < res ? res = two : res;
	three < res ?  res = three : res;
	res += 1;
	if (res >= bsq->max_size) {
		bsq->max_size = res;
		bsq->y = y;
		bsq->x = x;
	}
	return (res);
}

void    do_all_my_tab(struct s_bsq *bsq)
{
	int     y = bsq->map_size - 1;
	int     x = bsq->large - 1;

	while (y >= 0) {
		x = bsq->large - 1;
		while (x >= 0) {
			bsq->mod[y][x] = my_add(bsq, y, x);
			x--;
		}
		y--;
	}
}

void    fill_side(struct s_bsq *bsq)
{
	for (int i = 0; bsq->tab[bsq->map_size][i]; i++) {
		if (bsq->tab[bsq->map_size][i] == '.')
			bsq->mod[bsq->map_size][i] = 1;
		else if (bsq->tab[bsq->map_size][i] == 'o')
			bsq->mod[bsq->map_size][i] = 0;
	}
	for (int i = 0; bsq->tab[i]; i++) {
		if (bsq->tab[i][bsq->large] == '.')
			bsq->mod[i][bsq->large] = 1;
		else if (bsq->tab[i][bsq->large] == 'o')
			bsq->mod[i][bsq->large] = 0;
	}
}
