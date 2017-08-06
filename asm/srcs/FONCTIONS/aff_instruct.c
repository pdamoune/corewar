#include "../includes/op.h"


void	aff_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "aff"))
		printf("<%s> = 0x10 \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
