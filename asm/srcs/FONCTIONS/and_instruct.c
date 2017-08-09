#include "../includes/op.h"

static char	*ft_compose_arg_bis(global_t *global, char **line, int i, char **arg)
{
	if (i == 2)
	{
		if (ft_strstart(line[i], "%:"))
			*arg = ft_arg(*arg, 2, IND_CODE);
		else if (ft_strstart(line[i], "%"))
			*arg = ft_arg(*arg, 2, DIR_CODE);
		else if (ft_strstart(line[i], "r"))
			*arg = ft_arg(*arg, 2, REG_CODE);
		else
			ft_exit(12, global, NULL);
	}
	else if (i == 3)
	{
		if (ft_strstart(line[i], "r"))
			*arg = ft_arg(*arg, 3, REG_CODE);
		else
			ft_exit(12, global, NULL);
	}
	return(*arg);
}

static char	*ft_compose_arg(global_t *global, char **line)
{
	int		i;
	char	*arg;

	arg = ft_strdup("00000000");
	i = 0;
	while (line[++i] && !ft_strstart(line[i], "#"))
	{
		if (i > 3)
			ft_exit(11, global, NULL);
		else if (i == 1)
		{
			if (ft_strstart(line[i], "%:"))
				arg = ft_arg(arg, 1, IND_CODE);
			else if (ft_strstart(line[i], "%"))
				arg = ft_arg(arg, 1, DIR_CODE);
			else if (ft_strstart(line[i], "r"))
				arg = ft_arg(arg, 1, REG_CODE);
			else
				ft_exit(12, global, NULL);
		}
		else
			ft_compose_arg_bis(global, line, i, &arg);
	}
	return(arg);
}

static void	ft_write_values(global_t *global, char **line)
{
	int		i;
	char	*value;
	char	*val_tmp;

	i = 0;
	val_tmp = NULL;
	value = NULL;
	while (line[++i] && !ft_strstart(line[i], "#"))
	{
		if ((val_tmp = ft_strstart(line[i], "%:")) || (val_tmp = ft_strstart(line[i], "%")))
			if(ft_isstrdigit(val_tmp))
				value = ft_convert_hexa(global, val_tmp, DIR_CODE, 4);
			else
				printf("!!!FCT à coder!!! value : %s", value);
		else if ((val_tmp = ft_strstart(line[i], "r")) && ft_isstrdigit(val_tmp))
			value = ft_convert_hexa(global, val_tmp, REG_CODE, 4);
		ft_write(global, value);
		printf("%s", value);
		free(value);
	}
}
/*
**  INSTRUCTION : AND
**  OPCODE = 6
**	PARAM = T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG
**	Label_size = 4
*/
void	and_instruct(global_t *global, char *line)
{
	char	*arg;
	char	*arg_tmp;

	ft_write(global, "0x06");
		printf("<%s> = 0x06", line);
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
