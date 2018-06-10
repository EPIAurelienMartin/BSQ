/*
** EPITECH PROJECT, 2017
** particular
** File description:
** ...
*/

#include "my.h"
#include "bsq.h"

void    large_is_one(char **tab, struct s_bsq *bsq)
{
	int     y = 0;

	while (tab[y][0] != '.' && tab[y] && y < bsq->map_size) {
		y++;
	}
	if (tab[y] != NULL && tab[y][0] != 'o')
		tab[y][0] = 'x';
	my_show_word_array(tab);
}

void    only_one_line(char **tab)
{
	int     x = 0;

	while (tab[0][x] != '.' && tab[0][x])
		x++;
	if (tab[0][x] != '\0')
		tab[0][x] = 'x';
	my_putstr(tab[0]);
	my_putchar('\n');
}

void    my_size_one(struct s_bsq *bsq)
{
	if (bsq->map_size + 1 == 1 && my_strlen(bsq->tab[0]) == 1) {
		bsq->tab[0][0] == '.' ? bsq->tab[0][0] = 'x' : 0;
		my_putchar(bsq->tab[0][0]);
		my_putchar('\n');
	} else if (my_strlen(bsq->tab[0]) == 1 && bsq->map_size > 0)
		large_is_one(bsq->tab, bsq);
	else
		only_one_line(bsq->tab);

}
