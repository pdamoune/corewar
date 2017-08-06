#include "../includes/op.h"


void	live_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "live"))
		printf("<%s> = 0x01 \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
