#include "../includes/op.h"


void	cmd_string(global_t *global, char *line)
{
	if (ft_strstart(line, "."))
		printf("<%s> = cmd_string \n", line);
	else
		printf("<%s> autre \n", line);
	global->i = 0;
}
