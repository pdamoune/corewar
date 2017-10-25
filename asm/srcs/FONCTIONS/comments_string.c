#include "../includes/op.h"


void	comments_string(global_t *global, int step)
{
	if (ft_strstart(global->s_label->s_content->line[0], "#"))
		printf("<%s> = Commentaire \n", global->s_label->s_content->line[0]);
	else
		printf("<%s> nop comment\n", global->s_label->s_content->line[0]);
	step = 0;
}
