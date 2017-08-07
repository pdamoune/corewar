#include "../includes/op.h"

/*
**  INSTRUCTION : LIVE
**  OPCODE = 1
**	ARG = T_DIR
**	Label_size = 4
*/
void	live_instruct(global_t *global, char *line)
{
	int		i;
	int		comment;
	char	*arg_1;
	char	*value_1;

	arg_1 = ft_strdup("00000000");
	ft_write(global, "0x01", 0);
	comment = 0;
	i = 1;
	while (global->s_label->s_content->line[i])
	{
		if (!ft_strstart(global->s_label->s_content->line[i], "#") && !comment)
		{
			if (i > 1)
				ft_exit(11, global, NULL);
			else if (i == 1)
			{
				if ((value_1 = ft_strstart(global->s_label->s_content->line[i], "%")))
				{
					arg_1 = ft_arg(arg_1, 1, DIR_CODE, NULL);
					// printf("arg = %s\n", arg_1);
					arg_1 = ft_convert_base(arg_1, "01", "0123456789ABCDEF");
					ft_write(global, arg_1, 0);
					ft_write(global, " ", 0);
					value_1 = ft_convert_base(value_1, "0123456789", "0123456789ABCDEF");
					ft_write(global, value_1, 4);
				}
				else
					ft_exit(12, global, NULL);
			}
		}
		else
			comment = 1;
		i++;
	}
	ft_write(global, "\n", 0);
	printf("<%s> = 0x01 0x%s 0x00 0x00 0x00 0x%s\n", line, arg_1, value_1);
}
