/*
** EPITECH PROJECT, 2017
** str
** File description:
** cat
*/

#include "my.h"

char	*my_strcat(char *dest, char const *src)
{
	int	i = my_strlen(dest);
	int	count = 0;

	while (src[count]) {
		dest[i + count] = src[count];
		count++;
	}
	dest[i + count] = '\0';
	return (dest);
}
