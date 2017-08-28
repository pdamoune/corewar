#include "../includes/op.h"

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
		if ((val_tmp = ft_strstart(line[i], "%")))
		{
			if (ft_isstrdigit(val_tmp))
				value = ft_convert_hexa(global, val_tmp, DIR_CODE, 4);
			else
			{
				value = ft_strdup("0x.. 0x.. 0x.. 0x..");
				printf("!!!FCT à coder!!! value : %s", value);
			}
			global->s_label->s_content->instruction = ft_free_strjoin(&(global->s_label->s_content->instruction), &value);
		}
	}
}
/*
**  INSTRUCTION : LIVE
**  OPCODE = 1
**	PARAM = T_DIR
**	Label_size = 4
**	Nombre d'octet = 4 + opcode
*/

//faire fonction pour param
void	live_instruct(global_t *global, int step)
{
	/* Debug */
	printf("<%s> = 0x01\n", global->s_label->s_content->line[0]);
	ft_print_words_tables(global->s_label->s_content->line);
	/* End Debug */
	if (step == STOCK)
	{
		global->s_label->s_content->nb_octet += 4;
		global->s_label->s_content->instruction = ft_strdup("0x01");
		/* Pas de composition d'argument pour LIVE	*/
		ft_get_values(global, global->s_label->s_content->line);
	}
	else
	{
		ft_write(global, global->s_label->s_content->instruction);
		ft_write(global, "\n");
	}
	printf("instruction = %s \n", global->s_label->s_content->instruction);
}
