#include "../includes/op.h"

void	indirect_param(global_t *global)
{
	if (!ft_strstart(global->s_label->s_content->line[0], "%") && !ft_strstart(global->s_label->s_content->line[0], "r"))
		printf("<%s> = INDIRECT 11 + %s\n", global->s_label->s_content->line[0], global->s_label->s_content->line[0]);
	else
		printf("<%s> \n", global->s_label->s_content->line[0]);
}
