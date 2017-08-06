#include "../includes/op.h"


void	register_param(global_t *global, char *line)
{
	char	*nbr;
	char	*registre;

	registre = ft_strstart(line, "r");
	if (registre)
	{
		nbr = ft_convert_base(registre, "0123456789", "0123456789ABCDEF");
		printf("<%s> = REGISTRE %s\n", line, nbr);
	}
	else
		printf("<%s> \n", line);
	global->i = 0;

}
