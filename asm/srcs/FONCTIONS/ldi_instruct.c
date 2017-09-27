#include "../includes/op.h"

char	*ft_compose_arg_ldi_bis(global_t *global, char **line, int i, char **arg)
{
	char *comment_tmp;

	comment_tmp = NULL;
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
		printf("line[i] avant : -%s- \n", line[i]);
		if ((comment_tmp = ft_strchr(line[i], COMMENT_CHAR)))
			*comment_tmp = '\0';
		printf("line[i] apres : -%s- \n", line[i]);
		if (ft_strstart(line[i], "r"))
			*arg = ft_arg(*arg, 3, REG_CODE);
		else
			ft_exit(12, global, NULL);
	}
	return(*arg);
}

char	*ldi_instruct(global_t *global, char **line)
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
			ft_compose_arg_ldi_bis(global, line, i, &arg);
	}
	return(arg);
}

// void        ldi_instruct(global_t *global)
// {
//     int     *arg;
//     char    *arg_tmp;
//
//     arg_tmp = ft_compose_arg_ldi(global, global->s_label->s_content->line);
// 	arg = (int *)&(global->s_label->s_content->instruction[1]);
// 	*arg = ft_atoi(ft_convert_base(arg_tmp, "01", "0123456789"));
// 	printf("<%s> = arg\n", arg_tmp);
// 	printf("<%d> = arg\n", *arg);
// 	printf("<%X> = arg\n", *arg);
// 	free(arg_tmp);
//
// 	/* Get the values */
// 	global->i = 0;
// 	ft_get_values(global, global->s_label->s_content->line, 0);
//
// 	/* Write the instruction */
// 	ft_write(global, global->s_label->s_content->instruction, global->s_label->s_content->nb_octet);
//
// 	/* DEBUG */
// 	printf("\nvalue instruction : ");
//     int i = 0;
// 	while(i < global->s_label->s_content->nb_octet)
// 		printf("0x%X ", global->s_label->s_content->instruction[i++]);
// 	printf("\n\n");
// 	/* Fin DEBUG */
// }
