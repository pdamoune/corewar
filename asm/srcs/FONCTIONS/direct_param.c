#include "../includes/op.h"


void	direct_param(global_t *global, int step)
{
	if (ft_strstart(global->s_label->s_content->line[0], "%:"))
		printf("<%s> = DIRECT 10 + %s\n", global->s_label->s_content->line[0], ft_strstart(global->s_label->s_content->line[0], "%:"));
	else if (!ft_strstart(global->s_label->s_content->line[0], "%:") && ft_strstart(global->s_label->s_content->line[0], "%"))
		printf("<%s> = DIRECT 10 + %s\n", global->s_label->s_content->line[0], ft_strstart(global->s_label->s_content->line[0], "%"));
	else
		printf("<%s> \n", global->s_label->s_content->line[0]);
	step = 0;
}
