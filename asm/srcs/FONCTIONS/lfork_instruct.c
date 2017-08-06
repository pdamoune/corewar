#include "../includes/op.h"


void	lfork_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "lfork"))
		printf("<%s> = 0x0f \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
