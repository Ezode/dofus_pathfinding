/*
** EPITECH PROJECT, 2018
** Minishell 2
** File description:
** print functions
*/

#include <unistd.h>

void my_putchar(int c)
{
	write(1, &c, 1);
}

void my_put_nbr(int nbr)
{
	int dgt;

	if (nbr < 0) {
		my_putchar('-');
		nbr = nbr * (-1);
	}
	if (nbr >= 0) {
		if (nbr >= 10) {
			dgt = (nbr % 10);
			nbr = (nbr - dgt) / 10;
			my_put_nbr(nbr);
			my_putchar(dgt + 48);
		}
		else
			my_putchar(nbr % 10 + 48);
	}
}

int my_putstr(const char *str)
{
	int i = 0;

	if (str == NULL)
		return (-1);
	while (str[i] != '\0') {
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}
