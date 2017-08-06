#include "../includes/op.h"


void	direct_param(global_t *global, char *line)
{
	if (ft_strstart(line, "%"))
		printf("<%s> = DIRECT 10 + %s\n", line, ft_strstart(line, "%"));
	else
		printf("<%s> \n", line);
	global->i = 0;
}
