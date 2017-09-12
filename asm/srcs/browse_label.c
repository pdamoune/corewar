/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:56:12 by tdebarge          #+#    #+#             */
/*   Updated: 2017/09/12 14:03:49 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		ft_find_index(global_t *global, char *line)
{
	int i;

	i = 0;
	while (global->index_tab[i])
	{
		if (ft_strstart(line, global->index_tab[i]))
			return(i);
		i++;
	}
	return(i);
}

void        ft_counting(global_t *global, char *inst_line)
{
    int     index;

    index = ft_find_index(global, inst_line);
    printf("index == %d\n", index);
    if (index > 0 && index <= 13 && index != 6 && index != 9)
    {
        global->s_label->s_content->nb_octet++;
        ft_calcul_octet(global, global->s_label->s_content->line);
        global->s_label->s_content->instruction = ft_strnew(global->s_label->s_content->nb_octet);
    }
    else if (index == 0 || index == 6 || index == 9 || (index >= 14 && index <= 22))
    {
        ft_calcul_octet(global, global->s_label->s_content->line);
        global->s_label->s_content->instruction = ft_strnew(global->s_label->s_content->nb_octet); 
    }
    else
        ft_exit(10, global, NULL);
}

void        ft_browse_file_counting(global_t *global)
{
    global->s_label = global->begin_label;
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
            global->s_label->s_content->nb_octet++;
            global->s_label->s_content->begin_octet = global->total_octet;
            ft_counting(global, global->s_label->s_content->line[0]);
            global->total_octet += global->s_label->s_content->nb_octet;
             /* DEBUG */
	    	printf("begin_octet : %d\n", global->s_label->s_content->begin_octet);
	    	printf("nb_octet : %d\n", global->s_label->s_content->nb_octet);
	    	printf("global->total_octet : %d\n\n", global->total_octet);
		    /* FIN DEBUG */
            global->s_label->s_content = global->s_label->s_content->next;
        }
       
        printf("\n");
        global->s_label = global->s_label->next;
    }
}

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
    if (index >= 0 && index <= 15)
    {
        global->s_label->s_content->instruction[0] = opcode[index];
        ft_pointeur_tab(global, index);
    }
    else
        ft_exit(10, global, NULL);
}

void        ft_browse_content(global_t *global)
{
   global->s_label = global->begin_label;
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