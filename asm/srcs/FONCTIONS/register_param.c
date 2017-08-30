#include "../includes/op.h"


void	register_param(global_t *global, int step)
{
	char	*nbr;
	char	*registre;

	registre = ft_strstart(global->s_label->s_content->line[0], "r");
	if (registre)
	{
		nbr = ft_convert_base(registre, "0123456789", "0123456789ABCDEF");
		printf("<%s> = REGISTRE 0x0%s\n", global->s_label->s_content->line[0], nbr);
	}
	ft_print_words_tables(global->s_label->s_content->line);
	step = 0;
}
