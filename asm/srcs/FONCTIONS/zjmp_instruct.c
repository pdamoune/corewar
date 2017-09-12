#include "../includes/op.h"


void	zjmp_instruct(global_t *global)
{
	printf("<%s> = 0x09 \n", global->s_label->s_content->line[0]);
	ft_print_words_tables(global->s_label->s_content->line);
}
