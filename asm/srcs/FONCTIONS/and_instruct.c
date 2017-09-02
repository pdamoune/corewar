#include "../includes/op.h"

static char	*ft_compose_arg_bis(global_t *global, char **line, int i, char **arg)
{
	if (i == 2)
	{
		if (ft_strstart(line[i], "%"))
			*arg = ft_arg(*arg, 2, DIR_CODE);
		else if (ft_strstart(line[i], "r"))
			*arg = ft_arg(*arg, 2, REG_CODE);
		else
			*arg = ft_arg(*arg, 2, IND_CODE);
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
			if (ft_strstart(line[i], "%"))
				arg = ft_arg(arg, 1, DIR_CODE);
			else if (ft_strstart(line[i], "r"))
				arg = ft_arg(arg, 1, REG_CODE);
			else
				arg = ft_arg(arg, 1, IND_CODE);
		}
		else
			ft_compose_arg_bis(global, line, i, &arg);
	}
	return(arg);
}

static void	ft_calcul_octet(global_t *global, char **line)
{
	int		i;
	char	*val_tmp;

	i = 0;
	val_tmp = NULL;
	while (line[++i] && !ft_strstart(line[i], "#"))
	{
		if ((val_tmp = ft_strstart(line[i], "r")) && ft_isstrdigit(val_tmp))
			global->s_label->s_content->nb_octet++;
		else if ((val_tmp = ft_strstart(line[i], ":")))
			global->s_label->s_content->nb_octet += 2;
		else if (ft_isstrdigit(line[i]))
			global->s_label->s_content->nb_octet += 2;
		else
			global->s_label->s_content->nb_octet += 4;
	}
}

static void	ft_get_values(global_t *global, char **line)
{
	int		*value;
	char	*val_tmp;

	global->j = 2;
	val_tmp = NULL;
	value = 0;
	while (line[++global->i] && !ft_strstart(line[global->i], "#"))
	{
		value = (int *)&(global->s_label->s_content->instruction[global->j]);
		if ((val_tmp = ft_strstart(line[global->i], "%:"))
		|| (val_tmp = ft_strstart(line[global->i], "%")))
		{
			if(ft_isstrdigit(val_tmp))
				*value = INTREV32(ft_atoi(val_tmp));
			else
				*value = INTREV32(go_to_label(val_tmp, global, DIR_CODE));
			global->j += 4;
		}
		else if ((val_tmp = ft_strstart(line[global->i], ":")))
		{
			printf("val_tmp %s\n", val_tmp);
			if(ft_isstrdigit(val_tmp))
				*value = INTREV16(ft_atoi(val_tmp));
			else
				*value = INTREV16(go_to_label(val_tmp, global, IND_CODE));
				printf("go_to_label %lX\n", go_to_label(val_tmp, global, IND_CODE));
				printf("val_tmp %X\n", *value);
			// global->j += 2;
		}
		else if ((val_tmp = ft_strstart(line[global->i], "r"))
				&& ft_isstrdigit(val_tmp) && global->j++)
			*value = ft_atoi(val_tmp);
		else if (ft_isstrdigit(line[global->i]) && (global->j += 2))
			*value = ft_atoi(line[global->i]);
	}
}

void	and_instruct(global_t *global, int step)
{
	int		*arg;
	char	*arg_tmp;

	/* Debug */
	printf("<%s> = 0x06\n", global->s_label->s_content->line[0]);
	ft_print_words_tables(global->s_label->s_content->line);
	/* End Debug */
	if (step == OCTET)
	{
		/* Octet of the Argument */
		global->s_label->s_content->nb_octet++;
		/* Octets of the Values */
		ft_calcul_octet(global, global->s_label->s_content->line);

		printf("nb_octet OCTET = %d \n", global->s_label->s_content->nb_octet);
		global->s_label->s_content->instruction = ft_strnew(global->s_label->s_content->nb_octet);
	}
	else if (step == STOCK)
	{
		printf("nb_octet STOCK = %d \n", global->s_label->s_content->nb_octet);
		/* OPCODE */
		global->s_label->s_content->instruction[0] = 6;

		/* Get the argument */
		arg_tmp = ft_compose_arg(global, global->s_label->s_content->line);
		arg = (int *)&(global->s_label->s_content->instruction[1]);
		*arg = ft_atoi(ft_convert_base(arg_tmp, "01", "0123456789"));
		printf("<%s> = arg\n", arg_tmp);
		printf("<%d> = arg\n", *arg);
		printf("<%X> = arg\n", *arg);
		free(arg_tmp);

		/* Get the values */
		global->i = 0;
		ft_get_values(global, global->s_label->s_content->line);

		/* Write the instruction */
		ft_write(global, global->s_label->s_content->instruction, global->s_label->s_content->nb_octet);

		/* DEBUG */
		printf("value instruction : ");
		int i = 0;
		while(i < global->s_label->s_content->nb_octet)
			printf("0x%X ", global->s_label->s_content->instruction[i++]);
		printf("\n");
		/* Fin DEBUG */
	}
	/* En enlevant tous les commentaires on est à 19 lignes ! */
}
