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
	global->s_label->s_content->nb_octet++;
	return(arg);
}

static void	ft_get_values(global_t *global, char **line)
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
		{
			if(ft_isstrdigit(val_tmp))
				value = ft_convert_hexa(global, val_tmp, DIR_CODE, 4);
			else
			{
				value = ft_strdup("0x.. 0x.. 0x.. 0x..");
				/* Au prochain passage, remplacer les . par le code du label*/
				printf("!!!FCT à coder!!! value : %s", value);
			}
			global->s_label->s_content->nb_octet += 4;
		}
		else if ((val_tmp = ft_strstart(line[i], "r")) && ft_isstrdigit(val_tmp))
		{
			value = ft_convert_hexa(global, val_tmp, REG_CODE, 4);
			global->s_label->s_content->nb_octet++;
			printf("<%d> = registre %d\n", global->s_label->s_content->nb_octet, i);

		}
		global->s_label->s_content->instruction = ft_free_strjoin(&(global->s_label->s_content->instruction), &value);

	}
}
/*
**  INSTRUCTION : AND
**  OPCODE = 6
**	PARAM = T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG
**	Label_size = 4
*/
void	and_instruct(global_t *global, int step)
{
	char	*arg;
	char	*arg_tmp;

	/* Debug */
	printf("<%s> = 0x06\n", global->s_label->s_content->line[0]);
	ft_print_words_tables(global->s_label->s_content->line);
	/* End Debug */
	if (step == STOCK)
	{
		global->s_label->s_content->instruction = ft_strdup("0x06");
		/* Get the argument */
		arg_tmp = ft_compose_arg(global, global->s_label->s_content->line);
		arg = ft_convert_hexa(global, arg_tmp, ARG_CODE, 4);
		printf("<%s> = arg\n", arg);
		free(arg_tmp);
		global->s_label->s_content->instruction = ft_free_strjoin(&(global->s_label->s_content->instruction), &arg);
		/* End of get the argument */
		/* Get the values */
		ft_get_values(global, global->s_label->s_content->line);
	}
	else
	{
		ft_write(global, global->s_label->s_content->instruction);
		ft_write(global, "\n");
	}
	printf("instruction = %s \n", global->s_label->s_content->instruction);
}
