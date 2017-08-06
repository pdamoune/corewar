#include "../includes/op.h"


void	lldi_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "lldi"))
		printf("<%s> = 0x0e \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
