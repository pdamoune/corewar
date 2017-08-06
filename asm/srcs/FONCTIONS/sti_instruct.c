#include "../includes/op.h"


void	sti_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "sti"))
		printf("<%s> = 0x0b \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
