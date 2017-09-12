#include "../includes/op.h"


void	others_string(global_t *global)
{
	if (ft_strstart(global->s_label->s_content->line[0], "."))
		printf("<%s> = !! Instruction BIZARRE - A méditer !! \n", global->s_label->s_content->line[0]);
	else
		printf("<%s> nop comment\n", global->s_label->s_content->line[0]);
}
