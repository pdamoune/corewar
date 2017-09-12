#include "../includes/op.h"


void	add_instruct(global_t *global)
{
	printf("<%s> = 0x06 \n", global->s_label->s_content->line[0]);
	ft_print_words_tables(global->s_label->s_content->line);
}
