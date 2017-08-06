#include "../includes/op.h"


void	fork_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "fork"))
		printf("<%s> = 0x0c \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
