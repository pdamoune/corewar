#include "../includes/op.h"


void	lld_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "lld"))
		printf("<%s> = 0x0d \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
