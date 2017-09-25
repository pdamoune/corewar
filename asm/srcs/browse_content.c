/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:56:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/09/20 11:33:26 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

void        ft_get_opcode(global_t *global, char *line)
{
    int     index;
    int     opcode[16];

/* opcode[index] = opcode de l'instruction associee */
    opcode[0] = 1;
    opcode[1] = 4;
    opcode[2] = 5;
    opcode[3] = 6;
    opcode[4] = 7;
    opcode[5] = 8;
    opcode[6] = 9;
    opcode[7] = 11;
    opcode[8] = 3;
    opcode[9] = 12;
    opcode[10] = 14;
    opcode[11] = 13;
    opcode[12] = 10;
    opcode[13] = 2;
    opcode[14] = 15;
    opcode[15] = 16;
    index = ft_find_index(global, line);
	if (index > 0 && index <= 13 && index != 6 && index != 9)
	{
		global->s_label->s_content->instruction[0] = opcode[index];
		ft_pointeur_tab(global, index, 0);
	}
    else if (index == 0 || index == 6 || index == 9 || (index >= 14 && index <= 22))
    {
        global->s_label->s_content->instruction[0] = opcode[index];
        ft_pointeur_tab(global, index, 1);
    }
    else
        ft_exit(10, global, NULL);
}

void        ft_browse_content(global_t *global)
{
    global->s_label = global->begin_label;
	ft_check_header_bis(global);
    while (!ft_strcmp(global->s_label->name, "HEADER") || !ft_strcmp(global->s_label->name, "COMMENTS"))
        global->s_label = global->s_label->next;
    while (global->s_label)
    {
        printf("/--------------- NEW LABEL n°%d --------------/\n", global->s_label->num);
        printf("Name :%s \n", global->s_label->name);
        printf("Content : \n");
        global->s_label->s_content = global->s_label->begin_content;
        while (global->s_label->s_content)
        {
            ft_get_opcode(global, global->s_label->s_content->line[0]);
            global->s_label->s_content = global->s_label->s_content->next;
        }
        global->s_label = global->s_label->next;
    }
}

void	ft_get_values(global_t *global, char **line, int one_arg)
{
	int				*value;
	unsigned short	*value_ind;
	char			*value_char;
	char			*val_tmp;


	val_tmp = NULL;
	value = 0;
	value_ind = 0;
	value_char = 0;
	if (one_arg)
		global->j = 1;
	else
		global->j = 2;
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
			printf("value %d\n", *value);
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
