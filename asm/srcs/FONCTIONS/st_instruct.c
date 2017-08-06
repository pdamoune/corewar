#include "../includes/op.h"


void	st_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "st"))
		printf("<%s> = 0x03 \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
