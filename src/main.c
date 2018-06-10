/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include "my.h"
#include "bsq.h"

void    fill_my_square(struct s_bsq *bsq)
{
	int     y = bsq->y;
	int     x = bsq->x;

	while (y != (bsq->y + bsq->max_size)) {
		x = bsq->x;
		while (x != (bsq->x + bsq->max_size) && bsq->tab[y][x] != 'o') {
			bsq->tab[y][x] = 'x';
			x++;
		}
		y++;
	}
	y = 0;
	while (bsq->tab[y]) {
		write(1, bsq->tab[y], bsq->large + 1);
		write(1, "\n", 1);
		y++;
	}
}

void	start_bsq(struct s_bsq *bsq)
{
	if (bsq->map_size > 1 && my_strlen(bsq->tab[0]) > 1) {
		fill_side(bsq);
		do_all_my_tab(bsq);
		fill_my_square(bsq);
	} else
		my_size_one(bsq);
}

int	main(int ac, char **av)
{
	struct s_bsq bsq;

	if (ac == 2) {
		bsq.buffer = open_my_file(av[1]);
		my_check_buffer(bsq.buffer);
		init_struct(&bsq, bsq.buffer);
		start_bsq(&bsq);
	} else
		return (84);
	return (0);
}
