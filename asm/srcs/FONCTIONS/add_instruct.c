#include "../includes/op.h"


void	add_instruct(global_t *global, char *line)
{
	if (!ft_strcmp(line, "add"))
		printf("<%s> = 0x04 \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
