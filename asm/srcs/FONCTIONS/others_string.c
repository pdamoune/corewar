#include "../includes/op.h"


void	others_string(global_t *global, char *line)
{
	if (ft_strstart(line, "."))
		printf("<%s> = !! Instruction BIZARRE - A méditer !! \n", line);
	else
		printf("<%s> nop comment\n", line);
	global->i = 0;
}
