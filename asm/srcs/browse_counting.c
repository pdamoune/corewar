/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_counting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:27:04 by tdebarge          #+#    #+#             */
/*   Updated: 2017/09/26 17:27:14 by tdebarge         ###   ########.fr       */
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
    if ((index > 0 && index <= 5) || index == 8 || index == 13 || index == 11)
	{
        global->s_label->s_content->nb_octet++;
        ft_calcul_octet(global, global->s_label->s_content->line, 0);
        global->s_label->s_content->instruction = ft_strnew(global->s_label->s_content->nb_octet);
	}
	else if (index == 0 || index == 15)
	{
        ft_calcul_octet(global, global->s_label->s_content->line, 0);
        global->s_label->s_content->instruction = ft_strnew(global->s_label->s_content->nb_octet); 
	}
	else if (index == 6 || index == 9 || index == 14)
	{
        ft_calcul_octet(global, global->s_label->s_content->line, 1);
        global->s_label->s_content->instruction = ft_strnew(global->s_label->s_content->nb_octet);
	}
	else if (index == 7 || index == 10 || index == 12)
	{
        global->s_label->s_content->nb_octet++;
        ft_calcul_octet(global, global->s_label->s_content->line, 1);
        global->s_label->s_content->instruction = ft_strnew(global->s_label->s_content->nb_octet);
	}
    else
        ft_exit(10, global, NULL);
}

void	ft_calcul_octet(global_t *global, char **line, int arg_ind)
{
	int		i;
	char	*val_tmp;

	i = 0;
	val_tmp = NULL;
	while (line[++i] && !ft_strstart(line[i], "#"))
	{
		if ((val_tmp = ft_strstart(line[i], "r")) && ft_isstrdigit(val_tmp))
			global->s_label->s_content->nb_octet++;
        else if (!arg_ind && ((val_tmp = ft_strstart(line[i], "%:"))
            || (val_tmp = ft_strstart(line[i], "%"))))
            global->s_label->s_content->nb_octet += 4;
        else
			global->s_label->s_content->nb_octet += 2;
	}
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