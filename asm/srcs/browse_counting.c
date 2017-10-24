/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_counting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdebarge <tdebarge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:27:04 by tdebarge          #+#    #+#             */
/*   Updated: 2017/10/23 18:57:29 by tdebarge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/op.h"

int		ft_find_i(char *line)
{
	int i;

	i = 0;
	while (g_op_tab[i])
	{
		if (line && !ft_strcmp(line, g_op_tab[i].label))
			return (i);
		i++;
	}
	return (i);
}

void	ft_counting(t_global *global, char *inst_line)
{
	global->i_tab = ft_find_i(inst_line);
	if (g_op_tab[global->i_tab].ocp == 1)
		global->s_label->s_content->nb_octet++;
	ft_calcul_octet(global, global->s_label->s_content->line)
}

void	ft_calcul_octet(t_global *global, char **line)
{
	int		i;
	char	*val_tmp;

	i = 0;
	val_tmp = NULL;
	while (line[++i] && !ft_str_mod(line[i], "#"))
	{
		if ((val_tmp = ft_str_mod(line[i], "r"))
		&& !ft_strchr(line[i], ':') && ft_isdigitspace(val_tmp))
			global->s_label->s_content->nb_octet++;
		else if (!g_op_tab[global->i_tab].index && ((val_tmp = ft_str_mod(line[i], "%:"))
		|| ((val_tmp = ft_str_mod(line[i], "%")) && !ft_strchr(val_tmp, ':'))))
			global->s_label->s_content->nb_octet += 4;
		else
			global->s_label->s_content->nb_octet += 2;
	}
}

void	ft_browse_file_counting(t_global *global)
{
	global->s_label = global->begin_label;
	while (!ft_strcmp(global->s_label->name, "HEADER")
		|| !ft_strcmp(global->s_label->name, "COMMENTS"))
		global->s_label = global->s_label->next;
	while (global->s_label)
	{
		global->s_label->s_content = global->s_label->begin_content;
		while (global->s_label->s_content)
		{
			global->s_label->s_content->begin_octet = global->total_octet;
			if (global->s_label->s_content->line && global->s_label->s_content->line[0])
			{
				global->s_label->s_content->nb_octet++;
				ft_counting(global, global->s_label->s_content->line[0]);
				global->total_octet += global->s_label->s_content->nb_octet;
			}
			global->s_label->s_content = global->s_label->s_content->next;
		}
		global->s_label = global->s_label->next;
	}
}
