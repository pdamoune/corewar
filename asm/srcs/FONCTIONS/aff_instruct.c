#include "../includes/op.h"

char	*ft_compose_arg_aff(global_t *global, char **line)
{
	int		i;
	char	*arg;

	arg = ft_strdup("00000000");
	i = 0;
	while (line[i++] && !ft_strstart(line[i], "#"))
	{
		if (i > 1)
			ft_exit(11, global, NULL);
		else if (i == 1)
		{
			if (ft_strstart(line[i], "r"))
				arg = ft_arg(arg, 1, REG_CODE);
			else
				ft_exit(12, global, NULL);
		}
	}
	return(arg);
}


void	aff_instruct(global_t *global)
{
	int     *arg;
    char    *arg_tmp;

    arg_tmp = ft_compose_arg_aff(global, global->s_label->s_content->line);
	arg = (int *)&(global->s_label->s_content->instruction[1]);
	*arg = ft_atoi(ft_convert_base(arg_tmp, "01", "0123456789"));
	printf("<%s> = arg\n", arg_tmp);
	printf("<%d> = arg\n", *arg);
	printf("<%X> = arg\n", *arg);
	free(arg_tmp);

	/* Get the values */
	global->i = 0;
	ft_get_values_aff(global, global->s_label->s_content->line);

	/* Write the instruction */
	ft_write(global, global->s_label->s_content->instruction, global->s_label->s_content->nb_octet);

	/* DEBUG */
	printf("\nvalue instruction : ");
    int i = 0;
	while(i < global->s_label->s_content->nb_octet)
		printf("0x%X ", global->s_label->s_content->instruction[i++]);
	printf("\n\n");
	/* Fin DEBUG */
}

void	ft_get_values_aff(global_t *global, char **line)
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
		if ((val_tmp = ft_strstart(line[global->i], "r"))
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
		else
			ft_exit(9, global, NULL);
	}
	printf("global->j %d\n", global->j);
}
