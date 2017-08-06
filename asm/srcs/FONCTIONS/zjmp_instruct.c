#include "../includes/op.h"


void	zjmp_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "zjmp"))
		printf("<%s> = 0x09 \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
