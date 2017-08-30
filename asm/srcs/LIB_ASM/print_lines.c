#include "../../includes/op.h"

void	ft_print_lines(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		// ft_putstr(tab[i]);
		printf("<%s>\n", tab[i]);
		// ft_putchar('\n');
		i++;
	}
}
