/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"
#include "bsq.h"

int	my_add(struct s_bsq *bsq, int y, int x)
{
	int	one = bsq->mod[y][x + 1] + 1;
	int	two = bsq->mod[y + 1][x + 1] + 1;
	int	three = bsq->mod[y + 1][x] + 1;
	int	res = one;

	if (one > two)
		res = two;
	if (three < two)
		res = three;
	if (bsq->tab[y][x] == 'o')
		return (0);
	return (res);
}

void	do_all_my_tab(struct s_bsq *bsq)
{
	int	y = bsq->map_size - 1;
	int	x = bsq->large - 1;

	while (y >= 0) {
		x = bsq->large - 1;
		while (x >= 0) {
			bsq->mod[y][x] = my_add(bsq, y, x);
			x--;
		}
		y--;
	}
}

void	fill_side(struct s_bsq *bsq)
{
	for (int i = 0; bsq->tab[bsq->map_size][i]; i++)
		bsq->mod[bsq->map_size][i] = (bsq->tab[bsq->map_size][i] == '.' ? 1 : 0);
	for (int i = 0; bsq->tab[i]; i++)
		bsq->mod[i][bsq->large] = (bsq->tab[i][bsq->large] == '.' ? 1 : 0);
}

void	check_carac(struct s_bsq *bsq, int y, int x)
{
	if (bsq->mod[y][x] > bsq->max_size) {
		bsq->max_size = bsq->mod[y][x];
		bsq->y = y;
		bsq->x = x;
	}
}

void	detect_bigger(struct s_bsq *bsq)
{
	for (int y = 0; y < bsq->map_size + 1 ; y++) {
		for (int x = 0; x < bsq->large + 1; x++) {
			check_carac(bsq, y, x);
		}
	}
}

void    fill_my_square(struct s_bsq *bsq)
{
	int     y = bsq->y;
	int     x = bsq->x;

	while (y != (bsq->y + bsq->max_size) && bsq->tab[y]) {
		x = bsq->x;
		while (x != (bsq->x + bsq->max_size) && bsq->tab[y][x] == '.' && bsq->tab[y][x]) {
			bsq->tab[y][x] = 'x';
			x += 1;
		}
		y += 1;
	}
	for (y = 0; bsq->tab[y]; y++) {
		write(1, bsq->tab[y], bsq->large + 1);
		write(1, "\n", 1);
	}
}

void	start_bsq(struct s_bsq *bsq)
{
	fill_side(bsq);
	do_all_my_tab(bsq);
	detect_bigger(bsq);
	fill_my_square(bsq);
}

int	main(int ac, char **av)
{
	struct s_bsq bsq;

	if (ac == 2) {
		bsq.buffer = open_my_file(av[1]);
		init_struct(&bsq, bsq.buffer);
		start_bsq(&bsq);
	} else
		return (84);
	return (0);
}
