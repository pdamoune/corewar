#include "../includes/op.h"


void	indirect_param(global_t *global, char *line)
{
	if (ft_strstart(line, "%:"))
		printf("<%s> = INDIRECT 11 + %s\n", line, ft_strstart(line, "%:"));
	else
		printf("<%s> \n", line);
	global->i = 0;
}