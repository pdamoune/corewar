#include "../includes/op.h"


void	live_instruct(global_t *global, char *line)
{
	int		i;
	int		comment;
	char	*name;
	char	*arg_1;
	char	*value_1;

	name = "0x01";
	arg_1 = NULL;
	comment = 0;
	i = 1;
	while (global->s_label->s_content->line[i])
	{
		if (!ft_strstart(global->s_label->s_content->line[i], "#") && !comment)
		{
			if (i > 1)
				ft_exit(11, global, NULL);
			if ((value_1 = ft_strstart(global->s_label->s_content->line[i], "%")))
			{
				arg_1 = ft_convert_base("10000000", "01", "0123456789ABCDEF");
				value_1 = ft_convert_base(value_1, "0123456789", "0123456789ABCDEF");
			}
			else
				ft_exit(12, global, NULL);
		}
		else
			comment = 1;
		i++;
	}
	printf("<%s> = 0x01 0x%s 0x00 0x00 0x00 0x%s\n", line, arg_1, value_1);
}
