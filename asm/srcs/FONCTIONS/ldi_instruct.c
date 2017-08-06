#include "../includes/op.h"


void	ldi_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "ldi"))
		printf("<%s> = 0x0a \n", line);
	else
		printf("<%s> ici\n", line);
	global->i = 0;
}
