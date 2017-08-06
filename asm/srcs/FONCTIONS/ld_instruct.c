#include "../includes/op.h"


void	ld_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "ld"))
		printf("<%s> = 0x02 \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
