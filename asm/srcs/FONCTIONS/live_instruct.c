#include "../includes/op.h"
/*
static void	ft_get_values(global_t *global, char **line, int type)
{
	int		i;
	int		*value;
	char	*val_tmp;

	i = 0;
	val_tmp = NULL;
	value = 0;
	while (line[++i] && !ft_strstart(line[i], "#"))
	{
		if (type == OCTET)
			global->s_label->s_content->nb_octet += 4;
		else if (type == STOCK)
		{
			if ((val_tmp = ft_strstart(line[i], "%")))
			{
				value = (int *)&(global->s_label->s_content->instruction[1]);
				if (ft_isstrdigit(val_tmp))
					*value = INTREV32(ft_atoi(val_tmp));
				else
					*value = INTREV32(go_to_label(val_tmp, global));
			}
			else
				ft_exit(12, global, NULL);
		}
	}
}
*/
/*
**  INSTRUCTION : LIVE
**  OPCODE = 1
**	PARAM = T_DIR
**	Label_size = 4
**	Nombre d'octet = 4 + opcode
*/

//faire fonction pour param
/*void	live_instruct(global_t *global, int step)
{
	 Debug */
/*	printf("<%s> = 0x01\n", global->s_label->s_content->line[0]);
	ft_print_words_tables(global->s_label->s_content->line);
	 End Debug */
/*	if (step == OCTET)
	{
		 Pas de composition d'argument pour LIVE	*/
		/* Octets of the Values */
/*		ft_get_values(global, global->s_label->s_content->line, OCTET);
		printf("nb_octet OCTET = %d \n", global->s_label->s_content->nb_octet);
		global->s_label->s_content->instruction = ft_strnew(global->s_label->s_content->nb_octet);

	}
	else if (step == STOCK)
	{
		printf("nb_octet STOCK = %d \n", global->s_label->s_content->nb_octet);
		 OPCODE  */
/*		global->s_label->s_content->instruction[0] = 1;

		 Get the values */
/*		ft_get_values(global, global->s_label->s_content->line, STOCK);

		 Write the instruction */
/*		ft_write(global, global->s_label->s_content->instruction, global->s_label->s_content->nb_octet);

		 DEBUG */
/*		printf("value instruction : ");
		int i = 0;
		while(i < global->s_label->s_content->nb_octet)
			printf("0x%X ", global->s_label->s_content->instruction[i++]);
		printf("\n");
		 Fin DEBUG */
/*	}
}
*/