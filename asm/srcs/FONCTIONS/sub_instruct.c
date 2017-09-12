#include "../includes/op.h"


void	sub_instruct(global_t *global)
{
	printf("<%s> = 0x05 \n", global->s_label->s_content->line[0]);
	ft_print_words_tables(global->s_label->s_content->line);
}
