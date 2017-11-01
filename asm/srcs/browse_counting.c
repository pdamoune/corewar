/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_counting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 14:27:04 by tdebarge          #+#    #+#             */
/*   Updated: 2017/11/01 04:09:09 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

// extern t_op	g_op_tab[];

// int		ft_find_i(char *line)
// {
// 	int i;

// 	i = 0;
// 	while (i < 16)
// 	{
// 		if (line && !ft_strcmp(line, g_op_tab[i].label))
// 			return (i);
// 		i++;
// 	}
// 	return (i);
// }

// void	ft_counting(t_global *global, char *inst_line)
// {
// 	ITAB = ft_find_i(inst_line);
// 	if (g_op_tab[ITAB].ocp == 1)
// 		G_L_C->nb_octet++;
// 	ft_calcul_octet(global, G_L_C->line);
// }

// void	ft_calcul_octet(t_global *global, char **line)
// {
// 	int		i;
// 	char	*val_tmp;

// 	i = 0;
// 	val_tmp = NULL;
// 	while (line[++i] && !ft_str_mod(line[i], "#"))
// 	{
// 		if ((val_tmp = ft_str_mod(line[i], "r"))
// 		&& !ft_strchr(line[i], ':') && ft_isdigitspace(val_tmp))
// 			G_L_C->nb_octet++;
// 		else if (!g_op_tab[ITAB].index && ((val_tmp = ft_str_mod(line[i], "%:"))
// 		|| ((val_tmp = ft_str_mod(line[i], "%")) && !ft_strchr(val_tmp, ':'))))
// 			G_L_C->nb_octet += 4;
// 		else
// 			G_L_C->nb_octet += 2;
// 	}
// }

// void	ft_browse_file_counting(t_global *global)
// {
// 	global->s_label = global->begin_label;
// 	while (!ft_strcmp(global->s_label->name, "HEADER")
// 		|| !ft_strcmp(global->s_label->name, "COMMENTS"))
// 		global->s_label = global->s_label->next;
// 	while (global->s_label)
// 	{
// 		G_L_C = global->s_label->begin_content;
// 		while (G_L_C)
// 		{
// 			G_L_C->begin_octet = global->total_octet;
// 			if (G_L_C->line && G_L_C->line[0])
// 			{
// 				G_L_C->nb_octet++;
// 				ft_counting(global, G_L_C->line[0]);
// 				global->total_octet += G_L_C->nb_octet;
// 			}
// 			G_L_C = G_L_C->next;
// 		}
// 		global->s_label = global->s_label->next;
// 	}
// }
