#include "../includes/op.h"


char	*ft_compose_arg(global_t *global, char **line)
{
	int		i;
	int		comment;
	char	*arg;

	arg = ft_strdup("00000000");
	comment = 0;
	i = 0;
	while (line[++i])
		if (!ft_strstart(line[i], "#") && !comment)
		{
			if (i > 1)
				ft_exit(11, global, NULL);
			else if (i == 1)
			{
				if (ft_strstart(line[i], "%"))
					arg = ft_arg(arg, 1, DIR_CODE);
				else
					ft_exit(12, global, NULL);
			}
		}
		else
			comment = 1;
	return(arg);
}

void	ft_write_values(global_t *global, char **line)
{
	int		i;
	int		comment;
	char	*value;
	char	*val_tmp;

	comment = 0;
	i = 0;
	val_tmp = NULL;
	value = NULL;
	while (line[++i])
		if (!ft_strstart(line[i], "#") && !comment)
		{
			if ((val_tmp = ft_strstart(line[i], "%")))
			{
				if (ft_isstrdigit(val_tmp))
					value = ft_convert_hexa(global, val_tmp, DIR_CODE, 4);
				else
					printf("!!!FCT à coder!!! value : %s", value);
				ft_write(global, value);
				printf("%s", value);
				free(value);
			}
		}
		else
			comment = 1;
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
	char	*arg_tmp;

	ft_write(global, "0x01 ");
		printf("<%s> = 0x01 ", line);
	arg_tmp = ft_compose_arg(global, global->s_label->s_content->line);
	arg = ft_convert_hexa(global, arg_tmp, ARG_CODE, 4);
	free(arg_tmp);
	ft_write(global, arg);
		printf("%s", arg);
	free(arg);
	ft_write_values(global, global->s_label->s_content->line);
	ft_write(global, "\n");
		printf("\n");
}
