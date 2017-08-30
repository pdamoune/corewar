#include "../includes/op.h"


void	fork_instruct(global_t *global, int step)
{
	printf("<%s> = 0x0c \n", global->s_label->s_content->line[0]);
	ft_print_words_tables(global->s_label->s_content->line);
	step = 0;
}
