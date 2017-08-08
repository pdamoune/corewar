#include "../includes/op.h"


char	*ft_compose_arg(global_t *global)
{
	int		i;
	int		comment;
	char	*value;
	char	*arg;

	i = 1;
	arg = ft_strdup("00000000");
	comment = 0;
	while (global->s_label->s_content->line[i])
	{
		if (!ft_strstart(global->s_label->s_content->line[i], "#") && !comment)
		{
			if (i > 1)
				ft_exit(11, global, NULL);
			else if (i == 1)
			{
				if ((value =
					ft_strstart(global->s_label->s_content->line[i], "%")))
				{
					arg = ft_arg(arg, 1, DIR_CODE);
				}
				else
					ft_exit(12, global, NULL);
			}
		}
		else
			comment = 1;
		i++;
	}
	return(arg);
}

void	ft_browse_values(global_t *global)
{
	int		i;
	int		comment;
	char	*value;

	comment = 0;
	i = 1;
	while (global->s_label->s_content->line[i])
	{
		if (!ft_strstart(global->s_label->s_content->line[i], "#") && !comment)
		{
			if ((value =
				ft_strstart(global->s_label->s_content->line[i], "%")))
			{
				value = ft_convert_hexa(global, value, DIR_CODE, 4);
				ft_write(global, value);
				printf("%s", value);
			}
		}
		else
			comment = 1;
		i++;
	}
	// free(tmp);
	// free(arg);
}
/*
**  INSTRUCTION : LIVE
**  OPCODE = 1
**	ARG = T_DIR
**	Label_size = 4
*/
void	live_instruct(global_t *global, char *line)
{
	char	*arg;
	char	*tmp;

	ft_write(global, "0x01 ");
	printf("<%s> = 0x01 ", line);
	arg = ft_compose_arg(global);
	tmp = ft_convert_hexa(global, arg, ARG_CODE, 4);
	ft_write(global, tmp);
	printf("%s ", tmp);
	ft_write(global, " ");
	ft_browse_values(global);
	ft_write(global, "\n");
	printf("\n");
}
