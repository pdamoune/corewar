#include "../includes/op.h"


void	or_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "or"))
		printf("<%s> = 0x07 \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
