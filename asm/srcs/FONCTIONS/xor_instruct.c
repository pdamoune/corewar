#include "../includes/op.h"


void	xor_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "xor"))
		printf("<%s> = 0x08 \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
