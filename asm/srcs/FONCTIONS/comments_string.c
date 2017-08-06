#include "../includes/op.h"


void	comments_string(global_t *global, char *line)
{
	if (ft_strstart(line, "#"))
		printf("<%s> = Commentaire \n", line);
	else
		printf("<%s> nop comment\n", line);
	global->i = 0;
}
