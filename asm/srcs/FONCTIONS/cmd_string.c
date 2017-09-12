#include "../includes/op.h"


void	cmd_string(global_t *global)
{
	if (ft_strstart(global->s_label->s_content->line[0], "."))
		printf("<%s> = cmd_string \n", global->s_label->s_content->line[0]);
	else
		printf("<%s> autre \n", global->s_label->s_content->line[0]);
}
