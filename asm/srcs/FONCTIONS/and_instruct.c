#include "../includes/op.h"

char	*ft_compose_arg_bis(global_t *global, char **line, int i, char **arg)
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

char	*ft_compose_arg(global_t *global, char **line)
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
/*
** Cette fonction pourrait marcher pour toutes les instructions sans retouche
*/
void	ft_calcul_octet(global_t *global, char **line)
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

void	ft_get_values(global_t *global, char **line)
{
	int				*value;
	unsigned short	*value_ind;
	char			*value_char;
	char			*val_tmp;

	global->j = 2;
	val_tmp = NULL;
	value = 0;
	value_ind = 0;
	value_char = 0;
	while (line[++global->i] && !ft_strstart(line[global->i], "#"))
	{
		printf("global->j %d\n", global->j);

		if ((val_tmp = ft_strstart(line[global->i], "%:"))
		|| (val_tmp = ft_strstart(line[global->i], "%")))
		{
			printf("Je suis un DIRECT\n");
			value = (int *)&(global->s_label->s_content->instruction[global->j]);
			if(ft_isstrdigit(val_tmp))
				*value = INTREV32(ft_atoi(val_tmp));
			else
				*value = INTREV32(go_to_label(val_tmp, global));
			global->j += 4;

		}
		else if ((val_tmp = ft_strstart(line[global->i], "r"))
				&& ft_isstrdigit(val_tmp))
		{
			printf("Je suis un REGISTRE\n");
			printf("global->j %d\n", global->j);
			value_char = (char *)&(global->s_label->s_content->instruction[global->j]);
			*value_char = ft_atoi(val_tmp);
			printf("value %d\n", *value_char);
			if (global->s_label->s_content->nb_octet - 1 != global->j)
				global->j++;

		}
		else if (ft_isstrdigit(line[global->i]))
		{
			printf("Je suis un INDIRECT valeur decimale\n");
			value = (int *)&(global->s_label->s_content->instruction[global->j]);
			*value = INTREV16(ft_atoi(line[global->i]));
			global->j += 2;

		}
		else if ((val_tmp = ft_strstart(line[global->i], ":")))
		{
			printf("Je suis un INDIRECT label\n");
			printf("val_tmp %s\n", val_tmp);
			value_ind = (unsigned short *)&(global->s_label->s_content->instruction[global->j]);
			*value_ind = INTREV16((unsigned short)go_to_label(val_tmp, global));
			printf("go_to_label %X\n", go_to_label(val_tmp, global));
			printf("val_tmp %X\n", *value_ind);
			global->j += 2;
			// 0x6 0x74 0x1 0x1 0x0 0x0
		}
	}
	printf("global->j %d\n", global->j);

}

// void	and_instruct(global_t *global, int step, int opcode, int if_arg)
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
