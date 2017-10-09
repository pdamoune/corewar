/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:56:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/09 16:55:26 by tdebarge         ###   ########.fr       */
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
	if ((index > 0 && index <= 5) || index == 8 || index == 13 || index == 11)
	{
		global->res[global->res_pc] = opcode[index];
		++global->res_pc;
		ft_pointeur_tab(global, index, 0, 0);
	}
	else if (index == 0 || index == 15)
	{
		global->res[global->res_pc] = opcode[index];
		global->res_pc++;
		ft_pointeur_tab(global, index, 1, 0);
	}
	else if (index == 6 || index == 9 || index == 14)
	{
		global->res[global->res_pc] = opcode[index];
		global->res_pc++;
		ft_pointeur_tab(global, index, 1, 1);
	}
	else if (index == 7 || index == 10 || index == 12)
	{
		global->res[global->res_pc] = opcode[index];
		global->res_pc++;
		ft_pointeur_tab(global, index, 0, 1);
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

void	ft_get_values(global_t *global, char **line, int arg_ind)
{
	int				*value;
	unsigned short	*value_ind;
	char			*value_char;
	char			*val_tmp;

	val_tmp = NULL;
	value = 0;
	value_ind = 0;
	value_char = 0;
	while (line[++global->i] && !ft_strstart(line[global->i], "#"))
	{

		if (!arg_ind && ((val_tmp = ft_strstart(line[global->i], "%:"))
			|| (val_tmp = ft_strstart(line[global->i], "%"))))
		{
			printf("Je suis un DIRECT\n");
			value = (int*)(global->res + global->res_pc);
			if(ft_isstrint(val_tmp))
				*value = INTREV32(ft_atoi(val_tmp));
			else
				*value = INTREV32(go_to_label(val_tmp, global));
			global->res_pc += 4;
		}
		else if ((val_tmp = ft_strstart(line[global->i], "r"))
				&& ft_isdigitspace(val_tmp))
		{
			printf("Je suis un REGISTRE\n");
			value_char = (global->res + global->res_pc);
			*value_char = ft_atoi(val_tmp);
			global->res_pc++;
		}
		else if ((arg_ind && (val_tmp = ft_strstart(line[global->i], "%:")))
			|| (val_tmp = ft_strstart(line[global->i], ":")))
		{
			printf("Je suis un INDIRECT label\n");
			value_ind = (unsigned short*)(global->res + global->res_pc);
			*value_ind = INTREV16((unsigned short)go_to_label(val_tmp, global));
			global->res_pc += 2;
		}
		else if ((arg_ind && (val_tmp = ft_strstart(line[global->i], "%"))) || ((val_tmp = ft_strdup(line[global->i])) && ft_isstrint(val_tmp)))
		{
			printf("Je suis un INDIRECT valeur decimale\n");
			value_ind = (unsigned short*)(global->res + global->res_pc);
			*value_ind = INTREV16(ft_atoi(val_tmp));
			global->res_pc += 2;
		}
	}
	printf("global->j %d\n", global->j);
}
