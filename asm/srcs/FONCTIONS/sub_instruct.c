#include "../includes/op.h"


void	sub_instruct(global_t *global, char *line)
{
	if (ft_strstart(line, "sub"))
		printf("<%s> = 0x05 \n", line);
	else
		printf("<%s> \n", line);
	global->i = 0;
}
