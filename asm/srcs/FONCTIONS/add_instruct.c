#include "../includes/op.h"


void	add_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "and"))
		printf("<%s> = 0x06 \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
